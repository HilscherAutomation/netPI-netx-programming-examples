/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: pns_error.h 66123 2016-12-14 12:44:37Z albantilatti $:

Description:
 PNSIF
 Includes PNSIF task error codes
**************************************************************************************/
#ifndef __PNS_ERROR_H
#define __PNS_ERROR_H




/////////////////////////////////////////////////////////////////////////////////////
// PROFINET IO-Device Interface Task
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_PNS_IF_COMMAND_INVALID
//
// MessageText:
//
//  Invalid command.
//
#define TLR_E_PNS_IF_COMMAND_INVALID     ((TLR_RESULT)0xC0300001L)

//
// MessageId: TLR_E_PNS_IF_OS_INIT_FAILED
//
// MessageText:
//
//  Initialization of PNS Operating system adapatation failed.
//
#define TLR_E_PNS_IF_OS_INIT_FAILED      ((TLR_RESULT)0xC0300002L)

//
// MessageId: TLR_E_PNS_IF_SET_INIT_IP_FAILED
//
// MessageText:
//
//  Initialization of PNS IP address failed.
//
#define TLR_E_PNS_IF_SET_INIT_IP_FAILED  ((TLR_RESULT)0xC0300003L)

//
// MessageId: TLR_E_PNS_IF_PNIO_SETUP_FAILED
//
// MessageText:
//
//  PROFINET IO-Device Setup failed.
//
#define TLR_E_PNS_IF_PNIO_SETUP_FAILED   ((TLR_RESULT)0xC0300004L)

//
// MessageId: TLR_E_PNS_IF_DEVICE_INFO_ALREADY_SET
//
// MessageText:
//
//  Device information set already.
//
#define TLR_E_PNS_IF_DEVICE_INFO_ALREADY_SET ((TLR_RESULT)0xC0300005L)

//
// MessageId: TLR_E_PNS_IF_SET_DEVICE_INFO_FAILED
//
// MessageText:
//
//  Setting of device information failed.
//
#define TLR_E_PNS_IF_SET_DEVICE_INFO_FAILED ((TLR_RESULT)0xC0300006L)

//
// MessageId: TLR_E_PNS_IF_NO_DEVICE_SETUP
//
// MessageText:
//
//  PROFINET IO-Device stack is not initialized. Send PNS_IF_SET_DEVICEINFO_REQ before PNS_IF_OPEN_DEVICE_REQ.
//
#define TLR_E_PNS_IF_NO_DEVICE_SETUP     ((TLR_RESULT)0xC0300007L)

//
// MessageId: TLR_E_PNS_IF_DEVICE_OPEN_FAILED
//
// MessageText:
//
//  Opening a device instance failed.
//
#define TLR_E_PNS_IF_DEVICE_OPEN_FAILED  ((TLR_RESULT)0xC0300008L)

//
// MessageId: TLR_E_PNS_IF_NO_DEVICE_INSTANCE
//
// MessageText:
//
//  No device instance open.
//
#define TLR_E_PNS_IF_NO_DEVICE_INSTANCE  ((TLR_RESULT)0xC0300009L)

//
// MessageId: TLR_E_PNS_IF_PLUG_MODULE_FAILED
//
// MessageText:
//
//  Plugging a module failed.
//
#define TLR_E_PNS_IF_PLUG_MODULE_FAILED  ((TLR_RESULT)0xC030000AL)

//
// MessageId: TLR_E_PNS_IF_PLUG_SUBMODULE_FAILED
//
// MessageText:
//
//  Plugging a submodule failed.
//
#define TLR_E_PNS_IF_PLUG_SUBMODULE_FAILED ((TLR_RESULT)0xC030000BL)

//
// MessageId: TLR_E_PNS_IF_DEVICE_START_FAILED
//
// MessageText:
//
//  Start of PROFINET IO-Device failed.
//
#define TLR_E_PNS_IF_DEVICE_START_FAILED ((TLR_RESULT)0xC030000CL)

//
// MessageId: TLR_E_PNS_IF_EDD_ENABLE_FAILED
//
// MessageText:
//
//  Start of network communication failed.
//
#define TLR_E_PNS_IF_EDD_ENABLE_FAILED   ((TLR_RESULT)0xC030000DL)

//
// MessageId: TLR_E_PNS_IF_ALLOC_MNGMNT_BUFFER_FAILED
//
// MessageText:
//
//  Allocation of a device instance management buffer failed.
//
#define TLR_E_PNS_IF_ALLOC_MNGMNT_BUFFER_FAILED ((TLR_RESULT)0xC030000EL)

//
// MessageId: TLR_E_PNS_IF_DEVICE_HANDLE_NULL
//
// MessageText:
//
//  Given device handle is NULL.
//
#define TLR_E_PNS_IF_DEVICE_HANDLE_NULL  ((TLR_RESULT)0xC030000FL)

//
// MessageId: TLR_E_PNS_IF_SET_APPL_READY_FAILED
//
// MessageText:
//
//  Command PNS_IF_SET_APPL_READY_REQ failed.
//
#define TLR_E_PNS_IF_SET_APPL_READY_FAILED ((TLR_RESULT)0xC0300010L)

//
// MessageId: TLR_E_PNS_IF_SET_DEVSTATE_FAILED
//
// MessageText:
//
//  Command PNS_IF_SET_DEVSTATE_REQ failed.
//
#define TLR_E_PNS_IF_SET_DEVSTATE_FAILED ((TLR_RESULT)0xC0300011L)

//
// MessageId: TLR_E_PNS_IF_PULL_SUBMODULE_FAILED
//
// MessageText:
//
//  Pulling the submodule failed.
//
#define TLR_E_PNS_IF_PULL_SUBMODULE_FAILED ((TLR_RESULT)0xC0300012L)

//
// MessageId: TLR_E_PNS_IF_PULL_MODULE_FAILED
//
// MessageText:
//
//  Pulling the module failed.
//
#define TLR_E_PNS_IF_PULL_MODULE_FAILED  ((TLR_RESULT)0xC0300013L)

//
// MessageId: TLR_E_PNS_IF_WRONG_DEST_ID
//
// MessageText:
//
//  Destination ID in command invalid.
//
#define TLR_E_PNS_IF_WRONG_DEST_ID       ((TLR_RESULT)0xC0300014L)

//
// MessageId: TLR_E_PNS_IF_DEVICE_HANDLE_INVALID
//
// MessageText:
//
//  Device Handle in command invalid.
//
#define TLR_E_PNS_IF_DEVICE_HANDLE_INVALID ((TLR_RESULT)0xC0300015L)

//
// MessageId: TLR_E_PNS_IF_CALLBACK_TIMEOUT
//
// MessageText:
//
//  PNS stack callback timeout.
//
#define TLR_E_PNS_IF_CALLBACK_TIMEOUT    ((TLR_RESULT)0xC0300016L)

//
// MessageId: TLR_E_PNS_IF_PACKET_POOL_EMPTY
//
// MessageText:
//
//  PNS_IF packet pool empty.
//
#define TLR_E_PNS_IF_PACKET_POOL_EMPTY   ((TLR_RESULT)0xC0300017L)

//
// MessageId: TLR_E_PNS_IF_ADD_API_FAILED
//
// MessageText:
//
//  Command PNS_IF_ADD_API_REQ failed.
//
#define TLR_E_PNS_IF_ADD_API_FAILED      ((TLR_RESULT)0xC0300018L)

//
// MessageId: TLR_E_PNS_IF_SET_SUB_STATE_FAILED
//
// MessageText:
//
//  Setting submodule state failed.
//
#define TLR_E_PNS_IF_SET_SUB_STATE_FAILED ((TLR_RESULT)0xC0300019L)

//
// MessageId: TLR_E_PNS_IF_NO_NW_DBM_ERROR
//
// MessageText:
//
//  No network configuration DBM-file.
//
#define TLR_E_PNS_IF_NO_NW_DBM_ERROR     ((TLR_RESULT)0xC030001AL)

//
// MessageId: TLR_E_PNS_IF_NW_SETUP_TABLE_ERROR
//
// MessageText:
//
//  Error during reading the "SETUP" table of the network configuration DBM-file .
//
#define TLR_E_PNS_IF_NW_SETUP_TABLE_ERROR ((TLR_RESULT)0xC030001BL)

//
// MessageId: TLR_E_PNS_IF_CFG_SETUP_TABLE_ERROR
//
// MessageText:
//
//  Error during reading the "SETUP" table of the config.xxx DBM-file .
//
#define TLR_E_PNS_IF_CFG_SETUP_TABLE_ERROR ((TLR_RESULT)0xC030001CL)

//
// MessageId: TLR_E_PNS_IF_NO_CFG_DBM_ERROR
//
// MessageText:
//
//  No config.xxx DBM-file.
//
#define TLR_E_PNS_IF_NO_CFG_DBM_ERROR    ((TLR_RESULT)0xC030001DL)

//
// MessageId: TLR_E_PNS_IF_DBM_DATASET_ERROR
//
// MessageText:
//
//  Error getting dataset pointer.
//
#define TLR_E_PNS_IF_DBM_DATASET_ERROR   ((TLR_RESULT)0xC030001EL)

//
// MessageId: TLR_E_PNS_IF_SETUPEX_TABLE_ERROR
//
// MessageText:
//
//  Error getting dataset pointer(SETUP_EX table).
//
#define TLR_E_PNS_IF_SETUPEX_TABLE_ERROR ((TLR_RESULT)0xC030001FL)

//
// MessageId: TLR_E_PNS_IF_AP_TABLE_ERROR
//
// MessageText:
//
//  Error getting either dataset pointer or number of datasets(AP table).
//
#define TLR_E_PNS_IF_AP_TABLE_ERROR      ((TLR_RESULT)0xC0300020L)

//
// MessageId: TLR_E_PNS_IF_MODULES_TABLE_ERROR
//
// MessageText:
//
//  Error getting either dataset pointer or number of datasets(MODULE table).
//
#define TLR_E_PNS_IF_MODULES_TABLE_ERROR ((TLR_RESULT)0xC0300021L)

//
// MessageId: TLR_E_PNS_IF_SUBMODULES_TABLE_ERROR
//
// MessageText:
//
//  Error getting either dataset pointer or number of datasets(SUBMODULE table).
//
#define TLR_E_PNS_IF_SUBMODULES_TABLE_ERROR ((TLR_RESULT)0xC0300022L)

//
// MessageId: TLR_E_PNS_IF_PNIO_SETUP_ERROR
//
// MessageText:
//
//  Error setting up PNIO configuration(PNIO_setup()).
//
#define TLR_E_PNS_IF_PNIO_SETUP_ERROR    ((TLR_RESULT)0xC0300023L)

//
// MessageId: TLR_E_PNS_IF_MODULES_GET_REC
//
// MessageText:
//
//  Error getting record of "MODULES" linked table.
//
#define TLR_E_PNS_IF_MODULES_GET_REC     ((TLR_RESULT)0xC0300024L)

//
// MessageId: TLR_E_PNS_IF_SUBMODULES_GET_REC
//
// MessageText:
//
//  Error getting record of "SUBMODULES" linked table.
//
#define TLR_E_PNS_IF_SUBMODULES_GET_REC  ((TLR_RESULT)0xC0300025L)

//
// MessageId: TLR_E_PNS_IF_PNIOD_MODULE_ID_TABLE_ERROR
//
// MessageText:
//
//  Error accessing "PNIOD_MODULE_ID" table or table record error.
//
#define TLR_E_PNS_IF_PNIOD_MODULE_ID_TABLE_ERROR ((TLR_RESULT)0xC0300026L)

//
// MessageId: TLR_E_PNS_IF_SIGNALS_TABLE_ERROR
//
// MessageText:
//
//  Error accessing "SIGNALS" table or table record error.
//
#define TLR_E_PNS_IF_SIGNALS_TABLE_ERROR ((TLR_RESULT)0xC0300027L)

//
// MessageId: TLR_E_PNS_IF_MODULES_IO_TABLE_ERROR
//
// MessageText:
//
//  Error accessing "MODULES_IO" table or table record error.
//
#define TLR_E_PNS_IF_MODULES_IO_TABLE_ERROR ((TLR_RESULT)0xC0300028L)

//
// MessageId: TLR_E_PNS_IF_CHANNEL_SETTING_TABLE_ERROR
//
// MessageText:
//
//  Error accessing "CHANNEL_SETTING" table or table record error.
//
#define TLR_E_PNS_IF_CHANNEL_SETTING_TABLE_ERROR ((TLR_RESULT)0xC0300029L)

//
// MessageId: TLR_E_PNS_IF_WRITE_DBM
//
// MessageText:
//
//  Error writing DBM-file.
//
#define TLR_E_PNS_IF_WRITE_DBM           ((TLR_RESULT)0xC030002AL)

//
// MessageId: TLR_E_PNS_IF_DPM_CONFIG
//
// MessageText:
//
//  No basic DPM configuration.
//
#define TLR_E_PNS_IF_DPM_CONFIG          ((TLR_RESULT)0xC030002BL)

//
// MessageId: TLR_E_PNS_IF_WATCHDOG
//
// MessageText:
//
//  Application did not trigger the watchdog.
//
#define TLR_E_PNS_IF_WATCHDOG            ((TLR_RESULT)0xC030002CL)

//
// MessageId: TLR_E_PNS_IF_SIGNALS_SUBMODULES
//
// MessageText:
//
//  Data length in "SIGNALS" table does not correspond to that in "SUBMODULES" table.
//
#define TLR_E_PNS_IF_SIGNALS_SUBMODULES  ((TLR_RESULT)0xC030002DL)

//
// MessageId: TLR_E_PNS_IF_READ_DPM_SUBAREA
//
// MessageText:
//
//  Failed to read DPM subarea.
//
#define TLR_E_PNS_IF_READ_DPM_SUBAREA    ((TLR_RESULT)0xC030002EL)

//
// MessageId: TLR_E_PNS_IF_MOD_0_SUB_1
//
// MessageText:
//
//  Error configuring Module 0 Submodule 1.
//
#define TLR_E_PNS_IF_MOD_0_SUB_1         ((TLR_RESULT)0xC030002FL)

//
// MessageId: TLR_E_PNS_IF_SIGNALS_LENGTH
//
// MessageText:
//
//  Length of I/O signals is bigger then the size of DPM subarea.
//
#define TLR_E_PNS_IF_SIGNALS_LENGTH      ((TLR_RESULT)0xC0300030L)

//
// MessageId: TLR_E_PNS_IF_SUB_TRANSFER_DIRECTION
//
// MessageText:
//
//  A submodule can not have input and outputs at the same time.
//
#define TLR_E_PNS_IF_SUB_TRANSFER_DIRECTION ((TLR_RESULT)0xC0300031L)

//
// MessageId: TLR_E_PNS_IF_FORMAT_PNVOLUME
//
// MessageText:
//
//  Error while formatting PNVOLUME.
//
#define TLR_E_PNS_IF_FORMAT_PNVOLUME     ((TLR_RESULT)0xC0300032L)

//
// MessageId: TLR_E_PNS_IF_MOUNT_PNVOLUME
//
// MessageText:
//
//  Error while mounting PNVOLUME.
//
#define TLR_E_PNS_IF_MOUNT_PNVOLUME      ((TLR_RESULT)0xC0300033L)

//
// MessageId: TLR_E_PNS_IF_INIT_REMOTE
//
// MessageText:
//
//  Error during initialization of the remote resources of the stack.
//
#define TLR_E_PNS_IF_INIT_REMOTE         ((TLR_RESULT)0xC0300034L)

//
// MessageId: TLR_E_PNS_IF_WARMSTART_CONFIG_REDUNDANT
//
// MessageText:
//
//  Warmstart parameters are redundant. The stack was configured with DBM or packets.
//
#define TLR_E_PNS_IF_WARMSTART_CONFIG_REDUNDANT ((TLR_RESULT)0xC0300035L)

//
// MessageId: TLR_E_PNS_IF_WARMSTART_PARAMETER
//
// MessageText:
//
//  Incorrect warmstart parameter(s).
//
#define TLR_E_PNS_IF_WARMSTART_PARAMETER ((TLR_RESULT)0xC0300036L)

//
// MessageId: TLR_E_PNS_IF_SET_APPL_STATE_READY
//
// MessageText:
//
//  PNIO_set_appl_state_ready() returns error.
//
#define TLR_E_PNS_IF_SET_APPL_STATE_READY ((TLR_RESULT)0xC0300037L)

//
// MessageId: TLR_E_PNS_IF_SET_DEV_STATE
//
// MessageText:
//
//  PNIO_set_dev_state() returns error.
//
#define TLR_E_PNS_IF_SET_DEV_STATE       ((TLR_RESULT)0xC0300038L)

//
// MessageId: TLR_E_PNS_IF_PROCESS_ALARM_SEND
//
// MessageText:
//
//  PNIO_process_alarm_send() returns error.
//
#define TLR_E_PNS_IF_PROCESS_ALARM_SEND  ((TLR_RESULT)0xC0300039L)

//
// MessageId: TLR_E_PNS_IF_RET_OF_SUB_ALARM_SEND
//
// MessageText:
//
//  PNIO_ret_of_sub_alarm_send() returns error.
//
#define TLR_E_PNS_IF_RET_OF_SUB_ALARM_SEND ((TLR_RESULT)0xC030003AL)

//
// MessageId: TLR_E_PNS_IF_DIAG_ALARM_SEND
//
// MessageText:
//
//  PNIO_diag_alarm_send() returns error.
//
#define TLR_E_PNS_IF_DIAG_ALARM_SEND     ((TLR_RESULT)0xC030003BL)

//
// MessageId: TLR_E_PNS_IF_DIAG_GENERIC_ADD
//
// MessageText:
//
//  PNIO_diag_generic_add() returns error.
//
#define TLR_E_PNS_IF_DIAG_GENERIC_ADD    ((TLR_RESULT)0xC030003CL)

//
// MessageId: TLR_E_PNS_IF_DIAG_GENERIC_REMOVE
//
// MessageText:
//
//  PNIO_diag_generic_remove() returns error.
//
#define TLR_E_PNS_IF_DIAG_GENERIC_REMOVE ((TLR_RESULT)0xC030003DL)

//
// MessageId: TLR_E_PNS_IF_DIAG_CHANNEL_ADD
//
// MessageText:
//
//  PNIO_diag_channel_add() returns error.
//
#define TLR_E_PNS_IF_DIAG_CHANNEL_ADD    ((TLR_RESULT)0xC030003EL)

//
// MessageId: TLR_E_PNS_IF_DIAG_CHANNEL_REMOVE
//
// MessageText:
//
//  PNIO_diag_channel_remove() returns error.
//
#define TLR_E_PNS_IF_DIAG_CHANNEL_REMOVE ((TLR_RESULT)0xC030003FL)

//
// MessageId: TLR_E_PNS_IF_EXT_DIAG_CHANNEL_ADD
//
// MessageText:
//
//  PNIO_ext_diag_channel_add() returns error.
//
#define TLR_E_PNS_IF_EXT_DIAG_CHANNEL_ADD ((TLR_RESULT)0xC0300040L)

//
// MessageId: TLR_E_PNS_IF_EXT_DIAG_CHANNEL_REMOVE
//
// MessageText:
//
//  PNIO_ext_diag_channel_remove() returns error.
//
#define TLR_E_PNS_IF_EXT_DIAG_CHANNEL_REMOVE ((TLR_RESULT)0xC0300041L)

//
// MessageId: TLR_E_PNS_IF_STATION_NAME_LEN
//
// MessageText:
//
//  Parameter station name length is incorrect.
//
#define TLR_E_PNS_IF_STATION_NAME_LEN    ((TLR_RESULT)0xC0300042L)

//
// MessageId: TLR_E_PNS_IF_STATION_NAME
//
// MessageText:
//
//  Parameter station name is incorrect.
//
#define TLR_E_PNS_IF_STATION_NAME        ((TLR_RESULT)0xC0300043L)

//
// MessageId: TLR_E_PNS_IF_STATION_TYPE_LEN
//
// MessageText:
//
//  Parameter station type length is incorrect.
//
#define TLR_E_PNS_IF_STATION_TYPE_LEN    ((TLR_RESULT)0xC0300044L)

//
// MessageId: TLR_E_PNS_IF_DEVICE_TYPE
//
// MessageText:
//
//  Parameter device type is incorrect.
//
#define TLR_E_PNS_IF_DEVICE_TYPE         ((TLR_RESULT)0xC0300045L)

//
// MessageId: TLR_E_PNS_IF_ORDER_ID
//
// MessageText:
//
//  Parameter order id is incorrect.
//
#define TLR_E_PNS_IF_ORDER_ID            ((TLR_RESULT)0xC0300046L)

//
// MessageId: TLR_E_PNS_IF_INPUT_STATUS
//
// MessageText:
//
//  Parameter input data status bytes length is incorrect.
//
#define TLR_E_PNS_IF_INPUT_STATUS        ((TLR_RESULT)0xC0300047L)

//
// MessageId: TLR_E_PNS_IF_OUTPUT_STATUS
//
// MessageText:
//
//  Parameter output data status bytes length is incorrect.
//
#define TLR_E_PNS_IF_OUTPUT_STATUS       ((TLR_RESULT)0xC0300048L)

//
// MessageId: TLR_E_PNS_IF_WATCHDOG_PARAMETER
//
// MessageText:
//
//  Parameter watchdog timing is incorrect(must be >= 10).
//
#define TLR_E_PNS_IF_WATCHDOG_PARAMETER  ((TLR_RESULT)0xC0300049L)

//
// MessageId: TLR_E_PNS_IF_OUT_UPDATE
//
// MessageText:
//
//  Parameter output data update timing is incorrect.
//
#define TLR_E_PNS_IF_OUT_UPDATE          ((TLR_RESULT)0xC030004AL)

//
// MessageId: TLR_E_PNS_IF_IN_UPDATE
//
// MessageText:
//
//  Parameter input data update timing is incorrect.
//
#define TLR_E_PNS_IF_IN_UPDATE           ((TLR_RESULT)0xC030004BL)

//
// MessageId: TLR_E_PNS_IF_IN_SIZE
//
// MessageText:
//
//  Parameter input memory area size is incorrect.
//
#define TLR_E_PNS_IF_IN_SIZE             ((TLR_RESULT)0xC030004CL)

//
// MessageId: TLR_E_PNS_IF_OUT_SIZE
//
// MessageText:
//
//  Parameter output memory area size is incorrect.
//
#define TLR_E_PNS_IF_OUT_SIZE            ((TLR_RESULT)0xC030004DL)

//
// MessageId: TLR_E_PNS_IF_GLOBAL_RESOURCES
//
// MessageText:
//
//  Unable to allocate memory for global access to local resources.
//
#define TLR_E_PNS_IF_GLOBAL_RESOURCES    ((TLR_RESULT)0xC030004EL)

//
// MessageId: TLR_E_PNS_IF_DYNAMIC_CFG_PCK
//
// MessageText:
//
//  Unable to allocate memory for dynamic configuration packet.
//
#define TLR_E_PNS_IF_DYNAMIC_CFG_PCK     ((TLR_RESULT)0xC030004FL)

//
// MessageId: TLR_E_PNS_IF_DEVICE_STOP
//
// MessageText:
//
//  Unable to stop device.
//
#define TLR_E_PNS_IF_DEVICE_STOP         ((TLR_RESULT)0xC0300050L)

//
// MessageId: TLR_E_PNS_IF_DEVICE_ID
//
// MessageText:
//
//  Parameter device id is incorrect.
//
#define TLR_E_PNS_IF_DEVICE_ID           ((TLR_RESULT)0xC0300051L)

//
// MessageId: TLR_E_PNS_IF_VENDOR_ID
//
// MessageText:
//
//  Parameter vendor id is incorrect.
//
#define TLR_E_PNS_IF_VENDOR_ID           ((TLR_RESULT)0xC0300052L)

//
// MessageId: TLR_E_PNS_IF_SYS_START
//
// MessageText:
//
//  Parameter system start is incorrect.
//
#define TLR_E_PNS_IF_SYS_START           ((TLR_RESULT)0xC0300053L)

//
// MessageId: TLR_E_PNS_IF_DYN_CFG_IO_LENGTH
//
// MessageText:
//
//  The length of IO data expected by the controller exceeds the limit specified in warmstart parameters.
//
#define TLR_E_PNS_IF_DYN_CFG_IO_LENGTH   ((TLR_RESULT)0xC0300054L)

//
// MessageId: TLR_E_PNS_IF_DYN_CFG_MOD_NUM
//
// MessageText:
//
//  The count of the IO modules expected by the controller exceeds the supported by the stack count.
//
#define TLR_E_PNS_IF_DYN_CFG_MOD_NUM     ((TLR_RESULT)0xC0300055L)

//
// MessageId: TLR_E_PNS_IF_ACCESS_LOCAL_RSC
//
// MessageText:
//
//  No global access to local resources.
//
#define TLR_E_PNS_IF_ACCESS_LOCAL_RSC    ((TLR_RESULT)0xC0300056L)

//
// MessageId: TLR_E_PNS_IF_PULL_PLUG
//
// MessageText:
//
//  Plugging and pulling modules during creation of communication is not allowed.
//
#define TLR_E_PNS_IF_PULL_PLUG           ((TLR_RESULT)0xC0300057L)

//
// MessageId: TLR_E_PNS_IF_AR_NUM
//
// MessageText:
//
//  Maximum number of ARs is 1.
//
#define TLR_E_PNS_IF_AR_NUM              ((TLR_RESULT)0xC0300058L)

//
// MessageId: TLR_E_PNS_IF_API_NUM
//
// MessageText:
//
//  Only API = 0 is supported.
//
#define TLR_E_PNS_IF_API_NUM             ((TLR_RESULT)0xC0300059L)

//
// MessageId: TLR_E_PNS_IF_ALREADY_OPEN
//
// MessageText:
//
//  Device is already opened.
//
#define TLR_E_PNS_IF_ALREADY_OPEN        ((TLR_RESULT)0xC030005AL)

//
// MessageId: TLR_E_PNS_IF_API_ADDED
//
// MessageText:
//
//  Application is already added.
//
#define TLR_E_PNS_IF_API_ADDED           ((TLR_RESULT)0xC030005BL)

//
// MessageId: TLR_E_PNS_IF_CONFIG_MODE
//
// MessageText:
//
//  Configuration modes should not be mixed( DBM-files,application,warmstart message ).
//
#define TLR_E_PNS_IF_CONFIG_MODE         ((TLR_RESULT)0xC030005CL)

//
// MessageId: TLR_E_PNS_IF_UNK_LED_MODE
//
// MessageText:
//
//  Unknown LED mode.
//
#define TLR_E_PNS_IF_UNK_LED_MODE        ((TLR_RESULT)0xC030005DL)

//
// MessageId: TLR_E_PNS_IF_PHYSICAL_LINK
//
// MessageText:
//
//  Physical link rate is less then 100 Mbit.
//
#define TLR_E_PNS_IF_PHYSICAL_LINK       ((TLR_RESULT)0xC030005EL)

//
// MessageId: TLR_E_PNS_IF_MAX_SLOT_SUBSLOT
//
// MessageText:
//
//  Number of slots or subslots too big.
//
#define TLR_E_PNS_IF_MAX_SLOT_SUBSLOT    ((TLR_RESULT)0xC030005FL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_MEM
//
// MessageText:
//
//  AR error. Out of memory.
//
#define TLR_E_PNS_IF_AR_REASON_MEM       ((TLR_RESULT)0xC0300060L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_FRAME
//
// MessageText:
//
//  AR error. Add provider or consumer failed.
//
#define TLR_E_PNS_IF_AR_REASON_FRAME     ((TLR_RESULT)0xC0300061L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_MISS
//
// MessageText:
//
//  AR error. Consumer missing.
//
#define TLR_E_PNS_IF_AR_REASON_MISS      ((TLR_RESULT)0xC0300062L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_TIMER
//
// MessageText:
//
//  AR error. CMI timeout.
//
#define TLR_E_PNS_IF_AR_REASON_TIMER     ((TLR_RESULT)0xC0300063L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_ALARM
//
// MessageText:
//
//  AR error. Alarm open failed.
//
#define TLR_E_PNS_IF_AR_REASON_ALARM     ((TLR_RESULT)0xC0300064L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_ALSND
//
// MessageText:
//
//  AR error. Alarm send confirmation failed.
//
#define TLR_E_PNS_IF_AR_REASON_ALSND     ((TLR_RESULT)0xC0300065L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_ALACK
//
// MessageText:
//
//  AR error. Alarm acknowledge send confirmation failed.
//
#define TLR_E_PNS_IF_AR_REASON_ALACK     ((TLR_RESULT)0xC0300066L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_ALLEN
//
// MessageText:
//
//  AR error. Alarm data too long.
//
#define TLR_E_PNS_IF_AR_REASON_ALLEN     ((TLR_RESULT)0xC0300067L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_ASRT
//
// MessageText:
//
//  AR error. Alarm indication error.
//
#define TLR_E_PNS_IF_AR_REASON_ASRT      ((TLR_RESULT)0xC0300068L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_RPC
//
// MessageText:
//
//  AR error. RPC client call confirmation failed.
//
#define TLR_E_PNS_IF_AR_REASON_RPC       ((TLR_RESULT)0xC0300069L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_ABORT
//
// MessageText:
//
//  AR error. Abort request.
//
#define TLR_E_PNS_IF_AR_REASON_ABORT     ((TLR_RESULT)0xC030006AL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_RERUN
//
// MessageText:
//
//  AR error. Re-Run.
//
#define TLR_E_PNS_IF_AR_REASON_RERUN     ((TLR_RESULT)0xC030006BL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_REL
//
// MessageText:
//
//  AR error. Release indication received.
//
#define TLR_E_PNS_IF_AR_REASON_REL       ((TLR_RESULT)0xC030006CL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_PAS
//
// MessageText:
//
//  AR error. Device deactivated.
//
#define TLR_E_PNS_IF_AR_REASON_PAS       ((TLR_RESULT)0xC030006DL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_RMV
//
// MessageText:
//
//  AR error. Device/ar removed.
//
#define TLR_E_PNS_IF_AR_REASON_RMV       ((TLR_RESULT)0xC030006EL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_PROT
//
// MessageText:
//
//  AR error. Protocol violation.
//
#define TLR_E_PNS_IF_AR_REASON_PROT      ((TLR_RESULT)0xC030006FL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_NARE
//
// MessageText:
//
//  AR error. NARE error.
//
#define TLR_E_PNS_IF_AR_REASON_NARE      ((TLR_RESULT)0xC0300070L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_BIND
//
// MessageText:
//
//  AR error. RPC-Bind error.
//
#define TLR_E_PNS_IF_AR_REASON_BIND      ((TLR_RESULT)0xC0300071L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_CONNECT
//
// MessageText:
//
//  AR error. RPC-Connect error.
//
#define TLR_E_PNS_IF_AR_REASON_CONNECT   ((TLR_RESULT)0xC0300072L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_READ
//
// MessageText:
//
//  AR error. RPC-Read error.
//
#define TLR_E_PNS_IF_AR_REASON_READ      ((TLR_RESULT)0xC0300073L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_WRITE
//
// MessageText:
//
//  AR error. RPC-Write error.
//
#define TLR_E_PNS_IF_AR_REASON_WRITE     ((TLR_RESULT)0xC0300074L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_CONTROL
//
// MessageText:
//
//  AR error. RPC-Control error.
//
#define TLR_E_PNS_IF_AR_REASON_CONTROL   ((TLR_RESULT)0xC0300075L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_UNKNOWN
//
// MessageText:
//
//  AR error. Unknown.
//
#define TLR_E_PNS_IF_AR_REASON_UNKNOWN   ((TLR_RESULT)0xC0300076L)

//
// MessageId: TLR_E_PNS_IF_INIT_WATCHDOG
//
// MessageText:
//
//  Watchdog initialization failed.
//
#define TLR_E_PNS_IF_INIT_WATCHDOG       ((TLR_RESULT)0xC0300077L)

//
// MessageId: TLR_E_PNS_IF_NO_PHYSICAL_LINK
//
// MessageText:
//
//  The Device is not connected to a network.
//
#define TLR_E_PNS_IF_NO_PHYSICAL_LINK    ((TLR_RESULT)0xC0300078L)

//
// MessageId: TLR_DPM_CYCLIC_IO_RW
//
// MessageText:
//
//  Failed to copy from DPM or to DPM the cyclic IO data.
//
#define TLR_DPM_CYCLIC_IO_RW             ((TLR_RESULT)0xC0300079L)

//
// MessageId: TLR_E_PNS_IF_SUBMODULE
//
// MessageText:
//
//  Submodule number is wrong.
//
#define TLR_E_PNS_IF_SUBMODULE           ((TLR_RESULT)0xC030007AL)

//
// MessageId: TLR_E_PNS_IF_MODULE
//
// MessageText:
//
//  Module number is wrong.
//
#define TLR_E_PNS_IF_MODULE              ((TLR_RESULT)0xC030007BL)

//
// MessageId: TLR_E_PNS_IF_NO_AR
//
// MessageText:
//
//  The AR was closed or the AR handle is not valid.
//
#define TLR_E_PNS_IF_NO_AR               ((TLR_RESULT)0xC030007CL)

//
// MessageId: TLR_E_PNS_IF_WRITE_REC_RES_TIMEOUT
//
// MessageText:
//
//  Timeout while waiting for response to write_record_indication.
//
#define TLR_E_PNS_IF_WRITE_REC_RES_TIMEOUT ((TLR_RESULT)0xC030007DL)

//
// MessageId: TLR_E_PNS_IF_UNREGISTERED_SENDER
//
// MessageText:
//
//  The sender of the request in not registered with request PNS_IF_REGISTER_AP_REQ.
//
#define TLR_E_PNS_IF_UNREGISTERED_SENDER ((TLR_RESULT)0xC030007EL)

//
// MessageId: TLR_E_PNS_IF_RECORD_HANDLE_INVALID
//
// MessageText:
//
//  Unknown record handle.
//
#define TLR_E_PNS_IF_RECORD_HANDLE_INVALID ((TLR_RESULT)0xC030007FL)

//
// MessageId: TLR_E_PNS_IF_REGISTER_AP
//
// MessageText:
//
//  Another instance is registered at the moment.
//
#define TLR_E_PNS_IF_REGISTER_AP         ((TLR_RESULT)0xC0300080L)

//
// MessageId: TLR_E_PNS_IF_UNREGISTER_AP
//
// MessageText:
//
//  One instance can not unregister another one.
//
#define TLR_E_PNS_IF_UNREGISTER_AP       ((TLR_RESULT)0xC0300081L)

//
// MessageId: TLR_E_PNS_IF_CONFIG_DIFFER
//
// MessageText:
//
//  The Must-configuration differs from the Is-configuration.
//
#define TLR_E_PNS_IF_CONFIG_DIFFER       ((TLR_RESULT)0xC0300082L)

//
// MessageId: TLR_E_PNS_IF_NO_COMMUNICATION
//
// MessageText:
//
//  No communication processing.
//
#define TLR_E_PNS_IF_NO_COMMUNICATION    ((TLR_RESULT)0xC0300083L)

//
// MessageId: TLR_E_PNS_IF_BAD_PARAMETER
//
// MessageText:
//
//  At least one parameter in a packet was wrong or/and did not meet the requirements.
//
#define TLR_E_PNS_IF_BAD_PARAMETER       ((TLR_RESULT)0xC0300084L)

//
// MessageId: TLR_E_PNS_IF_AREA_OVERFLOW
//
// MessageText:
//
//  Input or Output data requires more space than available.
//
#define TLR_E_PNS_IF_AREA_OVERFLOW       ((TLR_RESULT)0xC0300085L)

//
// MessageId: TLR_E_PNS_IF_WRM_PCK_SAVE
//
// MessageText:
//
//  Saving Warmstart Configuration for later use was not successful.
//
#define TLR_E_PNS_IF_WRM_PCK_SAVE        ((TLR_RESULT)0xC0300086L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_PULLPLUG
//
// MessageText:
//
//  AR error. Pull and Plug are forbidden after check.rsp and before in-data.ind.
//
#define TLR_E_PNS_IF_AR_REASON_PULLPLUG  ((TLR_RESULT)0xC0300087L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_AP_RMV
//
// MessageText:
//
//  AR error. AP has been removed.
//
#define TLR_E_PNS_IF_AR_REASON_AP_RMV    ((TLR_RESULT)0xC0300088L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_LNK_DWN
//
// MessageText:
//
//  AR error. Link "down".
//
#define TLR_E_PNS_IF_AR_REASON_LNK_DWN   ((TLR_RESULT)0xC0300089L)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_MMAC
//
// MessageText:
//
//  AR error. Could not register multicast-MAC.
//
#define TLR_E_PNS_IF_AR_REASON_MMAC      ((TLR_RESULT)0xC030008AL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_SYNC
//
// MessageText:
//
//  AR error. Not synchronised(Cannot start companion-AR).
//
#define TLR_E_PNS_IF_AR_REASON_SYNC      ((TLR_RESULT)0xC030008BL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_TOPO
//
// MessageText:
//
//  AR error. Wrong topology(Cannot start companion-AR).
//
#define TLR_E_PNS_IF_AR_REASON_TOPO      ((TLR_RESULT)0xC030008CL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_DCP_NAME
//
// MessageText:
//
//  AR error. DCP. Station Name changed.
//
#define TLR_E_PNS_IF_AR_REASON_DCP_NAME  ((TLR_RESULT)0xC030008DL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_DCP_RESET
//
// MessageText:
//
//  AR error. DCP. Reset to factory-settings.
//
#define TLR_E_PNS_IF_AR_REASON_DCP_RESET ((TLR_RESULT)0xC030008EL)

//
// MessageId: TLR_E_PNS_IF_AR_REASON_PRM
//
// MessageText:
//
//  AR error. Cannot start companion-AR because a 0x8ipp submodule in the first AR /has appl-ready-pending/ is locked/ is wrong or pulled/ .
//
#define TLR_E_PNS_IF_AR_REASON_PRM       ((TLR_RESULT)0xC030008FL)

//
// MessageId: TLR_E_PNS_IF_PACKET_MNGMNT
//
// MessageText:
//
//  Packet management error.
//
#define TLR_E_PNS_IF_PACKET_MNGMNT       ((TLR_RESULT)0xC0300090L)

//
// MessageId: TLR_E_PNS_IF_WRONG_API_NUM
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_WRONG_API_NUM       ((TLR_RESULT)0xC0300091L)

//
// MessageId: TLR_E_PNS_IF_WRONG_MODULE_ID
//
// MessageText:
//
//  d.
//
#define TLR_E_PNS_IF_WRONG_MODULE_ID     ((TLR_RESULT)0xC0300092L)

//
// MessageId: TLR_E_PNS_IF_WRONG_MODULE_NUM
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_WRONG_MODULE_NUM    ((TLR_RESULT)0xC0300093L)

//
// MessageId: TLR_E_PNS_IF_UNS_AREA
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_UNS_AREA            ((TLR_RESULT)0xC0300094L)

//
// MessageId: TLR_E_PNS_IF_WRONG_SUB_ID
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_WRONG_SUB_ID        ((TLR_RESULT)0xC0300095L)

//
// MessageId: TLR_E_PNS_IF_WRONG_SUBMODULE_NUM
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_WRONG_SUBMODULE_NUM ((TLR_RESULT)0xC0300096L)

//
// MessageId: TLR_E_PNS_IF_DEVICE_STOP_FAILED
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_DEVICE_STOP_FAILED  ((TLR_RESULT)0xC0300097L)

//
// MessageId: TLR_E_PNS_IF_EDD_DISABLE_FAILED
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_EDD_DISABLE_FAILED  ((TLR_RESULT)0xC0300098L)

//
// MessageId: TLR_E_PNS_IF_WRITE_IN
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_WRITE_IN            ((TLR_RESULT)0xC0300099L)

//
// MessageId: TLR_E_PNS_IF_READ_OUT
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_READ_OUT            ((TLR_RESULT)0xC030009AL)

//
// MessageId: TLR_E_PNS_IF_PNIO_STATUS
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_PNIO_STATUS         ((TLR_RESULT)0xC030009BL)

//
// MessageId: TLR_E_PNS_IF_WRONG_MODULE_ADDRESS
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_WRONG_MODULE_ADDRESS ((TLR_RESULT)0xC030009CL)

//
// MessageId: TLR_E_PNS_IF_UNK_DEVICE_STATE
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_UNK_DEVICE_STATE    ((TLR_RESULT)0xC030009DL)

//
// MessageId: TLR_E_PNS_IF_ALARM_DATA_LEN
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_ALARM_DATA_LEN      ((TLR_RESULT)0xC030009EL)

//
// MessageId: TLR_E_PNS_IF_UNK_SUBMODULE_STATE
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_UNK_SUBMODULE_STATE ((TLR_RESULT)0xC030009FL)

//
// MessageId: TLR_E_PNS_IF_BAD_DIAG_HANDLE
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_BAD_DIAG_HANDLE     ((TLR_RESULT)0xC03000A0L)

//
// MessageId: TLR_E_PNS_IF_UNS_STRUCT_ID
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_UNS_STRUCT_ID       ((TLR_RESULT)0xC03000A1L)

//
// MessageId: TLR_E_PNS_IF_UNK_ALARM_STATE
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_UNK_ALARM_STATE     ((TLR_RESULT)0xC03000A2L)

//
// MessageId: TLR_E_PNS_IF_DIAG_DATA_LEN
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_DIAG_DATA_LEN       ((TLR_RESULT)0xC03000A3L)

//
// MessageId: TLR_E_PNS_IF_BAD_CHANNEL_ERR_TYPE
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_BAD_CHANNEL_ERR_TYPE ((TLR_RESULT)0xC03000A4L)

//
// MessageId: TLR_E_PNS_IF_BAD_CHANNEL_PROP
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_BAD_CHANNEL_PROP    ((TLR_RESULT)0xC03000A5L)

//
// MessageId: TLR_E_PNS_IF_BAD_CHANNEL_NUM
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_BAD_CHANNEL_NUM     ((TLR_RESULT)0xC03000A6L)

//
// MessageId: TLR_E_PNS_IF_RCX_RESTART
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_RCX_RESTART         ((TLR_RESULT)0xC03000A7L)

//
// MessageId: TLR_E_PNS_IF_CFG_MNGMNT
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_CFG_MNGMNT          ((TLR_RESULT)0xC03000A8L)

//
// MessageId: TLR_E_PNS_IF_UNK_INTERN_REQ
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_UNK_INTERN_REQ      ((TLR_RESULT)0xC03000A9L)

//
// MessageId: TLR_E_PNS_IF_CFG_STORE
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_CFG_STORE           ((TLR_RESULT)0xC03000AAL)

//
// MessageId: TLR_E_PNS_IF_CFG_DELETE_FAILED
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_CFG_DELETE_FAILED   ((TLR_RESULT)0xC03000ABL)

//
// MessageId: TLR_E_PNS_IF_READ_CFG
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_READ_CFG            ((TLR_RESULT)0xC03000ACL)

//
// MessageId: TLR_E_PNS_IF_ACCESS_SYS_VOLUME
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_ACCESS_SYS_VOLUME   ((TLR_RESULT)0xC03000ADL)

//
// MessageId: TLR_E_PNS_IF_ACCESS_BCKUP_VOLUME
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_ACCESS_BCKUP_VOLUME ((TLR_RESULT)0xC03000AEL)

//
// MessageId: TLR_E_PNS_IF_CFG_BAD_LEN
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_CFG_BAD_LEN         ((TLR_RESULT)0xC03000AFL)

//
// MessageId: TLR_E_PNS_IF_WRM_CFG_MNGMNT
//
// MessageText:
//
//  dd.
//
#define TLR_E_PNS_IF_WRM_CFG_MNGMNT      ((TLR_RESULT)0xC03000B0L)

//
// MessageId: TLR_E_PNS_IF_RESET_FACTORY_IND
//
// MessageText:
//
//  No registered application. Reset_to_factory_settings Indication failed.
//
#define TLR_E_PNS_IF_RESET_FACTORY_IND   ((TLR_RESULT)0xC03000B1L)

//
// MessageId: TLR_E_PNS_IF_MODULE_ALREADY_PLUGGED
//
// MessageText:
//
//  A module was already plugged to the slot.
//
#define TLR_E_PNS_IF_MODULE_ALREADY_PLUGGED ((TLR_RESULT)0xC03000B2L)

//
// MessageId: TLR_E_PNS_IF_OSINIT
//
// MessageText:
//
//  Failed to init the OS adaptation layer.
//
#define TLR_E_PNS_IF_OSINIT              ((TLR_RESULT)0xC03000B3L)

//
// MessageId: TLR_E_PNS_IF_OSSOCKINIT
//
// MessageText:
//
//  Failed to init the TCPIP adaptation layer.
//
#define TLR_E_PNS_IF_OSSOCKINIT          ((TLR_RESULT)0xC03000B4L)

//
// MessageId: TLR_E_PNS_IF_INVALID_NETMASK
//
// MessageText:
//
//  Invalid subnetwork mask.
//
#define TLR_E_PNS_IF_INVALID_NETMASK     ((TLR_RESULT)0xC03000B5L)

//
// MessageId: TLR_E_PNS_IF_INVALID_IP_ADDR
//
// MessageText:
//
//  Invalid IP address.
//
#define TLR_E_PNS_IF_INVALID_IP_ADDR     ((TLR_RESULT)0xC03000B6L)

//
// MessageId: TLR_E_PNS_IF_STA_STARTUP_PARAMETER
//
// MessageText:
//
//  Erroneous Task start-up parameters.
//
#define TLR_E_PNS_IF_STA_STARTUP_PARAMETER ((TLR_RESULT)0xC03000B7L)

//
// MessageId: TLR_E_PNS_IF_INIT_LOCAL
//
// MessageText:
//
//  Failed to initialize the Task local resources.
//
#define TLR_E_PNS_IF_INIT_LOCAL          ((TLR_RESULT)0xC03000B8L)

//
// MessageId: TLR_E_PNS_IF_APP_CONFIG_INCOMPLETE
//
// MessageText:
//
//  The configuration per packets is incomplete.
//
#define TLR_E_PNS_IF_APP_CONFIG_INCOMPLETE ((TLR_RESULT)0xC03000B9L)

//
// MessageId: TLR_E_PNS_IF_INIT_EDD
//
// MessageText:
//
//  EDD Initialization failed.
//
#define TLR_E_PNS_IF_INIT_EDD            ((TLR_RESULT)0xC03000BAL)

//
// MessageId: TLR_E_PNS_IF_DPM_NOT_ENABLED
//
// MessageText:
//
//  DPM is not enabled.
//
#define TLR_E_PNS_IF_DPM_NOT_ENABLED     ((TLR_RESULT)0xC03000BBL)

//
// MessageId: TLR_E_PNS_IF_READ_LINK_STATUS
//
// MessageText:
//
//  Reading Link Status failed.
//
#define TLR_E_PNS_IF_READ_LINK_STATUS    ((TLR_RESULT)0xC03000BCL)

//
// MessageId: TLR_E_PNS_IF_INVALID_GATEWAY
//
// MessageText:
//
//  Invalid gateway address (not reachable with configured netmask).
//
#define TLR_E_PNS_IF_INVALID_GATEWAY     ((TLR_RESULT)0xC03000BDL)

// these #defines are from Benjamin - for use with new PNIO stack (none-Siemens)
//
// MessageId: TLR_E_PNS_IF_PACKET_SEND_FAILED
//
// MessageText:
//
//  Error while sending a packet to another task.
//
#define TLR_E_PNS_IF_PACKET_SEND_FAILED  ((TLR_RESULT)0xC0300100L)

//
// MessageId: TLR_E_PNS_IF_RESOURCE_OUT_OF_MEMORY
//
// MessageText:
//
//  Unsufficient memory to handle the request.
//
#define TLR_E_PNS_IF_RESOURCE_OUT_OF_MEMORY ((TLR_RESULT)0xC0300101L)

//
// MessageId: TLR_E_PNS_IF_NO_APPLICATION_REGISTERED
//
// MessageText:
//
//  No application to send the indication to is registered.
//
#define TLR_E_PNS_IF_NO_APPLICATION_REGISTERED ((TLR_RESULT)0xC0300102L)

//
// MessageId: TLR_E_PNS_IF_INVALID_SOURCE_ID
//
// MessageText:
//
//  The host-application returned a packet with invalid (changed) SourceID.
//
#define TLR_E_PNS_IF_INVALID_SOURCE_ID   ((TLR_RESULT)0xC0300103L)

//
// MessageId: TLR_E_PNS_IF_PACKET_BUFFER_FULL
//
// MessageText:
//
//  The buffer used to store packets exchanged between host-application and stack is full.
//
#define TLR_E_PNS_IF_PACKET_BUFFER_FULL  ((TLR_RESULT)0xC0300104L)

//
// MessageId: TLR_E_PNS_IF_PULL_NO_MODULE
//
// MessageText:
//
//  Pulling the (sub)module failed because no module is plugged into the slot specified.
//
#define TLR_E_PNS_IF_PULL_NO_MODULE      ((TLR_RESULT)0xC0300105L)

//
// MessageId: TLR_E_PNS_IF_PULL_NO_SUBMODULE
//
// MessageText:
//
//  Pulling the submodule failed because no submodule is plugged into the subslot specified.
//
#define TLR_E_PNS_IF_PULL_NO_SUBMODULE   ((TLR_RESULT)0xC0300106L)

//
// MessageId: TLR_E_PNS_IF_PACKET_BUFFER_RESTORE_ERROR
//
// MessageText:
//
//  The packet buffer storing packets exchanged between host-application and stack returned an invalid packet.
//
#define TLR_E_PNS_IF_PACKET_BUFFER_RESTORE_ERROR ((TLR_RESULT)0xC0300107L)

//
// MessageId: TLR_E_PNS_IF_DIAG_NO_MODULE
//
// MessageText:
//
//  Diagnosis data not accepted because no module is plugged into the slot specified.
//
#define TLR_E_PNS_IF_DIAG_NO_MODULE      ((TLR_RESULT)0xC0300108L)

//
// MessageId: TLR_E_PNS_IF_DIAG_NO_SUBMODULE
//
// MessageText:
//
//  Diagnosis data not accepted because no submodule is plugged into the subslot specified.
//
#define TLR_E_PNS_IF_DIAG_NO_SUBMODULE   ((TLR_RESULT)0xC0300109L)

//
// MessageId: TLR_E_PNS_IF_CYCLIC_EXCHANGE_ACTIVE
//
// MessageText:
//
//  The services requested is not available while cyclic communication is running.
//
#define TLR_E_PNS_IF_CYCLIC_EXCHANGE_ACTIVE ((TLR_RESULT)0xC030010AL)

//
// MessageId: TLR_E_PNS_IF_FATAL_ERROR_CLB_ALREADY_REGISTERED
//
// MessageText:
//
//  This fatal error callback function could not be registered because there is already a function registered.
//
#define TLR_E_PNS_IF_FATAL_ERROR_CLB_ALREADY_REGISTERED ((TLR_RESULT)0xC030010BL)

//
// MessageId: TLR_E_PNS_IF_ERROR_STACK_WARMSTART_CONFIGURATION
//
// MessageText:
//
//  The stack did not accept the warmstart parameters.
//
#define TLR_E_PNS_IF_ERROR_STACK_WARMSTART_CONFIGURATION ((TLR_RESULT)0xC030010CL)

//
// MessageId: TLR_E_PNS_IF_ERROR_STACK_MODULE_CONFIGURATION
//
// MessageText:
//
//  The stack did not accept the module configuration packet.
//
#define TLR_E_PNS_IF_ERROR_STACK_MODULE_CONFIGURATION ((TLR_RESULT)0xC030010DL)

//
// MessageId: TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_MODULE
//
// MessageText:
//
//  The stack sent a Check Indication for an unexpected module. This module was not part of the CR Info Indication.
//
#define TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_MODULE ((TLR_RESULT)0xC030010EL)

//
// MessageId: TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_SUBMODULE
//
// MessageText:
//
//  The stack sent a Check Indication for an unexpected submodule. This submodule was not part of the CR Info Indication.
//
#define TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_SUBMODULE ((TLR_RESULT)0xC030010FL)

//
// MessageId: TLR_E_PNS_DIAG_BUFFER_FULL
//
// MessageText:
//
//  No more diagnosis records can be added to the stack because the maximum amount is already reached.
//
#define TLR_E_PNS_DIAG_BUFFER_FULL       ((TLR_RESULT)0xC0300110L)

//
// MessageId: TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_API
//
// MessageText:
//
//  The stack sent a Check Indication for an unexpected API. This API was not part of the CR Info Indication.
//
#define TLR_E_PNS_IF_CHECK_IND_FOR_UNEXPECTED_API ((TLR_RESULT)0xC0300111L)

//
// MessageId: TLR_E_PNS_IF_DPM_ACCESS_WITH_INVALID_OFFSET
//
// MessageText:
//
//  The DPM shall be accessed with an invalid data offset.
//
#define TLR_E_PNS_IF_DPM_ACCESS_WITH_INVALID_OFFSET ((TLR_RESULT)0xC0300112L)

//
// MessageId: TLR_E_PNS_IF_DUPLICATE_INPUT_CR_INFO
//
// MessageText:
//
//  The stack indicated to CR Info Indications with type input.
//
#define TLR_E_PNS_IF_DUPLICATE_INPUT_CR_INFO ((TLR_RESULT)0xC0300113L)

//
// MessageId: TLR_E_PNS_IF_DUPLICATE_OUTPUT_CR_INFO
//
// MessageText:
//
//  The stack indicated to CR Info Indications with type output.
//
#define TLR_E_PNS_IF_DUPLICATE_OUTPUT_CR_INFO ((TLR_RESULT)0xC0300114L)

//
// MessageId: TLR_E_PNS_IF_FAULTY_CR_INFO_IND_RECEIVED
//
// MessageText:
//
//  The stack indicated a faulty CR Info Indications.
//
#define TLR_E_PNS_IF_FAULTY_CR_INFO_IND_RECEIVED ((TLR_RESULT)0xC0300115L)

//
// MessageId: TLR_E_PNS_IF_CONFIG_RELOAD_RUNNING
//
// MessageText:
//
//  The request can not be executed because configuration reload respectively ChannelInit is running.
//
#define TLR_E_PNS_IF_CONFIG_RELOAD_RUNNING ((TLR_RESULT)0xC0300116L)

//
// MessageId: TLR_E_PNS_IF_NO_MAC_ADDRESS_SET
//
// MessageText:
//
//  There is no valid chassis MAC address set Without MAC address the stack will not work.
//
#define TLR_E_PNS_IF_NO_MAC_ADDRESS_SET  ((TLR_RESULT)0xC0300117L)

//
// MessageId: TLR_E_PNS_IF_SET_PORT_MAC_NOT_POSSIBLE
//
// MessageText:
//
//  The Port MAC addresses have to be set before sending Set-Configuration Request to the stack.
//
#define TLR_E_PNS_IF_SET_PORT_MAC_NOT_POSSIBLE ((TLR_RESULT)0xC0300118L)

//
// MessageId: TLR_E_PNS_IF_INVALID_MODULE_CONFIGURATION
//
// MessageText:
//
//  Evaluating the module configuration failed.
//
#define TLR_E_PNS_IF_INVALID_MODULE_CONFIGURATION ((TLR_RESULT)0xC030011AL)

//
// MessageId: TLR_E_PNS_IF_CONF_IO_LEN_TO_BIG
//
// MessageText:
//
//  The sum of IO-data length exceeds the maximum allowed value.
//
#define TLR_E_PNS_IF_CONF_IO_LEN_TO_BIG  ((TLR_RESULT)0xC030011BL)

//
// MessageId: TLR_E_PNS_IF_NO_MODULE_CONFIGURED
//
// MessageText:
//
//  The module configuration does not contain at least one module.
//
#define TLR_E_PNS_IF_NO_MODULE_CONFIGURED ((TLR_RESULT)0xC030011CL)

//
// MessageId: TLR_E_PNS_IF_INVALID_SW_REV_PREFIX
//
// MessageText:
//
//  The value of bSwRevisionPrefix is invalid.
//
#define TLR_E_PNS_IF_INVALID_SW_REV_PREFIX ((TLR_RESULT)0xC030011DL)

//
// MessageId: TLR_E_PNS_IF_RESERVED_VALUE_NOT_ZERO
//
// MessageText:
//
//  The value of usReserved it not zero.
//
#define TLR_E_PNS_IF_RESERVED_VALUE_NOT_ZERO ((TLR_RESULT)0xC030011EL)

//
// MessageId: TLR_E_PNS_IF_IDENTIFY_CMDEV_QUEUE_FAILED
//
// MessageText:
//
//  Identifying the stack message queue CMDEV failed.
//
#define TLR_E_PNS_IF_IDENTIFY_CMDEV_QUEUE_FAILED ((TLR_RESULT)0xC030011FL)

//
// MessageId: TLR_E_PNS_IF_CREATE_SYNC_QUEUE_FAILED
//
// MessageText:
//
//  Creating the sync message queue failed.
//
#define TLR_E_PNS_IF_CREATE_SYNC_QUEUE_FAILED ((TLR_RESULT)0xC0300120L)

//
// MessageId: TLR_E_PNS_IF_CREATE_ALARM_LOW_QUEUE_FAILED
//
// MessageText:
//
//  Creating the low alarm message queue failed.
//
#define TLR_E_PNS_IF_CREATE_ALARM_LOW_QUEUE_FAILED ((TLR_RESULT)0xC0300121L)

//
// MessageId: TLR_E_PNS_IF_CREATE_ALARM_HIGH_QUEUE_FAILED
//
// MessageText:
//
//  Creating the high alarm message queue failed.
//
#define TLR_E_PNS_IF_CREATE_ALARM_HIGH_QUEUE_FAILED ((TLR_RESULT)0xC0300122L)

//
// MessageId: TLR_E_PNS_IF_CFG_PACKET_TO_SMALL
//
// MessageText:
//
//  While evaulating SetConfiguration packet the packet length was found smaller than amount of configured modules needs.
//
#define TLR_E_PNS_IF_CFG_PACKET_TO_SMALL ((TLR_RESULT)0xC0300123L)

//
// MessageId: TLR_E_PNS_IF_FATAL_ERROR_OCCURRED
//
// MessageText:
//
//  A fatal error occurred prior to this request. Therefore this request can not be fullfiled.
//
#define TLR_E_PNS_IF_FATAL_ERROR_OCCURRED ((TLR_RESULT)0xC0300124L)

//
// MessageId: TLR_E_PNS_IF_SUBMODULE_NOT_IN_CYCLIC_EXCHANGE
//
// MessageText:
//
//  The request could not be executed because the submodule is not in cyclic dataexchange.
//
#define TLR_E_PNS_IF_SUBMODULE_NOT_IN_CYCLIC_EXCHANGE ((TLR_RESULT)0xC0300125L)

//
// MessageId: TLR_E_PNS_IF_SERVICE_NOT_AVAILABLE_THROUGH_DPM
//
// MessageText:
//
//  This service is not available through DPM.
//
#define TLR_E_PNS_IF_SERVICE_NOT_AVAILABLE_THROUGH_DPM ((TLR_RESULT)0xC0300126L)

//
// MessageId: TLR_E_PNS_IF_INVALID_PARAMETER_VERSION
//
// MessageText:
//
//  The version of parameters is invalid (most likely too old).
//
#define TLR_E_PNS_IF_INVALID_PARAMETER_VERSION ((TLR_RESULT)0xC0300127L)

//
// MessageId: TLR_E_PNS_IF_DATABASE_USAGE_IS_FORBIDDEN
//
// MessageText:
//
//  The usage of database is forbidden by task's startup parameters.
//
#define TLR_E_PNS_IF_DATABASE_USAGE_IS_FORBIDDEN ((TLR_RESULT)0xC0300128L)

//
// MessageId: TLR_E_PNS_IF_RECORD_LENGTH_TOO_BIG
//
// MessageText:
//
//  The amount of record data is too big.
//
#define TLR_E_PNS_IF_RECORD_LENGTH_TOO_BIG ((TLR_RESULT)0xC0300129L)

//
// MessageId: TLR_E_PNS_IF_IDENTIFY_LLDP_QUEUE_FAILED
//
// MessageText:
//
//  Identifying the stack message queue LLDP failed.
//
#define TLR_E_PNS_IF_IDENTIFY_LLDP_QUEUE_FAILED ((TLR_RESULT)0xC030012AL)

//
// MessageId: TLR_E_PNS_IF_INVALID_TOTAL_PACKET_LENGTH
//
// MessageText:
//
//  SetConfiguration Requests total packet length is invalid.
//
#define TLR_E_PNS_IF_INVALID_TOTAL_PACKET_LENGTH ((TLR_RESULT)0xC030012BL)

//
// MessageId: TLR_E_PNS_IF_APPLICATION_TIMEOUT
//
// MessageText:
//
//  The application needed to much time to respond to an indication.
//
#define TLR_E_PNS_IF_APPLICATION_TIMEOUT ((TLR_RESULT)0xC030012CL)

//
// MessageId: TLR_E_PNS_IF_PACKET_BUFFER_INVALID_PACKET
//
// MessageText:
//
//  The packet buffer storing packets exchanged between host-application and stack returned a faulty packet.
//
#define TLR_E_PNS_IF_PACKET_BUFFER_INVALID_PACKET ((TLR_RESULT)0xC030012DL)

//
// MessageId: TLR_E_PNS_IF_NO_IO_IMAGE_CONFIGURATION_AVAILABLE
//
// MessageText:
//
//  The request can not be handled until a valid IO Image configuration is available.
//
#define TLR_E_PNS_IF_NO_IO_IMAGE_CONFIGURATION_AVAILABLE ((TLR_RESULT)0xC030012EL)

//
// MessageId: TLR_E_PNS_IF_IO_IMAGE_ALREADY_CONFIGURED
//
// MessageText:
//
//  A valid IO Image configuration is already available.
//
#define TLR_E_PNS_IF_IO_IMAGE_ALREADY_CONFIGURED ((TLR_RESULT)0xC030012FL)

//
// MessageId: TLR_E_PNS_IF_INVALID_PDEV_SUBSLOT
//
// MessageText:
//
//  A submodule may only be plugged into a PDEV-subslot which does not exceed the number of supported interfaces and portnumbers.
//
#define TLR_E_PNS_IF_INVALID_PDEV_SUBSLOT ((TLR_RESULT)0xC0300130L)

//
// MessageId: TLR_E_PNS_IF_NO_DAP_PRESENT
//
// MessageText:
//
//  The module configuration does not contain a the Device Access Point DAP-submodule in slot 0 subslot 1.
//
#define TLR_E_PNS_IF_NO_DAP_PRESENT      ((TLR_RESULT)0xC0300131L)

//
// MessageId: TLR_E_PNS_IF_PLUG_SUBMOD_OUTPUT_SIZE_EXCEEDED
//
// MessageText:
//
//  Output size of the submodule exceeded. Configured value of ulCompleteOutputSize is smaller then the Output size of all plugged input modules. Upgrade ulCompleteOutputSize.
//
#define TLR_E_PNS_IF_PLUG_SUBMOD_OUTPUT_SIZE_EXCEEDED ((TLR_RESULT)0xC0300132L)

//
// MessageId: TLR_E_PNS_IF_PLUG_SUBMOD_INPUT_SIZE_EXCEEDED
//
// MessageText:
//
//  Input size of the submodule exceeded. Configured value of ulCompleteInputSize is smaller then the Input size of all plugged input modules. Upgrade ulCompleteInputSize.
//
#define TLR_E_PNS_IF_PLUG_SUBMOD_INPUT_SIZE_EXCEEDED ((TLR_RESULT)0xC0300133L)

//
// MessageId: TLR_E_PNS_IF_PLUG_SUBMOD_NO_MODULE_ATTACHED_TO_ADD_TO
//
// MessageText:
//
//  No module attached to add the submodule to.
//
#define TLR_E_PNS_IF_PLUG_SUBMOD_NO_MODULE_ATTACHED_TO_ADD_TO ((TLR_RESULT)0xC0300134L)

//
// MessageId: TLR_E_PNS_IF_PLUG_SUBMOD_ALREADY_PLUGGED_THIS_SUBMOD
//
// MessageText:
//
//  Submodule already plugged.
//
#define TLR_E_PNS_IF_PLUG_SUBMOD_ALREADY_PLUGGED_THIS_SUBMOD ((TLR_RESULT)0xC0300135L)

//
// MessageId: TLR_E_PNS_IF_SETIOXS_INVALID_PROV_IMAGE
//
// MessageText:
//
//  Invalid IOXS provider image.
//
#define TLR_E_PNS_IF_SETIOXS_INVALID_PROV_IMAGE ((TLR_RESULT)0xC0300136L)

//
// MessageId: TLR_E_PNS_IF_SETIOXS_INVALID_CONS_IMAGE
//
// MessageText:
//
//  Invalid IOXS consumer image.
//
#define TLR_E_PNS_IF_SETIOXS_INVALID_CONS_IMAGE ((TLR_RESULT)0xC0300137L)

//
// MessageId: TLR_E_PNS_IF_INVALID_IOPS_MODE
//
// MessageText:
//
//  Invalid IOPS mode.
//
#define TLR_E_PNS_IF_INVALID_IOPS_MODE   ((TLR_RESULT)0xC0300138L)

//
// MessageId: TLR_E_PNS_IF_INVALID_IOCS_MODE
//
// MessageText:
//
//  Invalid IOCS mode.
//
#define TLR_E_PNS_IF_INVALID_IOCS_MODE   ((TLR_RESULT)0xC0300139L)

//
// MessageId: TLR_E_PNS_IF_INVALID_API
//
// MessageText:
//
//  Invalid API.
//
#define TLR_E_PNS_IF_INVALID_API         ((TLR_RESULT)0xC030013AL)

//
// MessageId: TLR_E_PNS_IF_INVALID_SLOT
//
// MessageText:
//
//  Invalid slot.
//
#define TLR_E_PNS_IF_INVALID_SLOT        ((TLR_RESULT)0xC030013BL)

//
// MessageId: TLR_E_PNS_IF_INVALID_SUBSLOT
//
// MessageText:
//
//  Invalid subslot.
//
#define TLR_E_PNS_IF_INVALID_SUBSLOT     ((TLR_RESULT)0xC030013CL)

//
// MessageId: TLR_E_PNS_IF_INVALID_CHANNEL_NUMBER
//
// MessageText:
//
//  Invalid channel number.
//
#define TLR_E_PNS_IF_INVALID_CHANNEL_NUMBER ((TLR_RESULT)0xC030013DL)

//
// MessageId: TLR_E_PNS_IF_INVALID_CHANNEL_PROPERTIES
//
// MessageText:
//
//  Invalid channel properties.
//
#define TLR_E_PNS_IF_INVALID_CHANNEL_PROPERTIES ((TLR_RESULT)0xC030013EL)

//
// MessageId: TLR_E_PNS_IF_CHANNEL_ERRORTYPE_NOT_ALLOWED
//
// MessageText:
//
//  Invalid channel errortype not allowed.
//
#define TLR_E_PNS_IF_CHANNEL_ERRORTYPE_NOT_ALLOWED ((TLR_RESULT)0xC030013FL)

//
// MessageId: TLR_E_PNS_IF_EXT_CHANNEL_ERRORTYPE_NOT_ALLOWED
//
// MessageText:
//
//  Invalid channel EXT errortype not allowed.
//
#define TLR_E_PNS_IF_EXT_CHANNEL_ERRORTYPE_NOT_ALLOWED ((TLR_RESULT)0xC0300140L)

//
// MessageId: TLR_E_PNS_IF_INVALID_USER_STRUCT_IDENTIFIER
//
// MessageText:
//
//  Invalid user struct identifier.
//
#define TLR_E_PNS_IF_INVALID_USER_STRUCT_IDENTIFIER ((TLR_RESULT)0xC0300141L)

//
// MessageId: TLR_E_PNS_IF_INVALID_SUBMODULE
//
// MessageText:
//
//  Invalid submodule.
//
#define TLR_E_PNS_IF_INVALID_SUBMODULE   ((TLR_RESULT)0xC0300142L)

//
// MessageId: TLR_E_PNS_IF_INVALID_IM_TYPE
//
// MessageText:
//
//  Invalid IM type.
//
#define TLR_E_PNS_IF_INVALID_IM_TYPE     ((TLR_RESULT)0xC0300143L)

//
// MessageId: TLR_E_PNS_IF_IDENTIFY_FODMI_QUEUE_FAILED
//
// MessageText:
//
//  Failed to identify the FODMI Queue.
//
#define TLR_E_PNS_IF_IDENTIFY_FODMI_QUEUE_FAILED ((TLR_RESULT)0xC0300144L)

//
// MessageId: TLR_E_PNS_IF_DPM_MAILBOX_OVERFLOW
//
// MessageText:
//
//  The DPM Receive Mailbox Queue run out of space. Most likely the host did not fetch the packets.
//
#define TLR_E_PNS_IF_DPM_MAILBOX_OVERFLOW ((TLR_RESULT)0xC0300145L)

//
// MessageId: TLR_E_PNS_IF_APPL_IM_ACCESS_DENIED
//
// MessageText:
//
//  The application denied read/write access to I&M record object.
//
#define TLR_E_PNS_IF_APPL_IM_ACCESS_DENIED ((TLR_RESULT)0xC0300146L)

//
// MessageId: TLR_E_PNS_IF_APPL_IM_INVALID_INDEX
//
// MessageText:
//
//  The application does not implement the requested I&M record object.
//
#define TLR_E_PNS_IF_APPL_IM_INVALID_INDEX ((TLR_RESULT)0xC0300147L)

// START: On 12.11.08 Konstantin added: Area for Abort- and Offline- Reason error codes to support Siemens Stack
// MessageId = 0x0A00 - 0x0AFF
//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_NONE
//
// MessageText:
//
//  None. Unused.
//
#define TLR_E_PNS_IF_CM_AR_REASON_NONE   ((TLR_RESULT)0xC0300A00L)

//MessageId       = 0x0A01
//Severity        = Error
//Facility        = TLR_UNQ_NR_PNS_IF
//SymbolicName    = TLR_E_PNS_IF_
//Language        = English
//.
//.
//Language        = German
//.
//.
//
//MessageId       = 0x0A02
//Severity        = Error
//Facility        = TLR_UNQ_NR_PNS_IF
//SymbolicName    = TLR_E_PNS_IF_
//Language        = English
//.
//.
//Language        = German
//.
//.
//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_MEM
//
// MessageText:
//
//  AR Out of memory.
//
#define TLR_E_PNS_IF_CM_AR_REASON_MEM    ((TLR_RESULT)0xC0300A03L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_FRAME
//
// MessageText:
//
//  AR add provider or consumer failed.
//
#define TLR_E_PNS_IF_CM_AR_REASON_FRAME  ((TLR_RESULT)0xC0300A04L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_MISS
//
// MessageText:
//
//  AR consumer DHT/WDT expired.
//
#define TLR_E_PNS_IF_CM_AR_REASON_MISS   ((TLR_RESULT)0xC0300A05L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_TIMER
//
// MessageText:
//
//  AR cmi timeout.
//
#define TLR_E_PNS_IF_CM_AR_REASON_TIMER  ((TLR_RESULT)0xC0300A06L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_ALARM
//
// MessageText:
//
//  AR alarm-open failed.
//
#define TLR_E_PNS_IF_CM_AR_REASON_ALARM  ((TLR_RESULT)0xC0300A07L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_ALSND
//
// MessageText:
//
//  AR alarm-send.cnf(-).
//
#define TLR_E_PNS_IF_CM_AR_REASON_ALSND  ((TLR_RESULT)0xC0300A08L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_ALACK
//
// MessageText:
//
//  AR alarm-ack-send.cnf(-).
//
#define TLR_E_PNS_IF_CM_AR_REASON_ALACK  ((TLR_RESULT)0xC0300A09L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_ALLEN
//
// MessageText:
//
//  AR alarm data too long.
//
#define TLR_E_PNS_IF_CM_AR_REASON_ALLEN  ((TLR_RESULT)0xC0300A0AL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_ASRT
//
// MessageText:
//
//  AR alarm.ind(err).
//
#define TLR_E_PNS_IF_CM_AR_REASON_ASRT   ((TLR_RESULT)0xC0300A0BL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_RPC
//
// MessageText:
//
//  AR rpc-client call.cnf(-).
//
#define TLR_E_PNS_IF_CM_AR_REASON_RPC    ((TLR_RESULT)0xC0300A0CL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_ABORT
//
// MessageText:
//
//  AR abort.req.
//
#define TLR_E_PNS_IF_CM_AR_REASON_ABORT  ((TLR_RESULT)0xC0300A0DL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_RERUN
//
// MessageText:
//
//  AR re-run aborts existing AR.
//
#define TLR_E_PNS_IF_CM_AR_REASON_RERUN  ((TLR_RESULT)0xC0300A0EL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_REL
//
// MessageText:
//
//  AR release.ind received.
//
#define TLR_E_PNS_IF_CM_AR_REASON_REL    ((TLR_RESULT)0xC0300A0FL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_PAS
//
// MessageText:
//
//  AR device deactivated.
//
#define TLR_E_PNS_IF_CM_AR_REASON_PAS    ((TLR_RESULT)0xC0300A10L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_RMV
//
// MessageText:
//
//  AR removed.
//
#define TLR_E_PNS_IF_CM_AR_REASON_RMV    ((TLR_RESULT)0xC0300A11L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_PROT
//
// MessageText:
//
//  AR protocol violation.
//
#define TLR_E_PNS_IF_CM_AR_REASON_PROT   ((TLR_RESULT)0xC0300A12L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_NARE
//
// MessageText:
//
//  AR name resolution error.
//
#define TLR_E_PNS_IF_CM_AR_REASON_NARE   ((TLR_RESULT)0xC0300A13L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_BIND
//
// MessageText:
//
//  AR RPC-Bind error.
//
#define TLR_E_PNS_IF_CM_AR_REASON_BIND   ((TLR_RESULT)0xC0300A14L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_CONNECT
//
// MessageText:
//
//  AR RPC-Connect error.
//
#define TLR_E_PNS_IF_CM_AR_REASON_CONNECT ((TLR_RESULT)0xC0300A15L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_READ
//
// MessageText:
//
//  AR RPC-Read error.
//
#define TLR_E_PNS_IF_CM_AR_REASON_READ   ((TLR_RESULT)0xC0300A16L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_WRITE
//
// MessageText:
//
//  AR RPC-Write error.
//
#define TLR_E_PNS_IF_CM_AR_REASON_WRITE  ((TLR_RESULT)0xC0300A17L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_CONTROL
//
// MessageText:
//
//  AR RPC-Control error.
//
#define TLR_E_PNS_IF_CM_AR_REASON_CONTROL ((TLR_RESULT)0xC0300A18L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_PULLPLUG
//
// MessageText:
//
//  AR forbidden pull or plug after check.rsp and before in-data.ind.
//
#define TLR_E_PNS_IF_CM_AR_REASON_PULLPLUG ((TLR_RESULT)0xC0300A19L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_AP_RMV
//
// MessageText:
//
//  AR AP removed.
//
#define TLR_E_PNS_IF_CM_AR_REASON_AP_RMV ((TLR_RESULT)0xC0300A1AL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_LNK_DWN
//
// MessageText:
//
//  AR link down.
//
#define TLR_E_PNS_IF_CM_AR_REASON_LNK_DWN ((TLR_RESULT)0xC0300A1BL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_MMAC
//
// MessageText:
//
//  AR could not register multicast-mac address.
//
#define TLR_E_PNS_IF_CM_AR_REASON_MMAC   ((TLR_RESULT)0xC0300A1CL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_SYNC
//
// MessageText:
//
//  Not synchronized (cannot start companion-ar).
//
#define TLR_E_PNS_IF_CM_AR_REASON_SYNC   ((TLR_RESULT)0xC0300A1DL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_TOPO
//
// MessageText:
//
//  Wrong topology (cannot start companion-ar).
//
#define TLR_E_PNS_IF_CM_AR_REASON_TOPO   ((TLR_RESULT)0xC0300A1EL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_DCP_NAME
//
// MessageText:
//
//  DCP, station-name changed.
//
#define TLR_E_PNS_IF_CM_AR_REASON_DCP_NAME ((TLR_RESULT)0xC0300A1FL)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_DCP_RESET
//
// MessageText:
//
//  DCP, reset to factory-settings.
//
#define TLR_E_PNS_IF_CM_AR_REASON_DCP_RESET ((TLR_RESULT)0xC0300A20L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_PRM
//
// MessageText:
//
//  0x8ipp submodule in the first AR has either an appl-ready-pending (erroneous parameterisation) or is locked (no parameterisation) or is wrong or pulled (no parameterisation).
//
#define TLR_E_PNS_IF_CM_AR_REASON_PRM    ((TLR_RESULT)0xC0300A21L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_IRDATA
//
// MessageText:
//
//  No irdata record yet.
//
#define TLR_E_PNS_IF_CM_AR_REASON_IRDATA ((TLR_RESULT)0xC0300A22L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_PDEV
//
// MessageText:
//
//  Ownership of PDEV.
//
#define TLR_E_PNS_IF_CM_AR_REASON_PDEV   ((TLR_RESULT)0xC0300A23L)

//
// MessageId: TLR_E_PNS_IF_CM_AR_REASON_MAX
//
// MessageText:
//
//  Max. Unused.
//
#define TLR_E_PNS_IF_CM_AR_REASON_MAX    ((TLR_RESULT)0xC0300AFFL)

// END: On 12.11.08 Konstantin added: Area for Abort- and Offline- Reason error codes to support Siemens Stack
// MessageId = 0x0A00 - 0x0AFF



#endif  //__PNS_ERROR_H

