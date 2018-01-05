/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: PNIO_status.h 60756 2016-04-20 09:16:16Z andreasme $:

Description:
 Profinet
 Profinet status codes
**************************************************************************************/
#ifndef __PNIO_STATUS_H
#define __PNIO_STATUS_H

/** PNIOStatus */
enum PNIO_STATUS_E
{
  /** success state code */
  PNIO_S_OK                                           = 0x00000000,

  /** read record error codes, the lowest byte can be used for additional
   * user specific information.
   *
   * 0xDE800000 - 0xDE809FFF is reserved for future usage */

  PNIO_E_IOD_READ_APPL_ERROR                          = 0xDE80A000,
  PNIO_E_IOD_READ_APPL_MODULEFAIL                     = 0xDE80A200,
  PNIO_E_IOD_READ_APPL_UNSPEC1                        = 0xDE80A300,
  PNIO_E_IOD_READ_APPL_UNSPEC2                        = 0xDE80A400,
  PNIO_E_IOD_READ_APPL_UNSPEC3                        = 0xDE80A500,
  PNIO_E_IOD_READ_APPL_UNSPEC4                        = 0xDE80A600,
  PNIO_E_IOD_READ_APPL_BUSY                           = 0xDE80A700,
  PNIO_E_IOD_READ_APPL_VERSIONCONFLICT                = 0xDE80A800,
  PNIO_E_IOD_READ_APPL_UNSUPPORTED                    = 0xDE80A900,
  PNIO_E_IOD_READ_APPL_USERSPEC1                      = 0xDE80AA00,
  PNIO_E_IOD_READ_APPL_USERSPEC2                      = 0xDE80AB00,
  PNIO_E_IOD_READ_APPL_USERSPEC3                      = 0xDE80AC00,
  PNIO_E_IOD_READ_APPL_USERSPEC4                      = 0xDE80AD00,
  PNIO_E_IOD_READ_APPL_USERSPEC5                      = 0xDE80AE00,
  PNIO_E_IOD_READ_APPL_USERSPEC6                      = 0xDE80AF00,

  PNIO_E_IOD_READ_ACCESS_INVALIDINDEX                 = 0xDE80B000,
  PNIO_E_IOD_READ_ACCESS_INVALIDSLOT_SUBSLOT          = 0xDE80B200,
  PNIO_E_IOD_READ_ACCESS_TYPECONFLICT                 = 0xDE80B300,
  PNIO_E_IOD_READ_ACCESS_INVALIDAPI_AREA              = 0xDE80B400,
  PNIO_E_IOD_READ_ACCESS_STATECONFLICT                = 0xDE80B500,
  PNIO_E_IOD_READ_ACCESS_DENIED                       = 0xDE80B600,
  PNIO_E_IOD_READ_ACCESS_INVALIDRANGE                 = 0xDE80B700,
  PNIO_E_IOD_READ_ACCESS_INVALIDPARAM                 = 0xDE80B800,
  PNIO_E_IOD_READ_ACCESS_INVALIDTYPE                  = 0xDE80B900,
  PNIO_E_IOD_READ_ACCESS_BACKUP                       = 0xDE80BA00,
  PNIO_E_IOD_READ_ACCESS_USERSPEC7                    = 0xDE80BB00,
  PNIO_E_IOD_READ_ACCESS_USERSPEC8                    = 0xDE80BC00,
  PNIO_E_IOD_READ_ACCESS_USERSPEC9                    = 0xDE80BD00,
  PNIO_E_IOD_READ_ACCESS_USERSPEC10                   = 0xDE80BE00,
  PNIO_E_IOD_READ_ACCESS_USERSPEC11                   = 0xDE80BF00,

  PNIO_E_IOD_READ_RESOURCE_CONSTRAINCONFLICT          = 0xDE80C000,
  PNIO_E_IOD_READ_RESOURCE_BUSY                       = 0xDE80C200,
  PNIO_E_IOD_READ_RESOURCE_UNAVAILABLE                = 0xDE80C300,
  PNIO_E_IOD_READ_RESOURCE_UNSPEC1                    = 0xDE80C400,
  PNIO_E_IOD_READ_RESOURCE_UNSPEC2                    = 0xDE80C500,
  PNIO_E_IOD_READ_RESOURCE_UNSPEC3                    = 0xDE80C600,
  PNIO_E_IOD_READ_RESOURCE_UNSPEC4                    = 0xDE80C700,
  PNIO_E_IOD_READ_RESOURCE_USERSPEC12                 = 0xDE80C800,
  PNIO_E_IOD_READ_RESOURCE_USERSPEC13                 = 0xDE80C900,
  PNIO_E_IOD_READ_RESOURCE_USERSPEC14                 = 0xDE80CA00,
  PNIO_E_IOD_READ_RESOURCE_USERSPEC15                 = 0xDE80CB00,
  PNIO_E_IOD_READ_RESOURCE_USERSPEC16                 = 0xDE80CC00,
  PNIO_E_IOD_READ_RESOURCE_USERSPEC17                 = 0xDE80CD00,
  PNIO_E_IOD_READ_RESOURCE_USERSPEC18                 = 0xDE80CE00,
  PNIO_E_IOD_READ_RESOURCE_USERSPEC19                 = 0xDE80CF00,

  /** 0xDE80D000 - 0xDE80FFFF can be used for user specific read errors */

  /** write record error codes, the lowest byte can be used for additional
   * user specific information.
   *
   * 0xDF800000 - 0xDF809FFF is reserved for future usage */

  PNIO_E_IOD_WRITE_APPL_ERROR                          = 0xDF80A100,
  PNIO_E_IOD_WRITE_APPL_MODULEFAIL                     = 0xDF80A200,
  PNIO_E_IOD_WRITE_APPL_UNSPEC1                        = 0xDF80A300,
  PNIO_E_IOD_WRITE_APPL_UNSPEC2                        = 0xDF80A400,
  PNIO_E_IOD_WRITE_APPL_UNSPEC3                        = 0xDF80A500,
  PNIO_E_IOD_WRITE_APPL_UNSPEC4                        = 0xDF80A600,
  PNIO_E_IOD_WRITE_APPL_BUSY                           = 0xDF80A700,
  PNIO_E_IOD_WRITE_APPL_VERSIONCONFLICT                = 0xDF80A800,
  PNIO_E_IOD_WRITE_APPL_UNSUPPORTED                    = 0xDF80A900,
  PNIO_E_IOD_WRITE_APPL_USERSPEC1                      = 0xDF80AA00,
  PNIO_E_IOD_WRITE_APPL_USERSPEC2                      = 0xDF80AB00,
  PNIO_E_IOD_WRITE_APPL_USERSPEC3                      = 0xDF80AC00,
  PNIO_E_IOD_WRITE_APPL_USERSPEC4                      = 0xDF80AD00,
  PNIO_E_IOD_WRITE_APPL_USERSPEC5                      = 0xDF80AE00,
  PNIO_E_IOD_WRITE_APPL_USERSPEC6                      = 0xDF80AF00,

  PNIO_E_IOD_WRITE_ACCESS_INVALIDINDEX                 = 0xDF80B000,
  PNIO_E_IOD_WRITE_ACCESS_INVALIDLENGTH                = 0xDF80B100,
  PNIO_E_IOD_WRITE_ACCESS_INVALIDSLOT_SUBSLOT          = 0xDF80B200,
  PNIO_E_IOD_WRITE_ACCESS_TYPECONFLICT                 = 0xDF80B300,
  PNIO_E_IOD_WRITE_ACCESS_INVALIDAPI_AREA              = 0xDF80B400,
  PNIO_E_IOD_WRITE_ACCESS_STATECONFLICT                = 0xDF80B500,
  PNIO_E_IOD_WRITE_ACCESS_DENIED                       = 0xDF80B600,
  PNIO_E_IOD_WRITE_ACCESS_INVALIDRANGE                 = 0xDF80B700,
  PNIO_E_IOD_WRITE_ACCESS_INVALIDPARAM                 = 0xDF80B800,
  PNIO_E_IOD_WRITE_ACCESS_INVALIDTYPE                  = 0xDF80B900,
  PNIO_E_IOD_WRITE_ACCESS_BACKUP                       = 0xDF80BA00,
  PNIO_E_IOD_WRITE_ACCESS_USERSPEC7                    = 0xDF80BB00,
  PNIO_E_IOD_WRITE_ACCESS_USERSPEC8                    = 0xDF80BC00,
  PNIO_E_IOD_WRITE_ACCESS_USERSPEC9                    = 0xDF80BD00,
  PNIO_E_IOD_WRITE_ACCESS_USERSPEC10                   = 0xDF80BE00,
  PNIO_E_IOD_WRITE_ACCESS_USERSPEC11                   = 0xDF80BF00,

  PNIO_E_IOD_WRITE_RESOURCE_CONSTRAINCONFLICT          = 0xDF80C100,
  PNIO_E_IOD_WRITE_RESOURCE_BUSY                       = 0xDF80C200,
  PNIO_E_IOD_WRITE_RESOURCE_UNAVAILABLE                = 0xDF80C300,
  PNIO_E_IOD_WRITE_RESOURCE_UNSPEC1                    = 0xDF80C400,
  PNIO_E_IOD_WRITE_RESOURCE_UNSPEC2                    = 0xDF80C500,
  PNIO_E_IOD_WRITE_RESOURCE_UNSPEC3                    = 0xDF80C600,
  PNIO_E_IOD_WRITE_RESOURCE_UNSPEC4                    = 0xDF80C700,
  PNIO_E_IOD_WRITE_RESOURCE_USERSPEC12                 = 0xDF80C800,
  PNIO_E_IOD_WRITE_RESOURCE_USERSPEC13                 = 0xDF80C900,
  PNIO_E_IOD_WRITE_RESOURCE_USERSPEC14                 = 0xDF80CA00,
  PNIO_E_IOD_WRITE_RESOURCE_USERSPEC15                 = 0xDF80CB00,
  PNIO_E_IOD_WRITE_RESOURCE_USERSPEC16                 = 0xDF80CC00,
  PNIO_E_IOD_WRITE_RESOURCE_USERSPEC17                 = 0xDF80CD00,
  PNIO_E_IOD_WRITE_RESOURCE_USERSPEC18                 = 0xDF80CE00,
  PNIO_E_IOD_WRITE_RESOURCE_USERSPEC19                 = 0xDF80CF00,

  /** 0xDF80D000 - 0xDF80FFFF can be used for user specific write errors */


  /* the following error codes shall NOT be used by a user application */
  /* they shall only be used by the stack itself */

  /** IOX decode */
  PNIO_E_DECODE_IOX                                    = 0xDB810000,

  /* AlarmAck - ErrorCode = 0xCF, ErrorDecode = 0x81, ErrorCode1 = 0x3C (60) */
  /** alarm acknowledge, alarm type is not supported */
  PNIO_E_ALARM_ACK_TYPE_NOT_SUPPORTED                 = 0xDA813C00,
  /** alarm acknowledge, submodule has wrong state */
  PNIO_E_ALARM_ACK_WRONG_SUBMODULE_STATUS             = 0xDA813C01,

  /*
   * IOXControlRes (IODControlRes, IOCControlRes, IOSControlRes) - connection establishment
   * ErrorCode = 0xDD, ErrorDecode = 0x81, ErrorCode1 = 0x16 (22)
   */
  PNIO_E_IOX_CONN                                     = 0x00001600,
  PNIO_E_IOX_CONN_BLOCK_TYPE                          = 0xDD811600,
  PNIO_E_IOX_CONN_BLOCK_LEN                           = 0xDD811601,
  PNIO_E_IOX_CONN_BLOCK_MAJOR                         = 0xDD811602,
  PNIO_E_IOX_CONN_BLOCK_MINOR                         = 0xDD811603,
  PNIO_E_IOX_CONN_ARUUID                              = 0xDD811605,
  PNIO_E_IOX_CONN_SESSION_KEY                         = 0xDD811606,
  PNIO_E_IOX_CONN_CONTROL_COMMAND                     = 0xDD811608,
  PNIO_E_IOX_CONN_CONTROL_PROPERTY                    = 0xDD811609,

  /*
   * IOXControlRes (IODControlRes, IOCControlRes, IOSControlRes) - a plug alarm
   * ErrorCode = 0xDD, ErrorDecode = 0x81, ErrorCode1 = 0x17 (23)
   */
  PNIO_E_IOX_PLUG                                     = 0x00001700,
  PNIO_E_IOX_PLUG_BLOCK_TYPE                          = 0xDD811700,
  PNIO_E_IOX_PLUG_BLOCK_LEN                           = 0xDD811701,
  PNIO_E_IOX_PLUG_BLOCK_MAJOR                         = 0xDD811702,
  PNIO_E_IOX_PLUG_BLOCK_MINOR                         = 0xDD811703,
  PNIO_E_IOX_PLUG_ARUUID                              = 0xDD811705,
  PNIO_E_IOX_PLUG_SESSION_KEY                         = 0xDD811706,
  PNIO_E_IOX_PLUG_CONTROL_COMMAND                     = 0xDD811708,
  PNIO_E_IOX_PLUG_CONTROL_PROPERTY                    = 0xDD811709,

  /* CMDEV - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x3D (61) */
  PNIO_E_CMDEV_STATE_CONFLICT                         = 0xDB813D00,
  PNIO_E_CMDEV_CONNECT_RESOURCE                       = 0xDB813D01,
  PNIO_E_CMDEV_CONTROL_RESOURCE                       = 0xDD813D01,

  /* CMCTL - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x3E (62) */
  PNIO_E_CMCTL_STATE_CONFLICT                         = 0x81813E01,
  PNIO_E_CMCTL_TIME_OUT                               = 0x81813E02,
  PNIO_E_CMCTL_NO_DATA_SEND                           = 0x81813E03,

  /* NRPM - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x3F (63) */
  PNIO_E_NRPM_NO_DCP_ACTIVE                           = 0x81813F00,
  PNIO_E_NRPM_DNS_STATIONNAME_UNKNOWN                 = 0x81813F01,
  PNIO_E_NRPM_DCP_STATIONNAME_NO_REAL                 = 0x81813F02,
  PNIO_E_NRPM_DCP_STATIONNAME_MULTIPLE                = 0x81813F03,
  PNIO_E_NRPM_DCP_STATIONNAME_FAILED                  = 0x81813F04,
  PNIO_E_NRPM_NO_IP_ADDRESS                           = 0x81813F05,
  PNIO_E_NRPM_DCP_SET_ERROR                           = 0x81813F06,
  PNIO_E_NRPM_UNSPECIFIC_ERROR                        = 0x81813FFF,

  /* RMPM - ErrorCode = Service, ErrorDecode = 0x81, ErrorCode1 = 0x40 (64) */
  PNIO_E_RMPM_CONNECT_ARGS_LEN_INVALID                = 0xDB814000,
  PNIO_E_RMPM_RELEASE_ARGS_LEN_INVALID                = 0xDC814000,
  PNIO_E_RMPM_CONTROL_ARGS_LEN_INVALID                = 0xDD814000,
  PNIO_E_RMPM_READ_ARGS_LEN_INVALID                   = 0xDE814000,
  PNIO_E_RMPM_WRITE_ARGS_LEN_INVALID                  = 0xDF814000,
  PNIO_E_RMPM_CONNECT_UNKNOWN_BLOCKS                  = 0xDB814001,
  PNIO_E_RMPM_CONTROL_UNKNOWN_BLOCKS                  = 0xDD814001,
  PNIO_E_RMPM_CONNECT_IOCR_MISSING                    = 0xDB814002,
  PNIO_E_RMPM_CONNECT_WRONG_ALCR_BLOCK_COUNT          = 0xDB814003,
  PNIO_E_RMPM_CONNECT_OUT_OF_AR_RESOURCES             = 0xDB814004,
  PNIO_E_RMPM_RELEASE_AR_UUID_UNKNOWN                 = 0xDC814005,
  PNIO_E_RMPM_CONTROL_AR_UUID_UNKNOWN                 = 0xDD814005,
  PNIO_E_RMPM_READ_AR_UUID_UNKNOWN                    = 0xDE814005,
  PNIO_E_RMPM_WRITE_AR_UUID_UNKNOWN                   = 0xDF814005,
  PNIO_E_RMPM_STATE_CONFLICT                          = 0xDB814006,
  PNIO_E_RMPM_OUT_OF_PROV_CONS_OR_ALARM_RESOURCES     = 0xDB814007,
  PNIO_E_RMPM_OUT_OF_MEMORY                           = 0xDB814008,
  PNIO_E_CMRPC_PDEV_ALREADY_OWNED                     = 0xDB814009,
  PNIO_E_CMRPC_ARSET_STATE_CONFLICT_DURING_CONNECT    = 0xDB81400A,
  PNIO_E_CMRPC_ARSET_PARAMETER_CONFLICT_DURING_CONNECT= 0xDB81400B,
  PNIO_E_RMPM_WRONG_SRINFO_BLOCK_COUNT_HILSCHER_VALUE = 0xDB8140F0,
  PNIO_E_RMPM_UNSPECIFIC_ERROR                        = 0xDB8140FF,

  /* ALPMI - ErrorCode = 0xCF, ErrorDecode = 0x81, ErrorCode1 = 0x41 (65) */
  PNIO_E_ALPMI_INVALID_STATE                          = 0xCF814100,
  PNIO_E_ALPMI_WRONG_ACK_PDU                          = 0xCF814101,

  /* ALPMR - ErrorCode = 0xCF, ErrorDecode = 0x81, ErrorCode1 = 0x42 (66) */
  PNIO_E_ALPMR_INVALID_STATE                          = 0xCF814200,
  PNIO_E_ALPMR_WRONG_NOTIFICATION_PDU                 = 0xCF814201,

  /* APMR - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x46 (70) */
  PNIO_E_APMR_STATE_CONFLICT                          = 0xCF814600,
  PNIO_E_APMR_LMPM_SIGNALED_ERROR                     = 0xCF814601,
  PNIO_E_APMR_UNSPECIFIC_ERROR                        = 0xCF8146FF,

  /* APMS - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x47 (71) */
  PNIO_E_APMS_STATE_CONFLICT                          = 0xCF814700,
  PNIO_E_APMS_LMPM_SIGNALED_ERROR                     = 0xCF814701,
  PNIO_E_APMS_PROTOCOL_TIMEOUT                        = 0xCF814702,
  PNIO_E_APMS_UNSPECIFIC_ERROR                        = 0xCF8147FF,

  /* CPM - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x48 (72) */
  PNIO_E_CPM_STATE_CONFLICT                           = 0xCF814800,

  /* PPM - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x49 (73) */
  PNIO_E_PPM_STATE_CONFLICT                           = 0xCF814900,

  /* DCPUCS - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x4A (74) */
  PNIO_E_DCPUCS_STATE_CONFLICT                        = 0xCF814A00,
  PNIO_E_DCPUCS_LMPM_SIGNALED_ERROR                   = 0xCF814A01,
  PNIO_E_DCPUCS_TIMEOUT                               = 0xCF814A02,
  PNIO_E_DCPUCS_UNSPECIFIC_ERROR                      = 0xCF814AFF,

  /* DCPUCR - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x4B (75) */
  PNIO_E_DCPUCR_STATE_CONFLICT                        = 0x81814B00,
  PNIO_E_DCPUCR_LMPM_SIGNALED_ERROR                   = 0x81814A01,
  PNIO_E_DCPUCR_UNSPECIFIC_ERROR                      = 0x81814BFF,

  /* DCPMCS - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x4C (76) */
  PNIO_E_DCPMCS_STATE_CONFLICT                        = 0x81814C00,
  PNIO_E_DCPMCS_LMPM_SIGNALED_ERROR                   = 0x81814A01,
  PNIO_E_DCPMCS_UNSPECIFIC_ERROR                      = 0x81814CFF,

  /* DCPMCR - ErrorCode = 0x81, ErrorDecode = 0x81, ErrorCode1 = 0x4D (77) */
  PNIO_E_DCPMCR_STATE_CONFLICT                        = 0x81814D00,
  PNIO_E_DCPMCR_LMPM_SIGNALED_ERROR                   = 0x81814A01,
  PNIO_E_DCPMCR_UNSPECIFIC_ERROR                      = 0x81814DFF,

  /* RTA - ErrorCode = 0xCF, ErrorDecode = 0x81, ErrorCode1 = 0xFD (253) */
  PNIO_E_RTA_PROTOCOL_RESERVED_0                      = 0xCF81FD00,
  PNIO_E_RTA_PROTOCOL_SEQUENCE_NUMBER                 = 0xCF81FD01,
  PNIO_E_RTA_PROTOCOL_INSTANCE_CLOSED                 = 0xCF81FD02,
  PNIO_E_RTA_PROTOCOL_OUT_OF_MEMORY                   = 0xCF81FD03,
  PNIO_E_RTA_PROTOCOL_ADD_PM_FAILED                   = 0xCF81FD04,
  PNIO_E_RTA_PROTOCOL_DHT_WDT_EXPIRED                 = 0xCF81FD05,
  PNIO_E_RTA_PROTOCOL_CMI_TIMEOUT                     = 0xCF81FD06,
  PNIO_E_RTA_PROTOCOL_ALARM_OPEN_FAILED               = 0xCF81FD07,
  PNIO_E_RTA_PROTOCOL_ALARM_SEND_NEG                  = 0xCF81FD08,
  PNIO_E_RTA_PROTOCOL_ALARM_SEND_NEG_ACK              = 0xCF81FD09,
  PNIO_E_RTA_PROTOCOL_ALARM_DATA_TOO_LONG             = 0xCF81FD0A,
  PNIO_E_RTA_PROTOCOL_ALARM_IND_ERR                   = 0xCF81FD0B,
  PNIO_E_RTA_PROTOCOL_RPC_CLIENT_CALL_NEG             = 0xCF81FD0C,
  PNIO_E_RTA_PROTOCOL_ABORT_REQ                       = 0xCF81FD0D,
  PNIO_E_RTA_PROTOCOL_RERUN_ABORT_EXISTING            = 0xCF81FD0E,
  PNIO_E_RTA_PROTOCOL_RELEASE_IND_RECEIVED            = 0xCF81FD0F,
  PNIO_E_RTA_PROTOCOL_DEVICE_DEACTIVATED              = 0xCF81FD10,
  PNIO_E_RTA_PROTOCOL_REMOVED                         = 0xCF81FD11,
  PNIO_E_RTA_PROTOCOL_PROTOCOL_VIOLATION              = 0xCF81FD12,
  PNIO_E_RTA_PROTOCOL_NAME_RESOLUTION_ERR             = 0xCF81FD13,
  PNIO_E_RTA_PROTOCOL_RPC_BIND_ERR                    = 0xCF81FD14,
  PNIO_E_RTA_PROTOCOL_RPC_CONNECT_ERR                 = 0xCF81FD15,
  PNIO_E_RTA_PROTOCOL_RPC_READ_ERR                    = 0xCF81FD16,
  PNIO_E_RTA_PROTOCOL_RPC_WRITE_ERR                   = 0xCF81FD17,
  PNIO_E_RTA_PROTOCOL_RPC_CONTROL_ERR                 = 0xCF81FD18,
  PNIO_E_RTA_PROTOCOL_FORBIDDEN_PULL_OR_PLUG          = 0xCF81FD19,
  PNIO_E_RTA_PROTOCOL_AP_REMOVED                      = 0xCF81FD1A,
  PNIO_E_RTA_PROTOCOL_LINK_DOWN                       = 0xCF81FD1B,
  PNIO_E_RTA_PROTOCOL_REGISTER_MC_MAC_FAILED          = 0xCF81FD1C,
  PNIO_E_RTA_PROTOCOL_NOT_SYNCHRONIZED                = 0xCF81FD1D,
  PNIO_E_RTA_PROTOCOL_WRONG_TOPOLOGY                  = 0xCF81FD1E,
  PNIO_E_RTA_PROTOCOL_DCP_NAMEOFSTATION_CHANGED       = 0xCF81FD1F,
  PNIO_E_RTA_PROTOCOL_DCP_RESET_FACTORY_SETTINGS      = 0xCF81FD20,
  PNIO_E_RTA_PROTOCOL_COMP_AR_0X8IPP_SUBMOD_FIRST_AR  = 0xCF81FD21,
  PNIO_E_RTA_PROTOCOL_NO_IR_DATA_RECORD_YET           = 0xCF81FD22,
  PNIO_E_RTA_PROTOCOL_PDEV                            = 0xCF81FD23,
  PNIO_E_RTA_PROTOCOL_PDEV_NO_PORT_OFFERS_REQ_SPEED_DUPLEXITY = 0xCF81FD24,
  PNIO_E_RTA_PROTOCOL_IP_SUITE_OF_IOC_CHANGED         = 0xCF81FD25,
  PNIO_E_RTA_PROTOCOL_IOCARSR_RDHT_EXPIRED            = 0xCF81FD26,
  PNIO_E_RTA_PROTOCOL_RESERVED_39                     = 0xCF81FD27,
  PNIO_E_RTA_PROTOCOL_RESERVED_200                    = 0xCF81FDC8,
  PNIO_E_RTA_PROTOCOL_MANUF_SPECIFIC_START            = 0xCF81FDC9,

  PNIO_E_RTA_PROTOCOL_REMOVED_AP_WATCHDOG_TIMEOUT     = 0xCF81FDC9,
  PNIO_E_RTA_PROTOCOL_REMOVED_AP_POOL_EMPTY           = 0xCF81FDCA,
  PNIO_E_RTA_PROTOCOL_REMOVED_AP_QUE_SENDPACKET_ERROR = 0xCF81FDCB,
  PNIO_E_RTA_PROTOCOL_REMOVED_AP_OUTOFMEMORY          = 0xCF81FDCC,
  PNIO_E_RTA_PROTOCOL_REMOVED_AP_IP_SUITE_CHANGED     = 0xCF81FDCD,

  PNIO_E_RTA_PROTOCOL_MANUF_SPECIFIC_END              = 0xCF81FDFF,
};




/** PNIOStatus IOX */
enum PNIO_E_DECODE_IO_Etag
{
  PNIO_E_DECODE_IOC                                   = 0xDD810000,
  PNIO_E_DECODE_IOD                                   = 0xDB810000,
  PNIO_E_DECODE_IOX_RW_PN                             = 0xDF810000,
  PNIO_E_DECODE_IOX_RW                                = 0xDF800000,
  PNIO_E_DECODE_IOX_REL                               = 0xDC810000,
  PNIO_E_DECODE_IOX_RR_PN                             = 0xDE810000,
  PNIO_E_DECODE_IOX_RR                                = 0xDE800000,
};

/** PNIOStatus IOX BLOCK */
enum PNIO_E_DECODE_IOX_BLOCK_E
{
  PNIO_E_DECODE_IOX_AR                                = 0x00000100,
  PNIO_E_DECODE_IOX_IOCR                              = 0x00000200,
  PNIO_E_DECODE_IOX_EXPS                              = 0x00000300,
  PNIO_E_DECODE_IOX_ALCR                              = 0x00000400,
  PNIO_E_DECODE_IOX_ARRPC                             = 0x00000700,
  PNIO_E_DECODE_IOX_RWREQ                             = 0x00000800,
  PNIO_E_DECODE_IOX_IRINFO                            = 0x00000900,
  PNIO_E_DECODE_IOX_SRINFO                            = 0x00000A00,
  PNIO_E_DECODE_IOX_ARFSU                             = 0x00000B00,
  PNIO_E_DECODE_IOX_IODCTRL                           = 0x00001400,
  PNIO_E_DECODE_IOX_IODCTRL_PLUG                      = 0x00001500,
  PNIO_E_DECODE_IOX_IODCTRL_PRMBEGIN                  = 0x00001800,
  PNIO_E_DECODE_IOX_IODCTRL_SUBMODULELIST             = 0x00001900,
  PNIO_E_DECODE_IOX_RELEASE                           = 0x00002800,
  PNIO_E_DECODE_RTA_PROTOCOL                          = 0x0000FD00,
};

/** PNIOStatus IOX BLOCK AR Req */
enum PNIO_E_DECODE_IOX_AR_E
{
  /* IOX code */
  PNIO_E_CODE_IOX_BLOCK_TYPE                          = 0x00000000,
  PNIO_E_CODE_IOX_BLOCK_LEN                           = 0x00000001,
  PNIO_E_CODE_IOX_BLOCK_MAJOR                         = 0x00000002,
  PNIO_E_CODE_IOX_BLOCK_MINOR                         = 0x00000003,
  PNIO_E_CODE_IOX_TYPE                                = 0x00000004,
  PNIO_E_CODE_IOX_ARUUID                              = 0x00000005,
  PNIO_E_CODE_IOX_SESSION_KEY                         = 0x00000006,
  PNIO_E_CODE_IOX_MAC                                 = 0x00000007,
  PNIO_E_CODE_IOX_CMI_OBJECTUUID                      = 0x00000008,
  PNIO_E_CODE_IOX_AR_PROPERTY                         = 0x00000009,
  PNIO_E_CODE_IOX_CLOCK_FACTOR                        = 0x0000000A,
  PNIO_E_CODE_IOX_UDP_RTPORT                          = 0x0000000B,
  PNIO_E_CODE_IOX_STATION_NAME_LEN                    = 0x0000000C,
  PNIO_E_CODE_IOX_STATION_NAME                        = 0x0000000D,
};

/** PNIOStatus IOX BLOCK IOCR Req */
enum PNIO_E_DECODE_IOX_IOCR_E
{
  PNIO_E_CODE_IOX_IOCR_REF                            = 0x00000005,
  PNIO_E_CODE_IOX_IOCR_LT                             = 0x00000006,
  PNIO_E_CODE_IOX_IOCR_PROPERTY                       = 0x00000007,
  PNIO_E_CODE_IOX_IOCR_DATA_LEN                       = 0x00000008,
  PNIO_E_CODE_IOX_IOCR_FRAME_ID                       = 0x00000009,
  PNIO_E_CODE_IOX_IOCR_SENDCLOCK_FACT                 = 0x0000000A,
  PNIO_E_CODE_IOX_IOCR_REDUCTION_RATIO                = 0x0000000B,
  PNIO_E_CODE_IOX_IOCR_PHASE                          = 0x0000000C,
  PNIO_E_CODE_IOX_IOCR_FRAME_SEND_OFFSET              = 0x0000000E,
  PNIO_E_CODE_IOX_IOCR_WATCHDOG_FACTOR                = 0x0000000F,
  PNIO_E_CODE_IOX_IOCR_DATA_HOLD_FACTOR               = 0x00000010,
  PNIO_E_CODE_IOX_IOCR_TAG_HEADER                     = 0x00000011,
  PNIO_E_CODE_IOX_IOCR_MC_ADDR                        = 0x00000012,
  PNIO_E_CODE_IOX_IOCR_NUM_API                        = 0x00000013,
  PNIO_E_CODE_IOX_IOCR_API                            = 0x00000014,
  PNIO_E_CODE_IOX_IOCR_NUM_IO_DATA_OBJ                = 0x00000015,
  PNIO_E_CODE_IOX_IOCR_SLOT_IO_DATA_OBJ               = 0x00000016,
  PNIO_E_CODE_IOX_IOCR_SUBSLOT_IO_DATA_OBJ            = 0x00000017,
  PNIO_E_CODE_IOX_IOCR_IO_DATA_OBJ_FRAME_OFFSET       = 0x00000018,
  PNIO_E_CODE_IOX_IOCR_NUM_IOCS                       = 0x00000019,
  PNIO_E_CODE_IOX_IOCR_SLOT_IOCS                      = 0x0000001A,
  PNIO_E_CODE_IOX_IOCR_SUBSLOT_IOCS                   = 0x0000001B,
  PNIO_E_CODE_IOX_IOCR_IOCS_FRAME_OFFSET              = 0x0000001C
};

/** PNIOStatus IOX BLOCK EXPS Req */
enum PNIO_E_DECODE_IOX_EXPS_E
{
  PNIO_E_CODE_IOX_EXPS_API                            = 0x00000005,
  PNIO_E_CODE_IOX_EXPS_SLOT                           = 0x00000006,
  PNIO_E_CODE_IOX_EXPS_MODULE_ID                      = 0x00000007,
  PNIO_E_CODE_IOX_EXPS_PROP                           = 0x00000008,
  PNIO_E_CODE_IOX_EXPS_NR_SUBS                        = 0x00000009,
  PNIO_E_CODE_IOX_EXPS_SUBSLOT                        = 0x0000000A,
  PNIO_E_CODE_IOX_EXPS_UNUSED_1                       = 0x0000000B,
  PNIO_E_CODE_IOX_EXPS_SUBMODULE_PROP                 = 0x0000000C,
  PNIO_E_CODE_IOX_EXPS_DATA_DESCRIPTION               = 0x0000000D,
  PNIO_E_CODE_IOX_EXPS_LENGTH_SUBMODULE_DATA          = 0x0000000E,
  PNIO_E_CODE_IOX_EXPS_LENGTH_IOPS                    = 0x0000000F,
  PNIO_E_CODE_IOX_EXPS_LENGTH_IOCS                    = 0x00000010,
};

/** PNIOStatus IOX BLOCK ALCR Req */
enum PNIO_E_DECODE_IOX_ALCR_E
{
  /* IOX code */
  PNIO_E_CODE_IOX_ALCR_TYPE                           = 0x00000004,
  PNIO_E_CODE_IOX_ALCR_LT                             = 0x00000005,
  PNIO_E_CODE_IOX_ALCR_PROPERTIES                     = 0x00000006,
  PNIO_E_CODE_IOX_ALCR_RTA_FACTOR                     = 0x00000007,
  PNIO_E_CODE_IOX_ALCR_RTA_RETRIES                    = 0x00000008,
  PNIO_E_CODE_IOX_ALCR_NOT_CHECKED_1                  = 0x00000009,
  PNIO_E_CODE_IOX_ALCR_MAX_ALARM_DATA_LEN             = 0x0000000A,
  PNIO_E_CODE_IOX_ALCR_ALARM_PRIO_HIGH                = 0x0000000B,
  PNIO_E_CODE_IOX_ALCR_ALARM_PRIO_LOW                 = 0x0000000C,
};

/** PNIOStatus IOX BLOCK IORW Req */
enum PNIO_E_DECODE_IOX_IORW_E
{
  PNIO_E_CODE_IOX_IORW_ARUUID                         = 0x00000005,
  PNIO_E_CODE_IOX_IORW_API                            = 0x00000006,
  PNIO_E_CODE_IOX_IORW_PADDING                        = 0x00000009,
};

/** @} */


/*************************************************************************************/
#endif /* #ifndef __PNIO_STATE_H */
