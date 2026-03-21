/**
 * sBrN1 測試程式：Incorrect GetBRCBValues
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "iec61850_client.h"

/* =====================填入設定 ========================= */
#define DUT_IP            "192.168.50.142"         /* ← 改成你的 Server IP   */
#define DUT_PORT          102                      /* ← 改成你的 Server Port */
#define UNKNOWN_BRCB_REF  "projectDERDER3/LLN0.BR.TestsBrN1"  /* ← 確保這個路徑在你的 DUT 上不存在 */
/* ============================================================= */

int main(void)
{
    printf("=== sBrN1: Incorrect GetBRCBValues ===\n");
    printf("DUT       : %s:%d\n", DUT_IP, DUT_PORT);
    printf("BRCB Ref  : %s\n\n", UNKNOWN_BRCB_REF);

    /* 1. 建立連線 */
    IedClientError error;
    IedConnection  con = IedConnection_create();

    IedConnection_connect(con, &error, DUT_IP, DUT_PORT);
    if (error != IED_ERROR_OK) {
        printf("[連線失敗] 錯誤碼: %d\n", (int)error);
        printf("結果: INCONCLUSIVE(無法連線到 DUT)\n");
        IedConnection_destroy(con);
        return 1;
    }
    printf("[連線成功]\n\n");

    /* 2. 對不存在的 BRCB 路徑發出 GetBRCBValues */
    ClientReportControlBlock rcb =
        IedConnection_getRCBValues(con, &error, UNKNOWN_BRCB_REF, NULL);

    if (rcb != NULL)
        ClientReportControlBlock_destroy(rcb);

    /* 3. 判斷結果 */
    printf("[DUT 回傳錯誤碼] %d\n\n", (int)error);

    if (error == IED_ERROR_OBJECT_DOES_NOT_EXIST) {
        printf("結果: PASSED\n");
        printf("DUT 正確回傳 object-non-existent\n");
    } else if (error == IED_ERROR_OK) {
        printf("結果: FAILED\n");
        printf("DUT 竟然成功回傳了不存在的 BRCB！\n");
    } else if (error == IED_ERROR_TIMEOUT ||
               error == IED_ERROR_CONNECTION_LOST) {
        printf("結果: INCONCLUSIVE\n");
        printf("連線問題，無法判斷 DUT 行為\n");
    } else {
        printf("結果: FAILED\n");
        printf("DUT 回傳了錯誤，但不是 object-non-existent\n");
        printf("(收到的錯誤碼: %d，不符合規範要求)\n", (int)error);
    }

    /* 4. 釋放資源 */
    IedConnection_close(con);
    IedConnection_destroy(con);

    return (error == IED_ERROR_OBJECT_DOES_NOT_EXIST) ? 0 : 1;
}