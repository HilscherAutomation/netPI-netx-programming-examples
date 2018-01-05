/*******************************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************************

   Filename:
    $Workfile: EthIntf_Public.h $
   Last Modification:
    @version $Id: EthIntf_Public.h 19347 2011-09-20 07:58:07Z andreasme $
    $Author: Eric $
    $Modtime: 15.05.07 9:59 $
    $Revision: 1 $

   Targets:
    Win32/ANSI   : no
    Win32/Unicode: no (define _UNICODE)
    WinCE        : yes
    rcX          : yes

   Description:

    Eth Intf
    public

   Changes:

     Version    Date        Author
        Description
     ---------------------------------------------------------------------------------------
                24.07.2009  VD/MS
        Added support for Ethernet interface firmware option module (Mantis ID 0006410):
          Added ETH_INTF_TASK_NAME
          Added command ETH_INTF_REGISTER_EDD_REQ/_CNF
          Added packet ETH_INTF_REGISTER_EDD_REQ_T/_CNF_T
     
     5					02.07.09	  AM
     		Extended SetConfig service request & confirmation.
     		
     4          22.06.09    VD
        Changed postion of __PACKED_POST to avoid trouble with GCC < 4.0
        (overtaken changes form UJ, 28.04.09)

     3          04.11.08-   VD
                13.11.08
        Added _TCPIP_EIF_PACKET_ROUTER_: Added command ETH_INTF_RECV_IP_CONFIG_IND/RES and
        packet ETH_INTF_RECV_IP_CONFIG_IND_PCK_T/ETH_INTF_RECV_IP_CONFIG_RES_PCK_T

     2          07.07.08    ES
        Added handling for 2 standard ethernet ports

*******************************************************************************************/
/**
 * @file EthIntf_Public.h
 *  Eth Intf - public definition of task
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

#ifndef __ETH_INTF_PUBLIC_H
#define __ETH_INTF_PUBLIC_H

#include <stdint.h>

/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(__ETH_INTF_PACKET)
#endif

/** @defgroup ethintf_public_api Ethernet Interface Public API
 * @ingroup task_ethintf
 *
 * This section describes the API between Host application and
 * Ethernet Interface Task.
 *
 * \see \ref ethintf_doc
 * @{
 */

/** Size of an ethernet mac address */
#define ETH_INTF_ETH_ADDR_SIZE          (6)

typedef enum ETH_INTF_LINK_STATUS_Etag {
  ETH_INTF_LINK_STATUS_NOK = 0,                 /**< Link status not OK              */
  ETH_INTF_LINK_STATUS_OK  = 1,                 /**< Link status OK                  */
} ETH_INTF_LINK_STATUS_E;

typedef enum ETH_INTF_AUTO_NEGOTIATION_Etag {
  ETH_INTF_AUTO_NEGOTIATION_OFF = 0,            /**< Auto-Negtiation deactivated     */
  ETH_INTF_AUTO_NEGOTIATION_ON  = 1,            /**< Auto-Negtiation activated       */
} ETH_INTF_AUTO_NEGOTIATION_E;

typedef enum ETH_INTF_DUPLEX_Etag {
  ETH_INTF_HALF_DUPLEX = 0,                     /**< Half-Duplex                     */
  ETH_INTF_FULL_DUPLEX = 1,                     /**< Full-Duplex                     */
} ETH_INTF_DUPLEX_E;

typedef enum ETH_INTF_TRANSMISSION_RATE_Etag {
  ETH_INTF_TRANSMISSION_RATE_UNK  =   0,         /**< UNK                            */
  ETH_INTF_TRANSMISSION_RATE_10   =  10,         /**< 10  MBit/s                     */
  ETH_INTF_TRANSMISSION_RATE_100  = 100,         /**< 100 MBit/s                     */
} ETH_INTF_TRANSMISSION_RATE_E;

typedef enum ETH_INTF_AUTO_CROSSOVER_Etag {
  ETH_INTF_AUTO_CROSSOVER_OFF = 0,              /**< Auto cross-over deactivated     */
  ETH_INTF_AUTO_CROSSOVER_ON  = 1,              /**< Auto cross-over activated       */
} ETH_INTF_AUTO_CROSSOVER_E;

typedef enum ETH_INTF_TSK_FLAGS_Etag {
  ETH_INTF_TSK_FLAGS_CONFIGURED   = 0x00000001, /* Flag: Task is configured          */
  ETH_INTF_TSK_FLAGS_APP_REGISTER = 0x00000002, /* Flag: Application is registered   */
  ETH_INTF_TSK_FLAGS_APP_NOT_RDY  = 0x00000004, /* Flag: Application set not ready   */
  ETH_INTF_TSK_FLAGS_APP_CFG_LOCK = 0x00000008, /* Flag: Application set config lock */

  ETH_INTF_TSK_FLAGS_COM_READY    = 0x00000100, /* Flag: Communication is ready      */

  ETH_INTF_TSK_FLAGS_LINK_0_OK    = 0x00010000, /* Flag: Link 0 OK                   */
  ETH_INTF_TSK_FLAGS_LINK_1_OK    = 0x00020000, /* Flag: Link 1 OK                   */
} ETH_INTF_TSK_FLAGS_E;

/** Extended Status Area content in case of PROT_CLASS_ETHERNET"
 */
typedef __PACKED_PRE struct ETH_INTF_EXTENDED_STATE_ETH_Ttag
{
  /** The mac address of the ethernet interface
   *
   * This is set to zero if ethernet mac is not available */
  TLR_UINT8 abMacAddress[ETH_INTF_ETH_ADDR_SIZE];
  /** The current mau type according IANA */
  TLR_UINT8 bMautype;
  /** alignment */
  TLR_UINT8  bPadding;
  /** The current ip address of the local TCP/IP stack */
  uint32_t   ulIpAddress;
  /** The current network mask of the local TCP/IP stack */
  uint32_t   ulNetMask;
  /** The current gateway address of the local TCP/IP stack */
  uint32_t   ulGateway;
  /** The number of received packets passed to the host */
  uint64_t   ullIfInPkts;
  /** The number of received packets not passed to the host because of
   ** packet queue overflow */
  uint64_t   ullIfInDiscards;
  /** The number of sent ethernet frames */
  uint64_t   ullIfOutPkts;
  /** The number of ethernet frames dropped because of no
   ** ethernet frame buffer available */
  uint64_t   ullIfOutDiscards;
  /** the number of bytes received */
  uint64_t   ullIfInBytes;
  /** the number of bytes transmitted */
  uint64_t   ullIfOutBytes;
} __PACKED_POST ETH_INTF_EXTENDED_STATE_ETH_T;

/** Extended status Area Content in case of PROT_CLASS_OEM
 */
typedef __PACKED_PRE struct ETH_INTF_EXTENDED_STATE_OEM_Ttag
{
  TLR_UINT8   abEthernetAddrPort0[ETH_INTF_ETH_ADDR_SIZE];
  TLR_UINT8   abEthernetAddrPort1[ETH_INTF_ETH_ADDR_SIZE];

  TLR_UINT32  ulLinkStatusPort0;
  TLR_UINT32  ulLinkStatusPort1;

  TLR_UINT32  ulAutoNegotiationPort0;
  TLR_UINT32  ulAutoNegotiationPort1;

  TLR_UINT32  ulDuplexMode0;
  TLR_UINT32  ulDuplexMode1;

  TLR_UINT32  ulTransmissionRatePort0;
  TLR_UINT32  ulTransmissionRatePort1;

  TLR_UINT32  ulReserved1Port0;
  TLR_UINT32  ulReserved1Port1;

  TLR_UINT32  ulReserved2Port0;
  TLR_UINT32  ulReserved2Port1;

  TLR_UINT32  ulRxCntPort0;
  TLR_UINT32  ulRxCntPort1;

  TLR_UINT32  ulTxCntPort0;
  TLR_UINT32  ulTxCntPort1;

  TLR_UINT32  ulRxErrCntPort0;
  TLR_UINT32  ulRxErrCntPort1;

  TLR_UINT32  ulTxErrCntPort0;
  TLR_UINT32  ulTxErrCntPort1;

  TLR_UINT32  ulRxEthOverrunCntPort0;
  TLR_UINT32  ulRxEthOverrunCntPort1;

  TLR_UINT32  ulTxEthOverrunCntPort0;
  TLR_UINT32  ulTxEthOverrunCntPort1;

  TLR_UINT32  ulRxQueOverrunCntPort0;
  TLR_UINT32  ulRxQueOverrunCntPort1;

  TLR_UINT32  ulTxQueOverrunCntPort0;
  TLR_UINT32  ulTxQueOverrunCntPort1;

  TLR_UINT32  ulRxQueFillLevelPort0;
  TLR_UINT32  ulRxQueFillLevelPort1;

  TLR_UINT32  ulTxQueFillLevelPort0;
  TLR_UINT32  ulTxQueFillLevelPort1;

  TLR_UINT32  ulEthIntfTskFlags;
  TLR_UINT32  ulEthIntfTskStatusUpdateCnt;
  TLR_UINT32  ulEthIntfTskError;
  TLR_UINT32  ulEthIntfTskErrCnt;
} __PACKED_POST ETH_INTF_EXTENDED_STATE_OEM_T;

/** backwards compat typedef */
typedef ETH_INTF_EXTENDED_STATE_OEM_T ETH_INTF_DIAGNOSTIC_INFO_T;

/** Ethernet interface extended status area */
typedef union ETH_INTF_EXTENDED_STATE_Ttag
{
  /** Valid for PROT_CLASS_ETHERNET */
  ETH_INTF_EXTENDED_STATE_ETH_T tEth;
  /** Valid for PROT_CLASS_OEM */
  ETH_INTF_EXTENDED_STATE_OEM_T tOem;
} ETH_INTF_EXTENDED_STATE_T;

/** Packet Command Codes
 *
 * Besides these commands, the Ethernet Interface Task handles
 * the following standard commands:
 * - RCX_REGISTER_APP_REQ/RCX_REGISTER_APP_CNF
 * - RCX_UNREGISTER_APP_REQ/RCX_UNREGISTER_APP_CNF
 * - RCX_FIRMWARE_IDENTIFY_REQ
 * - DIAG_INFO_GET_COMMON_STATE_REQ
 * - DIAG_INFO_GET_EXTENDED_STATE_REQ
 */
typedef enum
{
  /** Set config request/confirmation */
  ETH_INTF_SET_CONFIG_REQ =         0x00003B00,
  ETH_INTF_SET_CONFIG_CNF =         0x00003B01,

  /** Send Ethernet frame request/confirmation */
  ETH_INTF_SEND_ETH_FRAME_REQ =     0x00003B02,
  ETH_INTF_SEND_ETH_FRAME_CNF =     0x00003B03,

  /** Receive Ethernet frame indication/response */
  ETH_INTF_RECV_ETH_FRAME_IND =     0x00003B04,
  ETH_INTF_RECV_ETH_FRAME_RES =     0x00003B05,

  /** Register application request/confirmation */
  ETH_INTF_REGISTER_APP_REQ =       0x00003B06,
  ETH_INTF_REGISTER_APP_CNF =       0x00003B07,

  /** Receive IP config indication/response */
  ETH_INTF_RECV_IP_CONFIG_IND =     0x00003B08,
  ETH_INTF_RECV_IP_CONFIG_RES =     0x00003B09,


  /** Register EDD request/confirmation (used for
   * registering with the virtual EDD of the TCP/IP stack)
   * */
  ETH_INTF_REGISTER_EDD_REQ =       0x00003B0A,
  ETH_INTF_REGISTER_EDD_CNF =       0x00003B0B,

#if !defined(_ETH_INTF_TEST_OLDNDIS_)
  /** event indication */
  ETH_INTF_CMD_EVENT_IND =          0x00003B20,
  /** event response */
  ETH_INTF_CMD_EVENT_RSP =          0x00003B21,

  /** Send ethernet frame request */
  ETH_INTF_CMD_SEND_ETH_FRAME_REQ = 0x00003B22,
  /** Send ethernet frame confirmation */
  ETH_INTF_CMD_SEND_ETH_FRAME_CNF = 0x00003B23,

  /** Received ethernet frame indication */
  ETH_INTF_CMD_RECV_ETH_FRAME_IND = 0x00003B24,
  /** Received ethernet frame response */
  ETH_INTF_CMD_RECV_ETH_FRAME_RSP = 0x00003B25,
#else
  /** event indication */
  ETH_INTF_CMD_EVENT_IND =          0x00003B00,
  /** event response */
  ETH_INTF_CMD_EVENT_RSP =          0x00003B01,

  /** Send ethernet frame request */
  ETH_INTF_CMD_SEND_ETH_FRAME_REQ = 0x00003B02,
  /** Send ethernet frame confirmation */
  ETH_INTF_CMD_SEND_ETH_FRAME_CNF = 0x00003B03,

  /** Received ethernet frame indication */
  ETH_INTF_CMD_RECV_ETH_FRAME_IND = 0x00003B04,
  /** Received ethernet frame response */
  ETH_INTF_CMD_RECV_ETH_FRAME_RSP = 0x00003B05,
#endif
  ETH_INTF_GET_HW_STAT_REQ    =     0x00003BFC,
  ETH_INTF_GET_HW_STAT_CNF    =     0x00003BFD,

  /** read out specific xc registers. this command is usually
   * disabled and not available for host application */
  ETH_INTF_PEEK_REGISTER_REQ      = 0x00003BFE,
  ETH_INTF_PEEK_REGISTER_CNF      = 0x00003BFF,
} ETH_INTF_CMD_E;


/** @defgroup ethintf_oem_services Services in PROT_CLASS_OEM mode
 *
 * @{
 */

/** Set configuration request data
 *
 * The structure represent the specific request parameter of the service.
 */

typedef enum ETH_INTF_SET_CONFIG_REQ_FLAG_Etag {
  ETH_INTF_SET_CONFIG_REQ_FLAG_USE_ETHERNET = 0x00000001,
  ETH_INTF_SET_CONFIG_REQ_FLAG_USE_TCPIP    = 0x00000002,
} ETH_INTF_SET_CONFIG_REQ_FLAG_E;

typedef __PACKED_PRE struct ETH_INTF_SET_CONFIG_REQ_DATA_Ttag
{
  TLR_UINT32  ulAutoNegotiationPort0;
  TLR_UINT32  ulAutoNegotiationPort1;

  TLR_UINT32  ulDuplexMode0;
  TLR_UINT32  ulDuplexMode1;

  TLR_UINT32  ulTransmissionRatePort0;
  TLR_UINT32  ulTransmissionRatePort1;

  TLR_UINT32  ulAutoCrossOverPort0;
  TLR_UINT32  ulAutoCrossOverPort1;

  TLR_UINT32  ulReserved1Port0;
  TLR_UINT32  ulReserved1Port1;

  TLR_UINT32  ulReserved2Port0;
  TLR_UINT32  ulReserved2Port1;

  TLR_UINT32  ulModeFlags;
} __PACKED_POST ETH_INTF_SET_CONFIG_REQ_DATA_T;

/** set configuration confirmation data
 *
 * The structure represents the return parameters of the service.
 */
typedef enum ETH_INTF_SET_CONFIG_CNF_ETHERNET_STATUS_Etag {
  ETH_INTF_SET_CONFIG_CNF_ETHERNET_STATUS_UNDEF      = 0,
  ETH_INTF_SET_CONFIG_CNF_ETHERNET_STATUS_UNAVAIL    = 1,
  ETH_INTF_SET_CONFIG_CNF_ETHERNET_STATUS_DISABLED   = 2,
  ETH_INTF_SET_CONFIG_CNF_ETHERNET_STATUS_RESTRICTED = 3,
  ETH_INTF_SET_CONFIG_CNF_ETHERNET_STATUS_ENABLED    = 4,
  ETH_INTF_SET_CONFIG_CNF_ETHERNET_STATUS_2NDCHASSIS = 5,
} ETH_INTF_SET_CONFIG_CNF_ETHERNET_STATUS_E;

typedef enum ETH_INTF_SET_CONFIG_CNF_TCPIP_STATUS_Etag {
  ETH_INTF_SET_CONFIG_CNF_TCPIP_STATUS_UNDEF         = 0,
  ETH_INTF_SET_CONFIG_CNF_TCPIP_STATUS_UNAVAIL       = 1,
  ETH_INTF_SET_CONFIG_CNF_TCPIP_STATUS_DISABLED      = 2,
  ETH_INTF_SET_CONFIG_CNF_TCPIP_STATUS_RESTRICTED    = 3,
  ETH_INTF_SET_CONFIG_CNF_TCPIP_STATUS_ENABLED       = 4,
} ETH_INTF_SET_CONFIG_CNF_TCPIP_STATUS_E;

typedef __PACKED_PRE struct ETH_INTF_SET_CONFIG_CNF_DATA_Ttag
{
  TLR_UINT32  ulStatusEthernet;
  TLR_UINT32  ulStatusTcpIp;
} __PACKED_POST ETH_INTF_SET_CONFIG_CNF_DATA_T;

/** deprecated set config request data structue
 *
 * This structure represents the set config request as it was
 * before adding the tcpip support to the ethernet interface task.
 * the old request is still accepted but should not be used in new
 * implementations.
 *
 */

typedef __PACKED_PRE struct ETH_INTF_SET_CONFIG_REQ_DATA_DEPRECATED_Ttag
{
  TLR_UINT32  ulAutoNegotiationPort0;
  TLR_UINT32  ulAutoNegotiationPort1;

  TLR_UINT32  ulDuplexMode0;
  TLR_UINT32  ulDuplexMode1;

  TLR_UINT32  ulTransmissionRatePort0;
  TLR_UINT32  ulTransmissionRatePort1;

  TLR_UINT32  ulAutoCrossOverPort0;
  TLR_UINT32  ulAutoCrossOverPort1;

  TLR_UINT32  ulReserved1Port0;
  TLR_UINT32  ulReserved1Port1;

  TLR_UINT32  ulReserved2Port0;
  TLR_UINT32  ulReserved2Port1;
} __PACKED_POST ETH_INTF_SET_CONFIG_REQ_DATA_DEPRECATED_T;



/** Set configuration request
 */
typedef __PACKED_PRE struct  ETH_INTF_SET_CONFIG_REQ_PCK_Ttag
{
  /** Packet header */
  TLR_PACKET_HEADER_T             tHead;
  /** Packet data */
  ETH_INTF_SET_CONFIG_REQ_DATA_T  tData;
} __PACKED_POST ETH_INTF_SET_CONFIG_REQ_PCK_T;

/** set configuration confirmation
 */
typedef __PACKED_PRE struct  ETH_INTF_SET_CONFIG_CNF_PCK_Ttag
{
  /** packet header */
  TLR_PACKET_HEADER_T             tHead;
  /** packet data */
  ETH_INTF_SET_CONFIG_CNF_DATA_T  tData;
} __PACKED_POST ETH_INTF_SET_CONFIG_CNF_PCK_T;


/** Set configuration request
 */
typedef __PACKED_PRE struct ETH_INTF_SET_CONFIG_REQ_PCK_DEPRECATED_Ttag
{
  /** Packet header */
  TLR_PACKET_HEADER_T                        tHead;
  /** Packet data */
  ETH_INTF_SET_CONFIG_REQ_DATA_DEPRECATED_T  tData;
} __PACKED_POST ETH_INTF_SET_CONFIG_REQ_PCK_DEPRECATED_T;

/** set configuration confirmation
 */
typedef __PACKED_PRE struct  ETH_INTF_SET_CONFIG_CNF_PCK_DEPRECATED_Ttag
{
  /** packet header */
  TLR_PACKET_HEADER_T             tHead;
} __PACKED_POST ETH_INTF_SET_CONFIG_CNF_PCK_DEPRECATED_T;

/******************************************************************************************/
/*             Send Ethernet frame request                                                */
/******************************************************************************************/
#define ETH_INTF_MIN_SEND_ETH_FRAME_SIZE    60  /* Minimum data count for request         */

#define ETH_INTF_MAX_SEND_ETH_FRAME_SIZE  1518  /* Maximum data count for request         */

#define ETH_INTF_SEND_ETH_FRAME_HEADER_SIZE   8 /* 8 Bytes for header (port and reserved) */
#define ETH_INTF_SEND_ETH_FRAME_RSRV_SIZE     4 /* 4 Bytes reserved in send request       */

typedef enum ETH_INTF_SEND_ETH_FRAME_PORT_Etag {
  ETH_INTF_SEND_ETH_FRAME_DEFAULT_PORT = 0, /* Default port for 2 switch    */
  ETH_INTF_SEND_ETH_FRAME_PORT_0       = 1, /* Port 0                       */
  ETH_INTF_SEND_ETH_FRAME_PORT_1       = 2, /* Port 1                       */
} ETH_INTF_SEND_ETH_FRAME_PORT_E;

#define ETH_INTF_MIN_SEND_ETH_FRAME_PACKET_LENGTH \
  ETH_INTF_MIN_SEND_ETH_FRAME_SIZE + ETH_INTF_SEND_ETH_FRAME_HEADER_SIZE

#define ETH_INTF_MAX_SEND_ETH_FRAME_PACKET_LENGTH \
  ETH_INTF_MAX_SEND_ETH_FRAME_SIZE + ETH_INTF_SEND_ETH_FRAME_HEADER_SIZE


/** Send Ethernet frame request data
 */
typedef __PACKED_PRE struct ETH_INTF_SEND_ETH_FRAME_REQ_DATA_Ttag
{
  TLR_UINT32 ulEthPort;
  TLR_UINT32 ulReserved;

  TLR_UINT8  abData[ETH_INTF_MAX_SEND_ETH_FRAME_SIZE];
} __PACKED_POST ETH_INTF_SEND_ETH_FRAME_REQ_DATA_T;

/** Send Ethernet frame request
 */
typedef __PACKED_PRE struct  ETH_INTF_SEND_ETH_FRAME_REQ_PCK_Ttag
{
  /** Packet header */
  TLR_PACKET_HEADER_T                 tHead;
  /** Packet data */
  ETH_INTF_SEND_ETH_FRAME_REQ_DATA_T  tData;
} __PACKED_POST ETH_INTF_SEND_ETH_FRAME_REQ_PCK_T;

/** set configuration confirmation
 */
typedef __PACKED_PRE struct ETH_INTF_SEND_ETH_FRAME_CNF_PCK_Ttag
{
  /** packet header */
  TLR_PACKET_HEADER_T             tHead;
} __PACKED_POST ETH_INTF_SEND_ETH_FRAME_CNF_PCK_T;


/******************************************************************************************/
/*             Receive Ethernet frame indication                                          */
/******************************************************************************************/
#define ETH_INTF_MAX_RECV_ETH_FRAME_SIZE  1518  /* Maximum data count for indication      */

#define ETH_INTF_RECV_ETH_FRAME_HEADER_SIZE  8  /* 8 Bytes not for header (port and resrv)*/
#define ETH_INTF_RECV_ETH_FRAME_RSRV_SIZE    4  /* 4 Bytes reserved in indication         */

typedef enum ETH_INTF_RECV_ETH_FRAME_PORT_Etag {
  ETH_INTF_RECV_ETH_FRAME_PORT_0 = 1,
  ETH_INTF_RECV_ETH_FRAME_PORT_1 = 2,
} ETH_INTF_RECV_ETH_FRAME_PORT_E;

/** Receive Ethernet frame indication data
 */
typedef __PACKED_PRE struct ETH_INTF_RECV_ETH_FRAME_IND_DATA_Ttag
{
  TLR_UINT32 ulEthPort;
  TLR_UINT32 ulReserved;

  TLR_UINT8  abData[ETH_INTF_MAX_RECV_ETH_FRAME_SIZE];
} __PACKED_POST ETH_INTF_RECV_ETH_FRAME_IND_DATA_T;

/** Receive Ethernet frame indication
 */
typedef __PACKED_PRE struct ETH_INTF_RECV_ETH_FRAME_IND_PCK_Ttag
{
  /** Packet header */
  TLR_PACKET_HEADER_T                 tHead;
  /** Packet data */
  ETH_INTF_RECV_ETH_FRAME_IND_DATA_T  tData;
} __PACKED_POST ETH_INTF_RECV_ETH_FRAME_IND_PCK_T;

/** set configuration confirmation
 *
 * The structure defines the confirmation packet of the service.
 */
typedef __PACKED_PRE struct ETH_INTF_RECV_ETH_FRAME_RES_PCK_Ttag
{
  /** packet header */
  TLR_PACKET_HEADER_T             tHead;
} __PACKED_POST ETH_INTF_RECV_ETH_FRAME_RES_PCK_T;


/******************************************************************************************/
/*             Register application request                                               */
/******************************************************************************************/

typedef enum ETH_INTF_REGISTER_Etag {
  ETH_INTF_UNREGISTER_APPLICATION = 0,
  ETH_INTF_REGISTER_APPLICATION   = 1,
} ETH_INTF_REGISTER_E;


/** Register application request data
 */
typedef __PACKED_PRE struct ETH_INTF_REGISTER_APP_REQ_DATA_Ttag
{
  TLR_UINT32 ulMode;
} __PACKED_POST ETH_INTF_REGISTER_APP_REQ_DATA_T;


/** Register application request
 */
typedef __PACKED_PRE struct ETH_INTF_REGISTER_APP_REQ_PCK_Ttag
{
  /** Packet header */
  TLR_PACKET_HEADER_T               tHead;
  /** Packet data */
  ETH_INTF_REGISTER_APP_REQ_DATA_T  tData;
} __PACKED_POST ETH_INTF_REGISTER_APP_REQ_PCK_T;

/** Register application confirmation
 */
typedef __PACKED_PRE struct ETH_INTF_REGISTER_APP_CNF_PCK_Ttag
{
  /** packet header */
  TLR_PACKET_HEADER_T             tHead;
} __PACKED_POST ETH_INTF_REGISTER_APP_CNF_PCK_T;


/******************************************************************************************/
/*             Receive IP configuration indication                                        */
/******************************************************************************************/

/* Flags ulFlags (from TcpipTcpTask_Public.h)! */
#ifndef IP_CFG_FLAG_IP_ADDR
typedef enum IP_CFG_FLAG_Etag {
  IP_CFG_FLAG_IP_ADDR       = 0x0001,
  IP_CFG_FLAG_NET_MASK      = 0x0002,
  IP_CFG_FLAG_GATEWAY       = 0x0004,
  IP_CFG_FLAG_BOOTP         = 0x0008,
  IP_CFG_FLAG_DHCP          = 0x0010,
  IP_CFG_FLAG_ETHERNET_ADDR = 0x0020,
} IP_CFG_FLAG_E;
#endif

/** Receive IP configuration indication data
 */
typedef __PACKED_PRE struct ETH_INTF_RECV_IP_CONFIG_IND_DATA_Ttag
{
  TLR_UINT32  ulFlags;            /* Compatible to TCPIP_DATA_IP_CMD_SET_CONFIG_REQ_T */
  TLR_UINT32  ulIpAddr;           /* from TCP/IP stack                                */
  TLR_UINT32  ulNetMask;
  TLR_UINT32  ulGateway;
  TLR_UINT8   abEthernetAddr[6];

} __PACKED_POST ETH_INTF_RECV_IP_CONFIG_IND_DATA_T;

#define ETH_INTF_DATA_IP_CONFIG_FRAME_IND_SIZE  \
                (sizeof(ETH_INTF_RECV_IP_CONFIG_IND_DATA_T))

/** Receive IP configuration indication
 */
typedef __PACKED_PRE struct ETH_INTF_RECV_IP_CONFIG_IND_PCK_Ttag
{
  /** Packet header */
  TLR_PACKET_HEADER_T                 tHead;
  /** Packet data */
  ETH_INTF_RECV_IP_CONFIG_IND_DATA_T  tData;
} __PACKED_POST ETH_INTF_RECV_IP_CONFIG_IND_PCK_T;

/** Receive IP configuration response
 */
typedef __PACKED_PRE struct  ETH_INTF_RECV_IP_CONFIG_RES_PCK_Ttag
{
  /** packet header */
  TLR_PACKET_HEADER_T             tHead;
} __PACKED_POST ETH_INTF_RECV_IP_CONFIG_RES_PCK_T;

/******************************************************************************************/
/*             Register EDD request                                                       */
/******************************************************************************************/

/** Register EDD request data structure */
typedef __PACKED_PRE struct ETH_INTF_REGISTER_EDD_REQ_DATA_Ttag
{
  TLR_STR                           szQueueName[16]; /* Ethernet interface message queue name (NUL-terminated)  */
  TLR_STR                           szTaskName[16];  /* Ethernet interface task name (NUL-terminated)           */
  TLR_UINT                          uTaskInstance;   /* Ethernet interface task instance number                 */
} __PACKED_POST ETH_INTF_REGISTER_EDD_REQ_DATA_T;

/** Register EDD request packet structure */
typedef __PACKED_PRE struct ETH_INTF_REGISTER_EDD_REQ_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
  ETH_INTF_REGISTER_EDD_REQ_DATA_T  tData;
} __PACKED_POST ETH_INTF_REGISTER_EDD_REQ_T;

/** Register EDD confirmation packet structure */
typedef __PACKED_PRE struct ETH_INTF_REGISTER_EDD_CNF_Ttag
{
  TLR_PACKET_HEADER_T               tHead;
} __PACKED_POST ETH_INTF_REGISTER_EDD_CNF_T;


/** @} */

/** @defgroup ethintf_eth_services Services in PROT_CLASS_ETHERNET mode
 *
 * @{
 */


/******************************************************************************************/
/*             Receive Ethernet frame indication                                          */
/******************************************************************************************/

/** Minimum Ethernet Frame length. (Without FCS) */
#define ETH_INTF_MIN_ETH_FRAME_SIZE  (60)
/** Maximum Ethernet Frame length. (Without FCS) */
#define ETH_INTF_MAX_ETH_FRAME_SIZE  (1518)

/** Ethernet frame data type */
typedef __PACKED_PRE struct ETH_INTF_ETH_FRAME_Ttag
{
  /** Destination Mac Address */
  TLR_UINT8 abDestMacAddr[ETH_INTF_ETH_ADDR_SIZE];
  /** Source Mac Address */
  TLR_UINT8 abSrcMacAddr[ETH_INTF_ETH_ADDR_SIZE];
  /** Remaining Data */
  TLR_UINT8  abData[ETH_INTF_MAX_ETH_FRAME_SIZE - 2 * ETH_INTF_ETH_ADDR_SIZE];
} __PACKED_POST ETH_INTF_ETH_FRAME_T;


/** @defgroup ethintf_service_sendframe Send Ethernet Frame Service
 *
 * This service shall be used by the Host Application to send an ethernet
 * frame.
 *
 * @{
 */

/** Send Ethernet frame request packet */
typedef struct
{
  /** Packet header */
  TLR_PACKET_HEADER_T                 tHead;
  /** Packet data */
  ETH_INTF_ETH_FRAME_T                tData;
} ETH_INTF_SEND_ETH_FRAME_REQ_T;

/** Send Ethernet frame comfirmation packet */
typedef TLR_EMPTY_PACKET_T  ETH_INTF_SEND_ETH_FRAME_CNF_T;

/** Send Ethernet frame packet union */
typedef union
{
  /** Request */
  ETH_INTF_SEND_ETH_FRAME_REQ_T tReq;
  /** Confirmation */
  ETH_INTF_SEND_ETH_FRAME_CNF_T tCnf;
} ETH_INTF_SEND_ETH_FRAME_PCK_T;

/** @} */


/** @defgroup ethintf_service_recvframe Receive Ethernet Frame Service
 *
 * This service is used by the Ethernet Interface to indicate
 * reception of an Ethernet Frame to the Host application. The
 * Host application must use the RCX_REGISTER_APP_REQ before this
 * service is enabled.
 * @{
 */

/** Received Ethernet frame indication packet */
typedef struct
{
  /** Packet header */
  TLR_PACKET_HEADER_T                 tHead;
  /** Packet data */
  ETH_INTF_ETH_FRAME_T                tData;
} ETH_INTF_RECV_ETH_FRAME_IND_T;

/** Send Ethernet frame comfirmation packet */
typedef TLR_EMPTY_PACKET_T  ETH_INTF_RECV_ETH_FRAME_RSP_T;

/** Receive Ethernet frame packet union */
typedef union
{
  /** Indication */
  ETH_INTF_RECV_ETH_FRAME_IND_T tInd;
  /** Response */
  ETH_INTF_RECV_ETH_FRAME_RSP_T tRsp;
} ETH_INTF_RECV_ETH_FRAME_PCK_T;

/** @} */


/** @defgroup ethintf_service_event Event service
 *
 *  This service is used by the Ethernet Interface task to
 *  notify the Host Application about occuring events. The
 *  service will be enabled after the Host Application used
 *  the RCX_REGISTER_APP_REQ.
 *
 *  The service uses a locking mechanism to avoid flooding the
 *  host application with events. After an event indication
 *  has been generated, the Ethernet Interface task will count
 *  any subsequent events instead of sending a new packet. After
 *  the host returned the event response back to the Ethernet
 *  Interface task, a new event indication will be generated if
 *  necessary.
 * @{
 */

/** Event counter enumeration */
typedef enum
{
  ETH_INTF_EVENT_LINKCHANGED = 0,
  ETH_INTF_EVENT_IPCHANGED,
  ETH_INTF_EVENT_MAX
} ETH_INTF_EVENT_E;

/** Event Data */
typedef __PACKED_PRE struct ETH_INTF_EVENT_DATA_Ttag
{
  /** Array of Counters counting the events defined by
   * ETH_INTF_EVENT_E */
  TLR_UINT16  uiEventCnt[ETH_INTF_EVENT_MAX];
} __PACKED_POST ETH_INTF_EVENT_DATA_T;

/** Event occured indication packet */
typedef struct
{
  /** Packet header */
  TLR_PACKET_HEADER_T                 tHead;
  /** Packet data */
  ETH_INTF_EVENT_DATA_T               tData;
} ETH_INTF_EVENT_IND_T;

/** Event occured response packet */
typedef TLR_EMPTY_PACKET_T  ETH_INTF_EVENT_RSP_T;

/** Event service packet union */
typedef union
{
  /** Indication */
  ETH_INTF_EVENT_IND_T tInd;
  /** Response */
  ETH_INTF_EVENT_RSP_T tRsp;
} ETH_INTF_EVENT_PCK_T;
/** @} */


typedef struct ETH_INTF_GET_HW_STAT_REQ_DATA_Ttag  ETH_INTF_GET_HW_STAT_REQ_DATA_T;

__PACKED_PRE
struct  ETH_INTF_GET_HW_STAT_REQ_DATA_Ttag
{
  TLR_UINT32 ulPortNo;
} __PACKED_POST;

typedef struct ETH_INTF_GET_HW_STAT_PCK_REQ_Ttag ETH_INTF_GET_HW_STAT_PCK_REQ_T;


struct ETH_INTF_GET_HW_STAT_PCK_REQ_Ttag
{
  /** Packet header */
  TLR_PACKET_HEADER_T                tHead;
  /** Packet data */
  ETH_INTF_GET_HW_STAT_REQ_DATA_T tData;
};


typedef struct ETH_INTF_GET_HW_STAT_CNF_DATA_Ttag ETH_INTF_GET_HW_STAT_CNF_DATA_T;

__PACKED_PRE struct __PACKED_POST ETH_INTF_GET_HW_STAT_CNF_DATA_Ttag
{
  /* port to be read out */
  UINT32                    ulPortNo;
  /* count of frames that were transmitted correctly */
  UINT32                    ulTransmittedOkay;
  /* single collision frames counter */
  UINT32                    ulSingleCollisionFrames;
  /* multiple collision frames counter */
  UINT32                    ulMultipleCollisionFrames;
  /* late collisions counter */
  UINT32                    ulLateCollisions;
  /* link down during transmission counter */
  UINT32                    ulLinkDownDuringTransmission;
  /* utx underflow during transmission */
  UINT32                    ulUtxUnderflowDuringTransmission;
  /* count of frames that were received correctly */
  UINT32                    ulFramesReceivedOkay;
  /* fcs errors */
  UINT32                    ulFCSErrors;
  /* alignment errors */
  UINT32                    ulAlignmentErrors;
  /* Frame too long errors */
  UINT32                    ulFrameTooLongErrors;
  /* Runt frame errors */
  UINT32                    ulRuntFrames;
  /* Collision fragments received */
  UINT32                    ulCollisionFragmentsReceived;
  /* Frames dropped due to low resource */
  UINT32                    ulDroppedDueLowResource;
  /* Frames dropped due to urx overflow */
  UINT32                    ulUrxOverflows;
  /* current rx fifo fill */
  UINT32                    ulRxFifoFill;
  /* current tx fifo fill */
  UINT32                    ulTxFifoFill;
};

typedef struct ETH_INTF_GET_HW_STAT_PCK_CNF_Ttag ETH_INTF_GET_HW_STAT_PCK_CNF_T;

struct ETH_INTF_GET_HW_STAT_PCK_CNF_Ttag
{
  /** Packet header */
  TLR_PACKET_HEADER_T              tHead;
  /** Packet data */
  ETH_INTF_GET_HW_STAT_CNF_DATA_T  tData;
};

/** @} */

#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(__ETH_INTF_PACKET)
#endif


/** @page ethintf_doc Ethernet Interface Usage
 * @section ethintf_sec_intro Introduction
 *
 * Depending on the Firmware, the Ethernet Interface Task
 * may provide the following services to the host application:
 * - Sending/Receiving Raw Ethernet Frames
 * - Accessing the TCP/IP Implementation on netX
 *
 * @section ethintf_sec_usage Usage
 *
 * The Ethernet Interface Task does not require any configuration.
 * Therefore there is no Configuration Packet nor Configuration
 * Database available. Because of that the following standard services
 * are not implemented:
 * - ChannelInit
 * - BusOn/Off
 * - Configuration Lock/Unlock
 *
 * @subsection ethintf_sec_raw Raw Ethernet
 *
 * Before the host application may use the raw ethernet access, the extended
 * state block shall be evaluated. The field ETH_INTF_EXTENDED_STATE_T::abMacAddress
 * contains the ethernet mac address the host shall use as source mac address
 * for outgoing frames. If this mac address is set to zero, raw ethernet access
 * is not available.
 *
 * The Host application may send raw ethernet frames at any time using the
 * \ref ethintf_service_sendframe. In order to receive frames, the host application
 * must register with the ethernet interface task using standard
 * RCX_REGISTER_APP_REQ service. After registering, any multicast frame or frame
 * with destination mac equal to ETH_INTF_EXTENDED_STATE_T::abMacAddress will be
 * indicated to the host application using the \ref ethintf_service_recvframe.
 *
 * @subsection ethintf_sec_tcpip TCP/IP
 *
 * The firmwares own TCP/IP implementation may be accessed using the services
 * described in TCP/IP Protocol API manual. The packets will be filtered in order
 * to prevent any configuration changes by the host. If TCP/IP is not available or
 * using the specific service is not allowed, the packets will be returned to
 * the host application with error code TLR_E_FAIL.
 *
 * @subsection ethintf_sec_misc Miscellaneous
 *
 * If an host application is registered, the @ref ethintf_service_event is used
 * to indicate state changes including link state changes and ip changes of the
 * local TCP/IP stack.
 *
 */

#endif /* #ifndef __ETH_INTF_PUBLIC_H */
