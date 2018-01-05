/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpipTcpTask_error.h 63545 2016-08-29 09:04:12Z RalfH $:

Description:
    TCP/IP error definitions (automatically generated header)


  Changes:
    Date         Description
 -----------------------------------------------------------------------------------
    2010-05-26   File created.

**************************************************************************************/


#ifndef __TCPIP_ERROR_H
#define __TCPIP_ERROR_H

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  IP Packet Status codes (TCP_UDP task) */
/* /////////////////////////////////////////////////////////////////////////////////// */
/*  Initialization Error Codes */
/* MessageId       = 50 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_NO_TCP_TASK */
/* Language        = English */
/* TCP/UDP task not available. */
/* . */
/* Language        = German */
/* TCP/UDP Task nicht vorhanden. */
/* . */
/* MessageId       = 51 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_TASK_CONFIG */
/* Language        = English */
/* Internal task configuration data not available. */
/* . */
/* Language        = German */
/* Interne Task Konfigurationsdaten nicht verfügbar. */
/* . */
/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_NO_ETHERNET_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   There is no Ethernet address (MAC address) available. */
/*  */
#define TLR_E_IP_ERR_INIT_NO_ETHERNET_ADDR ((TLR_RESULT)0xC0070034L)

/* MessageId       = 53 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_WAIT_FOR_WARMSTART */
/* Language        = English */
/* Waiting for warm-start by application program. */
/* . */
/* Language        = German */
/* Warte auf einen Warmstart der Applikation. */
/* . */
/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_FLAG */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters contains one or more unknown flags. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_FLAG   ((TLR_RESULT)0xC0070036L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_IP_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters contains an invalid IP address. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_IP_ADDR ((TLR_RESULT)0xC0070037L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_NETMASK */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters contains an invalid subnet mask. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_NETMASK ((TLR_RESULT)0xC0070038L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters contains an invalid gateway IP address. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_GATEWAY ((TLR_RESULT)0xC0070039L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_UNKNOWN_HARDWARE */
/*  */
/*  MessageText: */
/*  */
/*   The device type is unknown. */
/*  */
#define TLR_E_IP_ERR_INIT_UNKNOWN_HARDWARE ((TLR_RESULT)0xC007003BL)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_NO_IP_ADDR */
/*  */
/*  MessageText: */
/*  */
/*   Failed to obtain an IP address from the specified source(s). */
/*  */
#define TLR_E_IP_ERR_INIT_NO_IP_ADDR     ((TLR_RESULT)0xC007003CL)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_DRIVER_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The initialisation of the driver layer (EDD) is failed. */
/*  */
#define TLR_E_IP_ERR_INIT_DRIVER_FAILED  ((TLR_RESULT)0xC007003DL)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_NO_IP_ADDR_CFG */
/*  */
/*  MessageText: */
/*  */
/*   There is no source for an IP address (BOOTP, DHCP, IP address parameter) specified. */
/*  */
#define TLR_E_IP_ERR_INIT_NO_IP_ADDR_CFG ((TLR_RESULT)0xC007003EL)

/* MessageId       = 63 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_INVALID_SERIAL_NUMBER */
/* Language        = English */
/* Invalid serial number. */
/* . */
/* Language        = German */
/* Ungültige Seriennummer. */
/* . */
/* MessageId       = 64 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_MEM_NOT_ON_CHIP */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/* MessageId       = 65 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_NO_MEM */
/* Language        = English */
/* . */
/* . */
/* Language        = German */
/* . */
/* . */
/* MessageId       = 66 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_CREATE_MBX */
/* Language        = English */
/* Failed to create the IP mailbox. */
/* . */
/* Language        = German */
/* Das Erzeugen der IP Mailbox ist fehlgeschlagen. */
/* . */
/* MessageId       = 67 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_CREATE_INFO_FIELD */
/* Language        = English */
/* Failed to create a task information field (task state). */
/* . */
/* Language        = German */
/* Das Erzeugen eines Task Informationsfeldes (Taskstatus) ist fehlgeschlagen. */
/* . */
/* MessageId       = 68 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_INIT_IDENTIFY_MBX */
/* Language        = English */
/* Failed to identify the mailbox of TCP task. */
/* . */
/* Language        = German */
/* Das Identifizieren der Mailbox der TCP Task ist fehlgeschlagen. */
/* . */
/*  Run-time Error Codes */
/*  */
/*  MessageId: TLR_E_IP_ERR_ETH_ADDR_INVALID_IP_CMD_SET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The Ethernet address (MAC address) abEthernetAddr in command TCPIP_IP_CMD_SET_PARAM_REQ is invalid. */
/*   Invalid means, abEthernetAddr is equal to the broadcast address FF-FF-FF-FF-FF-FF. */
/*  */
#define TLR_E_IP_ERR_ETH_ADDR_INVALID_IP_CMD_SET_PARAM ((TLR_RESULT)0xC007007CL)

/* MessageId       = 130 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_MODE_UNKNOWN */
/* Language        = English */
/* The mode parameter is invalid. */
/* . */
/* Language        = German */
/* Der Mode Parameter ist ungültig. */
/* . */
/*  */
/*  MessageId: TLR_E_IP_ERR_ARP_CACHE_FULL_IP_CMD_SET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_IP_CMD_SET_PARAM_REQ could not be executed, because the ARP cache is full. */
/*   The ARP cache has per default configuration 64 entries. */
/*  */
#define TLR_E_IP_ERR_ARP_CACHE_FULL_IP_CMD_SET_PARAM ((TLR_RESULT)0xC0070083L)

/*  */
/*  MessageId: TLR_E_IP_ERR_ARP_ENTRY_NOT_FOUND_IP_CMD_SET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The specified ARP entry in command TCPIP_IP_CMD_SET_PARAM_REQ could not be deleted. */
/*   The ARP entry was not found in ARP cache. */
/*  */
#define TLR_E_IP_ERR_ARP_ENTRY_NOT_FOUND_IP_CMD_SET_PARAM ((TLR_RESULT)0xC0070086L)

/*  */
/*  MessageId: TLR_E_IP_ERR_ARP_ENTRY_NOT_FOUND_IP_CMD_GET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The requested ARP information in command TCPIP_IP_CMD_GET_PARAM_REQ could not be delivered. */
/*   The ARP entry was not found in ARP cache. */
/*  */
#define TLR_E_IP_ERR_ARP_ENTRY_NOT_FOUND_IP_CMD_GET_PARAM ((TLR_RESULT)0xC0070087L)

/*                                                        */
/* MessageId: TLR_W_IP_ERR_ACD_MAX_CONFLICTS_REACHED      */
/*                                                        */
/* MessageText:                                           */
/*                                                        */
/*  The maximum number of ACD conflicts has been reached. */
/*  IP address could not be obtained via BOOTP/DHCP.      */
/*                                                        */
#define TLR_W_IP_ERR_ACD_MAX_CONFLICTS_REACHED ((TLR_RESULT)0x80070088L)

/* MessageId       = 149 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_IP */
/* SymbolicName    = TLR_E_IP_ERR_UNEXP_ANSWER */
/* Language        = English */
/* Unexpected answer message received. */
/* . */
/* Language        = German */
/* Unerwartete Anwortmessage empfangen. */
/* . */
/*  Special Error Codes from file TcpipIpbase.h */
/*  */
/*  MessageId: TLR_E_IP_ERR_DELAYED */
/*  */
/*  MessageText: */
/*  */
/*   Special internal error code returned by IpStart function. */
/*  */
#define TLR_E_IP_ERR_DELAYED             ((TLR_RESULT)0xC00700FEL)

/*  */
/*  MessageId: TLR_E_IP_ERR_GENERIC */
/*  */
/*  MessageText: */
/*  */
/*   Special internal error code returned by IpStart function. */
/*  */
#define TLR_E_IP_ERR_GENERIC             ((TLR_RESULT)0xC00700FFL)

/* /////////////////////////////////////////////////////////////////////////////////// */
/*  TCP_UDP task Packet Status codes */
/*  */
/*  Added here also the "TCP_UDP Diagnostic Status codes" from file tcpip_diag.mc - */
/*  there are no conflicts (except the MessageId 0x0001 and 0x0002 because of old and */
/*  comment out errors/diag codes, see below) - so the error numbers are unchanged. */
/*  But some codes are also comment out, because the corresponding error code exists! */
/*  Renamed from TLR_DIAG_E_xx to TLR_E_xx */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* MessageId       = 0x0001 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCPIP_TCP_TASK_COMMAND_INVALID --> TLR_E_UNKNOWN_COMMAND */
/* Language        = English */
/* Invalid command received. */
/* . */
/* Language        = German */
/* Ungültiges Kommando erhalten. */
/* . */
/* MessageId       = 0x0001 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_DIAG_E_TCP_ERR_TASK_PROCESS_TERMINATED */
/* Language        = English */
/* The task process was terminated with error - see task status. */
/* . */
/* Language        = German */
/* Die Task wurde beendet - siehe Taskstatus. */
/* . */
/* MessageId       = 0x0002 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCPIP_TCP_TASK_PROCESS_CANCELED */
/* Language        = English */
/* Cancel process is in progress, command can not be executed. */
/* . */
/* Language        = German */
/* Task wird gerade beendet, das Kommando kann nicht ausgeführt werden. */
/* . */
/* MessageId       = 0x0002 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_DIAG_E_TCP_ERR_INIT_RESET_CYCLE */
/* Language        = English */
/* Failed to reset the cyclic event. */
/* . */
/* Language        = German */
/* Das Reseten des zyklischen Events ist fehlgeschlagen. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_ERR_CODEDIAG_FATAL */
/*  */
/*  MessageText: */
/*  */
/*   A fatal error is occured. Terminate the task. */
/*  */
#define TLR_E_TCP_ERR_CODEDIAG_FATAL     ((TLR_RESULT)0xC0080003L)

/* MessageId       = 0x0004 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_NOT_INITIALIZED */
/* Language        = English */
/* Task is not initialized. */
/* . */
/* Language        = German */
/* Die Task ist nicht initialisiert. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_TASK_F_INITIALIZATION_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize the task. */
/*   Accept Init packets and Config packets only. */
/*  */
#define TLR_E_TCP_TASK_F_INITIALIZATION_FAILED ((TLR_RESULT)0xC0080005L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_SERIAL_NUMBER */
/*  */
/*  MessageText: */
/*  */
/*   Invalid serial number. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_SERIAL_NUMBER ((TLR_RESULT)0xC0080006L)

/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_IP_INIT_ERROR */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize the IP layer - see task status. */
/*  */
#define TLR_E_IP_ERR_INIT_IP_INIT_ERROR  ((TLR_RESULT)0xC0080007L)

/* MessageId       = 0x0008 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_OS_CYCLETIME */
/* Language        = English */
/* The configured operating system cycletime is out of range (0.1 ms ... 20 ms). */
/* . */
/* Language        = German */
/* Die konfigurierte Zykluszeit des Betriebssystems liegt ausserhalb der zulässigen Grenzen (0,1 ms ... 20 ms). */
/* . */
/*  */
/*  MessageId: TLR_E_TCPIP_TCP_TASK_PROCESS_CANCELED */
/*  */
/*  MessageText: */
/*  */
/*   Cancel process is in progress, command can not be executed. */
/*  */
#define TLR_E_TCPIP_TCP_TASK_PROCESS_CANCELED ((TLR_RESULT)0xC0080009L)

/*  */
/*  MessageId: TLR_E_TCPIP_EDD_IDENTIFY_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to identify the EDD (Ethernet Device Driver). */
/*  */
#define TLR_E_TCPIP_EDD_IDENTIFY_FAILED  ((TLR_RESULT)0xC008000AL)

/*  */
/*  MessageId: TLR_E_TCPIP_APPLICATION_TIMER_CREATE_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create an application timer (Timer task). */
/*  */
#define TLR_E_TCPIP_APPLICATION_TIMER_CREATE_FAILED ((TLR_RESULT)0xC008000BL)

/*  */
/*  MessageId: TLR_E_TCPIP_APPLICATION_TIMER_INIT_PACKET_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   Failed to initialize a packet of application timer (Timer task). */
/*  */
#define TLR_E_TCPIP_APPLICATION_TIMER_INIT_PACKET_FAILED ((TLR_RESULT)0xC008000CL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_SOCKET_MAX_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulSocketMaxCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_SOCKET_MAX_CNT ((TLR_RESULT)0xC008000DL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulPoolElemCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_POOL_ELEM_CNT ((TLR_RESULT)0xC008000EL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_OUT_BUF_MAX_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulEddOutBufMaxCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_OUT_BUF_MAX_CNT ((TLR_RESULT)0xC008000FL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_CACHE_SIZE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulArpCacheSize. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_CACHE_SIZE ((TLR_RESULT)0xC0080010L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_FREE_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulQueFreeElemCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_FREE_ELEM_CNT ((TLR_RESULT)0xC0080011L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_TCP_CYCLE_EVENT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulTcpCycleEvent. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_TCP_CYCLE_EVENT ((TLR_RESULT)0xC0080012L)

/* MessageId       = 0x0013 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_OS_AND_TCPUDP_CYCLETIME */
/* Language        = English */
/* The combination of configured operating system cycletime and TCP/IP stacks cycletime (startup-parameter */
/* ulTcpCycleEvent) is not possible. The operating system cycletime must be smaller or equal than the */
/* TCP/IP stacks cycletime. */
/* . */
/* Language        = German */
/* Die Kombination aus konfigurierter Zykluszeit des Betriebssystems und der Zykluszeit des TCP/IP Stacks */
/* (Startparameter ulTcpCycleEvent) ist nicht möglich. Die konfigurierter Zykluszeit des Betriebssystems */
/* muss kleiner oder gleich der Zykluszeit des TCP/IP Stacks sein. */
/* . */
/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT_AP */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulQueElemCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_QUE_ELEM_CNT_AP ((TLR_RESULT)0xC0080014L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_QUE_POOL_ELEM_CNT */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulEddQuePoolElemCnt. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_QUE_POOL_ELEM_CNT ((TLR_RESULT)0xC0080015L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_START_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulStartFlags. Unknown flags are set. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_START_FLAGS ((TLR_RESULT)0xC0080016L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter pszEddName. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EDD_NAME ((TLR_RESULT)0xC0080017L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF pszEddName. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_NAME ((TLR_RESULT)0xC0080018L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_INSTANCE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEddInstance. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_EDD_INSTANCE ((TLR_RESULT)0xC0080019L)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_ETH_INTF_NAME */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF pszEifEthIntfName. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_ETH_INTF_NAME ((TLR_RESULT)0xC008001AL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_MODE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEifMode. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_MODE ((TLR_RESULT)0xC008001BL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_RANGE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIFs ulEifPortStart, ulEifPortEnd. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_RANGE ((TLR_RESULT)0xC008001CL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_NMB */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEifPortNmb. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_PORT_NMB ((TLR_RESULT)0xC008001DL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_TIMEOUT_CACHE */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter ulArpTimeoutCache. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_ARP_TIMEOUT_CACHE ((TLR_RESULT)0xC008001EL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_FLAGS */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter EIF ulEifFlags. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_EIF_FLAGS ((TLR_RESULT)0xC008001FL)

/*  */
/*  MessageId: TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_HW_NAME_NETX */
/*  */
/*  MessageText: */
/*  */
/*   Invalid Startup Parameter pszHwNameNetX. */
/*  */
#define TLR_E_TCPIP_INVALID_STARTUP_PARAMETER_HW_NAME_NETX ((TLR_RESULT)0xC0080020L)

/*  Initialization Error Codes */
/*  */
/*  MessageId: TLR_E_TCP_ERR_INIT_IP_TASK_NOT_READY */
/*  */
/*  MessageText: */
/*  */
/*   The IP layer is not ready. */
/*  */
#define TLR_E_TCP_ERR_INIT_IP_TASK_NOT_READY ((TLR_RESULT)0xC0080032L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_INIT_IP_TASK_FAILED */
/*  */
/*  MessageText: */
/*  */
/*   The initialization of IP layer has failed. */
/*  */
#define TLR_E_TCP_ERR_INIT_IP_TASK_FAILED ((TLR_RESULT)0xC0080034L)

/* MessageId       = 61 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_CREATE_CYCLE */
/* Language        = English */
/* Failed to create the cyclic event. */
/* . */
/* Language        = German */
/* Das Erzeugen des zyklischen Events ist fehlgeschlagen. */
/* . */
/* MessageId       = 62 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_RESET_CYCLE */
/* Language        = English */
/* Failed to reset the cyclic event. */
/* . */
/* Language        = German */
/* Das Reseten des zyklischen Events ist fehlgeschlagen. */
/* . */
/* MessageId       = 63 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_CREATE_MULTIPLE */
/* Language        = English */
/* Failed to create the multiple object. */
/* . */
/* Language        = German */
/* Das Erzeugen des Multiple Objekt ist fehlgeschlagen. */
/* . */
/* MessageId       = 64 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_INIT_CREATE_INFO_FIELD */
/* Language        = English */
/* The creation of an information field (task state) has failed. */
/* . */
/* Language        = German */
/* Das Erzeugen eines Informationsfeldes (Taskstatus) ist fehlgeschlagen. */
/* . */
/*  */
/*  MessageId: TLR_W_TCP_ERR_INIT_TPIF_INIT_REQ_PCKT */
/*  */
/*  MessageText: */
/*  */
/*   Warning: A pending application packet has discarded (because of a new application packet). */
/*  */
#define TLR_W_TCP_ERR_INIT_TPIF_INIT_REQ_PCKT ((TLR_RESULT)0x80080043L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_INIT_OS_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   The configured operating system cycletime is out of range (0.1 ms ... 20 ms). */
/*  */
#define TLR_E_TCP_ERR_INIT_OS_CYCLETIME  ((TLR_RESULT)0xC0080044L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_INIT_OS_AND_TCPUDP_CYCLETIME */
/*  */
/*  MessageText: */
/*  */
/*   The combination of configured operating system cycletime and TCP/IP stacks cycletime (startup-parameter */
/*   ulTcpCycleEvent) is not possible. The operating system cycletime must be smaller or equal than the */
/*   TCP/IP stacks cycletime. */
/*  */
#define TLR_E_TCP_ERR_INIT_OS_AND_TCPUDP_CYCLETIME ((TLR_RESULT)0xC0080045L)

/*  Run-time Error Codes */
/* MessageId       = 111 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_TIMEOUT_INVALID */
/* Language        = English */
/* The timeout parameter is invalid. */
/* . */
/* Language        = German */
/* Der Timeout Parameter ist ungültig. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_INVALID */
/*  */
/*  MessageText: */
/*  */
/*   The socket handle ulDestId is invalid. */
/*   A further reason for this error: The command (Mode) is not applicable on this socket type (TCP/UDP). */
/*  */
#define TLR_E_TCP_ERR_SOCKET_INVALID     ((TLR_RESULT)0xC0080070L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_OPTION_NOT_SUPPORTED_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The option parameter ulOptions in command TCPIP_TCP_CMD_SEND_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_OPTION_NOT_SUPPORTED_TCP_CMD_SEND ((TLR_RESULT)0xC0080074L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PARAMETER_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The parameter in command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_PARAMETER_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080075L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_CONN_CLOSED */
/*  */
/*  MessageText: */
/*  */
/*   The connection has closed (Graceful close). */
/*  */
#define TLR_E_TCP_ERR_CONN_CLOSED        ((TLR_RESULT)0xC0080078L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_CONN_RESET */
/*  */
/*  MessageText: */
/*  */
/*   The Connection has closed by reset (Hard close). */
/*  */
#define TLR_E_TCP_ERR_CONN_RESET         ((TLR_RESULT)0xC0080079L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PROTOCOL_UNKNOWN_TCP_UDP_CMD_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   The protocol parameter ulProtocol in command TCPIP_TCP_UDP_CMD_OPEN_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_PROTOCOL_UNKNOWN_TCP_UDP_CMD_OPEN ((TLR_RESULT)0xC008007AL)

/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_SOCKETS_TCP_UDP_CMD_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_UDP_CMD_OPEN_REQ: There are no socket handles available. */
/*  */
#define TLR_E_TCP_ERR_NO_SOCKETS_TCP_UDP_CMD_OPEN ((TLR_RESULT)0xC008007BL)

/* MessageId       = 130 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_MODE_UNKNOWN */
/* Language        = English */
/* The mode parameter in command is invalid. */
/* . */
/* Language        = German */
/* Das Kommando enthält einen ungültigen Mode Parameter. */
/* . */
/* MessageId       = 131 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED */
/* Language        = English */
/* The maximum data length has exceeded. */
/* . */
/* Language        = German */
/* Die maximale Datenlänge wurde überschritten. */
/* . */
/* MessageId       = 132 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_ERR_MAX_PCKT_CNT_EXCEEDED_UDP_CMD_SEND */
/* Language        = English */
/* Command TCPIP_UDP_CMD_SEND_REQ: The maximum number of queued packets ( = TCPHDL_RCX_PCKT_QUEUED_MAX (6) ) */
/* has exceeded. The request command was rejected. The application must wait for at least one confirmation */
/* command from stack before sending the next request command. */
/* . */
/* Language        = German */
/* Kommando TCPIP_UDP_CMD_SEND_REQ: Die maximale Anzahl gequeueter Pakete ( = TCPHDL_RCX_PCKT_QUEUED_MAX (6) ) */
/* wurde überschritten. Das Request Command wurde abgelehnt. Die Applikation muss mindestens auf ein */
/* Confirmation Command vom Stack warten, bevor das nächste Request Command gesendet werden kann. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_ERR_MAX_GROUP_EXCEEDED_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ, ulMode = TCP_SOCK_ADD_MEMBERSHIP: The maximum number of */
/*   IP multicast groups has exceeded (Default configuration = 64). */
/*  */
#define TLR_E_TCP_ERR_MAX_GROUP_EXCEEDED_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080085L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DISCARD_KEPT_REQ_CMD */
/*  */
/*  MessageText: */
/*  */
/*   A kept request command has discarded. This confirmation has no further meaning for the application, unless */
/*   the application must give back this packet to their resource pool! */
/*  */
#define TLR_E_TCP_ERR_DISCARD_KEPT_REQ_CMD ((TLR_RESULT)0xC0080086L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_UNEXP_ANSWER */
/*  */
/*  MessageText: */
/*  */
/*   An unexpected/unknown confirmation command has received. */
/*  */
#define TLR_E_TCP_ERR_UNEXP_ANSWER       ((TLR_RESULT)0xC0080095L)

/* MessageId       = 151 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_MESSAGESIZE --> TLR_E_INVALID_PACKET_LEN */
/* Language        = English */
/* The packet length parameter ulLen is invalid. The correct packet lenght depends on the command parameter ulCmd. */
/* . */
/* Language        = German */
/* Die Paketlänge (Parameter ulLen) ist ungültig. Die korrekte Paketlänge hängt vom Kommando Parameter ulCmd ab. */
/* . */
/* MessageId       = 152 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_MESSAGECOMMAND --> TLR_E_UNKNOWN_COMMAND */
/* Language        = English */
/* The command ulCmd is unknown. */
/* . */
/* Language        = German */
/* Das Kommando ulCmd ist unbekannt. */
/* . */
/* MessageId       = 156 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_MESSAGESEQUENCE */
/* Language        = English */
/* Sequence error during segmented message transfer. */
/* . */
/* Language        = German */
/* Es ist ein Sequenzfehler während einem segmentierten Messagetransfer aufgetreten. */
/* . */
/* MessageId       = 158 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_MESSAGECOMMANDRUNNING */
/* Language        = English */
/* The command cannot be executed, because the previous command is still running. */
/* . */
/* Language        = German */
/* Das Kommando kann nicht ausgeführt werden, weil das vorhergehende Kommando noch läuft. */
/* . */
/*  */
/*  MessageId: TLR_E_TCP_TASK_F_NOT_INITIALIZED */
/*  */
/*  MessageText: */
/*  */
/*   The task is not initialized. */
/*  */
#define TLR_E_TCP_TASK_F_NOT_INITIALIZED ((TLR_RESULT)0xC00800C8L)

/*  */
/*  MessageId: TLR_E_TCP_TASK_F_BUSY */
/*  */
/*  MessageText: */
/*  */
/*   The task is busy (intern). */
/*  */
#define TLR_E_TCP_TASK_F_BUSY            ((TLR_RESULT)0xC00800C9L)

/* MessageId       = 210 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_DATABASE --> TLR_E_DATABASE_ACCESS_FAILED */
/* Language        = English */
/* The configuration database is not available. */
/* . */
/* Language        = German */
/* Die Parameterdatenbank ist nicht vorhanden. */
/* . */
/*  System Error Codes */
/* MessageId       = 212 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_DATABASE_READ --> TLR_E_DATABASE_ACCESS_FAILED */
/* Language        = English */
/* Error while reading configuration database. */
/* . */
/* Language        = German */
/* Beim Lesen der Parameterdatenbank ist ein Fehler aufgetreten. */
/* . */
/* MessageId       = 213 */
/* Severity        = Error */
/* Facility        = TLR_UNQ_NR_TCPIP_TCP */
/* SymbolicName    = TLR_E_TCP_TASK_F_STRUCTURE */
/* Language        = English */
/* Error while registering diagnostics structure. */
/* . */
/* Language        = German */
/* Beim Registrieren einer Diagnosestruktur ist ein Fehler aufgetreten. */
/* . */
/* //////// New rcX error codes, starting with a value bigger than the RCS error codes = 255  ////////// */
/* //////// for IP and TCP_UDP error codes!                                                   ////////// */
/* //////// The order of this errors is:                                                      ////////// */
/* ////////   - Parameter errors from application: 0x0100 ... 0x01FF                          ////////// */
/* ////////   - Local source of errors (stack)   : 0x0200 ... 0x02FF                          ////////// */
/* ////////   - Remote source of errors          : 0x0300 ... 0x03FF                          ////////// */
/* ////////   - Parameter errors from application: 0x0100 ... 0x01FF                          ////////// */
/* /// IP address invalid errors 0x0100 ... 0x010F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_IP_ADDR_INVALID_IP_CMD_PING */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_IP_CMD_PING_REQ is invalid. */
/*   This means, the IP address ulIpAddr is equal to the TCP/IP stacks own IP address. */
/*  */
#define TLR_E_IP_ERR_IP_ADDR_INVALID_IP_CMD_PING ((TLR_RESULT)0xC0070100L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_TCP_UDP_CMD_OPEN_REQ is invalid. */
/*   The parameter ulIpAddr must be zero (0.0.0.0) or equal to the TCP/IP stacks own IP address. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_OPEN ((TLR_RESULT)0xC0080101L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_TCP_CMD_CONNECT_REQ is invalid. */
/*   The parameter ulIpAddr must be unequal to the TCP/IP stacks own IP address. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080102L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_UDP_CMD_SEND_REQ is invalid or doesn't match to the local sub network. */
/*   This error occurs, if the IP address is zero (0.0.0.0) or equal to the address of the local subnet. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_UDP_CMD_SEND ((TLR_RESULT)0xC0080103L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The parameter ulMulticastGroup (ulMode = TCP_SOCK_ADD_MEMBERSHIP or TCP_SOCK_DROP_MEMBERSHIP) in command */
/*   TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ is invalid. */
/*   The parameter ulMulticastGroup must be a valid Multicast address. */
/*   Valid Multicast addresses are 224.0.0.1 ... 239.255.255.255 (224.0.0.0 is reserved as Base-multicast address). */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080104L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_BIND */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr in command TCPIP_TCP_UDP_CMD_BIND_REQ is invalid. */
/*   The parameter ulIpAddr must be zero (0.0.0.0) or equal to the TCP/IP stacks own IP address. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_TCP_UDP_CMD_BIND ((TLR_RESULT)0xC0080105L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_IP_ADDR_INVALID_NO_GATEWAY */
/*  */
/*  MessageText: */
/*  */
/*   The IP address parameter ulIpAddr is invalid, because there is no gateway configured. */
/*   The parameter ulIpAddr must be inside the local network. */
/*  */
#define TLR_E_TCP_ERR_IP_ADDR_INVALID_NO_GATEWAY ((TLR_RESULT)0xC0080106L)

/* /// Port invalid errors 0x0110 ... 0x011F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_PORT_INVALID_TCP_UDP_CMD_OPEN */
/*  */
/*  MessageText: */
/*  */
/*   The port parameter ulPort in command TCPIP_TCP_UDP_CMD_OPEN_REQ is invalid or not available. */
/*   The parameter ulPort must be in range 0 ... 65535. */
/*  */
#define TLR_E_TCP_ERR_PORT_INVALID_TCP_UDP_CMD_OPEN ((TLR_RESULT)0xC0080110L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PORT_INVALID_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The port parameter ulPort in command TCPIP_TCP_CMD_CONNECT_REQ is invalid or not available. */
/*   The parameter ulPort must be in range 1 ... 65535. */
/*  */
#define TLR_E_TCP_ERR_PORT_INVALID_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080111L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PORT_INVALID_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The port parameter ulPort in command TCPIP_UDP_CMD_SEND_REQ is invalid or not available. */
/*   The parameter ulPort must be in range 0 ... 65535. */
/*  */
#define TLR_E_TCP_ERR_PORT_INVALID_UDP_CMD_SEND ((TLR_RESULT)0xC0080112L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_PORT_INVALID_TCP_UDP_CMD_BIND */
/*  */
/*  MessageText: */
/*  */
/*   The port parameter ulPort in command TCPIP_TCP_UDP_CMD_BIND_REQ is invalid or not available. */
/*   The parameter ulPort must be in range 0 ... 65535. */
/*  */
#define TLR_E_TCP_ERR_PORT_INVALID_TCP_UDP_CMD_BIND ((TLR_RESULT)0xC0080113L)

/* /// Timeout invalid errors 0x0120 ... 0x012F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_TIMEOUT_INVALID_IP_CMD_PING */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeout in command TCPIP_IP_CMD_PING_REQ is invalid. */
/*  */
#define TLR_E_IP_ERR_TIMEOUT_INVALID_IP_CMD_PING ((TLR_RESULT)0xC0070120L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_CLOSE */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeout in command TCPIP_TCP_UDP_CMD_CLOSE_REQ is invalid. */
/*   Consider the distinction between TCP and UDP sockets! For UDP sockets, ulTimeout must be zero. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_CLOSE ((TLR_RESULT)0xC0080121L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_CLOSE_ALL */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeout in command TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_CLOSE_ALL ((TLR_RESULT)0xC0080122L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_CMD_WAIT_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeoutSend and/or ulTimeoutListen in command TCPIP_TCP_CMD_WAIT_CONNECT_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_CMD_WAIT_CONNECT ((TLR_RESULT)0xC0080123L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeoutSend and/or ulTimeoutConnect in command TCPIP_TCP_CMD_CONNECT_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080124L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The timeout parameter ulTimeoutSend (ulMode = TCP_SOCK_SEND_TIMEOUT) or ulTimeoutInactive */
/*   (ulMode = TCP_SOCK_INACTIVE_TIMEOUT) or ulTimeoutKeepAlive (ulMode = TCP_SOCK_KEEPALIVE_TIMEOUT) */
/*   in command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_INVALID_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080125L)

/* /// Mode unknown errors 0x0130 ... 0x013F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_MODE_UNKNOWN_IP_CMD_SET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The mode parameter ulMode in command TCPIP_IP_CMD_SET_PARAM_REQ is invalid. */
/*  */
#define TLR_E_IP_ERR_MODE_UNKNOWN_IP_CMD_SET_PARAM ((TLR_RESULT)0xC0070130L)

/*  */
/*  MessageId: TLR_E_IP_ERR_MODE_UNKNOWN_IP_CMD_GET_PARAM */
/*  */
/*  MessageText: */
/*  */
/*   The mode parameter ulMode in command TCPIP_IP_CMD_GET_PARAM_REQ is invalid. */
/*  */
#define TLR_E_IP_ERR_MODE_UNKNOWN_IP_CMD_GET_PARAM ((TLR_RESULT)0xC0070131L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_MODE_UNKNOWN_TCP_UDP_CMD_SET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The mode parameter ulMode in command TCPIP_TCP_UDP_CMD_SET_SOCK_OPTION_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_MODE_UNKNOWN_TCP_UDP_CMD_SET_SOCK_OPTION ((TLR_RESULT)0xC0080132L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_MODE_UNKNOWN_TCP_UDP_CMD_GET_SOCK_OPTION */
/*  */
/*  MessageText: */
/*  */
/*   The mode parameter ulMode in command TCPIP_TCP_UDP_CMD_GET_SOCK_OPTION_REQ is invalid. */
/*  */
#define TLR_E_TCP_ERR_MODE_UNKNOWN_TCP_UDP_CMD_GET_SOCK_OPTION ((TLR_RESULT)0xC0080133L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_MODE_UNKNOWN_FATAL_DUMMY */
/*  */
/*  MessageText: */
/*  */
/*   Internal fatal error in module TcpipTcphdlPckt.c! */
/*  */
#define TLR_E_TCP_ERR_MODE_UNKNOWN_FATAL_DUMMY ((TLR_RESULT)0xC0080134L)

/* /// Data len errors 0x0140 ... 0x014F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The maximum TCP data count n in command TCPIP_TCP_CMD_SEND_REQ has exceeded. See parameter ulLen. */
/*   The maximum value for n is TCPIP_MAX_TCP_DATA_CNT (1460). */
/*  */
#define TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED_TCP_CMD_SEND ((TLR_RESULT)0xC0080140L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The maximum UDP data count n in command TCPIP_UDP_CMD_SEND_REQ has exceeded. See parameter ulLen. */
/*   The maximum value for n is TCPIP_MAX_UDP_DATA_CNT (1472). */
/*  */
#define TLR_E_TCP_ERR_MAX_DATA_LEN_EXCEEDED_UDP_CMD_SEND ((TLR_RESULT)0xC0080141L)

/* /// IP Configuration errors 0x0150 ... 0x015F (reserved) - implemented further checkings ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_INIT_INVALID_FLAGS_IP_CONFIG */
/*  */
/*  MessageText: */
/*  */
/*   The start parameters configures an invalid flag combination for the manual IP configuration */
/*   (IP_CFG_FLAG_IP_ADDR, IP_CFG_FLAG_NET_MASK, IP_CFG_FLAG_GATEWAY). */
/*   Valid flag combinations are: */
/*   - No flag set: No manual configuration - only DHCP and/or BOOTP */
/*   - IP_CFG_FLAG_IP_ADDR + IP_CFG_FLAG_NET_MASK: Local network without gateway */
/*   - IP_CFG_FLAG_IP_ADDR + IP_CFG_FLAG_NET_MASK + IP_CFG_FLAG_GATEWAY: Network with gateway. */
/*  */
#define TLR_E_IP_ERR_INIT_INVALID_FLAGS_IP_CONFIG ((TLR_RESULT)0xC0070150L)

/* ////////   - Local source of errors (stack)   : 0x0200 ... 0x02FF                          ////////// */
/* /// Socket state errors 0x0200 ... 0x020F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_WAIT_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_TCP_CMD_WAIT_CONNECT_REQ cannot be executed, because the socket is in an inappropriate state. */
/*  */
#define TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_WAIT_CONNECT ((TLR_RESULT)0xC0080200L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_TCP_CMD_CONNECT_REQ cannot be executed, because the socket is in an inappropriate state. */
/*  */
#define TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080201L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_TCP_CMD_SEND_REQ cannot be executed, because the socket is in an inappropriate state. */
/*  */
#define TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_SEND ((TLR_RESULT)0xC0080202L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_BIND */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_TCP_UDP_CMD_BIND_REQ cannot be executed, because the TCP socket is in an inappropriate state. */
/*  */
#define TLR_E_TCP_ERR_SOCKET_STATE_TCP_CMD_BIND ((TLR_RESULT)0xC0080203L)

/* /// Resource errors (queues, buffers) 0x0210 ... 0x021F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_FREE_QUEUE_ELEMENT_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The TCP send command TCPIP_TCP_CMD_SEND_REQ must be rejected, because the list of free queue elements is empty. */
/*   Remark: Per default configuration, the initial size of this list is 128. */
/*   Every send command (TCPIP_TCP_CMD_SEND_REQ or TCPIP_UDP_CMD_SEND_REQ) occupy one queue element, until the */
/*   confirmation command is given back to the application. To avoid this resource problem, the application must */
/*   reduce the count of open send jobs over all sockets. */
/*  */
#define TLR_E_TCP_ERR_NO_FREE_QUEUE_ELEMENT_TCP_CMD_SEND ((TLR_RESULT)0xC0080210L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_FREE_QUEUE_ELEMENT_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The UDP send command TCPIP_UDP_CMD_SEND_REQ must be rejected, because the list of free queue elements is empty. */
/*   Remark: Per default configuration, the initial size of this list is 128. */
/*   Every send command (TCPIP_TCP_CMD_SEND_REQ or TCPIP_UDP_CMD_SEND_REQ) occupy one queue element, until the */
/*   confirmation command is given back to the application. To avoid this resource problem, the application must */
/*   reduce the count of open send jobs over all sockets. */
/*  */
#define TLR_E_TCP_ERR_NO_FREE_QUEUE_ELEMENT_UDP_CMD_SEND ((TLR_RESULT)0xC0080211L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_ETH_OUT_BUFFER_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The UDP send command TCPIP_UDP_CMD_SEND_REQ must be rejected, because all outgoing Ethernet buffers are occupied. */
/*  */
#define TLR_E_TCP_ERR_NO_ETH_OUT_BUFFER_UDP_CMD_SEND ((TLR_RESULT)0xC0080212L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_NO_FREE_RESOURCE_FOR_ARP_REQ_INTF */
/*  */
/*  MessageText: */
/*  */
/*   The command TCPIP_IP_CMD_SET_PARAM_REQ in mode IP_PRM_SEND_ARP_REQ/IP_PRM_SEND_ARP_TMT_REQ must be rejected, */
/*   because all free resources for this command are occupied. A maximum of 128 parallel jobs is possible. */
/*  */
#define TLR_E_TCP_ERR_NO_FREE_RESOURCE_FOR_ARP_REQ_INTF ((TLR_RESULT)0xC0080213L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_ETH_OUT_SEND_BUFFER */
/*  */
/*  MessageText: */
/*  */
/*   The send of the outgoing Ethernet buffer has failed. The reason of this error is normally a */
/*   resource problem - there is no EDD buffer available. */
/*  */
#define TLR_E_TCP_ERR_ETH_OUT_SEND_BUFFER ((TLR_RESULT)0xC0080214L)

/* /// Multicast errors 0x0220 ... 0x022F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_TCP_ERR_MCAST_CREATE */
/*  */
/*  MessageText: */
/*  */
/*   Failed to create an IP Multicast group. */
/*  */
#define TLR_E_TCP_ERR_MCAST_CREATE       ((TLR_RESULT)0xC0080220L)

/* ////////   - Remote source of errors          : 0x0300 ... 0x03FF                          ////////// */
/* /// Destination unreachable errors 0x0300 ... 0x030F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_DEST_UNREACHABLE_IP_CMD_PING */
/*  */
/*  MessageText: */
/*  */
/*   The target IP address ulIpAddr in command TCPIP_IP_CMD_PING_REQ is not reachable. */
/*  */
#define TLR_E_IP_ERR_DEST_UNREACHABLE_IP_CMD_PING ((TLR_RESULT)0xC0070300L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_UDP_CMD_CLOSE */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_UDP_CMD_CLOSE_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_UDP_CMD_CLOSE ((TLR_RESULT)0xC0080301L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_UDP_CMD_CLOSE_ALL */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_UDP_CMD_CLOSE_ALL ((TLR_RESULT)0xC0080302L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_CMD_WAIT_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_CMD_WAIT_CONNECT_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_CMD_WAIT_CONNECT ((TLR_RESULT)0xC0080303L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_TCP_CMD_CONNECT_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080304L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_DEST_UNREACHABLE_UDP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   Command TCPIP_UDP_CMD_SEND_REQ: The destination (host, network, or port) is unreachable. */
/*  */
#define TLR_E_TCP_ERR_DEST_UNREACHABLE_UDP_CMD_SEND ((TLR_RESULT)0xC0080305L)

/* /// Timeout errors 0x0310 ... 0x031F (reserved) ///// */
/*  */
/*  MessageId: TLR_E_IP_ERR_TIMEOUT_IP_CMD_PING */
/*  */
/*  MessageText: */
/*  */
/*   The specified timeout ulTimeout in command TCPIP_IP_CMD_PING_REQ has expired. */
/*   The specified host is not reachable. */
/*  */
#define TLR_E_IP_ERR_TIMEOUT_IP_CMD_PING ((TLR_RESULT)0xC0070310L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_UDP_CMD_CLOSE */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Close timeout has expired. A connection to the remote host could not be closed gracefully */
/*   within this time. */
/*   For this timeout, see command TCPIP_TCP_UDP_CMD_CLOSE_REQ, parameter ulTimeout. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_UDP_CMD_CLOSE ((TLR_RESULT)0xC0080311L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_UDP_CMD_CLOSE_ALL */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Close timeout has expired. One or more connections to remote host(s) could not be closed gracefully */
/*   within this time. */
/*   For this timeout, see command TCPIP_TCP_UDP_CMD_CLOSE_ALL_REQ, parameter ulTimeout. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_UDP_CMD_CLOSE_ALL ((TLR_RESULT)0xC0080312L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_WAIT_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Connect timeout has expired. No remote host has connected within this time. */
/*   For this timeout, see command TCPIP_TCP_CMD_WAIT_CONNECT_REQ, parameter ulTimeoutListen. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_WAIT_CONNECT ((TLR_RESULT)0xC0080313L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_CONNECT */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Connect timeout has expired. A connection to the specified remote host could not be established */
/*   within this time. */
/*   For this timeout, see command TCPIP_TCP_CMD_CONNECT_REQ, parameter ulTimeoutConnect. */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_CONNECT ((TLR_RESULT)0xC0080314L)

/*  */
/*  MessageId: TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_SEND */
/*  */
/*  MessageText: */
/*  */
/*   The TCP Send timeout has expired by sending TCP data with command TCPIP_TCP_CMD_SEND_REQ. */
/*   The remote host has not answered within the Send Timeout. */
/*   The TCP Send timeout is set in command TCPIP_TCP_CMD_WAIT_CONNECT_REQ or */
/*   TCPIP_TCP_CMD_CONNECT_REQ, parameter ulTimeoutSend (Default = 31 s). */
/*  */
#define TLR_E_TCP_ERR_TIMEOUT_TCP_CMD_SEND ((TLR_RESULT)0xC0080315L)

/* /// Further errors 0x0xxx ... ///// */



#endif  /* __TCPIP_ERROR_H */

