/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: CmdTable_Public.h 5750 2016-05-13 06:33:43Z ynikolov $:

Description:
 The header contains the public definition of the task.
 It has to be included by another task to get access of task specific definition.

Changes:

 -----------------------------------------------------------------------------------
 2016-01-13 created
**************************************************************************************/


#ifndef __CMDTBL_PUBLIC_H
#define __CMDTBL_PUBLIC_H

#include "CmdTable_Configuration.h"

/*************************************************************************************/
/** @name Queue Name
 *
 * Use the queue name to identify the process queue of task 'Cmd Table'.
 * Example for internal identification:<br>
 * @code
 * TLR_RESULT eRslt;
 * TLR_HANDLE hQue;
 * TLR_UINT   uiInstance = 0;
 *
 * eRslt = TLR_QUE_IDENTIFY_INTERN(
 *                                 CMDTBL_QUEUE_NAME,
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
 * eRslt = TLR_QUE_IDENTIFY(CMDTBL_QUEUE_NAME, uiInstance, &tQue);
 * @endcode
 * <br>
 * @{
 */
/** queue name */
#define CMDTBL_QUEUE_NAME               "QUE_CMDTBL"

/* CmdTable shared memory name. */
#define CMDTBL_DIAG_SHM_NAME            "DIAG_IMAGE"

#define CMDTBL_MAX_QUE_NAME_LEN         16
/*******************************************************************
* Command Table Commands
*******************************************************************/
#define CMDTBL_INIT_REQ                 (0x0000A300)
#define CMDTBL_INIT_CNF                 (0x0000A301)

#define CMDTBL_ADD_TABLE_REQ            (0x0000A302)
#define CMDTBL_ADD_TABLE_CNF            (0x0000A303)

#define CMDTBL_DELETE_TABLE_REQ         (0x0000A304)
#define CMDTBL_DELETE_TABLE_CNF         (0x0000A305)

#define CMDTBL_ACTIVATE_TABLE_REQ       (0x0000A306)
#define CMDTBL_ACTIVATE_TABLE_CNF       (0x0000A307)

#define CMDTBL_DEACTIVATE_TABLE_REQ     (0x0000A308)
#define CMDTBL_DEACTIVATE_TABLE_CNF     (0x0000A309)

#define CMDTBL_ADD_COMMAND_REQ          (0x0000A30A)
#define CMDTBL_ADD_COMMAND_CNF          (0x0000A30B)

#define CMDTBL_DELETE_COMMAND_REQ       (0x0000A30C)
#define CMDTBL_DELETE_COMMAND_CNF       (0x0000A30D)

#define CMDTBL_ACTIVATE_COMMAND_REQ     (0x0000A30E)
#define CMDTBL_ACTIVATE_COMMAND_CNF     (0x0000A30F)

#define CMDTBL_DEACTIVATE_COMMAND_REQ   (0x0000A310)
#define CMDTBL_DEACTIVATE_COMMAND_CNF   (0x0000A311)

#define CMDTBL_TRIGGER_COMMAND_REQ      (0x0000A312)
#define CMDTBL_TRIGGER_COMMAND_CNF      (0x0000A313)

#define CMDTBL_GET_IO_INFO_REQ          (0x0000A314)
#define CMDTBL_GET_IO_INFO_CNF          (0x0000A315)

#define CMDTBL_DEINIT_REQ               (0x0000A316)
#define CMDTBL_DEINIT_CNF               (0x0000A317)

#define CMDTBL_START_STOP_REQ           (0x0000A318)
#define CMDTBL_START_STOP_CNF           (0x0000A319)


#define CMDTBL_ALL_TABLES_ID                (0)

#define CMDTBL_SLAVES_BIT_FIELD_BYTE_SIZE   (16)
#define CMDTBL_CMD_BIT_FIELD_BYTE_SIZE      (32)
#define CMDTBL_MAX_SLAVES_NUM               (CMDTBL_SLAVES_BIT_FIELD_BYTE_SIZE * 8)
#define CMDTBL_MAX_COMMANDS_NUM             (CMDTBL_CMD_BIT_FIELD_BYTE_SIZE * 8)

#define CMDTBL_CYCLIC_PERIOD_MIN            (0)          /* in ms */
#define CMDTBL_CYCLIC_PERIOD_MAX            (60000)      /* in ms */


typedef enum CMDTBL_START_STOP_COMMAND_Etag
{
  CMDTBL_STOP_COMMAND   = 0,
  CMDTBL_START_COMMAND  = 1,
}
CMDTBL_START_STOP_COMMAND_E;

/*************************************************************************************/
/* packets */

/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(__CMDTBL_PACKET)
#endif

/* Diag data structs. */
typedef struct CMDTBL_BIT_FIELDS_Ttag
{
  uint8_t abConfigSlaves[CMDTBL_SLAVES_BIT_FIELD_BYTE_SIZE]; /* Configured Slave                  */
  uint8_t abActiveSlaves[CMDTBL_SLAVES_BIT_FIELD_BYTE_SIZE]; /* Active Slave in communication     */
  uint8_t abDiagSlaves[CMDTBL_SLAVES_BIT_FIELD_BYTE_SIZE];   /* Slave with diagnostic             */
  uint8_t abCommandDiag[CMDTBL_CMD_BIT_FIELD_BYTE_SIZE];     /* Diag flags per configured command */

}CMDTBL_BIT_FIELDS_T;

typedef struct CMDTBL_SLAVES_DIAG_COUNTERS_Ttag
{
  TLR_UINT32  ulConfigSlavesCount;
  TLR_UINT32  ulActiveSlavesCount;
  TLR_UINT32  ulDiagSlavesCount;
}CMDTBL_SLAVES_DIAG_COUNTERS_T;

typedef struct CMDTBL_DIAG_DATA_Ttag
{
  CMDTBL_BIT_FIELDS_T           tBitFields;
  CMDTBL_SLAVES_DIAG_COUNTERS_T tSlavesDiagCounters;
  uint32_t                      ulErrorCode;
  uint32_t                      ulErrorCount;
}CMDTBL_DIAG_DATA_T;

/*******************************************************************
* Init Request
*******************************************************************/
typedef struct CMDTBL_INIT_DATA_REQ_Ttag
{
  uint32_t ulProtocolType;               /*!< Protocol supported by the current instance of the module. */
  uint32_t ulDpmBitFieldOffset;          /*!< Offset of the slaves/commands diagnostic structure within the DPM. */
  uint8_t  abReserved[16];                /*!< Reserved field. */
}
CMDTBL_INIT_DATA_REQ_T;


typedef struct CMDTBL_INIT_REQ_Ttag
{
  TLR_PACKET_HEADER_T       tHead;
  CMDTBL_INIT_DATA_REQ_T    tData;
}
CMDTBL_INIT_REQ_T;

typedef struct CMDTBL_INIT_CNF_Ttag
{
  TLR_PACKET_HEADER_T       tHead;
}
CMDTBL_INIT_CNF_T;


/*******************************************************************
* Deinit Request
*******************************************************************/
typedef struct CMDTBL_DEINIT_REQ_Ttag
{
  TLR_PACKET_HEADER_T       tHead;
}
CMDTBL_DEINIT_REQ_T;

typedef struct CMDTBL_DEINIT_CNF_Ttag
{
  TLR_PACKET_HEADER_T       tHead;
}
CMDTBL_DEINIT_CNF_T;


/*******************************************************************
* Add Table
*******************************************************************/
typedef CMDTBL_TABLE_T CMDTBL_ADD_TABLE_DATA_REQ_T;

typedef struct CMDTBL_ADD_TABLE_DATA_CNF_Ttag
{
  uint32_t ulTableId;
}
CMDTBL_ADD_TABLE_DATA_CNF_T;


typedef struct CMDTBL_ADD_TABLE_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_ADD_TABLE_DATA_REQ_T       tData;
}
CMDTBL_ADD_TABLE_REQ_T;

typedef struct CMDTBL_ADD_TABLE_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_ADD_TABLE_DATA_CNF_T       tData;
}
CMDTBL_ADD_TABLE_CNF_T;


/*******************************************************************
* Delete Table
*******************************************************************/
typedef struct CMDTBL_DELETE_TABLE_DATA_REQ_Ttag
{
  uint32_t ulTableId;
}
CMDTBL_DELETE_TABLE_DATA_REQ_T;

typedef CMDTBL_DELETE_TABLE_DATA_REQ_T CMDTBL_DELETE_TABLE_DATA_CNF_T;

typedef struct CMDTBL_DELETE_TABLE_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_DELETE_TABLE_DATA_REQ_T    tData;
}
CMDTBL_DELETE_TABLE_REQ_T;

typedef struct CMDTBL_DELETE_TABLE_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_DELETE_TABLE_DATA_CNF_T    tData;
}
CMDTBL_DELETE_TABLE_CNF_T;


/*******************************************************************
* Activate Table
*******************************************************************/
typedef struct CMDTBL_ACTIVATE_TABLE_DATA_REQ_Ttag
{
  uint32_t ulTableId;   /* Table ID returned by the CMDTBL_ADD_TABLE_CNF_T packet
                           or 0 for all tables created into the database */
}
CMDTBL_ACTIVATE_TABLE_DATA_REQ_T;

typedef CMDTBL_ACTIVATE_TABLE_DATA_REQ_T CMDTBL_ACTIVATE_TABLE_DATA_CNF_T;

typedef struct CMDTBL_ACTIVATE_TABLE_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_ACTIVATE_TABLE_DATA_REQ_T  tData;
}
CMDTBL_ACTIVATE_TABLE_REQ_T;

typedef struct CMDTBL_ACTIVATE_TABLE_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_ACTIVATE_TABLE_DATA_CNF_T  tData;
}
CMDTBL_ACTIVATE_TABLE_CNF_T;


/*******************************************************************
* Deactivate Table
*******************************************************************/

typedef CMDTBL_ACTIVATE_TABLE_DATA_REQ_T CMDTBL_DEACTIVATE_TABLE_DATA_REQ_T;
typedef CMDTBL_ACTIVATE_TABLE_DATA_CNF_T CMDTBL_DEACTIVATE_TABLE_DATA_CNF_T;

typedef struct CMDTBL_DEACTIVATE_TABLE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                 tHead;
  CMDTBL_DEACTIVATE_TABLE_DATA_REQ_T  tData;
}
CMDTBL_DEACTIVATE_TABLE_REQ_T;

typedef struct CMDTBL_DEACTIVATE_TABLE_CNF_Ttag
{
  TLR_PACKET_HEADER_T                 tHead;
  CMDTBL_DEACTIVATE_TABLE_DATA_CNF_T  tData;
}
CMDTBL_DEACTIVATE_TABLE_CNF_T;


/*******************************************************************
* Add Command
*******************************************************************/
typedef struct CMDTBL_ADD_COMMAND_DATA_REQ_Ttag
{
  uint32_t          ulTableId;
  CMDTBL_COMMAND_T  tCommand;
}
CMDTBL_ADD_COMMAND_DATA_REQ_T;

typedef struct CMDTBL_ADD_COMMAND_DATA_CNF_Ttag
{
  uint32_t          ulCommandId;
}
CMDTBL_ADD_COMMAND_DATA_CNF_T;


typedef struct CMDTBL_ADD_COMMAND_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_ADD_COMMAND_DATA_REQ_T     tData;
}
CMDTBL_ADD_COMMAND_REQ_T;

typedef struct CMDTBL_ADD_COMMAND_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_ADD_COMMAND_DATA_CNF_T     tData;
}
CMDTBL_ADD_COMMAND_CNF_T;


/*******************************************************************
* Delete Command
*******************************************************************/
typedef struct CMDTBL_DELETE_COMMAND_DATA_REQ_Ttag
{
  uint32_t ulCommandId;
}
CMDTBL_DELETE_COMMAND_DATA_REQ_T;

typedef CMDTBL_DELETE_COMMAND_DATA_REQ_T CMDTBL_DELETE_COMMAND_DATA_CNF_T;

typedef struct CMDTBL_DELETE_COMMAND_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_DELETE_COMMAND_DATA_REQ_T  tData;
}
CMDTBL_DELETE_COMMAND_REQ_T;

typedef struct CMDTBL_DELETE_COMMAND_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_DELETE_COMMAND_DATA_CNF_T  tData;
}
CMDTBL_DELETE_COMMAND_CNF_T;


/*******************************************************************
* Activate Command
*******************************************************************/
typedef struct CMDTBL_ACTIVATE_COMMAND_DATA_REQ_Ttag
{
  uint32_t ulCommandId;
}
CMDTBL_ACTIVATE_COMMAND_DATA_REQ_T;

typedef CMDTBL_ACTIVATE_COMMAND_DATA_REQ_T CMDTBL_ACTIVATE_COMMAND_DATA_CNF_T;

typedef struct CMDTBL_ACTIVATE_COMMAND_REQ_Ttag
{
  TLR_PACKET_HEADER_T                 tHead;
  CMDTBL_ACTIVATE_COMMAND_DATA_REQ_T  tData;
}
CMDTBL_ACTIVATE_COMMAND_REQ_T;

typedef struct CMDTBL_ACTIVATE_COMMAND_CNF_Ttag
{
  TLR_PACKET_HEADER_T                 tHead;
  CMDTBL_ACTIVATE_COMMAND_DATA_CNF_T  tData;
}
CMDTBL_ACTIVATE_COMMAND_CNF_T;


/*******************************************************************
* Deactivate Command
*******************************************************************/
typedef CMDTBL_ACTIVATE_COMMAND_DATA_REQ_T  CMDTBL_DEACTIVATE_COMMAND_DATA_REQ_T;
typedef CMDTBL_ACTIVATE_COMMAND_DATA_CNF_T  CMDTBL_DEACTIVATE_COMMAND_DATA_CNF_T;

typedef struct CMDTBL_DEACTIVATE_COMMAND_REQ_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
  CMDTBL_DEACTIVATE_COMMAND_DATA_REQ_T  tData;
}
CMDTBL_DEACTIVATE_COMMAND_REQ_T;

typedef struct CMDTBL_DEACTIVATE_COMMAND_CNF_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
  CMDTBL_DEACTIVATE_COMMAND_DATA_CNF_T  tData;
}
CMDTBL_DEACTIVATE_COMMAND_CNF_T;


/*******************************************************************
* Trigger Command
*******************************************************************/
typedef struct CMDTBL_TRIGGER_COMMAND_DATA_REQ_Ttag
{
  uint32_t ulCommandId;
}
CMDTBL_TRIGGER_COMMAND_DATA_REQ_T;

typedef CMDTBL_TRIGGER_COMMAND_DATA_REQ_T   CMDTBL_TRIGGER_COMMAND_DATA_CNF_T;


typedef struct CMDTBL_TRIGGER_COMMAND_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_TRIGGER_COMMAND_DATA_REQ_T tData;
}
CMDTBL_TRIGGER_COMMAND_REQ_T;

typedef struct CMDTBL_TRIGGER_COMMAND_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_TRIGGER_COMMAND_DATA_CNF_T tData;
}
CMDTBL_TRIGGER_COMMAND_CNF_T;

/*******************************************************************
* IO Size Command
*******************************************************************/
typedef struct CMDTBL_GET_IO_INFO_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
}
CMDTBL_GET_IO_INFO_REQ_T;

typedef struct CMDTBL_GET_IO_INFO_DATA_CNF_Ttag
{
  uint32_t ulInputByteSize;
  uint32_t ulOutputByteSize;
  uint32_t ulDpmBitFieldPosition;
}
CMDTBL_GET_IO_INFO_DATA_CNF_T;

typedef struct CMDTBL_GET_IO_INFO_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  CMDTBL_GET_IO_INFO_DATA_CNF_T     tData;
}
CMDTBL_GET_IO_INFO_CNF_T;


/*******************************************************************
* Start/Stop Request
*******************************************************************/
typedef struct CMDTBL_START_STOP_DATA_REQ_Ttag
{
  uint32_t       ulStartStopCommand;
}
CMDTBL_START_STOP_DATA_REQ_T;

typedef struct CMDTBL_START_STOP_REQ_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
  CMDTBL_START_STOP_DATA_REQ_T  tData;
}
CMDTBL_START_STOP_REQ_T;

typedef struct CMDTBL_START_STOP_CNF_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
}
CMDTBL_START_STOP_CNF_T;


/* pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(__CMDTBL_PACKET)
#endif


/*************************************************************************************/
#endif /* #ifndef __CMDTBL_PUBLIC_H */
