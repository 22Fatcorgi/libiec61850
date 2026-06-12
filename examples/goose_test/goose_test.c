/*
 * goose_publisher_example_minimal.c
 * run as root: sudo ./goose_pub eth0
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "mms_value.h"
#include "goose_publisher.h"
#include "hal_thread.h"

static void
publishWithTal(GoosePublisher publisher, LinkedList dataSetValues, int talMs, const char* msg)
{
    GoosePublisher_setTimeAllowedToLive(publisher, talMs);

    int ret = GoosePublisher_publish(publisher, dataSetValues);

    if (ret == -1)
        printf("%s publish failed, TAL=%d ms\n", msg, talMs);
    else
        printf("%s publish ok, TAL=%d ms\n", msg, talMs);
}

int main(int argc, char **argv)
{
    char *interface = (argc > 1) ? argv[1] : "eth0";

    printf("Using interface: %s\n", interface);

    LinkedList dataSetValues = LinkedList_create();

    /*
     * 重要：
     * 直接保留 MmsValue* 指標。
     * 之後要改 dataset value 時，直接改 val1。
     */
    MmsValue* val1 = MmsValue_newIntegerFromInt32(1234);
    MmsValue* val2 = MmsValue_newBinaryTime(false);
    MmsValue* val3 = MmsValue_newIntegerFromInt32(5678);

    LinkedList_add(dataSetValues, val1);
    LinkedList_add(dataSetValues, val2);
    LinkedList_add(dataSetValues, val3);

    CommParameters gooseCommParameters;

    memset(&gooseCommParameters, 0, sizeof(CommParameters));

    gooseCommParameters.appId = 1000;

    /* GOOSE multicast MAC */
    gooseCommParameters.dstAddress[0] = 0x01;
    gooseCommParameters.dstAddress[1] = 0x0c;
    gooseCommParameters.dstAddress[2] = 0xcd;
    gooseCommParameters.dstAddress[3] = 0x01;
    gooseCommParameters.dstAddress[4] = 0x00;
    gooseCommParameters.dstAddress[5] = 0x01;

    /* Untagged GOOSE */
    gooseCommParameters.vlanId = 0;
    gooseCommParameters.vlanPriority = 0;

    GoosePublisher publisher = GoosePublisher_create(&gooseCommParameters, interface);

    if (publisher == NULL) {
        printf("Failed to create GOOSE publisher.\n");
        printf("Check interface name and run with root permission.\n");
        LinkedList_destroyDeep(dataSetValues, (LinkedListValueDeleteFunction) MmsValue_delete);
        return -1;
    }

    GoosePublisher_setGoCbRef(publisher, "simpleIOGenericIO/LLN0$GO$gcbAnalogValues");
    GoosePublisher_setConfRev(publisher, 1);
    GoosePublisher_setDataSetRef(publisher, "simpleIOGenericIO/LLN0$AnalogValues");

    printf("Start publishing GOOSE...\n");

    /*
     * 平常狀態：
     * 每 1000 ms 發一次。
     * timeAllowedToLive 設成 2000 ms，避免 subscriber 中間 timeout。
     */
    const int stableIntervalMs = 1000;
    const int stableTalMs = 2000;

    /*
     * 事件後重送間隔：
     * 一開始很快，後面慢慢拉長。
     */
    int retransmitIntervalsMs[] = {4, 8, 16, 32, 64, 128, 256, 500};
    int retransmitCount = sizeof(retransmitIntervalsMs) / sizeof(retransmitIntervalsMs[0]);

    for (int i = 0; i < 30; i++) {

        /*
         * i 從 0 開始。
         * i == 14 代表第 15 筆。
         */
        if (i == 14) {

            printf("\n[%02d] EVENT: dataset value changed 1234 -> 4321\n", i + 1);

            MmsValue_setInt32(val1, 4321);

            /*
             * DataSet 狀態變化，stNum 要增加。
             * libiec61850 會讓 sqNum 回到 0。
             */
            GoosePublisher_increaseStNum(publisher);

            printf("[%02d] value now = %d\n", i + 1, MmsValue_toInt32(val1));

            /*
             * 事件後快速重送。
             * 第一次會馬上 publish，之後依 intervals 慢慢拉長。
             */
            for (int k = 0; k < retransmitCount; k++) {

                int intervalMs = retransmitIntervalsMs[k];

                /*
                 * TAL 原則上要大於下一次預期封包間隔。
                 * 這裡用 interval * 2，但最低給 100 ms，避免 TAL 太小。
                 */
                int talMs = intervalMs * 2;

                if (talMs < 100)
                    talMs = 100;

                char logMsg[128];
                snprintf(logMsg, sizeof(logMsg),
                         "  event retransmit %d/%d, interval=%d ms",
                         k + 1, retransmitCount, intervalMs);

                publishWithTal(publisher, dataSetValues, talMs, logMsg);

                Thread_sleep(intervalMs);
            }

            printf("[%02d] EVENT retransmission finished, return to stable publishing\n\n", i + 1);

            /*
             * 這次 loop 已經在事件重送裡 publish 很多包了，
             * 所以不要再執行下面的 stable publish。
             */
            continue;
        }

        /*
         * 平常穩定狀態發送。
         */
        char logMsg[64];
        snprintf(logMsg, sizeof(logMsg), "[%02d] stable", i + 1);

        publishWithTal(publisher, dataSetValues, stableTalMs, logMsg);

        Thread_sleep(stableIntervalMs);
    }

    GoosePublisher_destroy(publisher);
    LinkedList_destroyDeep(dataSetValues, (LinkedListValueDeleteFunction) MmsValue_delete);

    printf("Done.\n");
    return 0;
}