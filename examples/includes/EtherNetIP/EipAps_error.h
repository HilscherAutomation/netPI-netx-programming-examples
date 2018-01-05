#ifndef __EIP_APS_ERROR_H
#define __EIP_APS_ERROR_H

/////////////////////////////////////////////////////////////////////////////////////
// Ethernet/IP Application Task
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_EIP_APS_COMMAND_INVALID
//
// MessageText:
//
//  Invalid command received.
//
#define TLR_E_EIP_APS_COMMAND_INVALID    ((TLR_RESULT)0xC0590001L)

//
// MessageId: TLR_E_EIP_APS_PACKET_LENGTH_INVALID
//
// MessageText:
//
//  Invalid packet length.
//
#define TLR_E_EIP_APS_PACKET_LENGTH_INVALID ((TLR_RESULT)0xC0590002L)

//
// MessageId: TLR_E_EIP_APS_PACKET_PARAMETER_INVALID
//
// MessageText:
//
//  Parameter of the packet are invalid.
//
#define TLR_E_EIP_APS_PACKET_PARAMETER_INVALID ((TLR_RESULT)0xC0590003L)

//
// MessageId: TLR_E_EIP_APS_TCP_CONFIG_FAIL
//
// MessageText:
//
//  Configuration of TCP/IP failed.
//
#define TLR_E_EIP_APS_TCP_CONFIG_FAIL    ((TLR_RESULT)0xC0590004L)

//
// MessageId: TLR_E_EIP_APS_CONNECTION_CLOSED
//
// MessageText:
//
//  Existing connection is closed.
//
#define TLR_E_EIP_APS_CONNECTION_CLOSED  ((TLR_RESULT)0xC0590005L)

//
// MessageId: TLR_E_EIP_APS_ALREADY_REGISTERED
//
// MessageText:
//
//  A application is already registered.
//
#define TLR_E_EIP_APS_ALREADY_REGISTERED ((TLR_RESULT)0xC0590006L)

//
// MessageId: TLR_E_EIP_APS_ACCESS_FAIL
//
// MessageText:
//
//  Command is not allowed.
//
#define TLR_E_EIP_APS_ACCESS_FAIL        ((TLR_RESULT)0xC0590007L)

//
// MessageId: TLR_E_EIP_APS_STATE_FAIL
//
// MessageText:
//
//  Command not allowed at this state.
//
#define TLR_E_EIP_APS_STATE_FAIL         ((TLR_RESULT)0xC0590008L)

//
// MessageId: TLR_E_EIP_APS_IO_OFFSET_INVALID
//
// MessageText:
//
//  Invalid offset for I/O data.
//
#define TLR_E_EIP_APS_IO_OFFSET_INVALID  ((TLR_RESULT)0xC0590009L)

//
// MessageId: TLR_E_EIP_APS_FOLDER_NOT_FOUND
//
// MessageText:
//
//  Folder for database not found.
//
#define TLR_E_EIP_APS_FOLDER_NOT_FOUND   ((TLR_RESULT)0xC059000AL)

//
// MessageId: TLR_E_EIP_APS_CONFIG_DBM_INVALID
//
// MessageText:
//
//  Configuration database invalid.
//
#define TLR_E_EIP_APS_CONFIG_DBM_INVALID ((TLR_RESULT)0xC059000BL)

//
// MessageId: TLR_E_EIP_APS_NO_CONFIG_DBM
//
// MessageText:
//
//  Configuration database not found.
//
#define TLR_E_EIP_APS_NO_CONFIG_DBM      ((TLR_RESULT)0xC059000CL)

//
// MessageId: TLR_E_EIP_APS_NWID_DBM_INVALID
//
// MessageText:
//
//  network database invalid.
//
#define TLR_E_EIP_APS_NWID_DBM_INVALID   ((TLR_RESULT)0xC059000DL)

//
// MessageId: TLR_E_EIP_APS_NO_NWID_DBM
//
// MessageText:
//
//  network database not found.
//
#define TLR_E_EIP_APS_NO_NWID_DBM        ((TLR_RESULT)0xC059000EL)

//
// MessageId: TLR_E_EIP_APS_NO_DBM
//
// MessageText:
//
//  no database found.
//
#define TLR_E_EIP_APS_NO_DBM             ((TLR_RESULT)0xC059000FL)

//
// MessageId: TLR_E_EIP_APS_NO_MAC_ADDRESS_AVAILABLE
//
// MessageText:
//
//  no MAC address available.
//
#define TLR_E_EIP_APS_NO_MAC_ADDRESS_AVAILABLE ((TLR_RESULT)0xC0590010L)

//
// MessageId: TLR_E_EIP_APS_INVALID_FILESYSTEM
//
// MessageText:
//
//  access to file system failed.
//
#define TLR_E_EIP_APS_INVALID_FILESYSTEM ((TLR_RESULT)0xC0590011L)

//
// MessageId: TLR_E_EIP_APS_NUM_AS_INSTANCE_EXCEEDS
//
// MessageText:
//
//  maximum number of assembly instances exceeds.
//
#define TLR_E_EIP_APS_NUM_AS_INSTANCE_EXCEEDS ((TLR_RESULT)0xC0590012L)

//
// MessageId: TLR_E_EIP_APS_CONFIGBYDATABASE
//
// MessageText:
//
//  stack is already configured via database.
//
#define TLR_E_EIP_APS_CONFIGBYDATABASE   ((TLR_RESULT)0xC0590013L)




#endif  //__EIP_APS_ERROR_H

