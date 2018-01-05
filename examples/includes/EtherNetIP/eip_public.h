/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of EtherNet/IP Encapsulation Layer

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2013-11-12  RH            Created
**************************************************************************************/
#ifndef EIP_PUBLIC_H
#define EIP_PUBLIC_H

#include "eip_error.h"

/*#####################################################################################*/
  /* extended error codes for the connection manager */
  #define EIP_ESR_ALREADY_USED                             0x100  /* Connection already in use     */
  #define EIP_ESR_BAD_TRANSPORT                            0x103  /* Transport type not supported  */
  #define EIP_ESR_OWNER_CONFLICT                           0x106  /* More than one guy configuring */
  #define EIP_ESR_BAD_CONNECTION                           0x107  /* Trying to close inactive conn */
  #define EIP_ESR_BAD_CONN_TYPE                            0x108  /* Unsupported connection type   */
  #define EIP_ESR_BAD_CONN_SIZE                            0x109  /* Connection size mismatch      */

  #define EIP_ESR_CONN_UNCONFIGURED                        0x110  /* Connection unconfigured       */
  #define EIP_ESR_BAD_RPI                                  0x111  /* Unsupportable RPI             */
  #define EIP_ESR_NO_CM_RESOURCES                          0x113  /* Conn Mgr out of connections   */
  #define EIP_ESR_BAD_VENDOR_PRODUCT                       0x114  /* Mismatch in electronic key    */
  #define EIP_ESR_BAD_DEVICE_TYPE                          0x115  /* Mismatch in electronic key    */
  #define EIP_ESR_BAD_REVISION                             0x116  /* Mismatch in electronic key    */
  #define EIP_ESR_BAD_CONN_POINT                           0x117  /* Nonexistant instance number   */
  #define EIP_ESR_BAD_CONFIGURATION                        0x118  /* Bad config instance number    */
  #define EIP_ESR_CONN_REQ_FAILS                           0x119  /* No controlling connection opn */
  #define EIP_ESR_NO_APP_RESOURCES                         0x11A  /* App out of connections        */

  #define EIP_ESR_BAD_TRANSPORT_CLASS                      0x11C  /* The transport class requested in the
                                                                     Transport Type/Trigger parameter is
                                                                     not supported. */

  #define EIP_ESR_BAD_PRODUCTION_TRIGGER                   0x11D  /* The production trigger requested
                                                                     in the Transport Type/Trigger parameter
                                                                     is not supported. */

  #define EIP_ESR_BAD_DIRECTION                            0x11E  /* The direction requested in the Transport
                                                                     Type/Trigger parameter is not supported. */

  #define EIP_ESR_BAD_O2T_NETWORK_CONN_FIXVAR              0x11F  /* This extended status code shall be returned
                                                                     as the result of specifying an O2T
                                                                     fixed / variable flag that is not supported. */

  #define EIP_ESR_BAD_T2O_NETWORK_CONN_FIXVAR              0x120  /* This extended status code shall be returned
                                                                     as the result of specifying a T2O
                                                                     fixed / variable flag that is not supported. */

  #define EIP_ESR_BAD_02T_NETWORK_CONN_PRIORITY            0x121 /* This extended status code shall be returned
                                                                    as the result of specifying an O2T priority
                                                                    code that is not supported. */

  #define EIP_ESR_BAD_T20_NETWORK_CONN_PRIORITY            0x122 /* This extended status code shall be returned
                                                                     as the result of specifying a T2O priority
                                                                     code that is not supported. */

  #define EIP_ESR_BAD_02T_NETWORK_CONN_TYPE                0x123 /* This extended status code shall be returned
                                                                    as the result of specifying an O2T connection
                                                                    type that is not supported */

  #define EIP_ESR_BAD_T2O_NETWORK_CONN_TYPE                0x124 /* This extended status code shall be returned
                                                                    as the result of specifying a T2O connection
                                                                    type that is not supported */

  #define EIP_ESR_BAD_O2T_NETWORK_CONN_RED_OWNER           0x125 /* This extended status code shall be returned
                                                                    as the result of specifying an O2T Redundant
                                                                    Owner flag that is not supported */

  #define EIP_ESR_BAD_CONFIG_SIZE                          0x126 /* This extended status code is returned
                                                                    when the target device determines that
                                                                    the data segment provided in the
                                                                    Connection_Path parameter did not contain
                                                                    an acceptable number of 16-bit words
                                                                    for the the configuration application
                                                                    path requested.*/

  #define EIP_ESR_BAD_O2T_SIZE                             0x127 /* This extended status code is returned by the
                                                                    target when the size of the consuming object
                                                                    declared in the Forward_Open request and
                                                                    available on the target does not match the
                                                                    size declared in the O->T Network Connection
                                                                    Parameter. */

  #define EIP_ESR_BAD_T2O_SIZE                             0x128 /* This extended status code is returned by the
                                                                    target when the size of the producing object
                                                                    declared in the Forward Open request and
                                                                    available on the target does not match the
                                                                    size declared in the T->O Network Connection
                                                                    Parameter. */

  #define EIP_ESR_BAD_CONFIG_APPL_PATH                     0x129 /* The configuration application path specified
                                                                    in the connection path does not correspond to
                                                                    a valid configuration application path within
                                                                    the target application. This error could also
                                                                    be returned if a configuration application path
                                                                    was required, but not provided by a connection
                                                                    request */

  #define EIP_ESR_BAD_CONSUMING_APPL_PATH                  0x12A /* The consumed application path specified in the
                                                                    connection path does not correspond to a valid
                                                                    consumed application path within the target
                                                                    application. This error could also be returned
                                                                    if a consumed application path was required,
                                                                    but not provided by a connection request */

  #define EIP_ESR_BAD_PRODUCING_APPL_PATH                  0x12B /* The produced application path specified in the
                                                                    connection path does not correspond to a valid
                                                                    produced application path within the target
                                                                    application. This error could also be returned
                                                                    if a produced application path was required,
                                                                    but not provided by a connection request. */

  #define EIP_ESR_BAD_CONFIG_SYMBOL                        0x12C /* Configuration Symbol does not exist. The
                                                                    originator attempts to connect to a configuration
                                                                    tag name, but the name is not on the list of tags
                                                                    defined on the target. */

  #define EIP_ESR_BAD_CONSUMING_SYMBOL                     0x12D /* Consuming Symbol does not exist. The originator
                                                                    attempts to connect to a consuming tag name, but
                                                                    the name is not on the list of tags defined on the
                                                                    target. */

  #define EIP_ESR_BAD_PRODUCING_SYMBOL                     0x12E /* Producing Symbol does not exist. The originator
                                                                    attempts to connect to a producing tag name, but
                                                                    the name is not on the list of tags defined on the
                                                                    target. */

  #define EIP_ESR_BAD_APPL_PATH_COMBINATION                0x12F /* The combination of configuration and/or consume
                                                                    and/or produce application paths specified in the
                                                                    connection path are inconsistent with each other */

  #define EIP_ESR_BAD_CONSUME_DATA_FORMAT                  0x130 /* Information in the data segment is not consistent
                                                                    with the format of the consumed data. For example
                                                                    the configuration data specifies float configuration
                                                                    data while the consumed path specifies integer data */

  #define EIP_ESR_BAD_PRODUCE_DATA_FORMAT                  0x131 /* Information in the data segment is not consistent
                                                                    with the format of the produced data. For example the
                                                                    configuration data specifies float configuration data
                                                                    while the produced path specifies integer data. */

  #define EIP_ESR_CONN_TIMED_OUT                           0x203 /* Using a timed out connection  */
  #define EIP_ESR_UCSEND_TIMED_OUT                         0x204 /* Unconnected Send timed out    */
  #define EIP_ESR_UCSEND_PARAM_ERR                         0x205 /* Unconnected Send param. error */

  #define EIP_ESR_NO_BUFFER                                0x301 /* No buffer memory available    */
  #define EIP_ESR_NO_BANDWIDTH                             0x302 /* Insufficient bandwidth left   */
  #define EIP_ESR_NO_SCREENER                              0x303 /* Out of gen screeners          */
  #define EIP_ESR_NOT_CONF_FOR_RT                          0x304 /* Not configured to send RT data*/
  #define EIP_ESR_SIGNATURE_MISMATCH                       0x305 /* sig does not match sig store in CCM */
  #define EIP_ESR_CCM_NOT_AVAIL                            0x306 /* ccm is not responding to req. */

  #define EIP_ESR_BAD_PORT                                 0x311 /* Nonexistant port              */
  #define EIP_ESR_BAD_LINK_ADDRESS                         0x312 /* Invalid link address in path  */
  #define EIP_ESR_BAD_SEGMENT                              0x315 /* Invalid segment in path       */
  #define EIP_ESR_BAD_CLOSE                                0x316 /* Path & conn not equal in close*/
  #define EIP_ESR_BAD_NET_SEGMENT                          0x317 /* Net seg not present or bad    */
  #define EIP_ESR_BAD_LINK_AD_TO_SELF                      0x318 /* Link address to self invalid  */
  #define EIP_ESR_NO_SEC_RESOURCE                          0x319 /* Resources in secondary unavail*/

  #define EIP_ESR_REDUND_CONN_MISMATCH                     0x31D /* Redundant connection mismatch */

  #define EIP_ESR_NOT_CONFIGURED_FOR_OFF_SUBNET_MULTICAST  0x813  /* A multicast connection has been requested between a
                                                                     producer and a consumer that are on different subnets,
                                                                     and the producer is not configured for off-subnet multicast. */
  /* Vendor specific */
  #define EIP_ESR_ACCESS_CONFLICT                 0x320 /* read write access fail */
  #define EIP_ESR_INTERNAL_ERROR                  0x321 /* Internal error occurred (send/receive packets) */

typedef enum CIP_STACK_MODE_Etag
{
  CIP_STACK_MODE_OFFLINE  = 0x00,
  CIP_STACK_MODE_STOP     = 0x01,
  CIP_STACK_MODE_IDLE     = 0x02,
  CIP_STACK_MODE_RUN      = 0x03,
} CIP_STACK_MODE_E;

  /*#####################################################################################*/

  typedef struct EIP_PARAMETER_Ttag
  {
    uint16_t usMaxUCMMConnections;
    uint16_t usMaxCL3Connections;
    uint16_t usMaxCL1Connections;
    uint16_t usMaxTcpServerConnections;
    uint8_t  bTcpServerQueueSize;
    uint8_t  bUdpServerQueueSize;
    uint16_t usTcpUdpBufferSize;
  }EIP_PARAMETER_T;

  /*#####################################################################################*/

  typedef struct EIP_CONNECTION_SUMMARY_Ttag
  {
    struct
    {
      uint16_t usNumExclusiveOwner;
      uint16_t usNumInputOnly;
      uint16_t usNumListenOnly;
      uint16_t usNumExplicitMessaging;
    }tAdapter;

    struct
    {
      #define EIP_MAX_EXCLUSIVE_OWNER_TIMEOUT_CONN    4
      uint8_t                   bOTTimeoutCnt;
      struct
      {
        uint32_t  ulClass;
        uint32_t  ulInstance;
        uint32_t  ulOTConnPoint;
      } atOTConnTimeout[EIP_MAX_EXCLUSIVE_OWNER_TIMEOUT_CONN];
    } tTimedOutConnections;

  } EIP_CONNECTION_SUMMARY_T;

  /*#####################################################################################*/

  typedef struct EIP_CONNECTION_PARAMETER_Ttag
  {
    uint8_t   bPriority;          /* used to calculate request timeout information   */
    uint8_t   bTimeOutTicks;      /* used to calculate request timeout information   */
    uint32_t  ulOTConnID;         /* Network connection ID orginator to target       */
    uint32_t  ulTOConnID;         /* Network connection ID target to orginator       */
    uint16_t  usConnSerialNum;    /* Connection serial number                        */
    uint16_t  usVendorId;         /* Orginator Vendor ID                             */
    uint32_t  ulOSerialNum;       /* Orginator serial number                         */
    uint8_t   bTimeoutMultiple;   /* Connection timeout multiple                     */
    uint32_t  ulOTRpi;            /* orginator to target requested packet rate in us */
    uint16_t  usOTConnParam;      /* orginator to target connection parameter        */
    uint16_t  usOTConnSize;       /* orginator to target connection size             */
    uint32_t  ulTORpi;            /* target to orginator requested packet rate in us */
    uint16_t  usTOConnParam;      /* target to orginator connection parameter        */
    uint16_t  usTOConnSize;       /* target to orginator connection size             */
    uint8_t   bTriggerType;       /* Transport type/trigger                          */
    uint32_t  ulClass;
    uint32_t  ulInstance;
    uint32_t  ulOTConnectionPoints;
    uint32_t  ulTOConnectionPoints;
    uint8_t * pbDataSeg;
    uint16_t  usDataSegSize;
    uint32_t  ulProInhib;
    uint8_t   bConnType;
  } EIP_CONNECTION_PARAMETER_T;

  /*#####################################################################################*/

  typedef struct EIP_QOS_CONFIG_Ttag
  {
    uint8_t b802_1TagEnable;
    uint8_t bDSCP_Urgent;
    uint8_t bDSCP_Scheduled;
    uint8_t bDSCP_High;
    uint8_t bDSCP_Low;
    uint8_t bDSCP_Explicit;
  } EIP_QOS_CONFIG_T;

  /*#####################################################################################*/

  uint32_t
  Cip_SetStackMode( void*   pvRsc,
                    uint8_t bMode );

  void
  Cip_ResetStack( void* pvRsc );


  typedef void (*CIP_OBJ_STATUS_CALLBACK) (void* pvParam, uint8_t bLedState, uint8_t bState);
  typedef void (*CIP_CONNECTION_CALLBACK) (void* pvParam, uint8_t bReason, EIP_CONNECTION_SUMMARY_T *ptSummary, EIP_CONNECTION_PARAMETER_T *ptConnection);

  uint32_t
  Cip_RegisterConnectionStatusCallback( void*                   pvRsc,
                                        CIP_CONNECTION_CALLBACK pfCallback,
                                        void*                   pvParam );

  uint32_t
  Cip_RegisterModuleStatusCallback( void*                   ptRsc,
                                    CIP_OBJ_STATUS_CALLBACK pfCallback,
                                    void*                   pvParam );

  uint32_t
  Cip_RegisterNetworkStatusCallback( void*                   ptRsc,
                                     CIP_OBJ_STATUS_CALLBACK pfCallback,
                                     void*                   pvParam );

  void
  Cip_GetModulNetworkStatus( void*    pvRsc,
                             uint8_t* pbModuleStatus,
                             uint8_t* pbNetworkStatus );

  void EipTimer_CycleCbk( void* pvArg );

#endif
