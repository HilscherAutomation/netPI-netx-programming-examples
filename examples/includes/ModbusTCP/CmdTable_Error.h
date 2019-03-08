#ifndef __CMD_TABLE_ERROR_H
#define __CMD_TABLE_ERROR_H

/////////////////////////////////////////////////////////////////////////////////////
// Command Table ERROR codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_CMD_TABLE_COMMAND_INVALID
//
// MessageText:
//
//  Invalid command received.
//
#define TLR_E_CMD_TABLE_COMMAND_INVALID  (0xC0E20001L)

//
// MessageId: TLR_E_CMDTBL_INVALID_PROTOCOL_TYPE
//
// MessageText:
//
//  Not supported protocol.
//
#define TLR_E_CMDTBL_INVALID_PROTOCOL_TYPE (0xC0E20002L)

//
// MessageId: TLR_E_CMDTBL_INVALID_QUEUE_NAME
//
// MessageText:
//
//  The Queue name is invalid.
//
#define TLR_E_CMDTBL_INVALID_QUEUE_NAME  (0xC0E20003L)

//
// MessageId: TLR_E_CMDTBL_UNSUPPORTED_VERSION
//
// MessageText:
//
//  The version is not supported.
//
#define TLR_E_CMDTBL_UNSUPPORTED_VERSION (0xC0E20004L)

//
// MessageId: TLR_E_CMDTBL_TABLE_NOT_AVAILABLE
//
// MessageText:
//
//  The table is not configured.
//
#define TLR_E_CMDTBL_TABLE_NOT_AVAILABLE (0xC0E20005L)

//
// MessageId: TLR_E_CMDTBL_COMMAND_NOT_AVAILABLE
//
// MessageText:
//
//  The command is not configured.
//
#define TLR_E_CMDTBL_COMMAND_NOT_AVAILABLE (0xC0E20006L)

//
// MessageId: TLR_E_CMDTBL_DEST_QUEUE_NOT_INITED
//
// MessageText:
//
//  The destination queue is not initialized.
//
#define TLR_E_CMDTBL_DEST_QUEUE_NOT_INITED (0xC0E20007L)

//
// MessageId: TLR_E_CMDTBL_COMMAND_DOES_NOT_MATCH_TABLE
//
// MessageText:
//
//  The requested command does not exist in the table.
//
#define TLR_E_CMDTBL_COMMAND_DOES_NOT_MATCH_TABLE (0xC0E20008L)

//
// MessageId: TLR_E_CMDTBL_COMMAND_NOT_TRIGGERABLE
//
// MessageText:
//
//  The command is not defined as a triggerable one.
//
#define TLR_E_CMDTBL_COMMAND_NOT_TRIGGERABLE (0xC0E20009L)

//
// MessageId: TLR_E_CMDTBL_COMMAND_NOT_ACTIVE
//
// MessageText:
//
//  The command is not active or belongs to inactive table.
//
#define TLR_E_CMDTBL_COMMAND_NOT_ACTIVE  (0xC0E2000AL)

//
// MessageId: TLR_E_CMDTBL_UNSUPPORTED_PROTOCOL_TYPE
//
// MessageText:
//
//  The command is not active or belongs to inactive table.
//
#define TLR_E_CMDTBL_UNSUPPORTED_PROTOCOL_TYPE (0xC0E2000BL)

//
// MessageId: TLR_E_CMDTBL_MAX_TABLES_REACHED
//
// MessageText:
//
//  The maximum tables number has been reached.
//
#define TLR_E_CMDTBL_MAX_TABLES_REACHED  (0xC0E2000CL)

//
// MessageId: TLR_E_CMDTBL_MAX_COMMANDS_REACHED
//
// MessageText:
//
//  The maximum commands number has been reached.
//
#define TLR_E_CMDTBL_MAX_COMMANDS_REACHED (0xC0E2000DL)

//
// MessageId: TLR_E_CMDTBL_ALREADY_INITED
//
// MessageText:
//
//  The Command Table has already been initialized. Performe a Deinitialization first.
//
#define TLR_E_CMDTBL_ALREADY_INITED      (0xC0E2000EL)

//
// MessageId: TLR_E_CMDTBL_NOT_INITED
//
// MessageText:
//
//  The Command Table has not been initialized. Performe a Initialization first.
//
#define TLR_E_CMDTBL_NOT_INITED          (0xC0E2000FL)

//
// MessageId: TLR_E_CMDTBL_REQ_NOT_ALLOWED
//
// MessageText:
//
//  The reguest is not allowed at this moment/state.
//
#define TLR_E_CMDTBL_REQ_NOT_ALLOWED     (0xC0E20010L)

//
// MessageId: TLR_E_CMDTBL_INVALID_DEVICE_ADDRESS
//
// MessageText:
//
//  An invalid Device Address has been detected.
//
#define TLR_E_CMDTBL_INVALID_DEVICE_ADDRESS (0xC0E20011L)

//
// MessageId: TLR_E_CMDTBL_INVALID_UNIT_ID
//
// MessageText:
//
//  An invalid Unit Identifier has been detected.
//
#define TLR_E_CMDTBL_INVALID_UNIT_ID     (0xC0E20012L)

//
// MessageId: TLR_E_CMDTBL_INVALID_FUNCTION_CODE
//
// MessageText:
//
//  An invalid Function Code has been detected.
//
#define TLR_E_CMDTBL_INVALID_FUNCTION_CODE (0xC0E20013L)

//
// MessageId: TLR_E_CMDTBL_INVALID_DATA_COUNT
//
// MessageText:
//
//  An invalid Data Size has been detected.
//
#define TLR_E_CMDTBL_INVALID_DATA_COUNT  (0xC0E20014L)

//
// MessageId: TLR_E_CMDTBL_INVALID_COMMAND_OFFSET
//
// MessageText:
//
//  An invalid Command Offset has been detected.
//
#define TLR_E_CMDTBL_INVALID_COMMAND_OFFSET (0xC0E20015L)

//
// MessageId: TLR_E_CMDTBL_INVALID_TRIGGER_TYPE
//
// MessageText:
//
//  An invalid Trigger Type has been detected.
//
#define TLR_E_CMDTBL_INVALID_TRIGGER_TYPE (0xC0E20016L)

//
// MessageId: TLR_E_CMDTBL_INVALID_CYCLE_PERIOD
//
// MessageText:
//
//  An invalid Cycle Period has been detected.
//
#define TLR_E_CMDTBL_INVALID_CYCLE_PERIOD (0xC0E20017L)

//
// MessageId: TLR_E_CMDTBL_INVALID_RESERVED_VALUE
//
// MessageText:
//
//  An invalid Reserved Field has been detected.
//
#define TLR_E_CMDTBL_INVALID_RESERVED_VALUE (0xC0E20018L)

//
// MessageId: TLR_E_CMDTBL_ONE_TABLE_PER_DEVICE_ADDR
//
// MessageText:
//
//  Each device address can be part of only one table.
//
#define TLR_E_CMDTBL_ONE_TABLE_PER_DEVICE_ADDR (0xC0E20019L)

//
// MessageId: TLR_E_CMDTBL_OFFSET_NOT_ALIGNED
//
// MessageText:
//
//  The offset is not 4-byte alligned.
//
#define TLR_E_CMDTBL_OFFSET_NOT_ALIGNED  (0xC0E2001AL)

//
// MessageId: TLR_E_CMDTBL_INVALID_DATA_ADDRESS
//
// MessageText:
//
//  An invalid Data Address has been detected.
//
#define TLR_E_CMDTBL_INVALID_DATA_ADDRESS (0xC0E2001BL)

//
// MessageId: TLR_E_CMDTBL_INVALID_BITFIELD_OFFSET
//
// MessageText:
//
//  An invalid Bitfield Offset has been detected.
//
#define TLR_E_CMDTBL_INVALID_BITFIELD_OFFSET (0xC0E2001CL)

//
// MessageId: TLR_E_CMDTBL_INVALID_COMMAND_DELAY
//
// MessageText:
//
//  An invalid Command Dellay has been detected.
//
#define TLR_E_CMDTBL_INVALID_COMMAND_DELAY (0xC0E2001DL)

//
// MessageId: TLR_E_CMDTBL_INVALID_SCAN_DELAY
//
// MessageText:
//
//  An invalid Interscan Dellay has been detected.
//
#define TLR_E_CMDTBL_INVALID_SCAN_DELAY  (0xC0E2001EL)

//
// MessageId: TLR_E_CMDTBL_CYCLE_PERIOD_MUST_BE_ZERO
//
// MessageText:
//
//  The command cycle period and the table cycle period can not be non-zero values at the same time.
//
#define TLR_E_CMDTBL_CYCLE_PERIOD_MUST_BE_ZERO (0xC0E2001FL)




#endif  //__CMD_TABLE_ERROR_H

