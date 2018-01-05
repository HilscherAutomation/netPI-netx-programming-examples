/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: Eip_SNMP.c 51163 2015-01-29 10:39:41Z kai $:

Description:
  EIP - Time Sync

**************************************************************************************/

#ifndef CIP_TIMESYNC_H
#define CIP_TIMESYNC_H

#include "Ptp_Public.h"
#include "Ptp_Init.h"

  /*#####################################################################################*/


  typedef struct CIP_TIMESYNC_RSC_Ttag  CIP_TIMESYNC_RSC_T;

/*
  ************************************************************
  *  Object specific defines
  ************************************************************
  */

  #define CIP_TIMESYNC_CLASS_NUMBER                         0x43
  #define CIP_TIMESYNC_REVISION                                3
  #define CIP_TIMESYNC_MAX_INSTANCE                            1
  #define CIP_TIMESYNC_MAX_CLASS_ATTR                          7
  #define CIP_TIMESYNC_MAX_INSTANCE_ATTR                      28


  /* attributes of identity object */
  #define CIP_TIMESYNC_ATTR_1_PTP_ENABLE                       1
  #define CIP_TIMESYNC_ATTR_2_IS_SYNCHONIZED                   2
  #define CIP_TIMESYNC_ATTR_3_SYSTEM_TIME_MICROSECONDS         3
  #define CIP_TIMESYNC_ATTR_4_SYSTEM_TIME_NANOSECONDS          4
  #define CIP_TIMESYNC_ATTR_5_OFFSET_FROM_MASTER               5
  #define CIP_TIMESYNC_ATTR_6_MAX_OFFSET_FROM_MASTER           6
  #define CIP_TIMESYNC_ATTR_7_MEAN_PATH_DELAY_TO_MASTER        7
  #define CIP_TIMESYNC_ATTR_8_GRAND_MASTER_CLOCK_INFO          8
  #define CIP_TIMESYNC_ATTR_9_PARENT_CLOCK_INFO                9
  #define CIP_TIMESYNC_ATTR_10_LOCAL_CLOCK_INFO               10
  #define CIP_TIMESYNC_ATTR_11_NUMBER_OF_PORTS                11
  #define CIP_TIMESYNC_ATTR_12_PORT_STATE_INFO                12
  #define CIP_TIMESYNC_ATTR_13_PORT_ENABLE_CFG                13
  #define CIP_TIMESYNC_ATTR_14_PORT_LOG_ANNOUNCE_INTERVAL_CFG 14
  #define CIP_TIMESYNC_ATTR_15_PORT_LOG_SYNC_INTERVAL_CFG     15
  #define CIP_TIMESYNC_ATTR_16_PRIORITY_1                     16
  #define CIP_TIMESYNC_ATTR_17_PRIORITY_2                     17
  #define CIP_TIMESYNC_ATTR_18_DOMAIN_NUMBER                  18
  #define CIP_TIMESYNC_ATTR_19_CLOCK_TYPE                     19
  #define CIP_TIMESYNC_ATTR_20_MANUFACTURE_IDENTITY           20
  #define CIP_TIMESYNC_ATTR_21_PRODUCT_DESCRIPTION            21
  #define CIP_TIMESYNC_ATTR_22_REVISION_DATA                  22
  #define CIP_TIMESYNC_ATTR_23_USER_DESCRIPTION               23
  #define CIP_TIMESYNC_ATTR_24_PORT_PROFILE_IDENTITY_INFO     24
  #define CIP_TIMESYNC_ATTR_25_PORT_PHYSICAL_ADDRESS_INFO     25
  #define CIP_TIMESYNC_ATTR_26_PORT_PROTOCOL_ADDRESS_INFO     26
  #define CIP_TIMESYNC_ATTR_27_STEPS_REMOVED                  27
  #define CIP_TIMESYNC_ATTR_28_SYSTEM_TIME_AND_OFFSET         28

  #define CIP_TIMESYNC_ATTR_300_SYNC_PARAMETER               300

  /* CIP Sync PTP Profile Identifier */
  #define CIP_TIMESYNC_PROFILE_IDENTIFIER_0      0x00
  #define CIP_TIMESYNC_PROFILE_IDENTIFIER_1      0x21
  #define CIP_TIMESYNC_PROFILE_IDENTIFIER_2      0x6C
  #define CIP_TIMESYNC_PROFILE_IDENTIFIER_3      0x00
  #define CIP_TIMESYNC_PROFILE_IDENTIFIER_4      0x01
  #define CIP_TIMESYNC_PROFILE_IDENTIFIER_5      0x00
  #define CIP_TIMESYNC_PROFILE_IDENTIFIER_6      0x00
  #define CIP_TIMESYNC_PROFILE_IDENTIFIER_7      0x00


  #define CIP_TIMESYNC_NUM_OF_PORTS                 1
  /*#####################################################################################*/

/*
  ************************************************************
  *  Object specific types
  ************************************************************
  */

  typedef enum TIMESYNC_ATTR1_PTP_ENABLE_Etag
  {
    TIMESYNC_ATTR1_PTP_ENABLE_DISABLED = 0,
    TIMESYNC_ATTR1_PTP_ENABLE_ENABLED  = 1,
  } TIMESYNC_ATTR1_PTP_ENABLE_E;

  typedef enum TIMESYNC_ATTR2_IS_SYNCHONIZED_Etag
  {
    TIMESYNC_ATTR2_IS_SYNCHONIZED_NOT_SYNCHRONIZED = 0,
    TIMESYNC_ATTR2_IS_SYNCHONIZED_SYNCHRONIZED     = 1,
  } TIMESYNC_ATTR2_IS_SYNCHONIZED_E;


  typedef enum TIMESYNC_ATTR13_PORT_ENABLE_Etag
  {
    TIMESYNC_ATTR13_PORT_ENABLE_DISABLED = 0,
    TIMESYNC_ATTR13_PORT_ENABLE_ENABLED  = 1,
  } TIMESYNC_ATTR13_PORT_ENABLE_E;


#pragma pack(1)

  /* Time Sync Object - Class Attributes */
  typedef __PACKED_PRE struct  CIP_TIMESYNC_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;         /* 1 */
    uint16_t  usMaxInstance;      /* 2 */
    uint16_t  usNumInstance;      /* 3 */
    uint16_t  usMaxClassAttr;     /* 6 */
    uint16_t  usMaxInstanceAttr;  /* 7 */
  } __PACKED_POST CIP_TIMESYNC_CLASS_ATTR_T;

  /*#####################################################################################*/

  /* Time Sync Object - Class Attributes */
  typedef __PACKED_PRE struct CIP_TIMESYNC_INST_ATTR_Ttag
  {
    uint8_t    bPTPEnable;                            /* Attribute 1  */ /* Use TIMESYNC_ATTR1_PTP_ENABLE_E     */
    uint8_t    fIsSynchronized;                       /* Attribute 2  */ /* Use TIMESYNC_ATTR2_IS_SYNCHONIZED_E */
    uint64_t   ullSystemTimeMicroseconds;             /* Attribute 3  */
    uint64_t   ullSystemTimeNanoseconds;              /* Attribute 4  */
    int64_t    llOffsetFromMaster;                    /* Attribute 5  */
    uint64_t   ullMaxOffsetFromMaster;                /* Attribute 6  */
    int64_t    ulMeanPathDelayToMaster;               /* Attribute 7  */

    /**************************/
    struct
    {
      uint8_t  abClockIdentity[8];
      uint16_t usClockClass;
      uint16_t usTimeAccuracy;
      uint16_t usOffsetScaledLogVariance;
      uint16_t usCurrentUtcOffset;
      uint16_t usTimePropertyFlags;
      uint16_t usTimeSource;
      uint16_t usPriority1;
      uint16_t usPriority2;
    } tGrandMasterClockInfo;                          /* Attribute 8  */

    /**************************/
    struct
    {
      uint8_t  abClockIdentity[8];
      uint16_t usPortNumber;
      uint16_t usObservedOffsetScaledLogVariance;
      uint32_t ulObservedPhaseChangeRate;
    } tParentClockInfo;                               /* Attribute 9  */
    /**************************/
    struct
    {
      uint8_t  abClockIdentity[8];
      uint16_t usClockClass;
      uint16_t usTimeAccuracy;
      uint16_t usOffsetScaledLogVatiance;
      uint16_t usCurrentUtcOffset;
      uint16_t usTimePropertyFlags;
      uint16_t usTimeSource;
    } tLocalClockInfo;                                /* Attribute 10 */

    uint16_t usNumberOfPorts;                         /* Attribute 11 */

    /**************************/
    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      struct
      {
        uint16_t usPortNumber;
        uint16_t usPortState;
      } tPortState[CIP_TIMESYNC_NUM_OF_PORTS];

    } __PACKED_POST tPortStateInfo;                   /* Attribute 12 */

    /**************************/

    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      struct
      {
        uint16_t usPortNumber;
        uint16_t usPortEnable;      /* Use TIMESYNC_ATTR13_PORT_ENABLE_E */
      } tPortEnable[CIP_TIMESYNC_NUM_OF_PORTS];

    } __PACKED_POST tPortEnableConfig;                /* Attribute 13 */

    /**************************/
    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      struct
      {
        uint16_t usPortNumber;
        uint16_t usPortLogAnnounceInterval;
      } tPortLogAnnounceInterval[CIP_TIMESYNC_NUM_OF_PORTS];
    }__PACKED_POST tPortLogAnnounceIntervalCfg;       /* Attribute 14 */

    /**************************/
    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      struct
      {
        uint16_t usPortNumber;
        int16_t  sPortLogSyncInterval;
      } tPortLogSyncInterval[CIP_TIMESYNC_NUM_OF_PORTS];

    } __PACKED_POST tPortLogSyncIntervalCfg;          /* Attribute 15 */

    uint8_t  bPriotity1;                              /* Attribute 16 (optional --> not implemented) */
    uint8_t  bPriotity2;                              /* Attribute 17 (optional --> not implemented) */
    uint8_t  bDomainNumber;                           /* Attribute 18 */
    uint16_t usClockType;                             /* Attribute 19 */
    uint8_t  abManufactureIdentity[4];                /* Attribute 20 */

    /**************************/
    struct
    {
      uint32_t ulSize;
      uint8_t  abDescription[64];
    } tProductDescription;                            /* Attribute 21 */

    /**************************/
    struct
    {
      uint32_t ulSize;
      uint8_t  abRevision[32];
    } tRevisionData;                                  /* Attribute 22 */

    /**************************/
    struct
    {
      uint32_t ulSize;
      uint32_t abDescription[128];
    } tUserDescription;                               /* Attribute 23 */

    /**************************/
    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      __PACKED_PRE struct
      {
        uint16_t usPortNumber;
        uint8_t  abPortProfileIdentity[8];
      } __PACKED_POST tPortProfileIdentity[CIP_TIMESYNC_NUM_OF_PORTS];
    } __PACKED_POST tPortProfileIdentityInfo;         /* Attribute 24 */

    /**************************/
    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      struct
      {
        uint16_t usPortNumber;
        uint8_t  abPhysicalProtocol[16];
        uint16_t usSizeOfAddress;
        uint8_t  abPortPhysicalAddress[16];
      } tPortPhysicalAddress[CIP_TIMESYNC_NUM_OF_PORTS];

    } __PACKED_POST tPortPhysicalAddressInfo;         /* Attribute 25 */

    /**************************/
    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      __PACKED_PRE struct
      {
        uint16_t usPortNumber;
        uint16_t usNetworkProtocol;
        uint16_t usSizeOfAddress;
        uint8_t  abPortProtocolAddress[16];
      } __PACKED_POST tPortProtocolAddress[CIP_TIMESYNC_NUM_OF_PORTS];
    } __PACKED_POST tPortProtocolAddressInfo;         /* Attribute 26 */

    uint16_t usStepsRemoved;                          /* Attribute 27 */

    /**************************/
    struct
    {
      int64_t llSystemTime;
      int64_t llSystemOffset;
    } tSystemTimeAndOffset;                           /* Attribute 28 */
    /**************************/

    PTP_SYNC_PARAMETER_T  tSyncParameter;             /* Attribute 300 */

    /**************************/

  } __PACKED_POST CIP_TIMESYNC_INST_ATTR_T;


#pragma pack()

  /*#####################################################################################*/

  typedef struct CIP_TIMESYNC_UPDATE_PARAM_Ttag
  {
    uint32_t            ulInstance;
    CIP_TIMESYNC_RSC_T* ptRsc;
  } CIP_TIMESYNC_UPDATE_PARAM_T;

  /*#####################################################################################*/

  typedef struct CIP_TIMESYNC_Ttag
  {
    CIP_TIMESYNC_CLASS_ATTR_T tClass;
    CIP_TIMESYNC_INST_ATTR_T  atInstance[CIP_TIMESYNC_MAX_INSTANCE];
  } CIP_TIMESYNC_T;

  /*#####################################################################################*/

  typedef struct CIP_TIMESYNC_INST_ATTR_STORED_Ttag
  {
    uint8_t    bPTPEnable;                             /* Attribute 1  */ /* Use TIMESYNC_ATTR1_PTP_ENABLE_E     */

    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      struct
      {
        uint16_t usPortNumber;
        uint16_t usPortEnable;
      } tPortEnable[CIP_TIMESYNC_NUM_OF_PORTS];

    } __PACKED_POST tPortEnableConfig;                /* Attribute 13 */

    /**************************/
    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      struct
      {
        uint16_t usPortNumber;
        uint16_t usPortLogAnnounceInterval;
      } tPortLogAnnounceInterval[CIP_TIMESYNC_NUM_OF_PORTS];
    }__PACKED_POST tPortLogAnnounceIntervalCfg;       /* Attribute 14 */

    /**************************/
    __PACKED_PRE struct
    {
      uint16_t usNumberOfPorts;
      struct
      {
        uint16_t usPortNumber;
        int16_t  sPortLogSyncInterval;
      } tPortLogSyncInterval[CIP_TIMESYNC_NUM_OF_PORTS];

    } __PACKED_POST tPortLogSyncIntervalCfg;            /* Attribute 15 */

    uint8_t  bPriotity1;                                /* Attribute 16 (optional --> not implemented) */
    uint8_t  bPriotity2;                                /* Attribute 17 (optional --> not implemented) */
    uint8_t  bDomainNumber;                             /* Attribute 18 */

  } CIP_TIMESYNC_INST_ATTR_STORED_T;

  /*#####################################################################################*/

  typedef struct CIP_TIMESYNC_STORED_Ttag
  {
    CIP_TIMESYNC_INST_ATTR_STORED_T  atInstance[CIP_TIMESYNC_MAX_INSTANCE];
  } CIP_TIMESYNC_STORED_T;

  /*#####################################################################################*/


  /*
  ****************************************************************************
  *  Object specific macros
  ****************************************************************************
  */


  /*#####################################################################################*/

  /*
  ************************************************************
  *  Task Function Prototypes
  ************************************************************
  */

  typedef struct CIP_TIMESYNC_INIT_PARAM_Ttag
  {
    PTP_STARTUP_T        tPtpStartup;

  } CIP_TIMESYNC_INIT_PARAM_T;

  /** Creates the Time Sync object.
   *
   * \param pvRsc [in]  Task Resources
   *
   * \return Description of return value, if any
   */
  uint32_t CipTimeSync_ObjectCreate( void*                      pvRsc,
                                     CIP_TIMESYNC_INIT_PARAM_T* ptParam );

#endif /* CIP_TIMESYNC_H */
