/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of EtherNet/IP Ethernet Link Object

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2014-01-10  RH            Created
**************************************************************************************/
#ifndef EIP_EN_H
#define EIP_EN_H

  /*#####################################################################################*/


  typedef struct EIP_EN_RSC_Ttag  EIP_EN_RSC_T;

/*
  ************************************************************
  *  Object specific defines
  ************************************************************
  */
  #define EIP_EN_CLASS_NUMBER            0xF6
  #define EIP_EN_REVISION                3
  #define EIP_EN_MAX_INSTANCE            2
  #define EIP_EN_MAX_CLASS_ATTR          7
  #define EIP_EN_MAX_INSTANCE_ATTR       10

  #define EIP_MAC_ADDR_LENGTH             6
  #define EIP_INTF_LABEL_LENGTH           64

  /* attributes of identity object */
  #define EIP_EN_ATTR_1_INTERFACE_SPEED                  1
  #define EIP_EN_ATTR_2_INTERFACE_FLAGS                  2
  #define EIP_EN_ATTR_3_PHYSICAL_ADDRESS                 3
  #define EIP_EN_ATTR_4_INTERFACE_COUNTERS               4
  #define EIP_EN_ATTR_5_MEDIA_COUNTERS                   5
  #define EIP_EN_ATTR_6_INTERFACE_CONTROL                6
  #define EIP_EN_ATTR_7_INTERFACE_TYPE                   7
  #define EIP_EN_ATTR_8_INTERFACE_STATE                  8
  #define EIP_EN_ATTR_9_ADMIN_STATE                      9
  #define EIP_EN_ATTR_10_INTERFACE_LABEL                 10

  #define EIP_EN_ATTR_300_MDIX_CONFIG                    300


  #define EIP_EN_INTF_LSTATUS             0x01
  #define EIP_EN_INTF_FULLDUBLEX          0x02
  #define EIP_EN_INTF_NEGSTATUS_MSK       0x1C
  #define EIP_EN_INTF_NS_AUTONEQ_PROCESS  0x00
  #define EIP_EN_INTF_NS_FAILED1          0x40
  #define EIP_EN_INTF_NS_FAILED2          0x80
  #define EIP_EN_INTF_NS_SUCCESS          0xC0
  #define EIP_EN_INTF_NS_NOTATTEMPTED     0x10

  #define EIP_EN_INTF_MANSETTING          0x20
  #define EIP_EN_INTF_HW_FAULT            0x40

  #define EIP_EN_INTF_TYPE_UNKNOWN        0x00
  #define EIP_EN_INTF_TYPE_INTERNAL       0x01
  #define EIP_EN_INTF_TYPE_TWISTEDPAIR    0x02
  #define EIP_EN_INTF_TYPE_OPTICAL        0x03

  #define EIP_EN_INTF_STATE_UNKNOWN       0x00
  #define EIP_EN_INTF_STATE_ENABLE        0x01
  #define EIP_EN_INTF_STATE_DISABLE       0x02
  #define EIP_EN_INTF_STATE_TEST          0x03

  #define EIP_EN_ADMIN_STATE_ENABLE       0x01
  #define EIP_EN_ADMIN_STATE_DISABLE      0x02

  #define EIP_EN_INTF_MDIX_AUTO           0x01
  #define EIP_EN_INTF_MDIX_MDI            0x02
  #define EIP_EN_INTF_MDIX_MDIX           0x03

  /*#####################################################################################*/

/*
  ************************************************************
  *  Object specific types
  ************************************************************
  */

#pragma pack(1)


  /* Ethernet Link Object - Class Attributes */
  typedef __PACKED_PRE struct  EIP_EN_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;         /* 1 */
    uint16_t  usMaxInstance;      /* 2 */
    uint16_t  usNumInstance;      /* 3 */
    uint16_t  usMaxClassAttr;     /* 6 */
    uint16_t  usMaxInstanceAttr;  /* 7 */
  } __PACKED_POST EIP_EN_CLASS_ATTR_T;


  /*#####################################################################################*/

  typedef __PACKED_PRE struct EIP_EN_INTERFACE_CNT_Ttag
  {
    uint32_t   lInOctets;        /* Number of octets received on the interface    */
    uint32_t   lInUcastPkts;     /* Number of subnetwork-unicast packets
                                    delivered to a higher-layer protocol          */
    uint32_t   lInNUcastPkts;    /* Number of non-unicast packets delivered
                                    to a higher layer protocol                    */
    uint32_t   lInDiscards;      /* Number of inbound packets discarded           */
    uint32_t   lInErrors;        /* Inbound packets that contained errors         */
    uint32_t   lInUnknownProtos; /* Inbound packets discarded due to unknown
                                    or unsupported protocol                       */
    uint32_t   lOutOctets;       /* Number of octets transmitted on the interface */
    uint32_t   lOutUcastPkts;    /* Number of packets transmitted to subnet
                                    unicast address                               */
    uint32_t   lOutNUcastPkts;   /* Number of packets sent to non-unicast
                                    address                                       */
    uint32_t   lOutDiscards;     /* Number of outbound packets discarded          */
    uint32_t   lOutErrors;       /* Number of outbound packets that could not     */
  } __PACKED_POST EIP_EN_INTERFACE_CNT_T;

  /*#####################################################################################*/


  typedef __PACKED_PRE struct EIP_EN_MEDIA_CNT_Ttag
  {
    uint32_t   ulAlignmentErrors;
    uint32_t   ulFcsErrors;
    uint32_t   ulSingleCollisions;
    uint32_t   ulMultipleCollisions;
    uint32_t   ulSqeTestErrors;
    uint32_t   ulDeferredXmission;
    uint32_t   ulLateCollisions;
    uint32_t   ulExcessiveCollisions;
    uint32_t   ulInternalMacXmitErrors;
    uint32_t   ulCarrierSenseErrors;
    uint32_t   ulFrameTooLong;
    uint32_t   ulInternalMacReadErrors;
  } __PACKED_POST EIP_EN_MEDIA_CNT_T;

  /*#####################################################################################*/

  /* Ethernet Link Object - Class Attributes */
  typedef __PACKED_PRE struct EIP_EN_INST_ATTR_Ttag
  {
    #define EIP_EN_SPEED_100      100
    #define EIP_EN_SPEED_10        10
    uint32_t  ulInterfaceSpeed;                            /*  1 */

    #define EIP_EN_FLAGS_LINKUP                 0x00000001
    #define EIP_EN_FLAGS_FULLDUPLEX             0x00000002
    #define EIP_EN_FLAGS_AUTONEG_MASK           0x0000001C /* Bits 2-4 */
    #define EIP_EN_FLAGS_AUTONEG_IN_PROGRESS    0x00000000
    #define EIP_EN_FLAGS_AUTONEG_FAILED         0x00000004
    #define EIP_EN_FLAGS_AUTONEG_DETECTED_SPEED 0x00000008
    #define EIP_EN_FLAGS_AUTONEG_SUCCESSFUL     0x0000000C
    #define EIP_EN_FLAGS_AUTONEG_NOT_ATTEMPTED  0x00000010
    #define EIP_EN_FLAGS_RESET                  0x00000020

    uint32_t               ulInterfaceFlags;                            /*  2 */

    uint8_t                abMacAddr[EIP_MAC_ADDR_LENGTH];              /*  3 */

    #define EIP_EN_CONTROL_AUTONEG              0x00000001
    #define EIP_EN_CONTROL_FULLDUPLEX           0x00000002
    #define EIP_EN_CONTROL_SPEED_MSK            0xFFFF0000
    EIP_EN_INTERFACE_CNT_T tInterfaceCounters;                          /*  4 */
    EIP_EN_MEDIA_CNT_T     tMediaCounters;                              /*  5 */

    uint32_t               ulInterfaceControl;                          /*  6 */
    uint8_t                bInterfaceType;                              /*  7 */
    uint8_t                bInterfaceState;                             /*  8 */
    uint8_t                bAdminState;                                 /*  9 */
    uint8_t                abInterfaceLabel[EIP_INTF_LABEL_LENGTH + 1]; /* 10 */

    uint8_t                bMDIXCfg;                                    /* 300 (vendor specific range) */
  } __PACKED_POST EIP_EN_INST_ATTR_T;


#pragma pack()

  /*#####################################################################################*/

  typedef struct EIP_EN_UPDATE_PARAM_Ttag
  {
    unsigned long   ulInstance;
    EIP_EN_RSC_T*   ptRsc;
  } EIP_EN_UPDATE_PARAM_T;

  /*#####################################################################################*/

  typedef struct EIP_EN_Ttag
  {
    EIP_EN_CLASS_ATTR_T tClass;
    EIP_EN_INST_ATTR_T  atInstance[EIP_EN_MAX_INSTANCE];
  } EIP_EN_T;

  /*#####################################################################################*/

  typedef struct EIP_EN_INST_ATTR_STORED_Ttag
  {
    uint32_t  ulInterfaceControl;                          /*   6 */
    uint8_t   bAdminState;                                 /*   9 */
    uint8_t   bMDIXCfg;                                    /* 300 */
    EIP_EN_INTERFACE_CNT_T tOffsetInterfaceCounters;       /*  4 */
    EIP_EN_MEDIA_CNT_T     tOffsetMediaCounters;           /*  5 */

  } EIP_EN_INST_ATTR_STORED_T;

  /*#####################################################################################*/

  typedef struct EIP_EN_STORED_Ttag
  {
    EIP_EN_INST_ATTR_STORED_T  atInstance[EIP_EN_MAX_INSTANCE];
  } EIP_EN_STORED_T;

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

  typedef struct EIP_EN_INIT_PARAM_Ttag
  {
    #define EIP_ETH_TYPE_DLR       1
    #define EIP_ETH_TYPE_STD_ETH   2
    #define EIP_ETH_TYPE_2PORT_SW  3

    uint8_t bEthType;
    void*   hDrvEth;
    void*   ahPhy[2];

  } EIP_EN_INIT_PARAM_T;

  /** Creates the Ethermet Link object.
   *
   * \param pvRsc [in]  Task Resources
   *
   * \return Description of return value, if any
   */
  uint32_t CipEn_ObjectCreate( void*                pvRsc,
                               EIP_EN_INIT_PARAM_T* ptParam );

#endif /* EIP_EN_H */
