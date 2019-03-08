/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: CmdTable_Configuration.h 5600 2016-04-26 12:19:22Z Alexander.Ivanov $:

Description:
 The header contains the common types definitions.

Changes:

 -----------------------------------------------------------------------------------
 2016-02-10 created
**************************************************************************************/

#ifndef __CMDTBL_CONFIGURATION_H
#define __CMDTBL_CONFIGURATION_H


#include <stdint.h>


typedef enum CMDTBL_PROTOCOL_TYPE_Etag
{
  CMDTBL_PROTOCOL_TYPE_UNDEFINED  = 0,
  CMDTBL_PROTOCOL_TYPE_MODBUS_RTU = 0x11,   /* RCX_PROT_CLASS_MODBUS_RTU */
  CMDTBL_PROTOCOL_TYPE_MODBUS_TCP = 0x12,   /* RCX_PROT_CLASS_OPEN_MODBUS_TCP */
}
CMDTBL_PROTOCOL_TYPE_E;


typedef enum CMDTBL_TRIGGER_TYPE_Etag
{
  CMDTBL_TRIGGER_TYPE_CYCLIC             = 0,   /* cyclicly depending on a configured interval. */
  CMDTBL_TRIGGER_TYPE_ON_CHANGE          = 1,   /* only in case of data change. */
  CMDTBL_TRIGGER_TYPE_ON_CHANGE_NON_ZERO = 2,   /* only in case of data change to a non-zero value */
  CMDTBL_TRIGGER_TYPE_ON_REQUEST         = 3,   /* on external trigger event only.
                                                   Triggered by CMDTBL_TRIGGER_COMMAND_REQ */
}
CMDTBL_TRIGGER_TYPE_E;

typedef enum CMDTBL_TABLE_FLAGS_Etag
{
  CMDTBL_TABLE_FLAGS_INACTIVE_BY_DEFAULT = 1,
}
CMDTBL_TABLE_FLAGS_E;

typedef enum CMDTBL_COMMAND_FLAGS_Etag
{
  CMDTBL_COMMAND_FLAGS_INACTIVE_BY_DEFAULT = 1,
}
CMDTBL_COMMAND_FLAGS_E;


/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(__CMDTBL_PACKET_DATA)
#endif

typedef struct CMDTBL_TABLE_Ttag
{
  uint32_t ulProtocolType;        /*!< Protocol used for all commands within the table. */
  uint32_t ulCycleTime;           /*!< The cycle defines the interval at which the table is executed */
  uint32_t ulInterCommandDelay;   /*!< Timeout inserted between two commands to the same server */
  uint32_t ulInterScanDelay;      /*!< Timeout inserted between last and first commands of a cycle
                                       to the same server */
  uint32_t ulFlags;               /*!< Table flags - CMDTBL_TABLE_FLAGS_E. */
  uint8_t  abReserved[16];
}
CMDTBL_TABLE_T;


typedef struct CMDTBL_COMMAND_Ttag
{
  uint32_t ulDeviceAddr;
  uint32_t ulUnitId;
  uint32_t ulFunctionCode;
  uint32_t ulRegisterWriteAddr;
  uint32_t ulRegisterWriteCount;
  uint32_t ulRegisterReadAddr;
  uint32_t ulRegisterReadCount;
  uint32_t ulDPMSrcOffset;
  uint32_t ulDPMDstOffset;
  uint32_t ulTriggerType;
  uint32_t ulCyclePeriod;
  uint32_t ulFlags;               /*!< Command flags - CMDTBL_COMMAND_FLAGS_E. */
  uint8_t  abReserved[16];
}
CMDTBL_COMMAND_T;

/* pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(__CMDTBL_PACKET_DATA)
#endif


#endif /* #ifndef __CMDTBL_CONFIGURATION_H */
