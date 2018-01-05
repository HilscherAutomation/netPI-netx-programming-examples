/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Definition of Common Industrial Protocol (CIP)

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2013-11-12  RH            Created
**************************************************************************************/
#ifndef CIP_COMMON_PUBLIC_H
#define CIP_COMMON_PUBLIC_H

#include <stdint.h>

  /*#####################################################################################*/

  #ifndef MAX
    #define MAX(a,b)    (((a) > (b)) ? (a) : (b))
  #endif

  #ifndef MIN
    #define MIN(a,b)    (((a) > (b)) ? (b) : (a))
  #endif

  #ifndef MAX_CNT
    #define MAX_CNT(x)  (sizeof(x) / sizeof(x[0]))
  #endif


  /*#####################################################################################*/

  #define CIP_SWAP_16(n) (uint16_t) ((((uint8_t*)&n)[0] << 8) | \
                                       (((uint8_t*)&n)[1]     ))
  #define CIP_SWAP_32(n) (uint32_t) ((((uint8_t*)&n)[0] <<24) | \
                                       (((uint8_t*)&n)[1] <<16) | \
                                       (((uint8_t*)&n)[2] << 8) | \
                                       (((uint8_t*)&n)[3]     ))
  #define CIP_UNPACK_16(n) (uint16_t) ((((uint8_t*)&n)[1] << 8) | \
                                         (((uint8_t*)&n)[0]     ))
  #define CIP_UNPACK_32(n) (uint32_t) ((((uint8_t*)&n)[3] <<24) | \
                                         (((uint8_t*)&n)[2] <<16) | \
                                         (((uint8_t*)&n)[1] << 8) | \
                                         (((uint8_t*)&n)[0]     ))

  /*#####################################################################################*/

  #define CIP_HOST_LITTLE_ENDIAN
  //#define CIP_HOST_BIG_ENDIAN
  #ifdef CIP_HOST_LITTLE_ENDIAN
  #define CIP_NTOH16(n) CIP_UNPACK_16(n)
  #define CIP_NTOH32(n) CIP_UNPACK_32(n)
  #define CIP_HTON16(n) CIP_UNPACK_16(n)
  #define CIP_HTON32(n) CIP_UNPACK_32(n)
  #elif defined (EIP_HOST_BIG_ENDIAN)
  #define CIP_NTOH16(n) CIP_SWAP_16(n)
  #define CIP_NTOH32(n) CIP_SWAP_32(n)
  #define CIP_HTON16(n) CIP_SWAP_16(n)
  #define CIP_HTON32(n) CIP_SWAP_32(n)
  #else
  #error "undefined endianess"
  #endif

  /*#####################################################################################*/

  /*
  *  Path Segment definitions
  */
  #define CIP_SEG_MASK                  0xE0
  #define CIP_SEG_PORT                  0x00
  #define CIP_SEG_LOGICAL               0x20
  #define CIP_SEG_NETWORK               0x40
  #define CIP_SEG_SYMBOLIC              0x60
  #define CIP_SEG_DATA                  0x80
  #define CIP_SEG_DATATYPE1             0xA0
  #define CIP_SEG_DATATYPE2             0xC0
  #define CIP_SEG_RESERVED              0xE0

  /* port segment */
  #define CIP_SEG_PORT_ID_MSK           0x0F      /* mask for the port identifier                       */
  #define CIP_SEG_PORT_LEN_EXT          0x10      /* mask if extended address information are available */

  /* Data segment */
  #define CIP_SEG_DATA_TYPE_MSK         0x1F  /* mask for the Data Segment Type */
  #define CIP_SEG_DATA_TYPE_SIMPLE      0x00
  #define CIP_SEG_DATA_TYPE_ASCII       0x11

  /* Logic segment */
  #define CIP_SEG_LOG_TYP_MASK          0x1C
  #define CIP_SEG_LOG_TYP_CLASS         0x00
  #define CIP_SEG_LOG_TYP_INSTANCE      0x04
  #define CIP_SEG_LOG_TYP_MEMBER        0x08
  #define CIP_SEG_LOG_TYP_CONNPOINT     0x0C
  #define CIP_SEG_LOG_TYP_ATTRIBUTE     0x10
  #define CIP_SEG_LOG_TYP_SPECIAL       0x14
  #define CIP_SEG_LOG_TYP_SERVICE       0x18
  #define CIP_SEG_LOG_TYP_RESERVED      0x1C
  #define CIP_SEG_LOG_TYP_EKEY          0x34

  #define CIP_SEG_LOG_FORMAT_MASK       0x03
  #define CIP_SEG_LOG_FORMAT_UINT8      0x00
  #define CIP_SEG_LOG_FORMAT_UINT16     0x01
  #define CIP_SEG_LOG_FORMAT_UINT32     0x02
  #define CIP_SEG_LOG_FORMAT_RESERV     0x03

  /* Net Segment */
  #define CIP_SEG_NET_SCHEDULE          0x01
  #define CIP_SEG_NET_FIXED             0x02
  #define CIP_SEG_NET_PROD_INHIBIT_TIME 0x03
  #define CIP_SEG_NET_SAFETY            0x10
  #define CIP_SEG_NET_EXTENDED          0x1F

  #define CIP_KEY_FORMAT_TABLE             4
  #define CIP_KEY_COMPATIBILITY         0x80
  #define CIP_KEY_MAJREV_MASK           0x7F
  /*
  ** CIP commands/services
  */
  #define CIP_CMD_RESPONSE                    0x80

  #define CIP_CMD_GET_ATTRIBUTE_ALL         ( 0x01 )
  #define CIP_CMD_SET_ATTRIBUTE_ALL         ( 0x02 )
  #define CIP_CMD_GET_ATTRIBUTE_LIST        ( 0x03 )
  #define CIP_CMD_SET_ATTRIBUTE_LIST        ( 0x04 )
  #define CIP_CMD_RESET                     ( 0x05 )
  #define CIP_CMD_START                     ( 0x06 )
  #define CIP_CMD_STOP                      ( 0x07 )
  #define CIP_CMD_CREATE                    ( 0x08 )
  #define CIP_CMD_DELETE                    ( 0x09 )
  #define CIP_CMD_GET_ATTRIBUTE_ALL         ( 0x01 )
  #define CIP_CMD_APPLY_ATTRIBUTES          ( 0x0D )
  #define CIP_CMD_GET_ATTR_SINGLE           ( 0x0E )
  #define CIP_CMD_SET_ATTR_SINGLE           ( 0x10 )
  #define CIP_CMD_FIND_NEXT_OBJ_INST        ( 0x11 )
  #define CIP_CMD_RESTORE                   ( 0x15 )
  #define CIP_CMD_SAVE                      ( 0x16 )
  #define CIP_CMD_NO_OPERATION              ( 0x17 )
  #define CIP_CMD_GET_MEMBER                ( 0x18 )
  #define CIP_CMD_SET_MEMBER                ( 0x19 )

  #define CIP_CMD_GET_AND_CLEAR             ( 0x4C )


  #define CIPHIL_CMD_RESET_OBJECT           ( 0xFF32 )
  #define CIPHIL_CMD_GET_ATTR_OPTION        ( 0xFF33 )
  #define CIPHIL_CMD_SET_ATTR_OPTION        ( 0xFF34 )
  #define CIPHIL_CMD_START_OBJECT           ( 0xFF35 )
  #define CIPHIL_CMD_STOP_OBJECT            ( 0xFF36 )

  /*#####################################################################################*/

  /*
  ** CIP general status codes
  */
  #define CIP_GSR_SUCCESS              0x00  /* We done good...               */
  #define CIP_GSR_FAILURE              0x01  /* Connection failure            */
  #define CIP_GSR_NO_RESOURCE          0x02  /* Resource(s) unavailable       */
  #define CIP_GSR_BAD_DATA             0x03  /* Obj specific data bad         */
  #define CIP_GSR_BAD_PATH             0x04  /* Path segment hosed            */
  #define CIP_GSR_BAD_CLASS_INSTANCE   0x05  /* Class/instance unknown        */
  #define CIP_GSR_PARTIAL_DATA         0x06  /* Not all expected data sent    */
  #define CIP_GSR_CONN_LOST            0x07  /* Messaging connection lost     */
  #define CIP_GSR_BAD_SERVICE          0x08  /* Unimplemented service code    */
  #define CIP_GSR_BAD_ATTR_DATA        0x09  /* Bad attribute data value      */
  #define CIP_GSR_ATTR_LIST_ERROR      0x0A  /* Get/set attr list failed      */
  #define CIP_GSR_ALREADY_IN_MODE      0x0B  /* Obj already in requested mode */
  #define CIP_GSR_BAD_OBJ_MODE         0x0C  /* Obj not in proper mode        */
  #define CIP_GSR_OBJ_ALREADY_EXISTS   0x0D  /* Object already created        */
  #define CIP_GSR_ATTR_NOT_SETTABLE    0x0E  /* Set of get only attr tried    */
  #define CIP_GSR_PERMISSION_DENIED    0x0F  /* Insufficient access permission*/
  #define CIP_GSR_DEV_IN_WRONG_STATE   0x10  /* Device not in proper mode     */
  #define CIP_GSR_REPLY_DATA_TOO_LARGE 0x11  /* Response packet too large     */
  #define CIP_GSR_FRAGMENT_PRIMITIVE   0x12  /* Primitive value will fragment */
  #define CIP_GSR_CONFIG_TOO_SMALL     0x13  /* Goldilocks complaint #1       */
  #define CIP_GSR_UNDEFINED_ATTR       0x14  /* Attribute is undefined        */
  #define CIP_GSR_CONFIG_TOO_BIG       0x15  /* Goldilocks complaint #2       */
  #define CIP_GSR_OBJ_DOES_NOT_EXIST   0x16  /* Non-existant object specified */
  #define CIP_GSR_NO_FRAGMENTATION     0x17  /* Fragmentation not active      */
  #define CIP_GSR_DATA_NOT_SAVED       0x18  /* Attr data not previously saved*/
  #define CIP_GSR_DATA_WRITE_FAILURE   0x19  /* Attr data not saved this time */
  #define CIP_GSR_REQUEST_TOO_LARGE    0x1A  /* Routing failure on request    */
  #define CIP_GSR_RESPONSE_TOO_LARGE   0x1B  /* Routing failure on response   */
  #define CIP_GSR_MISSING_LIST_DATA    0x1C  /* Attr data not found in list   */
  #define CIP_GSR_INVALID_LIST_STATUS  0x1D  /* Returned list of attr w/status*/
  #define CIP_GSR_SERVICE_ERROR        0x1E  /* Embedded service failed       */
  #define CIP_GSR_CONN_RELATED_FAILURE 0x1F  /* Error in conn processing      */
  #define CIP_GSR_INVALID_PARAMETER    0x20  /* Invalid Parameter             */
  #define CIP_GSR_WRITE_ONCE_FAILURE   0x21  /* Write once previously done    */
  #define CIP_GSR_INVALID_REPLY        0x22  /* Invalid reply received        */
  #define CIP_GSR_BAD_KEY_IN_PATH      0x25  /* Electronic key in path failed */
  #define CIP_GSR_BAD_PATH_SIZE        0x26  /* Invalid path size             */
  #define CIP_GSR_UNEXPECTED_ATTR      0x27  /* Cannot set attr at this time  */
  #define CIP_GSR_INVALID_MEMBER       0x28  /* Member ID in list nonexistant */
  #define CIP_GSR_MEMBER_NOT_SETTABLE  0x29  /* Cannot set value of member    */
  #define CIP_GSR_GROUP2_ONLY_S_GENERAL_FAIL  0x2A  /* Group 2 only server general failure */
  #define CIP_GSR_UNKNOWN_MODBUS_ERROR  0x2B /* CIP to Modbus reveived unknown Modbus error code */
  #define CIP_GSR_ATTRIBUTE_NOT_GET    0x2C  /* Attribute is not readable     */
  #define CIP_GSR_INSTANCE_NOT_DELETE  0x2D  /* Instance not deletable        */
  #define CIP_GSR_SERVICE_NOT_SUPPORT_PATH 0x2E /* Service not support for this path */
  #define CIP_GSR_STILL_PROCESSING     0xFF  /* Special marker to indicate    */
                                             /* we haven't finished processing*/
                                             /* the request yet               */

  /*#####################################################################################*/

  /* extended error codes for the connection manager */
  #define CIP_ESR_ALREADY_USED                             0x100  /* Connection already in use     */
  #define CIP_ESR_BAD_TRANSPORT                            0x103  /* Transport type not supported  */
  #define CIP_ESR_OWNER_CONFLICT                           0x106  /* More than one guy configuring */
  #define CIP_ESR_BAD_CONNECTION                           0x107  /* Trying to close inactive conn */
  #define CIP_ESR_BAD_CONN_TYPE                            0x108  /* Unsupported connection type   */
  #define CIP_ESR_BAD_CONN_SIZE                            0x109  /* Connection size mismatch      */

  #define CIP_ESR_CONN_UNCONFIGURED                        0x110  /* Connection unconfigured       */
  #define CIP_ESR_BAD_RPI                                  0x111  /* Unsupportable RPI             */
  #define CIP_ESR_NO_CM_RESOURCES                          0x113  /* Conn Mgr out of connections   */
  #define CIP_ESR_BAD_VENDOR_PRODUCT                       0x114  /* Mismatch in electronic key    */
  #define CIP_ESR_BAD_DEVICE_TYPE                          0x115  /* Mismatch in electronic key    */
  #define CIP_ESR_BAD_REVISION                             0x116  /* Mismatch in electronic key    */
  #define CIP_ESR_BAD_CONN_POINT                           0x117  /* Nonexistant instance number   */
  #define CIP_ESR_BAD_CONFIGURATION                        0x118  /* Bad config instance number    */
  #define CIP_ESR_CONN_REQ_FAILS                           0x119  /* No controlling connection opn */
  #define CIP_ESR_NO_APP_RESOURCES                         0x11A  /* App out of connections        */

  #define CIP_ESR_BAD_TRANSPORT_CLASS                      0x11C  /* The transport class requested in the
                                                                     Transport Type/Trigger parameter is
                                                                     not supported. */

  #define CIP_ESR_BAD_PRODUCTION_TRIGGER                   0x11D  /* The production trigger requested
                                                                     in the Transport Type/Trigger parameter
                                                                     is not supported. */

  #define CIP_ESR_BAD_DIRECTION                            0x11E  /* The direction requested in the Transport
                                                                     Type/Trigger parameter is not supported. */

  #define CIP_ESR_BAD_O2T_NETWORK_CONN_FIXVAR              0x11F  /* This extended status code shall be returned
                                                                     as the result of specifying an O2T
                                                                     fixed / variable flag that is not supported. */

  #define CIP_ESR_BAD_T2O_NETWORK_CONN_FIXVAR              0x120  /* This extended status code shall be returned
                                                                     as the result of specifying a T2O
                                                                     fixed / variable flag that is not supported. */

  #define CIP_ESR_BAD_02T_NETWORK_CONN_PRIORITY            0x121 /* This extended status code shall be returned
                                                                    as the result of specifying an O2T priority
                                                                    code that is not supported. */

  #define CIP_ESR_BAD_T20_NETWORK_CONN_PRIORITY            0x122 /* This extended status code shall be returned
                                                                     as the result of specifying a T2O priority
                                                                     code that is not supported. */

  #define CIP_ESR_BAD_02T_NETWORK_CONN_TYPE                0x123 /* This extended status code shall be returned
                                                                    as the result of specifying an O2T connection
                                                                    type that is not supported */

  #define CIP_ESR_BAD_T2O_NETWORK_CONN_TYPE                0x124 /* This extended status code shall be returned
                                                                    as the result of specifying a T2O connection
                                                                    type that is not supported */

  #define CIP_ESR_BAD_O2T_NETWORK_CONN_RED_OWNER           0x125 /* This extended status code shall be returned
                                                                    as the result of specifying an O2T Redundant
                                                                    Owner flag that is not supported */

  #define CIP_ESR_BAD_CONFIG_SIZE                          0x126 /* This extended status code is returned
                                                                    when the target device determines that
                                                                    the data segment provided in the
                                                                    Connection_Path parameter did not contain
                                                                    an acceptable number of 16-bit words
                                                                    for the the configuration application
                                                                    path requested.*/

  #define CIP_ESR_BAD_O2T_SIZE                             0x127 /* This extended status code is returned by the
                                                                    target when the size of the consuming object
                                                                    declared in the Forward_Open request and
                                                                    available on the target does not match the
                                                                    size declared in the O->T Network Connection
                                                                    Parameter. */

  #define CIP_ESR_BAD_T2O_SIZE                             0x128 /* This extended status code is returned by the
                                                                    target when the size of the producing object
                                                                    declared in the Forward Open request and
                                                                    available on the target does not match the
                                                                    size declared in the T->O Network Connection
                                                                    Parameter. */

  #define CIP_ESR_BAD_CONFIG_APPL_PATH                     0x129 /* The configuration application path specified
                                                                    in the connection path does not correspond to
                                                                    a valid configuration application path within
                                                                    the target application. This error could also
                                                                    be returned if a configuration application path
                                                                    was required, but not provided by a connection
                                                                    request */

  #define CIP_ESR_BAD_CONSUMING_APPL_PATH                  0x12A /* The consumed application path specified in the
                                                                    connection path does not correspond to a valid
                                                                    consumed application path within the target
                                                                    application. This error could also be returned
                                                                    if a consumed application path was required,
                                                                    but not provided by a connection request */

  #define CIP_ESR_BAD_PRODUCING_APPL_PATH                  0x12B /* The produced application path specified in the
                                                                    connection path does not correspond to a valid
                                                                    produced application path within the target
                                                                    application. This error could also be returned
                                                                    if a produced application path was required,
                                                                    but not provided by a connection request. */

  #define CIP_ESR_BAD_CONFIG_SYMBOL                        0x12C /* Configuration Symbol does not exist. The
                                                                    originator attempts to connect to a configuration
                                                                    tag name, but the name is not on the list of tags
                                                                    defined on the target. */

  #define CIP_ESR_BAD_CONSUMING_SYMBOL                     0x12D /* Consuming Symbol does not exist. The originator
                                                                    attempts to connect to a consuming tag name, but
                                                                    the name is not on the list of tags defined on the
                                                                    target. */

  #define CIP_ESR_BAD_PRODUCING_SYMBOL                     0x12E /* Producing Symbol does not exist. The originator
                                                                    attempts to connect to a producing tag name, but
                                                                    the name is not on the list of tags defined on the
                                                                    target. */

  #define CIP_ESR_BAD_APPL_PATH_COMBINATION                0x12F /* The combination of configuration and/or consume
                                                                    and/or produce application paths specified in the
                                                                    connection path are inconsistent with each other */

  #define CIP_ESR_BAD_CONSUME_DATA_FORMAT                  0x130 /* Information in the data segment is not consistent
                                                                    with the format of the consumed data. For example
                                                                    the configuration data specifies float configuration
                                                                    data while the consumed path specifies integer data */

  #define CIP_ESR_BAD_PRODUCE_DATA_FORMAT                  0x131 /* Information in the data segment is not consistent
                                                                    with the format of the produced data. For example the
                                                                    configuration data specifies float configuration data
                                                                    while the produced path specifies integer data. */

  #define CIP_ESR_CONN_TIMED_OUT                           0x203 /* Using a timed out connection  */
  #define CIP_ESR_UCSEND_TIMED_OUT                         0x204 /* Unconnected Send timed out    */
  #define CIP_ESR_UCSEND_PARAM_ERR                         0x205 /* Unconnected Send param. error */

  #define CIP_ESR_NO_BUFFER                                0x301 /* No buffer memory available    */
  #define CIP_ESR_NO_BANDWIDTH                             0x302 /* Insufficient bandwidth left   */
  #define CIP_ESR_NO_SCREENER                              0x303 /* Out of gen screeners          */
  #define CIP_ESR_NOT_CONF_FOR_RT                          0x304 /* Not configured to send RT data*/
  #define CIP_ESR_SIGNATURE_MISMATCH                       0x305 /* sig does not match sig store in CCM */
  #define CIP_ESR_CCM_NOT_AVAIL                            0x306 /* ccm is not responding to req. */

  #define CIP_ESR_BAD_PORT                                 0x311 /* Nonexistant port              */
  #define CIP_ESR_BAD_LINK_ADDRESS                         0x312 /* Invalid link address in path  */
  #define CIP_ESR_BAD_SEGMENT                              0x315 /* Invalid segment in path       */
  #define CIP_ESR_BAD_CLOSE                                0x316 /* Path & conn not equal in close*/
  #define CIP_ESR_BAD_NET_SEGMENT                          0x317 /* Net seg not present or bad    */
  #define CIP_ESR_BAD_LINK_AD_TO_SELF                      0x318 /* Link address to self invalid  */
  #define CIP_ESR_NO_SEC_RESOURCE                          0x319 /* Resources in secondary unavail*/

  #define CIP_ESR_REDUND_CONN_MISMATCH                     0x31D /* Redundant connection mismatch */

  #define CIP_ESR_NOT_CONFIGURED_FOR_OFF_SUBNET_MULTICAST  0x813  /* A multicast connection has been requested between a
                                                                     producer and a consumer that are on different subnets,
                                                                     and the producer is not configured for off-subnet multicast. */

  /*#####################################################################################*/

  /* Reserved Class Attributes */
  #define CIP_CLASS_ATTR_1_REVISION                 1
  #define CIP_CLASS_ATTR_2_MAX_INSTANCE             2
  #define CIP_CLASS_ATTR_3_NUM_INSTANCE             3
  #define CIP_CLASS_ATTR_4_ATTRIBUTE_LIST           4
  #define CIP_CLASS_ATTR_5_SERVICE_LIST             5
  #define CIP_CLASS_ATTR_6_MAX_CLASS_ATTRIBUTES     6
  #define CIP_CLASS_ATTR_7_MAX_INSTANCE_ATTRIBUTES  7

  #define CIP_RT_HEADER_RUN                0x00000001
  #define CIP_RT_HEADER_COO                0x00000002
  #define CIP_RT_HEADER_ROO_MSK            0x0000000C


  /*#####################################################################################*/

  /* Connection types */
  #define CIP_CTYPE_UNDEFINED          0x00
  #define CIP_CTYPE_EXCLUSIVE_OWNER    0x01
  #define CIP_CTYPE_REDUNDANT_OWNER    0x02
  #define CIP_CTYPE_LISTEN_ONLY        0x03
  #define CIP_CTYPE_INPUT_ONLY         0x04
  #define CIP_CTYPE_MESSAGING          0x05

  #define CIP_CONNECTION_OPEN          0x01
  #define CIP_CONNECTION_CLOSE         0x02
  #define CIP_CONNECTION_TIMEOUT       0x03


  /*#####################################################################################*/

  typedef  struct CIP_RESPONSE_Ttag
  {
    uint8_t  bService;
    uint8_t  bPad;
    uint8_t  bGeneralStatus;
    uint8_t  bAddStatusSize;
    uint16_t ausAddStatus[1];
  } CIP_RESPONSE_T;

  /*#####################################################################################*/

  #pragma pack(1)
  typedef __PACKED_PRE struct CIP_KEY_PACKED_Ttag
  {
    uint16_t  usVendorId;
    uint16_t  usProductType;
    uint16_t  usProductCode;
    uint8_t   bMajorRevision;
    uint8_t   bMinorRevision;
  }__PACKED_POST CIP_KEY_PACKED_T;

  /*#####################################################################################*/

  typedef __PACKED_PRE struct CIPHIL_SET_ATTR_OPTION_Ttag
  {
    uint16_t  usMask;
    uint16_t  usValue;
  }__PACKED_POST CIPHIL_SET_ATTR_OPTION_T;

  #pragma pack()

  /*#####################################################################################*/

  #define CIP_E_OK             (0)
  #define CIP_E_NO_RESSOURCES  (-1)
  #define CIP_E_EXIST          (-2)

  /*#####################################################################################*/

#endif
