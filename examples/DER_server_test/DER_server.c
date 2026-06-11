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
#include "static_model.h"

#include "model.c"
#include <sys/time.h>


extern IedModel iedModel;
static IedServer iedServer = NULL;



int running = 1;
static uint32_t dpc_state = 0;
int operation_delay;
bool state;

typedef enum {
    BEH_ON = 1,
    BEH_ON_BLOCKED = 2,
    BEH_TEST = 3,
    BEH_TEST_BLOCKED = 4,
    BEH_OFF = 5
} BehMode;


typedef enum {
    MOD_ON = 1,     
    MOD_ON_BLOCKED = 2, 
    MOD_TEST = 3,
    MOD_TEST_BLOCKED = 4,
    MOD_OFF = 5,
} Mode;


BehMode changeBeh(Mode LN_Mod, Mode LLN0_Mod)
{
    switch(LN_Mod)
    {
        case MOD_ON:
            switch(LLN0_Mod)
            {
                case MOD_ON:
                    return BEH_ON;
                case MOD_ON_BLOCKED:
                    return BEH_ON_BLOCKED;
                case MOD_TEST:
                    return BEH_TEST;   
                case MOD_TEST_BLOCKED:
                    return BEH_TEST_BLOCKED;
                case MOD_OFF:
                    return BEH_OFF;     
            }
        
        case MOD_ON_BLOCKED:
            switch(LLN0_Mod)
            {
                case MOD_ON:
                    return BEH_ON_BLOCKED;
                case MOD_ON_BLOCKED:
                    return BEH_ON_BLOCKED;
                case MOD_TEST:
                    return BEH_TEST_BLOCKED;   
                case MOD_TEST_BLOCKED:
                    return BEH_TEST_BLOCKED;
                case MOD_OFF:
                    return BEH_OFF;     
            }           

        case MOD_TEST:
            switch(LLN0_Mod)
            {
                case MOD_ON:
                    return BEH_TEST;
                case MOD_ON_BLOCKED:
                    return BEH_TEST_BLOCKED;
                case MOD_TEST:
                    return BEH_TEST;   
                case MOD_TEST_BLOCKED:
                    return BEH_TEST_BLOCKED;
                case MOD_OFF:
                    return BEH_OFF;     
            }

        case MOD_TEST_BLOCKED:
            if(LLN0_Mod != MOD_OFF){
                return BEH_TEST_BLOCKED;
            }
            else{
                return BEH_OFF;
            }                

        case MOD_OFF:
            return BEH_OFF;
    
        default:
            return BEH_OFF;
    }
}


Quality changeQuality(BehMode newBeh)
{
    switch (newBeh)
    {
        case BEH_ON:
            return QUALITY_VALIDITY_GOOD;
        
        case BEH_ON_BLOCKED:
            return QUALITY_VALIDITY_GOOD | QUALITY_OPERATOR_BLOCKED;
        
        case BEH_TEST:
            return QUALITY_VALIDITY_GOOD | QUALITY_TEST;
        
        case BEH_TEST_BLOCKED:
            return QUALITY_VALIDITY_GOOD | QUALITY_TEST | QUALITY_OPERATOR_BLOCKED;
        
        case BEH_OFF:
            return QUALITY_VALIDITY_INVALID;
                
        default:
            return QUALITY_VALIDITY_INVALID;
    }
}


CheckHandlerResult ackForClient(ControlAction action,BehMode newBeh, bool test)
{
    switch (newBeh)
    {
        case BEH_ON:
            if(test){
                printf("a- neg.ack\n");
                ControlAction_setAddCause(action, ADD_CAUSE_BLOCKED_BY_MODE);
                return CONTROL_OBJECT_ACCESS_DENIED;
            }
            printf("a+ pos.ack\n");
            break;
  
        case BEH_ON_BLOCKED:
            printf("a- neg.ack\n");
            ControlAction_setAddCause(action, ADD_CAUSE_BLOCKED_BY_MODE);
            return CONTROL_OBJECT_ACCESS_DENIED;
    
        case BEH_TEST:
            if(!test) {
                printf("a- neg.ack\n");
                ControlAction_setAddCause(action, ADD_CAUSE_BLOCKED_BY_MODE);
                return CONTROL_OBJECT_ACCESS_DENIED;
            }
            printf("a+ pos.ack\n");    
            break;
    
        case BEH_TEST_BLOCKED:
            if(!test){
                printf("a- neg.ack\n");
                ControlAction_setAddCause(action, ADD_CAUSE_BLOCKED_BY_MODE);
                return CONTROL_OBJECT_ACCESS_DENIED;
            }
            printf("a+ pos.ack/n");
            break;
    
        case BEH_OFF:
            printf("a- neg.ack\n");
            ControlAction_setAddCause(action, ADD_CAUSE_BLOCKED_BY_MODE);
            return CONTROL_OBJECT_ACCESS_DENIED;

        default:
            printf("a- neg.ack\n");
            ControlAction_setAddCause(action, ADD_CAUSE_BLOCKED_BY_MODE);
            return CONTROL_OBJECT_ACCESS_DENIED;
    }
    return CONTROL_ACCEPTED;   
}





void
sigint_handler(int signalId)
{
    running = 0;
}
void *delay_function(void* arg){
    uint64_t timeStamp = Hal_getTimeInMs();
    Quality q = QUALITY_VALIDITY_GOOD;
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
    uint64_t timestamp = Hal_getTimeInMs();
    Quality q = QUALITY_VALIDITY_GOOD;

    printf("control handler called\n");
    printf("  ctlNum: %i\n", ControlAction_getCtlNum(action));

    ClientConnection clientCon = ControlAction_getClientConnection(action);

    if (clientCon) {
        printf("Control from client %s\n", ClientConnection_getPeerAddress(clientCon));
    }
    else {
        printf("clientCon == NULL!\n");
    }

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

    if (parameter == IEDMODEL_DER3_GGIO1_Mod) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Mod_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Mod_stVal, value);
        IedServer_updateQuality(iedServer, IEDMODEL_DER3_GGIO1_Mod_q, q);
    }

    return CONTROL_RESULT_OK;
}


static ControlHandlerResult
controlHandlerForLLN0(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    uint64_t timestamp = Hal_getTimeInMs();

    printf("control handler called\n");
    printf("  ctlNum: %i\n", ControlAction_getCtlNum(action));

    ClientConnection clientCon = ControlAction_getClientConnection(action);

    if (clientCon) {
        printf("Control from client %s\n", ClientConnection_getPeerAddress(clientCon));
    }
    else {
        printf("clientCon == NULL!\n");
    }

    if (parameter == IEDMODEL_DER3_LLN0_Mod) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_LLN0_Mod_t, timestamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_LLN0_Mod_stVal, value);

        Mode LN_Mod = (Mode)IedServer_getUInt32AttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Mod_stVal);
        Mode LLN0_Mod = (Mode)IedServer_getUInt32AttributeValue(iedServer, IEDMODEL_DER3_LLN0_Mod_stVal);
        BehMode NewBeh = changeBeh(LN_Mod, LLN0_Mod);

        printf("%u\n",NewBeh);

        IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Beh_stVal, (int32_t)NewBeh);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Beh_t, timestamp);

        printf("Changed Mod successful!\n");
    }
    
    BehMode newBeh = (BehMode)IedServer_getUInt32AttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Beh_stVal);
    
    Quality q = changeQuality(newBeh);
    
    IedServer_updateQuality(iedServer, IEDMODEL_DER3_GGIO1_Beh_q, q);
    IedServer_updateQuality(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_q, q);  
    
    printf("Changed q successful!\n");

    return CONTROL_RESULT_OK;

}




static ControlHandlerResult
controlHandlerForMod(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    uint64_t timestamp = Hal_getTimeInMs();

    printf("control handler called\n");
    printf("  ctlNum: %i\n", ControlAction_getCtlNum(action));

    ClientConnection clientCon = ControlAction_getClientConnection(action);

    if (clientCon) {
        printf("Control from client %s\n", ClientConnection_getPeerAddress(clientCon));
    }
    else {
        printf("clientCon == NULL!\n");
    }

    if (parameter == IEDMODEL_DER3_GGIO1_Mod) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Mod_t, timestamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Mod_stVal, value);

        Mode LLN0_Mod = (Mode)IedServer_getUInt32AttributeValue(iedServer, IEDMODEL_DER3_LLN0_Mod_stVal);
        Mode LN_Mod = (Mode)IedServer_getUInt32AttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Mod_stVal);
        BehMode NewBeh = changeBeh(LN_Mod, LLN0_Mod);
        
        printf("%u\n",NewBeh);

        IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Beh_stVal, (int32_t)NewBeh);
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Beh_t, timestamp);
        printf("Changed Mod successful!\n");
    }

    BehMode newBeh = (BehMode)IedServer_getUInt32AttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Beh_stVal);
    
    Quality q = changeQuality(newBeh);
    
    IedServer_updateQuality(iedServer, IEDMODEL_DER3_GGIO1_Beh_q, q);
    IedServer_updateQuality(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_q, q);  
    
    printf("Changed q successful!\n");

    return CONTROL_RESULT_OK;

}


static ControlHandlerResult
controlHandlerForSPCSO1(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    uint64_t timestamp = Hal_getTimeInMs();

    printf("control handler called\n");
    printf("  ctlNum: %i\n", ControlAction_getCtlNum(action));

    ClientConnection clientCon = ControlAction_getClientConnection(action);

    if (clientCon) {
        printf("Control from client %s\n", ClientConnection_getPeerAddress(clientCon));
    }
    else {
        printf("clientCon == NULL!\n");
    }

    
    BehMode newBeh = (BehMode)IedServer_getUInt32AttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Beh_stVal);

    switch (newBeh)
    {
    case BEH_ON:
        if(test){
            printf("a- neg.ack\n");
            return CONTROL_RESULT_FAILED;
        }
        printf("a+ pos.ack\n");
        break;
  
    case BEH_ON_BLOCKED:
        printf("a- neg.ack\n");
        return CONTROL_RESULT_FAILED;
    
    case BEH_TEST:
        if(!test) {
            printf("a- neg.ack\n");
            return CONTROL_RESULT_FAILED;
        }
        printf("a+ pos.ack\n");    
        break;
    
    case BEH_TEST_BLOCKED:
        if(!test){
            printf("a- neg.ack\n");
            return CONTROL_RESULT_FAILED;
        }
        printf("a+ pos.ack/n");
        break;
    
    case BEH_OFF:
        printf("a- neg.ack\n");
        return CONTROL_RESULT_FAILED;

    default:
        printf("a- neg.ack\n");
        return CONTROL_RESULT_FAILED;
    }

    if (parameter == IEDMODEL_DER3_GGIO1_SPCSO1) { 
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_t, timestamp);
    IedServer_updateAttributeValue(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1_stVal, value);  
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

    if (parameter == IEDMODEL_DER3_GGIO1_SPCSO1){
        BehMode newBeh = (BehMode)IedServer_getUInt32AttributeValue(iedServer, IEDMODEL_DER3_GGIO1_Beh_stVal);
        return ackForClient(newBeh, test);        
    }     

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


int
main(int argc, char** argv)
{
    
    printf("Using libIEC61850 version %s\n", LibIEC61850_getVersionString());
    
    
        
    signal(SIGINT, sigint_handler);
    
    
  

    //if (pthread-create(
    /* Create new server configuration object */
    IedServerConfig config = IedServerConfig_create();

    /* Set buffer size for buffered report control blocks to 200000 bytes */
    IedServerConfig_setReportBufferSize(config, 400000);

    /* Set stack compliance to a specific edition of the standard (WARNING: data model has also to be checked for compliance) */
    IedServerConfig_setEdition(config, IEC_61850_EDITION_2_1);

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

    IedServerConfig_enableOwnerForRCB(config, true);

    IedServerConfig_enableResvTmsForBRCB(config, true);

    
    /* Create a new IEC 61850 server instance */
    iedServer = IedServer_createWithConfig(&iedModel, NULL, config);

    /* configuration object is no longer required */
    IedServerConfig_destroy(config);
    
    
    
    
    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_DER3_XCBR1_Pos_stVal, true);

    /* set the identity values for MMS identify service */
    IedServer_setServerIdentity(iedServer, "MZ", "basic io", "1.4.2");

    /* Install handler for operate command */
    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_LLN0_Mod,
            (ControlHandler) controlHandlerForLLN0,
            IEDMODEL_DER3_LLN0_Mod);


    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1,
            (ControlHandler) controlHandlerForSPCSO1,
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

    IedServer_setControlHandler(iedServer, IEDMODEL_DER3_GGIO1_Mod,
            (ControlHandler) controlHandlerForMod,
            IEDMODEL_DER3_GGIO1_Mod);

    IedServer_setPerformCheckHandler(iedServer, IEDMODEL_DER3_GGIO1_SPCSO1, checkHandler,
            IEDMODEL_DER3_GGIO1_SPCSO1);

    IedServer_setConnectionIndicationHandler(iedServer, (IedConnectionIndicationHandler) connectionHandler, NULL);

    IedServer_setRCBEventHandler(iedServer, (IedServer_RCBEventHandler) rcbEventHandler, NULL);

    /* Allow write access to CF parameters (here "db" and "rangeC") */
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_CF, ACCESS_POLICY_ALLOW);
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_ST, ACCESS_POLICY_ALLOW);

    

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
    
    uint64_t nextHzUpdate = Hal_getTimeInMs() + 30000;
    float_t HzTest = 50.0f;
    
  
    while (running) {

        uint64_t timestamp = Hal_getTimeInMs();     

        if(timestamp >= nextHzUpdate)
        {
            IedServer_lockDataModel(iedServer);
            IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_DER3_MMXU1_Hz_mag_f, HzTest);
            IedServer_unlockDataModel(iedServer); 
            
            nextHzUpdate += 30000;
            HzTest += 10.0f;
        }

        Timestamp iecTimestamp;

        Timestamp_clearFlags(&iecTimestamp);
        Timestamp_setTimeInMilliseconds(&iecTimestamp, timestamp);
        Timestamp_setLeapSecondKnown(&iecTimestamp, true);

        Thread_sleep(500);
    }

    
   

    /* stop MMS server - close TCP server socket and all client sockets */
    IedServer_stop(iedServer);

    /* Cleanup - free all resources */
    IedServer_destroy(iedServer);

    return 0;
} /* main() */
