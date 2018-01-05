/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of EtherNet/IP TCP/IP Object

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2014-01-10  RH            Created
**************************************************************************************/
#ifndef EIP_TCP_H
#define EIP_TCP_H

  /*#####################################################################################*/


  /*
  ************************************************************
  *  Object specific defines
  ************************************************************
  */

  #define EIP_TCP_CLASS_NUMBER            0xF5
  #define EIP_TCP_REVISION                4
  #define EIP_TCP_MAX_INSTANCE            1
  #define EIP_TCP_MAX_CLASS_ATTR          7
  #define EIP_TCP_MAX_INSTANCE_ATTR       13

  #define EIP_TCP_LINK_PATH_LENGTH        4
  #define EIP_TCP_MAX_HOSTNAME_LENGTH     64
  #define EIP_TCP_MAX_DOMAINNAME_LENGTH   48


  /* attributes of identity object */
  #define EIP_TCP_ATTR_1_STATUS                  1
  #define EIP_TCP_ATTR_2_CFG_CAPABILITY          2
  #define EIP_TCP_ATTR_3_CFG_CONTROL             3
  #define EIP_TCP_ATTR_4_PHY_LINK_OBJ            4
  #define EIP_TCP_ATTR_5_INTERFACE_CFG           5
  #define EIP_TCP_ATTR_6_HOST_NAME               6
  #define EIP_TCP_ATTR_7_SAFETY_NETWORK_NUMBER   7
  #define EIP_TCP_ATTR_8_TTL_VALUE               8
  #define EIP_TCP_ATTR_9_MCAST_CFG               9
  #define EIP_TCP_ATTR_10_SELECT_ACD             10
  #define EIP_TCP_ATTR_11_LAST_CONFLICT_DETECTED 11
  #define EIP_TCP_ATTR_12_EIP_QUICK_CONNECT      12
  #define EIP_TCP_ATTR_13_ENCAP_TIMEOUT          13

  /* Configuration Capility Flags */
  #define EIP_TCP_CAP_BOOTP                      0x01
  #define EIP_TCP_CAP_DNS                        0x02
  #define EIP_TCP_CAP_DHCP                       0x04
  #define EIP_TCP_CAP_DHCPDNS                    0x08
  #define EIP_TCP_CAP_CNFSET                     0x10
  #define EIP_TCP_CAP_HW_CONFIG                  0x20
  #define EIP_TCP_CAP_CFG_CHANGE_REQUIRES_RESET  0x40
  #define EIP_TCP_CAP_ACD_CAPABLE                0x80

  /* Configuration Control Flags */
  #define EIP_TCP_CNTRL_START_MSK                0x0F
  #define EIP_TCP_CNTRL_INTERN                   0x00
  #define EIP_TCP_CNTRL_BOOTP                    0x01
  #define EIP_TCP_CNTRL_DHCP                     0x02

  #define EIP_TCP_CNTRL_DNS                      0x10

  #define EIP_TCP_STATUS_CONFIG_MASK             0x0000000F
  #define EIP_TCP_STATUS_CONFIG_NOT_CONFIGURED   0x00000000 /* The Interface Configuration attribute has not been configured. */
  #define EIP_TCP_STATUS_CONFIG_BOOTP_DHCP_NV    0x00000001 /* The Interface Configuration attribute contains
                                                               configuration obtained from BOOTP, DHCP or non- volatile storage */
  #define EIP_TCP_STATUS_CONFIG_HARDWARE         0x00000002 /* The IP address member of the Interface Configuration attribute
                                                               contains configuration, obtained from hardware settings
                                                               (e.g.: pushwheel, thumbwheel, etc.) */

  #define EIP_TCP_STATUS_MCAST_CFG_PENDING       0x00000010
  #define EIP_TCP_STATUS_INTERFACE_CFG_PENDING   0x00000020
  #define EIP_TCP_STATUS_ACD_STATUS              0x00000040
  #define EIP_TCP_STATUS_ACD_FAULT               0x00000080

  #define EIP_TCP_ENCAP_TIMEOUT_DISABLE          0
  #define EIP_TCP_ENCAP_TIMEOUT_MIN              1
  #define EIP_TCP_ENCAP_TIMEOUT_MAX              3600
  #define EIP_TCP_ENCAP_TIMEOUT_DEFAULT          120

  #define CIPHIL_TCP_CMD_GET_NXT_MULTICAST       0xF501

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific types
  ************************************************************
  */

  #pragma pack(1)

  typedef __PACKED_PRE struct __PACKED_POST EIP_TCP_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;
    uint16_t  usMaxInstance;
    uint16_t  usNumInstance;
    uint16_t  usMaxClassAttr;
    uint16_t  usMaxInstanceAttr;
  } EIP_TCP_CLASS_ATTR_T;

  /*#####################################################################################*/

  typedef __PACKED_PRE struct __PACKED_POST EIP_TCP_INTERFACE_CONFIG_Ttag
  {
    uint32_t   ulIpAddr;
    uint32_t   ulSubnetMask;
    uint32_t   ulGatewayAddr;
    uint32_t   ulNameServer;
    uint32_t   ulNameServer_2;
    uint8_t    abDomainName[EIP_TCP_MAX_DOMAINNAME_LENGTH + 2];
  } EIP_TCP_INTERFACE_CONFIG_T;

  /*#####################################################################################*/

  /* IP multicast address configuration */
  typedef __PACKED_PRE struct __PACKED_POST EIP_TCP_MCAST_CONFIG_Ttag
  {
#define EIP_TCP_ALLOCCONTROL_DEFAULT 0
#define EIP_TCP_ALLOCCONTROL_MANUAL  1
    uint8_t    bAllocControl;     /* Multicast address allocation control
                                        word. Determines how addresses are
                                        allocated. */
    uint8_t    bReserved;
    uint16_t   usNumMCast;        /* Number of IP multicast addresses
                                       to allocate for EtherNet/IP */
    uint32_t   ulMcastStartAddr;  /* Starting multicast address from which
                                       to begin allocation */
  } EIP_TCP_MCAST_CONFIG_T;

  /*#####################################################################################*/

  /* Last Detected ACD Conflict  */
  typedef __PACKED_PRE struct __PACKED_POST EIP_TCP_ACD_LAST_CONFLICT_Ttag
  {
    uint8_t    bAcdActivity;      /* State of ACD activity when last
                                       conflict detected */

    uint8_t    abRemoteMac[6];    /* MAC address of remote node from
                                       the ARP PDU in which a conflict was
                                       detected */

    uint8_t    abArpPdu[28];      /* Copy of the raw ARP PDU in which
                                       a conflict was detected. */
  } EIP_TCP_ACD_LAST_CONFLICT_T;

  /*#####################################################################################*/

  typedef __PACKED_PRE struct __PACKED_POST EIP_TCP_INST_ATTR_Ttag
  {
    uint32_t                    ulInterfaceStatus;                          /* 1 Interface Status         */
    uint32_t                    ulConfigCapability;                         /* 2 Configuration Capability */
    uint32_t                    ulConfigControl;                            /* 3 Configuration Control    */
    uint16_t                    usLinkObjPathSize;                          /* 4 Physical Link Object     */
    uint8_t                     achLinkObjPath[EIP_TCP_LINK_PATH_LENGTH];    /* 4 */
    EIP_TCP_INTERFACE_CONFIG_T  tInterfaceConfig;                           /* 5 Interface Configuration  */
    uint8_t                     abHostname[EIP_TCP_MAX_HOSTNAME_LENGTH + 2]; /* 6 Host Name                */
    uint32_t                    ulFlags;
    uint8_t                     abEthernetAddr[6];
    uint8_t                     abSNN[6];                                   /* 7 Safety Network Number    */
    uint8_t                     bTTLValue;                                  /* 8 TTL Value                */
    EIP_TCP_MCAST_CONFIG_T      tMcastConfig;                               /* 9 Mcast Config             */
    uint8_t                     bSelectAcd;                                 /* 10 Select ACD              */
    EIP_TCP_ACD_LAST_CONFLICT_T tLastConflictDetected;                      /* 11 Last detected conflict  */
    uint8_t                     bQuickConnectEnable;                        /* 12 Enable/Disable of
                                                                                  QuickConnect feature    */
    uint16_t                    usEncapTimeout;                             /* 13 Encapsulation Inactivity
                                                                                  Timeout                 */
  } EIP_TCP_INST_ATTR_T;

#pragma pack()


  /*#####################################################################################*/

  typedef struct EIP_TCP_Ttag
  {
    EIP_TCP_CLASS_ATTR_T tClass;
    EIP_TCP_INST_ATTR_T  atInstance[1];
    uint32_t ulActiveMulticast;
  }EIP_TCP_T;

  /*#####################################################################################*/

  typedef struct EIP_TCP_INST_ATTR_STORED_Ttag
  {
    uint32_t                    ulConfigControl;                            /* 3 Configuration Control    */
    EIP_TCP_INTERFACE_CONFIG_T  tInterfaceConfig;                           /* 5 Interface Configuration  */
    uint8_t                     bSelectAcd;                                 /* 10 Select ACD              */
  } EIP_TCP_INST_ATTR_STORED_T;

  /*#####################################################################################*/

  typedef struct EIP_TCP_STORED_Ttag
  {
    EIP_TCP_INST_ATTR_STORED_T  atInstance[1];
  }EIP_TCP_STORED_T;

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

  typedef struct EIP_TCP_INIT_PARAM_Ttag
  {
    void* hNetif;
  }EIP_TCP_INIT_PARAM_T;


  uint32_t
  EipTcp_ObjectCreate( void*                 pvRsc,
                       EIP_TCP_INIT_PARAM_T* ptParam );

  void
  EipTcp_GetIp( void*    pvObjDir,
                uint32_t *pulIP );


#endif /* EIP_TCP_H */
