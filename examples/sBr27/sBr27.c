/*
 * sBr27_client.c
 * 測試：GetBRCBValues and EntryID
 * 參考：IEC 61850-7-2 Subclause 17.2.3.2.2.9
 *        IEC 61850-8-1 Subclause 17.1.2
 *
 * 編譯方式：
 *   gcc sBr27_client.c -o sBr27_client \
 *       -I/path/to/libiec61850/src/iec61850/inc \
 *       -I/path/to/libiec61850/src/hal/inc \
 *       -L/path/to/libiec61850/build -liec61850 -lpthread
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "iec61850_client.h"
#include "hal_thread.h"

/* ================================================================
 * 請根據你的測試環境修改以下參數
 * ================================================================ */
#define SERVER_IP        "192.168.50.142"     /* DUT IP 位址 */
#define SERVER_PORT      102                 /* MMS 預設 Port */
#define BRCB_REFERENCE   "projectDERDER3/LLN0.BR.B123456789012345678901234567890101"
#define DATASET_REF      "projectDERDER3/LLN0$A1234567890123456789012345678901"
#define INTEGRITY_PERIOD 200   /* Integrity Period: 5000 ms */
/* ================================================================ */

/* 全域變數：儲存從報告收到的最後一筆 EntryID */
static MmsValue* g_lastReportEntryId = NULL;
static int       g_reportCount       = 0;

/* ----------------------------------------------------------------
 * 輔助函數：以 Hex 格式印出 EntryID
 * ---------------------------------------------------------------- */
static void printEntryId(const char* label, MmsValue* entryId)
{
    if (entryId == NULL) {
        printf("  %s = (null)\n", label);
        return;
    }
    int len = MmsValue_getOctetStringSize(entryId);
    uint8_t* buf = MmsValue_getOctetStringBuffer(entryId);
    printf("  %s = 0x", label);
    for (int i = 0; i < len; i++)
        printf("%02X", buf[i]);
    printf(" (%d bytes)\n", len);
}

/* ----------------------------------------------------------------
 * 輔助函數：印出 BRCB 完整內容（對應每次 GetBRCBValues 的輸出）
 * ---------------------------------------------------------------- */
static void printBRCBValues(ClientReportControlBlock rcb, const char* label)
{
    printf("\n=== GetBRCBValues [%s] ===\n", label);
    printf("  RptEna  = %s\n",
           ClientReportControlBlock_getRptEna(rcb) ? "true" : "false");
    printf("  TrgOps  = 0x%02X\n",
           ClientReportControlBlock_getTrgOps(rcb));
    printf("  IntgPd  = %u ms\n",
           ClientReportControlBlock_getIntgPd(rcb));
    printf("  OptFlds = 0x%04X\n",
           ClientReportControlBlock_getOptFlds(rcb));
    printEntryId("EntryID", ClientReportControlBlock_getEntryId(rcb));
    printf("=========================================\n");
}

/* ----------------------------------------------------------------
 * 報告回呼函數：每次收到報告時被呼叫
 * ---------------------------------------------------------------- */
static void reportHandler(void* parameter, ClientReport report)
{
    g_reportCount++;
    printf("[Report #%d received]", g_reportCount);

    if (ClientReport_hasSeqNum(report))
        printf(" SeqNum=%u", ClientReport_getSeqNum(report));

    MmsValue* entryId = ClientReport_getEntryId(report);
    if (entryId != NULL) {
        /* 儲存這筆 EntryID（複製一份供後續步驟使用） */
        if (g_lastReportEntryId != NULL)
            MmsValue_delete(g_lastReportEntryId);
        g_lastReportEntryId = MmsValue_clone(entryId);
        printEntryId("", entryId);
    } else {
        printf("\n");
    }
}

/* ----------------------------------------------------------------
 * 輔助函數：連線到 DUT
 * ---------------------------------------------------------------- */
static IedConnection connectToDUT(int localDetail)
{
    IedClientError error;
    IedConnection con = IedConnection_create();

    MmsConnection mmsConn = IedConnection_getMmsConnection(con);
    MmsConnection_setLocalDetail(mmsConn, localDetail);

    IedConnection_connect(con, &error, SERVER_IP, SERVER_PORT);
    if (error != IED_ERROR_OK) {
        printf("ERROR: 連線失敗 (error=%d)\n", error);
        IedConnection_destroy(con);
        return NULL;
    }
    printf("  連線成功 -> %s:%d\n", SERVER_IP, SERVER_PORT);
    return con;
}

/* ================================================================
 * main：sBr27 測試主流程
 * ================================================================ */
int main(int argc, char** argv)
{
    IedClientError error;
    IedConnection  con = NULL;
    ClientReportControlBlock rcb = NULL;

    printf("====================================\n");
    printf("  sBr27: GetBRCBValues and EntryID  \n");
    printf("====================================\n");

    /* ============================================================
     * STEP 1: 連線、Reserve BRCB、設定所有 OptFlds、
     *         TrgOps (data-change + integrity)、IntgPd
     * ============================================================ */
    printf("\n[STEP 1] 建立連線，Reserve 並設定 BRCB...\n");

    con = connectToDUT(65000);
    if (con == NULL) goto cleanup;

    /* 讀取 BRCB（同時 Reserve：libiec61850 在 getRCBValues 時自動 reserve） */
    rcb = IedConnection_getRCBValues(con, &error, BRCB_REFERENCE, NULL);
    if (error != IED_ERROR_OK || rcb == NULL) {
        printf("ERROR: GetBRCBValues 失敗 (error=%d)\n", error);
        goto cleanup;
    }

    ClientReportControlBlock_setResvTms(rcb, 10);
    /* 設定所有 Optional Fields（OptFlds）：
     * SEQ_NUM | TIME_STAMP | DATA_SET | REASON_FOR_INCLUSION
     * | DATA_REFERENCE | ENTRY_ID | CONF_REV | BUF_OVF        */
    ClientReportControlBlock_setOptFlds(rcb,
        RPT_OPT_SEQ_NUM            |
        RPT_OPT_TIME_STAMP         |
        RPT_OPT_DATA_SET           |
        RPT_OPT_REASON_FOR_INCLUSION |
        RPT_OPT_DATA_REFERENCE     |
        RPT_OPT_ENTRY_ID           |
        RPT_OPT_CONF_REV           |
        RPT_OPT_BUFFER_OVERFLOW);

    /* 設定 TrgOps：data-change + integrity */
    ClientReportControlBlock_setTrgOps(rcb,
        TRG_OPT_DATA_CHANGED | TRG_OPT_INTEGRITY);

    /* 設定 Integrity Period */
    ClientReportControlBlock_setIntgPd(rcb, INTEGRITY_PERIOD);

    /* 設定 Dataset */
    ClientReportControlBlock_setDataSetReference(rcb, DATASET_REF);

    /* 寫入設定到 DUT */
    IedConnection_setRCBValues(con, &error, rcb,
        RCB_ELEMENT_RESV_TMS |
        RCB_ELEMENT_OPT_FLDS |
        RCB_ELEMENT_TRG_OPS  |
        RCB_ELEMENT_INTG_PD  |
        RCB_ELEMENT_DATSET,
        true);
    if (error != IED_ERROR_OK) {
        printf("ERROR: SetBRCBValues 設定參數失敗 (error=%d)\n", error);
        goto cleanup;
    }
    printf("  BRCB 設定完成（OptFlds=all, TrgOps=DataChange+Integrity）\n");

    /* 安裝報告回呼函數 */
    IedConnection_installReportHandler(con, BRCB_REFERENCE,
        ClientReportControlBlock_getRptId(rcb),
        reportHandler, NULL);

    /* ============================================================
     * STEP 2: 啟用 BRCB (RptEna = true)
     * ============================================================ */
    printf("\n[STEP 2] 啟用 BRCB (RptEna=true)...\n");

    ClientReportControlBlock_setRptEna(rcb, true);
    IedConnection_setRCBValues(con, &error, rcb, RCB_ELEMENT_RPT_ENA, true);
    if (error != IED_ERROR_OK) {
        printf("ERROR: 啟用 BRCB 失敗 (error=%d)\n", error);
        goto cleanup;
    }
    printf("  BRCB 已啟用。\n");

    /* ============================================================
     * STEP 3: 等待 Equipment Simulator 產生 data-change 事件
     * 【預期結果】: DUT 送出 data-change 和 integrity reports
     * ============================================================ */
    printf("\n[STEP 3] 等待 Equipment Simulator 產生 data-change...\n");
    printf("  (等待 30 秒，包含至少一次 IntgPd=5秒 的 integrity report)\n");
    printf("  預期結果: DUT 送出 data-change 和 integrity reports\n");
    Thread_sleep(30000);
    printf("  共收到報告數: %d\n", g_reportCount);

    if (g_lastReportEntryId != NULL) {
        printEntryId("  最後收到報告的 EntryID", g_lastReportEntryId);
    } else {
        printf("  WARNING: 未收到任何報告，請確認 Equipment Simulator 有產生 data-change\n");
    }

    /* ============================================================
     * STEP 4: Client 請求 Release（斷開連線）
     * ============================================================ */
    printf("\n[STEP 4] Client 執行 Release（斷開連線）...\n");

    IedConnection_release(con, &error);
    if (error != IED_ERROR_OK)
        printf("  WARNING: Release 回傳 error=%d（繼續關閉）\n", error);

    IedConnection_close(con);
    IedConnection_destroy(con);
    con = NULL;

    ClientReportControlBlock_destroy(rcb);
    rcb = NULL;

    printf("  連線已關閉。\n");

    /* ============================================================
     * STEP 5: Equipment Simulator 繼續產生更多 data-change
     *         （此時 DUT 應繼續在 buffer 中累積報告）
     * ============================================================ */
    printf("\n[STEP 5] 等待 Equipment Simulator 繼續產生 data-change (30秒)...\n");
    printf("  (DUT 斷線期間應繼續 buffer 報告)\n");
    Thread_sleep(30000);

    /* ============================================================
     * STEP 6: Client 重新建立連線
     * ============================================================ */
    printf("\n[STEP 6] 重新建立連線 (Re-establish association)...\n");

    con = connectToDUT(480);
    if (con == NULL) goto cleanup;

    /* ============================================================
     * STEP 7: GetBRCBValues
     * 【預期結果】: DUT 回傳 EntryID = buffer 中最後一筆 entry
     *              此 EntryID 應與 STEP 3 最後收到報告的 EntryID 不同
     *              (因為 STEP 5 期間有新的 data-change 進入 buffer)
     * ============================================================ */
    printf("\n[STEP 7] GetBRCBValues (第一次，查看斷線後 buffer 狀態)...\n");
    printf("  預期: EntryID = buffer 最後一筆（應與 STEP 3 最後報告 EntryID 不同）\n");

    rcb = IedConnection_getRCBValues(con, &error, BRCB_REFERENCE, NULL);
    if (error != IED_ERROR_OK || rcb == NULL) {
        printf("ERROR: GetBRCBValues 失敗 (error=%d)\n", error);
        goto cleanup;
    }
    printBRCBValues(rcb, "STEP 7");

    /* 安裝報告回呼（新連線需要重新安裝） */
    IedConnection_installReportHandler(con, BRCB_REFERENCE,
        ClientReportControlBlock_getRptId(rcb),
        reportHandler, NULL);

    /* ============================================================
     * STEP 8: Reserve BRCB 並設定 EntryID = 上次收到的報告 EntryID
     *         （告訴 DUT：從這個 EntryID 之後的報告補傳給我）
     * ============================================================ */
    printf("\n[STEP 8] 設定 EntryID = 最後收到報告的 EntryID...\n");

    if (g_lastReportEntryId == NULL) {
        printf("  WARNING: 沒有收到報告 EntryID，改用全零 EntryID\n");
        g_lastReportEntryId = MmsValue_newOctetString(8, 8);
        memset(MmsValue_getOctetStringBuffer(g_lastReportEntryId), 0, 8);
    }
    printEntryId("  設定的 EntryID", g_lastReportEntryId);

    ClientReportControlBlock_setResvTms(rcb, 10);
    ClientReportControlBlock_setEntryId(rcb, g_lastReportEntryId);
    IedConnection_setRCBValues(con, &error, rcb, 
        RCB_ELEMENT_RESV_TMS |
        RCB_ELEMENT_ENTRY_ID, 
        true);
    if (error != IED_ERROR_OK) {
        printf("ERROR: SetBRCBValues EntryID 失敗 (error=%d)\n", error);
        goto cleanup;
    }

    /* 同時重新設定 OptFlds、TrgOps、IntgPd */
    ClientReportControlBlock_setOptFlds(rcb,
        RPT_OPT_SEQ_NUM | RPT_OPT_TIME_STAMP | RPT_OPT_DATA_SET |
        RPT_OPT_REASON_FOR_INCLUSION | RPT_OPT_DATA_REFERENCE |
        RPT_OPT_ENTRY_ID | RPT_OPT_CONF_REV | RPT_OPT_BUFFER_OVERFLOW);
    ClientReportControlBlock_setTrgOps(rcb,
        TRG_OPT_DATA_CHANGED | TRG_OPT_INTEGRITY);
    ClientReportControlBlock_setIntgPd(rcb, INTEGRITY_PERIOD);

    IedConnection_setRCBValues(con, &error, rcb,
        RCB_ELEMENT_OPT_FLDS | RCB_ELEMENT_TRG_OPS | RCB_ELEMENT_INTG_PD,
        true);
    printf("  BRCB 參數重新設定完成。\n");

    /* ============================================================
     * STEP 9: 啟用 BRCB，等待至少 1 個 buffered report
     * 【預期結果】: DUT 傳送 buffer 中尚未傳過的報告
     * ============================================================ */
    printf("\n[STEP 9] 啟用 BRCB，等待 buffered reports...\n");
    printf("  預期: DUT 補傳 STEP 4 斷線後累積的報告\n");

    int reportsBefore = g_reportCount;
    ClientReportControlBlock_setRptEna(rcb, true);
    IedConnection_setRCBValues(con, &error, rcb, RCB_ELEMENT_RPT_ENA, true);
    if (error != IED_ERROR_OK) {
        printf("ERROR: 啟用 BRCB 失敗 (error=%d)\n", error);
        goto cleanup;
    }


    /* ============================================================
     * STEP 10: DUT 傳送 buffered reports 時做 GetBRCBValues
     * 【預期結果】: EntryID = 最後已格式化並排隊傳輸的 entry
     * ============================================================ */
    printf("\n[STEP 10] DUT 傳送 buffered reports 同時 GetBRCBValues...\n");
    printf("  預期: EntryID = 最後已格式化並排隊傳輸的 entry\n");

    IedConnection_getRCBValues(con, &error, BRCB_REFERENCE, rcb);
    if (error != IED_ERROR_OK)
        printf("ERROR: GetBRCBValues 失敗 (error=%d)\n", error);
    else
        printBRCBValues(rcb, "STEP 10");

    /* 繼續等一段時間讓所有 buffered reports 傳完 */
    Thread_sleep(3000);

    /* ============================================================
     * STEP 11: 停用 BRCB (RptEna = false)
     * ============================================================ */
    printf("\n[STEP 11] 停用 BRCB (RptEna=false)...\n");

    ClientReportControlBlock_setRptEna(rcb, false);
    IedConnection_setRCBValues(con, &error, rcb, RCB_ELEMENT_RPT_ENA, true);
    if (error != IED_ERROR_OK)
        printf("ERROR: 停用 BRCB 失敗 (error=%d)\n", error);
    else
        printf("  BRCB 已停用。\n");

    /* ============================================================
     * STEP 12: GetBRCBValues
     * 【預期結果】: EntryID = buffer 中最後一筆 entry 的 ID
     * ============================================================ */
    printf("\n[STEP 12] GetBRCBValues...\n");
    printf("  預期: EntryID = buffer 中最後一筆 entry\n");

    IedConnection_getRCBValues(con, &error, BRCB_REFERENCE, rcb);
    if (error != IED_ERROR_OK)
        printf("ERROR: GetBRCBValues 失敗 (error=%d)\n", error);
    else
        printBRCBValues(rcb, "STEP 12");

    /* ============================================================
     * STEP 13: 設定 EntryID = 0（全零 8 bytes）
     *          意義：從 buffer 最開頭重新傳所有報告
     * ============================================================ */
    printf("\n[STEP 13] 設定 EntryID = 0 (全零，代表從頭開始)...\n");
    {
        MmsValue* zeroEntryId = MmsValue_newOctetString(8, 8);
        memset(MmsValue_getOctetStringBuffer(zeroEntryId), 0x00, 8);

        ClientReportControlBlock_setEntryId(rcb, zeroEntryId);
        IedConnection_setRCBValues(con, &error, rcb,
                                   RCB_ELEMENT_ENTRY_ID, true);
        MmsValue_delete(zeroEntryId);

        if (error != IED_ERROR_OK)
            printf("ERROR: 設定 EntryID=0 失敗 (error=%d)\n", error);
        else
            printf("  EntryID 已設為 0（全零）。\n");
    }

    /* ============================================================
     * STEP 14: GetBRCBValues
     * 【預期結果】: EntryID = buffer 中最後一筆 entry 的 ID
     * ============================================================ */
    printf("\n[STEP 14] GetBRCBValues...\n");
    printf("  預期: EntryID = buffer 中最後一筆 entry\n");

    IedConnection_getRCBValues(con, &error, BRCB_REFERENCE, rcb);
    if (error != IED_ERROR_OK)
        printf("ERROR: GetBRCBValues 失敗 (error=%d)\n", error);
    else
        printBRCBValues(rcb, "STEP 14");

    /* ============================================================
     * STEP 15: 啟用 BRCB
     * 【預期結果】: DUT 傳送所有 buffer 報告（包含之前已傳的）
     *              因為 EntryID=0，所以從頭開始重送
     * ============================================================ */
    printf("\n[STEP 15] 啟用 BRCB（EntryID=0，DUT 從頭重送所有 buffer）...\n");
    printf("  預期: DUT 傳送 buffer 中所有報告（包含先前已傳的）\n");

    reportsBefore = g_reportCount;
    ClientReportControlBlock_setRptEna(rcb, true);
    IedConnection_setRCBValues(con, &error, rcb, RCB_ELEMENT_RPT_ENA, true);
    if (error != IED_ERROR_OK) {
        printf("ERROR: 啟用 BRCB 失敗 (error=%d)\n", error);
        goto cleanup;
    }
    printf("  等待 DUT 重送所有 buffer 報告 ...\n");
    
    printf("  收到新報告數: %d\n", g_reportCount - reportsBefore);

    /* ============================================================
     * STEP 16: 在 DUT 傳送 buffered reports 時 GetBRCBValues
     * 【預期結果】: EntryID = 最後已格式化並排隊傳輸的 entry
     * ============================================================ */
    printf("\n[STEP 16] DUT 傳送 buffered reports 同時 GetBRCBValues...\n");
    printf("  預期: EntryID = 最後已格式化並排隊傳輸的 entry\n");

    IedConnection_getRCBValues(con, &error, BRCB_REFERENCE, rcb);
    if (error != IED_ERROR_OK)
        printf("ERROR: GetBRCBValues 失敗 (error=%d)\n", error);
    else
        printBRCBValues(rcb, "STEP 16");

    Thread_sleep(3000);  /* 等待所有 buffered reports 傳完 */

    /* ============================================================
     * STEP 17: 停用 BRCB
     * ============================================================ */
    printf("\n[STEP 17] 停用 BRCB (RptEna=false)...\n");

    ClientReportControlBlock_setRptEna(rcb, false);
    IedConnection_setRCBValues(con, &error, rcb, RCB_ELEMENT_RPT_ENA, true);
    if (error != IED_ERROR_OK)
        printf("ERROR: 停用 BRCB 失敗 (error=%d)\n", error);
    else
        printf("  BRCB 已停用。\n");

    printf("\n==============================================\n");
    printf("  sBr27 測試流程全部完成！\n");
    printf("  總共收到報告數: %d\n", g_reportCount);
    printf("==============================================\n");

cleanup:
    if (g_lastReportEntryId) {
        MmsValue_delete(g_lastReportEntryId);
        g_lastReportEntryId = NULL;
    }
    if (rcb) {
        ClientReportControlBlock_destroy(rcb);
        rcb = NULL;
    }
    if (con) {
        IedConnection_close(con);
        IedConnection_destroy(con);
    }
    return 0;
}
