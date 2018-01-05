/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: PNIO_spec.h 48794 2014-10-22 11:48:47Z Benjamin $:

Description:
 Profinet
 Profinet definitions
**************************************************************************************/
#ifndef __PNIO_SPEC_H
#define __PNIO_SPEC_H


/*************************************************************************************/
/** @name General Definitions of Limits and Sizes
 *
 * The PROFINET IO-specification describes the maximum length of several parameter.
 * @{
 */

#define PNIO_MAX_PORTS                  (2)     /**< maximum number of physical Ethernet links supported */
#define PNIO_LEN_MAC_ADDR               (6)     /**< length of MAC address */

/** @} */


/*************************************************************************************/
/** @name Length Definitions
 *
 * The PROFINET IO-specification describes the maximum length of several parameter.
 * @{
 */

#define PNIO_MIN_NAME_OF_STATION        (1)     /**< minimum length of NameOfStation */
#define PNIO_MAX_NAME_OF_STATION        (240)   /**< maximum length of NameOfStation */
#define PNIO_MIN_TYPE_OF_STATION        (1)     /**< minimum length of TypeOfStation */
#define PNIO_MAX_TYPE_OF_STATION        (240)   /**< maximum length of TypeOfStation */
#define PNIO_MIN_PORT_ID                (8)     /**< minimum length of Port ID */
#define PNIO_MAX_PORT_ID                (14)    /**< maximum length of Port ID */
#define PNIO_MIN_CHASSIS_ID             (1)     /**< minimum length of Chassis ID */
#define PNIO_MAX_CHASSIS_ID             (240)   /**< maximum length of Chassis ID */
#define PNIO_MIN_ALIAS_NAME             (10)    /**< minimum length of AliasName, min. concatenation result: 8+1+1 */
#define PNIO_MAX_ALIAS_NAME             (255)   /**< maximum length of AliasName, max. concatenation result: 14+1+240 */
#define PNIO_MIN_ORDER_ID               (1)     /**< minimum length of Order ID */
#define PNIO_MAX_ORDER_ID               (20)    /**< maximum length of Order ID */
#define PNIO_MIN_SER_NUMBER             (1)     /**< minimum length of Serial number */
#define PNIO_MAX_SER_NUMBER             (16)    /**< maximum length of Serial number */

// NameOfStation : OctetString[1..240], labels concatenated with '.', e.g.: "device-1.machine-1.plant-1.vendor"
// Label         : OctetString[1..63], octets: ['a'..'z', '0'..'9', '-'], leading and trailing '-' not allowed, all lowercase!

// AliasName     : Peer PortID + '.' + Peer ChassisID, e.g.: "port-001.device-1.machine-1.plant-1.vendor"
// PortID either : OctetString[8], "port-xyz", xyz in [001..255], all lowercase!
//        or     : OctetString[14], "port-xyz-abcde", xyz in [001..255], abcde in [00000..65535], all lowercase!
// ChassisID     : OctetString[1..240]

// OctetStrings are not NUL-terminated!

/** @} */


/*************************************************************************************/
/** @name Device Role Definition
 *
 * According to PROFINET IO specification the subsequently defined symbols
 * represent the role of a device.
 * @{
 */
#define PNIO_DEVICE_ROLE_IOD            (0x01)  /**< IO-Device */
#define PNIO_DEVICE_ROLE_IOC            (0x02)  /**< IO-Controller */
#define PNIO_DEVICE_ROLE_IOM            (0x04)  /**< IO-Multidevice */
#define PNIO_DEVICE_ROLE_IOS            (0x08)  /**< IO-Supervisor */

/** @} */


/*************************************************************************************/
/** @name VLAN Priority Definition
 *
 * According to PROFINET IO specification the subsequently defined symbols
 * represent the VLAN priorities.
 * @{
 */

#define PNIO_VLAN_PRIO_RTA_LOW          (5)   /**< Data-RTC-PDU low / UDP-RTC-PDU low */
#define PNIO_VLAN_PRIO_RTA_HIGH         (6)   /**< Data-RTA-PDU high / UDP-RTC-PDU high*/
#define PNIO_VLAN_PRIO_RTC              (6)   /**< Data-RTA-PDU / UDP-RTC-PDU */

/** @} */


/*************************************************************************************/
/** @name Alarm Sequence Counter Definition
 *
 * According to PROFINET IO specification the subsequently defined symbols
 * describes the initial values of sequence counter.
 * @{
 */
#define PNIO_SEQ_COUNT_INIT_CURRENT     (0xFFFF)  /**< current sequence counter */
#define PNIO_SEQ_COUNT_INIT_PREVIOUS    (0xFFFE)  /**< previous sequence counter */

/** sequence counter increase macro */
#define PNIO_SEQ_COUNT_IOAR_INCREASE(uiCnt)           ((((uiCnt) + 1) & 0x7FF) == 0 ? (0) : (((uiCnt) + 1) & 0x7FF))
#define PNIO_SEQ_COUNT_IOAR_DECREASE(uiCnt)           ((((uiCnt) - 1) & 0x7FF) == 0 ? (0) : (((uiCnt) - 1) & 0x7FF))

/* in case of system redundancy the value 0 shall not be used */
#define PNIO_SEQ_COUNT_SYSRED_INCREASE(uiCnt)           ((((uiCnt) + 1) & 0x7FF) == 0 ? (((uiCnt) + 2) & 0x7FF) : (((uiCnt) + 1) & 0x7FF))
#define PNIO_SEQ_COUNT_SYSRED_DECREASE(uiCnt)           ((((uiCnt) - 1) & 0x7FF) == 0 ? (((uiCnt) - 2) & 0x7FF) : (((uiCnt) - 1) & 0x7FF))


/** @} */


/*************************************************************************************/
/** @name RTA related value definitions
 *
 * According to PROFINET IO specification some minimum and maximum values are allowed.
 * @{
 */
#define PNIO_RTA_MIN_DATA_LEN           (200)
#define PNIO_RTA_MAX_DATA_LEN           (1432)
#define PNIO_RTA_MIN_RETRY_VALUE        (3)
#define PNIO_RTA_MAX_RETRY_VALUE        (15)
#define PNIO_RTA_BASE_TIMEOUT_VALUE     (100)

/** @} */


/*************************************************************************************/
/** @name Slot Definition
 *
 * The PROFINET IO-specification describes a set of parameters, which have to be
 * used for Slot.
 * @{
 */

#define PNIO_MAX_SLOT_NUMBER      (0x7FFF)


/** @} */

/*************************************************************************************/
/** @name Sublot Definition
 *
 * The PROFINET IO-specification describes a set of parameters, which have to be
 * used for Subslot.
 * @{
 */
#define PNIO_MIN_SUBSLOT_NUMBER         (1)
#define PNIO_MAX_SUBSLOT_NUMBER         (0x8FFF)
#define PNIO_SUBSTATE_FORMAT_INDICATOR  (0x8000)

/** SubmoduleState AddInfo */
enum PNIO_SUBSTATE_ADDINFO_Etag
{
  PNIO_SUBSTATE_ADDINFO_NONE                  = (0x0000),     /**< none */
  PNIO_SUBSTATE_ADDINFO_TAKEOVER_NOT_ALLOWED  = (0x0001)      /**< Takeover by IOSAR not available */
  /* 0x02 - 0x07 reserved */
};

/** SubmoduleState QualifiedInfo */
enum PNIO_SUBSTATE_QUALIFIEDINFO_Etag
{
  PNIO_SUBSTATE_QUALIFIEDINFO_NONE       = (0x0000),     /**< No QualifiedInfo available */
  PNIO_SUBSTATE_QUALIFIEDINFO_AVAILABLE  = (0x0080)      /**< QualifiedInfo available */
};

/** SubmoduleState IdentInfo */
typedef enum
{
  PNIO_SUBSTATE_IDENTINFO_OK        = (0x0000),               /**< IdentInfo ok */
  PNIO_SUBSTATE_IDENTINFO_SU        = (0x0001),               /**< IdentInfo substitute submodule */
  PNIO_SUBSTATE_IDENTINFO_WR        = (0x0002),               /**< IdentInfo wrong submodule */
  PNIO_SUBSTATE_IDENTINFO_NO        = (0x0003)                /**< IdentInfo no Submodule */
  /* 0x04 - 0x0F reserved */
} PNIO_SUBSTATE_IDENTINFO_E;
/** @} */

typedef enum PNIO_SUBSTATE_ADDINFO_Etag          PNIO_SUBSTATE_ADDINFO_E;       /**< SubmoduleState.AddInfo */
typedef enum PNIO_SUBSTATE_QUALIFIEDINFO_Etag    PNIO_SUBSTATE_QUALIFIEDINFO_E; /**< SubmoduleState.QualifiedInfo */

/*************************************************************************************/
/** @name Link Status Definition
 *
 * .
 * @{
 */
#define PNIO_LINK_STATUS_UP         (1)
#define PNIO_LINK_STATUS_DOWN       (0)

/** @} */

/*************************************************************************************/
/** @name Link Speed Definition
 *
 * .
 * @{
 */
#define PNIO_LINK_SPEED_10         (10)
#define PNIO_LINK_SPEED_100        (100)

/** @} */

/*************************************************************************************/
/** @name Link Speed Definition
 *
 * .
 * @{
 */
#define PNIO_LINK_MODE_HALF         (1)
#define PNIO_LINK_MODE_FULL         (0)

/** @} */

/*************************************************************************************/
/** @name Alarm Type Definition
 *
 * .
 * @{
 */
typedef enum {
  PNIO_ALARM_TYPE_RESERVED  = 0,
  PNIO_ALARM_TYPE_DIAGNOSIS,           /* (0x0001) */
  PNIO_ALARM_TYPE_PROCESS,             /* (0x0002) */
  PNIO_ALARM_TYPE_PULL,                /* (0x0003) */
  PNIO_ALARM_TYPE_PLUG,                /* (0x0004) */
  PNIO_ALARM_TYPE_STATUS,              /* (0x0005) */
  PNIO_ALARM_TYPE_UPDATE,              /* (0x0006) */
  PNIO_ALARM_TYPE_MEDIA_REDUNDANCY,    /* (0x0007)       Media Redundancy */
  PNIO_ALARM_TYPE_SUPERVISOR,          /* (0x0008)       Controlled by supervisor */
  PNIO_ALARM_TYPE_RELEASED,            /* (0x0009)       Released */
  PNIO_ALARM_TYPE_PLG_WRONG_SM,        /* (0x000A)       Plug Wrong Submodule */
  PNIO_ALARM_TYPE_RTN_OF_SM,           /* (0x000B)       Return of Submodule */
  PNIO_ALARM_TYPE_DIAGNOSIS_DIS,       /* (0x000C)       Diagnosis disappears */
  PNIO_ALARM_TYPE_MC_COMM_MISMATCH,    /* (0x000D)       Multicast communication mismatch notification */
  PNIO_ALARM_TYPE_PORT_DATA_CH_N,      /* (0x000E)       Port data change notification */
  PNIO_ALARM_TYPE_SYNC_CH_NOT,         /* (0x000F)       Sync data changed notification */
  PNIO_ALARM_TYPE_ISO_PROBLEM,         /* (0x0010)       Isochronous mode problem notification */
  PNIO_ALARM_TYPE_NETWORK_PRB,         /* (0x0011)       Network component problem notification */
  PNIO_ALARM_TYPE_TIME_CH_N,           /* (0x0012)       Time data changed notification */
  PNIO_ALARM_TYPE_DCP_PROBLEM,         /* (0x0013)       Dynamic Frame Packing problem notification */
  PNIO_ALARM_TYPE_MRPD_PROBLEM,        /* (0x0014)       MediaRedundancywithPlannedDublication problem notification */
  PNIO_ALARM_TYPE_SYSTEM_REDUNDANCY,   /* (0x0015)       System Redundancy */
  PNIO_ALARM_TYPE_UPL_RT_N =              (0x001E),   /* Upload and retrieval notification */
  PNIO_ALARM_TYPE_PULL_MODULE,         /* (0x001F)       Pull module */
  PNIO_ALARM_TYPE_MANUF_SPEC_START,    /* (0x0020) */
  PNIO_ALARM_TYPE_MANUF_SPEC_STOP       = (0x007F),
  PNIO_ALARM_TYPE_RESERVED_PROFILES =     (0x0080)
} PNIO_ALARM_TYPE_E;
/** @} */

/*************************************************************************************/
/** @name Alarmspecifier masks
 *
 * .
 * @{
 */
#define  CHANNELDIAGMASK      ((TLR_UINT16)0x0800)
#define  CHANNELDIAGCOUNT     (0xc)
#define  MANUFACTURERMASK     ((TLR_UINT16)0x1000)
#define  MANUFACTURERCOUNT    (0xd)
#define  SUBMODULEDIAGMASK    ((TLR_UINT16)0x2000)
#define  SUBMODULEDIAGCOUNT   (0xe)
#define  ARDIAGNOSISMASK      ((TLR_UINT16)0x8000)
#define  ARDIAGNOSISCOUNT     (0xf)

/** @} */

/*************************************************************************************/
/** @name DCP signal
 *
 * .
 * @{
 */
#define DCP_SIGNAL_VALUE          ((TLR_UINT16)0x0100)
#define DCP_SIGNAL_FREQUENCY      ((TLR_UINT32)0x00000001)
#define DCP_SIGNAL_DURATION       ((TLR_UINT32)0x00000B90) /* 2960 ms to avoid last very short flash of LED */

/** @} */

#define PNIO_RPC_EPM_LISTEN_PORT    (0x8894)
#define PNIO_RPC_DEVICE_LISTEN_PORT (0xC000)

typedef __PACKED_PRE
struct
{
  /** 00:25, DeviceType */
  TLR_UINT8   abDeviceType[25];
  /** 25:01, Blank */
  TLR_UINT8   bBlank1;
  /** 26:20, OrderId */
  TLR_UINT8   abOrderId[20];
  /** 46:01, Blank */
  TLR_UINT8   bBlank2;
  /** 47:05, HWRevision */
  TLR_UINT8   abHWRevision[5];
  /** 52:01, Blank */
  TLR_UINT8   bBlank3;
  /** 53:01, SWRevisionPrefix */
  TLR_UINT8   bSWRevisionPrefix;
  /** 54:09, SWRevision */
  TLR_UINT8   abSWRevision[9];
  /** 63:01, EndTerm (=0) */
  TLR_UINT8   bEndTerm;
} __PACKED_POST PNIO_ANNOTATION_T;

/*************************************************************************************/
#endif /* #ifndef __PNIO_SPEC_H */
