/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: OmbOmb_DiagStructDef.h 3661 2015-09-30 07:19:11Z iborisov $:
Description:
Omb Task
Includes following functions...
**************************************************************************************/

#ifndef __STRUCT_OMB_OMB_INFO_STATUS__
#define __STRUCT_OMB_OMB_INFO_STATUS__

#include "TLR_Types.h"

typedef __PACKED_PRE struct __PACKED_POST OMB_OMB_INFO_STATUStag {
  /*  Task State */
  TLR_UINT32 ulTaskState;
  /*  Error Count */
  TLR_UINT32 ulErrorCount;
  /*  Last Error */
  TLR_UINT32 ulLastError;
  /*  Socket Status */
  TLR_UINT32 ulOpenSockets;
  /*  Cyclic Event Count */
  TLR_UINT32 ulCyclicCount;
  /*  Idle Count */
  TLR_UINT32 ulIdleCount;
} OMB_OMB_INFO_STATUS;
#endif
#ifndef __STRUCT_OMB_OMB_CLIENT_STATUS__
#define __STRUCT_OMB_OMB_CLIENT_STATUS__
typedef __PACKED_PRE struct __PACKED_POST OMB_OMB_CLIENT_STATUStag {
  /*  Messages Send to User */
  TLR_UINT32 ulMsgSend;
  /*  Messages Recv from User */
  TLR_UINT32 ulMsgRecv;
  /*  FC1  Count */
  TLR_UINT32 ulFc1Cnt;
  /*  FC2  Count */
  TLR_UINT32 ulFc2Cnt;
  /*  FC3  Count */
  TLR_UINT32 ulFc3Cnt;
  /*  FC4  Count */
  TLR_UINT32 ulFc4Cnt;
  /*  FC5  Count */
  TLR_UINT32 ulFc5Cnt;
  /*  FC6  Count */
  TLR_UINT32 ulFc6Cnt;
  /*  FC7  Count */
  TLR_UINT32 ulFc7Cnt;
  /*  FC15 Count */
  TLR_UINT32 ulFc15Cnt;
  /*  FC16 Count */
  TLR_UINT32 ulFc16Cnt;
  /*  FC23 Count */
  TLR_UINT32 ulFc23Cnt;
} OMB_OMB_CLIENT_STATUS;
#endif
#ifndef __STRUCT_OMB_OMB_SERVER_STATUS__
#define __STRUCT_OMB_OMB_SERVER_STATUS__
typedef __PACKED_PRE struct __PACKED_POST OMB_OMB_SERVER_STATUStag {
  /*  Messages Send to TCP-Task */
  TLR_UINT32 ulMsgSend;
  /*  Messages Recv from TCP-Task */
  TLR_UINT32 ulMsgRecv;
  /*  FC1  Count */
  TLR_UINT32 ulFc1Cnt;
  /*  FC2  Count */
  TLR_UINT32 ulFc2Cnt;
  /*  FC3  Count */
  TLR_UINT32 ulFc3Cnt;
  /*  FC4  Count */
  TLR_UINT32 ulFc4Cnt;
  /*  FC5  Count */
  TLR_UINT32 ulFc5Cnt;
  /*  FC6  Count */
  TLR_UINT32 ulFc6Cnt;
  /*  FC7  Count */
  TLR_UINT32 ulFc7Cnt;
  /*  FC15 Count */
  TLR_UINT32 ulFc15Cnt;
  /*  FC16 Count */
  TLR_UINT32 ulFc16Cnt;
  /*  FC23 Count */
  TLR_UINT32 ulFc23Cnt;
} OMB_OMB_SERVER_STATUS;
#endif
#ifndef __STRUCT_OMB_OMB_IO_STATUS__
#define __STRUCT_OMB_OMB_IO_STATUS__
typedef __PACKED_PRE struct __PACKED_POST OMB_OMB_IO_STATUStag {
  /*  Messages Send to TCP-Task */
  TLR_UINT32 ulMsgSend;
  /*  Messages Recv from TCP-Task */
  TLR_UINT32 ulMsgRecv;
  /*  FC1  Count */
  TLR_UINT32 ulFc1Cnt;
  /*  FC2  Count */
  TLR_UINT32 ulFc2Cnt;
  /*  FC3  Count */
  TLR_UINT32 ulFc3Cnt;
  /*  FC4  Count */
  TLR_UINT32 ulFc4Cnt;
  /*  FC5  Count */
  TLR_UINT32 ulFc5Cnt;
  /*  FC6  Count */
  TLR_UINT32 ulFc6Cnt;
  /*  FC7  Count */
  TLR_UINT32 ulFc7Cnt;
  /*  FC15 Count */
  TLR_UINT32 ulFc15Cnt;
  /*  FC16 Count */
  TLR_UINT32 ulFc16Cnt;
  /*  FC23 Count */
  TLR_UINT32 ulFc23Cnt;
  /*  Modbus address */
  TLR_UINT16 usModbusAdr;
  /*  Data count */
  TLR_UINT16 usDataCnt;
  /*  Function code */
  TLR_UINT16 usFunction;
  /*  Data */
  TLR_UINT16 ausData[3];
  /*  Error Count */
  TLR_UINT32 ulErrorCount;
  /*  Last Error */
  TLR_UINT32 ulLastError;
  /* Process data watchdog event counter */
  TLR_UINT32 ulPdwEventCounter;
} OMB_OMB_IO_STATUS;
#endif
#ifndef __STRUCT_MID_CDG_CODE_DIAG__
#define __STRUCT_MID_CDG_CODE_DIAG__
typedef __PACKED_PRE struct __PACKED_POST MID_CDG_CODE_DIAGtag {
  /*  Info Count */
  TLR_UINT32 ulInfoCnt;
  /*  Warning Count */
  TLR_UINT32 ulWarningCnt;
  /*  Error Count */
  TLR_UINT32 ulErrorCnt;
  /*  Severity Level */
  TLR_UINT32 ulDiagLevel;
  /*  Code */
  TLR_UINT32 ulErrorCode;
  /*  Parameter */
  TLR_UINT32 ulUserParam;
  /*  Module */
  TLR_CHAR abCodeDiagFilename[32];
  /*  Line Number */
  TLR_INT32 lLine;
  /*  Resource Pointer (hidden!!) */
  TLR_UINT32 ulRsc;
} MID_CDG_CODE_DIAG;
#endif
