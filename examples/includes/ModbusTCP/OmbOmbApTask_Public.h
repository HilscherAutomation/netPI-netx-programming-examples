/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: OmbOmbApTask_Public.h 3662 2015-09-30 07:23:53Z iborisov $:
Description:
Omb Application Task
Includes following functions...
**************************************************************************************/

/**
 * @file OmbOmbApTask_Public.h
 *  Omb OmbApTask - public definition of task
 *
 * The header contains the public definition of task.
 * It has to be included by another task to get access of task specfic definition.
 *
 * @note
 * The structures for the services must be packed on 1 byte of boundary.
 * The <code>#pragma</code> instructions are already planned for Microsoft compiler.
 * For gnu's compiler and Realview compiler the macros <code>__PACKED_PRE</code>
 * and <code>__PACKED_PRE</code> have to be added with the structural definition
 * in addition.
 */
#ifndef __OMB_OMBAPTASK_PUBLIC_H
#define __OMB_OMBAPTASK_PUBLIC_H


/*************************************************************************************/
/** @name Queue Name
 *
 * Use the queue name to identify the process queue of task 'Omb OmbApTask'.
 * Example for internal identification:<br>
 * @code
 * TLR_RESULT eRslt;
 * TLR_HANDLE hQue;
 * TLR_UINT   uiInstance = 0;
 *
 * eRslt = TLR_QUE_IDENTIFY_INTERN(
 *                                 OMB_OMBAPTASK_QUEUE_NAME,
 *                                 uiInstance,
 *                                 &hQue
 *                                );
 * @endcode
 * <br>
 * Example for external or normal identification:<br>
 * @code
 * TLR_RESULT      eRslt;
 * TLR_QUE_LINK_T  tQue;
 * TLR_UINT        uiInstance = 0;
 *
 * eRslt = TLR_QUE_IDENTIFY(OMB_OMBAPTASK_QUEUE_NAME, uiInstance, &tQue);
 * @endcode
 * <br>
 * @{
 */
/** queue name */
#define OMB_OMBAPTASK_QUEUE_NAME        "QUE_OMBAPTASK"

/** Task name */
#define OMB_AP_TASK_NAME                "OMB_AP"


/** @} */


/****************************************************************************************
* OMB OMBAPTASK, Public defines */


/****************************************************************************************
* OMB OMBAPTASK, command codes  */


/****************************************************************************************
* OMB OMBAPTASK, Structs */

/* Compiler settings */
#if _MSC_VER >= 1000
  #define __OMBAP_PACKED_PRE
  #define __OMBAP_PACKED_POST
  #pragma once
  #pragma pack(1)            /* Always align structures to byte boundery */
  #ifndef STRICT             /* Check Typdefinition */
    #define STRICT
  #endif
#endif /* _MSC_VER >= 1000 */

/* support for GNU compiler */
#ifdef __GNUC__
  #define __OMBAP_PACKED_PRE
  #define __OMBAP_PACKED_POST    __attribute__((__packed__))
#endif

/* support for REALVIEW ARM compiler */
#if defined (__ADS__) || defined (__REALVIEW__)
  #define __OMBAP_PACKED_PRE   __packed
  #define __OMBAP_PACKED_POST
#endif


/*************************************************************************************/
/* Omb OmbApTask public, packets */


/*
 * Structures of all Request/Confirmation commands the task is able to send and receive
 *
 * Request and Confirmation Packets __PREFIX___PACKET___TASKNAME___xx_REQ/CNF
 * (xx = Command)
 *
 * Use the same order as the commands in TLR_Commands.h
 * __PREFIX_____TASKNAME___xx_REQ/CNF (xx = Command)!
 */




/*** Definition of the packet types this Task is able to receive/send as server ***/

/* Set Bus on (command RCX_START_STOP_COMM_REQ) */

/* Request */
typedef __OMBAP_PACKED_PRE struct OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_REQ_Ttag
{
  TLR_BOOLEAN32  fBusOn;    /* Bus-on */

} __OMBAP_PACKED_POST OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_REQ_T;

#define OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_REQ_SIZE  \
                    (sizeof(OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_REQ_T))

typedef __OMBAP_PACKED_PRE struct OMB_OMBAPTASK_PACKET_CMD_SET_BUS_ON_REQ_Ttag
{
  TLR_PACKET_HEADER_T                      tHead;
  OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_REQ_T  tData;

} __OMBAP_PACKED_POST OMB_OMBAPTASK_PACKET_CMD_SET_BUS_ON_REQ_T;


/* Confirmation */
typedef __OMBAP_PACKED_PRE struct OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_CNF_Ttag
{
  TLR_BOOLEAN32  fBusOn;    /* Bus-on */

} __OMBAP_PACKED_POST OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_CNF_T;

#define OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_CNF_SIZE  \
                    (sizeof(OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_CNF_T))

typedef __OMBAP_PACKED_PRE struct OMB_OMBAPTASK_PACKET_CMD_SET_BUS_ON_CNF_Ttag
{
  TLR_PACKET_HEADER_T                      tHead;
  OMB_OMBAPTASK_DATA_CMD_SET_BUS_ON_CNF_T  tData;

} __OMBAP_PACKED_POST OMB_OMBAPTASK_PACKET_CMD_SET_BUS_ON_CNF_T;


/*---------------------------------------------------------------------------*/
/* Compiler settings */
#if _MSC_VER >= 1000
  #pragma pack()           /* Always allign structures to compiler settings  */
#endif /* _MSC_VER >= 1000 */
/*---------------------------------------------------------------------------*/

#undef __OMBAP_PACKED_PRE
#undef __OMBAP_PACKED_POST

/*************************************************************************************/
#endif /* #ifndef __OMB_OMBAPTASK_PUBLIC_H */
