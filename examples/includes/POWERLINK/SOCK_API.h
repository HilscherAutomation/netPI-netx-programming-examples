/**********************************************************************************************

  Copyright (C) 2014 Hilscher Gesellschaft f�r Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id: SOCK_API.h 3176 2017-07-05 15:26:30Z Ricky $

   Description:
     Socket API

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2014-04-01  AM            Created
**************************************************************************************/

#ifndef SOCK_API_H_
#define SOCK_API_H_

#include <stdint.h>

/* packing of structure members */

#if defined (__GNUC__)
#if !defined(__PACKED_PRE) || !defined(__PACKED_POST)
  #define __PACKED_PRE
  #define __PACKED_POST  __attribute__ ((packed))
#endif

#elif _MSC_VER >= 1000
  #define __PACKED_PRE
  #define __PACKED_POST
  #pragma pack (1)
#endif




enum SOCK_LIMITS_Etag
{
  /** Maximum number of FDs to poll */
  SOCK_LIMITS_MAX_POLL     = 32,
  /** Maximum number of FDs to poll */
  SOCK_LIMITS_MAX_PCK_SIZE = 1472,
};

typedef enum SOCK_LIMITS_Etag SOCK_LIMITS_E;

enum SOCK_CMD_Etag
{
  /* generic file descriptor commands */

  /* Not implemented, not applicable
  SOCK_CMD_OPEN_REQ     = 0x00009600,
  SOCK_CMD_OPEN_CNF     = 0x00009601,
  */

  SOCK_CMD_CLOSE_REQ    = 0x00009602,
  SOCK_CMD_CLOSE_CNF    = 0x00009603,

  /* Not implemented, see recv,send and poll
  SOCK_CMD_READ_REQ     = 0x00009604,
  SOCK_CMD_READ_CNF     = 0x00009605,

  SOCK_CMD_WRITE_REQ    = 0x00009606,
  SOCK_CMD_WRITE_CNF    = 0x00009607,

  SOCK_CMD_SELECT_REQ   = 0x00009608,
  SOCK_CMD_SELECT_CNF   = 0x00009609,
  */

  SOCK_CMD_POLL_REQ     = 0x0000960A,
  SOCK_CMD_POLL_CNF     = 0x0000960B,

  SOCK_CMD_FCNTL_REQ    = 0x0000960C,
  SOCK_CMD_FCNTL_CNF    = 0x0000960D,

  /* Not implemented, not required
  SOCK_CMD_IOCTL_REQ    = 0x0000960E,
  SOCK_CMD_IOCTL_CNF    = 0x0000960F,
  */

  /* socket commands */
  SOCK_CMD_SOCKET_REQ      = 0x00009610,
  SOCK_CMD_SOCKET_CNF      = 0x00009611,

  SOCK_CMD_CONNECT_REQ     = 0x00009612,
  SOCK_CMD_CONNECT_CNF     = 0x00009613,

  SOCK_CMD_BIND_REQ        = 0x00009614,
  SOCK_CMD_BIND_CNF        = 0x00009615,

  SOCK_CMD_LISTEN_REQ      = 0x00009616,
  SOCK_CMD_LISTEN_CNF      = 0x00009617,

  SOCK_CMD_ACCEPT_REQ      = 0x00009618,
  SOCK_CMD_ACCEPT_CNF      = 0x00009619,

  SOCK_CMD_RECVFROM_REQ    = 0x0000961A,
  SOCK_CMD_RECVFROM_CNF    = 0x0000961B,

  SOCK_CMD_SENDTO_REQ      = 0x0000961C,
  SOCK_CMD_SENDTO_CNF      = 0x0000961D,

  SOCK_CMD_ABORT_REQ       = 0x0000961E,
  SOCK_CMD_ABORT_CNF       = 0x0000961F,

  SOCK_CMD_SETSOCKOPT_REQ  = 0x00009620,
  SOCK_CMD_SETSOCKOPT_CNF  = 0x00009621,

  SOCK_CMD_GETSOCKOPT_REQ  = 0x00009622,
  SOCK_CMD_GETSOCKOPT_CNF  = 0x00009623,

  /* misc commands */
  SOCK_CMD_GETIFADDRS_REQ  = 0x00009630,
  SOCK_CMD_GETIFADDRS_CNF  = 0x00009631,
};

typedef enum SOCK_CMD_Etag SOCK_CMD_E;

/* allow compilation without including the whole tlr stuff */
#ifdef __TLR_TYPES_H
#define SOCK_PCKHEADER_T TLR_PACKET_HEADER_T
#else
typedef struct SOCK_PCKHEADER_Ttag SOCK_PCKHEADER_T;

__PACKED_PRE struct __PACKED_POST SOCK_PCKHEADER_Ttag
{
  uint32_t  ulDest;   /* destination of the packet (task message queue reference) */
  uint32_t  ulSrc;    /* source of the packet (task message queue reference) */
  uint32_t  ulDestId; /* destination reference (internal use for message routing) */
  uint32_t  ulSrcId;  /* source reference (internal use for message routing) */
  uint32_t  ulLen;    /* length of packet data (starting from the end of the header) */
  uint32_t  ulId;     /* identification reference (internal use by the sender) */
  uint32_t  ulSta;    /* operation status code (error code, initialize with 0) */
  uint32_t  ulCmd;    /* operation command code */
  uint32_t  ulExt;    /* extension count (nonzero in multi-packet transfers) */
  uint32_t  ulRout;   /* router reference (internal use for message routing) */
} ;
#endif

typedef struct SOCK_EMPTY_PCK_Ttag SOCK_EMPTY_PCK_T;
/** Empty packet without additional data
 *
 */
__PACKED_PRE struct __PACKED_POST SOCK_EMPTY_PCK_Ttag
{
  SOCK_PCKHEADER_T tHead;
};

typedef uint16_t SOCK_H;
/**
 * @defgroup FD_Close_Service File descriptor Close Service
 * @{
 */
typedef struct SOCK_CLOSE_REQ_DATA_Ttag SOCK_CLOSE_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_CLOSE_REQ_DATA_Ttag
{
  /** Socket or file descriptor handle */
  SOCK_H         hSocket;
};


typedef struct SOCK_CLOSE_REQ_Ttag SOCK_CLOSE_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_CLOSE_REQ_Ttag
{
  SOCK_PCKHEADER_T      tHead;

  SOCK_CLOSE_REQ_DATA_T tData;
};

typedef struct SOCK_EMPTY_PCK_Ttag SOCK_CLOSE_CNF_T;


typedef union SOCK_CLOSE_PCK_Ttag SOCK_CLOSE_PCK_T;

union SOCK_CLOSE_PCK_Ttag
{
  SOCK_CLOSE_REQ_T tReq;

  SOCK_CLOSE_CNF_T tCnf;
};
/** @} */

/**
 * @defgroup FD_Poll_Service File Descriptor Poll Service
 *
 * This service shall be used to wait for events on filedescriptors
 *
 * @{
 */

/** poll event bitmask, these are defined similar to posix values */
enum SOCK_POLL_EVENT_Etag
{
  SOCK_POLLIN   = 0x0001,
  SOCK_POLLPRI  = 0x0002,
  SOCK_POLLOUT  = 0x0004,
  SOCK_POLLERR  = 0x0008,
  SOCK_POLLHUP  = 0x0010,
  SOCK_POLLNVAL = 0x0020,
};

typedef enum SOCK_POLL_EVENT_Etag SOCK_POLL_EVENT_E;

typedef struct SOCK_POLL_Ttag SOCK_POLL_T;

__PACKED_PRE struct __PACKED_POST SOCK_POLL_Ttag
{
  /** The file handle to poll */
  SOCK_H              hSocket;
  /** the events */
  uint16_t               usEventMsk;
};

typedef struct SOCK_POLL_REQ_DATA_Ttag SOCK_POLL_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_POLL_REQ_DATA_Ttag
{
  int32_t            ilTimeout;
  /** array of file descriptors to poll
   *
   * actuall array size might be smaller and must be specified in header */
  SOCK_POLL_T  atFds[SOCK_LIMITS_MAX_POLL];
};

typedef struct SOCK_POLL_REQ_Ttag SOCK_POLL_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_POLL_REQ_Ttag
{
  SOCK_PCKHEADER_T          tHead;

  SOCK_POLL_REQ_DATA_T   tData;
};


typedef struct SOCK_POLL_CNF_DATA_Ttag SOCK_POLL_CNF_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_POLL_CNF_DATA_Ttag
{
  /** number of fds with events */
  int32_t            ilNumFd;
  /** array of file descriptors to poll
   *
   * actuall array size might be smaller and must be specified in header */
  SOCK_POLL_T  atFds[SOCK_LIMITS_MAX_POLL];
};


typedef struct SOCK_POLL_CNF_Ttag SOCK_POLL_CNF_T;

__PACKED_PRE struct __PACKED_POST SOCK_POLL_CNF_Ttag
{
  SOCK_PCKHEADER_T        tHead;

  SOCK_POLL_CNF_DATA_T tData;
};

typedef union SOCK_POLL_PCK_Ttag SOCK_POLL_PCK_T;

union SOCK_POLL_PCK_Ttag
{
  SOCK_POLL_REQ_T tReq;

  SOCK_POLL_CNF_T tCnf;
};
/** @} */

/**
 * @defgroup FD_Fcntl_Service File Descriptor Control Service
 * @{
 */

enum SOCK_FCNTL_Etag
{
  /* not implemented
  SOCK_FCNTL_GETFD = 1,
  SOCK_FCNTL_SETFD = 2,
  */
  SOCK_FCNTL_GETFL = 3,
  SOCK_FCNTL_SETFL = 4,
};

typedef enum SOCK_FCNTL_Etag SOCK_FCNTL_E;

enum SOCK_STATUS_FLAGS_Etag
{
  SOCK_FL_O_NONBLOCK = 0x800,
};

typedef enum SOCK_STATUS_FLAGS_Etag SOCK_STATUS_FLAGS_E;

typedef struct SOCK_FCNTL_COM_Ttag SOCK_FCNTL_COM_T;

__PACKED_PRE struct __PACKED_POST SOCK_FCNTL_COM_Ttag
{
  /** the file descriptor to perform the fcntl on */
  SOCK_H hSocket;
  /** the command to execute */
  uint16_t  usFcntl;
};

typedef struct SOCK_FCNTL_FL_Ttag SOCK_FCNTL_FL_T;

__PACKED_PRE struct __PACKED_POST SOCK_FCNTL_FL_Ttag
{
  /** the file descriptor to perform the fcntl on */
  SOCK_H hSocket;
  /** the command to execute */
  uint16_t  usFcntl;
  /** the status flags */
  uint32_t ulStatusFlags;
};

typedef union SOCK_FCNTL_DATA_Ttag SOCK_FCNTL_DATA_T;

union SOCK_FCNTL_DATA_Ttag
{
  /** To access fields common to all fcntl commands */
  SOCK_FCNTL_COM_T tCom;
  /** used for F_GETFL/F_SETFL */
  SOCK_FCNTL_FL_T  tFileStatus;
};

typedef struct SOCK_FCNTL_REQ_Ttag SOCK_FCNTL_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_FCNTL_REQ_Ttag
{
  SOCK_PCKHEADER_T  tHead;

  SOCK_FCNTL_DATA_T tData;
};

typedef struct SOCK_FCNTL_CNF_Ttag SOCK_FCNTL_CNF_T;

__PACKED_PRE struct __PACKED_POST SOCK_FCNTL_CNF_Ttag
{
  SOCK_PCKHEADER_T     tHead;

  SOCK_FCNTL_DATA_T    tData;
};

typedef union SOCK_FCNTL_PCK_Ttag SOCK_FCNTL_PCK_T;

union SOCK_FCNTL_PCK_Ttag
{
  SOCK_FCNTL_REQ_T tReq;

  SOCK_FCNTL_CNF_T tCnf;
};
/** @}*/

/**
 * @defgroup SOCK_Socket_Service Create a socket Service
 *
 * @{
 */

enum SOCK_SOCKET_DOMAIN_Etag
{
  SOCK_AF_INET = 2,
};

typedef enum SOCK_SOCKET_DOMAIN_Etag SOCK_SOCKET_DOMAIN_E;


enum SOCK_SOCKET_TYPE_Etag
{
  SOCK_SOCKET_STREAM = 1,
  SOCK_SOCKET_DGRAM  = 2,
};

typedef enum SOCK_SOCKET_TYPE_Etag SOCK_SOCKET_TYPE_E;


enum SOCK_IPPROTO_Etag
{
  /** Dummy, alias for TCP */
  SOCK_IPPROTO_IP  = 0,
  /** TCP */
  SOCK_IPPROTO_TCP = 6,
  /** UDP */
  SOCK_IPPROTO_UDP = 17,
};

typedef enum SOCK_IPPROTO_Etag SOCK_IPPROTO_E;

typedef struct SOCK_SOCKET_REQ_DATA_Ttag SOCK_SOCKET_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_SOCKET_REQ_DATA_Ttag
{
  /** the socket domain */
  uint32_t ulDomain;
  /** the socket type */
  uint32_t ulType;
  /** the socket protocol */
  uint32_t ulProtocol;
};

typedef struct SOCK_SOCKET_REQ_Ttag SOCK_SOCKET_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_SOCKET_REQ_Ttag
{
  SOCK_PCKHEADER_T       tHead;

  SOCK_SOCKET_REQ_DATA_T tData;
};

typedef struct SOCK_SOCKET_CNF_DATA_Ttag SOCK_SOCKET_CNF_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_SOCKET_CNF_DATA_Ttag
{
  SOCK_H hSocket;
};

typedef struct SOCK_SOCKET_CNF_Ttag SOCK_SOCKET_CNF_T;

__PACKED_PRE struct __PACKED_POST SOCK_SOCKET_CNF_Ttag
{
  SOCK_PCKHEADER_T       tHead;

  SOCK_SOCKET_CNF_DATA_T tData;
};

typedef union SOCK_SOCKET_PCK_Ttag SOCK_SOCKET_PCK_T;

union SOCK_SOCKET_PCK_Ttag
{
  SOCK_SOCKET_REQ_T tReq;

  SOCK_SOCKET_CNF_T tCnf;
};
/** @}*/



typedef struct SOCK_ADDR_COMMON_Ttag SOCK_ADDR_COMMON_T;

__PACKED_PRE struct __PACKED_POST SOCK_ADDR_COMMON_Ttag
{
  uint8_t    bFamily;

  uint8_t    bReserved[14];

  uint8_t    bPadding;
};

typedef struct SOCK_ADDR_IP_Ttag SOCK_ADDR_IP_T;

__PACKED_PRE struct __PACKED_POST SOCK_ADDR_IP_Ttag
{
  uint8_t    bFamily;

  uint8_t    bPadding;

  uint32_t   ulIpAddr;

  uint16_t   usPort;
};

typedef union SOCK_ADDR_Ttag SOCK_ADDR_T;

union SOCK_ADDR_Ttag
{
  /** contains common fields of all socket address structures */
  SOCK_ADDR_COMMON_T tCommon;
  /** IPv4 specific socket address */
  SOCK_ADDR_IP_T     tIp;
};

typedef struct SOCK_ADDR_DATA_Ttag SOCK_ADDR_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_ADDR_DATA_Ttag
{
  SOCK_H   hSocket;

  SOCK_ADDR_T tSa;
};

/**
 * @defgroup SOCK_Connect_Service Connect Socket Service
 *
 * @{
 */

typedef struct SOCK_CONNECT_REQ_Ttag SOCK_CONNECT_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_CONNECT_REQ_Ttag
{
  SOCK_PCKHEADER_T  tHead;

  SOCK_ADDR_DATA_T  tData;
};

typedef struct SOCK_EMPTY_PCK_Ttag SOCK_CONNECT_CNF_T;

typedef union SOCK_CONNECT_PCK_Ttag SOCK_CONNECT_PCK_T;

union SOCK_CONNECT_PCK_Ttag
{
  SOCK_CONNECT_REQ_T tReq;

  SOCK_CONNECT_CNF_T tCnf;
};
/** @}*/

/**
 * @defgroup SOCK_Bind_Service Bind Socket Service
 * @{
 */
typedef struct SOCK_BIND_REQ_Ttag SOCK_BIND_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_BIND_REQ_Ttag
{
  SOCK_PCKHEADER_T   tHead;

  SOCK_ADDR_DATA_T   tData;
};

typedef struct SOCK_BIND_CNF_Ttag SOCK_BIND_CNF_T;

__PACKED_PRE struct __PACKED_POST SOCK_BIND_CNF_Ttag
{
  SOCK_PCKHEADER_T   tHead;

  SOCK_ADDR_DATA_T   tData;
};

typedef union SOCK_BIND_PCK_Ttag SOCK_BIND_PCK_T;

union SOCK_BIND_PCK_Ttag
{
  SOCK_BIND_REQ_T tReq;

  SOCK_BIND_CNF_T tCnf;
};
/**@}*/

/**
 * @defgroup SOCK_Listen_Service Socket Listen Service
 */
typedef struct SOCK_LISTEN_REQ_DATA_Ttag SOCK_LISTEN_REQ_DATA_T;

struct SOCK_LISTEN_REQ_DATA_Ttag
{
  SOCK_H hSocket;
  /** maximum size of pending connect queue */
  uint16_t  usBackLog;
};

typedef struct SOCK_LISTEN_REQ_Ttag SOCK_LISTEN_REQ_T;

struct SOCK_LISTEN_REQ_Ttag
{
  SOCK_PCKHEADER_T       tHead;

  SOCK_LISTEN_REQ_DATA_T tData;
};

typedef struct SOCK_EMPTY_PCK_Ttag SOCK_LISTEN_CNF_T;

typedef union SOCK_LISTEN_PCK_Ttag SOCK_LISTEN_PCK_T;

union SOCK_LISTEN_PCK_Ttag
{
  SOCK_LISTEN_REQ_T tReq;

  SOCK_LISTEN_CNF_T tCnf;
};
/**@}*/

/**_Accept_Service Socket Accept Service
 * @defgroup SOCK
 * @{
 */
typedef struct SOCK_ACCEPT_REQ_DATA_Ttag SOCK_ACCEPT_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_ACCEPT_REQ_DATA_Ttag
{
  SOCK_H   hSocket;
  /** Reserved for future extensions set to zero */
  uint16_t usFlags;
};

typedef struct SOCK_ACCEPT_REQ_Ttag SOCK_ACCEPT_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_ACCEPT_REQ_Ttag
{
  SOCK_PCKHEADER_T       tHead;

  SOCK_ACCEPT_REQ_DATA_T tData;
};

typedef struct SOCK_ACCEPT_CNF_DATA_Ttag SOCK_ACCEPT_CNF_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_ACCEPT_CNF_DATA_Ttag
{
  /** the socket handle of the new connection */
  SOCK_H   hAcceptSocket;
  /** address information */
  SOCK_ADDR_T tSa;
};

typedef struct SOCK_ACCEPT_CNF_Ttag SOCK_ACCEPT_CNF_T;

__PACKED_PRE struct __PACKED_POST SOCK_ACCEPT_CNF_Ttag
{
  SOCK_PCKHEADER_T       tHead;

  SOCK_ACCEPT_CNF_DATA_T tData;
};

typedef union SOCK_ACCEPT_PCK_Ttag SOCK_ACCEPT_PCK_T;

union SOCK_ACCEPT_PCK_Ttag
{
  SOCK_ACCEPT_REQ_T tReq;

  SOCK_ACCEPT_CNF_T tCnf;
};
/**@}*/

/**
 * @defgroup SOCK_RecvFrom_Sevice Socket RecvFrom Service
 *
 * @{
 */
typedef struct SOCK_RECVFROM_REQ_DATA_Ttag SOCK_RECVFROM_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_RECVFROM_REQ_DATA_Ttag
{
  SOCK_H hSocket;
  /** Reserved for future extensions set to zero */
  uint16_t  usFlags;

  uint16_t  usMaxLen;
};

typedef struct SOCK_RECVFROM_REQ_Ttag SOCK_RECVFROM_REQ_T;
__PACKED_PRE struct __PACKED_POST SOCK_RECVFROM_REQ_Ttag
{
  SOCK_PCKHEADER_T         tHead;

  SOCK_RECVFROM_REQ_DATA_T tData;
};

typedef struct SOCK_RECVFROM_CNF_DATA_Ttag SOCK_RECVFROM_CNF_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_RECVFROM_CNF_DATA_Ttag
{
  /** remote address information */
  SOCK_ADDR_T  tSa;
  /** data */
  uint8_t      abPayload[SOCK_LIMITS_MAX_PCK_SIZE];
};

typedef struct SOCK_RECVFROM_CNF_Ttag SOCK_RECVFROM_CNF_T;

__PACKED_PRE struct __PACKED_POST SOCK_RECVFROM_CNF_Ttag
{
  SOCK_PCKHEADER_T         tHead;

  SOCK_RECVFROM_CNF_DATA_T tData;
};

typedef union SOCK_RECVFROM_PCK_Ttag SOCK_RECVFROM_PCK_T;

union SOCK_RECVFROM_PCK_Ttag
{
  SOCK_RECVFROM_REQ_T tReq;

  SOCK_RECVFROM_CNF_T tCnf;
};
/**@}*/

/**
 * @defgroup SOCK_SendTo_Service Socket SendTo Service
 *
 * @{
 */
typedef struct SOCK_SENDTO_REQ_DATA_Ttag SOCK_SENDTO_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_SENDTO_REQ_DATA_Ttag
{
  SOCK_H    hSocket;
  /** Reserved for future extensions set to zero */
  uint16_t     usFlags;
  /** remote address information */
  SOCK_ADDR_T  tSa;
  /** data */
  uint8_t      abBuffer[SOCK_LIMITS_MAX_PCK_SIZE];
};

typedef struct SOCK_SENDTO_REQ_Ttag SOCK_SENDTO_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_SENDTO_REQ_Ttag
{
  SOCK_PCKHEADER_T       tHead;

  SOCK_SENDTO_REQ_DATA_T tData;
};

typedef struct SOCK_EMPTY_PCK_Ttag SOCK_SENDTO_CNF_T;

typedef union SOCK_SENDTO_PCK_Ttag SOCK_SENDTO_PCK_T;

union SOCK_SENDTO_PCK_Ttag
{
  SOCK_SENDTO_REQ_T tReq;

  SOCK_SENDTO_CNF_T tCnf;
};
/**@}*/


/**
 * @defgroup SOCK_Abort_Service Socket Abort Service
 * @{
 */
typedef struct SOCK_ABORT_REQ_DATA_Ttag SOCK_ABORT_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_ABORT_REQ_DATA_Ttag
{
  /** Socket or file descriptor handle */
  SOCK_H         hSocket;
};


typedef struct SOCK_ABORT_REQ_Ttag SOCK_ABORT_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_ABORT_REQ_Ttag
{
  SOCK_PCKHEADER_T      tHead;

  SOCK_ABORT_REQ_DATA_T tData;
};

typedef struct SOCK_EMPTY_PCK_Ttag SOCK_ABORT_CNF_T;


typedef union SOCK_ABORT_PCK_Ttag SOCK_ABORT_PCK_T;

union SOCK_ABORT_PCK_Ttag
{
  SOCK_ABORT_REQ_T tReq;

  SOCK_ABORT_CNF_T tCnf;
};
/** @} */

/** TCP socket options */
enum
{
  SOCK_TCP_NODELAY = 1,
};



/** Set sockopt tcp no delay */
typedef struct SOCK_SOCKOPT_TCP_NODELAY_Ttag SOCK_SOCKOPT_TCP_NODELAY_T;

__PACKED_PRE struct __PACKED_POST SOCK_SOCKOPT_TCP_NODELAY_Ttag
{
  /** Set to true if socket shall immediately send out the data */
  int32_t ulEnabled;
};

typedef union SOCK_SOCKOPT_Ttag SOCK_SOCKOPT_T;

union SOCK_SOCKOPT_Ttag
{
  SOCK_SOCKOPT_TCP_NODELAY_T tTcpNoDelay;
};

/**
 * @defgroup SOCK_SetSockOpt_Service Set Socket Options Service
 * @{
 *
 */

typedef struct SOCK_SETSOCKOPT_REQ_DATA_Ttag SOCK_SETSOCKOPT_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_SETSOCKOPT_REQ_DATA_Ttag
{
  SOCK_H         hSocket;
  /** option level to set, value should be one of SOCK_IPPROTO_*  enums */
  uint16_t       usLevel;

  uint16_t       usOption;

  uint16_t       usReserved;
/* valid union field depends on usOption */
  SOCK_SOCKOPT_T tOpt;
};

typedef struct SOCK_SETSOCKOPT_REQ_Ttag SOCK_SETSOCKOPT_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_SETSOCKOPT_REQ_Ttag
{
  SOCK_PCKHEADER_T           tHead;

  SOCK_SETSOCKOPT_REQ_DATA_T tData;
};

typedef struct SOCK_EMPTY_PCK_Ttag SOCK_SETSOCKOPT_CNF_T;

typedef union SOCK_SETSOCKOPT_PCK_Ttag SOCK_SETSOCKOPT_PCK_T;

union SOCK_SETSOCKOPT_PCK_Ttag
{
  SOCK_SETSOCKOPT_REQ_T tReq;

  SOCK_SETSOCKOPT_CNF_T tCnf;
};
/** @}*/

/**
 * @defgroup SOCK_GetSockOpt_Service Get Socket Options Service
 * @{
 *
 */

typedef struct SOCK_GETSOCKOPT_REQ_DATA_Ttag SOCK_GETSOCKOPT_REQ_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_GETSOCKOPT_REQ_DATA_Ttag
{
  SOCK_H         hSocket;

  uint16_t       usLevel;

  uint16_t       usOption;

  uint16_t       usReserved;
};

typedef struct SOCK_GETSOCKOPT_REQ_Ttag SOCK_GETSOCKOPT_REQ_T;

__PACKED_PRE struct __PACKED_POST SOCK_GETSOCKOPT_REQ_Ttag
{
  SOCK_PCKHEADER_T           tHead;

  SOCK_GETSOCKOPT_REQ_DATA_T tData;
};

typedef struct SOCK_GETSOCKOPT_CNF_DATA_Ttag SOCK_GETSOCKOPT_CNF_DATA_T;

/** Common fields of every sockopt data */
__PACKED_PRE struct __PACKED_POST SOCK_GETSOCKOPT_CNF_DATA_Ttag
{
  SOCK_H         hSocket;

  uint16_t       usLevel;

  uint16_t       usOption;

  uint16_t       usReserved;
  /* valid union field depends on usOption */
  SOCK_SOCKOPT_T tOpt;
};

typedef struct SOCK_GETSOCKOPT_CNF_Ttag SOCK_GETSOCKOPT_CNF_T;

__PACKED_PRE struct __PACKED_POST SOCK_GETSOCKOPT_CNF_Ttag
{
  SOCK_PCKHEADER_T           tHead;

  SOCK_GETSOCKOPT_CNF_DATA_T tData;
};

typedef union SOCK_GETSOCKOPT_PCK_Ttag SOCK_GETSOCKOPT_PCK_T;

union SOCK_GETSOCKOPT_PCK_Ttag
{
  SOCK_GETSOCKOPT_REQ_T tReq;

  SOCK_GETSOCKOPT_CNF_T tCnf;
};
/** @}*/


/**
 * @defgroup SOCK_GetIfAddrs_Service Get IfAddrs Service
 * @{
 */
typedef struct SOCK_EMPTY_PCK_Ttag SOCK_GETIFADDRS_REQ_T;

typedef struct SOCK_GETIFADDRS_CNF_DATA_Ttag SOCK_GETIFADDRS_CNF_DATA_T;

__PACKED_PRE struct __PACKED_POST SOCK_GETIFADDRS_CNF_DATA_Ttag
{
  uint8_t     szIfName[8];

  uint32_t    ulFlags;

  SOCK_ADDR_T tIpAddress;

  SOCK_ADDR_T tNetmask;

  SOCK_ADDR_T tBcastAddr;
};

typedef struct SOCK_GETIFADDRS_CNF_Ttag SOCK_GETIFADDRS_CNF_T;

__PACKED_PRE struct __PACKED_POST SOCK_GETIFADDRS_CNF_Ttag
{
  SOCK_PCKHEADER_T           tHead;

  SOCK_GETIFADDRS_CNF_DATA_T tData;
};

typedef union SOCK_GETIFADDRS_PCK_Ttag SOCK_GETIFADDRS_PCK_T;

union SOCK_GETIFADDRS_PCK_Ttag
{
  SOCK_GETIFADDRS_REQ_T tReq;

  SOCK_GETIFADDRS_CNF_T tCnf;
};
/**@}*/


typedef union SOCK_PCK_Ttag SOCK_PCK_T;

/**
 * Packet Union of all supported services.
 */
union SOCK_PCK_Ttag
{
  SOCK_CLOSE_PCK_T      tClose;
  SOCK_POLL_PCK_T       tPoll;
  SOCK_FCNTL_PCK_T      tFcntl;

  SOCK_SOCKET_PCK_T     tSocket;
  SOCK_CONNECT_PCK_T    tConnect;
  SOCK_BIND_PCK_T       tBind;
  SOCK_LISTEN_PCK_T     tListen;
  SOCK_ACCEPT_PCK_T     tAccept;

  SOCK_RECVFROM_PCK_T   tRecvFrom;
  SOCK_SENDTO_PCK_T     tSendTo;

  SOCK_ABORT_PCK_T      tAbort;

  SOCK_SETSOCKOPT_PCK_T tSetSockOpt;
  SOCK_GETSOCKOPT_PCK_T tGetSockOpt;

  SOCK_GETIFADDRS_PCK_T tGetIfAddrs;

  SOCK_EMPTY_PCK_T      tEmpty;
};

#if _MSC_VER >= 1000
  #pragma pack
#endif

#endif /* SOCK_API_H_ */
