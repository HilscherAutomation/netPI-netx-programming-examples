/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: EplCn_Nmt_Results.h 3176 2017-07-05 15:26:30Z Ricky $:

Description:
  Powerlink Controlled Node result codes definitions for NMT component
**************************************************************************************/

#ifndef __EPLCN_NMT_RESULTS_H
#define __EPLCN_NMT_RESULTS_H

#include<stdint.h>

/////////////////////////////////////////////////////////////////////////////////////
// POWERLINK Controlled Node result codes for NMT component
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: ERR_EPLCN_NMT_INVALID_STATE_CHANGE
//
// MessageText:
//
// Invalid state change.
//
#define ERR_EPLCN_NMT_INVALID_STATE_CHANGE ((uint32_t)0xC0E60001L)

//
// MessageId: ERR_EPLCN_NMT_STACK_NOT_CONFIGURED
//
// MessageText:
//
// Stack is not configured.
//
#define ERR_EPLCN_NMT_STACK_NOT_CONFIGURED ((uint32_t)0xC0E60002L)

//
// MessageId: ERR_EPLCN_NMT_NOT_ALLOWED_IN_ACT_STATE
//
// MessageText:
//
// Action not allowed in current NMT state.
//
#define ERR_EPLCN_NMT_NOT_ALLOWED_IN_ACT_STATE ((uint32_t)0xC0E60003L)

//
// MessageId: ERR_EPLCN_NMT_MAX_PDO_SIZE_EXCEEDED
//
// MessageText:
//
// Maximum allowed PDO exceeded.
//
#define ERR_EPLCN_NMT_MAX_PDO_SIZE_EXCEEDED ((uint32_t)0xC0E60004L)

//
// MessageId: ERR_EPLCN_NMT_ENTRY_TYPE_IS_NOT_ERROR_ENTRY
//
// MessageText:
//
// Entry type is not ErrorEntry.
//
#define ERR_EPLCN_NMT_ENTRY_TYPE_IS_NOT_ERROR_ENTRY ((uint32_t)0xC0E60005L)

//
// MessageId: ERR_EPLCN_NMT_ENTRY_TYPE_IS_NOT_STATUS_ENTRY
//
// MessageText:
//
// Entry type is not StatusEntry.
//
#define ERR_EPLCN_NMT_ENTRY_TYPE_IS_NOT_STATUS_ENTRY ((uint32_t)0xC0E60006L)

//
// MessageId: ERR_EPLCN_NMT_MAX_NUM_STATUS_ENTRIES_EXCEEDED
//
// MessageText:
//
// Maximum allowed number of StatusEntry exceeded.
//
#define ERR_EPLCN_NMT_MAX_NUM_STATUS_ENTRIES_EXCEEDED ((uint32_t)0xC0E60007L)

//
// MessageId: ERR_EPLCN_NMT_CONFIGURED_NUM_STATUS_ENTRIES_EXCEEDED
//
// MessageText:
//
// Entry number exceeds the configured maximum number of StatusEntry.
//
#define ERR_EPLCN_NMT_CONFIGURED_NUM_STATUS_ENTRIES_EXCEEDED ((uint32_t)0xC0E60008L)

//
// MessageId: ERR_EPLCN_NMT_INVALID_STATIC_FIELD_BIT_NUMBER
//
// MessageText:
//
// Invalid requested bit number for StaticFieldBit.
//
#define ERR_EPLCN_NMT_INVALID_STATIC_FIELD_BIT_NUMBER ((uint32_t)0xC0E60009L)

//
// MessageId: ERR_EPLCN_NMT_FSM_AUTO_RUN_ENABLED
//
// MessageText:
//
// The NMT state machine is running in auto mode. State changes cannot be triggered by the application.
//
#define ERR_EPLCN_NMT_FSM_AUTO_RUN_ENABLED ((uint32_t)0xC0E6000AL)

//
// MessageId: ERR_EPLCN_NMT_CONFIGURED_CYCLE_LENGTH_TOO_LOW
//
// MessageText:
//
// Configured cycle length is too low.
//
#define ERR_EPLCN_NMT_CONFIGURED_CYCLE_LENGTH_TOO_LOW ((uint32_t)0xC0E6000BL)

//
// MessageId: ERR_EPLCN_NMT_CONFIGURED_MIN_CYCLE_LENGTH_TOO_LOW
//
// MessageText:
//
// Configured minimum cycle length is too low for the current hardware/software combination.
//
#define ERR_EPLCN_NMT_CONFIGURED_MIN_CYCLE_LENGTH_TOO_LOW ((uint32_t)0xC0E6000CL)

//
// MessageId: ERR_EPLCN_NMT_INVALID_NODE_ID
//
// MessageText:
//
// The configured NodeId is Invalid.
//
#define ERR_EPLCN_NMT_INVALID_NODE_ID    ((uint32_t)0xC0E6000DL)

#endif  /* __EPLCN_NMT_RESULTS_H */
