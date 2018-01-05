/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpipTcpTask_Public.h 63563 2016-08-29 14:06:08Z RalfH $:

Description:
    Task Tcpip TcpTask - public declaration of task (queue packets)


  Changes:
    Date        Description
  ---------------------------------------------------------------------------
    2012-07-19  Added packet
                TCPIP_TCP_UDP_CMD_STOP_QC_ARPS_REQ/CNF
                Added parameter ulQC_Active to command
                TCPIP_TCP_UDP_CMD_ENABLE_ACD_REQ

                (Mantis ID 0019075):
                Feature: Support EtherNet/IP Quick Connect ACD
                beahvior


    2011-02-04- Added VLAN structure to packet
                TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_T

                (Mantis ID 0012423):
                TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION_REQ
                with mode TCP_SOCK_VLAN not implemented

    2011-02-02- Added VLAN tag structure to
                TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_T

                (Mantis ID 0012378):Feature: Add support of
                sending VLAN tagged frames as defined in
                IEEE 802.1Q

    2010-10-22  Added new mode IP_PRM_SEND_ARP_TMT_REQ_W_CACHEENTRY
                to command IP_CMD_SET_PARAM

    2010-05-26  File created.
 **************************************************************************************/


#ifndef __TCPIP_TCP_TASK_PUBLIC_H
#define __TCPIP_TCP_TASK_PUBLIC_H



/****************************************************************************************
* Tcpip TcpTask, includes */

#include "TcpipConfig.h"


/***************************************************************************************/
/* __Prefix__ __TaskName__ public, constants */

/*** Process queue name ***/
#define EN_TCPUDP_PROCESS_QUEUE_NAME    "EN_TCPUDP_QUE"


/*** Maximum user data counts ***/
#define TCPIP_MAX_TCP_DATA_CNT          1460
#define TCPIP_MAX_UDP_DATA_CNT          1472
#define TCPIP_MAX_TCP_UDP_DATA_CNT      TCPIP_MAX_UDP_DATA_CNT  /* Max. = 1472! */


/*** Flags in usFlags/ulFlags (variable of structures TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_T,
     TCPIP_DATA_IP_CMD_GET_CONFIG_CNF_T, IP_CONFIG_DPM_T                                  ***/
/* For usable flags IP_CFG_FLAG_xx see Protocol API manual! */

/*****************************************************************/
/* Configuration Flags - lower 16 bits of field ulFlags */
   #define IP_CFG_FLAG_IP_ADDR             (0x0001)
   #define IP_CFG_FLAG_NET_MASK            (0x0002)
   #define IP_CFG_FLAG_GATEWAY             (0x0004)
   #define IP_CFG_FLAG_BOOTP               (0x0008)
   #define IP_CFG_FLAG_DHCP                (0x0010)
   #define IP_CFG_FLAG_ETHERNET_ADDR       (0x0020)
   #define IP_CFG_FLAG_HTTP_SOCKETS        (0x0040)
   #define IP_CFG_FLAG_FQDN_NAME           (0x0080)

/* #define IP_CFG_FLAG_AUTO_DETECT         (0x0100) */
   #define IP_CFG_FLAG_INTF_TP             (0x0200)


   /* PHY related configuration of Speed and Duplex.
    *
    * If the flag IP_CFG_FLAG_EXTENDED_FLAGS IS NOT set:
    * The following flags configure port 0 and 1.
    *
    * If the flag IP_CFG_FLAG_EXTENDED_FLAGS IS set:
    * The following flags configure only port 0. For port 1 the
    * corresponding extended flags must be used.
    *  */
   #define IP_CFG_FLAG_AUTO_NEGOTIATE      (0x0400)
   #define IP_CFG_FLAG_FULL_DUPLEX         (0x0800)
   #define IP_CFG_FLAG_SPEED_100MBIT       (0x1000)


   #define IP_CFG_FLAG_NO_GRATUITOUS_ARP   (0x4000)
   #define IP_CFG_FLAG_EXTENDED_FLAGS      (0x8000) /* Enables the upper 16 bit of the ulFlags field */

/* Extended Configuration flags - upper 16 bits of field ulFlags */

/* PHY related configuration of Speed and Duplex.
 * The following flags configure only port 1. Make sure that the flag
 * IP_CFG_FLAG_EXTENDED_FLAGS is set in addition. */

   #define IP_CFG_EXT_FLAG_PORT1_AUTO_NEGOTIATE (0x0400)
   #define IP_CFG_EXT_FLAG_PORT1_FULL_DUPLEX    (0x0800)
   #define IP_CFG_EXT_FLAG_PORT1_SPEED_100MBIT  (0x1000)

/* PHY related configuration of MDI.
 * The following flags configure the MDI mode for port 0 and 1.
 * Make sure that the flag IP_CFG_FLAG_EXTENDED_FLAGS is set in addition. */
   #define IP_CFG_EXT_FLAG_PORT0_MDIX_MASK      (0x0003)
   #define IP_CFG_EXT_FLAG_PORT0_MDIX_AUTO      (0x0001)
   #define IP_CFG_EXT_FLAG_PORT0_MDIX_MDI       (0x0002)
   #define IP_CFG_EXT_FLAG_PORT0_MDIX_MDIX      (0x0003)

   #define IP_CFG_EXT_FLAG_PORT1_MDIX_MASK      (0x000C)
   #define IP_CFG_EXT_FLAG_PORT1_MDIX_AUTO      (0x0004)
   #define IP_CFG_EXT_FLAG_PORT1_MDIX_MDI       (0x0008)
   #define IP_CFG_EXT_FLAG_PORT1_MDIX_MDIX      (0x000C)

/* Old defines (kept to keep compatibility) */
   #define IP_CFG_FLAG_PORT1_AUTO_NEGOTIATE   IP_CFG_EXT_FLAG_PORT1_AUTO_NEGOTIATE
   #define IP_CFG_FLAG_PORT1_FULL_DUPLEX      IP_CFG_EXT_FLAG_PORT1_FULL_DUPLEX
   #define IP_CFG_FLAG_PORT1_SPEED_100MBIT    IP_CFG_EXT_FLAG_PORT1_SPEED_100MBIT


/*** Parameter limits for application request commands ***/

/* Min port depends on command */
#define TCP_UDP_PORT_0                  0     /* Port 0, means use the next free port   */
#define TCP_UDP_PORT_MIN                1     /* Min port value for TCP and UDP sockets */
#define TCP_UDP_PORT_MAX                65535 /* Max port value for TCP and UDP sockets */


/***************************************************************************************/
/* Tcpip TcpTask public, command codes */


/* Start of the reserved area from 0x200 - 0x2FF for TCP/IP IP service  */
/* commands and primitives                                              */
#define TCPIP_IP_PACKET_COMMAND_START           0x00000200

/* Summary of the TCP/IP IP service commands and primitives             */
#define TCPIP_IP_CMD_SET_CONFIG_REQ                   0x00000200
#define TCPIP_IP_CMD_SET_CONFIG_CNF                   0x00000201

#define TCPIP_IP_CMD_GET_CONFIG_REQ                   0x00000202
#define TCPIP_IP_CMD_GET_CONFIG_CNF                   0x00000203

#define TCPIP_IP_CMD_SET_PARAM_REQ                    0x00000204
#define TCPIP_IP_CMD_SET_PARAM_CNF                    0x00000205

#define TCPIP_IP_CMD_GET_PARAM_REQ                    0x00000206
#define TCPIP_IP_CMD_GET_PARAM_CNF                    0x00000207

#define TCPIP_IP_CMD_GET_OPTIONS_REQ                  0x00000208
#define TCPIP_IP_CMD_GET_OPTIONS_CNF                  0x00000209

#define TCPIP_IP_CMD_PING_REQ                         0x0000020A
#define TCPIP_IP_CMD_PING_CNF                         0x0000020B

#define TCPIP_IP_CMD_ICMP_IND                         0x0000020C
#define TCPIP_IP_CMD_ICMP_RES                         0x0000020D

#define TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_REQ        0x0000020E
#define TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_CNF        0x0000020F
  /* Special Task internal commands
  TCPIP_IP_CMD_END_PROCESS_REQ                = 0x2E0,
  TCPIP_IP_CMD_END_PROCESS_CNF                = 0x2E1,

  IP_CMD_SET_CONFIGURATION_REQ                = 0x2E2,
  IP_CMD_SET_CONFIGURATION_CNF                = 0x2E3, */

#define TCPIP_EIF_CMD_ETH_FRAME_REQ                   0x000002E4  /* _TCPIP_EIF_PACKET_ROUTER_  */
#define TCPIP_EIF_CMD_ETH_FRAME_CNF                   0x000002E5  /*                            */

#define TCPIP_EIF_CMD_IP_CONFIG_IND                   0x000002E6  /* _TCPIP_EIF_PACKET_ROUTER_  */
#define TCPIP_EIF_CMD_IP_CONFIG_RES                   0x000002E7  /*                            */

/* Start of the reserved area from 0x300 - 0x3FF for TCP/IP TCP_UDP     */
/* (TCP | TCP_UDP | UDP) service commands and primitives                */
#define TCPIP_TCP_UDP_PACKET_COMMAND_START      (0x00000300)

/* Summary of the TCP/IP TCP_UDP (TCP | TCP_UDP | UDP) service commands */
/* and primitives                                                       */

#define TCPIP_TCP_UDP_CMD_OPEN_REQ                    0x00000300
#define TCPIP_TCP_UDP_CMD_OPEN_CNF                    0x00000301

#define TCPIP_TCP_UDP_CMD_CLOSE_REQ                   0x00000302
#define TCPIP_TCP_UDP_CMD_CLOSE_CNF                   0x00000303

#define TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ               0x00000304
#define TCPIP_TCP_UDP_CMD_CLOSE_ALL_CNF               0x00000305

#define TCPIP_TCP_CMD_WAIT_CONNECT_REQ                0x00000306
#define TCPIP_TCP_CMD_WAIT_CONNECT_CNF                0x00000307

#define TCPIP_TCP_CMD_CONNECT_REQ                     0x00000308
#define TCPIP_TCP_CMD_CONNECT_CNF                     0x00000309

#define TCPIP_TCP_CMD_SEND_REQ                        0x0000030A
#define TCPIP_TCP_CMD_SEND_CNF                        0x0000030B

#define TCPIP_UDP_CMD_SEND_REQ                        0x0000030C
#define TCPIP_UDP_CMD_SEND_CNF                        0x0000030D

#define TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ         0x0000030E
#define TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_CNF         0x0000030F

#define TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION_REQ         0x00000310
#define TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION_CNF         0x00000311

#define TCPIP_TCP_UDP_CMD_RECEIVE_IND                 0x00000312
#define TCPIP_TCP_UDP_CMD_RECEIVE_RES                 0x00000313

#define TCPIP_TCP_UDP_CMD_SHUTDOWN_IND                0x00000314
#define TCPIP_TCP_UDP_CMD_SHUTDOWN_RES                0x00000315

#define TCPIP_TCP_UDP_CMD_RECEIVE_STOP_IND            0x00000316
#define TCPIP_TCP_UDP_CMD_RECEIVE_STOP_RES            0x00000317

#define TCPIP_TCP_UDP_CMD_BIND_REQ                    0x00000318
#define TCPIP_TCP_UDP_CMD_BIND_CNF                    0x00000319

#define TCPIP_TCP_UDP_CMD_ACD_CONFLICT_IND            0x0000031A
#define TCPIP_TCP_UDP_CMD_ACD_CONFLICT_RES            0x0000031B

#define TCPIP_TCP_UDP_CMD_ENABLE_ACD_REQ              0x0000031C
#define TCPIP_TCP_UDP_CMD_ENABLE_ACD_CNF              0x0000031D

#define TCPIP_TCP_UDP_CMD_STOP_QC_ARPS_REQ            0x0000031E
#define TCPIP_TCP_UDP_CMD_STOP_QC_ARPS_CNF            0x0000031F

/* ... Add here only function handler commands!! ... */

  /* Special Task internal commands */
#define TCPIP_TCP_UDP_CMD_END_PROCESS_REQ             0x000003E0
#define TCPIP_TCP_UDP_CMD_END_PROCESS_CNF             0x000003E1

#define TCPIP_TCP_UDP_CMD_CYCLE_EVENT_REQ             0x000003E2
#define TCPIP_TCP_UDP_CMD_CYCLE_EVENT_CNF             0x000003E3

#define TCPIP_TCP_UDP_CMD_ETH_FRAME_REQ               0x000003E4
#define TCPIP_TCP_UDP_CMD_ETH_FRAME_CNF               0x000003E5

#define TCPIP_TCP_CMD_GET_TASK_STATE_REQ              0x000003E6
#define TCPIP_TCP_CMD_GET_TASK_STATE_CNF              0x000003E7

#define TCPIP_CMD_FATAL_ERROR_REQ                     0x000003E8
#define TCPIP_CMD_FATAL_ERROR_CNF                     0x000003E9




/***************************************************************************************/
/* Tcpip TcpTask public, types */

/* Compiler settings */
#if _MSC_VER >= 1000
  #define __TCPIP_PACKED_PRE
  #define __TCPIP_PACKED_POST
  #pragma once
  #pragma pack(1)            /* Always align structures to byte boundery */
  #ifndef STRICT             /* Check Typdefinition */
    #define STRICT
  #endif
#endif /* _MSC_VER >= 1000 */

/* support for GNU compiler */
#ifdef __GNUC__
  #define __TCPIP_PACKED_PRE
  #define __TCPIP_PACKED_POST   __attribute__((__packed__))
#endif

/* support for REALVIEW ARM compiler */
#if defined (__ADS__) || defined (__REALVIEW__)
  #define __TCPIP_PACKED_PRE    __packed
  #define __TCPIP_PACKED_POST
#endif



/* Structure of IP layer parameters in DPM */
typedef __TCPIP_PACKED_PRE struct IP_CONFIG_DPM_Ttag {

  TLR_UINT8   bPlcMode;             /* Handshake mode */
  TLR_UINT16  usWatchdogTime;       /* Host watchdog time */
  TLR_UINT8   bReserved3;

  TLR_UINT16  usFlags;              /* Flags, see IP_CFG_FLAG_... definitions */
  TLR_UINT32  ulIpAddr;             /* IP address */
  TLR_UINT32  ulNetMask;            /* Net mask */
  TLR_UINT32  ulGateway;            /* Default gateway */
  TLR_UINT8   abEthernetAddr[6];    /* Ethernet address */
  TLR_UINT8   bHttpSockets;         /* Reserved */
  TLR_UINT8   abReserved4[7];       /* Reserved */

} __TCPIP_PACKED_POST IP_CONFIG_DPM_T;


/* MAC address */
typedef __TCPIP_PACKED_PRE struct MAC_ADDR_Ttag
{
  TLR_UINT8   abMacAddr[6];
} __TCPIP_PACKED_POST MAC_ADDR_T;




/****************************************************************************************
* Tcpip TcpTask public, packets */


/*
 * Structures of all Request/Confirmation commands the task is able to send and receive
 *
 * Request and Confirmation Packets __PREFIX___PACKET___TASKNAME___xx_REQ/CNF
 * (xx = Command)
 *
 * Use the same order as the commands in TLR_Commands.h
 * __PREFIX_____TASKNAME___xx_REQ/CNF (xx = Command)!
 */

/*** General definitions ***/
/* #define TCPIP_DATA_SIZE_NULL  0     tHead.ulLen for all packets without tData */



/*** Definition of the packet types this Task is able to receive/send as server ***/

/* Packets for providing configuration data - IP_CMD_SET_CONFIG */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_Ttag
{
  TLR_UINT32  ulFlags;
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulNetMask;
  TLR_UINT32  ulGateway;
  TLR_UINT8   abEthernetAddr[6];

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_T;

#define TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_SIZE \
                            (sizeof(TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_T))

typedef struct TCPIP_PACKET_IP_CMD_SET_CONFIG_REQ_Ttag
{
  TLR_PACKET_HEADER_T                 tHead;
  TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_T  tData;

} TCPIP_PACKET_IP_CMD_SET_CONFIG_REQ_T;


typedef struct TCPIP_PACKET_IP_CMD_SET_CONFIG_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_IP_CMD_SET_CONFIG_CNF_T;




/* Packets for obtaining configuration data - IP_CMD_GET_CONFIG */
typedef struct TCPIP_PACKET_IP_CMD_GET_CONFIG_REQ_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_IP_CMD_GET_CONFIG_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_GET_CONFIG_CNF_Ttag
{
  TLR_UINT32  ulFlags;
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulNetMask;
  TLR_UINT32  ulGateway;
  TLR_UINT8   abEthernetAddr[6];

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_GET_CONFIG_CNF_T;

#define TCPIP_DATA_IP_CMD_GET_CONFIG_CNF_SIZE \
                            (sizeof(TCPIP_DATA_IP_CMD_GET_CONFIG_CNF_T))

typedef struct TCPIP_PACKET_IP_CMD_GET_CONFIG_CNF_Ttag
{
  TLR_PACKET_HEADER_T                 tHead;
  TCPIP_DATA_IP_CMD_GET_CONFIG_CNF_T  tData;

} TCPIP_PACKET_IP_CMD_GET_CONFIG_CNF_T;




/* Packets for setting IP parameters - IP_CMD_SET_PARAM */

/* Valid modes of packet ulMode variable */
#define IP_PRM_ADD_ARP_ENTRY                   (1)
#define IP_PRM_DEL_ARP_ENTRY                   (2)
#define IP_PRM_DEL_ARP_ENTRY_IP                (3)
#define IP_PRM_DEL_ARP_ENTRY_MAC               (4)
#if defined(CONFIG_ARP_REQ_INTF) || defined(CONFIG_ARP_REQ_INTF_DBLY)
#define IP_PRM_SEND_ARP_REQ                    (5)
#define IP_PRM_SEND_ARP_TMT_REQ                (6)
#define IP_PRM_SET_ARP_REQ_TMT                 (7)
#define IP_PRM_SEND_ARP_TMT_REQ_W_CACHEENTRY  (10) /* same as IP_PRM_SEND_ARP_TMT_REQ but makes entry in ARP cache */
#endif
#define IP_PRM_REGISTER_ACD_APP                (8)
#define IP_PRM_REGISTER_ICMP_APP               (9)


/* Services for ICMP registration */
#define IP_PRM_REGISTER_ICMP_SERVICE_ECHO_REQUEST             0x00000001


#if defined(CONFIG_ARP_REQ_INTF) || defined(CONFIG_ARP_REQ_INTF_DBLY)
#define SEND_ARP_TMT_STATION_MAX        (100)   /* Maximum stations in tSendArpTmtCnf packet  */

#define ARP_REQ_INTF_TIMEOUT_MIN        (100L)  /* Timeout for "ARP send request interface"   */
#define ARP_REQ_INTF_TIMEOUT_DEFAULT    (1000L)
#define ARP_REQ_INTF_TIMEOUT_MAX        (60000L)
#endif

typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_SET_PARAM_REQ_Ttag
{
  TLR_UINT32   ulMode;

  __TCPIP_PACKED_PRE union
  {
    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIpAddr;
      TLR_UINT8   abEthernetAddr[6];
    } __TCPIP_PACKED_POST tAddDelArpEntry;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIpAddr;
    } __TCPIP_PACKED_POST tDelArpEntryIp;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT8  abEthernetAddr[6];
    } __TCPIP_PACKED_POST tDelArpEntryMac;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulServices;
    } __TCPIP_PACKED_POST tRegisterIcmpService;

#if defined(CONFIG_ARP_REQ_INTF) || defined(CONFIG_ARP_REQ_INTF_DBLY)
    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIpAddr;
      TLR_UINT8   abEthernetAddr[6];
    } __TCPIP_PACKED_POST tSendArpReq;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIpAddr;
      TLR_UINT8   abEthernetAddr[6];
      TLR_UINT32  ulStationCntAbort;  /* Abort command, if this count of    */
    } __TCPIP_PACKED_POST tSendArpTmtReq; /* stations has reached (e.g. 2)  */

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulTimeout;
    } __TCPIP_PACKED_POST tSetArpReqTmt;
#endif

  } __TCPIP_PACKED_POST unParam;

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_SET_PARAM_REQ_T;

#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_ADD_ARP_ENTRY      \
              (sizeof(TLR_UINT32) + 10 /*sizeof(tAddDelArpEntry)*/)

#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_DEL_ARP_ENTRY      \
              (sizeof(TLR_UINT32) + 10 /*sizeof(tAddDelArpEntry)*/)

#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_DEL_ARP_ENTRY_IP   \
              (sizeof(TLR_UINT32) + 4  /*sizeof(tDelArpEntryIp )*/)

#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_DEL_ARP_ENTRY_MAC  \
              (sizeof(TLR_UINT32) + 6  /*sizeof(tDelArpEntryMac)*/)

#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_REGISTER_ACD_APP    \
              (sizeof(TLR_UINT32))

#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_REGISTER_ICMP_APP    \
              (sizeof(TLR_UINT32) + 4 /*sizeof(tRegisterIcmpService)*/)

#if defined(CONFIG_ARP_REQ_INTF) || defined(CONFIG_ARP_REQ_INTF_DBLY)
#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_SEND_ARP_REQ       \
              (sizeof(TLR_UINT32) + 10 /*sizeof(tSendArpReq    )*/)

#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_SEND_ARP_TMT_REQ   \
              (sizeof(TLR_UINT32) + 14 /*sizeof(tSendArpTmtReq )*/)
#define TCPIP_DATA_IP_CMD_SET_PARAM_REQ_SIZE_SET_ARP_REQ_TMT    \
              (sizeof(TLR_UINT32) + 4  /*sizeof(tSetArpReqTmt  )*/)
#endif

typedef struct TCPIP_PACKET_IP_CMD_SET_PARAM_REQ_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  TCPIP_DATA_IP_CMD_SET_PARAM_REQ_T  tData;

} TCPIP_PACKET_IP_CMD_SET_PARAM_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_SET_PARAM_CNF_Ttag
{
  TLR_UINT32  ulMode;

#if defined(CONFIG_ARP_REQ_INTF) || defined(CONFIG_ARP_REQ_INTF_DBLY)
  __TCPIP_PACKED_PRE union
  {
    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIpAddr;
      TLR_UINT8   abEthernetAddr[6];
    } __TCPIP_PACKED_POST tSendArpCnf;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIpAddr;           /* Struct of Request  */
      TLR_UINT8   abEthernetAddr[6];  /*                    */
      TLR_UINT32  ulStationCntAbort;  /*                    */

      TLR_UINT32  ulStationCnt;         /* Count of founded stations  */
      MAC_ADDR_T  tStation[SEND_ARP_TMT_STATION_MAX]; /* Station list */
    } __TCPIP_PACKED_POST tSendArpTmtCnf;

  } __TCPIP_PACKED_POST unParam;
#endif

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_SET_PARAM_CNF_T;

#define TCPIP_DATA_IP_CMD_SET_PARAM_CNF_SIZE \
              (sizeof(TLR_UINT32))

#if defined(CONFIG_ARP_REQ_INTF) || defined(CONFIG_ARP_REQ_INTF_DBLY)
#define TCPIP_DATA_IP_CMD_SET_PARAM_CNF_SIZE_SEND_ARP_REQ       \
              (sizeof(TLR_UINT32) + 10 /*sizeof(tSendArpCnf    )*/)

#define TCPIP_DATA_IP_CMD_SET_PARAM_CNF_SIZE_SEND_ARP_TMT_REQ_MIN \
              (sizeof(TLR_UINT32) + 18 /*sizeof(tSendArpTmtCnf )*/)
#endif


typedef struct TCPIP_PACKET_IP_CMD_SET_PARAM_CNF_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  TCPIP_DATA_IP_CMD_SET_PARAM_CNF_T  tData;

} TCPIP_PACKET_IP_CMD_SET_PARAM_CNF_T;




/* Packets for obtaining IP parameters - IP_CMD_GET_PARAM */

/* Valid modes of packet ulMode variable */
#define IP_PRM_GET_ARP_ENTRY_INDEX      (1)
#define IP_PRM_GET_ARP_ENTRY_IP         (2)
#define IP_PRM_GET_ARP_ENTRY_MAC        (3)

#define IP_PRM_GET_HOST_NAME            (10)
#define IP_PRM_GET_DOMAIN_NAME          (11)

typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_GET_PARAM_REQ_Ttag
{
  TLR_UINT32  ulMode;

  __TCPIP_PACKED_PRE union
  {
    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIndex;
    } __TCPIP_PACKED_POST tArpEntryIndex;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIpAddr;
    } __TCPIP_PACKED_POST tArpEntryIp;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT8   abEthernetAddr[6];
    } __TCPIP_PACKED_POST tArpEntryMac;
  } __TCPIP_PACKED_POST unParam;

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_GET_PARAM_REQ_T;

#define TCPIP_DATA_IP_CMD_GET_PARAM_REQ_SIZE_GET_ARP_ENTRY_INDEX  \
              (sizeof(TLR_UINT32) + 4 /*sizeof(tArpEntryIndex)*/)

#define TCPIP_DATA_IP_CMD_GET_PARAM_REQ_SIZE_GET_ARP_ENTRY_IP     \
              (sizeof(TLR_UINT32) + 4 /*sizeof(tArpEntryIp)   */)

#define TCPIP_DATA_IP_CMD_GET_PARAM_REQ_SIZE_GET_ARP_ENTRY_MAC    \
              (sizeof(TLR_UINT32) + 6 /*sizeof(tArpEntryMac)  */)

#define TCP_MAX_HOST_NAME     256
#define TCP_MAX_DOMAIN_NAME   256

typedef struct TCPIP_PACKET_IP_CMD_GET_PARAM_REQ_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  TCPIP_DATA_IP_CMD_GET_PARAM_REQ_T  tData;

} TCPIP_PACKET_IP_CMD_GET_PARAM_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_GET_PARAM_CNF_Ttag
{
  TLR_UINT32  ulMode;

  __TCPIP_PACKED_PRE union
  {
    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT32  ulIpAddr;
      TLR_UINT8   abEthernetAddr[6];
    } __TCPIP_PACKED_POST tArpEntry;

    TLR_CHAR szDomainName[TCP_MAX_DOMAIN_NAME];
    TLR_CHAR szHostName[TCP_MAX_HOST_NAME];
  } __TCPIP_PACKED_POST unParam;
} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_GET_PARAM_CNF_T;

#define TCPIP_DATA_IP_CMD_GET_PARAM_CNF_SIZE_GET_ARP_ENTRY_INDEX  \
              (sizeof(TLR_UINT32) + 10 /*sizeof(tArpEntry)*/)

#define TCPIP_DATA_IP_CMD_GET_PARAM_CNF_SIZE_GET_ARP_ENTRY_IP     \
              (sizeof(TLR_UINT32) + 10 /*sizeof(tArpEntry)*/)

#define TCPIP_DATA_IP_CMD_GET_PARAM_CNF_SIZE_GET_ARP_ENTRY_MAC    \
              (sizeof(TLR_UINT32) + 10 /*sizeof(tArpEntry)*/)

typedef struct TCPIP_PACKET_IP_CMD_GET_PARAM_CNF_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  TCPIP_DATA_IP_CMD_GET_PARAM_CNF_T  tData;

} TCPIP_PACKET_IP_CMD_GET_PARAM_CNF_T;




/* Packets for obtaining TCP/IP stack capabilities - IP_CMD_GET_OPTIONS */
typedef struct TCPIP_PACKET_IP_CMD_GET_OPTIONS_REQ_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_IP_CMD_GET_OPTIONS_REQ_T;


/* Valid options of packet ulOptions variable */
#define IP_OPT_PROTO_TCP                (0x00000001)
#define IP_OPT_PROTO_UDP                (0x00000002)
#define IP_OPT_BOOTP                    (0x00000004)
#define IP_OPT_DHCP                     (0x00000008)
#define IP_OPT_MULTICAST                (0x00000010)

typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_GET_OPTIONS_CNF_Ttag
{
  TLR_UINT32  ulOptions;

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_GET_OPTIONS_CNF_T;

#define TCPIP_DATA_IP_CMD_GET_OPTIONS_CNF_SIZE \
                            (sizeof(TCPIP_DATA_IP_CMD_GET_OPTIONS_CNF_T))

typedef struct TCPIP_PACKET_IP_CMD_GET_OPTIONS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                  tHead;
  TCPIP_DATA_IP_CMD_GET_OPTIONS_CNF_T  tData;

} TCPIP_PACKET_IP_CMD_GET_OPTIONS_CNF_T;




/* Packets for sending a ping - IP_CMD_PING */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_PING_REQ_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulTimeout;

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_PING_REQ_T;

#define TCPIP_DATA_IP_CMD_PING_REQ_SIZE (sizeof(TCPIP_DATA_IP_CMD_PING_REQ_T))

typedef struct TCPIP_PACKET_IP_CMD_PING_REQ_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
  TCPIP_DATA_IP_CMD_PING_REQ_T  tData;

} TCPIP_PACKET_IP_CMD_PING_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_PING_CNF_Ttag
{
  TLR_UINT32  ulResponseTime;

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_PING_CNF_T;

#define TCPIP_DATA_IP_CMD_PING_CNF_SIZE (sizeof(TCPIP_DATA_IP_CMD_PING_CNF_T))

typedef struct TCPIP_PACKET_IP_CMD_PING_CNF_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
  TCPIP_DATA_IP_CMD_PING_CNF_T  tData;

} TCPIP_PACKET_IP_CMD_PING_CNF_T;


/* Packets for ICMP indications - TCPIP_IP_CMD_ICMP_IND */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_IP_CMD_ICMP_IND_Ttag
{
  TLR_UINT8   bType;
  TLR_UINT8   bCode;
  TLR_UINT16  usChecksum;
  TLR_UINT8   abData[TCPIP_MAX_TCP_UDP_DATA_CNT];

} __TCPIP_PACKED_POST TCPIP_DATA_IP_CMD_ICMP_IND_T;

#define TCPIP_DATA_IP_CMD_ICMP_IND_SIZE (sizeof(TCPIP_DATA_IP_CMD_ICMP_IND_T))

typedef struct TCPIP_PACKET_IP_CMD_ICMP_IND_Ttag
{
  TLR_PACKET_HEADER_T           tHead;
  TCPIP_DATA_IP_CMD_ICMP_IND_T  tData;

} TCPIP_PACKET_IP_CMD_ICMP_IND_T;

typedef struct TCPIP_PACKET_IP_CMD_ICMP_RES_Ttag
{
  TLR_PACKET_HEADER_T           tHead;

} TCPIP_PACKET_IP_CMD_ICMP_RES_T;


/* Packets for opening a socket - TCP_UDP_CMD_OPEN */

/* Protocol types of packet ulProtocol variable */
#define TCP_PROTO_TCP                   (1)
#define TCP_PROTO_UDP                   (2)

typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_OPEN_REQ_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;
  TLR_UINT32  ulProtocol;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_OPEN_REQ_T;

#define TCPIP_DATA_TCP_UDP_CMD_OPEN_REQ_SIZE \
                            (sizeof(TCPIP_DATA_TCP_UDP_CMD_OPEN_REQ_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_OPEN_REQ_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  TCPIP_DATA_TCP_UDP_CMD_OPEN_REQ_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_OPEN_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_OPEN_CNF_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;
  TLR_UINT32  ulProtocol;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_OPEN_CNF_T;

#define TCPIP_DATA_TCP_UDP_CMD_OPEN_CNF_SIZE \
                            (sizeof(TCPIP_DATA_TCP_UDP_CMD_OPEN_CNF_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_OPEN_CNF_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  TCPIP_DATA_TCP_UDP_CMD_OPEN_CNF_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_OPEN_CNF_T;




/* Packets for closing a socket - TCP_UDP_CMD_CLOSE */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_CLOSE_REQ_Ttag
{
  TLR_UINT32  ulTimeout;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_CLOSE_REQ_T;

#define TCPIP_DATA_TCP_UDP_CMD_CLOSE_REQ_SIZE \
                            (sizeof(TCPIP_DATA_TCP_UDP_CMD_CLOSE_REQ_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_CLOSE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                 tHead;
  TCPIP_DATA_TCP_UDP_CMD_CLOSE_REQ_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_CLOSE_REQ_T;


typedef struct TCPIP_PACKET_TCP_UDP_CMD_CLOSE_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_TCP_UDP_CMD_CLOSE_CNF_T;




/* Packets for closing all sockets - TCP_UDP_CMD_CLOSE_ALL */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_CLOSE_ALL_REQ_Ttag
{
  TLR_UINT32  ulTimeout;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_CLOSE_ALL_REQ_T;

#define TCPIP_DATA_TCP_UDP_CMD_CLOSE_ALL_REQ_SIZE \
                            (sizeof(TCPIP_DATA_TCP_UDP_CMD_CLOSE_ALL_REQ_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_REQ_Ttag
{
  TLR_PACKET_HEADER_T                     tHead;
  TCPIP_DATA_TCP_UDP_CMD_CLOSE_ALL_REQ_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_REQ_T;


typedef struct TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_CNF_T;




/* Packets for waiting for an incoming TCP connection - TCP_CMD_WAIT_CONNECT */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_CMD_WAIT_CONNECT_REQ_Ttag
{
  TLR_UINT32  ulTimeoutSend;
  TLR_UINT32  ulTimeoutListen;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_CMD_WAIT_CONNECT_REQ_T;

#define TCPIP_DATA_TCP_CMD_WAIT_CONNECT_REQ_SIZE \
                            (sizeof(TCPIP_DATA_TCP_CMD_WAIT_CONNECT_REQ_T))

typedef struct TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_REQ_Ttag
{
  TLR_PACKET_HEADER_T                    tHead;
  TCPIP_DATA_TCP_CMD_WAIT_CONNECT_REQ_T  tData;

} TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_CMD_WAIT_CONNECT_CNF_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_CMD_WAIT_CONNECT_CNF_T;

#define TCPIP_DATA_TCP_CMD_WAIT_CONNECT_CNF_SIZE \
                            (sizeof(TCPIP_DATA_TCP_CMD_WAIT_CONNECT_CNF_T))

typedef struct TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_CNF_Ttag
{
  TLR_PACKET_HEADER_T                    tHead;
  TCPIP_DATA_TCP_CMD_WAIT_CONNECT_CNF_T  tData;

} TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_CNF_T;




/* Packets for establishing a TCP connection - TCP_CMD_CONNECT */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_CMD_CONNECT_REQ_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;
  TLR_UINT32  ulTimeoutSend;
  TLR_UINT32  ulTimeoutConnect;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_CMD_CONNECT_REQ_T;

#define TCPIP_DATA_TCP_CMD_CONNECT_REQ_SIZE \
                            (sizeof(TCPIP_DATA_TCP_CMD_CONNECT_REQ_T))

typedef struct TCPIP_PACKET_TCP_CMD_CONNECT_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  TCPIP_DATA_TCP_CMD_CONNECT_REQ_T  tData;

} TCPIP_PACKET_TCP_CMD_CONNECT_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_CMD_CONNECT_CNF_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_CMD_CONNECT_CNF_T;

#define TCPIP_DATA_TCP_CMD_CONNECT_CNF_SIZE \
                            (sizeof(TCPIP_DATA_TCP_CMD_CONNECT_CNF_T))

typedef struct TCPIP_PACKET_TCP_CMD_CONNECT_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  TCPIP_DATA_TCP_CMD_CONNECT_CNF_T  tData;

} TCPIP_PACKET_TCP_CMD_CONNECT_CNF_T;




/* Packets for sending TCP data - TCP_CMD_SEND */

/* Options of packet ulOptions variable */
#define TCP_SEND_OPT_PUSH               (0x00000001)

typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_CMD_SEND_REQ_Ttag
{
  TLR_UINT32  ulOptions;
  TLR_UINT8   abData[TCPIP_MAX_TCP_DATA_CNT];
                /* Length depends only on the packet size from USER! - the calculation    */
                /* below is correct, but we don't use it here!                            */

  /* MSS = Maximum segment size (of TCP data), normally = 1460 byte on Ethernet (Maximum) */
  /* MTU = Maximum Transmission Unit, normally 1500 byte = Data part of Ethernet frame    */
  /* MSS = MTU - sizeof(ip header) - sizeof (tcp header)                                  */
  /* ==> MSS = 1500 -20 -20 = 1460 byte                                                   */

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_CMD_SEND_REQ_T;

#define TCPIP_DATA_TCP_CMD_SEND_REQ_SIZE (sizeof(TCPIP_DATA_TCP_CMD_SEND_REQ_T) \
                                          - TCPIP_MAX_TCP_DATA_CNT             )

typedef struct TCPIP_PACKET_TCP_CMD_SEND_REQ_Ttag
{
  TLR_PACKET_HEADER_T            tHead;
  TCPIP_DATA_TCP_CMD_SEND_REQ_T  tData;

} TCPIP_PACKET_TCP_CMD_SEND_REQ_T;


typedef struct TCPIP_PACKET_TCP_CMD_SEND_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_TCP_CMD_SEND_CNF_T;




/* Packets for sending UDP data - UDP_CMD_SEND */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_UDP_CMD_SEND_REQ_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;
  TLR_UINT32  ulOptions;
  TLR_UINT8   abData[TCPIP_MAX_UDP_DATA_CNT];
                /* Max_UDP_data_size = 1472, see below */

  /* MTU = Maximum Transmission Unit, normally 1500 byte = Data part of Ethernet frame  */
  /* Max_UDP_data_size = MTU - sizeof(ip header) - sizeof (udp header)                  */
  /* ==> Max_UDP_data_size = 1500 -20 -8 = 1472 byte                                    */

} __TCPIP_PACKED_POST TCPIP_DATA_UDP_CMD_SEND_REQ_T;

#define TCPIP_DATA_UDP_CMD_SEND_REQ_SIZE (sizeof(TCPIP_DATA_UDP_CMD_SEND_REQ_T) \
                                          - TCPIP_MAX_UDP_DATA_CNT             )

typedef struct TCPIP_PACKET_UDP_CMD_SEND_REQ_Ttag
{
  TLR_PACKET_HEADER_T            tHead;
  TCPIP_DATA_UDP_CMD_SEND_REQ_T  tData;

} TCPIP_PACKET_UDP_CMD_SEND_REQ_T;


typedef struct TCPIP_PACKET_UDP_CMD_SEND_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_UDP_CMD_SEND_CNF_T;




/* Valid modes of packet ulMode variable of following commands          */
/* TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION/TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION  */
#define TCP_SOCK_TTL                    (1)
#define TCP_SOCK_SEND_TIMEOUT           (2)
#define TCP_SOCK_PROTOCOL               (3)
#define TCP_SOCK_PORT                   (4)
#define TCP_SOCK_INACTIVE_TIMEOUT       (5)
#define TCP_SOCK_KEEPALIVE_TIMEOUT      (6)
#define TCP_SOCK_ADD_MEMBERSHIP         (7)
#define TCP_SOCK_DROP_MEMBERSHIP        (8)
#define TCP_SOCK_MULTICAST_TTL          (9)
#define TCP_SOCK_MULTICAST_LOOP         (10)
#define TCP_SOCK_TOS                    (11)
#define TCP_SOCK_VLAN                   (12)

/* Limits for command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ                     */
#define IP_TTL_MIN                      1   /* TTL (Time To Live) min value     */
#define IP_TTL_MAX                      255 /* TTL (Time To Live) max value     */

#define IP_TOS_MIN                      0   /* TOS (Type of Service) min value  */
#define IP_TOS_MAX                      255 /* TOS (Type of Service) max value  */
                                            /* is a byte value                  */
      /* Attention: Be very careful with this parameter! See RFCs 791 (old      */
      /* meaning of this parameter), 2474 (DSCP), 3168 (ECN)                    */

#define IP_VLAN_PRIO_MAX                    7     /* VLAN priority max value    */
#define IP_VLAN_ID_MAX                      0xFFF /* VLAN id max value          */


/* Packets for setting socket options - TCP_UDP_CMD_SET_SOCK_OPTION */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_Ttag
{
  TLR_UINT32  ulMode;

  __TCPIP_PACKED_PRE union
  {
    TLR_UINT32  ulTtl;
    TLR_UINT32  ulTimeoutSend;
    TLR_UINT32  ulTimeoutInactive;
    TLR_UINT32  ulTimeoutKeepAlive;
    TLR_UINT32  ulMulticastGroup;
    TLR_UINT32  ulMulticastTtl;
    TLR_UINT32  ulMulticastLoop;
    TLR_UINT32  ulTos;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT8  bEnable;
      TLR_UINT16 usId;
      TLR_UINT8  bPriority;
    } __TCPIP_PACKED_POST tVlanTag;

  } __TCPIP_PACKED_POST unParam;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_T;

#define TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_SIZE  \
              (sizeof(TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_Ttag
{
  TLR_PACKET_HEADER_T                           tHead;
  TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_Ttag
{
  TLR_UINT32  ulMode;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_T;

#define TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_SIZE  \
              (sizeof(TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_Ttag
{
  TLR_PACKET_HEADER_T                           tHead;
  TCPIP_DATA_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_T;




/* Packets for obtaining socket options - TCP_UDP_CMD_GET_SOCK_OPTION */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_Ttag
{
  TLR_UINT32  ulMode;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_T;

#define TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_SIZE  \
              (sizeof(TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_Ttag
{
  TLR_PACKET_HEADER_T                           tHead;
  TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_Ttag
{
  TLR_UINT32  ulMode;

  __TCPIP_PACKED_PRE union
  {
    TLR_UINT32  ulTtl;
    TLR_UINT32  ulTimeoutSend;
    TLR_UINT32  ulProtocol;
    TLR_UINT32  ulPort;
    TLR_UINT32  ulTimeoutInactive;
    TLR_UINT32  ulTimeoutKeepAlive;
    TLR_UINT32  ulMulticastTtl;
    TLR_UINT32  ulMulticastLoop;
    TLR_UINT32  ulTos;

    __TCPIP_PACKED_PRE struct
    {
      TLR_UINT8  bEnable;
      TLR_UINT16 usId;
      TLR_UINT8  bPriority;
    } __TCPIP_PACKED_POST tVlanTag;

  } __TCPIP_PACKED_POST unParam;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_T;

#define TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_SIZE  \
              (sizeof(TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_Ttag
{
  TLR_PACKET_HEADER_T                           tHead;
  TCPIP_DATA_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_T;




/* Packets for getting the TCP task state - TCP_CMD_GET_TASK_STATE */
#define TCPIP_DATA_TCP_CMD_GET_TASK_STATE_REQ_SIZE    0

typedef struct TCPIP_PACKET_TCP_CMD_GET_TASK_STATE_REQ_Ttag
{
  TLR_PACKET_HEADER_T                      tHead;

} TCPIP_PACKET_TCP_CMD_GET_TASK_STATE_REQ_T;


#define TCPIP_DATA_TCP_CMD_GET_TASK_STATE_CNF_SIZE    0

typedef struct TCPIP_PACKET_TCP_CMD_GET_TASK_STATE_CNF_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_TCP_CMD_GET_TASK_STATE_CNF_T;









/* Packets for binding a socket to a local name (IP address, port) - TCP_UDP_CMD_BIND */

typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_BIND_REQ_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_BIND_REQ_T;

#define TCPIP_DATA_TCP_UDP_CMD_BIND_REQ_SIZE \
                            (sizeof(TCPIP_DATA_TCP_UDP_CMD_BIND_REQ_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_BIND_REQ_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  TCPIP_DATA_TCP_UDP_CMD_BIND_REQ_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_BIND_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_BIND_CNF_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_BIND_CNF_T;

#define TCPIP_DATA_TCP_UDP_CMD_BIND_CNF_SIZE \
                            (sizeof(TCPIP_DATA_TCP_UDP_CMD_BIND_CNF_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_BIND_CNF_Ttag
{
  TLR_PACKET_HEADER_T                tHead;
  TCPIP_DATA_TCP_UDP_CMD_BIND_CNF_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_BIND_CNF_T;


/* Packets for enabling/disabling ACD - TCPIP_TCP_UDP_CMD_ENABLE_ACD_REQ */

typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_ENABLE_ACD_REQ_Ttag
{
  TLR_UINT32        ulEnable;    /* Enable (1) or disable (0) the ACD mechanism */
  TLR_UINT32        ulQC_Active; /* Quick Connect Status, 0: QC OFF, 1: QC ON   */

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_ENABLE_ACD_REQ_T;

#define TCPIP_PACKET_TCP_UDP_CMD_ENABLE_ACD_REQ_SIZE  \
              (sizeof(TCPIP_DATA_TCP_UDP_CMD_ENABLE_ACD_REQ_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_ENABLE_ACD_REQ_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;
  TCPIP_DATA_TCP_UDP_CMD_ENABLE_ACD_REQ_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_ENABLE_ACD_REQ_T;


typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_ENABLE_ACD_CNF_Ttag
{
  TLR_UINT32        ulEnable; /* Enabled (1) or disabled (0) the ACD mechanism */

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_ENABLE_ACD_CNF_T;

#define TCPIP_PACKET_TCP_UDP_CMD_ENABLE_ACD_CNF_SIZE   (sizeof(TCPIP_DATA_TCP_UDP_CMD_ENABLE_ACD_CNF_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_ENABLE_ACD_CNF_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;
  TCPIP_DATA_TCP_UDP_CMD_ENABLE_ACD_CNF_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_ENABLE_ACD_CNF_T;


/* Packets for stopping Quick Connect ARPs - TCPIP_TCP_UDP_CMD_STOP_QC_ARPS_REQ */

#define TCPIP_PACKET_TCP_UDP_CMD_STOP_QC_ARPS_REQ_SIZE  (0)

typedef struct TCPIP_PACKET_TCP_UDP_CMD_STOP_QC_ARPS_REQ_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;

} TCPIP_PACKET_TCP_UDP_CMD_STOP_QC_ARPS_REQ_T;


#define TCPIP_PACKET_TCP_UDP_CMD_STOP_QC_ARPS_CNF_SIZE   (0)

typedef struct TCPIP_PACKET_TCP_UDP_CMD_STOP_QC_ARPS_CNF_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;

} TCPIP_PACKET_TCP_UDP_CMD_STOP_QC_ARPS_CNF_T;


/* Packets for setting the host and domain name (DHCP option 81) - TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_REQ */

typedef struct TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_DATA_Ttag{
  TLR_CHAR szDomainName[TCP_MAX_DOMAIN_NAME];
  TLR_CHAR szHostName[TCP_MAX_HOST_NAME];
}TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_DATA_T;

typedef struct TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_REQ_Ttag{
  TLR_PACKET_HEADER_T                         tHead;
  TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_DATA_T   tData;
}TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_REQ_T;

#define TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_REQ_T_SIZE   (sizeof(TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_DATA_T))


typedef struct TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_CNF_Ttag{
  TLR_PACKET_HEADER_T                         tHead;
}TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_CNF_T;

#define TCPIP_TCP_SET_HOST_AND_DOMAIN_NAME_CNF_T_SIZE   (0)


/** Union enclosing all server packets **/
typedef union TCP_TASK_PACKET_SERVERtag
{
  TLR_PACKET_HEADER_T                             tHead;

  /* Packets for providing configuration data - IP_CMD_SET_CONFIG */
  TCPIP_PACKET_IP_CMD_SET_CONFIG_REQ_T            tIpCmdSetConfigReq;
  TCPIP_PACKET_IP_CMD_SET_CONFIG_CNF_T            tIpCmdSetConfigCnf;

  /* Packets for obtaining configuration data - IP_CMD_GET_CONFIG */
  TCPIP_PACKET_IP_CMD_GET_CONFIG_REQ_T            tIpCmdGetConfigReq;
  TCPIP_PACKET_IP_CMD_GET_CONFIG_CNF_T            tIpCmdGetConfigCnf;

  /* Packets for setting IP parameters - IP_CMD_SET_PARAM */
  TCPIP_PACKET_IP_CMD_SET_PARAM_REQ_T             tIpCmdSetParamReq;
  TCPIP_PACKET_IP_CMD_SET_PARAM_CNF_T             tIpCmdSetParamCnf;

  /* Packets for obtaining IP parameters - IP_CMD_GET_PARAM */
  TCPIP_PACKET_IP_CMD_GET_PARAM_REQ_T             tIpCmdGetParamReq;
  TCPIP_PACKET_IP_CMD_GET_PARAM_CNF_T             tIpCmdGetParamCnf;

  /* Packets for obtaining TCP/IP stack capabilities - IP_CMD_GET_OPTIONS */
  TCPIP_PACKET_IP_CMD_GET_OPTIONS_REQ_T           tIpCmdGetOptionsReq;
  TCPIP_PACKET_IP_CMD_GET_OPTIONS_CNF_T           tIpCmdGetOptionsCnf;

  /* Packets for sending a ping - IP_CMD_PING */
  TCPIP_PACKET_IP_CMD_PING_REQ_T                  tIpCmdPingReq;
  TCPIP_PACKET_IP_CMD_PING_CNF_T                  tIpCmdPingCnf;

  /* Packets for sending a ICMP indication - TCPIP_IP_CMD_ICMP_IND */
  TCPIP_PACKET_IP_CMD_ICMP_IND_T                  tIpCmdIcmpInd;
  TCPIP_PACKET_IP_CMD_ICMP_RES_T                  tIpCmdIcmpRes;

  /* Packets for opening a socket - TCP_UDP_CMD_OPEN */
  TCPIP_PACKET_TCP_UDP_CMD_OPEN_REQ_T             tTcpUdpCmdOpenReq;
  TCPIP_PACKET_TCP_UDP_CMD_OPEN_CNF_T             tTcpUdpCmdOpenCnf;

  /* Packets for closing a socket - TCP_UDP_CMD_CLOSE */
  TCPIP_PACKET_TCP_UDP_CMD_CLOSE_REQ_T            tTcpUdpCmdCloseReq;
  TCPIP_PACKET_TCP_UDP_CMD_CLOSE_CNF_T            tTcpUdpCmdCloseCnf;

  /* Packets for closing all sockets - TCP_UDP_CMD_CLOSE_ALL */
  TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_REQ_T        tTcpUdpCmdCloseAllReq;
  TCPIP_PACKET_TCP_UDP_CMD_CLOSE_ALL_CNF_T        tTcpUdpCmdCloseAllCnf;

  /* Packets for waiting for an incoming TCP connection - TCP_CMD_WAIT_CONNECT */
  TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_REQ_T         tTcpCmdWaitConnectReq;
  TCPIP_PACKET_TCP_CMD_WAIT_CONNECT_CNF_T         tTcpCmdWaitConnectCnf;

  /* Packets for establishing a TCP connection - TCP_CMD_CONNECT */
  TCPIP_PACKET_TCP_CMD_CONNECT_REQ_T              tTcpCmdConnectReq;
  TCPIP_PACKET_TCP_CMD_CONNECT_CNF_T              tTcpCmdConnectCnf;

  /* Packets for sending TCP data - TCP_CMD_SEND */
  TCPIP_PACKET_TCP_CMD_SEND_REQ_T                 tTcpCmdSendReq;
  TCPIP_PACKET_TCP_CMD_SEND_CNF_T                 tTcpCmdSendCnf;

  /* Packets for sending UDP data - UDP_CMD_SEND */
  TCPIP_PACKET_UDP_CMD_SEND_REQ_T                 tUdpCmdSendReq;
  TCPIP_PACKET_UDP_CMD_SEND_CNF_T                 tUdpCmdSendCnf;

  /* Packets for setting socket options - TCP_UDP_CMD_SET_SOCK_OPTION */
  TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_REQ_T  tTcpUdpCmdSetSockOptionReq;
  TCPIP_PACKET_TCP_UDP_CMD_SET_SOCK_OPTION_CNF_T  tTcpUdpCmdSetSockOptionCnf;

  /* Packets for obtaining socket options - TCP_UDP_CMD_GET_SOCK_OPTION */
  TCPIP_PACKET_TCP_UDP_CMD_GET_SOCK_OPTION_REQ_T  tTcpUdpCmdGetSockOptionReq;
  TCPIP_PACKET_TCP_UDP_CMD_GET_SOCK_OPTION_CNF_T  tTcpUdpCmdGetSockOptionCnf;

  /* Packets for binding a socket - TCP_UDP_CMD_BIND */
  TCPIP_PACKET_TCP_UDP_CMD_BIND_REQ_T             tTcpUdpCmdBindReq;
  TCPIP_PACKET_TCP_UDP_CMD_BIND_CNF_T             tTcpUdpCmdBindCnf;

  /* Packets for getting the TCP task state - TCP_CMD_GET_TASK_STATE */
  TCPIP_PACKET_TCP_CMD_GET_TASK_STATE_REQ_T       tTcpCmdGetTaskStateReq;
  TCPIP_PACKET_TCP_CMD_GET_TASK_STATE_CNF_T       tTcpCmdGetTaskStateCnf;

  /* Packets for providing configuration data - TCP_UDP_CMD_ENABLE_ACD */
  TCPIP_PACKET_TCP_UDP_CMD_ENABLE_ACD_REQ_T       tIpCmdEnableAcdReq;
  TCPIP_PACKET_TCP_UDP_CMD_ENABLE_ACD_CNF_T       tIpCmdEnableAcdCnf;

} TCP_TASK_PACKET_SERVER;


/*###############################################################################################*/
/*###############################################################################################*/

/*** Definition of the packet types this Task send/receive as client ***/

/*###############################################################################################*/

/* Packet for receiving TCP data and UDP data - TCP_UDP_CMD_RECEIVE */

/* Options of packet ulOptions variable */
#define TCP_RECV_OPT_BROADCAST          (0x00000001)
#define TCP_RECV_OPT_MULTICAST          (0x00000002)

typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_RECEIVE_IND_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;
  TLR_UINT32  ulOptions;
  TLR_UINT8   abData[TCPIP_MAX_TCP_UDP_DATA_CNT];

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_RECEIVE_IND_T;

#define TCPIP_DATA_TCP_UDP_CMD_RECEIVE_IND_SIZE              \
              (sizeof(TCPIP_DATA_TCP_UDP_CMD_RECEIVE_IND_T)  \
               - TCPIP_MAX_TCP_UDP_DATA_CNT                )

typedef struct TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_IND_Ttag
{
  TLR_PACKET_HEADER_T                   tHead;
  TCPIP_DATA_TCP_UDP_CMD_RECEIVE_IND_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_IND_T;

/* No response packet here! The application will return the packet back */
/* to the TCP_UDP-task context via TLR_QUE_RETURNPACKET()               */

/*###############################################################################################*/
/*###############################################################################################*/

/* Packets for shutdown of the device - TCP_UDP_CMD_SHUTDOWN */
typedef struct TCPIP_PACKET_TCP_UDP_CMD_SHUTDOWN_IND_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_TCP_UDP_CMD_SHUTDOWN_IND_T;

typedef struct TCPIP_PACKET_TCP_UDP_CMD_SHUTDOWN_RES_Ttag
{
  TLR_PACKET_HEADER_T  tHead;

} TCPIP_PACKET_TCP_UDP_CMD_SHUTDOWN_RES_T;

/*###############################################################################################*/
/*###############################################################################################*/

/* Packet for stop receiving of TCP data and UDP data - TCP_UDP_CMD_RECEIVE_STOP */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_RECEIVE_STOP_IND_Ttag
{
  TLR_UINT32  ulIpAddr;
  TLR_UINT32  ulPort;
  TLR_UINT32  ulOptions;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_RECEIVE_STOP_IND_T;

#define TCPIP_DATA_TCP_UDP_CMD_RECEIVE_STOP_IND_SIZE  \
              (sizeof(TCPIP_DATA_TCP_UDP_CMD_RECEIVE_STOP_IND_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_STOP_IND_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;
  TCPIP_DATA_TCP_UDP_CMD_RECEIVE_STOP_IND_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_STOP_IND_T;

/* No response packet here! The application will return the packet back */
/* to the TCP_UDP-task context via TLR_QUE_RETURNPACKET()               */

/*###############################################################################################*/
/*###############################################################################################*/
/* Address conflict reasons */
#define TCPIP_ACD_CONFL_RSN_DEFAULT       1   /* Conflict occurred --> Ceased using IP address */
#define TCPIP_ACD_CONFL_RSN_DEFENDED_IP   2   /* Defended IP address                           */

/* ACD States --> bAcdActivity */

#define TCPIP_ACD_CONFLICT_STATE_PROBING           1   /* Conflict occurred during probing phase           */
#define TCPIP_ACD_CONFLICT_STATE_ONGOING_DETECTION 2   /* Conflict occurred during ongoing detection phase */
#define TCPIP_ACD_CONFLICT_STATE_SEMI_ACTIVE       3   /* Conflict occurred during semi active phase       */

/* Structure of data area of an Ethernet ARP packet */
typedef __PACKED_PRE struct
{
  TLR_UINT16   usHardwAddrType;
  TLR_UINT16   usProtocolType;
  TLR_UINT8    usHardwSize;
  TLR_UINT8    usProtocolSize;
  TLR_UINT16   usOpCode;
  TLR_UINT8    abSenderMacAddr[6];
  TLR_UINT32   ulSenderIpAddr;
  TLR_UINT8    abTargetMacAddr[6];
  TLR_UINT32   ulTargetIpAddr;

} __PACKED_POST TCPIP_ARP_PACKET;

/* Packet for ACD conflict indications - TCPIP_TCP_UDP_CMD_ACD_CONFLICT_IND */
typedef __TCPIP_PACKED_PRE struct TCPIP_DATA_TCP_UDP_CMD_ACD_CONFLICT_IND_Ttag
{
  TLR_UINT32        ulReason;
  TLR_UINT8         bAcdActivity;
  TCPIP_ARP_PACKET  tLastConflictArp;

} __TCPIP_PACKED_POST TCPIP_DATA_TCP_UDP_CMD_ACD_CONFLICT_IND_T;

#define TCPIP_DATA_TCP_UDP_CMD_ACD_CONFLICT_IND_SIZE  \
              (sizeof(TCPIP_DATA_TCP_UDP_CMD_ACD_CONFLICT_IND_T))

typedef struct TCPIP_PACKET_TCP_UDP_CMD_ACD_CONFLICT_IND_Ttag
{
  TLR_PACKET_HEADER_T                        tHead;
  TCPIP_DATA_TCP_UDP_CMD_ACD_CONFLICT_IND_T  tData;

} TCPIP_PACKET_TCP_UDP_CMD_ACD_CONFLICT_IND_T;



/* No response packet here! The application will return the packet back */
/* to the TCP_UDP-task context via TLR_QUE_RETURNPACKET()               */


#if defined( _TCPIP_EIF_PACKET_ROUTER_ )
/******************************************************************************
 * Packet: TCPIP_TCPTASK_FRAME_IND/TCPIP_TCPTASK_FRAME_RES/TCPIP_TCPTASK_FRAME_REQ/TCPIP_TCPTASK_FRAME_CNF
 */

#define TCPIP_TCPTASK_FRAME_DATA_SIZE     1504
#define TCPIP_TCPTASK_FRAME_HEADER_SIZE   14

/* indication packet */
typedef __PACKED_PRE struct TCPIP_TCPTASK_FRAME_IND_DATA_Ttag
{
  /* flags associated with frame */
  TLR_UINT16            usFlags;
  /* port on which this has to be forwarded */
  TLR_UINT16            usPortNo;
  /* time stamp value */
  TLR_UINT32            ulTimestampNs;
  /* dest MAC address */
  TLR_UINT8             abDstMacAddr[6];
  /* source MAC address */
  TLR_UINT8             abSrcMacAddr[6];
  /* ether type in network byte order */
  TLR_UINT16            usEthType;
  /* abData (including VlanHeader if available (1500 bytes of data is max MTU of Ethernet)) */
  TLR_UINT8             abData[TCPIP_TCPTASK_FRAME_DATA_SIZE];
} __PACKED_POST TCPIP_TCPTASK_FRAME_IND_DATA_T;

#define TCPIP_TCPTASK_FRAME_FLAG_TIME_REQUEST        0x0001
#define TCPIP_TCPTASK_FRAME_FLAG_TIME_VALID          0x0002

typedef struct TCPIP_TCPTASK_FRAME_IND_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
  TCPIP_TCPTASK_FRAME_IND_DATA_T  tData;
} TCPIP_TCPTASK_FRAME_IND_T;
typedef TCPIP_TCPTASK_FRAME_IND_T TCPIP_TCPTASK_FRAME_REQ_T;

/* response packet */
typedef __PACKED_PRE struct TCPIP_TCPTASK_FRAME_RES_DATA_Ttag
{
  TLR_UINT16            usFlags;        /* TCPIP_TCPTASK_FRAME_FLAG_TIME_VALID specifies whether ulTimestamp* contain valid data */
  TLR_UINT32            ulTimestampNs;
  TLR_UINT16            usFrameLen;
  /* this packet must be end before the original frame starts */
} __PACKED_POST TCPIP_TCPTASK_FRAME_RES_DATA_T;

typedef struct TCPIP_TCPTASK_FRAME_RES_Ttag
{
  TLR_PACKET_HEADER_T             tHead;
  TCPIP_TCPTASK_FRAME_RES_DATA_T  tData;
} TCPIP_TCPTASK_FRAME_RES_T;

typedef TCPIP_TCPTASK_FRAME_RES_T TCPIP_TCPTASK_FRAME_CNF_T;

typedef union TCPIP_TCPTASK_FRAME_PCK_Ttag
{
  TLR_PACKET_HEADER_T tHead;
  TCPIP_TCPTASK_FRAME_REQ_T tFrameReq;
  TCPIP_TCPTASK_FRAME_CNF_T tFrameCnf;
} TCPIP_TCPTASK_FRAME_PCK_T;


/* IP (config) parameter indication packet */
#define TCPIP_DATA_EIF_CMD_IP_CONFIG_IND_SIZE \
                            (sizeof(TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_T))

typedef TCPIP_PACKET_IP_CMD_SET_CONFIG_REQ_T  TCPIP_PACKET_EIF_CMD_IP_CONFIG_IND_T;
typedef TCPIP_PACKET_IP_CMD_SET_CONFIG_CNF_T  TCPIP_PACKET_EIF_CMD_IP_CONFIG_RES_T;

#endif  /* #if defined( _TCPIP_EIF_PACKET_ROUTER_ ) */


/** Union enclosing all client packets **/
typedef union TCP_TASK_PACKET_CLIENT_Ttag
{
  TLR_PACKET_HEADER_T                      tHead;

  /* Packet for receiving TCP data and UDP data - TCP_UDP_CMD_RECEIVE */
  TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_IND_T       tTcpUdpCmdReceiveInd;
  /* No _RES_T packet here! */

  /* Packets for shutdown of the device - TCP_UDP_CMD_SHUTDOWN */
  TCPIP_PACKET_TCP_UDP_CMD_SHUTDOWN_IND_T      tTcpUdpCmdShutdownInd;
  TCPIP_PACKET_TCP_UDP_CMD_SHUTDOWN_RES_T      tTcpUdpCmdShutdownRes;

  TCPIP_PACKET_TCP_UDP_CMD_RECEIVE_STOP_IND_T  tTcpUdpCmdReceiveStopInd;
  /* No _RES_T packet here! */

#if defined( _TCPIP_EIF_PACKET_ROUTER_ )
  TCPIP_TCPTASK_FRAME_PCK_T                    tHalEddFrame;  /* union for Ind/Res, ... */
#endif  /* #if defined( _TCPIP_EIF_PACKET_ROUTER_ ) */

} TCP_TASK_PACKET_CLIENT_T;



/*---------------------------------------------------------------------------*/
/* Compiler settings */
#if _MSC_VER >= 1000
  #pragma pack()           /* Always allign structures to compiler settings  */
#endif /* _MSC_VER >= 1000 */
/*---------------------------------------------------------------------------*/

#undef __TCPIP_PACKED_PRE
#undef __TCPIP_PACKED_POST

#endif /* #ifndef __TCPIP_TCP_TASK_PUBLIC_H */

