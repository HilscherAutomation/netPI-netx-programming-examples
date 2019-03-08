/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: OmbOmbTask_Public.h 5417 2016-04-07 13:18:49Z dmilkov $:
Description:
Omb Task
Includes following functions...
**************************************************************************************/

/**
 * @file OmbOmbTask_Public.h
 *  Omb OmbTask - public definition of task
 *
 * The header contains the public definition of task.
 * It has to be included by another task to get access of task specfic definition.
 *
 * @note
 * The structures for the services must be packed on 1 byte of boundary.
 * The <code>#pragma</code> instructions are already planned for Microsoft compiler.
 * For gnu's compiler and Realview compiler the macros <code>__PACKED_PRE</code>
 * and <code>__PACKED_PRE</code> have to be added with the structural definition
 * in addition.
 */
#ifndef __OMB_OMBTASK_PUBLIC_H
#define __OMB_OMBTASK_PUBLIC_H


#include "TcpipTcpTask_Public.h"
#include "OmbOmb_DiagStructDef.h"



/*************************************************************************************/
/** @name Queue Name
 *
 * Use the queue name to identify the process queue of task 'Omb OmbTask'.
 * Example for internal identification:<br>
 * @code
 * TLR_RESULT eRslt;
 * TLR_HANDLE hQue;
 * TLR_UINT   uiInstance = 0;
 *
 * eRslt = TLR_QUE_IDENTIFY_INTERN(
 *                                 OMB_OMBTASK_QUEUE_NAME,
 *                                 uiInstance,
 *                                 &hQue
 *                                );
 * @endcode
 * <br>
 * Example for external or normal identification:<br>
 * @code
 * TLR_RESULT      eRslt;
 * TLR_QUE_LINK_T  tQue;
 * TLR_UINT        uiInstance = 0;
 *
 * eRslt = TLR_QUE_IDENTIFY(OMB_OMBTASK_QUEUE_NAME, uiInstance, &tQue);
 * @endcode
 * <br>
 * @{
 */
/** queue name */
#define OMB_OMBTASK_QUEUE_NAME        "QUE_OMBTASK"

/** Task name */
#define OMB_TASK_NAME                 "OMB"


/** @} */

/** Omb shared memory name. */
#define OMB_SHARED_MEMORY_NAME        "IO_IMAGE"

/****************************************************************************************
* OMB OMBTASK, Public defines */

/* OMB task modes */
#define OMB_MESSAGE_MODE    0     /* Message (packet) mode            */
#define OMB_IO_MODE         1     /* IO mode                          */

#define OMB_MAX_DATA_CNT    250   /* Maximum user data count in bytes */
                                  /* (125 registers or 2000 coils)    */

#define OMB_DATA_MODEL_SIZE 65536 /* Size of Modbus Data model, see   */
                                  /* OMB_SPEC_V11a, chapter 4.3 (p. 6)*/

/* Maximum register/coil counts of function codes (defines from OmbUser.h)  */
/* (e.g. value ulDataCnt of struct OMB_OMBTASK_DATA_CMD_T (struct tFcStd))  */
#define OMB_FC1_DATA_CNT_MAX        2000
#define OMB_FC2_DATA_CNT_MAX        2000
#define OMB_FC3_DATA_CNT_MAX        125
#define OMB_FC4_DATA_CNT_MAX        125

#define OMB_FC5_DATA_CNT            1     /* Implicit 1 */
#define OMB_FC6_DATA_CNT            1     /* Implicit 1 */
#define OMB_FC7_DATA_CNT            1
#define OMB_FC15_DATA_CNT_MAX       1968
#define OMB_FC16_DATA_CNT_MAX       123

#define OMB_FC23_DATA_CNT_READ_MAX  125
#define OMB_FC23_DATA_CNT_WRITE_MAX 121


/* task state (OMB_OMB_INFO_STATUS, ulTaskState) */
#define OMB_ST_TASK_NOT_INITIALIZED         (0)
#define OMB_ST_TASK_RUNNING                 (1)
#define OMB_ST_TASK_INITIALIZING            (2)
#define OMB_ST_TASK_INIT_ERROR              (3)
#define OMB_ST_TASK_WAIT_CONFIG             (4)


/****************************************************************************************
* OMB OMBTASK, command codes  */

/* Start of the reserved area from 0x3F00 - 0x3FFF for OMB OMBTASK commands */
#define OMB_OMBTASK_PACKET_COMMAND_START                  0x00003F00


/* Summary of the Open Modbus/TCP (OMB) task  service commands and primitives */

/* Register OMB AP task */
#define OMB_OMBTASK_CMD_REGISTER_OMB_AP_REQ               0x00003F00
#define OMB_OMBTASK_CMD_REGISTER_OMB_AP_CNF               0x00003F01

/* Register application (over Dualport-memory) */
#define OMB_OMBTASK_CMD_REGISTER_AP_REQ                   0x00003F02
#define OMB_OMBTASK_CMD_REGISTER_AP_CNF                   0x00003F03

/* Warmstart (Set config) */
#define OMB_OMBTASK_CMD_WARMSTART_REQ                     0x00003F04
#define OMB_OMBTASK_CMD_WARMSTART_CNF                     0x00003F05

/* Server mode */
#define OMB_OMBTASK_CMD_RECEIVE_IND                       0x00003F06
#define OMB_OMBTASK_CMD_RECEIVE_RES                       0x00003F07

/* Client mode */
#define OMB_OMBTASK_CMD_SEND_REQ                          0x00003F08
#define OMB_OMBTASK_CMD_SEND_CNF                          0x00003F09

/* State change */
#define OMB_OMBTASK_CMD_STATE_CHANGE_IND                  0x00003F0A
#define OMB_OMBTASK_CMD_STATE_CHANGE_RES                  0x00003F0B

/* Watchdog fail */
#define OMB_OMBTASK_CMD_SET_WATCHDOG_FAIL_REQ             0x00003F0C
#define OMB_OMBTASK_CMD_SET_WATCHDOG_FAIL_CNF             0x00003F0D

/* Read Modbus Memory map area */
#define OMB_OMBTASK_CMD_MOD_MEMORY_MAP_READ_REQ           0x00003F0E
#define OMB_OMBTASK_CMD_MOD_MEMORY_MAP_READ_CNF           0x00003F0F

/* Write Modbus Memory map area */
#define OMB_OMBTASK_CMD_MOD_MEMORY_MAP_WRITE_REQ          0x00003F10
#define OMB_OMBTASK_CMD_MOD_MEMORY_MAP_WRITE_CNF          0x00003F11

/* Initialize stack (Channel reset) */
#define OMB_OMBTASK_CMD_INITIALIZE_REQ                    0x00003F12
#define OMB_OMBTASK_CMD_INITIALIZE_CNF                    0x00003F13

/* Unregister application (over Dualport-memory) */
#define OMB_OMBTASK_CMD_UNREGISTER_AP_REQ                 0x00003F14
#define OMB_OMBTASK_CMD_UNREGISTER_AP_CNF                 0x00003F15

/* Start/Stop Open Modbus/TCP stack */
#define OMB_OMBTASK_CMD_START_STOP_OMB_REQ                0x00003F16
#define OMB_OMBTASK_CMD_START_STOP_OMB_CNF                0x00003F17

/* New warmstart (set config) packet - sets only the parameter */
#define OMB_OMBTASK_CMD_OMB_SET_CONFIGURATION_REQ         0x00003F18
#define OMB_OMBTASK_CMD_OMB_SET_CONFIGURATION_CNF         0x00003F19

/* Connection Indication */
#define OMB_OMBTASK_CMD_CONNECTION_IND                    0x00003F1A
#define OMB_OMBTASK_CMD_CONNECTION_RES                    0x00003F1B

                  /* internal command codes starting with 0x00003FE0! */


/* Inactivity Timeout Values in ms. */
#define OMB_OMBTASK_INACTIVITY_TIMEOUT_DEFAULT            30000
#define OMB_OMBTASK_INACTIVITY_TIMEOUT_MIN                20
#define OMB_OMBTASK_INACTIVITY_TIMEOUT_MAX                65535

/****************************************************************************************
* OMB OMBTASK, Structs */

/*---------------------------------------------------------------------------*/
/* Compiler settings */
#if _MSC_VER >= 1000
  #define __OMB_PACKED_PRE
  #define __OMB_PACKED_POST
  #pragma once
  #pragma pack(1)            /* Always align structures to byte boundery */
  #ifndef STRICT             /* Check Typdefinition */
    #define STRICT
  #endif
#endif /* _MSC_VER >= 1000 */


/* support for GNU compiler */
#if defined( __GNUC__ )
  #define __OMB_PACKED_PRE
  #define __OMB_PACKED_POST       __attribute__((__packed__))
#endif

/* support for REALVIEW ARM compiler */
#if defined (__ADS__) || defined (__REALVIEW__)
  #define __OMB_PACKED_PRE        __packed
  #define __OMB_PACKED_POST
#endif



/* Open Modbus/TCP task parameters */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_CONFIG_Ttag
{
  TLR_UINT32  ulOpenServerSockets;    /* number of sockets to open  */
  TLR_UINT32  ulAnswerTimeout;        /* Internal Timeout           */
  TLR_UINT32  ulOmbOpenTime;          /* Time to close Socket       */
  TLR_UINT32  ulMode;                 /* Message or IO-Mode         */
  TLR_UINT32  ulSendTimeout;          /* Parameter for TCP-Task     */
  TLR_UINT32  ulConnectTimeout;       /* Parameter for TCP-Task     */
  TLR_UINT32  ulCloseTimeout;         /* Parameter for TCP-Task     */
  TLR_UINT32  ulSwap;                 /* Swap Data or not           */

} __OMB_PACKED_POST OMB_OMBTASK_CONFIG_T;


/* Open Modbus/TCP task extended parameter */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_CONFIG_EXT_Ttag
{
  TLR_UINT32                          ulProcessWatchdog;
  TLR_UINT32                          ulInactiveTimeout;
  TLR_UINT16                          usMaxRegisterNumber;
  TLR_UINT16                          usMaxCoilsNumber;
  TLR_UINT16                          ausReserved[2];

} __OMB_PACKED_POST OMB_OMBTASK_CONFIG_EXT_T;

/* Open Modbus/TCP task identification parameter (FC43) */
#define OMB_OMBTASK_VENDOR_NAME_STR_SIZE              (64)
#define OMB_OMBTASK_PRODUCT_CODE_STR_SIZE             (64)
#define OMB_OMBTASK_MAJ_MIN_REV_STR_SIZE              (16)
#define OMB_OMBTASK_VENDOR_URL_STR_SIZE               (64)
#define OMB_OMBTASK_PRODUCT_NAME_STR_SIZE             (64)
#define OMB_OMBTASK_MODEL_NAME_STR_SIZE               (64)
#define OMB_OMBTASK_USER_APP_NAME_STR_SIZE            (64)

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_CONFIG_IDENT_Ttag
{
  TLR_CHAR  szVendorName[OMB_OMBTASK_VENDOR_NAME_STR_SIZE];
  TLR_CHAR  szProductCode[OMB_OMBTASK_PRODUCT_CODE_STR_SIZE];
  TLR_CHAR  szRevision[OMB_OMBTASK_MAJ_MIN_REV_STR_SIZE];
  TLR_CHAR  szVendorUrl[OMB_OMBTASK_VENDOR_URL_STR_SIZE];
  TLR_CHAR  szProductName[OMB_OMBTASK_PRODUCT_NAME_STR_SIZE];
  TLR_CHAR  szModelName[OMB_OMBTASK_MODEL_NAME_STR_SIZE];
  TLR_CHAR  szUseAppName[OMB_OMBTASK_USER_APP_NAME_STR_SIZE];
} __OMB_PACKED_POST OMB_OMBTASK_CONFIG_IDENT_T;


/* Dualport-memory task state */

/* Define this lowest eight flags compatible to RCS - this is helpful, e.g. for FC7   */
/* ==> Not used for FC7 - not senseful!                                               */
#define OMB_OMBTASK_STATE_FLAG_CMD_TABLE_LOADED   0x00008000L
#define OMB_OMBTASK_STATE_FLAG_IP_ADDR            0x00004000L
#define OMB_OMBTASK_STATE_FLAG_TIME_LIMIT_REACHED 0x00002000L
#define OMB_OMBTASK_STATE_TCP_CONFIG_FLAG_RDY     0x00001000L
#define OMB_OMBTASK_STATE_FLAG_RDY                0x00000080L   /* RCS flag READY               */
#define OMB_OMBTASK_STATE_FLAG_RUN                0x00000040L   /* RCS flag RUN                 */
#define OMB_OMBTASK_STATE_FLAG_COM                0x00000020L   /* RCS flag COM                 */
#define OMB_OMBTASK_STATE_FLAG_PD_EXT_ACK         0x00000010L   /* RCS flag PdExtAck - not used */
#define OMB_OMBTASK_STATE_FLAG_COMM_ERROR         0x00000008L   /* RCS flag ERR                 */
#define OMB_OMBTASK_STATE_FLAG_PD_ACK             0x00000004L   /* RCS flag PdAck    - not used */
#define OMB_OMBTASK_STATE_FLAG_DEV_ACK            0x00000002L   /* RCS flag DevAck   - not used */
#define OMB_OMBTASK_STATE_FLAG_HOST_COM           0x00000001L   /* RCS flag HostCom  - not used */

#define OMB_OMBTASK_STATE_FLAG_WARMSTART          0x00000100L   /* Warmstart active         */
#define OMB_OMBTASK_STATE_FLAG_CONFIG_RELOAD      0x00000200L   /* Config reload active     */
#define OMB_OMBTASK_STATE_FLAG_FATAL_ERROR        0x00000400L   /* Fatal error of OMB task  */
#define OMB_OMBTASK_STATE_FLAG_SET_CONFIGURATION  0x00000800L   /* Set configuration active */


#define OMB_OMBTASK_BIT_SLAVES_SIZE      (16)
#define OMB_OMBTASK_BIT_COMMANDS_SIZE    (32)

#define OMB_OMBTASK_MAX_SERVERS_NUMBER   OMB_OMBTASK_BIT_SLAVES_SIZE*8
#define OMB_OMBTASK_MAX_COMMANDS_NUMBER  OMB_OMBTASK_BIT_COMMANDS_SIZE*8

/* The diagnostic information is based on server (IP address) connection level. */
typedef struct OMB_BIT_FIELDS_Ttag
{
  TLR_UINT8 abConfigSlaves[OMB_OMBTASK_BIT_SLAVES_SIZE];   /* Configured Slave                  */
  TLR_UINT8 abActiveSlaves[OMB_OMBTASK_BIT_SLAVES_SIZE];   /* Active Slave in communication     */
  TLR_UINT8 abDiagSlaves[OMB_OMBTASK_BIT_SLAVES_SIZE];     /* Slave with diagnostic             */
  TLR_UINT8 abCommandDiag[OMB_OMBTASK_BIT_COMMANDS_SIZE];  /* Diag flags per configured command */

}OMB_BIT_FIELDS_T;

/* Contains variables from Communication Channels "Common Status Block" and some  */
/* further variables that must signaled to AP task (LED's, ...)                   */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DPM_STATE_Ttag
{
  TLR_UINT32                  ulCommunicationState;  /* Modbus communication state RCX_COMM_STATE_xx (NETX_COMMON_STATUS_BLOCK) */     /* ulCanState;   CAN state */

  TLR_UINT32                  ulFlags;
  TLR_UINT32                  ulErrorCount; /* Error count (NETX_COMMON_STATUS_BLOCK) */

  TLR_UINT32                  ulCommunicationError;    /* RCX_COMM_xx (e.g. RCX_COMM_CONNECTION_CLOSED) - (NETX_COMMON_STATUS_BLOCK) */
  TLR_UINT32                  ulRunLedState;
  TLR_UINT32                  ulErrLedState;

  TLR_UINT32                  ulInputSize;
  TLR_UINT32                  ulOutputSize;

  TLR_UINT32                  aulReserved[1];

  OMB_BIT_FIELDS_T            tStatusBitField;

  /* The diagnostic information is based on server (IP address) connection level. */
  TLR_UINT32                  ulConfigSlaves;
  TLR_UINT32                  ulActiveSlaves;
  TLR_UINT32                  ulDiagSlaves;

} __OMB_PACKED_POST OMB_OMBTASK_DPM_STATE_T;


/*************************************************************************************/
/* Omb OmbTask public, packets */




/*
 * Structures of all Request/Confirmation commands the task is able to send and receive
 *
 * Request and Confirmation Packets __PREFIX___PACKET___TASKNAME___xx_REQ/CNF
 * (xx = Command)
 *
 * Use the same order as the commands in TLR_Commands.h
 * __PREFIX_____TASKNAME___xx_REQ/CNF (xx = Command)!
 */




/*** Definition of the packet types this Task is able to receive/send as server ***/

/* Packet for send received OMB data to the application - OMB_OMBTASK_CMD_RECEIVE */

/* __START__ */


/* Register OMB AP task */
#define OMB_OMBTASK_DATA_CMD_AP_REGISTER_OMB_AP_REQ_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_REGISTER_OMB_AP_REQ_Ttag
{
  TLR_PACKET_HEADER_T     tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_REGISTER_OMB_AP_REQ_T;


#define OMB_OMBTASK_DATA_CMD_AP_REGISTER_OMB_AP_CNF_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_REGISTER_OMB_AP_CNF_Ttag
{
  TLR_PACKET_HEADER_T     tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_REGISTER_OMB_AP_CNF_T;




/* Register application (over Dualport-memory) */
#define OMB_OMBTASK_DATA_CMD_AP_REGISTER_AP_REQ_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_REGISTER_AP_REQ_Ttag
{
  TLR_PACKET_HEADER_T     tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_REGISTER_AP_REQ_T;


#define OMB_OMBTASK_DATA_CMD_AP_REGISTER_AP_CNF_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_REGISTER_AP_CNF_Ttag
{
  TLR_PACKET_HEADER_T     tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_REGISTER_AP_CNF_T;




/* Unregister application (over Dualport-memory) */
#define OMB_OMBTASK_DATA_CMD_AP_UNREGISTER_AP_REQ_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_UNREGISTER_AP_REQ_Ttag
{
  TLR_PACKET_HEADER_T     tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_UNREGISTER_AP_REQ_T;


#define OMB_OMBTASK_DATA_CMD_AP_UNREGISTER_AP_CNF_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_UNREGISTER_AP_CNF_Ttag
{
  TLR_PACKET_HEADER_T     tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_UNREGISTER_AP_CNF_T;



/* Start/stop OMB task */

/* Mode ulMode */
#define OMB_OMBTASK_STOP_OMB    0x00000000L
#define OMB_OMBTASK_START_OMB   0x00000001L

/* Request */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_START_STOP_OMB_REQ_Ttag
{
  TLR_UINT32                          ulMode; /* Start or stop OMB */

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_START_STOP_OMB_REQ_T;

#define OMB_OMBTASK_DATA_CMD_START_STOP_OMB_REQ_SIZE  \
                            (sizeof(OMB_OMBTASK_DATA_CMD_START_STOP_OMB_REQ_T))

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_START_STOP_OMB_REQ_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;
  OMB_OMBTASK_DATA_CMD_START_STOP_OMB_REQ_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_START_STOP_OMB_REQ_T;

/* Confirmation */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_START_STOP_OMB_CNF_Ttag
{
  TLR_UINT32                          ulMode; /* Start or stop OMB */

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_START_STOP_OMB_CNF_T;

#define OMB_OMBTASK_DATA_CMD_START_STOP_OMB_CNF_SIZE  \
                            (sizeof(OMB_OMBTASK_DATA_CMD_START_STOP_OMB_CNF_T))

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_START_STOP_OMB_CNF_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;
  OMB_OMBTASK_DATA_CMD_START_STOP_OMB_CNF_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_START_STOP_OMB_CNF_T;




/* Set config */

/* Warmstart System Flags */
#define OMB_OMBTASK_SYS_FLAG_COM_CONTROLLED_RELEASE   (0x00000001)
#define OMB_OMBTASK_SYS_FLAG_IO_STATUS_ENABLED        (0x00000002)
#define OMB_OMBTASK_SYS_FLAG_IO_STATUS_32_BIT         (0x00000004)

/* Limits of parameter ulWdgTime */
#define OMB_OMBTASK_WDG_OFF                           (0x00000000)
#define OMB_OMBTASK_WDG_MIN_TIMEOUT                   (0x00000014)
#define OMB_OMBTASK_WDG_MAX_TIMEOUT                   (0x0000FFFF)

/* Flags parameter (ulFlags) */
#define OMB_OMBTASK_CFG_FLAG_DEFAULT                          (0x00000000)

#define OMB_OMBTASK_CFG_FLAG_FC1_FC3_OUTPUT                   (0x00000001)
      /* Maps Function codes FC1 and FC3 to the Output Data image of    */
      /* Dualport-memory. Needed for Clients without FC2, FC4 support.  */

#define OMB_OMBTASK_CFG_FLAG_TCPIP_NO_CONFIG                  (0x00000002)
      /* Don't configure the TCP/IP stack (must be done by someone else)*/

#define OMB_OMBTASK_CFG_FLAG_FAILSAFE_MASK                    (0x0000000C)
      /* Fail-Safe Mode Flags                                           */
      /* Fail-Safe Mode: Set : Hold Last State                          */

#define OMB_OMBTASK_CFG_FLAG_FAILSAFE_SET                     (0x00000004)
      /* Fail-Safe Mode: Set                                            */

#define OMB_OMBTASK_CFG_FLAG_FAILSAFE_HLS                     (0x00000008)
      /* Fail-Safe Mode: Hold Last State                                */

#define OMB_OMBTASK_CFG_FLAG_PRESET_INPUTS                    (0x00000010)
      /* Preset Inputs Values.                                          */
      /* 0 - all inputs are cleared after init (default)                */
      /* 1 - all inputs are set after init                              */

#define OMB_OMBTASK_CFG_FLAG_SERVER_CONNECTION_IND_FORWARDING (0x00000020)
      /* Forwardind of Connection Indication packet                     */
      /*      0: Disable (default)                                      */
      /*      1: Enable                                                 */
      /* If this bit is set the packet Connection Indication will be    */
      /* forwarded to the host application                              */

#define OMB_OMBTASK_CFG_FLAG_READ_WD_TRIGGER                  (0x00000100)
      /* Process Watchdog Trigger                                       */
      /* 0 - Write requests will trigger the WD                         */
      /* 1 - Read and Write requests will trigger the WD                */

#define OMB_OMBTASK_CFG_FLAG_FC7_ENABLE_FORWARDING            (0x00000200)
      /* F07 Forwarding:                                                */
      /*      0: Forwarding FC07 disabled (Default)                     */
      /*      1: Forwarding FC07 enabled                                */
      /* If this bit is set function code FC07 is forwarded to host     */
      /* application. Normally. Only relevant in MESSAGE_MODE           */

#define OMB_OMBTASK_VENDOR_NAME_STR_SIZE              (64)
#define OMB_OMBTASK_PRODUCT_CODE_STR_SIZE             (64)
#define OMB_OMBTASK_MAJ_MIN_REV_STR_SIZE              (16)
#define OMB_OMBTASK_VENDOR_URL_STR_SIZE               (64)
#define OMB_OMBTASK_PRODUCT_NAME_STR_SIZE             (64)
#define OMB_OMBTASK_MODEL_NAME_STR_SIZE               (64)
#define OMB_OMBTASK_USER_APP_NAME_STR_SIZE            (64)

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_AP_WARMSTART_REQ_Ttag
{
  TLR_UINT32                          ulSystemFlags;
  TLR_UINT32                          ulWdgTime;

  OMB_OMBTASK_CONFIG_T                tOmbConfig;
  TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_T  tTcpConfig;

  /* Flags parameter, see above */
  TLR_UINT32  ulFlags;

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_AP_WARMSTART_REQ_T;


#define OMB_OMBTASK_DATA_CMD_AP_WARMSTART_REQ_SIZE  \
                            (sizeof(OMB_OMBTASK_DATA_CMD_AP_WARMSTART_REQ_T))

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_WARMSTART_REQ_Ttag
{
  TLR_PACKET_HEADER_T                      tHead;
  OMB_OMBTASK_DATA_CMD_AP_WARMSTART_REQ_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_WARMSTART_REQ_T;


#define OMB_OMBTASK_DATA_CMD_AP_WARMSTART_CNF_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_WARMSTART_CNF_Ttag
{
  TLR_PACKET_HEADER_T                    tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_WARMSTART_CNF_T;


/* Send/Receive data */

/* Definitions to calculate the Packet lengths ulLen (only data part  */
/* abData[] of struct OMB_OMBTASK_DATA_CMD_T!!)                       */
#define OMB_FC5_PACKET_LEN        1 /* Length of Data part of FC5     */
#define OMB_FC6_PACKET_LEN        2 /* Length of Data part of FC6     */
#define OMB_FC7_PACKET_LEN        1

/* Helper macros for calculating the Byte count of Coils or Registers */
#define OMB_BYTES_OF_COIL(len)    (((len)+7)/8) /* Byte count of Coils*/
#define OMB_BYTES_OF_REG(len)     (2*(len)) /* Byte count of Registers*/

/* Valid function codes of packet ulFunctionCode variable */
#define OMB_OMBTASK_FC1       (1)
#define OMB_OMBTASK_FC2       (2)
#define OMB_OMBTASK_FC3       (3)
#define OMB_OMBTASK_FC4       (4)
#define OMB_OMBTASK_FC5       (5)
#define OMB_OMBTASK_FC6       (6)
#define OMB_OMBTASK_FC7       (7)
#define OMB_OMBTASK_FC15      (15)
#define OMB_OMBTASK_FC16      (16)
#define OMB_OMBTASK_FC23      (23)
#define OMB_OMBTASK_FC43      (43)

/* Exception Status coils of FC7 */
#define OMB_OMBTASK_COIL_FC7_USER_NOT_READY   (0x01)  /* Set = Host application is not registerd        */
#define OMB_OMBTASK_COIL_FC7_WATCHDOG_ERROR   (0x02)  /* Set = Watchdog error active                    */
#define OMB_OMBTASK_COIL_FC7_NO_IO_ACCESS     (0x04)  /* Set = Access to IO image NOT allowed (IO mode) */
#define OMB_OMBTASK_COIL_FC7_RESERVED         (0xF8)  /* Reserved coils                                 */


/* One data structure for all OMB services: */
/*  - Receive indication  (Server)          */
/*  - Receive response    (Server)          */
/*  - Send request        (Client)          */
/*  - Send confirmation   (Client)          */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_Ttag
{
  TLR_UINT32  ulRouting;          /* IP address               */
  TLR_UINT32  ulUnitId;           /* Unit identifier          */

  TLR_UINT32  ulFunctionCode;     /* Function code (FC)       */
  TLR_UINT32  ulException;        /* Exception code           */

  __OMB_PACKED_PRE union
  {
    __OMB_PACKED_PRE struct
    {
      TLR_UINT32  ulDataAdr;      /* Starting address         */
      TLR_UINT32  ulDataCnt;      /* Register- or Bit-Count   */

      TLR_UINT8   abData[OMB_MAX_DATA_CNT];
    } __OMB_PACKED_POST tFcStd;   /* Union for FCs 1-6, 15-16 */

    __OMB_PACKED_PRE struct
    {
      TLR_UINT32  ulDataAdrRead;  /* Read Starting address    */
      TLR_UINT32  ulDataCntRead;  /* Quantity to Read         */
      TLR_UINT32  ulDataAdrWrite; /* Write Starting address   */
      TLR_UINT32  ulDataCntWrite; /* Quantity to Write        */
      TLR_UINT8   abData[OMB_MAX_DATA_CNT];
    } __OMB_PACKED_POST tFc23;    /* Union for FC 23          */

  } __OMB_PACKED_POST unData;     /* Data part of PDU         */

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_T;


/* The following size defines must be independet of future extensions with  */
/* bigger unions (because of compatibility reasons)!!                       */

/* Receive indication */
#define OMB_OMBTASK_DATA_CMD_RECEIVE_IND_SIZE_FC_STD  \
          ( 6 * sizeof(TLR_UINT32) )

#define OMB_OMBTASK_DATA_CMD_RECEIVE_IND_SIZE_FC23    \
          ( 8 * sizeof(TLR_UINT32) )

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_RECEIVE_IND_Ttag
{
  TLR_PACKET_HEADER_T     tHead;
  OMB_OMBTASK_DATA_CMD_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_RECEIVE_IND_T;


/* Receive response */
#define OMB_OMBTASK_DATA_CMD_RECEIVE_RES_SIZE_FC_STD  \
          OMB_OMBTASK_DATA_CMD_RECEIVE_IND_SIZE_FC_STD

#define OMB_OMBTASK_DATA_CMD_RECEIVE_RES_SIZE_FC23    \
          OMB_OMBTASK_DATA_CMD_RECEIVE_IND_SIZE_FC23

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_RECEIVE_RES_Ttag
{
  TLR_PACKET_HEADER_T     tHead;
  OMB_OMBTASK_DATA_CMD_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_RECEIVE_RES_T;


/* Send request */
#define OMB_OMBTASK_DATA_CMD_SEND_REQ_SIZE_FC_STD     \
          OMB_OMBTASK_DATA_CMD_RECEIVE_IND_SIZE_FC_STD

#define OMB_OMBTASK_DATA_CMD_SEND_REQ_SIZE_FC23       \
          OMB_OMBTASK_DATA_CMD_RECEIVE_IND_SIZE_FC23

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_SEND_REQ_Ttag
{
  TLR_PACKET_HEADER_T     tHead;
  OMB_OMBTASK_DATA_CMD_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_SEND_REQ_T;


/* Send confirmation */
#define OMB_OMBTASK_DATA_CMD_SEND_CNF_SIZE_FC_STD     \
          OMB_OMBTASK_DATA_CMD_RECEIVE_IND_SIZE_FC_STD

#define OMB_OMBTASK_DATA_CMD_SEND_CNF_SIZE_FC23       \
          OMB_OMBTASK_DATA_CMD_RECEIVE_IND_SIZE_FC23

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_SEND_CNF_Ttag
{
  TLR_PACKET_HEADER_T     tHead;
  OMB_OMBTASK_DATA_CMD_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_SEND_CNF_T;




/* State change indication */
/* All included structs are DWORD aligned - must not pack! */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_EXTENDED_STATE_Ttag
{
  OMB_OMB_INFO_STATUS     tOmbInfoStatus;   /* General information structure      */
  MID_CDG_CODE_DIAG       tMidCodeDiag;     /* Codediag information               */

} __OMB_PACKED_POST OMB_OMBTASK_EXTENDED_STATE_T;

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_AP_STATE_CHANGE_IND_Ttag
{
  OMB_OMBTASK_DPM_STATE_T       tDpmState;
  OMB_OMBTASK_EXTENDED_STATE_T  tExtendedState;

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_AP_STATE_CHANGE_IND_T;

#define OMB_OMBTASK_DATA_CMD_AP_STATE_CHANGE_IND_SIZE \
          ( sizeof(OMB_OMBTASK_DATA_CMD_AP_STATE_CHANGE_IND_T) )

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_STATE_CHANGE_IND_Ttag
{
  TLR_PACKET_HEADER_T                         tHead;
  OMB_OMBTASK_DATA_CMD_AP_STATE_CHANGE_IND_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_STATE_CHANGE_IND_T;


#define OMB_OMBTASK_DATA_CMD_AP_STATE_CHANGE_RES_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_AP_STATE_CHANGE_RES_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_AP_STATE_CHANGE_RES_T;




/* Watchdog fail */
#define OMB_OMBTASK_DATA_CMD_SET_WATCHDOG_FAIL_REQ_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_SET_WATCHDOG_FAIL_REQ_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_SET_WATCHDOG_FAIL_REQ_T;


#define OMB_OMBTASK_DATA_CMD_SET_WATCHDOG_FAIL_CNF_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_SET_WATCHDOG_FAIL_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_SET_WATCHDOG_FAIL_CNF_T;




/* Modbus Memory map read */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_READ_REQ_Ttag
{
  TLR_UINT32      ulOffset;   /* Read offset in Modbus Memory map */
  TLR_UINT32      ulByteCnt;  /* Read data count in bytes         */
  TLR_UINT8 FAR*  pbData;     /* Buffer (space) for Read data     */

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_READ_REQ_T;

#define OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_READ_REQ_SIZE  \
                            (sizeof(OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_READ_REQ_T))

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_MOD_MEMORY_MAP_READ_REQ_Ttag
{
  TLR_PACKET_HEADER_T                             tHead;
  OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_READ_REQ_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_MOD_MEMORY_MAP_READ_REQ_T;


#define OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_READ_CNF_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_MOD_MEMORY_MAP_READ_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_MOD_MEMORY_MAP_READ_CNF_T;


/* Modbus Memory map write */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_WRITE_REQ_Ttag
{
  TLR_UINT32      ulOffset;   /* Write offset in Modbus Memory map  */
  TLR_UINT32      ulByteCnt;  /* Write data count in bytes          */
  TLR_UINT8 FAR*  pbData;     /* Write data buffer                  */

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_WRITE_REQ_T;

#define OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_WRITE_REQ_SIZE  \
                            (sizeof(OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_WRITE_REQ_T))

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_MOD_MEMORY_MAP_WRITE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                              tHead;
  OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_WRITE_REQ_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_MOD_MEMORY_MAP_WRITE_REQ_T;


#define OMB_OMBTASK_DATA_CMD_MOD_MEMORY_MAP_WRITE_CNF_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_MOD_MEMORY_MAP_WRITE_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_MOD_MEMORY_MAP_WRITE_CNF_T;


/* Modbus Set Configuration Packet */
typedef __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_SET_CONFIGURATION_REQ_Ttag
{
  TLR_UINT32                          ulSystemFlags;
  TLR_UINT32                          ulWdgTime;

  OMB_OMBTASK_CONFIG_T                tOmbConfig;
  TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_T  tTcpConfig;

  /* Flags parameter, see above */
  TLR_UINT32  ulFlags;

  OMB_OMBTASK_CONFIG_EXT_T            tOmbConfigExt;
  OMB_OMBTASK_CONFIG_IDENT_T          tOmbConfigIdent;

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_SET_CONFIGURATION_REQ_T;

#define OMB_OMBTASK_DATA_CMD_SET_CONFIGURATION_REQ_SIZE  \
                            (sizeof(OMB_OMBTASK_DATA_CMD_SET_CONFIGURATION_REQ_T))

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_SET_CONFIGURATION_REQ_Ttag
{
  TLR_PACKET_HEADER_T                           tHead;
  OMB_OMBTASK_DATA_CMD_SET_CONFIGURATION_REQ_T  tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_SET_CONFIGURATION_REQ_T;


#define OMB_OMBTASK_DATA_CMD_SET_CONFIGURATION_CNF_SIZE   0

typedef __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_SET_CONFIGURATION_CNF_Ttag
{
  TLR_PACKET_HEADER_T                    tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_SET_CONFIGURATION_CNF_T;



/* Connection Indication Packet */

#define OMB_OMBTASK_CONNECTION_STATE_DISCONNECTED (0x00)
#define OMB_OMBTASK_CONNECTION_STATE_CONNECTED    (0x01)

typedef  __OMB_PACKED_PRE struct OMB_OMBTASK_DATA_CMD_CONNECTION_IND_Ttag
{
  TLR_UINT32  ulConnectionId;     /* Connection identifier    */
  TLR_UINT8   bStatus;            /* Connection status        */
  TLR_UINT8   bType;              /* Connection type          */
  TLR_UINT16  usReserved;         /* Reserved                 */
  TLR_UINT32  ulIpAddress;        /* Connected IP Address     */

} __OMB_PACKED_POST OMB_OMBTASK_DATA_CMD_CONNECTION_IND_T;

#define OMB_OMBTASK_DATA_CMD_CONNECTION_IND_SIZE \
          (sizeof(OMB_OMBTASK_DATA_CMD_CONNECTION_IND_T) )

typedef  __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_CONNECTION_IND_Ttag
{
  TLR_PACKET_HEADER_T                         tHead;
  OMB_OMBTASK_DATA_CMD_CONNECTION_IND_T       tData;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_CONNECTION_IND_T;

typedef  __OMB_PACKED_PRE struct OMB_OMBTASK_PACKET_CMD_CONNECTION_RES_Ttag
{
  TLR_PACKET_HEADER_T                         tHead;

} __OMB_PACKED_POST OMB_OMBTASK_PACKET_CMD_CONNECTION_RES_T;

#define OMB_OMBTASK_DATA_CMD_CONNECTION_RES_SIZE   0


/*---------------------------------------------------------------------------*/
/* Compiler settings */
#if _MSC_VER >= 1000
  #pragma pack()           /* Always allign structures to compiler settings  */
#endif /* _MSC_VER >= 1000 */
/*---------------------------------------------------------------------------*/

#undef __OMB_PACKED_PRE
#undef __OMB_PACKED_POST

/*************************************************************************************/
#endif /* #ifndef __OMB_OMBTASK_PUBLIC_H */
