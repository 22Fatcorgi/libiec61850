/*
 * auto_cswi_goose_publisher.c
 *
 * libiec61850 1.6 GOOSE Publisher
 *
 * DataSet:
 *   allData[0] = CSWI.OpOpn.general
 *   allData[1] = CSWI.OpCls.general
 *
 * Behavior:
 *   OPEN event:
 *     CSWI.OpOpn.general = true
 *     CSWI.OpCls.general = false
 *
 *   CLOSE event:
 *     CSWI.OpOpn.general = false
 *     CSWI.OpCls.general = true
 *
 * Timing:
 *   minTime = 10 ms
 *   maxTime = 2000 ms
 *
 *   After event:
 *     10, 20, 40, 80, 160, 320, 640, 1280, 2000, 2000, ...
 *
 *   timeAllowedToLive = 2 * next response time
 *
 * Run:
 *   sudo ./auto_cswi_goose_publisher eth0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <inttypes.h>

#include "goose_publisher.h"
#include "hal_thread.h"
#include "linked_list.h"
#include "mms_value.h"

#define MIN_TIME_MS        10u
#define MAX_TIME_MS        2000u
#define INITIAL_OFF_TIME_MS 15000u

/*
 * 每個狀態維持多久。
 * 20000 ms = OPEN 維持 20 秒，然後切 CLOSE。
 * 如果你覺得切太快，可以改成 60000u。
 */
#define STATE_HOLD_MS      20000u

/*
 * FPGA 目前如果只判斷 EtherType = 0x88B8，
 * 就先不要加 VLAN tag。
 */
#define USE_VLAN_TAG       false

static volatile bool running = true;
static uint64_t publishCount = 0;

static void
sigHandler(int sig)
{
    (void) sig;
    running = false;
}

static uint32_t
nextInterval(uint32_t interval)
{
    if (interval >= MAX_TIME_MS)
        return MAX_TIME_MS;

    uint32_t next = interval * 2u;

    if (next > MAX_TIME_MS)
        next = MAX_TIME_MS;

    return next;
}

static int
publishOnce(GoosePublisher publisher, LinkedList dataset, uint32_t intervalMs)
{
    /*
     * 你的設定：
     * timeAllowedToLive = 2 * next response time
     */
    uint32_t timeAllowedToLive = intervalMs * 2u;

    GoosePublisher_setTimeAllowedToLive(publisher, timeAllowedToLive);

    int result = GoosePublisher_publish(publisher, dataset);

    if (result == -1) {
        printf("ERROR: GOOSE publish failed\n");
        return -1;
    }

    publishCount++;

    printf("[%"PRIu64"]Publish: nextResponseTime=%u ms, TAL=%u ms\n",
           publishCount,
           intervalMs,
           timeAllowedToLive);

    return 0;
}

static void
publishInitialOffState(
        GoosePublisher publisher,
        LinkedList dataset,
        MmsValue* opOpn,
        MmsValue* opCls)
{
    printf("\n====================================\n");
    printf("Initial state: OFF\n");
    printf("CSWI.OpOpn.general = false\n");
    printf("CSWI.OpCls.general = false\n");
    printf("Duration = %u ms\n", INITIAL_OFF_TIME_MS);
    printf("====================================\n");

    /*
     * 初始 OFF 狀態：
     * allData[0] = CSWI.OpOpn.general = false
     * allData[1] = CSWI.OpCls.general = false
     */
    MmsValue_setBoolean(opOpn, false);
    MmsValue_setBoolean(opCls, false);

    /*
     * 這裡不呼叫 GoosePublisher_increaseStNum()
     * 因為這只是初始穩態，不是事件變化。
     *
     * 如果你想讓初始 OFF 也被視為一個新狀態事件，
     * 才需要在這裡加 increaseStNum()。
     */

    uint32_t elapsed = 0u;

    while (running && elapsed < INITIAL_OFF_TIME_MS) {

        /*
         * 沒有變化時，用 maxTime 週期傳送。
         * nextResponseTime = 2000 ms
         * timeAllowedToLive = 4000 ms
         */
        if (publishOnce(publisher, dataset, MAX_TIME_MS) == -1)
            break;

        Thread_sleep(MAX_TIME_MS);
        elapsed += MAX_TIME_MS;
    }
}


static void
publishState(
        GoosePublisher publisher,
        LinkedList dataset,
        MmsValue* opOpn,
        MmsValue* opCls,
        bool opOpnVal,
        bool opClsVal,
        const char* eventName)
{
    printf("\n====================================\n");
    printf("New event: %s\n", eventName);
    printf("CSWI.OpOpn.general = %s\n", opOpnVal ? "true" : "false");
    printf("CSWI.OpCls.general = %s\n", opClsVal ? "true" : "false");
    printf("====================================\n");

    /*
     * 1. 更新 DataSet
     *
     * DataSet 順序：
     *   allData[0] = CSWI.OpOpn.general
     *   allData[1] = CSWI.OpCls.general
     */
    MmsValue_setBoolean(opOpn, opOpnVal);
    MmsValue_setBoolean(opCls, opClsVal);

    /*
     * 2. 狀態變化，所以 stNum + 1。
     *
     * 後面沒有再呼叫 increaseStNum 時，
     * 代表資料沒變，stNum 不變，sqNum 會由 publish 自動累加。
     */
    GoosePublisher_increaseStNum(publisher);

    /*
     * 3. 事件後從 minTime 開始重送，
     *    間隔逐次加倍，最後維持 maxTime。
     */
    uint32_t interval = MIN_TIME_MS;
    uint32_t elapsed = 0u;

    while (running && elapsed < STATE_HOLD_MS) {

        if (publishOnce(publisher, dataset, interval) == -1)
            break;

        Thread_sleep(interval);
        elapsed += interval;

        /*
         * 10 → 20 → 40 → ... → 2000 → 2000 → ...
         */
        interval = nextInterval(interval);
    }
}

int
main(int argc, char** argv)
{
    const char* interface = "eth0";

    if (argc > 1)
        interface = argv[1];

    signal(SIGINT, sigHandler);

    printf("=== Auto CSWI GOOSE Publisher ===\n");
    printf("Interface: %s\n", interface);
    printf("APPID: 0x03E8\n");
    printf("Destination MAC: 01-0C-CD-01-00-01\n");
    printf("minTime = %u ms\n", MIN_TIME_MS);
    printf("maxTime = %u ms\n", MAX_TIME_MS);
    printf("timeAllowedToLive = 2 * next response time\n");
    printf("State hold time = %u ms\n", STATE_HOLD_MS);
    printf("Press Ctrl+C to stop\n\n");

    /*
     * GOOSE communication parameters
     */
    CommParameters gooseCommParameters;

    memset(&gooseCommParameters, 0, sizeof(CommParameters));

    /*
     * 建議用一個明確的 APPID，
     * 之後 FPGA 可用 APPID = 1000 判斷是否訂閱這個 GOOSE stream。
     */
    gooseCommParameters.appId = 1000;

    /*
     * GOOSE multicast MAC:
     * 01-0C-CD-01-00-01
     */
    gooseCommParameters.dstAddress[0] = 0x01;
    gooseCommParameters.dstAddress[1] = 0x0C;
    gooseCommParameters.dstAddress[2] = 0xCD;
    gooseCommParameters.dstAddress[3] = 0x01;
    gooseCommParameters.dstAddress[4] = 0x00;
    gooseCommParameters.dstAddress[5] = 0x01;

    gooseCommParameters.vlanPriority = 4;
    gooseCommParameters.vlanId = 0;

    /*
     * 建立 Publisher。
     *
     * libiec61850 1.6 如果有 GoosePublisher_createEx，
     * 建議用 createEx 並且第三個參數設 false，
     * 代表不加 VLAN tag。
     *
     * 如果你的 1.6 編譯時說找不到 GoosePublisher_createEx，
     * 請把這段改成：
     *
     *   GoosePublisher publisher =
     *       GoosePublisher_create(&gooseCommParameters, interface);
     */
#if 1
    GoosePublisher publisher =
        GoosePublisher_createEx(&gooseCommParameters, interface, USE_VLAN_TAG);
#else
    GoosePublisher publisher =
        GoosePublisher_create(&gooseCommParameters, interface);
#endif

    if (publisher == NULL) {
        printf("ERROR: Failed to create GoosePublisher\n");
        printf("Check interface name and run with sudo\n");
        return 1;
    }

    /*
     * GOOSE identification
     *
     * 這些欄位會進到 GOOSE APDU。
     * FPGA 若有解析 gocbRef / datSet / goID，UART 會印出來。
     */
    GoosePublisher_setGoCbRef(
        publisher,
        "TestIED/LLN0$GO$gcbCSWI");

    GoosePublisher_setDataSetRef(
        publisher,
        "TestIED/LLN0$dsCSWI");

    GoosePublisher_setGoID(
        publisher,
        "CSWIControl");

    GoosePublisher_setConfRev(publisher, 1);

    GoosePublisher_setSimulation(publisher, false);
    GoosePublisher_setNeedsCommission(publisher, false);

    /*
     * 建立 DataSet。
     *
     * 注意：
     * GoosePublisher_publish 通常吃 LinkedList，
     * 不要用 MmsValue_createEmptyArray 當 dataset 傳入。
     */
    LinkedList dataset = LinkedList_create();

    MmsValue* opOpn = MmsValue_newBoolean(false);
    MmsValue* opCls = MmsValue_newBoolean(false);

    LinkedList_add(dataset, opOpn);
    LinkedList_add(dataset, opCls);

    /*
     * 初始化 publisher 狀態。
     */
    GoosePublisher_reset(publisher);

    
    /*
    * 先送初始 OFF 狀態 15 秒。
    * 這段期間不做快速重送，只用 maxTime = 2000 ms 週期傳送。
    */
    publishInitialOffState(
        publisher,
        dataset,
        opOpn,
        opCls);

     /*
     * 15 秒後才開始 OPEN / CLOSE 事件循環。
     * 自動 OPEN / CLOSE 交替。
     */
    while (running) {

        /*
         * OPEN event:
         *   allData[0] = CSWI.OpOpn.general = true
         *   allData[1] = CSWI.OpCls.general = false
         */
        publishState(
            publisher,
            dataset,
            opOpn,
            opCls,
            true,
            false,
            "OPEN");

        if (!running)
            break;

        /*
         * CLOSE event:
         *   allData[0] = CSWI.OpOpn.general = false
         *   allData[1] = CSWI.OpCls.general = true
         */
        publishState(
            publisher,
            dataset,
            opOpn,
            opCls,
            false,
            true,
            "CLOSE");
    }

    printf("\nStopping publisher...\n");

    LinkedList_destroyDeep(dataset, (LinkedListValueDeleteFunction) MmsValue_delete);

    GoosePublisher_destroy(publisher);

    printf("Done\n");

    return 0;
}