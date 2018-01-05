/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: Pnio_errors.h 48794 2014-10-22 11:48:47Z Benjamin $:

Description:
 Profinet
 Includes error codes of several Profinet tasks
**************************************************************************************/
#ifndef __PNIOC_ERROR_H
#define __PNIOC_ERROR_H

/////////////////////////////////////////////////////////////////////////////////////
// PNIO CTL Status codes
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// CMCTL-Task
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNIO_CMCTL_COMMAND_INVALID
//
// MessageText:
//
//  Received invalid command in CMCTL task.
//
#define TLR_E_PNIO_CMCTL_COMMAND_INVALID ((TLR_RESULT)0xC00A0001L)

//
// MessageId: TLR_E_PNIO_STATUS
//
// MessageText:
//
//  Generic error code. See packets data-status code for details.
//
#define TLR_E_PNIO_STATUS                ((TLR_RESULT)0xC00A0002L)

// CMCTL
//
// MessageId: TLR_E_PNIO_CMCTL_INIT_PARAM_INVALID
//
// MessageText:
//
//  Invalid parameter in CMCTL_ResourceInit().
//
#define TLR_E_PNIO_CMCTL_INIT_PARAM_INVALID ((TLR_RESULT)0xC00A0010L)

//
// MessageId: TLR_E_PNIO_CMCTL_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  No more CMCTL protocol machines possible.
//
#define TLR_E_PNIO_CMCTL_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC00A0011L)

//
// MessageId: TLR_E_PNIO_CMCTL_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for this request to CMCTL.
//
#define TLR_E_PNIO_CMCTL_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC00A0012L)

//
// MessageId: TLR_E_PNIO_CMCTL_CLOSED
//
// MessageText:
//
//  This CMCTL protocol machine was closed.
//
#define TLR_E_PNIO_CMCTL_CLOSED          ((TLR_RESULT)0xC00A0013L)

//
// MessageId: TLR_E_PNIO_CMCTL_STATE_CONFLICT
//
// MessageText:
//
//  This request can not be served in current CMCTL state.
//
#define TLR_E_PNIO_CMCTL_STATE_CONFLICT  ((TLR_RESULT)0xC00A0014L)

//
// MessageId: TLR_E_PNIO_CMCTL_CONFIG_PENDING
//
// MessageText:
//
//  The state of CMCTL's managment resource is pending.
//
#define TLR_E_PNIO_CMCTL_CONFIG_PENDING  ((TLR_RESULT)0xC00A0015L)

//
// MessageId: TLR_E_PNIO_CMCTL_CONFIG_STATE_INVALID
//
// MessageText:
//
//  The state of CMCTL's managment resource is invalid.
//
#define TLR_E_PNIO_CMCTL_CONFIG_STATE_INVALID ((TLR_RESULT)0xC00A0016L)

//
// MessageId: TLR_E_PNIO_CMCTL_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to create a packet in CMCTL task.
//
#define TLR_E_PNIO_CMCTL_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC00A0017L)

//
// MessageId: TLR_E_PNIO_CMCTL_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in CMCTL.
//
#define TLR_E_PNIO_CMCTL_PACKET_SEND_FAILED ((TLR_RESULT)0xC00A0018L)

//
// MessageId: TLR_E_PNIO_CMCTL_CONN_REQ_LEN_INVALID
//
// MessageText:
//
//  The length of the Connect-Packet in CMCTL_Connect_req() is invalid.
//
#define TLR_E_PNIO_CMCTL_CONN_REQ_LEN_INVALID ((TLR_RESULT)0xC00A0019L)

//
// MessageId: TLR_E_PNIO_CMCTL_NAME_LEN_INVALID
//
// MessageText:
//
//  The length of the name for IO-Device does not match to the name in CMCTL_Connect_req().
//
#define TLR_E_PNIO_CMCTL_NAME_LEN_INVALID ((TLR_RESULT)0xC00A001AL)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKNUM_UNEXPECTED
//
// MessageText:
//
//  The Connect-Confirmation contains an incorrect amount of blocks.
//
#define TLR_E_PNIO_CMCTL_BLKNUM_UNEXPECTED ((TLR_RESULT)0xC00A001BL)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKNUM_UNEXPECTED_MEMORY_FAULT
//
// MessageText:
//
//  The Connect-Confirmation contains an incorrect amount of blocks but may be received correctly in RPC-layer. CMCTL protocol-machine has not reserved enough memory for the whole confirmation.
//
#define TLR_E_PNIO_CMCTL_BLKNUM_UNEXPECTED_MEMORY_FAULT ((TLR_RESULT)0xC00A001CL)

//
// MessageId: TLR_E_PNIO_CMCTL_INVALID_FRAMEID_RECEIVED
//
// MessageText:
//
//  The Connect-Response from IO-Device specified an invalid FrameID to use for IO-Controllers OutputCR.
//
#define TLR_E_PNIO_CMCTL_INVALID_FRAMEID_RECEIVED ((TLR_RESULT)0xC00A001DL)

//
// MessageId: TLR_E_PNIO_CMCTL_EMPTY_POOL_DETECTED
//
// MessageText:
//
//  The packet pool of CMCTL is empty.
//
#define TLR_E_PNIO_CMCTL_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC00A001EL)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED
//
// MessageText:
//
//  The connect-confirmation contains an unexpected block.
//
#define TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED ((TLR_RESULT)0xC00A0020L)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_INIT
//
// MessageText:
//
//  CMCTL_Connect_req() expected an INIT-block that is missing.
//
#define TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_INIT ((TLR_RESULT)0xC00A0021L)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_IODW_REQ
//
// MessageText:
//
//  CMCTL_RMWrite_req() expected a WriteReq-block that is missing.
//
#define TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_IODW_REQ ((TLR_RESULT)0xC00A0022L)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_IODW_DATA
//
// MessageText:
//
//  CMCTL_RMWrite_req() expected a WriteData-block that is missing.
//
#define TLR_E_PNIO_CMCTL_BLKTYPE_UNEXPECTED_IODW_DATA ((TLR_RESULT)0xC00A0023L)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKLEN_INVALID_INIT
//
// MessageText:
//
//  INIT-block length for CMCTL_Connect_req() is invalid.
//
#define TLR_E_PNIO_CMCTL_BLKLEN_INVALID_INIT ((TLR_RESULT)0xC00A0030L)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKLEN_INVALID_IODW_REQ
//
// MessageText:
//
//  WriteReq-block's length for CMCTL_RMWrite_req() is invalid.
//
#define TLR_E_PNIO_CMCTL_BLKLEN_INVALID_IODW_REQ ((TLR_RESULT)0xC00A0031L)

//
// MessageId: TLR_E_PNIO_CMCTL_BLKLEN_INVALID_IODW_DATA
//
// MessageText:
//
//  WriteData-block's length for CMCTL_RMWrite_req() is invalid.
//
#define TLR_E_PNIO_CMCTL_BLKLEN_INVALID_IODW_DATA ((TLR_RESULT)0xC00A0032L)

//
// MessageId: TLR_E_PNIO_CMCTL_INVALID_PM_INDEX
//
// MessageText:
//
//  The index of CMCTL protocol-machine is invalid.
//
#define TLR_E_PNIO_CMCTL_INVALID_PM_INDEX ((TLR_RESULT)0xC00A0040L)

//
// MessageId: TLR_E_PNIO_CMCTL_INVALID_PM
//
// MessageText:
//
//  The CMCTL protocol-machine corresponding to index is invalid.
//
#define TLR_E_PNIO_CMCTL_INVALID_PM      ((TLR_RESULT)0xC00A0041L)

//
// MessageId: TLR_E_PNIO_CMCTL_INVALID_CMCTL_HANDLE
//
// MessageText:
//
//  The handle to CMCTL protocol-machine is invalid.
//
#define TLR_E_PNIO_CMCTL_INVALID_CMCTL_HANDLE ((TLR_RESULT)0xC00A0042L)

//
// MessageId: TLR_E_PNIO_CMCTL_DEVICE_NOT_RESPONDING
//
// MessageText:
//
//  The IO-Device which shall be connected does not answer.
//
#define TLR_E_PNIO_CMCTL_DEVICE_NOT_RESPONDING ((TLR_RESULT)0xC00A0050L)

//
// MessageId: TLR_E_PNIO_CMCTL_DUPLICATE_DEVICE_NAME_DETECTED
//
// MessageText:
//
//  More than one IO-Device with the specified NameOfStation exists; a connection can not be established.
//
#define TLR_E_PNIO_CMCTL_DUPLICATE_DEVICE_NAME_DETECTED ((TLR_RESULT)0xC00A0051L)

//
// MessageId: TLR_E_PNIO_CMCTL_DEVICE_IP_ADDRESS_ALREADY_IN_USE
//
// MessageText:
//
//  The IP-address the controller shall use for the IO-Device is already in use by another network device; a connection can not be established.
//
#define TLR_E_PNIO_CMCTL_DEVICE_IP_ADDRESS_ALREADY_IN_USE ((TLR_RESULT)0xC00A0052L)

//
// MessageId: TLR_E_PNIO_CMCTL_RPC_CONNECT_FAILED
//
// MessageText:
//
//  The Connect-Response of IO-Device contained an error code; a connection could not be established.
//
#define TLR_E_PNIO_CMCTL_RPC_CONNECT_FAILED ((TLR_RESULT)0xC00A0060L)

//
// MessageId: TLR_E_PNIO_CMCTL_RPC_WRITE_PARAM_FAILED
//
// MessageText:
//
//  The Write_Param-Response of IO-Device contained an error code; a connection could not be established.
//
#define TLR_E_PNIO_CMCTL_RPC_WRITE_PARAM_FAILED ((TLR_RESULT)0xC00A0061L)

//
// MessageId: TLR_E_PNIO_CMCTL_RPC_WRITE_FAILED
//
// MessageText:
//
//  The Write-Response of IO-Device contained an error code.
//
#define TLR_E_PNIO_CMCTL_RPC_WRITE_FAILED ((TLR_RESULT)0xC00A0062L)

//
// MessageId: TLR_E_PNIO_CMCTL_RPC_READ_FAILED
//
// MessageText:
//
//  The Read-Response of IO-Device contained an error code.
//
#define TLR_E_PNIO_CMCTL_RPC_READ_FAILED ((TLR_RESULT)0xC00A0063L)

//
// MessageId: TLR_E_PNIO_CMCTL_TCP_IP_SHUTDOWN
//
// MessageText:
//
//  The TCP/IP-Stack closed a socket needed for communication.
//
#define TLR_E_PNIO_CMCTL_TCP_IP_SHUTDOWN ((TLR_RESULT)0xC00A0064L)

//
// MessageId: TLR_E_PNIO_CMCTL_RPC_RESPONSE_TOO_SHORT
//
// MessageText:
//
//  The RPC-Response received does not have the required minimum length.
//
#define TLR_E_PNIO_CMCTL_RPC_RESPONSE_TOO_SHORT ((TLR_RESULT)0xC00A0065L)

// CMCTL AR
//
// MessageId: TLR_E_PNIO_CMCTL_AR_BLOCKTYPE
//
// MessageText:
//
//  The expected configuration block for AR in CMCTL_RMConnect_req_LoadAr() is missing.
//
#define TLR_E_PNIO_CMCTL_AR_BLOCKTYPE    ((TLR_RESULT)0xC00A0070L)

//
// MessageId: TLR_E_PNIO_CMCTL_AR_BLOCKLEN
//
// MessageText:
//
//  The expected configuration block for AR in CMCTL_RMConnect_req_LoadAr() has an invalid length.
//
#define TLR_E_PNIO_CMCTL_AR_BLOCKLEN     ((TLR_RESULT)0xC00A0071L)

//
// MessageId: TLR_E_PNIO_CMCTL_AR_TYPE
//
// MessageText:
//
//  The configuration block for AR in CMCTL_RMConnect_req_LoadAr() has an invalid type.
//
#define TLR_E_PNIO_CMCTL_AR_TYPE         ((TLR_RESULT)0xC00A0072L)

//
// MessageId: TLR_E_PNIO_CMCTL_AR_UUID
//
// MessageText:
//
//  The configuration block for AR in CMCTL_RMConnect_req_LoadAr() has an invalid UUID.
//
#define TLR_E_PNIO_CMCTL_AR_UUID         ((TLR_RESULT)0xC00A0073L)

//
// MessageId: TLR_E_PNIO_CMCTL_AR_PROPERTY
//
// MessageText:
//
//  The configuration block for AR in CMCTL_RMConnect_req_LoadAr() has an invalid network properties value.
//
#define TLR_E_PNIO_CMCTL_AR_PROPERTY     ((TLR_RESULT)0xC00A0074L)

//
// MessageId: TLR_E_PNIO_CMCTL_AR_REF_UNEXPECTED
//
// MessageText:
//
//  The AR-Reference for CMCTL protocol-machine is invalid.
//
#define TLR_E_PNIO_CMCTL_AR_REF_UNEXPECTED ((TLR_RESULT)0xC00A0075L)

//
// MessageId: TLR_E_PNIO_CMCTL_AR_UUID_COMP_FAILED
//
// MessageText:
//
//  The UUID inside IO-Device's Connect-Confirmation is incorrect.
//
#define TLR_E_PNIO_CMCTL_AR_UUID_COMP_FAILED ((TLR_RESULT)0xC00A0076L)

//
// MessageId: TLR_E_PNIO_CMCTL_AR_KEY_COMP_FAILED
//
// MessageText:
//
//  The session-key inside IO-Device's Connect-Confirmation is incorrect.
//
#define TLR_E_PNIO_CMCTL_AR_KEY_COMP_FAILED ((TLR_RESULT)0xC00A0077L)

//
// MessageId: TLR_E_PNIO_CMCTL_AR_MAC_COMP_FAILED
//
// MessageText:
//
//  The MAC-address of IO-Device is incorrect.
//
#define TLR_E_PNIO_CMCTL_AR_MAC_COMP_FAILED ((TLR_RESULT)0xC00A0078L)

// CMCTL ALCR
//
// MessageId: TLR_E_PNIO_CMCTL_ALCR_BLOCKTYPE
//
// MessageText:
//
//  The expected configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() is missing.
//
#define TLR_E_PNIO_CMCTL_ALCR_BLOCKTYPE  ((TLR_RESULT)0xC00A0080L)

//
// MessageId: TLR_E_PNIO_CMCTL_ALCR_BLOCKLEN
//
// MessageText:
//
//  The expected configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid length.
//
#define TLR_E_PNIO_CMCTL_ALCR_BLOCKLEN   ((TLR_RESULT)0xC00A0081L)

//
// MessageId: TLR_E_PNIO_CMCTL_ALCR_TYPE
//
// MessageText:
//
//  The configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid type.
//
#define TLR_E_PNIO_CMCTL_ALCR_TYPE       ((TLR_RESULT)0xC00A0082L)

//
// MessageId: TLR_E_PNIO_CMCTL_ALCR_PROPERTY
//
// MessageText:
//
//  The configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid network properties value.
//
#define TLR_E_PNIO_CMCTL_ALCR_PROPERTY   ((TLR_RESULT)0xC00A0083L)

//
// MessageId: TLR_E_PNIO_CMCTL_ALCR_RTA_FACTOR
//
// MessageText:
//
//  The configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid RTA-factor.
//
#define TLR_E_PNIO_CMCTL_ALCR_RTA_FACTOR ((TLR_RESULT)0xC00A0084L)

//
// MessageId: TLR_E_PNIO_CMCTL_ALCR_RTA_RETRY
//
// MessageText:
//
//  The configuration block for Alarm-CR in CMCTL_RMConnect_req_LoadAlcr() has an invalid value for RTA-retry.
//
#define TLR_E_PNIO_CMCTL_ALCR_RTA_RETRY  ((TLR_RESULT)0xC00A0085L)

// CMCTL IOCR
//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_BLOCKLEN
//
// MessageText:
//
//  The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an invalid length.
//
#define TLR_E_PNIO_CMCTL_IOCR_BLOCKLEN   ((TLR_RESULT)0xC00A0090L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_TYPE_UNSUPPORTED
//
// MessageText:
//
//  The type of IOCR is unsupported.
//
#define TLR_E_PNIO_CMCTL_IOCR_TYPE_UNSUPPORTED ((TLR_RESULT)0xC00A0091L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_TYPE_UNKNOWN
//
// MessageText:
//
//  The type of IOCR is unknown.
//
#define TLR_E_PNIO_CMCTL_IOCR_TYPE_UNKNOWN ((TLR_RESULT)0xC00A0092L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_RTCCLASS_UNSUPPORTED
//
// MessageText:
//
//  The RTC-class is unsupported.
//
#define TLR_E_PNIO_CMCTL_IOCR_RTCCLASS_UNSUPPORTED ((TLR_RESULT)0xC00A0093L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_RTCCLASS_UNKNOWN
//
// MessageText:
//
//  The RTC-class is unknown.
//
#define TLR_E_PNIO_CMCTL_IOCR_RTCCLASS_UNKNOWN ((TLR_RESULT)0xC00A0094L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_IFTYPE_UNSUPPORTED
//
// MessageText:
//
//  The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an unsupported interface-type.
//
#define TLR_E_PNIO_CMCTL_IOCR_IFTYPE_UNSUPPORTED ((TLR_RESULT)0xC00A0095L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_SCSYNC_UNSUPPORTED
//
// MessageText:
//
//  The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an unsupported value for SendClock.
//
#define TLR_E_PNIO_CMCTL_IOCR_SCSYNC_UNSUPPORTED ((TLR_RESULT)0xC00A0096L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_ADDRESS_UNSUPPORTED
//
// MessageText:
//
//  The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an unsupported Address-Resolution.
//
#define TLR_E_PNIO_CMCTL_IOCR_ADDRESS_UNSUPPORTED ((TLR_RESULT)0xC00A0097L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_REDUNDANCY_UNSUPPORTED
//
// MessageText:
//
//  The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() has an unsupported Media-Redundancy.
//
#define TLR_E_PNIO_CMCTL_IOCR_REDUNDANCY_UNSUPPORTED ((TLR_RESULT)0xC00A0098L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_REFERENCE
//
// MessageText:
//
//  No IOCR could be found or created.
//
#define TLR_E_PNIO_CMCTL_IOCR_REFERENCE  ((TLR_RESULT)0xC00A0099L)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_OBJECT_IOD
//
// MessageText:
//
//  The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() does not contain any IO-Data.
//
#define TLR_E_PNIO_CMCTL_IOCR_OBJECT_IOD ((TLR_RESULT)0xC00A009AL)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_OBJECT_IOS
//
// MessageText:
//
//  The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() does not contain any IO-Status.
//
#define TLR_E_PNIO_CMCTL_IOCR_OBJECT_IOS ((TLR_RESULT)0xC00A009BL)

//
// MessageId: TLR_E_PNIO_CMCTL_IOCR_API
//
// MessageText:
//
//  The expected configuration block for IOCR in CMCTL_RMConnect_req_LoadIocr() does not contain any API.
//
#define TLR_E_PNIO_CMCTL_IOCR_API        ((TLR_RESULT)0xC00A009CL)

// CMCTL EXPS
//
// MessageId: TLR_E_PNIO_CMCTL_EXPS_BLOCKLEN
//
// MessageText:
//
//  The expected configuration block for Expected-Submodules in CMCTL_RMConnect_req_LoadExps() has an invalid length.
//
#define TLR_E_PNIO_CMCTL_EXPS_BLOCKLEN   ((TLR_RESULT)0xC00A00A0L)

//
// MessageId: TLR_E_PNIO_CMCTL_EXPS_API
//
// MessageText:
//
//  The expected configuration block for Expected-Submodules in CMCTL_RMConnect_req_LoadExps() does not contain any API.
//
#define TLR_E_PNIO_CMCTL_EXPS_API        ((TLR_RESULT)0xC00A00A1L)

//
// MessageId: TLR_E_PNIO_CMCTL_EXPS_SUBMODULE
//
// MessageText:
//
//  The expected configuration block for Expected-Submodules in CMCTL_RMConnect_req_LoadExps() does not contain any submodules.
//
#define TLR_E_PNIO_CMCTL_EXPS_SUBMODULE  ((TLR_RESULT)0xC00A00A2L)

//
// MessageId: TLR_E_PNIO_CMCTL_EXPS_DATADESCRIPTION
//
// MessageText:
//
//  The expected configuration block for Expected-Submodules in CMCTL_RMConnect_req_LoadExps() does not contain the expected amount of data-descriptions.
//
#define TLR_E_PNIO_CMCTL_EXPS_DATADESCRIPTION ((TLR_RESULT)0xC00A00A3L)

//
// MessageId: TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_REMOTE
//
// MessageText:
//
//  The acyclic service failed. The IO-Device answered with an error code which is contained in confirmation packet.
//
#define TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_REMOTE ((TLR_RESULT)0xC00A00AAL)

//
// MessageId: TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_RPC
//
// MessageText:
//
//  The acyclic service failed. The RPC-layer detected an error which is contained in confirmation packet.
//
#define TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_RPC ((TLR_RESULT)0xC00A00ABL)

//
// MessageId: TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_INTERNAL
//
// MessageText:
//
//  The acyclic service failed. An internal error occured.
//
#define TLR_E_PNIO_CMCTL_ACYCLIC_REQ_FAILED_INTERNAL ((TLR_RESULT)0xC00A00ACL)

//
// MessageId: TLR_E_PNIO_CMCTL_LATE_ERROR_REPORTED
//
// MessageText:
//
//  The NRPM state machine reported a late error. This forced CMCTL to shutdown the connection
//
#define TLR_E_PNIO_CMCTL_LATE_ERROR_REPORTED ((TLR_RESULT)0xC00A00ADL)

// CMCTL SRInfo
//
// MessageId: TLR_E_PNIO_CMCTL_SRINFO_BLOCKTYPE
//
// MessageText:
//
//  The expected configuration block for SRInfo in CMCTL_RMConnect_req_LoadSRInfo() is missing.
//
#define TLR_E_PNIO_CMCTL_SRINFO_BLOCKTYPE ((TLR_RESULT)0xC00A00B0L)

//
// MessageId: TLR_E_PNIO_CMCTL_SRINFO_BLOCKLEN
//
// MessageText:
//
//  The expected configuration block for SRInfo in CMCTL_RMConnect_req_LoadSRInfo() has an invalid length.
//
#define TLR_E_PNIO_CMCTL_SRINFO_BLOCKLEN ((TLR_RESULT)0xC00A00B1L)

/////////////////////////////////////////////////////////////////////////////////////
// CMDEV-Task
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNIO_CMDEV_COMMAND_INVALID
//
// MessageText:
//
//  Received invalid command in CMDEV task.
//
#define TLR_E_PNIO_CMDEV_COMMAND_INVALID ((TLR_RESULT)0xC00B0001L)

// CMDEV
//
// MessageId: TLR_E_PNIO_CMDEV_INIT_PARAM_INVALID
//
// MessageText:
//
//  Invalid parameter in CMDEV_ResourceInit().
//
#define TLR_E_PNIO_CMDEV_INIT_PARAM_INVALID ((TLR_RESULT)0xC00B0010L)

//
// MessageId: TLR_E_PNIO_CMDEV_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  No more CMDEV protocol machines possible.
//
#define TLR_E_PNIO_CMDEV_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC00B0011L)

//
// MessageId: TLR_E_PNIO_CMDEV_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for this request to CMDEV.
//
#define TLR_E_PNIO_CMDEV_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC00B0012L)

//
// MessageId: TLR_E_PNIO_CMDEV_CLOSED
//
// MessageText:
//
//  This CMDEV protocol machine was closed.
//
#define TLR_E_PNIO_CMDEV_CLOSED          ((TLR_RESULT)0xC00B0013L)

//
// MessageId: TLR_E_PNIO_CMDEV_STATE_CONFLICT
//
// MessageText:
//
//  This request can not be served in current CMDEV state.
//
#define TLR_E_PNIO_CMDEV_STATE_CONFLICT  ((TLR_RESULT)0xC00B0014L)

//
// MessageId: TLR_E_PNIO_CMDEV_CONFIG_PENDING
//
// MessageText:
//
//  The state of CMDEV's managment resource is pending.
//
#define TLR_E_PNIO_CMDEV_CONFIG_PENDING  ((TLR_RESULT)0xC00B0015L)

//
// MessageId: TLR_E_PNIO_CMDEV_CONFIG_STATE_INVALID
//
// MessageText:
//
//  The state of CMDEV's managment resource is invalid.
//
#define TLR_E_PNIO_CMDEV_CONFIG_STATE_INVALID ((TLR_RESULT)0xC00B0016L)

//
// MessageId: TLR_E_PNIO_CMDEV_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to create a packet in CMDEV task.
//
#define TLR_E_PNIO_CMDEV_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC00B0017L)

//
// MessageId: TLR_E_PNIO_CMDEV_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in CMDEV.
//
#define TLR_E_PNIO_CMDEV_PACKET_SEND_FAILED ((TLR_RESULT)0xC00B0018L)

//
// MessageId: TLR_E_PNIO_CMDEV_CONN_REQ_LEN_INVALID
//
// MessageText:
//
//  The length of the Connect-Packet in CMDEV_Connect_req() is invalid.
//
#define TLR_E_PNIO_CMDEV_CONN_REQ_LEN_INVALID ((TLR_RESULT)0xC00B0019L)

//
// MessageId: TLR_E_PNIO_CMDEV_NAME_LEN_INVALID
//
// MessageText:
//
//  The length of the name for IO-Device does not match to the name in CMDEV_Connect_req().
//
#define TLR_E_PNIO_CMDEV_NAME_LEN_INVALID ((TLR_RESULT)0xC00B001AL)

//
// MessageId: TLR_E_PNIO_CMDEV_BLKNUM_UNEXPECTED
//
// MessageText:
//
//  The Connect-Confirmation contains an incorrect amount of blocks.
//
#define TLR_E_PNIO_CMDEV_BLKNUM_UNEXPECTED ((TLR_RESULT)0xC00B001BL)

//
// MessageId: TLR_E_PNIO_CMDEV_BLKNUM_UNEXPECTED_MEMORY_FAULT
//
// MessageText:
//
//  The Connect-Confirmation contains an incorrect amount of blocks but may be received correctly in RPC-layer. CMDEV protocol-machine has not reserved enough memory for the whole confirmation.
//
#define TLR_E_PNIO_CMDEV_BLKNUM_UNEXPECTED_MEMORY_FAULT ((TLR_RESULT)0xC00B001CL)

//
// MessageId: TLR_E_PNIO_CMDEV_INVALID_FRAMEID_RECEIVED
//
// MessageText:
//
//  The Connect-Response from IO-Device specified an invalid FrameID to use for IO-Controllers OutputCR.
//
#define TLR_E_PNIO_CMDEV_INVALID_FRAMEID_RECEIVED ((TLR_RESULT)0xC00B001DL)

//
// MessageId: TLR_E_PNIO_CMDEV_PNIO_STATUS
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_PNIO_STATUS     ((TLR_RESULT)0xC00B001EL)

//
// MessageId: TLR_E_PNIO_CMDEV_EMPTY_POOL_DETECTED
//
// MessageText:
//
//  The packet pool of CMDEV is empty.
//
#define TLR_E_PNIO_CMDEV_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC00B001FL)

//
// MessageId: TLR_E_PNIO_CMDEV_PACKET_WRONG_DEVICEHANDLE
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_PACKET_WRONG_DEVICEHANDLE ((TLR_RESULT)0xC00B0020L)

//
// MessageId: TLR_E_PNIO_CMDEV_POINTER_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_POINTER_INVALID ((TLR_RESULT)0xC00B0021L)

//
// MessageId: TLR_E_PNIO_CMDEV_FUNCTION_RETURN_FAILURE
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_FUNCTION_RETURN_FAILURE ((TLR_RESULT)0xC00B0022L)

//
// MessageId: TLR_E_PNIO_CMDEV_WAIT_FOR_PACKET_FAILED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_WAIT_FOR_PACKET_FAILED ((TLR_RESULT)0xC00B0023L)

//
// MessageId: TLR_E_PNIO_CMDEV_ALPMI_ACTIVATE_FAILED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_ALPMI_ACTIVATE_FAILED ((TLR_RESULT)0xC00B0024L)

//
// MessageId: TLR_E_PNIO_CMDEV_BUILD_CONNECT_RSP_FAILED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_BUILD_CONNECT_RSP_FAILED ((TLR_RESULT)0xC00B0025L)

//
// MessageId: TLR_E_PNIO_CMDEV_AP_ENTRY_NOT_FOUND
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_AP_ENTRY_NOT_FOUND ((TLR_RESULT)0xC00B0026L)

//
// MessageId: TLR_E_PNIO_CMDEV_TIMER_CREATE_FAILED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_TIMER_CREATE_FAILED ((TLR_RESULT)0xC00B0027L)

//
// MessageId: TLR_E_PNIO_CMDEV_ERROR_SEQUENCE
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_ERROR_SEQUENCE  ((TLR_RESULT)0xC00B0028L)

//
// MessageId: TLR_E_PNIO_CMDEV_INVALID_PLUG_REQUEST_PCK
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_INVALID_PLUG_REQUEST_PCK ((TLR_RESULT)0xC00B0029L)

//
// MessageId: TLR_E_PNIO_CMDEV_INVALID_PULL_REQUEST_PCK
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_INVALID_PULL_REQUEST_PCK ((TLR_RESULT)0xC00B002AL)

//
// MessageId: TLR_E_PNIO_CMDEV_PLUG_SLOT_NOT_EXPECTED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_PLUG_SLOT_NOT_EXPECTED ((TLR_RESULT)0xC00B002BL)

//
// MessageId: TLR_E_PNIO_CMDEV_PLUG_SUBSLOT_NOT_EXPECTED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_PLUG_SUBSLOT_NOT_EXPECTED ((TLR_RESULT)0xC00B002CL)

//
// MessageId: TLR_E_PNIO_CMDEV_RPC_PACKET_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_RPC_PACKET_INVALID ((TLR_RESULT)0xC00B002DL)

//
// MessageId: TLR_E_PNIO_CMDEV_ALPMI_INIT_FAILED
//
// MessageText:
//
//  Initializing the ALPMI state machine failed.
//
#define TLR_E_PNIO_CMDEV_ALPMI_INIT_FAILED ((TLR_RESULT)0xC00B002EL)

//
// MessageId: TLR_E_PNIO_CMDEV_CHANGE_BUS_STATE_FAILED
//
// MessageText:
//
//  Changing the internal Bus state failed.
//
#define TLR_E_PNIO_CMDEV_CHANGE_BUS_STATE_FAILED ((TLR_RESULT)0xC00B002FL)

//
// MessageId: TLR_E_PNIO_CMDEV_INVALID_PM_INDEX
//
// MessageText:
//
//  The index of CMDEV protocol-machine is invalid.
//
#define TLR_E_PNIO_CMDEV_INVALID_PM_INDEX ((TLR_RESULT)0xC00B0040L)

//
// MessageId: TLR_E_PNIO_CMDEV_INVALID_PM
//
// MessageText:
//
//  The CMDEV protocol-machine corresponding to index is invalid.
//
#define TLR_E_PNIO_CMDEV_INVALID_PM      ((TLR_RESULT)0xC00B0041L)

//
// MessageId: TLR_E_PNIO_CMDEV_INVALID_CMDEV_HANDLE
//
// MessageText:
//
//  The handle to CMDEV protocol-machine is invalid.
//
#define TLR_E_PNIO_CMDEV_INVALID_CMDEV_HANDLE ((TLR_RESULT)0xC00B0042L)

//
// MessageId: TLR_E_PNIO_CMDEV_SUBMODULE_NOT_IN_CYCLIC_DATA_EXCHANGE
//
// MessageText:
//
//  The request can not be handled because the submodule is not contained in cyclic data exchange.
//
#define TLR_E_PNIO_CMDEV_SUBMODULE_NOT_IN_CYCLIC_DATA_EXCHANGE ((TLR_RESULT)0xC00B0043L)

//
// MessageId: TLR_E_PNIO_CMDEV_DEVICE_NOT_RESPONDING
//
// MessageText:
//
//  The IO-Device which shall be connected does not answer.
//
#define TLR_E_PNIO_CMDEV_DEVICE_NOT_RESPONDING ((TLR_RESULT)0xC00B0050L)

//
// MessageId: TLR_E_PNIO_CMDEV_DUPLICATE_DEVICE_NAME_DETECTED
//
// MessageText:
//
//  More than one IO-Device with the specified NameOfStation exists; a connection can not be established.
//
#define TLR_E_PNIO_CMDEV_DUPLICATE_DEVICE_NAME_DETECTED ((TLR_RESULT)0xC00B0051L)

//
// MessageId: TLR_E_PNIO_CMDEV_DEVICE_IP_ADDRESS_ALREADY_IN_USE
//
// MessageText:
//
//  The IP-address the controller shall use for the IO-Device is already in use by another network device; a connection can not be established.
//
#define TLR_E_PNIO_CMDEV_DEVICE_IP_ADDRESS_ALREADY_IN_USE ((TLR_RESULT)0xC00B0052L)

//
// MessageId: TLR_E_PNIO_CMDEV_TOO_MUCH_ALARM_DATA
//
// MessageText:
//
//  The packet contains to much alarm data.
//
#define TLR_E_PNIO_CMDEV_TOO_MUCH_ALARM_DATA ((TLR_RESULT)0xC00B0053L)

//
// MessageId: TLR_E_PNIO_CMDEV_RPC_CONNECT_FAILED
//
// MessageText:
//
//  The Connect-Response of IO-Device contained an error code; a connection could not be established.
//
#define TLR_E_PNIO_CMDEV_RPC_CONNECT_FAILED ((TLR_RESULT)0xC00B0060L)

//
// MessageId: TLR_E_PNIO_CMDEV_RPC_WRITE_PARAM_FAILED
//
// MessageText:
//
//  The Write_Param-Response of IO-Device contained an error code; a connection could not be established.
//
#define TLR_E_PNIO_CMDEV_RPC_WRITE_PARAM_FAILED ((TLR_RESULT)0xC00B0061L)

//
// MessageId: TLR_E_PNIO_CMDEV_RPC_WRITE_FAILED
//
// MessageText:
//
//  The Write-Response of IO-Device contained an error code.
//
#define TLR_E_PNIO_CMDEV_RPC_WRITE_FAILED ((TLR_RESULT)0xC00B0062L)

//
// MessageId: TLR_E_PNIO_CMDEV_RPC_READ_FAILED
//
// MessageText:
//
//  The Read-Response of IO-Device contained an error code.
//
#define TLR_E_PNIO_CMDEV_RPC_READ_FAILED ((TLR_RESULT)0xC00B0063L)

//
// MessageId: TLR_E_PNIO_CMDEV_TCP_IP_SHUTDOWN
//
// MessageText:
//
//  The TCP/IP-Stack closed a socket needed for communication.
//
#define TLR_E_PNIO_CMDEV_TCP_IP_SHUTDOWN ((TLR_RESULT)0xC00B0064L)

// CMDEV AR
//
// MessageId: TLR_E_PNIO_CMDEV_AR_BLOCKTYPE
//
// MessageText:
//
//  The expected configuration block for AR in CMDEV_RMConnect_req_LoadAr() is missing.
//
#define TLR_E_PNIO_CMDEV_AR_BLOCKTYPE    ((TLR_RESULT)0xC00B0070L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_BLOCKLEN
//
// MessageText:
//
//  The expected configuration block for AR in CMDEV_RMConnect_req_LoadAr() has an invalid length.
//
#define TLR_E_PNIO_CMDEV_AR_BLOCKLEN     ((TLR_RESULT)0xC00B0071L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_TYPE
//
// MessageText:
//
//  The configuration block for AR in CMDEV_RMConnect_req_LoadAr() has an invalid type.
//
#define TLR_E_PNIO_CMDEV_AR_TYPE         ((TLR_RESULT)0xC00B0072L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_UUID
//
// MessageText:
//
//  The configuration block for AR in CMDEV_RMConnect_req_LoadAr() has an invalid UUID.
//
#define TLR_E_PNIO_CMDEV_AR_UUID         ((TLR_RESULT)0xC00B0073L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_PROPERTY
//
// MessageText:
//
//  The configuration block for AR in CMDEV_RMConnect_req_LoadAr() has an invalid network properties value.
//
#define TLR_E_PNIO_CMDEV_AR_PROPERTY     ((TLR_RESULT)0xC00B0074L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_REF_UNEXPECTED
//
// MessageText:
//
//  The AR-Reference for CMDEV protocol-machine is invalid.
//
#define TLR_E_PNIO_CMDEV_AR_REF_UNEXPECTED ((TLR_RESULT)0xC00B0075L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_UUID_COMP_FAILED
//
// MessageText:
//
//  The UUID inside IO-Device's Connect-Confirmation is incorrect.
//
#define TLR_E_PNIO_CMDEV_AR_UUID_COMP_FAILED ((TLR_RESULT)0xC00B0076L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_KEY_COMP_FAILED
//
// MessageText:
//
//  The session-key inside IO-Device's Connect-Confirmation is incorrect.
//
#define TLR_E_PNIO_CMDEV_AR_KEY_COMP_FAILED ((TLR_RESULT)0xC00B0077L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_MAC_COMP_FAILED
//
// MessageText:
//
//  The MAC-address of IO-Device is incorrect.
//
#define TLR_E_PNIO_CMDEV_AR_MAC_COMP_FAILED ((TLR_RESULT)0xC00B0078L)

// CMDEV adressing related problems
//
// MessageId: TLR_E_PNIO_CMDEV_INSERT_MODULE_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_INSERT_MODULE_ERROR ((TLR_RESULT)0xC00B0080L)

//
// MessageId: TLR_E_PNIO_CMDEV_INSERT_SUBMODULE_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_INSERT_SUBMODULE_ERROR ((TLR_RESULT)0xC00B0081L)

//
// MessageId: TLR_E_PNIO_CMDEV_MAX_API_LIMIT_EXCEEDED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_MAX_API_LIMIT_EXCEEDED ((TLR_RESULT)0xC00B0082L)

//
// MessageId: TLR_E_PNIO_CMDEV_API_ALREADY_ADDED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_API_ALREADY_ADDED ((TLR_RESULT)0xC00B0083L)

//
// MessageId: TLR_E_PNIO_CMDEV_SLOT_OUT_OF_RANGE
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_SLOT_OUT_OF_RANGE ((TLR_RESULT)0xC00B0084L)

//
// MessageId: TLR_E_PNIO_CMDEV_SUBSLOT_OUT_OF_RANGE
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_SUBSLOT_OUT_OF_RANGE ((TLR_RESULT)0xC00B0085L)

//
// MessageId: TLR_E_PNIO_CMDEV_SUBSLOT_ALREADY_EXISTS
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_SUBSLOT_ALREADY_EXISTS ((TLR_RESULT)0xC00B0086L)

//
// MessageId: TLR_E_PNIO_CMDEV_PACKET_WRONG_API
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_PACKET_WRONG_API ((TLR_RESULT)0xC00B0087L)

//
// MessageId: TLR_E_PNIO_CMDEV_PACKET_WRONG_SLOT
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_PACKET_WRONG_SLOT ((TLR_RESULT)0xC00B0088L)

//
// MessageId: TLR_E_PNIO_CMDEV_PACKET_WRONG_SUBSLOT
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_PACKET_WRONG_SUBSLOT ((TLR_RESULT)0xC00B0089L)

//
// MessageId: TLR_E_PNIO_CMDEV_SLOT_ENTRY_NOT_FOUND
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_SLOT_ENTRY_NOT_FOUND ((TLR_RESULT)0xC00B008AL)

//
// MessageId: TLR_E_PNIO_CMDEV_SLOT_ALREADY_EXISTS
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_SLOT_ALREADY_EXISTS ((TLR_RESULT)0xC00B008BL)

//
// MessageId: TLR_E_PNIO_CMDEV_SUBSLOT_ENTRY_NOT_FOUND
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_SUBSLOT_ENTRY_NOT_FOUND ((TLR_RESULT)0xC00B008CL)

//
// MessageId: TLR_E_PNIO_CMDEV_FILTERED
//
// MessageText:
//
//  A CheckIndication shall not be forwarded to the user according to configuration.
//
#define TLR_E_PNIO_CMDEV_FILTERED        ((TLR_RESULT)0xC00B008DL)

// CMDEV IOCR
//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_BLOCKLEN
//
// MessageText:
//
//  The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an invalid length.
//
#define TLR_E_PNIO_CMDEV_IOCR_BLOCKLEN   ((TLR_RESULT)0xC00B0090L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_TYPE_UNSUPPORTED
//
// MessageText:
//
//  The type of IOCR is unsupported.
//
#define TLR_E_PNIO_CMDEV_IOCR_TYPE_UNSUPPORTED ((TLR_RESULT)0xC00B0091L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_TYPE_UNKNOWN
//
// MessageText:
//
//  The type of IOCR is unknown.
//
#define TLR_E_PNIO_CMDEV_IOCR_TYPE_UNKNOWN ((TLR_RESULT)0xC00B0092L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_RTCCLASS_UNSUPPORTED
//
// MessageText:
//
//  The RTC-class is unsupported.
//
#define TLR_E_PNIO_CMDEV_IOCR_RTCCLASS_UNSUPPORTED ((TLR_RESULT)0xC00B0093L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_RTCCLASS_UNKNOWN
//
// MessageText:
//
//  The RTC-class is unknown.
//
#define TLR_E_PNIO_CMDEV_IOCR_RTCCLASS_UNKNOWN ((TLR_RESULT)0xC00B0094L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_IFTYPE_UNSUPPORTED
//
// MessageText:
//
//  The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an unsupported interface-type.
//
#define TLR_E_PNIO_CMDEV_IOCR_IFTYPE_UNSUPPORTED ((TLR_RESULT)0xC00B0095L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_SCSYNC_UNSUPPORTED
//
// MessageText:
//
//  The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an unsupported value for SendClock.
//
#define TLR_E_PNIO_CMDEV_IOCR_SCSYNC_UNSUPPORTED ((TLR_RESULT)0xC00B0096L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_ADDRESS_UNSUPPORTED
//
// MessageText:
//
//  The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an unsupported Address-Resolution.
//
#define TLR_E_PNIO_CMDEV_IOCR_ADDRESS_UNSUPPORTED ((TLR_RESULT)0xC00B0097L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_REDUNDANCY_UNSUPPORTED
//
// MessageText:
//
//  The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() has an unsupported Media-Redundancy.
//
#define TLR_E_PNIO_CMDEV_IOCR_REDUNDANCY_UNSUPPORTED ((TLR_RESULT)0xC00B0098L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_REFERENCE
//
// MessageText:
//
//  No IOCR could be found or created.
//
#define TLR_E_PNIO_CMDEV_IOCR_REFERENCE  ((TLR_RESULT)0xC00B0099L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_OBJECT_IOD
//
// MessageText:
//
//  The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() does not contain any IO-Data.
//
#define TLR_E_PNIO_CMDEV_IOCR_OBJECT_IOD ((TLR_RESULT)0xC00B009AL)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_OBJECT_IOS
//
// MessageText:
//
//  The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() does not contain any IO-Status.
//
#define TLR_E_PNIO_CMDEV_IOCR_OBJECT_IOS ((TLR_RESULT)0xC00B009BL)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_API
//
// MessageText:
//
//  The expected configuration block for IOCR in CMDEV_RMConnect_req_LoadIocr() does not contain any API.
//
#define TLR_E_PNIO_CMDEV_IOCR_API        ((TLR_RESULT)0xC00B009CL)

// CMDEV parameter faults
//
// MessageId: TLR_E_PNIO_CMDEV_FRAME_ID_COUNT_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_FRAME_ID_COUNT_INVALID ((TLR_RESULT)0xC00B0100L)

//
// MessageId: TLR_E_PNIO_CMDEV_FRAME_ID_OUT_OF_RANGE
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_FRAME_ID_OUT_OF_RANGE ((TLR_RESULT)0xC00B0101L)

//
// MessageId: TLR_E_PNIO_CMDEV_RT_CLASS_NOT_SUPPORTED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_RT_CLASS_NOT_SUPPORTED ((TLR_RESULT)0xC00B0102L)

//
// MessageId: TLR_E_PNIO_CMDEV_INSERT_AR_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_INSERT_AR_ERROR ((TLR_RESULT)0xC00B0103L)

//
// MessageId: TLR_E_PNIO_CMDEV_MAX_AR_LIMIT_EXCEEDED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_MAX_AR_LIMIT_EXCEEDED ((TLR_RESULT)0xC00B0104L)

//
// MessageId: TLR_E_PNIO_CMDEV_AR_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_AR_INVALID      ((TLR_RESULT)0xC00B0105L)

//
// MessageId: TLR_E_PNIO_CMDEV_IOCR_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_IOCR_INVALID    ((TLR_RESULT)0xC00B0106L)

//
// MessageId: TLR_E_PNIO_CMDEV_TYPE_LEN_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_TYPE_LEN_INVALID ((TLR_RESULT)0xC00B0107L)

//
// MessageId: TLR_E_PNIO_CMDEV_INVALID_CTRL_REQUEST_BLOCK
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_INVALID_CTRL_REQUEST_BLOCK ((TLR_RESULT)0xC00B0108L)

//
// MessageId: TLR_E_PNIO_CMDEV_MODULECONFIG_PACKET_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_CMDEV_MODULECONFIG_PACKET_INVALID ((TLR_RESULT)0xC00B0109L)

/////////////////////////////////////////////////////////////////////////////////////
// EDD Task
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNIO_EDD_PROCESS_END
//
// MessageText:
//
//  Return value of EDD_Scheduler_PreProcess().
//
#define TLR_E_PNIO_EDD_PROCESS_END       ((TLR_RESULT)0xC00E0001L)

//
// MessageId: TLR_E_PNIO_EDD_PARAM_INVALID_EDD
//
// MessageText:
//
//  Invalid parameter for EDD_Scheduler_Start_req().
//
#define TLR_E_PNIO_EDD_PARAM_INVALID_EDD ((TLR_RESULT)0xC00E0002L)

/////////////////////////////////////////////////////////////////////////////////////
// ACP Task
/////////////////////////////////////////////////////////////////////////////////////
// ACP
//
// MessageId: TLR_E_PNIO_ACP_PHASE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to initialize ACP-phase.
//
#define TLR_E_PNIO_ACP_PHASE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110010L)

//
// MessageId: TLR_E_PNIO_ACP_PHASE_REDUCTION_RATIO
//
// MessageText:
//
//  Invalid reduction-ratio (uiMaxRatio) in ACP_PhaseInit().
//
#define TLR_E_PNIO_ACP_PHASE_REDUCTION_RATIO ((TLR_RESULT)0xC0110011L)

//
// MessageId: TLR_E_PNIO_ACP_PHASE_SEND_CLOCK_FACTOR
//
// MessageText:
//
//  Invalid sendClock-factor (uiScFact) in ACP_PhaseInit().
//
#define TLR_E_PNIO_ACP_PHASE_SEND_CLOCK_FACTOR ((TLR_RESULT)0xC0110012L)

//
// MessageId: TLR_E_PNIO_ACP_PHASE_FRAME_RESOURCES
//
// MessageText:
//
//  Invalid parameter (uiMaxFrame) in ACP_PhaseInit().
//
#define TLR_E_PNIO_ACP_PHASE_FRAME_RESOURCES ((TLR_RESULT)0xC0110013L)

//
// MessageId: TLR_E_PNIO_ACP_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error sending a packet to another task in ACP task.
//
#define TLR_E_PNIO_ACP_PACKET_SEND_FAILED ((TLR_RESULT)0xC0110014L)

//
// MessageId: TLR_E_PNIO_ACP_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory in ACP task.
//
#define TLR_E_PNIO_ACP_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110015L)

//
// MessageId: TLR_E_PNIO_ACP_DRV_EDD_IOCTL_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_ACP_DRV_EDD_IOCTL_ERROR ((TLR_RESULT)0xC0110016L)

//
// MessageId: TLR_E_PNIO_SYNC_LOAD_IRT_DATA_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_SYNC_LOAD_IRT_DATA_ERROR ((TLR_RESULT)0xC0110017L)

//
// MessageId: TLR_E_PNIO_ACP_EMPTY_POOL_DETECTED
//
// MessageText:
//
//  The packet pool of ACP is empty.
//
#define TLR_E_PNIO_ACP_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC0110018L)

// ALARM
//
// MessageId: TLR_E_PNIO_ALARM_PARAM_INVALID_INIT
//
// MessageText:
//
//  Invalid parameter "uiMaxAlpm" in Alarm_ResourceInit().
//
#define TLR_E_PNIO_ALARM_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110020L)

//
// MessageId: TLR_E_PNIO_ALARM_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory in Alarm_ResourceInit().
//
#define TLR_E_PNIO_ALARM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110021L)

// ALPMR
//
// MessageId: TLR_E_PNIO_ALPMR_PRIORITY_INVALID
//
// MessageText:
//
//  Invalid alarm priority in request packet of ALPMR_AlarmAck_req().
//
#define TLR_E_PNIO_ALPMR_PRIORITY_INVALID ((TLR_RESULT)0xC0110030L)

//
// MessageId: TLR_E_PNIO_ALPMR_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The requested number of ALPMR protocol machines exceedes the highest possible number in ALPMR_Init_req().
//
#define TLR_E_PNIO_ALPMR_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110031L)

//
// MessageId: TLR_E_PNIO_ALPMR_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory in ALPMR_Init_req().
//
#define TLR_E_PNIO_ALPMR_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110032L)

//
// MessageId: TLR_E_PNIO_ALPMR_HANDLE_INVALID
//
// MessageText:
//
//  The ALPMR protocol-machine corresponding to the index in request packet is invalid.
//
#define TLR_E_PNIO_ALPMR_HANDLE_INVALID  ((TLR_RESULT)0xC0110033L)

//
// MessageId: TLR_E_PNIO_ALPMR_STATE_INVALID
//
// MessageText:
//
//  The ALPMR protocol-machine state is invalid for the current request.
//
#define TLR_E_PNIO_ALPMR_STATE_INVALID   ((TLR_RESULT)0xC0110034L)

//
// MessageId: TLR_E_PNIO_ALPMR_PACKET_SEND_FAILED
//
// MessageText:
//
//  Sending an Alarm-Indication-packet to another task failed in ALPMR.
//
#define TLR_E_PNIO_ALPMR_PACKET_SEND_FAILED ((TLR_RESULT)0xC0110035L)

//
// MessageId: TLR_E_PNIO_ALPMR_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Creating an Alarm-Indication-packet to be send to another task failed due to insufficient memory.
//
#define TLR_E_PNIO_ALPMR_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0110036L)

//
// MessageId: TLR_E_PNIO_ALPMR_RESOURCE_INDEX_INVALID
//
// MessageText:
//
//  The index of ALPMR's protocol machine is invalid.
//
#define TLR_E_PNIO_ALPMR_RESOURCE_INDEX_INVALID ((TLR_RESULT)0xC0110037L)

// APMR
//
// MessageId: TLR_E_PNIO_APMR_PARAM_INVALID_INIT
//
// MessageText:
//
//  The parameter uiMaxApmr (maximum number of parallel APMR protocol-machines) in APMR_ResourceInit() is invalid.
//
#define TLR_E_PNIO_APMR_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110040L)

//
// MessageId: TLR_E_PNIO_APMR_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory in APMR_ResourceInit() to create the APMR protocol machines.
//
#define TLR_E_PNIO_APMR_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110041L)

//
// MessageId: TLR_E_PNIO_APMR_HANDLE_INVALID
//
// MessageText:
//
//  The APMR protocol machine or its index is invalid.
//
#define TLR_E_PNIO_APMR_HANDLE_INVALID   ((TLR_RESULT)0xC0110042L)

//
// MessageId: TLR_E_PNIO_APMR_STATE_INVALID
//
// MessageText:
//
//  The state of APMR protocol machine is invalid for current request.
//
#define TLR_E_PNIO_APMR_STATE_INVALID    ((TLR_RESULT)0xC0110043L)

//
// MessageId: TLR_E_PNIO_APMR_FRAME_SEND_FAILED
//
// MessageText:
//
//  Sending an ACK or NAK in response to a received Alarm-PDU failed.
//
#define TLR_E_PNIO_APMR_FRAME_SEND_FAILED ((TLR_RESULT)0xC0110044L)

// APMS
//
// MessageId: TLR_E_PNIO_APMS_PARAM_INVALID_INIT
//
// MessageText:
//
//  The parameter uiMaxApms (maximum number of parallel APMS protocol-machines) in APMS_ResourceInit() is invalid.
//
#define TLR_E_PNIO_APMS_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110050L)

//
// MessageId: TLR_E_PNIO_APMS_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory in APMS_ResourceInit() to create the APMS protocol machines.
//
#define TLR_E_PNIO_APMS_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110051L)

//
// MessageId: TLR_E_PNIO_APMS_HANDLE_INVALID
//
// MessageText:
//
//  The APMS protocol machine or its index is invalid.
//
#define TLR_E_PNIO_APMS_HANDLE_INVALID   ((TLR_RESULT)0xC0110052L)

//
// MessageId: TLR_E_PNIO_APMS_STATE_INVALID
//
// MessageText:
//
//  The state of APMS protocol machine is invalid for current request.
//
#define TLR_E_PNIO_APMS_STATE_INVALID    ((TLR_RESULT)0xC0110053L)

//
// MessageId: TLR_E_PNIO_APMS_FRAME_OUT_OF_MEMORY
//
// MessageText:
//
//  APMS was not able to get an Edd_FrameBuffer for sending a packet.
//
#define TLR_E_PNIO_APMS_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC0110054L)

//
// MessageId: TLR_E_PNIO_APMS_FRAME_SEND_FAILED
//
// MessageText:
//
//  An error occurred while APMS was trying to send an Edd_Frame.
//
#define TLR_E_PNIO_APMS_FRAME_SEND_FAILED ((TLR_RESULT)0xC0110055L)

//
// MessageId: TLR_E_PNIO_APMS_TIMER_CREATE_FAILED
//
// MessageText:
//
//  APMS_Activate_req() was not able to create a TLR-Timer.
//
#define TLR_E_PNIO_APMS_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0110056L)

//
// MessageId: TLR_E_PNIO_APMS_TIMER_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for APMS_Send_req_Data() to allocate a timer-indication packet.
//
#define TLR_E_PNIO_APMS_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0110057L)

//
// MessageId: TLR_E_PNIO_APMS_INDEX_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_APMS_INDEX_INVALID    ((TLR_RESULT)0xC0110058L)

// CPM
//
// MessageId: TLR_E_PNIO_CPM_PARAM_INVALID_INIT
//
// MessageText:
//
//  The parameter uiMaxCpmRtc1 and/or uiMaxCpmRtc2 of CPM_ResourceInit() is invalid.
//
#define TLR_E_PNIO_CPM_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110060L)

//
// MessageId: TLR_E_PNIO_CPM_PARAM_INVALID_CLASS
//
// MessageText:
//
//  The requested RTC-class is invalid in CPM_Init_req().
//
#define TLR_E_PNIO_CPM_PARAM_INVALID_CLASS ((TLR_RESULT)0xC0110061L)

//
// MessageId: TLR_E_PNIO_CPM_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The requested amount of CPM protocol machines is higher than the highest possible value.
//
#define TLR_E_PNIO_CPM_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110062L)

//
// MessageId: TLR_E_PNIO_CPM_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for current request in CPM.
//
#define TLR_E_PNIO_CPM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110063L)

//
// MessageId: TLR_E_PNIO_CPM_HANDLE_INVALID
//
// MessageText:
//
//  The handle to CPM protocol machine in invalid.
//
#define TLR_E_PNIO_CPM_HANDLE_INVALID    ((TLR_RESULT)0xC0110064L)

//
// MessageId: TLR_E_PNIO_CPM_STATE_INVALID
//
// MessageText:
//
//  The state of CPM protocol machine is incorrect for current request.
//
#define TLR_E_PNIO_CPM_STATE_INVALID     ((TLR_RESULT)0xC0110065L)

//
// MessageId: TLR_E_PNIO_CPM_PHASE_LIMIT_EXCEEDED
//
// MessageText:
//
//  Invalid phase found in Init-request-packet in CPM_Init_req() or in ACP_PhaseCpmAdd_req() or ACP_PhaseCpmRemove_req().
//
#define TLR_E_PNIO_CPM_PHASE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110066L)

//
// MessageId: TLR_E_PNIO_CPM_SEND_CLOCK_LIMIT_EXCEEDED
//
// MessageText:
//
//  The SendClock-factor in Init-request-packet to CPM does not match the one in ACP_Tasks' resources.
//
#define TLR_E_PNIO_CPM_SEND_CLOCK_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110067L)

//
// MessageId: TLR_E_PNIO_CPM_DATALEN_LIMIT_EXCEEDED
//
// MessageText:
//
//  Packet size to receive is to big. Error is detected in CPM_Init_req().
//
#define TLR_E_PNIO_CPM_DATALEN_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110069L)

//
// MessageId: TLR_E_PNIO_CPM_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in CPM.
//
#define TLR_E_PNIO_CPM_PACKET_SEND_FAILED ((TLR_RESULT)0xC011006AL)

// PPM
//
// MessageId: TLR_E_PNIO_PPM_PARAM_INVALID_INIT
//
// MessageText:
//
//  The parameter "uiMaxPPMRtc1" and/or "uiMaxPPMRtc2" of PPM_ResourceInit() is invalid.
//
#define TLR_E_PNIO_PPM_PARAM_INVALID_INIT ((TLR_RESULT)0xC0110080L)

//
// MessageId: TLR_E_PNIO_PPM_PARAM_INVALID_CLASS
//
// MessageText:
//
//  The requested RTC-class is invalid in PPM_Init_req().
//
#define TLR_E_PNIO_PPM_PARAM_INVALID_CLASS ((TLR_RESULT)0xC0110081L)

//
// MessageId: TLR_E_PNIO_PPM_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The requested amount of PPM protocol machines is higher than the highest possible value.
//
#define TLR_E_PNIO_PPM_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110082L)

//
// MessageId: TLR_E_PNIO_PPM_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for current request in PPM.
//
#define TLR_E_PNIO_PPM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110083L)

//
// MessageId: TLR_E_PNIO_PPM_HANDLE_INVALID
//
// MessageText:
//
//  The handle to PPM protocol machine in invalid.
//
#define TLR_E_PNIO_PPM_HANDLE_INVALID    ((TLR_RESULT)0xC0110084L)

//
// MessageId: TLR_E_PNIO_PPM_STATE_INVALID
//
// MessageText:
//
//  The state of PPM protocol machine is incorrect for current request.
//
#define TLR_E_PNIO_PPM_STATE_INVALID     ((TLR_RESULT)0xC0110085L)

//
// MessageId: TLR_E_PNIO_PPM_PHASE_LIMIT_EXCEEDED
//
// MessageText:
//
//  Invalid phase found in Init-request-packet in PPM_Init_req() or in ACP_PhasePPMAdd_req() or ACP_PhasePPMRemove_req().
//
#define TLR_E_PNIO_PPM_PHASE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110086L)

//
// MessageId: TLR_E_PNIO_PPM_SEND_CLOCK_LIMIT_EXCEEDED
//
// MessageText:
//
//  The SendClock-factor in PPMs Init-request-packet does not match the one in ACP_Tasks' resources.
//
#define TLR_E_PNIO_PPM_SEND_CLOCK_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110087L)

//
// MessageId: TLR_E_PNIO_PPM_DATALEN_LIMIT_EXCEEDED
//
// MessageText:
//
//  Packet size to send is to big. Error is detected in PPM_Init_req().
//
#define TLR_E_PNIO_PPM_DATALEN_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110089L)

//
// MessageId: TLR_E_PNIO_PPM_RESOURCE_CLASS_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_PPM_RESOURCE_CLASS_INVALID ((TLR_RESULT)0xC011008AL)

// ALPMI
//
// MessageId: TLR_E_PNIO_ALPMI_PRIORITY_INVALID
//
// MessageText:
//
//  Invalid alarm priority in request packet of ALPMI_AlarmAck_req().
//
#define TLR_E_PNIO_ALPMI_PRIORITY_INVALID ((TLR_RESULT)0xC0110090L)

//
// MessageId: TLR_E_PNIO_ALPMI_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The requested number of ALPMI protocol machines exceedes the highest possible number in ALPMI_Init_req().
//
#define TLR_E_PNIO_ALPMI_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0110091L)

//
// MessageId: TLR_E_PNIO_ALPMI_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory in ALPMI_Init_req().
//
#define TLR_E_PNIO_ALPMI_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0110092L)

//
// MessageId: TLR_E_PNIO_ALPMI_HANDLE_INVALID
//
// MessageText:
//
//  The ALPMI protocol-machine corresponding to the index in request packet is invalid.
//
#define TLR_E_PNIO_ALPMI_HANDLE_INVALID  ((TLR_RESULT)0xC0110093L)

//
// MessageId: TLR_E_PNIO_ALPMI_STATE_INVALID
//
// MessageText:
//
//  The ALPMI protocol-machine state is invalid for the current request.
//
#define TLR_E_PNIO_ALPMI_STATE_INVALID   ((TLR_RESULT)0xC0110094L)

//
// MessageId: TLR_E_PNIO_ALPMI_PACKET_SEND_FAILED
//
// MessageText:
//
//  Sending an Alarm-Indication-packet to another task failed in ALPMI.
//
#define TLR_E_PNIO_ALPMI_PACKET_SEND_FAILED ((TLR_RESULT)0xC0110095L)

//
// MessageId: TLR_E_PNIO_ALPMI_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Creating an Alarm-Indication-packet to be send to another task failed due to insufficient memory.
//
#define TLR_E_PNIO_ALPMI_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0110096L)

//
// MessageId: TLR_E_PNIO_ALPMI_RESOURCE_INDEX_INVALID
//
// MessageText:
//
//  The index of ALPIR's protocol machine is invalid.
//
#define TLR_E_PNIO_ALPMI_RESOURCE_INDEX_INVALID ((TLR_RESULT)0xC0110097L)

/////////////////////////////////////////////////////////////////////////////////////
// DCP Task
/////////////////////////////////////////////////////////////////////////////////////
// DCP
//
// MessageId: TLR_E_PNIO_DCP_PARAM_INVALID_EDD
//
// MessageText:
//
//  Invalid parameter in Start-Edd-packet for DCP_StartEDD_req().
//
#define TLR_E_PNIO_DCP_PARAM_INVALID_EDD ((TLR_RESULT)0xC012000AL)

// DCPMCR
//
// MessageId: TLR_E_PNIO_DCPMCR_INIT_PARAM_INVALID
//
// MessageText:
//
//  Invalid parameter (uiMaxMcr) in DCPMCR_ResourceInit().
//
#define TLR_E_PNIO_DCPMCR_INIT_PARAM_INVALID ((TLR_RESULT)0xC0120010L)

//
// MessageId: TLR_E_PNIO_DCPMCR_INIT_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to initialize DCPMCR protocol machines in DCPMCR_ResourceInit().
//
#define TLR_E_PNIO_DCPMCR_INIT_OUT_OF_MEMORY ((TLR_RESULT)0xC0120011L)

//
// MessageId: TLR_E_PNIO_DCPMCR_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The index of DCPMCR's protocol machine is invalid.
//
#define TLR_E_PNIO_DCPMCR_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0120012L)

//
// MessageId: TLR_E_PNIO_DCPMCR_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for request in DCPMCR_Activate_req().
//
#define TLR_E_PNIO_DCPMCR_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0120013L)

//
// MessageId: TLR_E_PNIO_DCPMCR_RESOURCE_STATE_INVALID
//
// MessageText:
//
//  The state of DCPMCR protocol machine is incorrect for current request.
//
#define TLR_E_PNIO_DCPMCR_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120014L)

//
// MessageId: TLR_E_PNIO_DCPMCR_RESOURCE_HANDLE_INVALID
//
// MessageText:
//
//  The handle to DCPMCR protocol machine in invalid.
//
#define TLR_E_PNIO_DCPMCR_RESOURCE_HANDLE_INVALID ((TLR_RESULT)0xC0120015L)

//
// MessageId: TLR_E_PNIO_DCPMCR_TIMER_CREATE_FAILED
//
// MessageText:
//
//  DCPMCR_Activate_req() was unable to create a TLR-timer.
//
#define TLR_E_PNIO_DCPMCR_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0120016L)

//
// MessageId: TLR_E_PNIO_DCPMCR_TIMER_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for DCPMCR_Identify_ind() to allocate a timer-indication packet.
//
#define TLR_E_PNIO_DCPMCR_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0120017L)

//
// MessageId: TLR_E_PNIO_DCPMCR_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to allocate a packet to be send to another task in DCPMCR.
//
#define TLR_E_PNIO_DCPMCR_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0120018L)

//
// MessageId: TLR_E_PNIO_DCPMCR_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in DCPMCR.
//
#define TLR_E_PNIO_DCPMCR_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120019L)

//
// MessageId: TLR_E_PNIO_DCPMCR_FRAME_OUT_OF_MEMORY
//
// MessageText:
//
//  DCPMCR was not able to get an Edd_FrameBuffer for sending a packet.
//
#define TLR_E_PNIO_DCPMCR_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC012001AL)

//
// MessageId: TLR_E_PNIO_DCPMCR_FRAME_SEND_FAILED
//
// MessageText:
//
//  An error occurred while DCPMCR was trying to send an Edd_Frame.
//
#define TLR_E_PNIO_DCPMCR_FRAME_SEND_FAILED ((TLR_RESULT)0xC012001BL)

//
// MessageId: TLR_E_PNIO_DCPMCR_WAIT_ACK
//
// MessageText:
//
//  DCPMCR could not be closed because it is still waiting for an ACK.
//
#define TLR_E_PNIO_DCPMCR_WAIT_ACK       ((TLR_RESULT)0xC012001CL)

//
// MessageId: TLR_E_PNIO_DCPMCR_TASK_RES_ADDRESS
//
// MessageText:
//
//  DCPMCR: Invalid parameter (task resources block address) while handling DCP Identify indication.
//
#define TLR_E_PNIO_DCPMCR_TASK_RES_ADDRESS ((TLR_RESULT)0xC012001DL)

//
// MessageId: TLR_E_PNIO_DCPMCR_EDD_FRAME_ADDRESS
//
// MessageText:
//
//  DCPMCR: Invalid parameter (EDD frame address) while handling DCP Identify indication.
//
#define TLR_E_PNIO_DCPMCR_EDD_FRAME_ADDRESS ((TLR_RESULT)0xC012001EL)

//
// MessageId: TLR_E_PNIO_DCPMCR_MCR_ADDRESS
//
// MessageText:
//
//  DCPMCR: Invalid parameter (DCPMCR state machine address) while handling DCP Identify indication.
//
#define TLR_E_PNIO_DCPMCR_MCR_ADDRESS    ((TLR_RESULT)0xC012001FL)

//
// MessageId: TLR_E_PNIO_DCPMCR_RMPM_ADDRESS
//
// MessageText:
//
//  DCPMCR: Invalid parameter (RMPM state machine address) while handling DCP Identify indication.
//
#define TLR_E_PNIO_DCPMCR_RMPM_ADDRESS   ((TLR_RESULT)0xC0120020L)

//
// MessageId: TLR_E_PNIO_DCP_EMPTY_POOL_DETECTED
//
// MessageText:
//
//  The packet pool of DCP is empty.
//
#define TLR_E_PNIO_DCP_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC0120021L)

// DCPMCS
//
// MessageId: TLR_E_PNIO_DCPMCS_INIT_PARAM_INVALID
//
// MessageText:
//
//  Invalid parameter (uiMaxMcs) in DCPMCS_ResourceInit().
//
#define TLR_E_PNIO_DCPMCS_INIT_PARAM_INVALID ((TLR_RESULT)0xC0120100L)

//
// MessageId: TLR_E_PNIO_DCPMCS_INIT_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to initialize DCPMCS protocol machines in DCPMCS_ResourceInit().
//
#define TLR_E_PNIO_DCPMCS_INIT_OUT_OF_MEMORY ((TLR_RESULT)0xC0120101L)

//
// MessageId: TLR_E_PNIO_DCPMCS_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  There are too many outstanding DCPMCS requests. New requests will not be accepted.
//
#define TLR_E_PNIO_DCPMCS_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0120102L)

//
// MessageId: TLR_E_PNIO_DCPMCS_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for request in DCPMCS_Activate_req().
//
#define TLR_E_PNIO_DCPMCS_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0120103L)

//
// MessageId: TLR_E_PNIO_DCPMCS_RESOURCE_STATE_INVALID
//
// MessageText:
//
//  The state of DCPMCS protocol machine is incorrect for current request.
//
#define TLR_E_PNIO_DCPMCS_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120104L)

//
// MessageId: TLR_E_PNIO_DCPMCS_RESOURCE_HANDLE_INVALID
//
// MessageText:
//
//  The handle to DCPMCS protocol machine in invalid.
//
#define TLR_E_PNIO_DCPMCS_RESOURCE_HANDLE_INVALID ((TLR_RESULT)0xC0120105L)

//
// MessageId: TLR_E_PNIO_DCPMCS_TIMER_CREATE_FAILED
//
// MessageText:
//
//  DCPMCS_Activate_req() was unable to create a TLR-timer.
//
#define TLR_E_PNIO_DCPMCS_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0120106L)

//
// MessageId: TLR_E_PNIO_DCPMCS_TIMER_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for DCPMCS_Identify_req() to allocate a timer-indication packet.
//
#define TLR_E_PNIO_DCPMCS_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0120107L)

//
// MessageId: TLR_E_PNIO_DCPMCS_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to allocate a packet to be send to another task in DCPMCS.
//
#define TLR_E_PNIO_DCPMCS_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0120108L)

//
// MessageId: TLR_E_PNIO_DCPMCS_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in DCPMCS.
//
#define TLR_E_PNIO_DCPMCS_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120109L)

//
// MessageId: TLR_E_PNIO_DCPMCS_FRAME_OUT_OF_MEMORY
//
// MessageText:
//
//  DCPMCS was not able to get an Edd_FrameBuffer for sending a packet.
//
#define TLR_E_PNIO_DCPMCS_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC012010AL)

//
// MessageId: TLR_E_PNIO_DCPMCS_FRAME_SEND_FAILED
//
// MessageText:
//
//  An error occurred while DCPMCS was trying to send an Edd_Frame.
//
#define TLR_E_PNIO_DCPMCS_FRAME_SEND_FAILED ((TLR_RESULT)0xC012010BL)

// DCPHMCS
//
// MessageId: TLR_E_PNIO_DCPHMCS_RESOURCE_STATE_INVALID
//
// MessageText:
//
//  The state of DCPHMCS protocol machine is incorrect for current request.
//
#define TLR_E_PNIO_DCPHMCS_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120150L)

//
// MessageId: TLR_E_PNIO_DCPHMCS_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in DCPHMCS.
//
#define TLR_E_PNIO_DCPHMCS_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120151L)

//
// MessageId: TLR_E_PNIO_DCPHMCS_FRAME_OUT_OF_MEMORY
//
// MessageText:
//
//  DCPHMCS was not able to get an Edd_FrameBuffer for sending a packet.
//
#define TLR_E_PNIO_DCPHMCS_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC0120152L)

//
// MessageId: TLR_E_PNIO_DCPHMCS_FRAME_SEND_FAILED
//
// MessageText:
//
//  An error occurred while DCPHMCS was trying to send an Edd_Frame.
//
#define TLR_E_PNIO_DCPHMCS_FRAME_SEND_FAILED ((TLR_RESULT)0xC0120153L)

// DCPUCR 
//
// MessageId: TLR_E_PNIO_DCPUCR_INIT_PARAM_INVALID
//
// MessageText:
//
//  Invalid parameter (uiMaxUcr) in DCPUCR_ResourceInit().
//
#define TLR_E_PNIO_DCPUCR_INIT_PARAM_INVALID ((TLR_RESULT)0xC0120200L)

//
// MessageId: TLR_E_PNIO_DCPUCR_INIT_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to initialize DCPUCR protocol machines in DCPUCR_ResourceInit().
//
#define TLR_E_PNIO_DCPUCR_INIT_OUT_OF_MEMORY ((TLR_RESULT)0xC0120201L)

//
// MessageId: TLR_E_PNIO_DCPUCR_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The index of DCPUCR's protocol machine is invalid.
//
#define TLR_E_PNIO_DCPUCR_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0120202L)

//
// MessageId: TLR_E_PNIO_DCPUCR_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for request in DCPUCR_Activate_req().
//
#define TLR_E_PNIO_DCPUCR_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0120203L)

//
// MessageId: TLR_E_PNIO_DCPUCR_RESOURCE_STATE_INVALID
//
// MessageText:
//
//  The state of DCPUCR protocol machine is incorrect for current request.
//
#define TLR_E_PNIO_DCPUCR_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120204L)

//
// MessageId: TLR_E_PNIO_DCPUCR_RESOURCE_HANDLE_INVALID
//
// MessageText:
//
//  The handle to DCPUCR protocol machine in invalid.
//
#define TLR_E_PNIO_DCPUCR_RESOURCE_HANDLE_INVALID ((TLR_RESULT)0xC0120205L)

//
// MessageId: TLR_E_PNIO_DCPUCR_TIMER_CREATE_FAILED
//
// MessageText:
//
//  DCPUCR_Activate_req() was unable to create a TLR-timer.
//
#define TLR_E_PNIO_DCPUCR_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0120206L)

//
// MessageId: TLR_E_PNIO_DCPUCR_TIMER_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to allocate a timer-indication packet.
//
#define TLR_E_PNIO_DCPUCR_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0120207L)

//
// MessageId: TLR_E_PNIO_DCPUCR_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to allocate a packet to be send to another task in DCPUCR.
//
#define TLR_E_PNIO_DCPUCR_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0120208L)

//
// MessageId: TLR_E_PNIO_DCPUCR_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in DCPUCR.
//
#define TLR_E_PNIO_DCPUCR_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120209L)

//
// MessageId: TLR_E_PNIO_DCPUCR_FRAME_OUT_OF_MEMORY
//
// MessageText:
//
//  DCPUCR was not able to get an Edd_FrameBuffer for sending a packet.
//
#define TLR_E_PNIO_DCPUCR_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC012020AL)

//
// MessageId: TLR_E_PNIO_DCPUCR_FRAME_SEND_FAILED
//
// MessageText:
//
//  An error occurred while DCPUCR was trying to send an Edd_Frame.
//
#define TLR_E_PNIO_DCPUCR_FRAME_SEND_FAILED ((TLR_RESULT)0xC012020BL)

//
// MessageId: TLR_E_PNIO_DCPUCR_SERVICE_INVALID
//
// MessageText:
//
//  The DCP-command of received response does not match the outstanding request in DCPUCR.
//
#define TLR_E_PNIO_DCPUCR_SERVICE_INVALID ((TLR_RESULT)0xC012020CL)

//
// MessageId: TLR_E_PNIO_DCPUCR_WAIT_ACK
//
// MessageText:
//
//  DCPUCR could not be closed because it is still waiting for an ACK.
//
#define TLR_E_PNIO_DCPUCR_WAIT_ACK       ((TLR_RESULT)0xC012020DL)

// DCPUCS
//
// MessageId: TLR_E_PNIO_DCPUCS_INIT_PARAM_INVALID
//
// MessageText:
//
//  Invalid parameter (uiMaxUcs) in DCPUCS_ResourceInit().
//
#define TLR_E_PNIO_DCPUCS_INIT_PARAM_INVALID ((TLR_RESULT)0xC0120300L)

//
// MessageId: TLR_E_PNIO_DCPUCS_INIT_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to initialize DCPUCS protocol machines in DCPUCS_ResourceInit().
//
#define TLR_E_PNIO_DCPUCS_INIT_OUT_OF_MEMORY ((TLR_RESULT)0xC0120301L)

//
// MessageId: TLR_E_PNIO_DCPUCS_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  There are too many outstanding DCPUCS requests. New requests will not be accepted.
//
#define TLR_E_PNIO_DCPUCS_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0120302L)

//
// MessageId: TLR_E_PNIO_DCPUCS_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for request in DCPUCS_Activate_req().
//
#define TLR_E_PNIO_DCPUCS_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0120303L)

//
// MessageId: TLR_E_PNIO_DCPUCS_RESOURCE_STATE_INVALID
//
// MessageText:
//
//  The state of DCPUCS protocol machine is incorrect for current request.
//
#define TLR_E_PNIO_DCPUCS_RESOURCE_STATE_INVALID ((TLR_RESULT)0xC0120304L)

//
// MessageId: TLR_E_PNIO_DCPUCS_RESOURCE_HANDLE_INVALID
//
// MessageText:
//
//  The handle to DCPUCS protocol machine in invalid.
//
#define TLR_E_PNIO_DCPUCS_RESOURCE_HANDLE_INVALID ((TLR_RESULT)0xC0120305L)

//
// MessageId: TLR_E_PNIO_DCPUCS_TIMER_CREATE_FAILED
//
// MessageText:
//
//  DCPUCS_Activate_req() was unable to create a TLR-timer.
//
#define TLR_E_PNIO_DCPUCS_TIMER_CREATE_FAILED ((TLR_RESULT)0xC0120306L)

//
// MessageId: TLR_E_PNIO_DCPUCS_TIMER_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory for DCPUCS_DataSend_req() to allocate a timer-indication packet.
//
#define TLR_E_PNIO_DCPUCS_TIMER_OUT_OF_MEMORY ((TLR_RESULT)0xC0120307L)

//
// MessageId: TLR_E_PNIO_DCPUCS_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to allocate a packet to be send to another task in DCPUCS.
//
#define TLR_E_PNIO_DCPUCS_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0120308L)

//
// MessageId: TLR_E_PNIO_DCPUCS_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in DCPUCS.
//
#define TLR_E_PNIO_DCPUCS_PACKET_SEND_FAILED ((TLR_RESULT)0xC0120309L)

//
// MessageId: TLR_E_PNIO_DCPUCS_FRAME_OUT_OF_MEMORY
//
// MessageText:
//
//  DCPUCS was not able to get an Edd_FrameBuffer for sending a packet.
//
#define TLR_E_PNIO_DCPUCS_FRAME_OUT_OF_MEMORY ((TLR_RESULT)0xC012030AL)

//
// MessageId: TLR_E_PNIO_DCPUCS_FRAME_SEND_FAILED
//
// MessageText:
//
//  An error occurred while DCPUCS was trying to send an Edd_Frame.
//
#define TLR_E_PNIO_DCPUCS_FRAME_SEND_FAILED ((TLR_RESULT)0xC012030BL)

//
// MessageId: TLR_E_PNIO_DCPUCS_FRAME_TIMEOUT
//
// MessageText:
//
//  DCPUCS did not get a response to an Edd_Frame send .
//
#define TLR_E_PNIO_DCPUCS_FRAME_TIMEOUT  ((TLR_RESULT)0xC012030CL)

//
// MessageId: TLR_E_PNIO_DCPUCS_DCP_OPTION_UNSUPPORTED
//
// MessageText:
//
//  The DCP option to set is not supported by IO-Device.
//
#define TLR_E_PNIO_DCPUCS_DCP_OPTION_UNSUPPORTED ((TLR_RESULT)0xC0120320L)

//
// MessageId: TLR_E_PNIO_DCPUCS_DCP_SUBOPTION_UNSUPPORTED
//
// MessageText:
//
//  The DCP suboption to set is not supported by IO-Device.
//
#define TLR_E_PNIO_DCPUCS_DCP_SUBOPTION_UNSUPPORTED ((TLR_RESULT)0xC0120321L)

//
// MessageId: TLR_E_PNIO_DCPUCS_DCP_SUBOPTION_NOT_SET
//
// MessageText:
//
//  The DCP suboption to set was not set inside IO-Device.
//
#define TLR_E_PNIO_DCPUCS_DCP_SUBOPTION_NOT_SET ((TLR_RESULT)0xC0120022L)

//
// MessageId: TLR_E_PNIO_DCPUCS_DCP_RESOURCE_ERROR
//
// MessageText:
//
//  An internal resource error occured in IO-Device while performing a DCP request.
//
#define TLR_E_PNIO_DCPUCS_DCP_RESOURCE_ERROR ((TLR_RESULT)0xC0120023L)

//
// MessageId: TLR_E_PNIO_DCPUCS_DCP_SET_IMPOSSIBLE_LOCAL_REASON
//
// MessageText:
//
//  The DCP (sub)option could not be set inside IO-Device for IO-Device internal reasons.
//
#define TLR_E_PNIO_DCPUCS_DCP_SET_IMPOSSIBLE_LOCAL_REASON ((TLR_RESULT)0xC0120024L)

//
// MessageId: TLR_E_PNIO_DCPUCS_DCP_SET_IMPOSSIBLE_WHILE_OPERATION
//
// MessageText:
//
//  The DCP (sub)option could not be set inside IO-Device because IO-Device is in operation.
//
#define TLR_E_PNIO_DCPUCS_DCP_SET_IMPOSSIBLE_WHILE_OPERATION ((TLR_RESULT)0xC0120025L)

/////////////////////////////////////////////////////////////////////////////////////
// MGT-Task
/////////////////////////////////////////////////////////////////////////////////////
// MGT
//
// MessageId: TLR_E_PNIO_MGT_PACKET_SEND_FAILED
//
// MessageText:
//
//  ACP_EDDStartDCP_req() was unable to send request packet to DCP-Task.
//
#define TLR_E_PNIO_MGT_PACKET_SEND_FAILED ((TLR_RESULT)0xC0130001L)

//
// MessageId: TLR_E_PNIO_MGT_WAIT_FOR_PACKET_FAILED
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_WAIT_FOR_PACKET_FAILED ((TLR_RESULT)0xC0130002L)

//
// MessageId: TLR_E_PNIO_MGT_CMDEV_HANDLE_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_CMDEV_HANDLE_INVALID ((TLR_RESULT)0xC0130003L)

//
// MessageId: TLR_E_PNIO_MGT_MAPPER_REGISTER_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_MAPPER_REGISTER_ERROR ((TLR_RESULT)0xC0130004L)

//
// MessageId: TLR_E_PNIO_MGT_SERVER_REGISTER_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_SERVER_REGISTER_ERROR ((TLR_RESULT)0xC0130005L)

//
// MessageId: TLR_E_PNIO_MGT_OBJECT_REGISTER_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_OBJECT_REGISTER_ERROR ((TLR_RESULT)0xC0130006L)

//
// MessageId: TLR_E_PNIO_MGT_CLIENT_REGISTER_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_CLIENT_REGISTER_ERROR ((TLR_RESULT)0xC0130007L)

//
// MessageId: TLR_E_PNIO_MGT_OPCODE_UNKNOWN
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_OPCODE_UNKNOWN    ((TLR_RESULT)0xC0130008L)

//
// MessageId: TLR_E_PNIO_MGT_RPCCLIENT_HANDLE_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_RPCCLIENT_HANDLE_INVALID ((TLR_RESULT)0xC0130009L)

//
// MessageId: TLR_E_PNIO_MGT_OBJECT_UUID_NOT_FOUND
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_OBJECT_UUID_NOT_FOUND ((TLR_RESULT)0xC013000AL)

//
// MessageId: TLR_E_PNIO_MGT_ARUUID_NOT_FOUND
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_ARUUID_NOT_FOUND  ((TLR_RESULT)0xC013000BL)

//
// MessageId: TLR_E_PNIO_MGT_INVALID_PORT_NUMBER
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_INVALID_PORT_NUMBER ((TLR_RESULT)0xC013000CL)

//
// MessageId: TLR_E_PNIO_MGT_DRV_EDD_IOCTL_ERROR
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_DRV_EDD_IOCTL_ERROR ((TLR_RESULT)0xC013000DL)

//
// MessageId: TLR_E_PNIO_MGT_INVALID_SESSION_KEY
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_INVALID_SESSION_KEY ((TLR_RESULT)0xC013000EL)

//
// MessageId: TLR_E_PNIO_MGT_TARGET_UUID_NOT_NIL
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_MGT_TARGET_UUID_NOT_NIL ((TLR_RESULT)0xC013000FL)

// NRPM
//
// MessageId: TLR_E_PNIO_NRPM_PARAM_INVALID_INIT
//
// MessageText:
//
//  Invalid parameter (uiMaxNrpm) in NRPM_ResourceInit().
//
#define TLR_E_PNIO_NRPM_PARAM_INVALID_INIT ((TLR_RESULT)0xC0130010L)

//
// MessageId: TLR_E_PNIO_NRPM_HANDLE_INVALID
//
// MessageText:
//
//  The handle to NRPM protocol machine in invalid.
//
#define TLR_E_PNIO_NRPM_HANDLE_INVALID   ((TLR_RESULT)0xC0130011L)

//
// MessageId: TLR_E_PNIO_NRPM_STATE_INVALID
//
// MessageText:
//
//  The state of NRPM protocol machine is invalid.
//
#define TLR_E_PNIO_NRPM_STATE_INVALID    ((TLR_RESULT)0xC0130012L)

//
// MessageId: TLR_E_PNIO_NRPM_IDENTIFY_FLAG_INVALID
//
// MessageText:
//
//  The identify-flag in NRPM_Init_req() is invalid.
//
#define TLR_E_PNIO_NRPM_IDENTIFY_FLAG_INVALID ((TLR_RESULT)0xC0130013L)

//
// MessageId: TLR_E_PNIO_NRPM_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The requested number of NRPM protocol machines exceedes the highest possible number in NRPM_Init_req().
//
#define TLR_E_PNIO_NRPM_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0130014L)

//
// MessageId: TLR_E_PNIO_NRPM_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory in NRPM_Init_req().
//
#define TLR_E_PNIO_NRPM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0130015L)

//
// MessageId: TLR_E_PNIO_NRPM_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in NRPM.
//
#define TLR_E_PNIO_NRPM_PACKET_SEND_FAILED ((TLR_RESULT)0xC0130016L)

//
// MessageId: TLR_E_PNIO_NRPM_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to allocate a packet in NRPM.
//
#define TLR_E_PNIO_NRPM_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0130017L)

//
// MessageId: TLR_E_PNIO_NRPM_DCP_TYPE_INVALID
//
// MessageText:
//
//  Received request with invalid type of DCP request in NRPM.
//
#define TLR_E_PNIO_NRPM_DCP_TYPE_INVALID ((TLR_RESULT)0xC0130018L)

//
// MessageId: TLR_E_PNIO_NRPM_NAME_OF_STATION_INVALID
//
// MessageText:
//
//  The requested NameOfStation is invalid. Either it has an invalid length or it contains invalid characters.
//
#define TLR_E_PNIO_NRPM_NAME_OF_STATION_INVALID ((TLR_RESULT)0xC0130019L)

//
// MessageId: TLR_E_PNIO_NRPM_DCP_SET_ERROR
//
// MessageText:
//
//  The requested DCP Set operation failed.
//
#define TLR_E_PNIO_NRPM_DCP_SET_ERROR    ((TLR_RESULT)0xC013001AL)

//
// MessageId: TLR_E_PNIO_NRPM_DEVICE_IP_ADDRESS_ALREADY_IN_USE
//
// MessageText:
//
//  The IP-address the controller shall set for the IO-Device is already in use by another network device.
//
#define TLR_E_PNIO_NRPM_DEVICE_IP_ADDRESS_ALREADY_IN_USE ((TLR_RESULT)0xC013001BL)

//
// MessageId: TLR_E_PNIO_NRPM_LATE_ERROR_INCONSISTENT_IP_PARAMETERS
//
// MessageText:
//
//  The ip parameters of HelloReq and IdentifyRsp are inconsistent.
//
#define TLR_E_PNIO_NRPM_LATE_ERROR_INCONSISTENT_IP_PARAMETERS ((TLR_RESULT)0xC013001CL)

//
// MessageId: TLR_E_PNIO_NRPM_LATE_ERROR_IP_LOOKUP_MAC_CONFLICT
//
// MessageText:
//
//  While checking the IP an invalid MAC address was found.
//
#define TLR_E_PNIO_NRPM_LATE_ERROR_IP_LOOKUP_MAC_CONFLICT ((TLR_RESULT)0xC013001DL)

//
// MessageId: TLR_E_PNIO_NRPM_LATE_ERROR_IP_LOOKUP_STATION_NOT_FOUND
//
// MessageText:
//
//  Late error detected while checking the IP. No station was found.
//
#define TLR_E_PNIO_NRPM_LATE_ERROR_IP_LOOKUP_STATION_NOT_FOUND ((TLR_RESULT)0xC013001EL)

//
// MessageId: TLR_E_PNIO_NRPM_LATE_ERROR_IP_LOOKUP_MULTIPLE_STATIONS_FOUND
//
// MessageText:
//
//  Late error detected while checking the IP. Multiple stations were found.
//
#define TLR_E_PNIO_NRPM_LATE_ERROR_IP_LOOKUP_MULTIPLE_STATIONS_FOUND ((TLR_RESULT)0xC013001FL)

//
// MessageId: TLR_E_PNIO_MGT_EMPTY_POOL_DETECTED
//
// MessageText:
//
//  The packet pool of MGT is empty.
//
#define TLR_E_PNIO_MGT_EMPTY_POOL_DETECTED ((TLR_RESULT)0xC01300F0L)

//
// MessageId: TLR_E_PNIO_MGT_INVALID_DEV_INDEX
//
// MessageText:
//
//  The index of the device is invalid.
//
#define TLR_E_PNIO_MGT_INVALID_DEV_INDEX ((TLR_RESULT)0xC01300F1L)

// RMPM
//
// MessageId: TLR_E_PNIO_RMPM_HANDLE_INVALID
//
// MessageText:
//
//  The handle to RMPM is invalid.
//
#define TLR_E_PNIO_RMPM_HANDLE_INVALID   ((TLR_RESULT)0xC0130101L)

//
// MessageId: TLR_E_PNIO_RMPM_STATE_INVALID
//
// MessageText:
//
//  The state of RMPM is invalid for current request.
//
#define TLR_E_PNIO_RMPM_STATE_INVALID    ((TLR_RESULT)0xC0130102L)

//
// MessageId: TLR_E_PNIO_RMPM_STATE_CLOSING
//
// MessageText:
//
//  The state of RMPM is closed
//
#define TLR_E_PNIO_RMPM_STATE_CLOSING    ((TLR_RESULT)0xC0130103L)

//
// MessageId: TLR_E_PNIO_RMPM_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The number of RMPM state-machines is to high.
//
#define TLR_E_PNIO_RMPM_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0130104L)

//
// MessageId: TLR_E_PNIO_RMPM_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to fullfill the current request in RMPM.
//
#define TLR_E_PNIO_RMPM_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0130105L)

//
// MessageId: TLR_E_PNIO_RMPM_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in RMPM.
//
#define TLR_E_PNIO_RMPM_PACKET_SEND_FAILED ((TLR_RESULT)0xC0130106L)

//
// MessageId: TLR_E_PNIO_RMPM_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to allocate a packet in RMPM.
//
#define TLR_E_PNIO_RMPM_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0130107L)

//
// MessageId: TLR_E_PNIO_RMPM_ROLE_UNSUPPORTED
//
// MessageText:
//
//  The parameter "role" is unsupported in RMPM_Init_req_ParameterRole() .
//
#define TLR_E_PNIO_RMPM_ROLE_UNSUPPORTED ((TLR_RESULT)0xC0130108L)

//
// MessageId: TLR_E_PNIO_RMPM_ROLE_UNKNOWN
//
// MessageText:
//
//  The parameter "role" is unknown in RMPM_Init_req_ParameterRole() .
//
#define TLR_E_PNIO_RMPM_ROLE_UNKNOWN     ((TLR_RESULT)0xC0130109L)

//
// MessageId: TLR_E_PNIO_RMPM_ROLE_IN_USE
//
// MessageText:
//
//  The parameter "role" is already in use in RMPM_Init_req_ParameterRole() .
//
#define TLR_E_PNIO_RMPM_ROLE_IN_USE      ((TLR_RESULT)0xC013010AL)

//
// MessageId: TLR_E_PNIO_RMPM_CONFIG_SEQUENCE
//
// MessageText:
//
//  Incorrect sequence of configuration in RMPM_ConfigSet_req().
//
#define TLR_E_PNIO_RMPM_CONFIG_SEQUENCE  ((TLR_RESULT)0xC013010BL)

//
// MessageId: TLR_E_PNIO_RMPM_CONFIG_INVALID_VENDOR_ID
//
// MessageText:
//
//  Incorrect configuration of Vendor-ID in RMPM_ConfigSet_req().
//
#define TLR_E_PNIO_RMPM_CONFIG_INVALID_VENDOR_ID ((TLR_RESULT)0xC013010CL)

//
// MessageId: TLR_E_PNIO_RMPM_CONFIG_INVALID_NAME
//
// MessageText:
//
//  Incorrect name of station in RMPM_ConfigSet_req().
//
#define TLR_E_PNIO_RMPM_CONFIG_INVALID_NAME ((TLR_RESULT)0xC013010DL)

//
// MessageId: TLR_E_PNIO_RMPM_CONFIG_INVALID_TYPE
//
// MessageText:
//
//  Incorrect name of type in RMPM_ConfigSet_req().
//
#define TLR_E_PNIO_RMPM_CONFIG_INVALID_TYPE ((TLR_RESULT)0xC013010EL)

//
// MessageId: TLR_E_PNIO_RMPM_DUPLICATE_NAME_OF_STATION
//
// MessageText:
//
//  The NameOfStation of IO-Controller is in use by another network device.
//
#define TLR_E_PNIO_RMPM_DUPLICATE_NAME_OF_STATION ((TLR_RESULT)0xC0130110L)

//
// MessageId: TLR_E_PNIO_RMPM_DUPLICATE_IP
//
// MessageText:
//
//  The IP-address the IO-Controller shall use is in use by another network device.
//
#define TLR_E_PNIO_RMPM_DUPLICATE_IP     ((TLR_RESULT)0xC0130111L)

//
// MessageId: TLR_E_PNIO_RMPM_RPC_PACKET_INVALID
//
// MessageText:
//
//  The packet length of an RPC-packet received is invalid (most likely too short).
//
#define TLR_E_PNIO_RMPM_RPC_PACKET_INVALID ((TLR_RESULT)0xC0130112L)

//
// MessageId: TLR_E_PNIO_RMPM_DCP_PACKET_INVALID
//
// MessageText:
//
//  The packet length of an DCP-packet received is invalid (most likely too short).
//
#define TLR_E_PNIO_RMPM_DCP_PACKET_INVALID ((TLR_RESULT)0xC0130113L)

// IO-Device error codes
//
// MessageId: TLR_E_PNIO_RMPM_INVALID_IP_ADDRESS
//
// MessageText:
//
//  The IP address is invalid.
//
#define TLR_E_PNIO_RMPM_INVALID_IP_ADDRESS ((TLR_RESULT)0xC0130120L)

//
// MessageId: TLR_E_PNIO_RMPM_INVALID_NETMASK
//
// MessageText:
//
//  The network mask is invalid.
//
#define TLR_E_PNIO_RMPM_INVALID_NETMASK  ((TLR_RESULT)0xC0130121L)

//
// MessageId: TLR_E_PNIO_RMPM_INVALID_GATEWAY
//
// MessageText:
//
//  The gateway address is invalid.
//
#define TLR_E_PNIO_RMPM_INVALID_GATEWAY  ((TLR_RESULT)0xC0130122L)

// NRMC
//
// MessageId: TLR_E_PNIO_NRMC_PARAM_INVALID_INIT
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_NRMC_PARAM_INVALID_INIT ((TLR_RESULT)0xC0130200L)

//
// MessageId: TLR_E_PNIO_NRMC_HANDLE_INVALID
//
// MessageText:
//
//  The handle to NRMC is invalid.
//
#define TLR_E_PNIO_NRMC_HANDLE_INVALID   ((TLR_RESULT)0xC0130201L)

//
// MessageId: TLR_E_PNIO_NRMC_STATE_INVALID
//
// MessageText:
//
//  The state of NRMC is invalid for current request.
//
#define TLR_E_PNIO_NRMC_STATE_INVALID    ((TLR_RESULT)0xC0130202L)

//
// MessageId: TLR_E_PNIO_NRMC_IDENTIFY_FLAG_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_NRMC_IDENTIFY_FLAG_INVALID ((TLR_RESULT)0xC0130203L)

//
// MessageId: TLR_E_PNIO_NRMC_RESOURCE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The number of NRMC state-machines is to high.
//
#define TLR_E_PNIO_NRMC_RESOURCE_LIMIT_EXCEEDED ((TLR_RESULT)0xC0130204L)

//
// MessageId: TLR_E_PNIO_NRMC_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to fullfill the current request in NRMC.
//
#define TLR_E_PNIO_NRMC_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0130205L)

//
// MessageId: TLR_E_PNIO_NRMC_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task in NRMC.
//
#define TLR_E_PNIO_NRMC_PACKET_SEND_FAILED ((TLR_RESULT)0xC0130206L)

//
// MessageId: TLR_E_PNIO_NRMC_PACKET_OUT_OF_MEMORY
//
// MessageText:
//
//  Insufficient memory to allocate a packet in NRMC.
//
#define TLR_E_PNIO_NRMC_PACKET_OUT_OF_MEMORY ((TLR_RESULT)0xC0130207L)

//
// MessageId: TLR_E_PNIO_NRMC_DCP_TYPE_INVALID
//
// MessageText:
//
//  tbd.
//
#define TLR_E_PNIO_NRMC_DCP_TYPE_INVALID ((TLR_RESULT)0xC0130208L)

/////////////////////////////////////////////////////////////////////////////////////
// PNIO CTL Diagnosis-Codes
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// CMCTL-Task Diagnosis-Codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_DIAG_E_CMCTL_TASK_RESOURCE_INIT_FAILED
//
// MessageText:
//
//  Initializing CMCTL's task-resources failed.
//
#define TLR_DIAG_E_CMCTL_TASK_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC00AF000L)

//
// MessageId: TLR_DIAG_E_CMCTL_TASK_CREATE_QUE_FAILED
//
// MessageText:
//
//  Failed to create message-queue for CMCTL.
//
#define TLR_DIAG_E_CMCTL_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC00AF001L)

//
// MessageId: TLR_DIAG_E_CMCTL_TASK_CREATE_SYNC_QUE_FAILED
//
// MessageText:
//
//  Failed to create synchronous message-queue for CMCTL.
//
#define TLR_DIAG_E_CMCTL_TASK_CREATE_SYNC_QUE_FAILED ((TLR_RESULT)0xC00AF002L)

//
// MessageId: TLR_DIAG_E_CMCTL_TASK_RPC_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize CMCTL's local RPC-ressources.
//
#define TLR_DIAG_E_CMCTL_TASK_RPC_INIT_FAILED ((TLR_RESULT)0xC00AF003L)

//
// MessageId: TLR_DIAG_E_CMCTL_TASK_IDENT_ACP_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to ACP message-queue in CMCTL.
//
#define TLR_DIAG_E_CMCTL_TASK_IDENT_ACP_QUE_FALIED ((TLR_RESULT)0xC00AF004L)

//
// MessageId: TLR_DIAG_E_CMCTL_TASK_IDENT_MGT_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to MGT message-queue in CMCTL.
//
#define TLR_DIAG_E_CMCTL_TASK_IDENT_MGT_QUE_FALIED ((TLR_RESULT)0xC00AF005L)

//
// MessageId: TLR_DIAG_E_CMCTL_TASK_IDENT_RPC_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to RPC message-queue in CMCTL.
//
#define TLR_DIAG_E_CMCTL_TASK_IDENT_RPC_QUE_FALIED ((TLR_RESULT)0xC00AF006L)

//
// MessageId: TLR_DIAG_E_CMCTL_TASK_IDENT_TCP_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to TCP/IP message-queue in CMCTL .
//
#define TLR_DIAG_E_CMCTL_TASK_IDENT_TCP_QUE_FALIED ((TLR_RESULT)0xC00AF007L)

/////////////////////////////////////////////////////////////////////////////////////
// CMDEV-Task Diagnosis-Codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_DIAG_E_CMDEV_TASK_RESOURCE_INIT_FAILED
//
// MessageText:
//
//  Initializing CMDEV's task-resources failed.
//
#define TLR_DIAG_E_CMDEV_TASK_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC00BF000L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_CREATE_QUE_FAILED
//
// MessageText:
//
//  Failed to create message-queue for CMDEV.
//
#define TLR_DIAG_E_CMDEV_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC00BF001L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_CREATE_SYNC_QUE_FAILED
//
// MessageText:
//
//  Failed to create synchronous message-queue for CMDEV.
//
#define TLR_DIAG_E_CMDEV_TASK_CREATE_SYNC_QUE_FAILED ((TLR_RESULT)0xC00BF002L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_RPC_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize CMDEV's local RPC-ressources.
//
#define TLR_DIAG_E_CMDEV_TASK_RPC_INIT_FAILED ((TLR_RESULT)0xC00BF003L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_ACP_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to ACP message-queue in CMDEV.
//
#define TLR_DIAG_E_CMDEV_TASK_IDENT_ACP_QUE_FALIED ((TLR_RESULT)0xC00BF004L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_MGT_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to MGT message-queue in CMDEV.
//
#define TLR_DIAG_E_CMDEV_TASK_IDENT_MGT_QUE_FALIED ((TLR_RESULT)0xC00BF005L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_RPC_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to RPC message-queue in CMDEV.
//
#define TLR_DIAG_E_CMDEV_TASK_IDENT_RPC_QUE_FALIED ((TLR_RESULT)0xC00BF006L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_TCP_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to TCP/IP message-queue in CMDEV .
//
#define TLR_DIAG_E_CMDEV_TASK_IDENT_TCP_QUE_FALIED ((TLR_RESULT)0xC00BF007L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_DCP_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to DCP message-queue in CMDEV .
//
#define TLR_DIAG_E_CMDEV_TASK_IDENT_DCP_QUE_FALIED ((TLR_RESULT)0xC00BF008L)

//
// MessageId: TLR_DIAG_E_CMDEV_TASK_IDENT_PNSIF_QUE_FALIED
//
// MessageText:
//
//  Failed to get handle to PNSIF message-queue in CMDEV .
//
#define TLR_DIAG_E_CMDEV_TASK_IDENT_PNSIF_QUE_FALIED ((TLR_RESULT)0xC00BF009L)

/////////////////////////////////////////////////////////////////////////////////////
// ACP-Task Diagnosis-Codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNIO_ACP_COMMAND_INVALID
//
// MessageText:
//
//  Received invalid command in ACP task.
//
#define TLR_E_PNIO_ACP_COMMAND_INVALID   ((TLR_RESULT)0xC011F001L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_ACP_PHASE_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize ACP Phase.
//
#define TLR_DIAG_E_ACP_TASK_ACP_PHASE_INIT_FAILED ((TLR_RESULT)0xC011F010L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_ALARM_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize Alarm-machines.
//
#define TLR_DIAG_E_ACP_TASK_ALARM_INIT_FAILED ((TLR_RESULT)0xC011F011L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_APMR_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize APMR.
//
#define TLR_DIAG_E_ACP_TASK_APMR_INIT_FAILED ((TLR_RESULT)0xC011F012L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_APMS_INIT_FAILED
//
// MessageText:
//
//  Failes to initialize APMS.
//
#define TLR_DIAG_E_ACP_TASK_APMS_INIT_FAILED ((TLR_RESULT)0xC011F013L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_CPM_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize CPM.
//
#define TLR_DIAG_E_ACP_TASK_CPM_INIT_FAILED ((TLR_RESULT)0xC011F014L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_PPM_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize PPM.
//
#define TLR_DIAG_E_ACP_TASK_PPM_INIT_FAILED ((TLR_RESULT)0xC011F015L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_CREATE_QUE_FAILED
//
// MessageText:
//
//  Failed to create message-queue for ACP.
//
#define TLR_DIAG_E_ACP_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC011F016L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_IDENT_EDD_FAILED
//
// MessageText:
//
//  Failed to identify Drv_EDD.
//
#define TLR_DIAG_E_ACP_TASK_IDENT_EDD_FAILED ((TLR_RESULT)0xC011F017L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_IDENT_EDD_QUE_FAILED
//
// MessageText:
//
//  Failed to get handle to EDD message-queue.
//
#define TLR_DIAG_E_ACP_TASK_IDENT_EDD_QUE_FAILED ((TLR_RESULT)0xC011F018L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_IDENT_DCP_QUE_FAILED
//
// MessageText:
//
//  Failed to get handle to DCP message-queue.
//
#define TLR_DIAG_E_ACP_TASK_IDENT_DCP_QUE_FAILED ((TLR_RESULT)0xC011F019L)

//
// MessageId: TLR_DIAG_E_ACP_TASK_IDENT_CMDEV_QUE_FAILED
//
// MessageText:
//
//  Failed to get handle to CMDEV message-queue.
//
#define TLR_DIAG_E_ACP_TASK_IDENT_CMDEV_QUE_FAILED ((TLR_RESULT)0xC011F01AL)

/////////////////////////////////////////////////////////////////////////////////////
// EDD-Task Diagnosis-Codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNIO_EDD_COMMAND_INVALID
//
// MessageText:
//
//  Received invalid command in EDD task.
//
#define TLR_E_PNIO_EDD_COMMAND_INVALID   ((TLR_RESULT)0xC00EF001L)

//
// MessageId: TLR_DIAG_E_EDD_TASK_INIT_LOCAL_FAILED
//
// MessageText:
//
//  Failed to initialize EDD's local resources.
//
#define TLR_DIAG_E_EDD_TASK_INIT_LOCAL_FAILED ((TLR_RESULT)0xC00EF010L)

/////////////////////////////////////////////////////////////////////////////////////
// DCP-Task Diagnosis-Codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNIO_DCP_COMMAND_INVALID
//
// MessageText:
//
//  Received invalid command in DCP task.
//
#define TLR_E_PNIO_DCP_COMMAND_INVALID   ((TLR_RESULT)0xC012F001L)

//
// MessageId: TLR_DIAG_E_DCP_TASK_UCS_RESOURCE_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize DCPUCS.
//
#define TLR_DIAG_E_DCP_TASK_UCS_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC012F010L)

//
// MessageId: TLR_DIAG_E_DCP_TASK_UCR_RESOURCE_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize DCPUCR.
//
#define TLR_DIAG_E_DCP_TASK_UCR_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC012F011L)

//
// MessageId: TLR_DIAG_E_DCP_TASK_MCS_RESOURCE_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize DCPMCS.
//
#define TLR_DIAG_E_DCP_TASK_MCS_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC012F012L)

//
// MessageId: TLR_DIAG_E_DCP_TASK_MCR_RESOURCE_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize DCPMCR.
//
#define TLR_DIAG_E_DCP_TASK_MCR_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC012F013L)

//
// MessageId: TLR_DIAG_E_DCP_TASK_CREATE_QUE_FAILED
//
// MessageText:
//
//  Failed to create message-queue for DCP task.
//
#define TLR_DIAG_E_DCP_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC012F014L)

/////////////////////////////////////////////////////////////////////////////////////
// MGT-Task Diagnosis-Codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNIO_MGT_COMMAND_INVALID
//
// MessageText:
//
//  Received invalid command in MGT task.
//
#define TLR_E_PNIO_MGT_COMMAND_INVALID   ((TLR_RESULT)0xC013F001L)

//
// MessageId: TLR_DIAG_E_MGT_TASK_RMPM_RESOURCE_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize RMPM.
//
#define TLR_DIAG_E_MGT_TASK_RMPM_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC013F010L)

//
// MessageId: TLR_DIAG_E_MGT_TASK_NRPM_RESOURCE_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize NRPM.
//
#define TLR_DIAG_E_MGT_TASK_NRPM_RESOURCE_INIT_FAILED ((TLR_RESULT)0xC013F011L)

//
// MessageId: TLR_DIAG_E_MGT_TASK_CREATE_QUE_FAILED
//
// MessageText:
//
//  Failed to create message-queue for MGT task.
//
#define TLR_DIAG_E_MGT_TASK_CREATE_QUE_FAILED ((TLR_RESULT)0xC013F012L)

//
// MessageId: TLR_DIAG_E_MGT_TASK_IDENT_TCPUDP_QUE_FAILED
//
// MessageText:
//
//  Failed to get handle to TCP/IP task in MGT task.
//
#define TLR_DIAG_E_MGT_TASK_IDENT_TCPUDP_QUE_FAILED ((TLR_RESULT)0xC013F013L)

//
// MessageId: TLR_DIAG_E_MGT_TASK_IDENT_DCP_QUE_FAILED
//
// MessageText:
//
//  Failed to get handle to DCP task in MGT task.
//
#define TLR_DIAG_E_MGT_TASK_IDENT_DCP_QUE_FAILED ((TLR_RESULT)0xC013F014L)

//
// MessageId: TLR_DIAG_E_MGT_TASK_IDENT_EDD_FAILED
//
// MessageText:
//
//  Failed to identify Drv_EDD im MGT task.
//
#define TLR_DIAG_E_MGT_TASK_IDENT_EDD_FAILED ((TLR_RESULT)0xC013F015L)

//
// MessageId: TLR_DIAG_E_MGT_TASK_IDENT_RPC_QUE_FAILED
//
// MessageText:
//
//  Failed to get handle to RPC task in MGT task.
//
#define TLR_DIAG_E_MGT_TASK_IDENT_RPC_QUE_FAILED ((TLR_RESULT)0xC013F016L)

/////////////////////////////////////////////////////////////////////////////////////
// RTA Task
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNIO_RTA_INVALID_SOURCE_ENDPOINT
//
// MessageText:
//
//  Invalid parameter alarm source endpoint is higher than specified maximum AR count.
//
#define TLR_E_PNIO_RTA_INVALID_SOURCE_ENDPOINT ((TLR_RESULT)0xC09F0000L)

//
// MessageId: TLR_E_PNIO_RTA_SOURCE_ENDPOINT_ALREADY_USED
//
// MessageText:
//
//  The alarm source endpoint specified is already used by another context managment instance.
//
#define TLR_E_PNIO_RTA_SOURCE_ENDPOINT_ALREADY_USED ((TLR_RESULT)0xC09F0001L)

//
// MessageId: TLR_E_PNIO_RTA_SOURCE_ENDPOINT_NOT_USED
//
// MessageText:
//
//  The alarm source endpoint specified is not used by a context managment instance.
//
#define TLR_E_PNIO_RTA_SOURCE_ENDPOINT_NOT_USED ((TLR_RESULT)0xC09F0002L)

//
// MessageId: TLR_E_PNIO_RTA_SOURCE_ENDPOINT_UNINITIALIZED
//
// MessageText:
//
//  The alarm source endpoint specified is not initialized.
//
#define TLR_E_PNIO_RTA_SOURCE_ENDPOINT_UNINITIALIZED ((TLR_RESULT)0xC09F0003L)

//
// MessageId: TLR_E_PNIO_RTA_INVALID_ALARM_PRIORITY
//
// MessageText:
//
//  The requested alarm priority is not supported.
//
#define TLR_E_PNIO_RTA_INVALID_ALARM_PRIORITY ((TLR_RESULT)0xC09F0004L)

//
// MessageId: TLR_E_PNIO_RTA_INVALID_ALARM_LENGTH
//
// MessageText:
//
//  The requested alarm data length exceeds the allowed maximum value of the AR.
//
#define TLR_E_PNIO_RTA_INVALID_ALARM_LENGTH ((TLR_RESULT)0xC09F0005L)

//
// MessageId: TLR_E_PNIO_RTA_NO_CONTEXT_MANAGMENT
//
// MessageText:
//
//  No context managment registered. The indication can not be sent to context managment.
//
#define TLR_E_PNIO_RTA_NO_CONTEXT_MANAGMENT ((TLR_RESULT)0xC09F0006L)




#endif  //__PNIOC_ERROR_H

