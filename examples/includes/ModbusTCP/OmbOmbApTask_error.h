#ifndef __OMB_OMBAPTASK_ERROR_H
#define __OMB_OMBAPTASK_ERROR_H

/////////////////////////////////////////////////////////////////////////////////////
// OMB OmbApTask Packet Status codes (Open Modbus TCP AP Task)
/////////////////////////////////////////////////////////////////////////////////////
//MessageId       = 0x0001
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB_AP
//SymbolicName    = TLR_E_OMB_OMBAPTASK_COMMAND_INVALID
//Language        = English
//Invalid command received.
//.
//Language        = German
//Ungultiges Kommando erhalten.
//.
//MessageId       = 0x0002
//Severity        = Information
//Facility        = TLR_UNQ_NR_OMB_OMB_AP
//SymbolicName    = TLR_I_OMB_OMBAPTASK_CONFIG_LOCK
//Language        = English
//Configuration is locked.
//.
//Language        = German
//Die Konfiguration ist gesperrt.
//.
//
// MessageId: TLR_E_OMB_OMBAPTASK_WATCHDOG_PARAMETER
//
// MessageText:
//
//  Invalid parameter for watchdog supervision.
//
#define TLR_E_OMB_OMBAPTASK_WATCHDOG_PARAMETER ((TLR_RESULT)0xC0610003L)

//
// MessageId: TLR_E_OMB_OMBAPTASK_WATCHDOG_ACTIVATE
//
// MessageText:
//
//  Failed to activate watchdog supervision.
//
#define TLR_E_OMB_OMBAPTASK_WATCHDOG_ACTIVATE ((TLR_RESULT)0xC0610004L)

//MessageId       = 0x0005
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB_AP
//SymbolicName    = TLR_E_OMB_OMBAPTASK_REQUEST_RUNNING
//Language        = English
//Request already running.
//.
//Language        = German
//Ein Befehl is bereits aktiv.
//.
//
// MessageId: TLR_E_OMB_OMBAPTASK_SYS_FLAG_PARAMETER
//
// MessageText:
//
//  Invalid parameter for system flags.
//
#define TLR_E_OMB_OMBAPTASK_SYS_FLAG_PARAMETER ((TLR_RESULT)0xC0610006L)

//
// MessageId: TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT
//
// MessageText:
//
//  Invalid Startup Parameter ulQueElemCnt.
//
#define TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT ((TLR_RESULT)0xC0610007L)

//
// MessageId: TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT
//
// MessageText:
//
//  Invalid Startup Parameter ulPoolElemCnt.
//
#define TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT ((TLR_RESULT)0xC0610008L)

//
// MessageId: TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_START_FLAGS
//
// MessageText:
//
//  Invalid Startup Parameter ulStartFlags.
//
#define TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_START_FLAGS ((TLR_RESULT)0xC0610009L)

//
// MessageId: TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_CHN_INST
//
// MessageText:
//
//  Invalid Startup Parameter ulChnInst.
//
#define TLR_E_OMB_OMBAPTASK_INVALID_STARTUP_PARAMETER_CHN_INST ((TLR_RESULT)0xC061000AL)

//
// MessageId: TLR_E_OMB_OMBAPTASK_FATAL_ERROR_OMB_TASK
//
// MessageText:
//
//  The OMB task reports a fatal error. System has stopped.
//  See extended status tMidCodeDiag for further information.
//
#define TLR_E_OMB_OMBAPTASK_FATAL_ERROR_OMB_TASK ((TLR_RESULT)0xC061000BL)

//
// MessageId: TLR_E_OMB_OMBAPTASK_COMMAND_EXCEEDS_DPM_SIZE
//
// MessageText:
//
//  The OMB task reports a fatal error. System has stopped.
//  See extended status tMidCodeDiag for further information.
//
#define TLR_E_OMB_OMBAPTASK_COMMAND_EXCEEDS_DPM_SIZE ((TLR_RESULT)0xC061000CL)

//
// MessageId: TLR_E_OMB_OMBAPTASK_COMMAND_OVERLAPED_DPM_OFFSET
//
// MessageText:
//
//  The OMB task reports a fatal error. System has stopped.
//  See extended status tMidCodeDiag for further information.
//
#define TLR_E_OMB_OMBAPTASK_COMMAND_OVERLAPED_DPM_OFFSET ((TLR_RESULT)0xC061000DL)

//
// MessageId: TLR_E_OMBAPTASK_COMMAND_NOT_ALLOWED_IN_CURRENT_MODE
//
// MessageText:
//
//  The OMB task reports a fatal error. The packet is not allowed to be sent.
//
#define TLR_E_OMBAPTASK_COMMAND_NOT_ALLOWED_IN_CURRENT_MODE ((TLR_RESULT)0xC061000EL)

//
// MessageId: TLR_E_OMBAPTASK_COMMAND_NOT_ALLOWED_IN_CURRENT_OMB_STATE
//
// MessageText:
//
//  The OMB task reports a fatal error. The packet is not allowed to be sent at this state.
//
#define TLR_E_OMBAPTASK_COMMAND_NOT_ALLOWED_IN_CURRENT_OMB_STATE ((TLR_RESULT)0xC061000FL)




#endif  //__OMB_OMBAPTASK_ERROR_H

