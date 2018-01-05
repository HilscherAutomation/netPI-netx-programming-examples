#ifndef __EIP_OBJECT_ERROR_H
#define __EIP_OBJECT_ERROR_H

#ifndef TLR_RESULT
  #define TLR_RESULT uint32_t
#endif

/////////////////////////////////////////////////////////////////////////////////////
// Ethernet/IP Object
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_EIP_OBJECT_COMMAND_INVALID
//
// MessageText:
//
//  Invalid command received.
//
#define TLR_E_EIP_OBJECT_COMMAND_INVALID ((TLR_RESULT)0xC01F0001L)

//
// MessageId: TLR_E_EIP_OBJECT_OUT_OF_MEMORY
//
// MessageText:
//
//  System is out of memory.
//
#define TLR_E_EIP_OBJECT_OUT_OF_MEMORY   ((TLR_RESULT)0xC01F0002L)

//
// MessageId: TLR_E_EIP_OBJECT_OUT_OF_PACKETS
//
// MessageText:
//
//  Task runs out of empty packets at the local packet pool.
//
#define TLR_E_EIP_OBJECT_OUT_OF_PACKETS  ((TLR_RESULT)0xC01F0003L)

//
// MessageId: TLR_E_EIP_OBJECT_SEND_PACKET
//
// MessageText:
//
//  Sending a packet failed.
//
#define TLR_E_EIP_OBJECT_SEND_PACKET     ((TLR_RESULT)0xC01F0004L)

//
// MessageId: TLR_E_EIP_OBJECT_AS_ALLREADY_EXIST
//
// MessageText:
//
//  Assembly instance already exist.
//
#define TLR_E_EIP_OBJECT_AS_ALLREADY_EXIST ((TLR_RESULT)0xC01F0010L)

//
// MessageId: TLR_E_EIP_OBJECT_AS_INVALID_INST
//
// MessageText:
//
//  Invalid Assembly Instance.
//
#define TLR_E_EIP_OBJECT_AS_INVALID_INST ((TLR_RESULT)0xC01F0011L)

//
// MessageId: TLR_E_EIP_OBJECT_AS_INVALID_LEN
//
// MessageText:
//
//  Invalid Assembly length.
//
#define TLR_E_EIP_OBJECT_AS_INVALID_LEN  ((TLR_RESULT)0xC01F0012L)

//
// MessageId: TLR_E_EIP_OBJECT_CONN_OVERRUN
//
// MessageText:
//
//  No free connection buffer available
//
#define TLR_E_EIP_OBJECT_CONN_OVERRUN    ((TLR_RESULT)0xC01F0020L)

//
// MessageId: TLR_E_EIP_OBJECT_INVALID_CLASS
//
// MessageText:
//
//  Object class is invalid.
//
#define TLR_E_EIP_OBJECT_INVALID_CLASS   ((TLR_RESULT)0xC01F0021L)

//
// MessageId: TLR_E_EIP_OBJECT_SEGMENT_FAULT
//
// MessageText:
//
//  Segment of the path is invalid.
//
#define TLR_E_EIP_OBJECT_SEGMENT_FAULT   ((TLR_RESULT)0xC01F0022L)

//
// MessageId: TLR_E_EIP_OBJECT_CLASS_ALLREADY_EXIST
//
// MessageText:
//
//  Object Class is already used.
//
#define TLR_E_EIP_OBJECT_CLASS_ALLREADY_EXIST ((TLR_RESULT)0xC01F0023L)

//
// MessageId: TLR_E_EIP_OBJECT_CONNECTION_FAIL
//
// MessageText:
//
//  Connection failed.
//
#define TLR_E_EIP_OBJECT_CONNECTION_FAIL ((TLR_RESULT)0xC01F0024L)

//
// MessageId: TLR_E_EIP_OBJECT_CONNECTION_PARAM
//
// MessageText:
//
//  Unknown format of connection parameter
//
#define TLR_E_EIP_OBJECT_CONNECTION_PARAM ((TLR_RESULT)0xC01F0025L)

//
// MessageId: TLR_E_EIP_OBJECT_UNKNOWN_CONNECTION
//
// MessageText:
//
//  Invalid connection ID.
//
#define TLR_E_EIP_OBJECT_UNKNOWN_CONNECTION ((TLR_RESULT)0xC01F0026L)

//
// MessageId: TLR_E_EIP_OBJECT_NO_OBJ_RESSOURCE
//
// MessageText:
//
//  No resource for creating a new class object available.
//
#define TLR_E_EIP_OBJECT_NO_OBJ_RESSOURCE ((TLR_RESULT)0xC01F0027L)

//
// MessageId: TLR_E_EIP_OBJECT_ID_INVALID_PARAMETER
//
// MessageText:
//
//  Invalid request parameter.
//
#define TLR_E_EIP_OBJECT_ID_INVALID_PARAMETER ((TLR_RESULT)0xC01F0028L)

//
// MessageId: TLR_E_EIP_OBJECT_CONNECTION_FAILED
//
// MessageText:
//
//  General connection failure. See also General Error Code and Extended Error Code for more details.
//
#define TLR_E_EIP_OBJECT_CONNECTION_FAILED ((TLR_RESULT)0xC01F0029L)

//
// MessageId: TLR_E_EIP_OBJECT_PACKET_LEN
//
// MessageText:
//
//  Packet length of the request is invalid.
//
#define TLR_E_EIP_OBJECT_PACKET_LEN      ((TLR_RESULT)0xC01F0030L)

//
// MessageId: TLR_E_EIP_OBJECT_READONLY_INST
//
// MessageText:
//
//  Access denied. Instance is read only.
//
#define TLR_E_EIP_OBJECT_READONLY_INST   ((TLR_RESULT)0xC01F0031L)

//
// MessageId: TLR_E_EIP_OBJECT_DPM_USED
//
// MessageText:
//
//  DPM address is already used by an other instance.
//
#define TLR_E_EIP_OBJECT_DPM_USED        ((TLR_RESULT)0xC01F0032L)

//
// MessageId: TLR_E_EIP_OBJECT_SET_OUTPUT_RUNNING
//
// MessageText:
//
//  Set Output command is already runnning.
//
#define TLR_E_EIP_OBJECT_SET_OUTPUT_RUNNING ((TLR_RESULT)0xC01F0033L)

//
// MessageId: TLR_E_EIP_OBJECT_TASK_RESETING
//
// MessageText:
//
//  Etthernet/IP Object Task is running a reset.
//
#define TLR_E_EIP_OBJECT_TASK_RESETING   ((TLR_RESULT)0xC01F0034L)

//
// MessageId: TLR_E_EIP_OBJECT_SERVICE_ALLREADY_EXIST
//
// MessageText:
//
//  The service that shall be registered already exists.
//
#define TLR_E_EIP_OBJECT_SERVICE_ALLREADY_EXIST ((TLR_RESULT)0xC01F0035L)

//
// MessageId: TLR_E_EIP_OBJECT_DUPLICATE_SERVICE
//
// MessageText:
//
//  The service is rejected by the application due to a duplicate sequence count.
//
#define TLR_E_EIP_OBJECT_DUPLICATE_SERVICE ((TLR_RESULT)0xC01F0036L)

#define TLR_E_EIP_TIMER_INVALID_HANDLE ((TLR_RESULT)0xC01F00FFL)

#define TLR_E_EIP_OUT_OF_OS_RESOURCES  ((TLR_RESULT)0xC01F00FEL)

#define TLR_E_EIP_INVALID_MODE         ((TLR_RESULT)0xC01F00FDL)

#ifndef TLR_E_EVALUATION_TIME_EXPIRED
#define TLR_E_EVALUATION_TIME_EXPIRED ((TLR_RESULT)0xC000F007L)
#endif
#endif  //__EIP_OBJECT_ERROR_H

