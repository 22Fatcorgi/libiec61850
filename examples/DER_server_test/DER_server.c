#include "iec61850_server.h"
#include "hal_thread.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <inttypes.h>
#include <unistd.h>
#include <pthread.h>
#include "model.h"
#define MAX_BUFFER_SIZE 1024
#define RECEIVING_PORT 5000 // 樹莓派的UDP接收端口號
#define SENDING_PORT 8008
#include "static_model.h"
#include <json-c/json.h>
#include "model.c"
#include <sys/time.h>

Quality q = QUALITY_VALIDITY_GOOD;
extern IedModel iedModel;
static IedServer iedServer = NULL;
//char message[50];
bool boolean_control_value;

int int32_control_value;
int float_found;
int boolean_found;
int int_found;
int do_the_loop;
float float_control_value;
void udp_sender(const char *ip, const char *message1, const char *message2, const char *message3, const char *message4, const char *message5, const char *message6, const char *message7, const char *message8);
int running = 1;
static uint32_t dpc_state = 0;
static float SOC = 0;
static uint8_t ctl ;
static MmsValue* iElem;
Dbpos Dbpos_value;
static double previous_values[6] = { NAN, NAN, NAN, NAN, NAN ,NAN};
int operation_delay;
bool state;
static int32_t Anout ;


void
sigint_handler(int signalId)
{
    running = 0;
}
void *delay_function(void* arg){
    uint64_t timeStamp = Hal_getTimeInMs();
    if(operation_delay == 1){
                
        dpc_state = 0;
        IedServer_updateBitStringAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_DPCSO1_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_DPCSO1_t, timeStamp);
        
        if(state){
            dpc_state = 2;

        }
        else{
            dpc_state = 1;
        }
        timeStamp = Hal_getTimeInMs();
        IedServer_updateDbposValue(iedServer, IEDMODEL_DER3_GGIO1_DPCSO1_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_DPCSO1_t, timeStamp);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_GGIO1_DPCSO1_q, q);
        
        
        }
    if(operation_delay == 2){
                
        dpc_state = 0;
        IedServer_updateBitStringAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_Pos_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_Pos_t, timeStamp);
        
        if(state){
            dpc_state = 2;

        }
        else{
            dpc_state = 1;
        }
        timeStamp = Hal_getTimeInMs();
        IedServer_updateDbposValue(iedServer, IEDMODEL_DER3_CSWI1_Pos_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_Pos_t, timeStamp);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_CSWI1_Pos_q, q);
        
        
        }
    if(operation_delay == 3){
                
        dpc_state = 0;
        IedServer_updateBitStringAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosA_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosA_t, timeStamp);
        
        if(state){
            dpc_state = 2;

        }
        else{
            dpc_state = 1;
        }
        timeStamp = Hal_getTimeInMs();
        IedServer_updateDbposValue(iedServer, IEDMODEL_DER3_CSWI1_PosA_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosA_t, timeStamp);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_CSWI1_PosA_q, q);
        
        
        }
        if(operation_delay == 4){
                
        dpc_state = 0;
        IedServer_updateBitStringAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosB_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosB_t, timeStamp);
        
        if(state){
            dpc_state = 2;

        }
        else{
            dpc_state = 1;
        }
        timeStamp = Hal_getTimeInMs();
        IedServer_updateDbposValue(iedServer, IEDMODEL_DER3_CSWI1_PosB_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosB_t, timeStamp);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_CSWI1_PosB_q, q);
        
        
        }
        if(operation_delay == 5){
                
        dpc_state = 0;
        IedServer_updateBitStringAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosC_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosC_t, timeStamp);
        
        if(state){
            dpc_state = 2;

        }
        else{
            dpc_state = 1;
        }
        timeStamp = Hal_getTimeInMs();
        IedServer_updateDbposValue(iedServer, IEDMODEL_DER3_CSWI1_PosC_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_PosC_t, timeStamp);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_CSWI1_PosC_q, q);
        
        
        }
        if(operation_delay == 6){
                
        dpc_state = 0;
        IedServer_updateBitStringAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_Pos_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_Pos_t, timeStamp);
        ctl=(uint8_t)dpc_state;
        if(state){
            dpc_state = 2;

        }
        else{
            dpc_state = 1;
        }
        timeStamp = Hal_getTimeInMs();
        IedServer_updateDbposValue(iedServer, IEDMODEL_DER3_XCBR1_Pos_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_Pos_t, timeStamp);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XCBR1_Pos_q, q);
        ctl=(uint8_t)dpc_state;

        
        }
        if(operation_delay == 7){
                
        dpc_state = 0;
        IedServer_updateBitStringAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_Pos_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_Pos_t, timeStamp);
        
        if(state){
            dpc_state = 2;

        }
        else{
            dpc_state = 1;
        }
        timeStamp = Hal_getTimeInMs();
        IedServer_updateDbposValue(iedServer, IEDMODEL_DER3_XSWI1_Pos_stVal, dpc_state);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_Pos_t, timeStamp);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XSWI1_Pos_q, q);
        
        
        }
    return NULL;
}

static void
printValue(char* name, MmsValue* value)
{
    char buf[1000];

    MmsValue_printToBuffer(value, buf, 1000);

    printf("%s: %s\n", name, buf);
} 

static ControlHandlerResult
controlHandlerForBinaryOutput(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    if (test)
        return CONTROL_RESULT_FAILED;
    /*for (int i = 0; i < MmsValue_getArraySize(value); i++) {
        printf("  [%i]", i);
        printf("%s\n",parameter);
        printValue("", MmsValue_getElement(value, i));
    }
    if (MmsValue_getType(value) == MMS_BOOLEAN) {

            

        if (MmsValue_getBoolean(value))
            printf("%d\n",MmsValue_getBoolean(value));
            
        else
            printf("%d\n",MmsValue_getBoolean(value));
    }
    else
        return CONTROL_RESULT_FAILED;
*/
    uint64_t timeStamp = Hal_getTimeInMs()+8;

    if (parameter == IEDMODEL_DER3_GGIO1_SPCSO1) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_q, q);
        
        bool start_flag = MmsValue_getBoolean(value);  // 取得 true / false
        const char* json_msg;

        if (start_flag) {
            json_msg = "{\"start_flag\":1}";
        } else {
            json_msg = "{\"start_flag\":0}";
        }
        
        
        }
    
    if (parameter == IEDMODEL_DER3_GGIO1_DPCSO1) {
        dpc_state = 0;
        operation_delay = 1;
        
        state = MmsValue_getBoolean(value);
        
        pthread_t delay_thread;
        pthread_create(&delay_thread, NULL, delay_function, NULL);
        pthread_detach(delay_thread);
    

    }
    
    if (parameter == IEDMODEL_DER3_CSWI1_LocSta) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_LocSta_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_CSWI1_LocSta_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_CSWI1_LocSta_q, q);
    }
    if (parameter == IEDMODEL_DER3_CSWI1_Pos) {
        dpc_state = 0;
        operation_delay = 2;
        
        state = MmsValue_getBoolean(value);
        
        pthread_t delay_thread;
        pthread_create(&delay_thread, NULL, delay_function, NULL);
        pthread_detach(delay_thread);
    }
    if (parameter == IEDMODEL_DER3_CSWI1_PosA) {
        dpc_state = 0;
        operation_delay = 3;
        
        state = MmsValue_getBoolean(value);
        
        pthread_t delay_thread;
        pthread_create(&delay_thread, NULL, delay_function, NULL);
        pthread_detach(delay_thread);
    }
    if (parameter == IEDMODEL_DER3_CSWI1_PosB) {
        dpc_state = 0;
        operation_delay = 4;
        
        state = MmsValue_getBoolean(value);
        
        pthread_t delay_thread;
        pthread_create(&delay_thread, NULL, delay_function, NULL);
        pthread_detach(delay_thread);
    }
    if (parameter == IEDMODEL_DER3_CSWI1_PosC) {
        dpc_state = 0;
        operation_delay = 5;
        
        state = MmsValue_getBoolean(value);
        
        pthread_t delay_thread;
        pthread_create(&delay_thread, NULL, delay_function, NULL);
        pthread_detach(delay_thread);
    } 
    
 if (parameter == IEDMODEL_DER3_XCBR1_Pos) {
        dpc_state = 0;
        operation_delay = 6;
        
        state = MmsValue_getBoolean(value);
        ctl=(uint8_t)state;

        pthread_t delay_thread;
        pthread_create(&delay_thread, NULL, delay_function, NULL);
        pthread_detach(delay_thread);
    } 

    if (parameter == IEDMODEL_DER3_XCBR1_LocSta) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_LocSta_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_LocSta_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XCBR1_LocSta_q, q);
    }

    if (parameter == IEDMODEL_DER3_XCBR1_BlkOpn) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_BlkOpn_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_BlkOpn_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XCBR1_BlkOpn_q, q);
    }

    if (parameter == IEDMODEL_DER3_XCBR1_BlkCls) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_BlkCls_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_BlkCls_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XCBR1_BlkCls_q, q);
    }

    if (parameter == IEDMODEL_DER3_XCBR1_ChaMotEna) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_ChaMotEna_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_ChaMotEna_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XCBR1_ChaMotEna_q, q);
    }

    if (parameter == IEDMODEL_DER3_XSWI1_Pos) {
        dpc_state = 0;
        operation_delay = 7;
        
        state = MmsValue_getBoolean(value);
        pthread_t delay_thread;
        pthread_create(&delay_thread, NULL, delay_function, NULL);
        pthread_detach(delay_thread);
    }
    
    if (parameter == IEDMODEL_DER3_XSWI1_LocSta) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_LocSta_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_LocSta_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XSWI1_LocSta_q, q);
    }

    if (parameter == IEDMODEL_DER3_XSWI1_BlkOpn) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_BlkOpn_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_BlkOpn_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XSWI1_BlkOpn_q, q);
    }

    if (parameter == IEDMODEL_DER3_XSWI1_BlkCls) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_BlkCls_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_BlkCls_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XSWI1_BlkCls_q, q);
    }

    if (parameter == IEDMODEL_DER3_XSWI1_ChaMotEna) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_ChaMotEna_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_XSWI1_ChaMotEna_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_XSWI1_ChaMotEna_q, q);
    }

    if (parameter == IEDMODEL_DER3_DVER1_ClcStr) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DVER1_ClcStr_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DVER1_ClcStr_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DVER1_ClcStr_q, q);
    }

    if (parameter == IEDMODEL_DER3_DECP1_ClcStr) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DECP1_ClcStr_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DECP1_ClcStr_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DECP1_ClcStr_q, q);
    }

    if (parameter == IEDMODEL_DER3_DPCC1_ClcStr) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DPCC1_ClcStr_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DPCC1_ClcStr_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DPCC1_ClcStr_q, q);
    }

    if (parameter == IEDMODEL_DER3_SBAT1_ClcStr) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_SBAT1_ClcStr_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_SBAT1_ClcStr_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_SBAT1_ClcStr_q, q);
    }

    if (parameter == IEDMODEL_DER3_SBAT1_CelVolRs) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_SBAT1_CelVolRs_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_SBAT1_CelVolRs_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_SBAT1_CelVolRs_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_LocSta) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_LocSta_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_LocSta_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_LocSta_q, q);
    }
    
    if (parameter == IEDMODEL_DER3_DSTO1_ClcStr) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_ClcStr_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_ClcStr_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_ClcStr_q, q);
    }
    
    if (parameter == IEDMODEL_DER3_DSTO1_CmdBlk) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_CmdBlk_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_CmdBlk_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_CmdBlk_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_AuthConn) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_AuthConn_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_AuthConn_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_AuthConn_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_CeaEgzCtl) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_CeaEgzCtl_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_CeaEgzCtl_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_CeaEgzCtl_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_EmgMod) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_EmgMod_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_EmgMod_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_EmgMod_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_AuthDscon) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_AuthDscon_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_AuthDscon_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_AuthDscon_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_TestEna) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_TestEna_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_TestEna_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_TestEna_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_Test) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_Test_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_Test_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_Test_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_ChaWhTotRs) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_ChaWhTotRs_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_ChaWhTotRs_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_ChaWhTotRs_q, q);
    }

    if (parameter == IEDMODEL_DER3_DSTO1_DschWhTotRs) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_DschWhTotRs_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DSTO1_DschWhTotRs_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DSTO1_DschWhTotRs_q, q);
    }

    if (parameter == IEDMODEL_DER3_DBAT1_ClcStr) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DBAT1_ClcStr_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DBAT1_ClcStr_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DBAT1_ClcStr_q, q);
    }

    if (parameter == IEDMODEL_DER3_DBAT1_CmdBlk) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DBAT1_CmdBlk_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DBAT1_CmdBlk_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DBAT1_CmdBlk_q, q);
    }

    if (parameter == IEDMODEL_DER3_DBAT1_LocSta) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_DBAT1_LocSta_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_DBAT1_LocSta_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_DBAT1_LocSta_q, q);
    }

    return CONTROL_RESULT_OK;
}

static CheckHandlerResult
checkHandler(ControlAction action, void* parameter, MmsValue* ctlVal, bool test, bool interlockCheck)
{
    ClientConnection clientCon = ControlAction_getClientConnection(action);

    if (clientCon) {
        printf("Control from client %s\n", ClientConnection_getPeerAddress(clientCon));
    }
    else {
        printf("clientCon == NULL\n");
    }

    if (ControlAction_isSelect(action))
        printf("check handler called by select command!\n");
    else
        printf("check handler called by operate command!\n");

    if (interlockCheck)
        printf("  with interlock check bit set!\n");

    printf("  ctlNum: %i\n", ControlAction_getCtlNum(action));

    if (parameter == IEDMODEL_DER3_CSWI1_Pos)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_GGIO1_SPCSO1)
        return CONTROL_ACCEPTED;
    
    if (parameter == IEDMODEL_DER3_GGIO1_ISCSO1)
        return CONTROL_ACCEPTED;
    
    if (parameter == IEDMODEL_DER3_GGIO1_DPCSO1)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_ZBAT1_BatTest)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_CSWI1_PosA)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_CSWI1_PosB)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_CSWI1_PosC)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_CSWI1_OpCntRs)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_CSWI1_LocSta)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_XCBR1_LocSta)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_XCBR1_ChaMotEna)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_XCBR1_Pos)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_XCBR1_BlkOpn)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_XCBR1_BlkCls)
        return CONTROL_ACCEPTED;               
        
    if (parameter == IEDMODEL_DER3_XSWI1_LocSta)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_XSWI1_Pos)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_XSWI1_BlkOpn)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_XSWI1_BlkCls)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_XSWI1_ChaMotEna)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DBAT1_Mod)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_DBAT1_ClcStr)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_DBAT1_LocSta)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DBAT1_CmdBlk)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DBAT1_OpCntRs)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_LocSta)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_CmdBlk)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_OpCntRs)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_AuthConn)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_DEROpStCtl)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_CeaEgzCtl)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_WSpt)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_VArSpt)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_EmgMod)
        return CONTROL_ACCEPTED;    
        
    if (parameter == IEDMODEL_DER3_DSTO1_AuthDscon)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_DSTO1_TestEna)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_DSTO1_Test)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_DSTO1_ChaWhTotRs)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_DSTO1_DschWhTotRs)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_DSTO1_ClcStr)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_DSTO1_Mod)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_SBAT1_Mod)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_SBAT1_ClcStr)
        return CONTROL_ACCEPTED;
        
    if (parameter == IEDMODEL_DER3_SBAT1_OpCntRs)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_SBAT1_CelVolRs)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_DECP1_Mod)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_DECP1_ClcStr)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_DPCC1_Mod)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_DPCC1_ClcStr)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_DER3_DVER1_Mod)
        return CONTROL_ACCEPTED;
    
    if (parameter == IEDMODEL_DER3_DVER1_ClcStr)
        return CONTROL_ACCEPTED;    

    if (parameter == IEDMODEL_DER3_GGIO1_AnOut1)
        return CONTROL_ACCEPTED;    
        

    return CONTROL_OBJECT_UNDEFINED;
}

static void
connectionHandler (IedServer self, ClientConnection connection, bool connected, void* parameter)
{
    if (connected)
        printf("Connection success\n");
    else
        printf("Connection closed\n");
}

static void
goCbEventHandler(MmsGooseControlBlock goCb, int event, void* parameter)
{
    printf("Access to GoCB: %s\n", MmsGooseControlBlock_getName(goCb));
    printf("         GoEna: %i\n", MmsGooseControlBlock_getGoEna(goCb));
}

static void
rcbEventHandler(void* parameter, ReportControlBlock* rcb, ClientConnection connection, IedServer_RCBEventType event, const char* parameterName, MmsDataAccessError serviceError)
{
  

    if ((event == RCB_EVENT_SET_PARAMETER) || (event == RCB_EVENT_GET_PARAMETER)) {
        printf("  param:  %s\n", parameterName);
        printf("  result: %i\n", serviceError);
    }

    if (event == RCB_EVENT_GI) {
        printf("get GI request\n");
        const char* Name = ReportControlBlock_getName(rcb);
        printf("RCB event name %s\n", Name);
        char* rptId = ReportControlBlock_getRptID(rcb);
        printf("rptID:  %s\n", rptId);
        char* dataSet = ReportControlBlock_getDataSet(rcb);
        printf("DataSet: %s\n", dataSet);

        free(rptId);
        free(dataSet);
    }
}

void *udp_receiver(void *data) {
    int udp_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[MAX_BUFFER_SIZE];

    // 建立UDP socket
    if ((udp_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // 綁定IP和port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(RECEIVING_PORT);

    if (bind(udp_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding");
        close(udp_socket);
        exit(EXIT_FAILURE);
    }

    printf("UDP 接收器已經啟動，監聽 port %d\n", RECEIVING_PORT);


    while (running) {
        // 接收資料
        int bytes_received = recvfrom(udp_socket, buffer, sizeof(buffer) - 1, 0,
                                      (struct sockaddr*)&client_addr, &addr_len);
        if (bytes_received == -1) {
            perror("Error receiving data");
            close(udp_socket);
            exit(EXIT_FAILURE);
        }


        buffer[bytes_received] = '\0';
        //printf("收到來自 %s 的資料：%s\n", inet_ntoa(client_addr.sin_addr), buffer);

                // 解析 JS
        json_object *root = json_tokener_parse(buffer);
        if (root != NULL) {
            
        json_object *param1, *param2, *param3, *param4, *param5, *param6, *param7, *param8;
        json_object_object_get_ex(root, "value", &param7);
        json_object_object_get_ex(root, "type", &param8);
        if(json_object_object_get_ex(root, "Operation", &param6)){
            char param6Str[50];
            strcpy(param6Str, json_object_get_string(param6));
            if(strcmp(param6Str, "Update") != 0 && strcmp(param6Str, "Read") != 0){
                json_object_object_get_ex(root, "IED", &param1);
                json_object_object_get_ex(root, "LD", &param2);
                json_object_object_get_ex(root, "LN", &param3);
                json_object_object_get_ex(root, "DO", &param4);
                json_object_object_get_ex(root, "DA", &param5);
                const char* param1Str = json_object_get_string(param1);
                const char* param2Str = json_object_get_string(param2);
                const char* param3Str = json_object_get_string(param3);
                const char* param4Str = json_object_get_string(param4);
                const char* param5Str = json_object_get_string(param5);
                udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "no value", "the operation should be Update or Read");
                do_the_loop = 0;
            }
            if(strcmp(param6Str, "Update") == 0){
                do_the_loop = 1;
                if (json_object_object_get_ex(root, "IED", &param1) &&
                json_object_object_get_ex(root, "LD", &param2) &&
                json_object_object_get_ex(root, "LN", &param3) &&
                json_object_object_get_ex(root, "DO", &param4) &&
                json_object_object_get_ex(root, "DA", &param5)) {
                
                char param1Str[30]; 
                char param2Str[30]; 
                char param3Str[30]; 
                char param4Str[30]; 
                char param5Str[30]; 
                
                strcpy(param1Str, json_object_get_string(param1));
                strcpy(param2Str, json_object_get_string(param2));
                strcpy(param3Str, json_object_get_string(param3));
                strcpy(param4Str, json_object_get_string(param4));
                strcpy(param5Str, json_object_get_string(param5));
                char variableName[200];
                const char* param7Str = json_object_get_string(param7);
                const char* param8Str = json_object_get_string(param8);
                
                struct timeval currentTime;
                gettimeofday(&currentTime, NULL);

                
                uint64_t milliseconds = (uint64_t)(currentTime.tv_sec) * 1000ULL + (uint64_t)(currentTime.tv_usec) / 1000ULL;

                printf("Current time in milliseconds (uint64_t): %"PRIu64"\n", milliseconds);
                
                if(strcmp(param8Str, "float") == 0){
                   float_found = 0;
                   sscanf(param7Str, "%f", &float_control_value);
                   printf("float activate");
                   printf("%f",float_control_value);
                   
                   
                   if(sscanf(param7Str, "%f", &float_control_value) != 1){
                       udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "no value return", "incorrect data type");
                       float_found = 1;
                       do_the_loop = 0;
                }
                }
                else if(strcmp(param8Str, "boolean") == 0){
                    boolean_found = 0;
                    if(strcmp(param7Str, "true") == 0){
                        boolean_control_value = 1;
                }
                    else if(strcmp(param7Str, "false") == 0){
                        boolean_control_value = 0;
                }
                    else if(strcmp(param7Str, "true") != 0 && strcmp(param7Str, "false") != 0){
                    udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "no value return", "incorrect data type");
                    boolean_found = 1;
                    do_the_loop = 0;
                }
             }   
                else if(strcmp(param8Str, "int") == 0){
                    int_found = 0;
                    sscanf(param7Str, "%d", &int32_control_value);
                    printf("int activate");
                    printf("%d", int32_control_value);
                    //printf("%d", int32_control_value);
                    if(sscanf(param7Str, "%d", &int32_control_value) != 1){
                       udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "no value return", "incorrect data type");
                       int_found = 1;
                       do_the_loop = 0;
                }
            }
                else if(strcmp(param8Str, "Dbpos") == 0){
                    printf("Dbpos activate");
                }
                else {
                printf("invalid value format");
                udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "no value return", "incorrect value format, the format should be string, boolean, float, int or Dbpos");
                do_the_loop = 0;
                }
                
                sprintf(variableName, "%s_%s_%s_%s_%s", param1Str, param2Str, param3Str, param4Str, param5Str);
                //printf("%s", variableName);
                int found = 0;
                if(do_the_loop == 1){
                for (int i = 0; i < 500; i++) {
                    uint64_t timestamp = Hal_getTimeInMs();
                    Timestamp TimeStamp1;
                    Timestamp_clearFlags(&TimeStamp1);
                    Timestamp_setTimeInMilliseconds(&TimeStamp1, timestamp);
                    Timestamp_setLeapSecondKnown(&TimeStamp1, true);
                    
                    if(strcmp(variableName, EFG[i].str) == 0 && strcmp(param8Str, "float") == 0) {
                        if(float_found == 0){
                            IedServer_lockDataModel(iedServer);
                            IedServer_updateFloatAttributeValue(iedServer, EFG[i].var, float_control_value);
                            if(EFG[i].timeupload == 1){
                            IedServer_updateUTCTimeAttributeValue(iedServer, EFG[i].time, milliseconds);
                            }
                            
                            IedServer_unlockDataModel(iedServer);
                            float Value2 = IedServer_getFloatAttributeValue(iedServer, EFG[i].var1);
                        
                            char strValue2[21];
                        
                            if(sprintf(strValue2, "%f", Value2)){
                                udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, strValue2, "OK");
                        }
                       
                        found = 1;
                        break;
                    }
            }
            
                   else if(strcmp(param8Str, "boolean") == 0) {
                       if(strcmp(variableName, EFG[i].str) == 0){
                        /*if(strcmp(param5Str, "Pos"){
                        sprintf(variableName, "%s_%s_%s_%s_%s", param1Str, param2Str, param3Str, param4Str, param5Str, "Oper");
                        }*/
                        if(boolean_found == 0){
                        IedServer_lockDataModel(iedServer);
                        IedServer_updateBooleanAttributeValue(iedServer, EFG[i].var, boolean_control_value);
                        if(EFG[i].timeupload == 1){
                        IedServer_updateUTCTimeAttributeValue(iedServer, EFG[i].time, milliseconds);
                        }
                        IedServer_unlockDataModel(iedServer);
                        bool Value = IedServer_getBooleanAttributeValue(iedServer, EFG[i].var1);
                        printf("%d yes", Value);
                        //printf("%llu\n",IedServer_getUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_t));
                        if(Value == 1){
                            udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "true", "OK");
                        }
                        else if(Value == 0){
                            udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "false", "OK");
                        }
                        found = 1;
                        break;
                    }
                }
 
                  }      
                    else if(strcmp(param8Str, "int") == 0) {
                        if(strcmp(variableName, EFG[i].str) == 0){
                        printf("%s", variableName);
                        if(int_found == 0){
                        IedServer_lockDataModel(iedServer);
                        IedServer_updateInt32AttributeValue(iedServer, EFG[i].var, int32_control_value);
                        printf("tes");
                        if(EFG[i].timeupload == 1){
                        IedServer_updateUTCTimeAttributeValue(iedServer, EFG[i].time, milliseconds);
                    }
                        IedServer_unlockDataModel(iedServer);
                        int Value3 = IedServer_getInt32AttributeValue(iedServer, EFG[i].var1);
                        printf("%d", Value3);
                        char strValue3[21];
                        sprintf(strValue3, "%d", Value3);
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, strValue3, "OK");
                        
                        found = 1;
                        break;
                    }
                }       

                    }
                    else if(strcmp(param8Str, "Dbpos") == 0){
                        if(strcmp(variableName, EFG[i].str) == 0){
                        printf("%s", variableName);
                        if(strcmp(param7Str, "intermediate_state") == 0){
                             Dbpos_value = 0;
                        }
                        if(strcmp(param7Str, "off") == 0){
                             Dbpos_value = 1;
                        }
                        if(strcmp(param7Str, "on") == 0){
                             Dbpos_value = 2;
                        }
                        if(strcmp(param7Str, "bad") == 0){
                             Dbpos_value = 3;
                        }
                        IedServer_lockDataModel(iedServer);
                        IedServer_updateDbposValue(iedServer, EFG[i].var, Dbpos_value);
                        if(EFG[i].timeupload == 1){
                        IedServer_updateUTCTimeAttributeValue(iedServer, EFG[i].time, milliseconds);
                    }
                        IedServer_unlockDataModel(iedServer);
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, param7Str, "OK");
                        found = 1;
                        break;
                    
                }
                    }
                    
                    else{
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, "go", "no value return", "incorrect data object or incorrect LN");
                        found = 1;
                        break;
            }
        } 
    }      
            }
            } 
         
       
            if(strcmp(param6Str, "Read") == 0){
            if (json_object_object_get_ex(root, "IED", &param1) &&
                json_object_object_get_ex(root, "LD", &param2) &&
                json_object_object_get_ex(root, "LN", &param3) &&
                json_object_object_get_ex(root, "DO", &param4) &&
                json_object_object_get_ex(root, "DA", &param5)) {
                
                char param1Str[30]; 
                char param2Str[30]; 
                char param3Str[30]; 
                char param4Str[30]; 
                char param5Str[30]; 
                
                strcpy(param1Str, json_object_get_string(param1));
                strcpy(param2Str, json_object_get_string(param2));
                strcpy(param3Str, json_object_get_string(param3));
                strcpy(param4Str, json_object_get_string(param4));
                strcpy(param5Str, json_object_get_string(param5));

                // 构建变量名
                char variableName[200];
                const char* param7Str = json_object_get_string(param7);
                const char* param8Str = json_object_get_string(param8);
                //printf(param1Str);
                //printf(param2Str);
                //printf(param3Str);
                //printf(param4Str);
                //printf(param5Str);
                sprintf(variableName, "%s_%s_%s_%s_%s", param1Str, param2Str, param3Str, param4Str, param5Str);
                //snprintf(variableName, sizeof(variableName), "%s_%s_%s_%s_%s", json_object_get_string(param1), json_object_get_string(param2), json_object_get_string(param3), json_object_get_string(param4), json_object_get_string(param5));
      
                int found = 0;
                struct timeval currentTime;
                gettimeofday(&currentTime, NULL);

                
                uint64_t milliseconds = (uint64_t)(currentTime.tv_sec) * 1000ULL + (uint64_t)(currentTime.tv_usec) / 1000ULL;

                printf("Current time in milliseconds (uint64_t): %"PRIu64"\n", milliseconds);
                
                for (int i = 0; i < 500; i++) {
                    if (strcmp(variableName, ABC[i].str) == 0 && ABC[i].type == 0) {
                        //IedServer_lockDataModel(iedServer);
                        //IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_stVal, 1);
                        //IedServer_unlockDataModel(iedServer);
                        bool Value1 =  IedServer_getBooleanAttributeValue(iedServer, ABC[i].var);
                        if(Value1 == 1){
                        printf("true\n");
                        //strcpy(message , "true");
                        //printf("%s",message);
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "true", "OK");
                    }
                        if(Value1 == 0){                            
                        printf("false\n");
                        //strcpy(message , "false");
                        //printf("%s",message);
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "false", "OK");
                    }
                   
                        found = 1;
                        break; 
                    } 
                    if (strcmp(variableName, ABC[i].str) == 0 && ABC[i].type == 1){
                        //printf("%llu\n",IedServer_getUTCTimeAttributeValue(iedServer, IEDMODEL_ProtCtrl_GGIO1_SPCSO_t));
                        uint64_t TimeStamp = IedServer_getUTCTimeAttributeValue(iedServer, ABC[i].var);
                        printf("%"PRIu64"\n",TimeStamp);
                        char str[21];
                        snprintf(str, sizeof(str), "%"PRIu64"", TimeStamp);
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, str, "OK");
                        found = 1;
                        break; 
                    }
                    if (strcmp(variableName, ABC[i].str) == 0 && ABC[i].type == 2){
                        //printf("%llu\n",IedServer_getUTCTimeAttributeValue(iedServer, IEDMODEL_ProtCtrl_GGIO1_SPCSO_t));
                        int Value2 = IedServer_getInt32AttributeValue(iedServer, ABC[i].var);
                        printf("%d\n",Value2);
                        char str2[21];
                        snprintf(str2, sizeof(str2), "%d", Value2);
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, str2, "OK");
                        found = 1;
                        break; 
                    }
                    if (strcmp(variableName, ABC[i].str) == 0 && ABC[i].type == 3){
                        //printf("%llu\n",IedServer_getUTCTimeAttributeValue(iedServer, IEDMODEL_ProtCtrl_GGIO1_SPCSO_t));
                        float Value3 = IedServer_getFloatAttributeValue(iedServer, ABC[i].var);
                        printf("%f\n",Value3);
                        char str3[21];
                        snprintf(str3, sizeof(str3), "%f", Value3);
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, str3, "OK");
                        found = 1;
                        break; 
                    }
                    if (strcmp(variableName, ABC[i].str) == 0 && ABC[i].type == 4){
                        //printf("%llu\n",IedServer_getUTCTimeAttributeValue(iedServer, IEDMODEL_ProtCtrl_GGIO1_SPCSO_t));
                        uint32_t Value4 = IedServer_getBitStringAttributeValue(iedServer, ABC[i].var);
                        printf("%u",Value4);
                        char str4[21];
                        snprintf(str4, sizeof(str4), "%s", param7Str);
                        printf("%s",str4);
                        udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, str4, "OK");
                        found = 1;
                        break; 
                    }
                    
                }

 
                if (!found) {
                    printf("No matching parameter found\n");
                    
                    udp_sender(inet_ntoa(client_addr.sin_addr), param1Str, param2Str, param3Str, param4Str, param5Str, param6Str, "no value return", "incorrect data object or incorrect LN");
                    found = 1;
                    break;                
            
                    
                }

                // 调用相关 API 函数
                //printf("API Result: %d\n", IedServer_getBooleanAttributeValue(iedServer, variableName));
           }
           }
        }
           else {
                printf("Invalid JSON Data Format\n");
            }

            json_object_put(root);
         } 
           else {
            printf("JSON Parsing Error\n");
        }
        
    }
    close(udp_socket);
    return NULL;
}

// 创建UDP发送器
void udp_sender(const char *ip, const char *message1, const char *message2, const char *message3, const char *message4, const char *message5, const char *message6, const char *message7, const char *message8) {

    int sock;
    struct sockaddr_in server_addr;

    struct json_object *input_json = json_object_new_object();
    json_object_object_add(input_json, "IED", json_object_new_string(message1));
    json_object_object_add(input_json, "LD", json_object_new_string(message2));
    json_object_object_add(input_json, "LN", json_object_new_string(message3));
    json_object_object_add(input_json, "DO", json_object_new_string(message4));
    json_object_object_add(input_json, "DA", json_object_new_string(message5));
    json_object_object_add(input_json, "Operation", json_object_new_string(message6));
    json_object_object_add(input_json, "value", json_object_new_string(message7));
    json_object_object_add(input_json, "status", json_object_new_string(message8));
    const char *message = json_object_to_json_string_ext(input_json, JSON_C_TO_STRING_PLAIN);
    
    
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SENDING_PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    sendto(sock, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    //printf("%s",message);
    close(sock);

}


int
main(int argc, char** argv)
{
    
    printf("Using libIEC61850 version %s\n", LibIEC61850_getVersionString());
    
    pthread_t receiver_thread , sender_thread ;
        
    signal(SIGINT, sigint_handler);
    
    // 創建一個線程來執行UDP接收器
    if (pthread_create(&receiver_thread, NULL, udp_receiver, NULL) != 0) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }
  

    //if (pthread-create(
    /* Create new server configuration object */
    IedServerConfig config = IedServerConfig_create();

    /* Set buffer size for buffered report control blocks to 200000 bytes */
    IedServerConfig_setReportBufferSize(config, 400000);

    /* Set stack compliance to a specific edition of the standard (WARNING: data model has also to be checked for compliance) */
    IedServerConfig_setEdition(config, IEC_61850_EDITION_2);

    /* Set the base path for the MMS file services */
    IedServerConfig_setFileServiceBasePath(config, "./vmd-filestore/");

    /* disable MMS file service */
    IedServerConfig_enableFileService(config, false);

    /* enable dynamic data set service */
    IedServerConfig_enableDynamicDataSetService(config, true);

    /* disable log service */
    IedServerConfig_enableLogService(config, false);

    /* set maximum number of clients */
    IedServerConfig_setMaxMmsConnections(config, 5);
    
    /* Create a new IEC 61850 server instance */
    iedServer = IedServer_createWithConfig(&iedModel, NULL, config);

    /* configuration object is no longer required */
    IedServerConfig_destroy(config);
    
    if (argc > 1) {
        char* ethernetIfcID = argv[1];

        printf("Using GOOSE interface: %s\n", ethernetIfcID);

        /* set GOOSE interface for all GOOSE publishers (GCBs) */
        IedServer_setGooseInterfaceId(iedServer, ethernetIfcID);
    }

    if (argc > 2) {
        char* ethernetIfcID = argv[2];

        printf("Using GOOSE interface for DER3/LLN0.gcbAnalogValues: %s\n", ethernetIfcID);

        /* set GOOSE interface for a particular GOOSE publisher (GCB) */
        IedServer_setGooseInterfaceIdEx(iedServer, IEDMODEL_DER3_LLN0, "gcbAnalogValues", ethernetIfcID);
    }

    IedServer_setGoCBHandler(iedServer, goCbEventHandler, NULL);
    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_Pos_stVal, true);

    /* set the identity values for MMS identify service */
    IedServer_setServerIdentity(iedServer, "MZ", "basic io", "1.4.2");

    /* Install handler for operate command */
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_GGIO1_SPCSO1);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_GGIO1_DPCSO1,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_GGIO1_DPCSO1);
            
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_CSWI1_LocSta,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_CSWI1_LocSta);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_CSWI1_Pos,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_CSWI1_Pos);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_CSWI1_PosA,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_CSWI1_PosA);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_CSWI1_PosB,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_CSWI1_PosB);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_CSWI1_PosC,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_CSWI1_PosC);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XCBR1_LocSta,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XCBR1_LocSta);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XCBR1_Pos,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XCBR1_Pos);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XCBR1_BlkOpn,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XCBR1_BlkOpn);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XCBR1_BlkCls,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XCBR1_BlkCls);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XCBR1_ChaMotEna,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XCBR1_ChaMotEna);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XSWI1_LocSta,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XSWI1_LocSta);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XSWI1_Pos,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XSWI1_Pos);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XSWI1_BlkOpn,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XSWI1_BlkOpn);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XSWI1_BlkCls,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XSWI1_BlkCls);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_XSWI1_ChaMotEna,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_XSWI1_ChaMotEna);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DVER1_ClcStr,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DVER1_ClcStr);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DECP1_ClcStr,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DECP1_ClcStr);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DPCC1_ClcStr,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DPCC1_ClcStr);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_SBAT1_ClcStr,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_SBAT1_ClcStr); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_SBAT1_CelVolRs,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_SBAT1_CelVolRs); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_LocSta,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_LocSta); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_CmdBlk,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_CmdBlk); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_AuthConn,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_AuthConn); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_CeaEgzCtl,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_CeaEgzCtl); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_EmgMod,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_EmgMod); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_AuthDscon,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_AuthDscon);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_TestEna,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_TestEna); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_Test,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_Test); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_ChaWhTotRs,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_ChaWhTotRs);
            
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_ClcStr,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_ClcStr); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DSTO1_DschWhTotRs,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DSTO1_DschWhTotRs);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DBAT1_ClcStr,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DBAT1_ClcStr); 

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DBAT1_CmdBlk,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DBAT1_CmdBlk);

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_DBAT1_LocSta,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_DER3_DBAT1_LocSta);   

    IedServer_setConnectionIndicationHandler(iedServer, (IedConnectionIndicationHandler) connectionHandler, NULL);

    IedServer_setRCBEventHandler(iedServer, rcbEventHandler, NULL);

    /* Allow write access to CF parameters (here "db" and "rangeC") */
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_CF, ACCESS_POLICY_ALLOW);

    /* By default access to variables with FC=DC and FC=CF is not allowed.
     * This allow to write to simpleIOGenericIO/GGIO1.NamPlt.vendor variable used
     * by iec61850_client_example1.
     */
    /*IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_DC, ACCESS_POLICY_ALLOW);*/

    /* MMS server will be instructed to start listening for client connections. */
    IedServer_start(iedServer, 102);
    

    


    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed (maybe need root permissions or another server is already using the port)! Exit.\n");
        IedServer_destroy(iedServer);
        exit(-1);
    }
    
     /* Start GOOSE publishing (也會初始化伺服器的報告功)更新*/
    IedServer_enableGoosePublishing(iedServer);
    
    float t = 0.f;

    //更新
    float anIn1 = 0.f;
    int eventCount = 10;

    float an1InstMag = 5 * sinf(t);

    float an1Mag = an1InstMag;

    running = 1;
    static char last_sent = '\0';
    ctl=2;
    while (running) {

        uint64_t timestamp = Hal_getTimeInMs();     



        Timestamp iecTimestamp;

        Timestamp_clearFlags(&iecTimestamp);
        Timestamp_setTimeInMilliseconds(&iecTimestamp, timestamp);
        Timestamp_setLeapSecondKnown(&iecTimestamp, true);

        Thread_sleep(500);
    }

    
    pthread_cancel(receiver_thread);
   
    // 等待線程執行完畢並回收資源
    pthread_join(receiver_thread, NULL);

    /* stop MMS server - close TCP server socket and all client sockets */
    IedServer_stop(iedServer);

    /* Cleanup - free all resources */
    IedServer_destroy(iedServer);

    return 0;
} /* main() */
