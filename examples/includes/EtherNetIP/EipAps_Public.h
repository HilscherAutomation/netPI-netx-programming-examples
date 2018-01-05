/**************************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

 **************************************************************************************

   Last Modification:
     @version $Id: EipAps_Public.h 37546 2013-08-21 09:36:49Z kai $

   Description:
     Eip DpmIntf
     public

   Changes:
     Date        Author        Description
     ----------------------------------------------------------------------------------
     2007-03-28  NC            Created

 **************************************************************************************/

#ifndef __EIP_DPMINTF_PUBLIC_H
#define __EIP_DPMINTF_PUBLIC_H

/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(EIP_DPMINTF_PUBLIC)
#endif

/***************************************************************************************/
/* Eip DpmIntf public, constants */

#define EIP_DPMINTF_PROCESS_QUEUE_NAME       "DPMINTF_QUE"

#define EIP_OBJECT_MAX_PACKET_LEN   1520  /*!< Maximum packet length */


// todo: add to right function
#define EIP_OBJECT_QOS_FLAGS_ENABLE          0x00000001
#define EIP_OBJECT_QOS_FLAGS_DEFAULT         0x00000002
#define EIP_OBJECT_QOS_FLAGS_DISABLE_802_1Q  0x00000004


/***************************************************************************************/
#define EIP_APS_PACKET_START              0x00003600

#define EIP_APS_SET_CONFIGURATION_REQ     0x00003608
#define EIP_APS_SET_CONFIGURATION_CNF     0x00003609

#define EIP_APS_SET_PARAMETER_REQ         0x0000360A
#define EIP_APS_SET_PARAMETER_CNF         0x0000360B

#define EIP_APS_MS_NS_CHANGE_IND          0x0000360C
#define EIP_APS_MS_NS_CHANGE_RES          0x0000360D

#define EIP_APS_GET_MS_NS_REQ             0x0000360E
#define EIP_APS_GET_MS_NS_CNF             0x0000360F

#define EIP_APS_SET_CONFIGURATION_PARAMETERS_REQ 0x00003612
#define EIP_APS_SET_CONFIGURATION_PARAMETERS_CNF 0x00003613

#define EIP_APS_CONFIG_DONE_REQ           0x00003614
#define EIP_APS_CONFIG_DONE_CNF           0x00003615

#define EIP_APS_PACKET_END                0x00003615

/***************************************************************************************/

#define EIP_OBJECT_PACKET_START           0x00001A00

#define EIP_OBJECT_MR_REGISTER_REQ        0x00001A02
#define EIP_OBJECT_MR_REGISTER_CNF        0x00001A03

#define EIP_OBJECT_AS_REGISTER_REQ        0x00001A0C
#define EIP_OBJECT_AS_REGISTER_CNF        0x00001A0D

#define   EIP_OBJECT_ID_SETDEVICEINFO_REQ 0x00001A16
#define   EIP_OBJECT_ID_SETDEVICEINFO_CNF 0x00001A17

#define   EIP_OBJECT_RESET_IND            0x00001A24
#define   EIP_OBJECT_RESET_RES            0x00001A25

#define   EIP_OBJECT_CONNECTION_IND       0x00001A2E
#define   EIP_OBJECT_CONNECTION_RES       0x00001A2F

#define   EIP_OBJECT_CL3_SERVICE_IND      0x00001A3E
#define   EIP_OBJECT_CL3_SERVICE_RES      0x00001A3F

#define   EIP_OBJECT_REGISTER_SERVICE_REQ 0x00001A44
#define   EIP_OBJECT_REGISTER_SERVICE_CNF 0x00001A45

#define   EIP_OBJECT_CYCLIC_EVENT_IND     0x00001AE0
#define   EIP_OBJECT_WATCHDOG_IND         0x00001AE2

#define   EIP_OBJECT_CIP_OBJECT_CHANGE2_IND  0x00001AEA

#define   EIP_OBJECT_CIP_SERVICE_REQ      0x00001AF8
#define   EIP_OBJECT_CIP_SERVICE_CNF      0x00001AF9

#define   EIP_OBJECT_CIP_OBJECT_CHANGE_IND  0x00001AFA
#define   EIP_OBJECT_CIP_OBJECT_CHANGE_RES  0x00001AFB



/***************************************************************************************/
/* Warmstart System Flags */
#define WSTART_SYSFLAG_START_MSK            0x00000001
#define WSTART_SYSFLAG_START_APPLICATION    0x00000001
#define WSTART_SYSFLAG_START_AUTO           0x00000000

#define WSTART_SYSFLAG_IOSTAT_ENABLE_MSK    0x00000002
#define WSTART_SYSFLAG_IOSTAT_ENABLED_MSK   0x00000002
#define WSTART_SYSFLAG_IOSTAT_DISABLED_MSK  0x00000000

#define WSTART_SYSFLAG_IOSTAT_LEN_MSK       0x00000004
#define WSTART_SYSFLAG_IOSTAT_LEN_8BIT      0x00000000
#define WSTART_SYSFLAG_IOSTAT_LEN_32BIT     0x00000004

/***************************************************************************************/
/* Eip DpmIntf public, types */
/*#####################################################################################*/
/*#####################################################################################*/

/*! \defgroup EIP_APS_SET_CONFIGURATION_REQ_Content Command related contents
 *  \ingroup EIP_APS_SET_CONFIGURATION_REQ
 * \{ */

typedef __PACKED_PRE struct EIP_DPMINTF_QOS_CONFIG_Ttag
{
  TLR_UINT32    ulQoSFlags;
  TLR_UINT8     bTag802Enable;        /* QoS Attribute 1 */
  TLR_UINT8     bDSCP_PTP_Event;      /* QoS Attribute 2 */
  TLR_UINT8     bDSCP_PTP_General;    /* QoS Attribute 3 */
  TLR_UINT8     bDSCP_Urgent;         /* QoS Attribute 4 */
  TLR_UINT8     bDSCP_Scheduled;      /* QoS Attribute 5 */
  TLR_UINT8     bDSCP_High;           /* QoS Attribute 6 */
  TLR_UINT8     bDSCP_Low;            /* QoS Attribute 7 */
  TLR_UINT8     bDSCP_Explicit;       /* QoS Attribute 8 */
} __PACKED_POST EIP_DPMINTF_QOS_CONFIG_T;

typedef __PACKED_PRE struct EIP_DPMINTF_TI_ACD_LAST_CONFLICT_Ttag
{
  TLR_UINT8    bAcdActivity;      /*!< State of ACD activity when last
                                       conflict detected */

  TLR_UINT8    abRemoteMac[6];    /*!< MAC address of remote node from
                                       the ARP PDU in which a conflict was
                                       detected */

  TLR_UINT8    abArpPdu[28];      /*!< Copy of the raw ARP PDU in which
                                       a conflict was detected. */
} __PACKED_POST EIP_DPMINTF_TI_ACD_LAST_CONFLICT_T;

typedef __PACKED_PRE struct EIP_DPMINTF_TI_MCAST_CONFIG_Ttag
{
  TLR_UINT8    bAllocControl;     /* Multicast address allocation control
                                    word. Determines how addresses are
                                    allocated. */
  TLR_UINT8    bReserved;
  TLR_UINT16   usNumMCast;        /* Number of IP multicast addresses
                                   to allocate for EtherNet/IP */
  TLR_UINT32   ulMcastStartAddr;  /* Starting multicast address from which */
} __PACKED_POST EIP_DPMINTF_TI_MCAST_CONFIG_T;

#define EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE    0x00000001  /*!< If set, the Quick Connect Attribute 12
                                                                   of the Tcp Interface Object (0xF5) is
                                                                   activated */

#define EIP_OBJECT_QC_FLAGS_ENABLE_QC             0x00000002  /*!< This flags sets the value of the Quick Connect Attribute.\n\n

                                                                   If set, Quick Connect is enabled.\n
                                                                   If not set, Quick Connect is disabled\n\n

                                                                   <b>Note:</b>\n

                                                                   This flag has only an effect if EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE is set simultaneously. */

typedef __PACKED_PRE struct EIP_APS_SET_CONFIGURATION_REQ_Ttag{
  TLR_UINT32  ulSystemFlags;    /*!< Reserved for IO status */
  TLR_UINT32  ulWdgTime;        /*!< Watch dog time (in milliseconds) <br>

                                     \valueRange
                                     0, 20...65535\n
                                     Default: 1000

                                     \description
                                     Value 0 switches off the watch dog */

  TLR_UINT32  ulInputLen;       /*!< Length of input data (Input Assembly)\n

                                     \valueRange
                                     0...504 \n
                                     Default: 16

                                     \description
                                     Defines the input data size and corresponds directly
                                     to the input assembly instance provided by ulInputAssInstance */
  TLR_UINT32  ulOutputLen;      /*!< Length of Output data (Output Assembly)\n

                                     \valueRange
                                     0...504 \n
                                     Default: 16

                                     \description
                                     Defines the output data size and corresponds directly
                                     to the input assembly instance provided by ulOutputAssInstance */

  TLR_UINT32  ulTcpFlag;        /*!< TCP configuration flags\n

                                     \valueRange
                                     Default: 0x00000410 (DHCP and Auto-Negotiation)

                                     \description
                                     For further information see TCPIP-Manual */
#define IP_CFG_FLAG_IP_ADDR             (0x0001)
#define IP_CFG_FLAG_NET_MASK            (0x0002)
#define IP_CFG_FLAG_GATEWAY             (0x0004)
#define IP_CFG_FLAG_BOOTP               (0x0008)
#define IP_CFG_FLAG_DHCP                (0x0010)
#define IP_CFG_FLAG_ETHERNET_ADDR       (0x0020)
#define IP_CFG_FLAG_HTTP_SOCKETS        (0x0040)
#define IP_CFG_FLAG_FQDN_NAME           (0x0080)

/*** #define IP_CFG_FLAG_AUTO_DETECT         (0x0100) ***/
#define IP_CFG_FLAG_INTF_TP             (0x0200)
#define IP_CFG_FLAG_AUTO_NEGOTIATE      (0x0400)
#define IP_CFG_FLAG_FULL_DUPLEX         (0x0800)
#define IP_CFG_FLAG_SPEED_100MBIT       (0x1000)
#define IP_CFG_FLAG_EXTENDED_FLAGS      (0x8000)

#define IP_CFG_FLAG_PORT1_AUTO_NEGOTIATE (0x0400)
#define IP_CFG_FLAG_PORT1_FULL_DUPLEX    (0x0800)
#define IP_CFG_FLAG_PORT1_SPEED_100MBIT  (0x1000)

  TLR_UINT32  ulIpAddr;         /*!< IP address \n
                                     \valueRange
                                     All valid IP addresses\n
                                     Default: 0.0.0.0 */
  TLR_UINT32  ulNetMask;        /*!< Network mask \n

                                     \valueRange
                                     All valid masks\n
                                     Default: 0.0.0.0 */
  TLR_UINT32  ulGateway;        /*!< Gateway address \n

                                     \valueRange
                                     All valid IP addresses\n
                                     Default: 0.0.0.0 */

  TLR_UINT16  usVendId;         /*!< CIP vendor identification \n

                                     \valueRange
                                     1...65535 \n
                                     Default: 283 (Hilscher GmbH)

                                     \description
                                     This is an identification number for
                                     the manufacturer of an EtherNet/IP device.
                                     Vendor IDs are managed by ODVA.
                                     The value zero is not valid */
  TLR_UINT16  usProductType;    /*!< CIP device type \n

                                     \valueRange
                                     Publicly defined: 0x00 - 0x64    \n
                                     Vendor specific: 0x64 - 0xC7     \n
                                     Reserved by CIP: 0xC8 - 0xFF     \n
                                     Publicly defined: 0x100 - 0x2FF  \n
                                     Vendor specific: 0x300 - 0x4FF   \n
                                     Reserved by CIP: 0x500 - 0xFFFF  \n\n
                                     Default: 0x0C (Communication Device)

                                     \description
                                     The list of device types is managed by ODVA.
                                     It is used to identify the device profile that a
                                     particular product is using. Device profiles
                                     define minimum requirements a device must
                                     implement as well as common options. */
  TLR_UINT16  usProductCode;    /*!< Product code \n

                                     \valueRange
                                     1...65535

                                     \description
                                     The vendor assigned Product Code identifies a particular product within a device type. Each
                                     vendor assigns this code to each of its products. The Product Code typically maps to one or
                                     more catalog/model numbers. Products shall have different codes if their configuration and/or
                                     runtime options are different. Such devices present a different logical view to the network. On
                                     the other hand for example, two products that are the same except for their color or mounting
                                     feet are the same logically and may share the same product code.
                                     The value zero is not valid. */

  TLR_UINT32  ulSerialNumber;   /*!< Serial number \n

                                     \valueRange
                                     0x00000000... 0xFFFFFFFF

                                     \description
                                     This attribute is a number used in conjunction with the Vendor ID to form a unique identifier
                                     for each device on any CIP network. Each vendor is responsible for guaranteeing the
                                     uniqueness of the serial number across all of its devices. \n
                                     Usually, this number will be set automatically by the firmware,
                                     if a security memory is available. */

  TLR_UINT8   bMinorRev;        /*!< Minor revision \n

                                     \valueRange
                                     1...255 */

  TLR_UINT8   bMajorRev;        /*!< Major revision \n

                                     \valueRange
                                     1...127 */

  TLR_UINT8   abDeviceName[32]; /*!< Device name\n

                                     \description
                                     This text string should represent a short description of the product/product family represented
                                     by the product code. The same product code may have a variety of product name
                                     strings.\n\n
                                     The first byte indicates the name length, byte
                                     2-31 contain the actual characters of the device name.*/

  TLR_UINT32  ulInputAssInstance;   /*!< Instance number of input assembly\n

                                     \valueRange \n\n
                                     Instances of the Assembly Object are divided into the following address ranges to \n
                                     provide for extensions to device profiles \n\n
                                     0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                     0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                     0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)      \n
                                     0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                     \description
                                     This parameter defines the instance number of the input assembly.

                                     */

  TLR_UINT8   ulInputAssFlags;      /*!< Input assembly flags\n

                                      \valueRange \n

                                       - <b> Bit 0:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 1:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 2:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 3:</b> \n
                                         If set, the assembly data is modeless
                                         (i.e. it does <b>not</b> contain run/idle information) \n\n

                                       - <b> Bit 4:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 5:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 6:</b> \n
                                         This flag decides whether the data that is mapped into the
                                         DPM memory area is cleared upon closing of
                                         the connection or whether the last sent/received data is left
                                         unchanged in the memory.
                                         If the bit is set the data will be left unchanged.\n\n
                                     */


  TLR_UINT32  ulOutputAssInstance;  /*!< Instance number of output assembly\n

                                     \valueRange \n\n
                                     Instances of the Assembly Object are divided into the following address ranges to \n
                                     provide for extensions to device profiles \n\n
                                     0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                     0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                     0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)      \n
                                     0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                     \description
                                     This parameter defines the instance number of the output assembly.

                                     */

  TLR_UINT8   ulOutputAssFlags;     /*!< Output assembly flags\n

                                      \valueRange \n
                                      See description of ulInputAssFlags
                                     */

  EIP_DPMINTF_QOS_CONFIG_T tQoS_Config; /*!< Quality of Service \n

                                          \description

                                           This parameter set configures the Quality of Service Object
                                           (CIP Id 0x48).
                                           For more information about specific parameters see command
                                           EIP_OBJECT_CFG_QOS_REQ.

                                         */

  TLR_UINT32   ulNameServer;         /*!< Name Server 1\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        Default value: 0.0.0.0
                                     */

  TLR_UINT32   ulNameServer_2;       /*!< Name Server 2\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        Default value: 0.0.0.0
                                      */

  TLR_UINT8    abDomainName[48 + 2]; /*!< Domain Name\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).
                                        The first two bytes of the name provide the length of the name.

                                        \valueRange \n
                                        Default value: No Name ("") \n
                                        Max. name length is 48 bytes

                                      */

  TLR_UINT8    abHostName[64+2];     /*!< Host Name\n

                                       \description
                                        This parameter corresponds to attribute 6 of the
                                        TCP Interface Object (CIP Id 0xF5).
                                        The first two bytes of the name provide the length of the name.

                                        \valueRange \n
                                        Default value: No Name ("") \n
                                        Max. name length is 64 bytes
                                      */

  TLR_UINT8    bSelectAcd;           /*!< Select ACD

                                         \description
                                        This parameter corresponds to attribute 10 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        1: ACD on (default) \n
                                        0: ACD off

                                      */

  EIP_DPMINTF_TI_ACD_LAST_CONFLICT_T  tLastConflictDetected; /*!< Last detected conflict\n

                                                               \description
                                                               This parameter corresponds to attribute 11 of the
                                                               TCP Interface Object (CIP Id 0xF5).

                                                               \valueRange \n
                                                               Default: All zero
                                                             */

  TLR_UINT8                           bQuickConnectFlags; /*!< Quick Connect flags \n

                                                               \description
                                                               This parameter enables/disables the Quick Connect
                                                               functionality within the stack.
                                                               This affects the TCP Interface Object (0xF5)
                                                               attribute 12. \n\n
                                                               \Note: This functionality needs special hardware settings (e.g. fast
                                                               flash)

                                                               \valueRange \n
                                                               See: \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               and  \ref EIP_OBJECT_QC_FLAGS_ENABLE_QC

                                                               <b>Examples:</b>\n\n
                                                               Do not support Quick Connect:\n
                                                               Set to zero \n\n

                                                               Support Quick Connect - Quick Connect disabled:\n
                                                               Set only flag \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               in order to activate the Quick Connect attribute within the object.\n\n

                                                               Support Quick Connect - Quick Connect enabled:\n
                                                               Set flag \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               and flag \ref EIP_OBJECT_QC_FLAGS_ENABLE_QC in order to
                                                               activate the attribute and simultaneously enable the
                                                               Quick Connection functionality.\n\n
                                                             */

}__PACKED_POST  EIP_APS_SET_CONFIGURATION_REQ_T;


#define EIP_APS_SET_CONFIGURATION_REQ_SIZE (sizeof(EIP_APS_SET_CONFIGURATION_REQ_T))


typedef struct EIP_APS_PACKET_SET_CONFIGURATION_REQ_Ttag{
  TLR_PACKET_HEADER_T             tHead;
  EIP_APS_SET_CONFIGURATION_REQ_T tData;
} EIP_APS_PACKET_SET_CONFIGURATION_REQ_T;


 #define EIP_APS_SET_CONFIGURATION_CNF_SIZE 0

typedef struct EIP_APS_PACKET_SET_CONFIGURATION_CNF_Ttag{
  TLR_PACKET_HEADER_T tHead;
} EIP_APS_PACKET_SET_CONFIGURATION_CNF_T;

/*! \} */

/*#####################################################################################*/
/*#####################################################################################*/

/*! \defgroup EIP_APS_SET_PARAMETER_REQ_Content Command related contents
 *  \ingroup EIP_APS_SET_PARAMETER_REQ
 * \{ */

#define EIP_APS_PRM_SIGNAL_MS_NS_CHANGE            0x00000001 /*!< This flag enables or disables the notification of
                                                                   the network and module status. Every time the status
                                                                   of the module or network changes packet
                                                                   EIP_APS_MS_NS_CHANGE_IND will be sent to the
                                                                   registered EtherNet/IP Application task.    */

typedef __PACKED_PRE struct EIP_APS_SET_PARAMETER_REQ_Ttag
{
  TLR_UINT32  ulParameterFlags;    /*!< Parameter flags \n

                                       \description
                                       \ref EIP_APS_PRM_SIGNAL_MS_NS_CHANGE\n
                                       If set, this flag enables the notification of
                                       the network and module status. Every time the status
                                       of the module or network changes packet
                                       EIP_APS_MS_NS_CHANGE_IND will be sent to the
                                       registered EtherNet/IP Application task. */

}__PACKED_POST  EIP_APS_SET_PARAMETER_REQ_T;

#define EIP_APS_SET_PARAMETER_REQ_SIZE (sizeof(EIP_APS_SET_PARAMETER_REQ_T))

typedef struct EIP_APS_PACKET_SET_PARAMETER_REQ_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
  EIP_APS_SET_PARAMETER_REQ_T     tData;
} EIP_APS_PACKET_SET_PARAMETER_REQ_T;

 #define EIP_APS_SET_PARAMETER_CNF_SIZE 0

typedef struct EIP_APS_PACKET_SET_PARAMETER_CNF_Ttag
{
  TLR_PACKET_HEADER_T tHead;
} EIP_APS_PACKET_SET_PARAMETER_CNF_T;

/*! \} */

/*#####################################################################################*/

/*! \defgroup EIP_APS_MS_NS_CHANGE_IND_Content Command related contents
 *  \ingroup EIP_APS_MS_NS_CHANGE_IND
 * \{ */

typedef __PACKED_PRE struct EIP_APS_MS_NS_CHANGE_IND_Ttag
{
  TLR_UINT32  ulModuleStatus;     /*!< Module Status \n

                                       \description
                                       The module status describes the current state of the
                                       corresponding MS-LED (provided that it is connected).
                                       See \ref EIP_HW_MODUL_STATUS_E for more details. */

  TLR_UINT32  ulNetworkStatus;     /*!< Network Status \n

                                       \description
                                       The network status describes the current state of the
                                       corresponding NS-LED (provided that it is connected).
                                       See \ref EIP_HW_NET_STATUS_E for more details. */

}__PACKED_POST  EIP_APS_MS_NS_CHANGE_IND_T;

#define EIP_APS_MS_NS_CHANGE_IND_SIZE (sizeof(EIP_APS_MS_NS_CHANGE_IND_T))

typedef struct EIP_APS_PACKET_MS_NS_CHANGE_IND_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
  EIP_APS_MS_NS_CHANGE_IND_T      tData;
} EIP_APS_PACKET_MS_NS_CHANGE_IND_T;


#define EIP_APS_MS_NS_CHANGE_RES_SIZE 0

typedef struct EIP_APS_PACKET_MS_NS_CHANGE_RES_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
} EIP_APS_PACKET_MS_NS_CHANGE_RES_T;

/*! \} */

/*#####################################################################################*/
/*#####################################################################################*/

/*! \defgroup EIP_APS_GET_MS_NS_REQ_Content Command related contents
 *  \ingroup EIP_APS_GET_MS_NS_REQ
 * \{ */

#define EIP_APS_GET_MS_NS_REQ_SIZE       0

typedef struct EIP_APS_PACKET_GET_MS_NS_REQ_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
} EIP_APS_PACKET_GET_MS_NS_REQ_T;


typedef __PACKED_PRE struct EIP_APS_GET_MS_NS_CNF_Ttag
{
  TLR_UINT32  ulModuleStatus;     /*!< Module Status \n

                                       \description
                                       The module status describes the current state of the
                                       corresponding MS-LED (provided that it is connected).
                                       See \ref EIP_HW_MODUL_STATUS_E for more details. */

  TLR_UINT32  ulNetworkStatus;     /*!< Network Status \n

                                       \description
                                       The network status describes the current state of the
                                       corresponding NS-LED (provided that it is connected).
                                       See \ref EIP_HW_NET_STATUS_E for more details. */

}__PACKED_POST  EIP_APS_GET_MS_NS_CNF_T;

#define EIP_APS_GET_MS_NS_CNF_SIZE  sizeof(EIP_APS_GET_MS_NS_CNF_T)

typedef struct EIP_APS_PACKET_GET_MS_NS_CNF_Ttag
{
  TLR_PACKET_HEADER_T      tHead;
  EIP_APS_GET_MS_NS_CNF_T  tData;

} EIP_APS_PACKET_GET_MS_NS_CNF_T;
/*! \} */

/*#####################################################################################*/
/*#####################################################################################*/
/* Eip Object, packets */

/*! \defgroup EIP_OBJECT_MR_REGISTER_REQ_Content Command related contents
 *  \ingroup EIP_OBJECT_MR_REGISTER_REQ
 * \{*/

typedef enum EIP_OBJECT_MR_REGISTER_OPTION_FLAGS_Etag
{
  EIP_OBJECT_MR_REGISTER_OPTION_FLAGS_USE_OBJECT_PROVIDED_BY_STACK = 1, /* Activate a stack internal CIP object.
                                                                           This option can currently be used for the following CIP objects

                                                                             - Time Sync object (class code 0x43)
                                                                           */
} EIP_OBJECT_MR_REGISTER_OPTION_FLAGS_E;

typedef  __PACKED_PRE struct EIP_OBJECT_MR_REGISTER_REQ_Ttag
{
  TLR_UINT32 ulReserved1;              /*!< Reserved, set to 0x00 */

  TLR_UINT32 ulClass;                 /*!< Object class identifier

                                           \valueRange \n\n
                                           Instances of the Assembly Object are divided into the following address ranges to \n
                                           provide for extensions to device profiles \n\n
                                           0x0001 - 0x0063 : Open                            \n
                                           0x0064 - 0x00C7 : Vendor Specific                 \n
                                           0x00C8 - 0x00EF : Reserved by ODVA for future use \n
                                           0x00F0 - 0x02FF : Open                            \n
                                           0x0300 - 0x04FF : Vendor Specific                 \n
                                           0x0500 - 0xFFFF : Reserved by ODVA for future use \n */

  TLR_UINT32 ulOptionFlags;           /*!< Option flags

                                           see EIP_OBJECT_MR_REGISTER_OPTION_FLAGS_E
                                           */

}__PACKED_POST EIP_OBJECT_MR_REGISTER_REQ_T;

typedef __PACKED_PRE struct EIP_OBJECT_MR_PACKET_REGISTER_REQ_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
  EIP_OBJECT_MR_REGISTER_REQ_T  tData;
}__PACKED_POST EIP_OBJECT_MR_PACKET_REGISTER_REQ_T;

#define EIP_OBJECT_MR_REGISTER_REQ_SIZE   (sizeof(EIP_OBJECT_MR_REGISTER_REQ_T) )

typedef  __PACKED_PRE struct EIP_OBJECT_MR_PACKET_REGISTER_CNF_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
}__PACKED_POST EIP_OBJECT_MR_PACKET_REGISTER_CNF_T;

#define EIP_OBJECT_MR_REGISTER_CNF_SIZE   0

/*! \}*/
/*#####################################################################################*/
/*#####################################################################################*/
/*! \defgroup EIP_OBJECT_AS_REGISTER_REQ_Content Command related contents
 *  \ingroup EIP_OBJECT_AS_REGISTER_REQ
 * \{ */

/* Flags for the Assembly Object */
#define EIP_AS_FLAG_READONLY            0x00000001 /*!< This flag decides whether the newly registered assembly instance is an
                                                        input or an output assembly (also called input/ouput connection point).
                                                        Output connection points will be mapped automatically into the DPM output data area.
                                                        Input connection points will be mapped automatically into the DPM input data area.\n\n
                                                        If set, the assembly instance serves as input connection point (data received from the network).\n
                                                        If not set, the assembly instance serves as output connection point (data transmitted to the network). */

/* #define EIP_AS_FLAG_ACTIVE           0x00000002 */
/* #define EIP_AS_FLAG_TRIBLEBUF        0x00000004 */

#define EIP_AS_FLAG_RUNIDLE             0x00000008 /*!< If set, the assembly data is modeless (i.e. it does not contain
                                                        run/idle information) */

#define EIP_AS_FLAG_NEWDATA             0x00000010 /*!< The new data flag is used internally and must be set to 0. */

#define EIP_AS_FLAG_CONFIG              0x00000020 /*!< This flag is used to make this assembly a configuration
                                                        assembly. For further information have a look at the command
                                                        \ref EIP_OBJECT_CONNECTION_CONFIG_IND */

#define EIP_AS_FLAG_HOLDLASTSTATE       0x00000040 /*!< This flag decides whether the data that is mapped into the
                                                        corresponding DPM memory area is cleared upon closing of
                                                        the connection or whether the last sent/received data is left
                                                        unchanged in the memory.
                                                        If the bit is set the data will be left unchanged. */

#define EIP_AS_FLAG_FIX_SIZE            0x00000080 /*!< This flag decides whether the assembly instance allows
                                                        a connection to be established with a smaller connection size than
                                                        defined in ulSize or whether only the size defined in ulSize is accepted.
                                                        If the bit is set, the connection size in a ForwardOpen must directly
                                                        correspond to ulSize. */

#define EIP_AS_FLAG_FORWARD_RUNIDLE     0x00000100 /*!< For input assemblies that receive the run/idle header, this flag
                                                        decides whether the run/idle header shall remain in the IO data when being
                                                        written into the triple buffer or DPM. This way the host application
                                                        has the possibility to evaluate the run/idle information on its own.
                                                        If the bit is set the run/idle header will be part of the IO data image. */

#define EIP_AS_FLAG_INVISIBLE           0x00000200 /*!< This flag decides whether the assembly instance can be accessed via
                                                        explicit services from the network. \n\n
                                                        Flag is set: the assembly instance is visible.\n
                                                        Flag is not set: the assembly instance is invisible. */
#define EIP_AS_FLAG_INPUTONLY           0x40000000 /*!< This flag decides if the assembly is an input only connection point */
#define EIP_AS_FLAG_LISTENONLY          0x80000000 /*!< This flag decides if the assembly is a listen only connection point */

typedef  __PACKED_PRE struct EIP_OBJECT_AS_REGISTER_REQ_Ttag
{
  TLR_UINT32      ulInstance;       /*!< Assembly instance number \n

                                         \valueRange \n\n
                                         Instances of the Assembly Object are divided into the following address ranges to  \n
                                         provide for extensions to device profiles \n\n
                                         0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                         0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                         0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                         0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                         0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)       \n
                                         0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                         \note \n\n
                                         The instance numbers 192 (hex C0) and 193 (hex C1) are usually used as the dummy connection
                                         points for listen only and input only connections. These values <b>must not </b> be used for new
                                         connection points.\n\n
                                         If loadable firmware is used these values are not adaptable. If not, theses values can be changed
                                         within the startup parameters of the object task
                                         (see structure EIP_OBJECT_PARAMETER_T in EipObject_Functionlist.h).
                                         */

  TLR_UINT32      ulDPMOffset;      /*!< Relative offset of the assembly instance data within the DPM input/output area. */
  TLR_UINT32      ulSize;           /*!< Size of the assembly instance data in bytes */
  TLR_UINT32      ulFlags;          /*!< Flags to configure the assembly instance properties \n

                                         \valueRange \n

                                         - Bit 0: <b> \ref EIP_AS_FLAG_READONLY        </b> \n\n
                                         - Bit 1: <b> \ref EIP_AS_FLAG_ACTIVE          </b> \n\n
                                         - Bit 2: <b> \ref EIP_AS_FLAG_TRIBLEBUF       </b> \n\n
                                         - Bit 3: <b> \ref EIP_AS_FLAG_RUNIDLE         </b> \n\n
                                         - Bit 4: <b> \ref EIP_AS_FLAG_NEWDATA         </b> \n\n
                                         - Bit 5: <b> \ref EIP_AS_FLAG_CONFIG          </b> \n\n
                                         - Bit 6: <b> \ref EIP_AS_FLAG_HOLDLASTSTATE   </b> \n\n
                                         - Bit 7: <b> \ref EIP_AS_FLAG_FIX_SIZE        </b> \n\n
                                         - Bit 8: <b> \ref EIP_AS_FLAG_FORWARD_RUNIDLE </b> \n\n
                                         - Bit 9: <b> \ref EIP_AS_FLAG_INVISIBLE       </b> \n\n */

}__PACKED_POST EIP_OBJECT_AS_REGISTER_REQ_T;

typedef  __PACKED_PRE struct EIP_OBJECT_AS_PACKET_REGISTER_REQ_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
  EIP_OBJECT_AS_REGISTER_REQ_T  tData;
}__PACKED_POST EIP_OBJECT_AS_PACKET_REGISTER_REQ_T;

#define EIP_OBJECT_AS_REGISTER_REQ_SIZE   (sizeof(EIP_OBJECT_AS_REGISTER_REQ_T) )

typedef  __PACKED_PRE struct EIP_OBJECT_AS_REGISTER_CNF_Ttag
{
  TLR_UINT32  ulInstance;               /*!< Assembly instance number from the request packet              */
  TLR_UINT32  ulDPMOffset;              /*!< DPM offset for the instance data area from the request packet */
  TLR_UINT32  ulSize;                   /*!< Size of the data area from the request packet                 */
  TLR_UINT32  ulFlags;                  /*!< Assembly flags from the request packet                        */
  TLR_HANDLE  hDataBuf;                 /*!< Handle of the triple data buffer                              */
}__PACKED_POST EIP_OBJECT_AS_REGISTER_CNF_T;

typedef  __PACKED_PRE struct EIP_OBJECT_AS_PACKET_REGISTER_CNF_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
  EIP_OBJECT_AS_REGISTER_CNF_T  tData;
}__PACKED_POST EIP_OBJECT_AS_PACKET_REGISTER_CNF_T;

#define EIP_OBJECT_AS_REGISTER_CNF_SIZE   (sizeof(EIP_OBJECT_AS_REGISTER_CNF_T) )

/*! \}*/
/*#####################################################################################*/
/*#####################################################################################*/

/*! \addtogroup EIP_OBJECT_ID_SETDEVICEINFO_REQ_Content
 * \{*/
#define EIP_ID_MAX_PRODUKTNAME_LEN  32
/* \} */
/*! \defgroup EIP_OBJECT_ID_SETDEVICEINFO_REQ_Content Command related contents
 *  \ingroup EIP_OBJECT_ID_SETDEVICEINFO_REQ
 * \{ */

typedef struct EIP_OBJECT_ID_SETDEVICEINFO_REQ_Ttag
{
  TLR_UINT32 ulVendId;        /*!< CIP vendor identification \n

                                     \valueRange
                                     1...65535 \n
                                     Default: 283 (Hilscher GmbH)

                                     \description
                                     This is an identification number for
                                     the manufacturer of an EtherNet/IP device.
                                     Vendor IDs are managed by ODVA.
                                     The value zero is not valid */

  TLR_UINT32 ulProductType;   /*!< CIP device type \n

                                     \valueRange
                                     Publicly defined: 0x00 - 0x64    \n
                                     Vendor specific: 0x64 - 0xC7     \n
                                     Reserved by CIP: 0xC8 - 0xFF     \n
                                     Publicly defined: 0x100 - 0x2FF  \n
                                     Vendor specific: 0x300 - 0x4FF   \n
                                     Reserved by CIP: 0x500 - 0xFFFF  \n\n
                                     Default: 0x0C (Communication Device)

                                     \description
                                     The list of device types is managed by ODVA.
                                     It is used to identify the device profile that a
                                     particular product is using. Device profiles
                                     define minimum requirements a device must
                                     implement as well as common options. */

  TLR_UINT32 ulProductCode;     /*!< Product code \n

                                     \valueRange
                                     1...65535

                                     \description
                                     The vendor assigned Product Code identifies a particular product within a device type. Each
                                     vendor assigns this code to each of its products. The Product Code typically maps to one or
                                     more catalog/model numbers. Products shall have different codes if their configuration and/or
                                     runtime options are different. Such devices present a different logical view to the network. On
                                     the other hand for example, two products that are the same except for their color or mounting
                                     feet are the same logically and may share the same product code.
                                     The value zero is not valid. */
  TLR_UINT32 ulMajRev;          /*!< Major revision \n

                                     \valueRange
                                     1...127 */

  TLR_UINT32 ulMinRev;          /*!< Minor revision \n

                                     \valueRange
                                     1...255 */

  TLR_UINT32 ulSerialNumber;    /*!< Serial number \n

                                     \valueRange
                                     0x00000000... 0xFFFFFFFF

                                     \description
                                     This attribute is a number used in conjunction with the Vendor ID to form a unique identifier
                                     for each device on any CIP network. Each vendor is responsible for guaranteeing the
                                     uniqueness of the serial number across all of its devices. \n
                                     Usually, this number will be set automatically by the firmware,
                                     if a security memory is available. */

  TLR_UINT8  abProductName[EIP_ID_MAX_PRODUKTNAME_LEN]; /*!< Device name with maximum name length of \ref EIP_ID_MAX_PRODUKTNAME_LEN\n

                                                             \description
                                                             This text string should represent a short description of the product/product family represented
                                                             by the product code. The same product code may have a variety of product name
                                                             strings.\n\n
                                                             The first byte indicates the name length, byte
                                                             2-31 contain the actual characters of the device name.*/
}EIP_OBJECT_ID_SETDEVICEINFO_REQ_T;

typedef struct EIP_OBJECT_ID_PACKET_SETDEVICEINFO_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  EIP_OBJECT_ID_SETDEVICEINFO_REQ_T tData;
}EIP_OBJECT_ID_PACKET_SETDEVICEINFO_REQ_T;

#define EIP_OBJECT_ID_SETDEVICEINFO_REQ_SIZE (sizeof(EIP_OBJECT_ID_SETDEVICEINFO_REQ_T))

typedef struct EIP_OBJECT_ID_PACKET_SETDEVICEINFO_CNF_Ttag
{
  TLR_PACKET_HEADER_T         tHead;
}EIP_OBJECT_ID_PACKET_SETDEVICEINFO_CNF_T;

#define EIP_OBJECT_ID_SETDEVICEINFO_CNF_SIZE 0
/* \} */
/*#####################################################################################*/
/*#####################################################################################*/

/*! \defgroup EIP_OBJECT_RESET_IND_Content Command related contents
 *  \ingroup EIP_OBJECT_RESET_IND
 * \{ */
typedef struct EIP_OBJECT_RESET_IND_Ttag
{
  TLR_UINT32 ulDataIdx;                 /*!< Index of the service */
  TLR_UINT32 ulResetTyp;                /*!< Type of the reset \n

                                             \valueRange
                                             0, 1

                                             \description
                                             0: Reset is done emulating power cycling of
                                                the device(default)\n
                                             1: Return as closely as possible to the factory
                                                default configuration. Reset is then done
                                                emulating power cycling of the device.<br>
                                                <b>Note</b>:\n Reset type 1 is not supported
                                                by default. It needs to be enabled separately
                                                using the command EIP_OBJECT_SET_PARAMETER_REQ.*/

}EIP_OBJECT_RESET_IND_T;

typedef __PACKED_PRE struct EIP_OBJECT_PACKET_RESET_IND_Ttag
{
  TLR_PACKET_HEADER_T     tHead;
  EIP_OBJECT_RESET_IND_T  tData;
} __PACKED_POST EIP_OBJECT_PACKET_RESET_IND_T;

#define EIP_OBJECT_RESET_IND_SIZE          sizeof(EIP_OBJECT_RESET_IND_T)

typedef struct EIP_OBJECT_PACKET_RESET_RES_Ttag
{
  TLR_PACKET_HEADER_T     tHead;
}EIP_OBJECT_PACKET_RESET_RES_T;

#define EIP_OBJECT_RESET_RES_SIZE          0

/* \} */
/*#####################################################################################*/
/*#####################################################################################*/
/*! \defgroup EIP_OBJECT_CONNECTION_IND_Content Command related contents
 *  \ingroup EIP_OBJECT_CONNECTION_IND
 * \{ */

/* Connection Indication defines *********************************************/
//#define EIP_UNCONNECT  0
//#define EIP_CONNECTED  1
//#define EIP_CONNECTED  2

typedef enum EIP_CONNECTION_STATE_Ttag
{
  EIP_UNCONNECT = 0,   /*!< 0: Connection was closed                  */
  EIP_CONNECTED,       /*!< 1: Connection was established             */
  EIP_DIAGNOSTIC       /*!< 2: Diagnostics (EtherNet/IP Scanner only) */
}EIP_CONNECTION_STATE_T;

typedef enum EIP_EXT_CONNECTION_STATE_Ttag
{
  EIP_CONN_STATE_UNDEFINED = 0, /*!< 0: Undefined, not used  */
  EIP_CONN_STATE_TIMEOUT        /*!< 1: Connection timed out */
}EIP_EXT_CONNECTION_STATE_T;


/* Connection type */
typedef enum EIP_CONNECTION_TYPE_Ttag{
  EIP_CONN_TYPE_UNDEFINED = 0,              /*!< 0: Undefined, not used                                 */
  EIP_CONN_TYPE_CLASS_0_1_EXCLUSIVE_OWNER,  /*!< 1: Class0/Class1 (implicit) exclusive owner connection */
  EIP_CONN_TYPE_CLASS_0_1_REDUNDANT_OWNER,  /*!< 2: Class0/Class1 (implicit) redundant owner connection */
  EIP_CONN_TYPE_CLASS_0_1_LISTEN_ONLY,      /*!< 3: Class0/Class1 (implicit) listen only connection     */
  EIP_CONN_TYPE_CLASS_0_1_INPUT_ONLY,       /*!< 4: Class0/Class1 (implicit) input only connection      */
  EIP_CONN_TYPE_CLASS_3                     /*!< 5: Class3        (explicit) connection                 */
}EIP_CONNECTION_TYPE_T;


typedef struct EIP_OBJECT_OT_CONNECTION_Ttag
{
    TLR_UINT32 ulConnHandle;                /*!< Connection handle
                                               \description
                                               This connection handle is the handle
                                               that was provided when the connection was
                                               registered using \ref EIP_OBJECT_REGISTER_CONNECTION_REQ. */

    TLR_UINT32 ulReserved[4];               /*!< Reserved */
} EIP_OBJECT_OT_CONNECTION_T;

typedef struct EIP_OBJECT_TO_CONNECTION_Ttag
{
    TLR_UINT32 ulClass;                     /*!< CIP object the connection was addressed to              */
    TLR_UINT32 ulInstance;                  /*!< Instance of CIP object                                  */
    TLR_UINT32 ulOTConnPoint;               /*!< O2T connection point                                    */
    TLR_UINT32 ulTOConnPoint;               /*!< T2O connection point                                    */
    TLR_UINT32 ulConnectionType;            /*!< Type of connection ( see \ref EIP_CONNECTION_TYPE_Ttag) */
} EIP_OBJECT_TO_CONNECTION_T;

typedef union EIP_OBJECT_CONNECTION_Ttag /*!< If  is true use tOTConnection otherwise
                                              tTOConnection */
{
    EIP_OBJECT_OT_CONNECTION_T tOTConnection; /*!< Use this structure if ulOriginator is true */
    EIP_OBJECT_TO_CONNECTION_T tTOConnection; /*!< Use this structure if ulOriginator is false */
} EIP_OBJECT_CONNECTION_T;

typedef __PACKED_PRE struct EIP_OBJECT_EXT_CONNECTION_INFO_Ttag
{
  TLR_UINT32  ulProConnId;           /*!< Producer Connection ID (T->O)                 */
  TLR_UINT32  ulConConnId;           /*!< Consumer Connection ID (O->T)                 */

  TLR_UINT32  ulConnSerialNum;       /*!< Connection serial number                      */
  TLR_UINT16  usOrigVendorId;        /*!< Originator device vendor ID                   */
  TLR_UINT32  ulOrigDeviceSn;        /*!< Originator device serial number               */

  /* Producer parameters */
  TLR_UINT32  ulProApi;              /*!< Actual packet interval (usecs) (T->O)         */
  TLR_UINT16  usProConnParams;       /*!< Connection parameters (T->O) from ForwardOpen */

  /* Consumer parameters */
  TLR_UINT32  ulConApi;              /*!< Actual packet interval (usecs) (O->T)          */
  TLR_UINT16  usConConnParams;       /*!< Connection parameters (O->T)  from ForwardOpen */

  TLR_UINT8   bTimeoutMultiplier;    /*!< Connection timeout multiplier                  */

} __PACKED_POST EIP_OBJECT_EXT_CONNECTION_INFO_T;

typedef __PACKED_PRE struct EIP_OBJECT_CONNECTION_IND_Ttag
{

  TLR_UINT32 ulConnectionState;

  uint16_t usNumExclusiveOwner;
  uint16_t usNumInputOnly;
  uint16_t usNumListenOnly;
  uint16_t usNumExplicitMessaging;

  uint8_t   bConnType;
  uint8_t   abReserved[3];

  uint32_t  ulClass;
  uint32_t  ulInstance;
  uint32_t  ulOTConnectionPoints;
  uint32_t  ulTOConnectionPoints;

  uint16_t  usConnSerialNum;
  uint16_t  usVendorId;
  uint32_t  ulOSerialNum;

  uint8_t   bPriority;
  uint8_t   bTimeOutTicks;
  uint8_t   bTimeoutMultiple;
  uint8_t   bTriggerType;

  uint32_t  ulOTConnID;
  uint32_t  ulTOConnID;

  uint32_t  ulOTRpi;
  uint16_t  usOTConnParam;
  uint16_t  usOTConnSize;
  uint32_t  ulTORpi;
  uint16_t  usTOConnParam;
  uint16_t  usTOConnSize;

  uint32_t  ulProInhib;


  TLR_UINT32 ulExtendedState;          /*!< Extended status (see \ref EIP_EXT_CONNECTION_STATE_Ttag)          */

} __PACKED_POST EIP_OBJECT_CONNECTION_IND_T;

typedef struct __PACKED_PRE EIP_OBJECT_PACKET_CONNECTION_IND_Ttag
{
  TLR_PACKET_HEADER_T          tHead;
  EIP_OBJECT_CONNECTION_IND_T  tData;
} __PACKED_POST EIP_OBJECT_PACKET_CONNECTION_IND_T;

typedef struct EIP_OBJECT_PACKET_CONNECTION_RES_Ttag
{
  TLR_PACKET_HEADER_T     tHead;
}EIP_OBJECT_PACKET_CONNECTION_RES_T;

/* \} */
/*#####################################################################################*/
/*#####################################################################################*/
/*! \defgroup EIP_OBJECT_CL3_SERVICE_IND_Content Command related contents
 *  \ingroup EIP_OBJECT_CL3_SERVICE_IND
 * \{ */

typedef __PACKED_PRE struct EIP_OBJECT_CL3_SERVICE_IND_Ttag
{
  TLR_UINT32    ulConnectionId;          /*!< Connection Handle \n

                                           \description \n
                                           The connection handle uniquely identifies
                                           the connection. The same connection handle is
                                           used for all transmissions of a particular
                                           connection. \n\n
                                           <b>Important: \n</b>
                                           This handle must be used for the response to
                                           this indication */

  TLR_UINT32    ulService;               /*!< Service \n

                                           \description \n
                                           This parameter holds the requested CIP service
                                           that related to the next parameter (ulObject).\n\n
                                           <b>Important: \n</b>
                                           This parameter must be used again for the response
                                           to this indication */

  TLR_UINT32    ulObject;                /*!< Object class \n

                                           \description \n
                                           This parameter holds the CIP object class ID.\n\n
                                           <b>Important: \n</b>
                                           This parameter must be used again for the response
                                           to this indication */

  TLR_UINT32    ulInstance;              /*!< Instance \n

                                           \description \n
                                           This parameter holds the instance number
                                           of the object class specified in ulObject.\n\n
                                           <b>Important: \n</b>
                                           This parameter must be used again for the response
                                           to this indication */

  TLR_UINT32    ulAttribute;             /*!< Attribute \n

                                           \description \n
                                           This parameter holds the attribute number
                                           of the object class instance specified in
                                           ulInstance.\n\n
                                           <b>Important: \n</b>
                                           This parameter must be used again for the response
                                           to this indication */

  TLR_UINT8     abData[1];
}__PACKED_POST EIP_OBJECT_CL3_SERVICE_IND_T;


typedef __PACKED_PRE struct EIP_OBJECT_PACKET_CL3_SERVICE_IND_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
  EIP_OBJECT_CL3_SERVICE_IND_T    tData;
} __PACKED_POST EIP_OBJECT_PACKET_CL3_SERVICE_IND_T;

#define EIP_OBJECT_CL3_SERVICE_IND_SIZE (sizeof(EIP_OBJECT_CL3_SERVICE_IND_T)-1)


typedef __PACKED_PRE struct EIP_OBJECT_CL3_SERVICE_RES_Ttag
{
  TLR_UINT32    ulConnectionId;          /*!< Connection Handle \n

                                           \description \n
                                           The connection handle from the indication packet. */

  TLR_UINT32    ulService;               /*!< Service \n

                                           \description \n
                                           The service code from the indication packet. */

  TLR_UINT32    ulObject;                /*!< Object class \n

                                           \description \n
                                           The object class ID from the indication packet */

  TLR_UINT32    ulInstance;              /*!< Instance \n

                                           \description \n
                                           The instance number from the indication packet */

  TLR_UINT32    ulAttribute;             /*!< Attribute \n

                                           \description \n
                                           The attribute number from the indication packet */

  TLR_UINT32    ulGRC;                 /*!< Generic Error Code \n

                                           \description \n
                                            This generic error code can be used to
                                            indicate whether the service request was successful
                                            or unsuccessful. */

  TLR_UINT32    ulERC;                 /*!< Extended Error Code \n

                                           \description \n
                                           This extended error code can be used to
                                           describe the occurred error (GRC) in more detail. */

  TLR_UINT8     abData[1];             /*!< Response service  data */

}__PACKED_POST EIP_OBJECT_CL3_SERVICE_RES_T;


typedef __PACKED_PRE struct EIP_OBJECT_PACKET_CL3_SERVICE_RES_Ttag
{
  TLR_PACKET_HEADER_T            tHead;
  EIP_OBJECT_CL3_SERVICE_RES_T   tData;
} __PACKED_POST EIP_OBJECT_PACKET_CL3_SERVICE_RES_T;


#define EIP_OBJECT_CL3_SERVICE_RES_SIZE (sizeof(EIP_OBJECT_CL3_SERVICE_RES_T)-1)
/*! \}*/
/*#####################################################################################*/
/*#####################################################################################*/
/*! \defgroup EIP_OBJECT_REGISTER_SERVICE_REQ_Content Command related contents
 *  \ingroup EIP_OBJECT_REGISTER_SERVICE_REQ
 * \{*/

typedef  __PACKED_PRE struct EIP_OBJECT_REGISTER_SERVICE_REQ_Ttag
{
  TLR_UINT32 ulService;                /*!< Service code \n

                                      \valueRange \n\n
                                       Instances of the Assembly Object are divided into the following address ranges to \n
                                       provide for extensions to device profiles \n\n

                                       0x00 - 0x31 : Open. These are referred to as Common Services.
                                                     These are defined in the EtherNet/IP spec. Vol.1 Appendix A.\n
                                       0x32 - 0x4A : Vendor Specific                        \n
                                       0x4B - 0x63 : Object Class Specific                  \n
                                       0x64 - 0x7F : Reserved by ODVA for future use        \n
                                       0x80 - 0xFF : Reserved for use as Reply Service Code \n

                                       \description \n\n
                                       Pre-defined service codes (hex): \n\n
                                       00:    Reserved \n
                                       01:    Get_Attributes_All \n
                                       02:    Set_Attributes_All \n
                                       03:    Get_Attribute_List \n
                                       04:    Set_Attribute_List \n
                                       05:    Reset \n
                                       06:    Start \n
                                       07:    Stop \n
                                       08:    Create \n
                                       09:    Delete \n
                                       0A:    Multiple_Service_Packet \n
                                       0B:    Reserved for future use \n
                                       0D:    Apply_Attributes \n
                                       0E:    Get_Attribute_Single \n
                                       0F:    Reserved for future use \n
                                       10:   Set_Attribute_Single \n
                                       11:    Find_Next_Object_Instance \n
                                       12-13: Reserved for future use \n
                                       14:    Error Response (used by DevNet only) \n
                                       15:    Restore \n
                                       16:    Save \n
                                       17:    No Operation (NOP) \n
                                       18:    Get_Member \n
                                       19:    Set_Member \n
                                       1A:    Insert_Member \n
                                       1B:    Remove_Member \n
                                       1C:    GroupSync \n
                                       1D-31: Reserved for additional Common Services \n */


}__PACKED_POST EIP_OBJECT_REGISTER_SERVICE_REQ_T;

/* command for register a new object to the message router */
typedef  __PACKED_PRE struct EIP_OBJECT_PACKET_REGISTER_SERVICE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  EIP_OBJECT_REGISTER_SERVICE_REQ_T  tData;
}__PACKED_POST EIP_OBJECT_PACKET_REGISTER_SERVICE_REQ_T;

#define EIP_OBJECT_REGISTER_SERVICE_REQ_SIZE (sizeof(EIP_OBJECT_REGISTER_SERVICE_REQ_T))

typedef  __PACKED_PRE struct EIP_OBJECT_PACKET_REGISTER_SERVICE_CNF_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
}__PACKED_POST EIP_OBJECT_PACKET_REGISTER_SERVICE_CNF_T;

#define EIP_OBJECT_REGISTER_SERVICE_CNF_SIZE 0
/*! \}*/
/*#####################################################################################*/
/*#####################################################################################*/
/*! \defgroup EIP_OBJECT_CIP_SERVICE_REQ_Content  Command related contents
 *  \ingroup EIP_OBJECT_CIP_SERVICE_REQ
 *  \{ */

typedef __PACKED_PRE struct EIP_OBJECT_CIP_SERVICE_REQ_Ttag
{
  TLR_UINT32    ulService;                          /*!< CIP service code          */
  TLR_UINT32    ulClass;                            /*!< CIP class ID              */
  TLR_UINT32    ulInstance;                         /*!< CIP instance number       */
  TLR_UINT32    ulAttribute;                        /*!< CIP attribute number      */
  TLR_UINT8     abData[EIP_OBJECT_MAX_PACKET_LEN];  /*!< CIP Service Data. <br><br>
                                                         Number of bytes provided in this field
                                                         must be add to the packet header length field
                                                         ulLen.
                                                         Do the following to set the proper packet length:<br>
                                                         ptReq->tHead.ulLen = EIP_OBJECT_CIP_SERVICE_REQ_SIZE + number of bytes provided in abData */
}__PACKED_POST EIP_OBJECT_CIP_SERVICE_REQ_T;


typedef __PACKED_PRE struct EIP_OBJECT_PACKET_CIP_SERVICE_REQ_Ttag
{
  TLR_PACKET_HEADER_T            tHead;
  EIP_OBJECT_CIP_SERVICE_REQ_T   tData;
}__PACKED_POST EIP_OBJECT_PACKET_CIP_SERVICE_REQ_T;

#define EIP_OBJECT_CIP_SERVICE_REQ_SIZE     (sizeof(EIP_OBJECT_CIP_SERVICE_REQ_T) - EIP_OBJECT_MAX_PACKET_LEN)

typedef __PACKED_PRE struct EIP_OBJECT_CIP_SERVICE_CNF_Ttag
{
  TLR_UINT32    ulService;                          /*!< CIP service code          */
  TLR_UINT32    ulClass;                            /*!< CIP class ID              */
  TLR_UINT32    ulInstance;                         /*!< CIP instance number       */
  TLR_UINT32    ulAttribute;                        /*!< CIP attribute number      */

  TLR_UINT32    ulGRC;                              /*!< Generic Error Code        */
  TLR_UINT32    ulERC;                              /*!< Extended Error Code       */

  TLR_UINT8     abData[EIP_OBJECT_MAX_PACKET_LEN];  /*!< CIP service data. <br><br>
                                                         Number of bytes provided in this field
                                                         is encoded in the packet header length field
                                                         ulLen. <br><br>
                                                         Do the following to get the data size:<br>
                                                         ulSize = ptCnf->tHead.ulLen - EIP_OBJECT_CIP_SERVICE_CNF_SIZE */

}__PACKED_POST EIP_OBJECT_CIP_SERVICE_CNF_T;


typedef struct EIP_OBJECT_PACKET_CIP_SERVICE_CNF_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
  EIP_OBJECT_CIP_SERVICE_CNF_T    tData;
}EIP_OBJECT_PACKET_CIP_SERVICE_CNF_T;

#define EIP_OBJECT_CIP_SERVICE_CNF_SIZE     (sizeof(EIP_OBJECT_CIP_SERVICE_CNF_T)) - EIP_OBJECT_MAX_PACKET_LEN

/* \} */
/*#####################################################################################*/
/*#####################################################################################*/
/*! \defgroup EIP_OBJECT_CIP_OBJECT_CHANGE_IND_Content  Command related contents
 *  \ingroup EIP_OBJECT_CIP_OBJECT_CHANGE_IND
 *  \{ */

/* Signals that the attached data must be stored in non-volatile memory  */
#define EIP_CIP_OBJECT_CHANGE_FLAG_STORE_REMANENT    0x00000001

/* Signal that the object change was done internally. So no service from
   the network has triggered the change indication.
   e.g.: This flag is used when the IP configuration has been applied
         the first time on startup.                                      */
#define EIP_CIP_OBJECT_CHANGE_FLAG_INTERNAL          0x00000002

typedef __PACKED_PRE struct EIP_OBJECT_CIP_OBJECT_CHANGE_IND_Ttag
{
  TLR_UINT32    ulInfoFlags;                        /*!< Information flags     */
  TLR_UINT32    ulService;                          /*!< CIP service code      */
  TLR_UINT32    ulClass;                            /*!< CIP class ID          */
  TLR_UINT32    ulInstance;                         /*!< CIP instance number   */
  TLR_UINT32    ulAttribute;                        /*!< CIP attribute number  */
  TLR_UINT8     abData[EIP_OBJECT_MAX_PACKET_LEN];  /*!< Service Data          */

}__PACKED_POST EIP_OBJECT_CIP_OBJECT_CHANGE_IND_T;


typedef __PACKED_PRE struct EIP_OBJECT_PACKET_CIP_OBJECT_CHANGE_IND_Ttag
{
  TLR_PACKET_HEADER_T                  tHead;
  EIP_OBJECT_CIP_OBJECT_CHANGE_IND_T   tData;
} __PACKED_POST EIP_OBJECT_PACKET_CIP_OBJECT_CHANGE_IND_T;

#define EIP_OBJECT_CIP_OBJECT_CHANGE_IND_SIZE     (sizeof(EIP_OBJECT_CIP_OBJECT_CHANGE_IND_T) - EIP_OBJECT_MAX_PACKET_LEN)


typedef struct EIP_OBJECT_PACKET_CIP_OBJECT_CHANGE_RES_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
}EIP_OBJECT_PACKET_CIP_OBJECT_CHANGE_RES_T;

#define EIP_OBJECT_CIP_OBJECT_CHANGE_RES_SIZE    0

/* \} */
/*#####################################################################################*/
/*#####################################################################################*/
/*! \defgroup EIP_APS_CONFIG_DONE_REQ_Content Command related contents
 *  \ingroup EIP_APS_CONFIG_DONE_REQ
 * \{*/

/* command for register a new object to the message router */
typedef  __PACKED_PRE struct EIP_APS_PACKET_CONFIG_DONE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
}__PACKED_POST EIP_APS_PACKET_CONFIG_DONE_REQ_T;

#define EIP_APS_CONFIG_DONE_REQ_SIZE 0

typedef  __PACKED_PRE struct EIP_APS_PACKET_CONFIG_DONE_CNF_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
}__PACKED_POST EIP_APS_PACKET_CONFIG_DONE_CNF_T;

#define EIP_APS_CONFIG_DONE_CNF_SIZE 0
/*! \}*/
/*#####################################################################################*/

/*#####################################################################################*/
#define EIP_APS_CONFIGURATION_PARAMETER_SET_V1         1

typedef __PACKED_PRE struct EIP_APS_CONFIGURATION_PARAMETER_SET_V1_Ttag
{

  TLR_UINT32  ulSystemFlags;    /*!< Reserved for IO status */
  TLR_UINT32  ulWdgTime;        /*!< Watch dog time (in milliseconds) <br>

                                     \valueRange
                                     0, 20...65535\n
                                     Default: 1000

                                     \description
                                     Value 0 switches off the watch dog */

  TLR_UINT32  ulInputLen;       /*!< Length of input data (Input Assembly)\n

                                     \valueRange
                                     0...504 \n
                                     Default: 16

                                     \description
                                     Defines the input data size and corresponds directly
                                     to the input assembly instance provided by ulInputAssInstance */
  TLR_UINT32  ulOutputLen;      /*!< Length of Output data (Output Assembly)\n

                                     \valueRange
                                     0...504 \n
                                     Default: 16

                                     \description
                                     Defines the output data size and corresponds directly
                                     to the input assembly instance provided by ulOutputAssInstance */

  TLR_UINT32  ulTcpFlag;        /*!< TCP configuration flags\n

                                     \valueRange
                                     Default: 0x00000410 (DHCP and Auto-Negotiation)

                                     \description
                                     For further information see TCPIP-Manual */
  TLR_UINT32  ulIpAddr;         /*!< IP address \n
                                     \valueRange
                                     All valid IP addresses\n
                                     Default: 0.0.0.0 */
  TLR_UINT32  ulNetMask;        /*!< Network mask \n

                                     \valueRange
                                     All valid masks\n
                                     Default: 0.0.0.0 */
  TLR_UINT32  ulGateway;        /*!< Gateway address \n

                                     \valueRange
                                     All valid IP addresses\n
                                     Default: 0.0.0.0 */

  TLR_UINT16  usVendId;         /*!< CIP vendor identification \n

                                     \valueRange
                                     1...65535 \n
                                     Default: 283 (Hilscher GmbH)

                                     \description
                                     This is an identification number for
                                     the manufacturer of an EtherNet/IP device.
                                     Vendor IDs are managed by ODVA.
                                     The value zero is not valid */
  TLR_UINT16  usProductType;    /*!< CIP device type \n

                                     \valueRange
                                     Publicly defined: 0x00 - 0x64    \n
                                     Vendor specific: 0x64 - 0xC7     \n
                                     Reserved by CIP: 0xC8 - 0xFF     \n
                                     Publicly defined: 0x100 - 0x2FF  \n
                                     Vendor specific: 0x300 - 0x4FF   \n
                                     Reserved by CIP: 0x500 - 0xFFFF  \n\n
                                     Default: 0x0C (Communication Device)

                                     \description
                                     The list of device types is managed by ODVA.
                                     It is used to identify the device profile that a
                                     particular product is using. Device profiles
                                     define minimum requirements a device must
                                     implement as well as common options. */
  TLR_UINT16  usProductCode;    /*!< Product code \n

                                     \valueRange
                                     1...65535

                                     \description
                                     The vendor assigned Product Code identifies a particular product within a device type. Each
                                     vendor assigns this code to each of its products. The Product Code typically maps to one or
                                     more catalog/model numbers. Products shall have different codes if their configuration and/or
                                     runtime options are different. Such devices present a different logical view to the network. On
                                     the other hand for example, two products that are the same except for their color or mounting
                                     feet are the same logically and may share the same product code.
                                     The value zero is not valid. */

  TLR_UINT32  ulSerialNumber;   /*!< Serial number \n

                                     \valueRange
                                     0x00000000... 0xFFFFFFFF

                                     \description
                                     This attribute is a number used in conjunction with the Vendor ID to form a unique identifier
                                     for each device on any CIP network. Each vendor is responsible for guaranteeing the
                                     uniqueness of the serial number across all of its devices. \n
                                     Usually, this number will be set automatically by the firmware,
                                     if a security memory is available. */

  TLR_UINT8   bMinorRev;        /*!< Minor revision \n

                                     \valueRange
                                     1...255 */

  TLR_UINT8   bMajorRev;        /*!< Major revision \n

                                     \valueRange
                                     1...127 */

  TLR_UINT8   abDeviceName[32]; /*!< Device name\n

                                     \description
                                     This text string should represent a short description of the product/product family represented
                                     by the product code. The same product code may have a variety of product name
                                     strings.\n\n
                                     The first byte indicates the name length, byte
                                     2-31 contain the actual characters of the device name.*/

  TLR_UINT32  ulInputAssInstance;   /*!< Instance number of input assembly\n

                                     \valueRange \n\n
                                     Instances of the Assembly Object are divided into the following address ranges to \n
                                     provide for extensions to device profiles \n\n
                                     0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                     0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                     0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)      \n
                                     0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                     \description
                                     This parameter defines the instance number of the input assembly.

                                     */

  TLR_UINT32  ulInputAssFlags;      /*!< Input assembly flags\n

                                      \valueRange \n

                                       - <b> Bit 0:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 1:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 2:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 3:</b> \n
                                         If set, the assembly data is modeless
                                         (i.e. it does <b>not</b> contain run/idle information) \n\n

                                       - <b> Bit 4:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 5:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 6:</b> \n
                                         This flag decides whether the data that is mapped into the
                                         DPM memory area is cleared upon closing of
                                         the connection or whether the last sent/received data is left
                                         unchanged in the memory.
                                         If the bit is set the data will be left unchanged.\n\n
                                     */


  TLR_UINT32  ulOutputAssInstance;  /*!< Instance number of output assembly\n

                                     \valueRange \n\n
                                     Instances of the Assembly Object are divided into the following address ranges to \n
                                     provide for extensions to device profiles \n\n
                                     0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                     0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                     0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)      \n
                                     0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                     \description
                                     This parameter defines the instance number of the output assembly.

                                     */

  TLR_UINT32   ulOutputAssFlags;     /*!< Output assembly flags\n

                                      \valueRange \n
                                      See description of ulInputAssFlags
                                     */

  EIP_DPMINTF_QOS_CONFIG_T tQoS_Config; /*!< Quality of Service \n

                                          \description

                                           This parameter set configures the Quality of Service Object
                                           (CIP Id 0x48).
                                           For more information about specific parameters see command
                                           EIP_OBJECT_CFG_QOS_REQ.

                                         */

  TLR_UINT32   ulNameServer;         /*!< Name Server 1\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        Default value: 0.0.0.0
                                     */

  TLR_UINT32   ulNameServer_2;       /*!< Name Server 2\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        Default value: 0.0.0.0
                                      */

  TLR_UINT8    abDomainName[48 + 2]; /*!< Domain Name\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).
                                        The first two bytes of the name provide the length of the name.

                                        \valueRange \n
                                        Default value: No Name ("") \n
                                        Max. name length is 48 bytes

                                      */

  TLR_UINT8    abHostName[64+2];     /*!< Host Name\n

                                       \description
                                        This parameter corresponds to attribute 6 of the
                                        TCP Interface Object (CIP Id 0xF5).
                                        The first two bytes of the name provide the length of the name.

                                        \valueRange \n
                                        Default value: No Name ("") \n
                                        Max. name length is 64 bytes
                                      */

  TLR_UINT8    bSelectAcd;           /*!< Select ACD

                                         \description
                                        This parameter corresponds to attribute 10 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        1: ACD on (default) \n
                                        0: ACD off

                                      */

  EIP_DPMINTF_TI_ACD_LAST_CONFLICT_T  tLastConflictDetected; /*!< Last detected conflict\n

                                                               \description
                                                               This parameter corresponds to attribute 11 of the
                                                               TCP Interface Object (CIP Id 0xF5).

                                                               \valueRange \n
                                                               Default: All zero
                                                             */

  TLR_UINT8                           bQuickConnectFlags; /*!< Quick Connect flags \n

                                                               \description
                                                               This parameter enables/disables the Quick Connect
                                                               functionality within the stack.
                                                               This affects the TCP Interface Object (0xF5)
                                                               attribute 12. \n\n
                                                               \Note: This functionality needs special hardware settings (e.g. fast
                                                               flash)

                                                               \valueRange \n
                                                               See: \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               and  \ref EIP_OBJECT_QC_FLAGS_ENABLE_QC

                                                               <b>Examples:</b>\n\n
                                                               Do not support Quick Connect:\n
                                                               Set to zero \n\n

                                                               Support Quick Connect - Quick Connect disabled:\n
                                                               Set only flag \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               in order to activate the Quick Connect attribute within the object.\n\n

                                                               Support Quick Connect - Quick Connect enabled:\n
                                                               Set flag \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               and flag \ref EIP_OBJECT_QC_FLAGS_ENABLE_QC in order to
                                                               activate the attribute and simultaneously enable the
                                                               Quick Connection functionality.\n\n
                                                             */

}__PACKED_POST  EIP_APS_CONFIGURATION_PARAMETER_SET_V1_T;

#define EIP_APS_CONFIGURATION_PARAMETER_SET_V1_SIZE (sizeof(EIP_APS_CONFIGURATION_PARAMETER_SET_V1_T) )

/*#####################################################################################*/
#define EIP_APS_CONFIGURATION_PARAMETER_SET_V2         2

typedef __PACKED_PRE struct EIP_APS_CONFIGURATION_PARAMETER_SET_V2_Ttag
{

  TLR_UINT32  ulSystemFlags;    /*!< Reserved for IO status */
  TLR_UINT32  ulWdgTime;        /*!< Watch dog time (in milliseconds) <br>

                                     \valueRange
                                     0, 20...65535\n
                                     Default: 1000

                                     \description
                                     Value 0 switches off the watch dog */

  TLR_UINT32  ulInputLen;       /*!< Length of input data (Input Assembly)\n

                                     \valueRange
                                     0...504 \n
                                     Default: 16

                                     \description
                                     Defines the input data size and corresponds directly
                                     to the input assembly instance provided by ulInputAssInstance */
  TLR_UINT32  ulOutputLen;      /*!< Length of Output data (Output Assembly)\n

                                     \valueRange
                                     0...504 \n
                                     Default: 16

                                     \description
                                     Defines the output data size and corresponds directly
                                     to the input assembly instance provided by ulOutputAssInstance */

  TLR_UINT32  ulTcpFlag;        /*!< TCP configuration flags\n

                                     \valueRange
                                     Default: 0x00000410 (DHCP and Auto-Negotiation)

                                     \description
                                     For further information see TCPIP-Manual */
  TLR_UINT32  ulIpAddr;         /*!< IP address \n
                                     \valueRange
                                     All valid IP addresses\n
                                     Default: 0.0.0.0 */
  TLR_UINT32  ulNetMask;        /*!< Network mask \n

                                     \valueRange
                                     All valid masks\n
                                     Default: 0.0.0.0 */
  TLR_UINT32  ulGateway;        /*!< Gateway address \n

                                     \valueRange
                                     All valid IP addresses\n
                                     Default: 0.0.0.0 */

  TLR_UINT16  usVendId;         /*!< CIP vendor identification \n

                                     \valueRange
                                     1...65535 \n
                                     Default: 283 (Hilscher GmbH)

                                     \description
                                     This is an identification number for
                                     the manufacturer of an EtherNet/IP device.
                                     Vendor IDs are managed by ODVA.
                                     The value zero is not valid */
  TLR_UINT16  usProductType;    /*!< CIP device type \n

                                     \valueRange
                                     Publicly defined: 0x00 - 0x64    \n
                                     Vendor specific: 0x64 - 0xC7     \n
                                     Reserved by CIP: 0xC8 - 0xFF     \n
                                     Publicly defined: 0x100 - 0x2FF  \n
                                     Vendor specific: 0x300 - 0x4FF   \n
                                     Reserved by CIP: 0x500 - 0xFFFF  \n\n
                                     Default: 0x0C (Communication Device)

                                     \description
                                     The list of device types is managed by ODVA.
                                     It is used to identify the device profile that a
                                     particular product is using. Device profiles
                                     define minimum requirements a device must
                                     implement as well as common options. */
  TLR_UINT16  usProductCode;    /*!< Product code \n

                                     \valueRange
                                     1...65535

                                     \description
                                     The vendor assigned Product Code identifies a particular product within a device type. Each
                                     vendor assigns this code to each of its products. The Product Code typically maps to one or
                                     more catalog/model numbers. Products shall have different codes if their configuration and/or
                                     runtime options are different. Such devices present a different logical view to the network. On
                                     the other hand for example, two products that are the same except for their color or mounting
                                     feet are the same logically and may share the same product code.
                                     The value zero is not valid. */

  TLR_UINT32  ulSerialNumber;   /*!< Serial number \n

                                     \valueRange
                                     0x00000000... 0xFFFFFFFF

                                     \description
                                     This attribute is a number used in conjunction with the Vendor ID to form a unique identifier
                                     for each device on any CIP network. Each vendor is responsible for guaranteeing the
                                     uniqueness of the serial number across all of its devices. \n
                                     Usually, this number will be set automatically by the firmware,
                                     if a security memory is available. */

  TLR_UINT8   bMinorRev;        /*!< Minor revision \n

                                     \valueRange
                                     1...255 */

  TLR_UINT8   bMajorRev;        /*!< Major revision \n

                                     \valueRange
                                     1...127 */

  TLR_UINT8   abDeviceName[32]; /*!< Device name\n

                                     \description
                                     This text string should represent a short description of the product/product family represented
                                     by the product code. The same product code may have a variety of product name
                                     strings.\n\n
                                     The first byte indicates the name length, byte
                                     2-31 contain the actual characters of the device name.*/

  TLR_UINT32  ulInputAssInstance;   /*!< Instance number of input assembly\n

                                     \valueRange \n\n
                                     Instances of the Assembly Object are divided into the following address ranges to \n
                                     provide for extensions to device profiles \n\n
                                     0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                     0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                     0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)      \n
                                     0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                     \description
                                     This parameter defines the instance number of the input assembly.

                                     */

  TLR_UINT32  ulInputAssFlags;      /*!< Input assembly flags\n

                                      \valueRange \n

                                       - <b> Bit 0:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 1:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 2:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 3:</b> \n
                                         If set, the assembly data is modeless
                                         (i.e. it does <b>not</b> contain run/idle information) \n\n

                                       - <b> Bit 4:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 5:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 6:</b> \n
                                         This flag decides whether the data that is mapped into the
                                         DPM memory area is cleared upon closing of
                                         the connection or whether the last sent/received data is left
                                         unchanged in the memory.
                                         If the bit is set the data will be left unchanged.\n\n
                                     */


  TLR_UINT32  ulOutputAssInstance;  /*!< Instance number of output assembly\n

                                     \valueRange \n\n
                                     Instances of the Assembly Object are divided into the following address ranges to \n
                                     provide for extensions to device profiles \n\n
                                     0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                     0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                     0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)      \n
                                     0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                     \description
                                     This parameter defines the instance number of the output assembly.

                                     */

  TLR_UINT32   ulOutputAssFlags;     /*!< Output assembly flags\n

                                      \valueRange \n
                                      See description of ulInputAssFlags
                                     */

  EIP_DPMINTF_QOS_CONFIG_T tQoS_Config; /*!< Quality of Service \n

                                          \description

                                           This parameter set configures the Quality of Service Object
                                           (CIP Id 0x48).
                                           For more information about specific parameters see command
                                           EIP_OBJECT_CFG_QOS_REQ.

                                         */

  TLR_UINT32   ulNameServer;         /*!< Name Server 1\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        Default value: 0.0.0.0
                                     */

  TLR_UINT32   ulNameServer_2;       /*!< Name Server 2\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        Default value: 0.0.0.0
                                      */

  TLR_UINT8    abDomainName[48 + 2]; /*!< Domain Name\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).
                                        The first two bytes of the name provide the length of the name.

                                        \valueRange \n
                                        Default value: No Name ("") \n
                                        Max. name length is 48 bytes

                                      */

  TLR_UINT8    abHostName[64+2];     /*!< Host Name\n

                                       \description
                                        This parameter corresponds to attribute 6 of the
                                        TCP Interface Object (CIP Id 0xF5).
                                        The first two bytes of the name provide the length of the name.

                                        \valueRange \n
                                        Default value: No Name ("") \n
                                        Max. name length is 64 bytes
                                      */

  TLR_UINT8    bSelectAcd;           /*!< Select ACD

                                         \description
                                        This parameter corresponds to attribute 10 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        1: ACD on (default) \n
                                        0: ACD off

                                      */

  EIP_DPMINTF_TI_ACD_LAST_CONFLICT_T  tLastConflictDetected; /*!< Last detected conflict\n

                                                               \description
                                                               This parameter corresponds to attribute 11 of the
                                                               TCP Interface Object (CIP Id 0xF5).

                                                               \valueRange \n
                                                               Default: All zero
                                                             */

  TLR_UINT8                           bQuickConnectFlags; /*!< Quick Connect flags \n

                                                               \description
                                                               This parameter enables/disables the Quick Connect
                                                               functionality within the stack.
                                                               This affects the TCP Interface Object (0xF5)
                                                               attribute 12. \n\n
                                                               \Note: This functionality needs special hardware settings (e.g. fast
                                                               flash)

                                                               \valueRange \n
                                                               See: \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               and  \ref EIP_OBJECT_QC_FLAGS_ENABLE_QC

                                                               <b>Examples:</b>\n\n
                                                               Do not support Quick Connect:\n
                                                               Set to zero \n\n

                                                               Support Quick Connect - Quick Connect disabled:\n
                                                               Set only flag \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               in order to activate the Quick Connect attribute within the object.\n\n

                                                               Support Quick Connect - Quick Connect enabled:\n
                                                               Set flag \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               and flag \ref EIP_OBJECT_QC_FLAGS_ENABLE_QC in order to
                                                               activate the attribute and simultaneously enable the
                                                               Quick Connection functionality.\n\n
                                                             */


  /* New parameters for packet V2 start here **************/

  TLR_UINT8                           abAdminState[2];       /*!< Admin State \n

                                                               \description
                                                               This parameter corresponds to attribute 9 of the
                                                               Ethernet Link Object (CIP Id 0xFF).
                                                               The Admin State attribute shall allow administrative
                                                               setting of the interface state. The interface (PHYs) can be
                                                               enabled or disabled.
                                                               Each array entry stands for one ethernet port.
                                                               This attribute shall be stored in non-volatile memory.

                                                               \valueRange \n
                                                               0x01: Interface enabled
                                                               0x02: Interface disabled
                                                               Default: Both entries 0x01 (enabled)
                                                             */

}__PACKED_POST  EIP_APS_CONFIGURATION_PARAMETER_SET_V2_T;

#define EIP_APS_CONFIGURATION_PARAMETER_SET_V2_SIZE (sizeof(EIP_APS_CONFIGURATION_PARAMETER_SET_V2_T) )

/*#####################################################################################*/
#define EIP_APS_CONFIGURATION_PARAMETER_SET_V3         3

typedef __PACKED_PRE struct EIP_APS_CONFIGURATION_PARAMETER_SET_V3_Ttag
{

  TLR_UINT32  ulSystemFlags;    /*!< Reserved for IO status */
  TLR_UINT32  ulWdgTime;        /*!< Watch dog time (in milliseconds) <br>

                                     \valueRange
                                     0, 20...65535\n
                                     Default: 1000

                                     \description
                                     Value 0 switches off the watch dog */

  TLR_UINT32  ulInputLen;       /*!< Length of input data (Input Assembly)\n

                                     \valueRange
                                     0...504 \n
                                     Default: 16

                                     \description
                                     Defines the input data size and corresponds directly
                                     to the input assembly instance provided by ulInputAssInstance */
  TLR_UINT32  ulOutputLen;      /*!< Length of Output data (Output Assembly)\n

                                     \valueRange
                                     0...504 \n
                                     Default: 16

                                     \description
                                     Defines the output data size and corresponds directly
                                     to the input assembly instance provided by ulOutputAssInstance */

  TLR_UINT32  ulTcpFlag;        /*!< TCP configuration flags\n

                                     \valueRange
                                     Default: 0x00000410 (DHCP and Auto-Negotiation)

                                     \description
                                     For further information see TCPIP-Manual */
  TLR_UINT32  ulIpAddr;         /*!< IP address \n
                                     \valueRange
                                     All valid IP addresses\n
                                     Default: 0.0.0.0 */
  TLR_UINT32  ulNetMask;        /*!< Network mask \n

                                     \valueRange
                                     All valid masks\n
                                     Default: 0.0.0.0 */
  TLR_UINT32  ulGateway;        /*!< Gateway address \n

                                     \valueRange
                                     All valid IP addresses\n
                                     Default: 0.0.0.0 */

  TLR_UINT16  usVendId;         /*!< CIP vendor identification \n

                                     \valueRange
                                     1...65535 \n
                                     Default: 283 (Hilscher GmbH)

                                     \description
                                     This is an identification number for
                                     the manufacturer of an EtherNet/IP device.
                                     Vendor IDs are managed by ODVA.
                                     The value zero is not valid */
  TLR_UINT16  usProductType;    /*!< CIP device type \n

                                     \valueRange
                                     Publicly defined: 0x00 - 0x64    \n
                                     Vendor specific: 0x64 - 0xC7     \n
                                     Reserved by CIP: 0xC8 - 0xFF     \n
                                     Publicly defined: 0x100 - 0x2FF  \n
                                     Vendor specific: 0x300 - 0x4FF   \n
                                     Reserved by CIP: 0x500 - 0xFFFF  \n\n
                                     Default: 0x0C (Communication Device)

                                     \description
                                     The list of device types is managed by ODVA.
                                     It is used to identify the device profile that a
                                     particular product is using. Device profiles
                                     define minimum requirements a device must
                                     implement as well as common options. */
  TLR_UINT16  usProductCode;    /*!< Product code \n

                                     \valueRange
                                     1...65535

                                     \description
                                     The vendor assigned Product Code identifies a particular product within a device type. Each
                                     vendor assigns this code to each of its products. The Product Code typically maps to one or
                                     more catalog/model numbers. Products shall have different codes if their configuration and/or
                                     runtime options are different. Such devices present a different logical view to the network. On
                                     the other hand for example, two products that are the same except for their color or mounting
                                     feet are the same logically and may share the same product code.
                                     The value zero is not valid. */

  TLR_UINT32  ulSerialNumber;   /*!< Serial number \n

                                     \valueRange
                                     0x00000000... 0xFFFFFFFF

                                     \description
                                     This attribute is a number used in conjunction with the Vendor ID to form a unique identifier
                                     for each device on any CIP network. Each vendor is responsible for guaranteeing the
                                     uniqueness of the serial number across all of its devices. \n
                                     Usually, this number will be set automatically by the firmware,
                                     if a security memory is available. */

  TLR_UINT8   bMinorRev;        /*!< Minor revision \n

                                     \valueRange
                                     1...255 */

  TLR_UINT8   bMajorRev;        /*!< Major revision \n

                                     \valueRange
                                     1...127 */

  TLR_UINT8   abDeviceName[32]; /*!< Device name\n

                                     \description
                                     This text string should represent a short description of the product/product family represented
                                     by the product code. The same product code may have a variety of product name
                                     strings.\n\n
                                     The first byte indicates the name length, byte
                                     2-31 contain the actual characters of the device name.*/

  TLR_UINT32  ulInputAssInstance;   /*!< Instance number of input assembly\n

                                     \valueRange \n\n
                                     Instances of the Assembly Object are divided into the following address ranges to \n
                                     provide for extensions to device profiles \n\n
                                     0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                     0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                     0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)      \n
                                     0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                     \description
                                     This parameter defines the instance number of the input assembly.

                                     */

  TLR_UINT32  ulInputAssFlags;      /*!< Input assembly flags\n

                                      \valueRange \n

                                       - <b> Bit 0:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 1:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 2:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 3:</b> \n
                                         If set, the assembly data is modeless
                                         (i.e. it does <b>not</b> contain run/idle information) \n\n

                                       - <b> Bit 4:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 5:</b> \n
                                         This flag is used internally and must be set to 0 \n\n

                                       - <b> Bit 6:</b> \n
                                         This flag decides whether the data that is mapped into the
                                         DPM memory area is cleared upon closing of
                                         the connection or whether the last sent/received data is left
                                         unchanged in the memory.
                                         If the bit is set the data will be left unchanged.\n\n
                                     */


  TLR_UINT32  ulOutputAssInstance;  /*!< Instance number of output assembly\n

                                     \valueRange \n\n
                                     Instances of the Assembly Object are divided into the following address ranges to \n
                                     provide for extensions to device profiles \n\n
                                     0x00000001 - 0x00000063 : Open (static assemblies defined in device profile)       \n
                                     0x00000064 - 0x000000C7 : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x000000C8 - 0x000002FF : Open (static assemblies defined in device profile)       \n
                                     0x00000300 - 0x000004FF : Vendor Specific static assemblies and dynamic assemblies \n
                                     0x00000500 - 0x000FFFFF : Open (static assemblies defined in device profile)      \n
                                     0x00100000 - 0xFFFFFFFF : Reserved by CIP for future use.

                                     \description
                                     This parameter defines the instance number of the output assembly.

                                     */

  TLR_UINT32   ulOutputAssFlags;     /*!< Output assembly flags\n

                                      \valueRange \n
                                      See description of ulInputAssFlags
                                     */

  EIP_DPMINTF_QOS_CONFIG_T tQoS_Config; /*!< Quality of Service \n

                                          \description

                                           This parameter set configures the Quality of Service Object
                                           (CIP Id 0x48).
                                           For more information about specific parameters see command
                                           EIP_OBJECT_CFG_QOS_REQ.

                                         */

  TLR_UINT32   ulNameServer;         /*!< Name Server 1\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        Default value: 0.0.0.0
                                     */

  TLR_UINT32   ulNameServer_2;       /*!< Name Server 2\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        Default value: 0.0.0.0
                                      */

  TLR_UINT8    abDomainName[48 + 2]; /*!< Domain Name\n

                                       \description
                                        This parameter corresponds to an entry of attribute 5 of the
                                        TCP Interface Object (CIP Id 0xF5).
                                        The first two bytes of the name provide the length of the name.

                                        \valueRange \n
                                        Default value: No Name ("") \n
                                        Max. name length is 48 bytes

                                      */

  TLR_UINT8    abHostName[64+2];     /*!< Host Name\n

                                       \description
                                        This parameter corresponds to attribute 6 of the
                                        TCP Interface Object (CIP Id 0xF5).
                                        The first two bytes of the name provide the length of the name.

                                        \valueRange \n
                                        Default value: No Name ("") \n
                                        Max. name length is 64 bytes
                                      */

  TLR_UINT8    bSelectAcd;           /*!< Select ACD

                                         \description
                                        This parameter corresponds to attribute 10 of the
                                        TCP Interface Object (CIP Id 0xF5).

                                        \valueRange \n
                                        1: ACD on (default) \n
                                        0: ACD off

                                      */

  EIP_DPMINTF_TI_ACD_LAST_CONFLICT_T  tLastConflictDetected; /*!< Last detected conflict\n

                                                               \description
                                                               This parameter corresponds to attribute 11 of the
                                                               TCP Interface Object (CIP Id 0xF5).

                                                               \valueRange \n
                                                               Default: All zero
                                                             */

  TLR_UINT8                           bQuickConnectFlags; /*!< Quick Connect flags \n

                                                               \description
                                                               This parameter enables/disables the Quick Connect
                                                               functionality within the stack.
                                                               This affects the TCP Interface Object (0xF5)
                                                               attribute 12. \n\n
                                                               \Note: This functionality needs special hardware settings (e.g. fast
                                                               flash)

                                                               \valueRange \n
                                                               See: \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               and  \ref EIP_OBJECT_QC_FLAGS_ENABLE_QC

                                                               <b>Examples:</b>\n\n
                                                               Do not support Quick Connect:\n
                                                               Set to zero \n\n

                                                               Support Quick Connect - Quick Connect disabled:\n
                                                               Set only flag \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               in order to activate the Quick Connect attribute within the object.\n\n

                                                               Support Quick Connect - Quick Connect enabled:\n
                                                               Set flag \ref EIP_OBJECT_QC_FLAGS_ACTIVATE_ATTRIBUTE
                                                               and flag \ref EIP_OBJECT_QC_FLAGS_ENABLE_QC in order to
                                                               activate the attribute and simultaneously enable the
                                                               Quick Connection functionality.\n\n
                                                             */


  /* New parameters for packet V2 start here **************/

  TLR_UINT8                           abAdminState[2];       /*!< Admin State \n

                                                               \description
                                                               This parameter corresponds to attribute 9 of the
                                                               Ethernet Link Object (CIP Id 0xFF).
                                                               The Admin State attribute shall allow administrative
                                                               setting of the interface state. The interface (PHYs) can be
                                                               enabled or disabled.
                                                               Each array entry stands for one ethernet port.
                                                               This attribute shall be stored in non-volatile memory.

                                                               \valueRange \n
                                                               0x01: Interface enabled
                                                               0x02: Interface disabled
                                                               Default: Both entries 0x01 (enabled)
                                                             */

  /* New parameters for packet V3 start here **************/

  TLR_UINT8                           bTTLValue;             /*!< TTL Value \n

                                                               \description
                                                               This parameter corresponds to attribute 8 of the
                                                               TCP/IP Interface Object (CIP Id 0xF5).
                                                               The TTL value attribute shall use for the IP header Time-to-Live
                                                               when sending EtherNet/IP packets via multicast.
                                                               This attribute shall be stored in non-volatile memory.

                                                               \valueRange \n
                                                               1 - 255
                                                               Default: 1
                                                             */
  EIP_DPMINTF_TI_MCAST_CONFIG_T       tMCastConfig;          /*!< Multicast Configuration \n

                                                               \description
                                                               This parameter corresponds to attribute 9 of the
                                                               TCP/IP Interface Object (CIP Id 0xF5).
                                                               The MCast Config set the used multicast range for multicast connections.
                                                               This attribute shall be stored in non-volatile memory.

                                                               \valueRange \n
                                                               0 - disabled
                                                               1 - 3600 seconds
                                                               Default: 120 seconds
                                                             */

  TLR_UINT16                          usEncapInactivityTimer;/*!< Encapsulation Inactivity Timeout \n

                                                               \description
                                                               This parameter corresponds to attribute 13 of the
                                                               TCP/IP Interface Object (CIP Id 0xF5).
                                                               The Encapsulation Inavtivity Timeout is used to close socketes when the
                                                               defined time (seconds) eclapsed without Encapsulation activity.
                                                               This attribute shall be stored in non-volatile memory.

                                                               \valueRange \n
                                                               0 - disabled
                                                               1 - 3600 seconds
                                                               Default: 120 seconds
                                                             */

}__PACKED_POST  EIP_APS_CONFIGURATION_PARAMETER_SET_V3_T;

#define EIP_APS_CONFIGURATION_PARAMETER_SET_V3_SIZE (sizeof(EIP_APS_CONFIGURATION_PARAMETER_SET_V3_T) )

/*#####################################################################################*/

/* Request Packet */

typedef __PACKED_PRE struct EIP_APS_SET_CONFIGURATION_PARAMETERS_REQ_Ttag
{
  TLR_UINT32  ulParameterVersion;  /*!< Version related to the following configuration union */

  __PACKED_PRE union
  {
    EIP_APS_CONFIGURATION_PARAMETER_SET_V1_T tV1;
    EIP_APS_CONFIGURATION_PARAMETER_SET_V2_T tV2;
    EIP_APS_CONFIGURATION_PARAMETER_SET_V3_T tV3;
  }__PACKED_POST unConfig;

}__PACKED_POST  EIP_APS_SET_CONFIGURATION_PARAMETERS_REQ_T;


typedef __PACKED_PRE struct EIP_APS_PACKET_SET_CONFIGURATION_PARAMETERS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;
  EIP_APS_SET_CONFIGURATION_PARAMETERS_REQ_T tData;

} __PACKED_POST EIP_APS_PACKET_SET_CONFIGURATION_PARAMETERS_REQ_T;

#define EIP_APS_SET_CONFIGURATION_PARAMETERS_REQ_SIZE   4 /* Basic size of request packet.
                                                             The size of the following parameter union needs to be added. */

/*#####################################################################################*/

/* Confirmation Packet */

typedef __PACKED_PRE struct EIP_APS_SET_CONFIGURATION_PARAMETERS_CNF_Ttag
{
  TLR_UINT32  ulPacketVersion;  /*!< Version related to the following union entry */

  __PACKED_PRE union
  {
    EIP_APS_CONFIGURATION_PARAMETER_SET_V1_T tV1;
  }__PACKED_POST unConfig;

}__PACKED_POST  EIP_APS_SET_CONFIGURATION_PARAMETERS_CNF_T;


typedef struct EIP_APS_PACKET_SET_CONFIGURATION_PARAMETERS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;
  EIP_APS_SET_CONFIGURATION_PARAMETERS_CNF_T tData;
} EIP_APS_PACKET_SET_CONFIGURATION_PARAMETERS_CNF_T;

/*#####################################################################################*/
/*#####################################################################################*/

#define PID_EIP_IP_CONFIGURATION  0x3000A001 /* EtherNet/IP Address Settings      */
#define PID_EIP_IP_CONFIGCONTROL  0x3000A002 /* EtherNet/IP Configuration Control */

typedef struct PID_EIP_IP_CONFIGURATION_Ttag
{
  TLR_UINT32 ulIP;
  TLR_UINT32 ulNetmask;
  TLR_UINT32 ulGateway;
}PID_EIP_IP_CONFIGURATION_T;

#define PRM_CFGCTRL_STORED_CFG  0
#define PRM_CFGCTRL_DHCP        1
#define PRM_CFGCTRL_BOOTP       2
#define PRM_CFGCTRL_FIXIP       3

typedef struct PID_EIP_IP_CONFIGCONTROL_Ttag
{
  TLR_UINT32 ulConfigurationControl;
} PID_EIP_IP_CONFIGCONTROL_T;


/*#####################################################################################*/
/*#####################################################################################*/
/* pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(EIP_DPMINTF_PUBLIC)
#endif


/***************************************************************************************/
/* Eip DpmIntf public, prototypes */

/***************************************************************************************/
#endif /* #ifndef __EIP_DPMINTF_PUBLIC_H */
