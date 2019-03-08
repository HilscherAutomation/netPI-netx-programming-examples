#ifndef __OMB_OMBTASK_ERROR_H
#define __OMB_OMBTASK_ERROR_H

/////////////////////////////////////////////////////////////////////////////////////
// OMB OmbTask Packet Status codes (Open Modbus TCP Task)
/////////////////////////////////////////////////////////////////////////////////////
// Initialization Error Codes
//MessageId       = 0x0001
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_COMMAND_INVALID
//Language        = English
//Invalid command received.
//.
//Language        = German
//Ungultiges Kommando erhalten.
//.
//
// MessageId: TLR_E_OMB_OMBTASK_SEND_IP_SET_CONFIG_FAILED
//
// MessageText:
//
//  Failed to forward the SET_CONFIG information to TCP_UDP task (because of a
//  resource problem).
//
#define TLR_E_OMB_OMBTASK_SEND_IP_SET_CONFIG_FAILED ((TLR_RESULT)0xC0600002L)

//
// MessageId: TLR_E_OMB_OMBTASK_SYSTEM_FUNCTION_CODE
//
// MessageText:
//
//  System error: Wrong function code.
//
#define TLR_E_OMB_OMBTASK_SYSTEM_FUNCTION_CODE ((TLR_RESULT)0xC0600003L)

//
// MessageId: TLR_E_OMB_OMBTASK_MOD_MEM_MOD_START_ADR
//
// MessageText:
//
//  IO mode: Wrong Modbus start address.
//
#define TLR_E_OMB_OMBTASK_MOD_MEM_MOD_START_ADR ((TLR_RESULT)0xC0600004L)

//
// MessageId: TLR_E_OMB_OMBTASK_MOD_MEM_LEN
//
// MessageText:
//
//  IO mode: Wrong length of Memory map.
//
#define TLR_E_OMB_OMBTASK_MOD_MEM_LEN    ((TLR_RESULT)0xC0600005L)

//
// MessageId: TLR_E_OMB_OMBTASK_MOD_MEM_START_MEM_OFF
//
// MessageText:
//
//  IO mode: Wrong Start byteoffset in Memory map.
//
#define TLR_E_OMB_OMBTASK_MOD_MEM_START_MEM_OFF ((TLR_RESULT)0xC0600006L)

//MessageId       = 0x00xx
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_MOD_MEM_ADR_AND_LEN
//Language        = English
//IO mode: Wrong Modbus start address in conjunction with the length of Memory map.
//.
//Language        = German
//IO-Mode: Falsche Modbus Startadresse in Verbindung mit der Laenge des Abbildspeichers.
//.
//
// MessageId: TLR_E_OMB_OMBTASK_MOD_MEM_SYSTEM_ERROR
//
// MessageText:
//
//  IO mode: System error.
//
#define TLR_E_OMB_OMBTASK_MOD_MEM_SYSTEM_ERROR ((TLR_RESULT)0xC0600007L)

//MessageId       = 0x00xx
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_TRIBUFF_INIT_BUFFER
//Language        = English
//The initialization of buffer has failed.
//.
//Language        = German
//Die Initialisierung der Puffer ist fehlgeschlagen.
//.
//
// MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT
//
// MessageText:
//
//  Invalid Startup Parameter ulQueElemCnt.
//
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT ((TLR_RESULT)0xC0600008L)

//
// MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT
//
// MessageText:
//
//  Invalid Startup Parameter ulPoolElemCnt.
//
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT ((TLR_RESULT)0xC0600009L)

//
// MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_START_FLAGS
//
// MessageText:
//
//  Invalid Startup Parameter ulStartFlags.
//
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_START_FLAGS ((TLR_RESULT)0xC060000AL)

//
// MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_CYCLE_EVENT
//
// MessageText:
//
//  Invalid Startup Parameter ulOmbCycleEvent.
//
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_CYCLE_EVENT ((TLR_RESULT)0xC060000BL)

//
// MessageId: TLR_E_OMB_OMBTASK_APPLICATION_TIMER_CREATE_FAILED
//
// MessageText:
//
//  Failed to create an application timer (Timer task).
//
#define TLR_E_OMB_OMBTASK_APPLICATION_TIMER_CREATE_FAILED ((TLR_RESULT)0xC060000CL)

//
// MessageId: TLR_E_OMB_OMBTASK_APPLICATION_TIMER_INIT_PACKET_FAILED
//
// MessageText:
//
//  Failed to initialize a packet of application timer (Timer task).
//
#define TLR_E_OMB_OMBTASK_APPLICATION_TIMER_INIT_PACKET_FAILED ((TLR_RESULT)0xC060000DL)

//
// MessageId: TLR_E_OMB_OMBTASK_TCP_UDP_IDENTIFY_FAILED
//
// MessageText:
//
//  Failed to identify the TCP_UDP task.
//
#define TLR_E_OMB_OMBTASK_TCP_UDP_IDENTIFY_FAILED ((TLR_RESULT)0xC060000EL)

//
// MessageId: TLR_E_OMB_OMBTASK_TCP_UDP_QUEUE_IDENTIFY_FAILED
//
// MessageText:
//
//  The queue identification of TCP_UDP task queue has failed.
//
#define TLR_E_OMB_OMBTASK_TCP_UDP_QUEUE_IDENTIFY_FAILED ((TLR_RESULT)0xC060000FL)

//
// MessageId: TLR_E_OMB_OMBTASK_BUFFER_QUEUE_CREATE_FAILED
//
// MessageText:
//
//  Creation of buffer queue failed.
//
#define TLR_E_OMB_OMBTASK_BUFFER_QUEUE_CREATE_FAILED ((TLR_RESULT)0xC0600010L)

//MessageId       = 0x0011
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_NOT_CONFIGURED
//Language        = English
//No configuration available.
//.
//Language        = German
//Keine Konfiguration vorhanden.
//.
//
// MessageId: TLR_E_OMB_OMBTASK_FLAGS_VALUE
//
// MessageText:
//
//  Invalid parameter 'Flags' (ulFlags).
//
#define TLR_E_OMB_OMBTASK_FLAGS_VALUE    ((TLR_RESULT)0xC0600012L)

// Initialization Error Codes (Numbers MessageId are compatible to old RCS errors)
//
// MessageId: TLR_E_OMB_OMBTASK_SERVER_CONNECT_VALUE
//
// MessageText:
//
//  Invalid parameter 'Open Server Sockets' (ulOpenServerSockets).
//
#define TLR_E_OMB_OMBTASK_SERVER_CONNECT_VALUE ((TLR_RESULT)0xC0600034L)

//
// MessageId: TLR_E_OMB_OMBTASK_ANSWER_TIMEOUT_VALUE
//
// MessageText:
//
//  Invalid parameter 'Answer Timeout' (ulAnswerTimeout).
//
#define TLR_E_OMB_OMBTASK_ANSWER_TIMEOUT_VALUE ((TLR_RESULT)0xC0600035L)

//
// MessageId: TLR_E_OMB_OMBTASK_OPEN_TIMEOUT_VALUE
//
// MessageText:
//
//  Invalid parameter 'Omb Open Time' (ulOmbOpenTime).
//
#define TLR_E_OMB_OMBTASK_OPEN_TIMEOUT_VALUE ((TLR_RESULT)0xC0600036L)

//
// MessageId: TLR_E_OMB_OMBTASK_MODE_VALUE
//
// MessageText:
//
//  Invalid parameter 'Mode' (ulMode).
//
#define TLR_E_OMB_OMBTASK_MODE_VALUE     ((TLR_RESULT)0xC0600037L)

//
// MessageId: TLR_E_OMB_OMBTASK_SEND_TIMEOUT_VALUE
//
// MessageText:
//
//  Invalid parameter 'Send Timeout' (ulSendTimeout).
//
#define TLR_E_OMB_OMBTASK_SEND_TIMEOUT_VALUE ((TLR_RESULT)0xC0600038L)

//
// MessageId: TLR_E_OMB_OMBTASK_CONNECT_TIMEOUT_VALUE
//
// MessageText:
//
//  Invalid parameter 'Connect Timeout' (ulConnectTimeout).
//
#define TLR_E_OMB_OMBTASK_CONNECT_TIMEOUT_VALUE ((TLR_RESULT)0xC0600039L)

//
// MessageId: TLR_E_OMB_OMBTASK_CLOSE_TIMEOUT_VALUE
//
// MessageText:
//
//  Invalid parameter 'Close Timeout' (ulCloseTimeout).
//
#define TLR_E_OMB_OMBTASK_CLOSE_TIMEOUT_VALUE ((TLR_RESULT)0xC060003AL)

//
// MessageId: TLR_E_OMB_OMBTASK_SWAB_VALUE
//
// MessageText:
//
//  Invalid parameter 'Swap' (ulSwap).
//
#define TLR_E_OMB_OMBTASK_SWAB_VALUE     ((TLR_RESULT)0xC060003BL)

//MessageId       = 60
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_ERR_INIT_TCP_TASK_NOT_READY
//Language        = English
//TCP_UDP task not ready.
//.
//Language        = German
//.
//.
//MessageId       = 61
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_ERR_INIT_PLC_TASK_NOT_READY
//Language        = English
//PLC task not found.
//.
//Language        = German
//.
//.
//MessageId       = 62
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_ERR_INIT_TASK_CONFIG
//Language        = English
//.
//.
//Language        = German
//.
//.
//MessageId       = 63
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_PLC_ERR_INIT_MODE
//Language        = English
//.
//.
//Language        = German
//.
//.
// Run-time Error Codes (Numbers MessageId are compatible to old RCS errors)
//MessageId       = 111
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_UNKNOWN_TX
//Language        = English
//.
//.
//Language        = German
//.
//.
//
// MessageId: TLR_E_OMB_OMBTASK_ERR_ANSWER
//
// MessageText:
//
//  TCP_UDP task answered with an error.
//
#define TLR_E_OMB_OMBTASK_ERR_ANSWER     ((TLR_RESULT)0xC0600070L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERR_STATE
//
// MessageText:
//
//  No socket in specific status found.
//
#define TLR_E_OMB_OMBTASK_ERR_STATE      ((TLR_RESULT)0xC0600071L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERR_VALUE
//
// MessageText:
//
//  Invalid value in command.
//
#define TLR_E_OMB_OMBTASK_ERR_VALUE      ((TLR_RESULT)0xC0600072L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERR_TCP_TASK_STATE
//
// MessageText:
//
//  Error in TCP_UDP task state.
//
#define TLR_E_OMB_OMBTASK_ERR_TCP_TASK_STATE ((TLR_RESULT)0xC0600073L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERR_MODBUS
//
// MessageText:
//
//  Error in Modbus telegram - for further information, see variable ulException in this chapter.
//
#define TLR_E_OMB_OMBTASK_ERR_MODBUS     ((TLR_RESULT)0xC0600074L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERR_NO_SOCKET
//
// MessageText:
//
//  No free and unused socket found.
//
#define TLR_E_OMB_OMBTASK_ERR_NO_SOCKET  ((TLR_RESULT)0xC0600075L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERR_UNKNOWN_SOCKET
//
// MessageText:
//
//  TCP_UDP command for an unknown socket received.
//
#define TLR_E_OMB_OMBTASK_ERR_UNKNOWN_SOCKET ((TLR_RESULT)0xC0600076L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERR_TIMEOUT
//
// MessageText:
//
//  The timeout for the Client-Job is expired. Timeout-Count starts after target has
//  received the command.
//
#define TLR_E_OMB_OMBTASK_ERR_TIMEOUT    ((TLR_RESULT)0xC0600077L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERR_UNEXPECTED_CLOSE
//
// MessageText:
//
//  Socket was unexpected closed.
//
#define TLR_E_OMB_OMBTASK_ERR_UNEXPECTED_CLOSE ((TLR_RESULT)0xC0600078L)

//
// MessageId: TLR_E_OMB_OMBTASK_USER_NOT_READY
//
// MessageText:
//
//  The User is not ready (not registered).
//
#define TLR_E_OMB_OMBTASK_USER_NOT_READY ((TLR_RESULT)0xC0600079L)

//
// MessageId: TLR_E_OMB_OMBTASK_NO_SOCKET_AVAILABLE
//
// MessageText:
//
//  OMB task is not able to open sockets (TCP_UDP task is not ready).
//
#define TLR_E_OMB_OMBTASK_NO_SOCKET_AVAILABLE ((TLR_RESULT)0xC060007AL)

//MessageId       = 123
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_WATCHDOG
//Language        = English
//Watchdog error.
//.
//Language        = German
//Watchdog-Fehler.
//.
//
// MessageId: TLR_E_OMB_OMBTASK_ERR_IP_CONFIG
//
// MessageText:
//
//  TCP_UDP task is in configuration status.
//
#define TLR_E_OMB_OMBTASK_ERR_IP_CONFIG  ((TLR_RESULT)0xC060007CL)

//
// MessageId: TLR_E_OMB_OMBTASK_PLC_TASK_NOT_INITIALIZED
//
// MessageText:
//
//  No Dualport-memory access.
//
#define TLR_E_OMB_OMBTASK_PLC_TASK_NOT_INITIALIZED ((TLR_RESULT)0xC060007DL)

//
// MessageId: TLR_E_OMB_OMBTASK_SEVER_SOCKET_CLOSED
//
// MessageText:
//
//  Server Socket was closed, before the answer is received.
//
#define TLR_E_OMB_OMBTASK_SEVER_SOCKET_CLOSED ((TLR_RESULT)0xC060007EL)

//MessageId       = 151
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_MESSAGESIZE
//Language        = English
//Invalid packet length detected.
//.
//Language        = German
//Falsche Packet-Lange.
//.
//
// MessageId: TLR_E_OMB_OMBTASK_DEVICE_ADR
//
// MessageText:
//
//  Invalid device address (IP address).
//
#define TLR_E_OMB_OMBTASK_DEVICE_ADR     ((TLR_RESULT)0xC06000A1L)

//
// MessageId: TLR_E_OMB_OMBTASK_DATA_CNT
//
// MessageText:
//
//  Invalid Data count.
//
#define TLR_E_OMB_OMBTASK_DATA_CNT       ((TLR_RESULT)0xC06000A5L)

//
// MessageId: TLR_E_OMB_OMBTASK_FUNCTION
//
// MessageText:
//
//  Wrong Function code. Function code is not supported.
//
#define TLR_E_OMB_OMBTASK_FUNCTION       ((TLR_RESULT)0xC06000A7L)

////////// New rxC error codes, starting with a value bigger than the RCS error codes = 255  //////////
///// General OMB errors 0x0100 ... 0x01FF (reserved) /////
//
// MessageId: TLR_E_OMB_OMBTASK_MOD_DATA_ADR
//
// MessageText:
//
//  IO mode: Wrong Modbus address. Modbus address is outside of Memory map.
//
#define TLR_E_OMB_OMBTASK_MOD_DATA_ADR   ((TLR_RESULT)0xC0600100L)

//
// MessageId: TLR_E_OMB_OMBTASK_MOD_DATA_CNT
//
// MessageText:
//
//  IO mode: Wrong Data count in conjunction with the Modbus address.
//  The access area is outside of Memory map.
//
#define TLR_E_OMB_OMBTASK_MOD_DATA_CNT   ((TLR_RESULT)0xC0600101L)

//
// MessageId: TLR_E_OMB_OMBTASK_MOD_FUNCTION_CODE
//
// MessageText:
//
//  IO mode: Wrong Function code. Function code is not supported.
//
#define TLR_E_OMB_OMBTASK_MOD_FUNCTION_CODE ((TLR_RESULT)0xC0600102L)

//
// MessageId: TLR_E_OMB_OMBTASK_MOD_DATA_TYPE
//
// MessageText:
//
//  IO mode: Wrong data type.
//
#define TLR_E_OMB_OMBTASK_MOD_DATA_TYPE  ((TLR_RESULT)0xC0600103L)

//
// MessageId: TLR_E_OMB_OMBTASK_MOD_BIT_AREA
//
// MessageText:
//
//  IO mode: Addressed coil is outside of the IO area.
//
#define TLR_E_OMB_OMBTASK_MOD_BIT_AREA   ((TLR_RESULT)0xC0600104L)

//MessageId       = 0x0105
//Severity        = Error
//Facility        = TLR_UNQ_NR_OMB_OMB
//SymbolicName    = TLR_E_OMB_OMBTASK_REQUEST_RUNNING
//Language        = English
//Request already running.
//.
//Language        = German
//Ein Befehl is bereits aktiv.
//.
//
// MessageId: TLR_E_OMB_OMBTASK_SEND_TCP_CONFIG_RELOAD_FAILED
//
// MessageText:
//
//  Failed to forward the configuration reload to TCP_UDP task (because of a
//  resource problem).
//
#define TLR_E_OMB_OMBTASK_SEND_TCP_CONFIG_RELOAD_FAILED ((TLR_RESULT)0xC0600106L)

//
// MessageId: TLR_E_OMB_OMBTASK_WRONG_CONFIG_RELOAD_STS
//
// MessageText:
//
//  Wrong configuration reload state.
//
#define TLR_E_OMB_OMBTASK_WRONG_CONFIG_RELOAD_STS ((TLR_RESULT)0xC0600107L)

//
// MessageId: TLR_E_OMB_OMBTASK_RESOURCE_OCCUPIED
//
// MessageText:
//
//  System error: The requestet resource is occupied.
//
#define TLR_E_OMB_OMBTASK_RESOURCE_OCCUPIED ((TLR_RESULT)0xC0600108L)

//
// MessageId: TLR_E_OMB_OMBTASK_AP_ALREADY_REGISTERED
//
// MessageText:
//
//  A application is already registered.
//
#define TLR_E_OMB_OMBTASK_AP_ALREADY_REGISTERED ((TLR_RESULT)0xC0600109L)

//
// MessageId: TLR_E_OMB_OMBTASK_AP_NOT_REGISTERED
//
// MessageText:
//
//  A application is not registered.
//
#define TLR_E_OMB_OMBTASK_AP_NOT_REGISTERED ((TLR_RESULT)0xC060010AL)

//
// MessageId: TLR_E_OMB_OMBTASK_START_STOP_MODE
//
// MessageText:
//
//  Wrong mode ulMode in command OMB_OMBTASK_CMD_START_STOP_OMB_REQ.
//
#define TLR_E_OMB_OMBTASK_START_STOP_MODE ((TLR_RESULT)0xC060010BL)

//
// MessageId: TLR_E_OMB_OMBTASK_START_STOP_STATE_CHANGE
//
// MessageText:
//
//  No senseful state change request (Start/stop) in command
//  OMB_OMBTASK_CMD_START_STOP_OMB_REQ.
//
#define TLR_E_OMB_OMBTASK_START_STOP_STATE_CHANGE ((TLR_RESULT)0xC060010CL)

//
// MessageId: TLR_E_OMB_OMBTASK_IO_MODE_COMMAND_INVALID
//
// MessageText:
//
//  IO mode:Invalid command received
//
#define TLR_E_OMB_OMBTASK_IO_MODE_COMMAND_INVALID ((TLR_RESULT)0xC060010DL)

//
// MessageId: TLR_E_OMB_OMBTASK_STATE_NOT_RUNNING
//
// MessageText:
//
//  The OMB stack is not in running state (Info status: ulTaskState is not
//  OMB_ST_TASK_RUNNING) or the Communication state is not operating
//  (ulCommunicationState is not RCX_COMM_STATE_OPERATE).
//
#define TLR_E_OMB_OMBTASK_STATE_NOT_RUNNING ((TLR_RESULT)0xC060010EL)

//
// MessageId: TLR_E_OMB_OMBTASK_MBAP_HEADER
//
// MessageText:
//
//  Wrong MBAP header received (Transaction Identifier, Protocol Identifier)
//
#define TLR_E_OMB_OMBTASK_MBAP_HEADER    ((TLR_RESULT)0xC060010FL)

//
// MessageId: TLR_E_OMB_OMBTASK_UNIT_ID
//
// MessageText:
//
//  Invalid Unit identifier (ulUnitId).
//
#define TLR_E_OMB_OMBTASK_UNIT_ID        ((TLR_RESULT)0xC0600110L)

//
// MessageId: TLR_E_OMB_OMBTASK_EXCEPTION
//
// MessageText:
//
//  Invalid Exception code (ulException).
//
#define TLR_E_OMB_OMBTASK_EXCEPTION      ((TLR_RESULT)0xC0600111L)

//
// MessageId: TLR_E_OMB_OMBTASK_MBAP_LENGTH
//
// MessageText:
//
//  Invalid MBAP header Length value.
//
#define TLR_E_OMB_OMBTASK_MBAP_LENGTH    ((TLR_RESULT)0xC0600112L)

//
// MessageId: TLR_E_OMB_OMBTASK_PDU_BYTE_COUNT
//
// MessageText:
//
//  Invalid PDU Byte count.
//
#define TLR_E_OMB_OMBTASK_PDU_BYTE_COUNT ((TLR_RESULT)0xC0600113L)

//
// MessageId: TLR_E_OMB_OMBTASK_PDU_REF_NUMBER
//
// MessageText:
//
//  Invalid PDU Reference Number (Starting Address).
//
#define TLR_E_OMB_OMBTASK_PDU_REF_NUMBER ((TLR_RESULT)0xC0600114L)

//
// MessageId: TLR_E_OMB_OMBTASK_PDU_DATA_CNT
//
// MessageText:
//
//  Invalid PDU Data count (Quantity).
//
#define TLR_E_OMB_OMBTASK_PDU_DATA_CNT   ((TLR_RESULT)0xC0600115L)

//
// MessageId: TLR_E_OMB_OMBTASK_PDU_VALUE
//
// MessageText:
//
//  Invalid PDU Value.
//
#define TLR_E_OMB_OMBTASK_PDU_VALUE      ((TLR_RESULT)0xC0600116L)

//
// MessageId: TLR_E_OMB_OMBTASK_DATA_ADR
//
// MessageText:
//
//  Wrong Modbus address. The Modbus address is outside of the Modbus Data model
//  (Range 0 ... 65535).
//
#define TLR_E_OMB_OMBTASK_DATA_ADR       ((TLR_RESULT)0xC0600117L)

//
// MessageId: TLR_E_OMB_OMBTASK_DATA_ADR_CNT
//
// MessageText:
//
//  Wrong Data count in conjunction with the Modbus address.
//  The access area is outside of the Modbus Data model (Range 0 ... 65535).
//
#define TLR_E_OMB_OMBTASK_DATA_ADR_CNT   ((TLR_RESULT)0xC0600118L)

//
// MessageId: TLR_E_OMB_OMBTASK_ERROR_DUE_TO_LIMITED_VERSION
//
// MessageText:
//
//  The operations is not possible due to limited version of the firmware.
//
#define TLR_E_OMB_OMBTASK_ERROR_DUE_TO_LIMITED_VERSION ((TLR_RESULT)0xC0600119L)

//
// MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_MAX_REGS_CNT
//
// MessageText:
//
//  The maximum defined coils does not fit into the DPM IO size.
//
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_MAX_REGS_CNT ((TLR_RESULT)0xC060011AL)

//
// MessageId: TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_MAX_COILS_CNT
//
// MessageText:
//
//  The maximum defined coils does not fit into the DPM IO size.
//
#define TLR_E_OMB_OMBTASK_INVALID_STARTUP_PARAMETER_OMB_MAX_COILS_CNT ((TLR_RESULT)0xC060011BL)

//
// MessageId: TLR_E_OMB_OMBTASK_INVALID_FUNCTION_PARAMETERS
//
// MessageText:
//
//  Any function has been called with invalid parameter.
//
#define TLR_E_OMB_OMBTASK_INVALID_FUNCTION_PARAMETERS ((TLR_RESULT)0xC060011CL)

//
// MessageId: TLR_E_OMB_PROCESS_DATA_WATCHDOG_TIME_EXPIRED
//
// MessageText:
//
//  The process data watchdog has expired.
//
#define TLR_E_OMB_PROCESS_DATA_WATCHDOG_TIME_EXPIRED ((TLR_RESULT)0xC060011DL)




#endif  //__OMB_OMBTASK_ERROR_H

