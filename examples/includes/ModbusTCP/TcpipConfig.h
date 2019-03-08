/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpipConfig.h 63545 2016-08-29 09:04:12Z RalfH $:

Description:
    Configurable parameters of TCP/UDP task
**************************************************************************************/


#ifndef __TCPIP_CONFIG_H
#define __TCPIP_CONFIG_H

#include "rX_Version.h"

/*-------------------------------------------------------------------------*
 * Program Options                                                         *
 *-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*
 * Debug Options                                                           *
 *-------------------------------------------------------------------------*/

/* #define DEBUG_TCPIP_CONFIG      Enable debug options, see details below    */

#ifdef DEBUG_TCPIP_CONFIG

#warning  "!!!!!!!!!! Warning: Debug options DEBUG_TCPIP_CONFIG enabled !!!!!!!!!!"

/* #define DEBUG_TCP_FSM_EVENT_COUNTER              Enable TCP state machine event counters           */
/* #define DEBUG_ETH_OUT_FRAME_PADDING_BY_SOFTWARE  Circumvent automatic frame padding by controller  */
/* #define DEBUG_TCP_SEND_CALL_TRACE                Enable tcp_send call trace                        */
/* #define DEBUG_DHCP_EVENT_TRACE                   Enable DHCP event trace                           */
/* #define DEBUG_TCP_LED_LIVESIGN                   Enable LiveSign LED in cyclic event (packet)      */

#endif /* #ifdef DEBUG_TCPIP_CONFIG */


/*-------------------------------------------------------------------------*
 * Constants                                                               *
 *-------------------------------------------------------------------------*/

/* Optional functionality */
#define CONFIG_MCAST                            /* Enable multicast functionality */

/* #define CONFIG_NID_SET_IP_ADDR_TIME_RESTRICTED  Enable time restriction for NetIdent's SetIpAddress */

/* #define CONFIG_ARP_REQ_INTF                        Enable user interface for sending ARP requests */
#define CONFIG_ARP_REQ_INTF_DBLY                   /* Enable user interface for sending ARP requests (new version) */


/****************************************************************************************************************
 *
 *  TCP/IP stack configuration (memory consumption)
 *  See also startup parameters TCPIP_TCP_TASK_STARTUPPARAMETER_T (TcpipTcpTask_Functionlist.h)
 *
 *  Parameter               Declaration                                 Default
 *  ---------------------------------------------------------------------------------------------
 *
 *  TCP_RECV_BUF_SIZE       Socket's receive buffer size                2048
 *
 *  ETH_FRAME_MIN_LEN       Min length of an Ethernet frame             60
 *
 *  IP_MSS                  Maximum segment size for Ethernet           1400
 *
 *  ARP_HASH_SIZE           Number of entries in ARP hash table         16
 *  ARP_TIMEOUT_xx          See below..
 *
 *  ROUTE_CACHE_SIZE        Number of entries in route cache            32
 *  ROUTE_HASH_SIZE         Number of entries in route hash table       16
 *  ROUTE_TIMEOUT_CACHE     Timeout for route cache entries (seconds)   900
 *
 *  MCAST_TABLE_SIZE        Number of entries multicast address table   96
 *  MCAST_HASH_SIZE         Number of entries in multicast address
 *                          hash table                                  16
 *
 *  EMTY_QUE_DATA_SIZE      Empty queue max. data size for receive data TCPIP_MAX_TCP_UDP_DATA_CNT
 *                          (1472 = max. UDP datagram size!, see TcpipTcpTask_Public.h)
 *
 ****************************************************************************************************************/


/* Size of socket's receive buffer */
#define TCP_RECV_BUF_SIZE               (2048)  /* Equals max. TCP receive window                               */
                                                /* Note: TCP_RECV_BUF_SIZE must be a power of 2, else the ring  */
                                                /*        buffer mechanism will fail                            */
                                                /*       TCP_RECV_BUF_SIZE must not exceed 32767, else some     */
                                                /*        signed integer variables will overflow                */
                                                /*       Don't forget to adjust the TMIF_ADJUST_RECV_BUF_OFFSET */
                                                /*        macro definition when changing TCP_RECV_BUF_SIZE      */

/* Maximum segment size for Ethernet */
#define IP_MSS                          (1400)

#define ETH_FRAME_MIN_LEN               (60)    /* Min length of an Ethernet frame = 6 + 6 + 2 + 46 ( = Dst MAC */
                                                /* Adr + Src MAC Adr + Type field + min Ethernet data part      */
                                                /* (46 ... 1500 bytes) )                                        */

/* ARP cache sizes */
#define ARP_HASH_SIZE                   (16)    /* Number of entries in ARP hash table, must be power of 2      */

#define ARP_TIMEOUT_RESOLVE             (10)    /* Timeout before removing resolving cache entries (seconds)    */
#define ARP_TIMEOUT_RESOLVE_SILENT      (1)     /* Time between ARP requests for the same IP address (seconds)  */
/* #define ARP_TIMEOUT_CACHE            (600L)  Timeout for ARP cache entries (seconds) - is now a startup      */
                                                /* parameter ulArpTimeoutCache                                  */

#define ARP_TIMEOUT_CACHE_DIRECT        (5L)    /* Time "window" after ARP timeout ulArpTimeoutCache (startup   */
                                                /* parameter) is elapsed. Inside this window, we send a         */
                                                /* Direct ARP                                                   */

#define ARP_TIMEOUT_CACHE_HOLD          (10)    /* Timeout before removing old cache entries (seconds)          */
#define ARP_TIMEOUT_DIRECT_ARP          (ARP_TIMEOUT_RESOLVE_SILENT)  /* Timeout for Direct ARP answer          */

#define ARP_DIRECT_ARP_MAX_CNT          (3)     /* Max count of Direct ARP attempt after ARP timeout is elapsed */
#define ARP_MAX_RND_VALUE               (2047L) /* Max random value (milliseconds)  / RndGetRandom16(ptRsc)>>5  */
                                                /* = (2^16-1)>>5 = 2047 / if change, consider the >>5 (search   */
                                                /* for ARP_MAX_RND_VALUE!)                                      */
/* Route cache sizes */
#define ROUTE_CACHE_SIZE                (32)    /* Number of entries in route cache, must be multiple of 16     */
#define ROUTE_HASH_SIZE                 (16)    /* Number of entries in route hash table, must be power of 2    */

#define ROUTE_TIMEOUT_CACHE             (900)   /* Timeout for route cache entries (seconds)                    */


/* IP multicast management table sizes */
#define MCAST_TABLE_SIZE                (96)    /* Number of entries multicast address table, must be multiple  */
                                                /* of 16                                                        */
#define MCAST_HASH_SIZE                 (16)    /* Number of entries in multicast address hash table, must be   */
                                                /* power of 2                                                   */


/* Packet definitions */
#define EMTY_QUE_DATA_SIZE              TCPIP_MAX_TCP_UDP_DATA_CNT  /* Empty queue max. data size for receive   */
                                                /* data (request command TCPIP_TCP_UDP_CMD_RECEIVE_IND)         */


/* Debug: DHCP event trace */
#define DHCP_EVENT_TRACE_BUFFER_SIZE    (1000 * sizeof(DHCP_EVENT_TRACE_ENTRY))


/* Name of tasks */
#define TCP_TASK_NAME                   "TCP_UDP"


/* Name of database (DBM/NXD file) */
#if RCX_VERSION < MAKE_RCX_VERSION(2,2,0)
#define IP_DBM_FILENAME_DBM             "CONFIG.DBM"
#define IP_DBM_FILENAME_NXD             "CONFIG.NXD"
#else
#define IP_DBM_FILENAME_DBM             "SYSVOLUME:/PORT_0/CONFIG.DBM"
#define IP_DBM_FILENAME_NXD             "SYSVOLUME:/PORT_0/CONFIG.NXD"
#endif
#define IP_DBM_FILENAME_LEN             10

/* Directory of database (DBM file) */
#define IP_DBM_DIR_NAME                 "PORT_0"  /* Default = _0 = Task instance 0 -   */
                                                  /* changed by software to _0 ... _3!  */
#define IP_DBM_DIR_NAME_LEN             6


/* Names of DBM tables */
#define IP_DBM_TABLE_NAME_ETHERNET      "ETHERNET"
#define IP_DBM_TABLE_NAME_SETUP         "IP_SETUP"

#define TCP_PACKET_TIMEOUT_SEND      10
#define TCP_PACKET_TIMEOUT_WAIT      1000

#endif /* #ifndef __TCPIP_CONFIG_H */

