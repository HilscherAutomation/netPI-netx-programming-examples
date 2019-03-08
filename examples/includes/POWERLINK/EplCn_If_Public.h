/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: EplCn_If_Public.h 3176 2017-07-05 15:26:30Z Ricky $:

Description:
  Powerlink Controlled Node Interface Task public definitions
**************************************************************************************/

#ifndef __EPLCN_IF_PUBLIC_H
#define __EPLCN_IF_PUBLIC_H

/*************************************************************************************/
/* Queue name                                                                        */
/*************************************************************************************/
#define EPLCN_IF_QUEUE_NAME                     "QUE_EPLCN_IF"

/*************************************************************************************/
/* Commands                                                                          */
/*************************************************************************************/
/* Start of packet range. Used to filter commands to be handled by the IF task */
#define EPLCN_IF_COMMAND_RANGE_START                                  0xA200

/* NMT state change indications */
#define EPLCN_IF_NMT_STATE_CHANGE_IND                                 0xA200
#define EPLCN_IF_NMT_STATE_CHANGE_RES                                 0xA201
#define EPLCN_IF_NMT_SET_STATE_REQ                                    0xA202
#define EPLCN_IF_NMT_SET_STATE_CNF                                    0xA203

/* NMT commands */
#define EPLCN_IF_NMT_CMD_ENABLE_RDY_TO_OPERATE_IND                    0xA210
#define EPLCN_IF_NMT_CMD_ENABLE_RDY_TO_OPERATE_RES                    0xA211

/* Status/Error entries and emergency queue */
#define EPLCN_IF_NMT_WRITE_ERROR_ENTRY_REQ                            0xA220
#define EPLCN_IF_NMT_WRITE_ERROR_ENTRY_CNF                            0xA221
#define EPLCN_IF_NMT_NEW_ERROR_ENTRY_IND                              0xA222
#define EPLCN_IF_NMT_NEW_ERROR_ENTRY_RES                              0xA223
#define EPLCN_IF_NMT_WRITE_STATUS_ENTRY_REQ                           0xA224
#define EPLCN_IF_NMT_WRITE_STATUS_ENTRY_CNF                           0xA225
#define EPLCN_IF_NMT_NEW_STATUS_ENTRY_IND                             0xA226
#define EPLCN_IF_NMT_NEW_STATUS_ENTRY_RES                             0xA227
#define EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ                 0xA228
#define EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_CNF                 0xA229

/* Configuration */
#define EPLCN_IF_SET_CONFIG_REQ                                       0xA230
#define EPLCN_IF_SET_CONFIG_CNF                                       0xA231
#define EPLCN_IF_SET_PDO_SIZE_REQ                                     0xA232
#define EPLCN_IF_SET_PDO_SIZE_CNF                                     0xA233
#define EPLCN_IF_SET_NODE_ID_REQ                                      0xA234
#define EPLCN_IF_SET_NODE_ID_CNF                                      0xA235

/* Pragma pack */
#ifdef PRAGMA_PACK_ENABLE
  #pragma PRAGMA_PACK_1(EPLCN_IF_PUBLIC)
#endif

/*************************************************************************************/
/* Packet: EPLCN_IF_NMT_STATE_CHANGE_IND                                             */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_STATE_CHANGE_IND_DATA_Ttag
{
  TLR_UINT8   bCurrentState;  //NMT state as defined in the EPSG (see Epl_Common_Defines.h). Status led has to be handled depending on the current state
  TLR_UINT8   fErrorLedIsOn;  //Error led is indicated explicitly here
} __TLR_PACKED_POST EPLCN_IF_NMT_STATE_CHANGE_IND_DATA_T;

typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_STATE_CHANGE_IND_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
  EPLCN_IF_NMT_STATE_CHANGE_IND_DATA_T  tData;
} __TLR_PACKED_POST EPLCN_IF_NMT_STATE_CHANGE_IND_T;

typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_STATE_CHANGE_RES_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_STATE_CHANGE_RES_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_NMT_SET_STATE_REQ                                                */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_SET_STATE_REQ_DATA_Ttag
{
  TLR_UINT8   bTargetState;  //Targeted NMT state as defined in the EPSG (see Epl_Common_Defines.h).
} __TLR_PACKED_POST EPLCN_IF_NMT_SET_STATE_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_SET_STATE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
  EPLCN_IF_NMT_SET_STATE_REQ_DATA_T     tData;
} __TLR_PACKED_POST EPLCN_IF_NMT_SET_STATE_REQ_T;

typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_SET_STATE_CNF_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_SET_STATE_CNF_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_NMT_CMD_ENABLE_RDY_TO_OPERATE_IND                                */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_CMD_ENABLE_RDY_TO_OPERATE_IND_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_CMD_ENABLE_RDY_TO_OPERATE_IND_T;

typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_CMD_ENABLE_RDY_TO_OPERATE_RES_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_CMD_ENABLE_RDY_TO_OPERATE_RES_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_NMT_WRITE_ERROR_ENTRY_REQ                                        */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_WRITE_ERROR_ENTRY_REQ_DATA_Ttag
{
  /* Error entry type (see EplCn_Defines.h) */
  TLR_UINT16        usEntryType;
  /* Error entry code */
  TLR_UINT16        usErrorCode;
  /* Profile or vendor specific additional error information */
  /* This is specified as UNSIGNED64 in the EPSG. But it is declared as byte field here,
   * in order to simplify encoding/decoding of the information with a neutral endianness */
  TLR_UINT8         abAddInformation[8];
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_ERROR_ENTRY_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_WRITE_ERROR_ENTRY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  EPLCN_IF_NMT_WRITE_ERROR_ENTRY_REQ_DATA_T tData;
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_ERROR_ENTRY_REQ_T;

typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_WRITE_ERROR_ENTRY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_ERROR_ENTRY_CNF_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_NMT_NEW_ERROR_ENTRY_IND                                          */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_NEW_ERROR_ENTRY_IND_DATA_Ttag
{
  /* Error entry type (see EplCn_Defines.h) */
  TLR_UINT16        usEntryType;
  /* Error entry code */
  TLR_UINT16        usErrorCode;
  /* Profile or vendor specific additional error information */
  /* This is specified as UNSIGNED64 in the EPSG. But it is declared as byte field here,
   * in order to simplify encoding/decoding of the information with a neutral endianness */
  TLR_UINT8         abAddInformation[8];
} __TLR_PACKED_POST EPLCN_IF_NMT_NEW_ERROR_ENTRY_IND_DATA_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_NEW_ERROR_ENTRY_IND_Ttag
{
  TLR_PACKET_HEADER_T                     tHead;
  EPLCN_IF_NMT_NEW_ERROR_ENTRY_IND_DATA_T tData;
} __TLR_PACKED_POST EPLCN_IF_NMT_NEW_ERROR_ENTRY_IND_T;

typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_NEW_ERROR_ENTRY_RES_Ttag
{
  TLR_PACKET_HEADER_T                     tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_NEW_ERROR_ENTRY_RES_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_NMT_WRITE_STATUS_ENTRY_REQ                                       */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_WRITE_STATUS_ENTRY_REQ_DATA_Ttag
{
  /* Status Entry Number */
  TLR_UINT16        usStatusEntryNumber;
  /* Error entry type (see EplCn_Defines.h) */
  TLR_UINT16        usEntryType;
  /* Error entry code */
  TLR_UINT16        usErrorCode;
  /* Profile or vendor specific additional error information */
  /* This is specified as UNSIGNED64 in the EPSG. But it is declared as byte field here,
   * in order to simplify encoding/decoding of the information with a neutral endianness */
  TLR_UINT8         abAddInformation[8];
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_STATUS_ENTRY_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_WRITE_STATUS_ENTRY_REQ_Ttag
{
  TLR_PACKET_HEADER_T                         tHead;
  EPLCN_IF_NMT_WRITE_STATUS_ENTRY_REQ_DATA_T  tData;
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_STATUS_ENTRY_REQ_T;

typedef __TLR_PACKED_PRE struct  EPLCN_IF_NMT_WRITE_STATUS_ENTRY_CNF_Ttag
{
  TLR_PACKET_HEADER_T                         tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_STATUS_ENTRY_CNF_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_NMT_NEW_STATUS_ENTRY_IND                                         */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_NEW_STATUS_ENTRY_IND_DATA_Ttag
{
  /* Status Entry Number */
  TLR_UINT16        usStatusEntryNumber;
  /* Error entry type (see EplCn_Defines.h) */
  TLR_UINT16        usEntryType;
  /* Error entry code */
  TLR_UINT16        usErrorCode;
  /* Profile or vendor specific additional error information */
  /* This is specified as UNSIGNED64 in the EPSG. But it is declared as byte field here,
   * in order to simplify encoding/decoding of the information with a neutral endianness */
  TLR_UINT8         abAddInformation[8];
} __TLR_PACKED_POST EPLCN_IF_NMT_NEW_STATUS_ENTRY_IND_DATA_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_NEW_STATUS_ENTRY_IND_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  EPLCN_IF_NMT_NEW_STATUS_ENTRY_IND_DATA_T  tData;
} __TLR_PACKED_POST EPLCN_IF_NMT_NEW_STATUS_ENTRY_IND_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_NEW_STATUS_ENTRY_RES_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_NEW_STATUS_ENTRY_RES_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ                             */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ_DATA_ENTRY_Ttag
{
  /* Bit number */
  TLR_UINT8                       bBitNumber;
  /* Bit value */
  TLR_BOOLEAN8                    fBitValue;
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ_DATA_ENTRY_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ_DATA_Ttag
{
  /* Only the first bit entry is defined here. Other entries may follow. The Stack recognizes
   * the number of the entries by checking the value of ulLen in the packet head */
  EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ_DATA_ENTRY_T  atEntry[1];
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ_Ttag
{
  TLR_PACKET_HEADER_T                                   tHead;
  EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ_DATA_T  tData;
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_REQ_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_CNF_Ttag
{
  TLR_PACKET_HEADER_T                                   tHead;
} __TLR_PACKED_POST EPLCN_IF_NMT_WRITE_STATIC_ERROR_BIT_FIELD_CNF_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_SET_CONFIG_REQ                                                   */
/*************************************************************************************/
/* System flags */
#define MSK_EPLCN_IF_CFG_SYSTEM_FLAGS_APP_CONTROLLED                        0x00000001

/* Stack configuration flags */
#define MSK_EPLCN_IF_CFG_STACK_CFG_FLAGS_NMT_TRIGGERED_BY_APP               0x00000001
#define MSK_EPLCN_IF_CFG_STACK_CFG_FLAGS_DISABLE_HOST_TRIGGERED_PREQ_XCHG   0x00000002  //Only for LFW application
#define MSK_EPLCN_IF_CFG_STACK_CFG_FLAGS_USE_CUSTOM_PDO_OBJ                 0x00000004
#define MSK_EPLCN_IF_CFG_STACK_CFG_FLAGS_DISABLE_PDO_MAP_VERS_CHECK         0x00000008
#define MSK_EPLCN_IF_CFG_STACK_CFG_FLAGS_USE_APP_READY_FOR_PRES_RD_FLAG     0x00000010  //Only for LFW application

/* Custom threshold for loss of frames detection */
#define MSK_EPLCN_IF_CFG_USE_CUSTOM_TH_LOSS_SOC_THRESHOLD                   0x00000001
#define MSK_EPLCN_IF_CFG_USE_CUSTOM_TH_LOSS_PREQ_THRESHOLD                  0x00000002
#define MSK_EPLCN_IF_CFG_USE_CUSTOM_TH_LOSS_SOA_THRESHOLD                   0x00000004
#define MSK_EPLCN_IF_CFG_USE_CUSTOM_TH_COLLISION_THRESHOLD                  0x00000008
#define MSK_EPLCN_IF_CFG_USE_CUSTOM_TH_CRC_ERROR_THRESHOLD                  0x00000010
#define MSK_EPLCN_IF_CFG_USE_CUSTOM_TH_SOC_JITTER_THRESHOLD                 0x00000020

typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_CONFIG_REQ_DATA_Ttag
{
  /** Only the bit MSK_EPLCN_IF_CFG_SYSTEM_FLAGS_APP_CONTROLLED is used */
  TLR_UINT32      ulSystemFlags;
  /** DPM watchdog time in millisecs */
  TLR_UINT32      ulWatchdogTime;

  /** Stack configuration flags (see EPLCN_IF_CFG_STACK_CFG_FLAGS_*) */
  TLR_UINT32      ulStackCfgFlags;

  /** Vendor Id */
  TLR_UINT32      ulVendorId;
  /** Product code */
  TLR_UINT32      ulProductCode;
  /** Revision number */
  TLR_UINT32      ulRevisionNumber;
  /** Serial number (0 will use default serial number from Sec Mem or Flash Device Label if available) */
  TLR_UINT32      ulSerialNumber;
  /** Cycle Length configuration (us) */
  TLR_UINT32      ulCycleLength;
  /** Device type */
  TLR_UINT32      ulDeviceType;

  /* Powerlink device feature flags */
  TLR_UINT32      ulFeatureFlags;

  /** Startup Poll Request data size (range 0 to 1490) */
  TLR_UINT16      usPReqDataSize;
  /** Startup Poll Response data size (range 0 to 1490) */
  TLR_UINT16      usPResDataSize;
  /** PReq Mapping Version */
  TLR_UINT8       bPReqMappingVersion;
  /** PRes Mapping Version */
  TLR_UINT8       bPResMappingVersion;
  /** Max supported PReq data size (range 0 to 1490).
   * This should be equal or bigger than usPReqDataSize */
  TLR_UINT16      usMaxPReqDataSize;
  /** Max supported PRes data size (range 0 to 1490).
   * This should be equal or bigger than usPResDataSize */
  TLR_UINT16      usMaxPResDataSize;

  /** EPL node id (range 1 to 239) */
  TLR_UINT8       bNodeId;
  /** IP Gateway (if set to 0: default address is configured 192.168.100.254) */
  TLR_UINT32      ulGatewayAddress;
  /** EPL node DNS Hostname (if abNodeName[0] is set to 0, the stack configures the Hostname with the format <nodeId>-<vendorId>) */
  TLR_UINT8       abNodeName[32];

  /** configured status entries (range: 0 .. 13) */
  TLR_UINT8       bNumberOfStatusEntries;

  /** if the bit MSK_EPLCN_IF_CFG_USE_CUSTOM_TH_* is set, the value of ulThreshold* is used.
   * Otherwise the thresholds are configured with their default values */
  TLR_UINT8       bUseCustomThreshold;
  /** LossSoC Threshold (disabled if set to 0) */
  TLR_UINT32      ulThresholdLossSoC;
  /** LossPReq Threshold (disabled if set to 0) */
  TLR_UINT32      ulThresholdLossPReq;
  /** LossSoA Threshold  (disabled if set to 0) */
  TLR_UINT32      ulThresholdLossSoA;
  /** Collision Threshold (disabled if set to 0) */
  TLR_UINT32      ulThresholdCollision;
  /** CrcError Threshold (disabled if set to 0) */
  TLR_UINT32      ulThresholdCrcError;

  /** Minimum cycle length supported by the device (us).
   * Internal defined values:
   * -- netX100/netX500: 200us
   * -- netX51/52: 200us
   * If the parameter is set to 0, it will be ignored and the stack will be configured with the internal defined minimum cycle length */
  TLR_UINT32      ulMinCycleLength;

  /** if the bit MSK_EPLCN_IF_CFG_USE_CUSTOM_TH_* is set, the value of ulThreshold* is used.
   * Otherwise the thresholds are configured with their default values */
  TLR_UINT32      ulThresholdSoCJitter;

  /** Reserved (for future purpose). Set to zero */
  TLR_UINT32       aulReserved[8];
} __TLR_PACKED_POST EPLCN_IF_SET_CONFIG_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_CONFIG_REQ_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
  EPLCN_IF_SET_CONFIG_REQ_DATA_T  tData;
} __TLR_PACKED_POST EPLCN_IF_SET_CONFIG_REQ_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_CONFIG_CNF_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
} __TLR_PACKED_POST EPLCN_IF_SET_CONFIG_CNF_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_SET_PDO_SIZE_REQ                                                 */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_PDO_SIZE_REQ_DATA_Ttag
{
  /** Poll Request data size (range 0 to 1490) */
  TLR_UINT16      usPReqDataSize;
  /** Poll Response data size (range 0 to 1490) */
  TLR_UINT16      usPResDataSize;
  /** PReq Mapping Version */
  TLR_UINT8       bPReqMappingVersion;
  /** PRes Mapping Version */
  TLR_UINT8       bPResMappingVersion;
} __TLR_PACKED_POST EPLCN_IF_SET_PDO_SIZE_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_PDO_SIZE_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  EPLCN_IF_SET_PDO_SIZE_REQ_DATA_T  tData;
} __TLR_PACKED_POST EPLCN_IF_SET_PDO_SIZE_REQ_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_PDO_SIZE_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
} __TLR_PACKED_POST EPLCN_IF_SET_PDO_SIZE_CNF_T;

/*************************************************************************************/
/* Packet: EPLCN_IF_SET_NODE_ID_REQ                                                  */
/*************************************************************************************/
typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_NODE_ID_REQ_DATA_Ttag
{
  /** NodeId. The new value will be activated while in NMT state EPL_NMT_GS_RESET_CONFIGURATION */
  TLR_UINT8   bNodeId;
} __TLR_PACKED_POST EPLCN_IF_SET_NODE_ID_REQ_DATA_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_NODE_ID_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  EPLCN_IF_SET_NODE_ID_REQ_DATA_T   tData;
} __TLR_PACKED_POST EPLCN_IF_SET_NODE_ID_REQ_T;

typedef __TLR_PACKED_PRE struct EPLCN_IF_SET_NODE_ID_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
} __TLR_PACKED_POST EPLCN_IF_SET_NODE_ID_CNF_T;

/*************************************************************************************/
/* Pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
  #pragma PRAGMA_UNPACK_1(EPLCN_IF_PUBLIC)
#endif

#endif /* __EPLCN_IF_PUBLIC_H */
/*************************************************************************************/
/*-----------------------------------------------------------------------------------*/
/*------------------- EOF -----------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/
/*************************************************************************************/
