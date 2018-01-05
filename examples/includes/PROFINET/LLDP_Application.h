/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: LLDP_Application.h 58013 2015-12-08 07:47:36Z Artem $:

Description:
 LLDP
 Includes packet structure definitions of services offered by LLDP task to applications

Changes:
 Date          Description
 -----------------------------------------------------------------------------------
 2014-08-25    created
**************************************************************************************/
#ifndef __LLDP_APPLICATION_H
#define __LLDP_APPLICATION_H

/* message queue name to identify */
#define LLDP_PROCESS_QUEUE_NAME    "QUE_LLDP"

#define __PACKED_PRE                                /* redefinition to prevent warnings */
#define __PACKED_POST __attribute__ ((__packed__))  /* redefinition to prevent warnings */


/* commands used by application */
typedef enum LLDP_APP_APPLICATION_COMMANDSTag
{
  /* set parameter request */
  TLR_APP_CMD_SET_PARAM_REQ                       = 0x00002304,
  TLR_APP_CMD_SET_PARAM_CNF                       = 0x00002305,
  /* indication to application registered for receiving a custom TLV */
  LLDP_APP_CMD_CUSTOM_TLV_DATA_CHANGE_IND         = 0x00002312,
  LLDP_APP_CMD_CUSTOM_TLV_DATA_CHANGE_RES         = 0x00002313,

} LLDP_APP_COMMANDS;


/**
 * Flags to use in Destination Id when registering application to LLDP
 */
typedef enum {
  LLDP_APP_CUSTOM_TLV  = 0x0008,
} LLDP_APP_FLAGS_E;


/***************************************************************************************/
/* Setting parameters. Constants define the type of the following parameter structure */
#define LLDP_APP_SET_PARAM_TYPE_END_OF_DATA                  (0)
#define LLDP_APP_SET_PARAM_TYPE_TX_INTERVAL_PORT             (32)
#define LLDP_APP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT     (33)
#define LLDP_APP_SET_PARAM_TYPE_UPDATE_DATA_CUSTOM_TLV_PORT  (34)

/***************************************************************************************/
/** SETTING PARAMETERS **/
/***************************************************************************************/

typedef __PACKED_PRE struct __PACKED_POST LLDP_SET_PARAM_DATA_Ttag
{
  TLR_UINT    uiReserved; /* the first type value of any LLDP_APP_SET_PARAM_TYPE_***  */
}LLDP_SET_PARAM_DATA_T;

/* set parameters request packet */
typedef __PACKED_PRE struct __PACKED_POST LLDP_SET_PARAM_PCK_Ttag
{
  TLR_PACKET_HEADER_T   tHead;
  LLDP_SET_PARAM_DATA_T tData;
}LLDP_SET_PARAM_PCK_T;

/* set parameters confirmation packet */
typedef __PACKED_PRE struct __PACKED_POST LLDP_SET_PARAM_CNF_Ttag
{
  TLR_PACKET_HEADER_T   tHead;
}LLDP_SET_PARAM_CNF_T;


/* message tx interval on specific port. TYPE = LLDP_APP_SET_PARAM_TYPE_TX_INTERVAL_PORT */
typedef __PACKED_PRE struct __PACKED_POST LLDP_SET_PARAM_TX_INTERVAL_PORT_Ttag
{
  TLR_UINT32  ulPortNum;      /* on which port is the uiTxInterval_ms applied */
  TLR_UINT  uiTxInterval_ms;  /* time interval in ms */
}LLDP_SET_PARAM_TX_INTERVAL_PORT_T;



#define LLDP_TLV_OUC_SUBTYPE_LENGHT   4   /* length of OUC(3) plus Subtype(1) */

/* allowed range for the data lenght usDataLen of the lldp set parameter request LLDP_APP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT in structure LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_PORT_T */
#define LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_DL_MIN         (1)    /* because 0 make no sence */
#define LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_DL_MAX         (511-LLDP_TLV_OUC_SUBTYPE_LENGHT)/* full 9 bit value(511) - OUC(3) - Subtype(1) */

/* allowed flags for the field usFlags of the lldp set parameter request LLDP_APP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT in structure LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_PORT_T */
#define LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_F_SEND         (1)
#define LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_F_RECEIVE      (2)
#define LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_F_ALLOWEDMASK  (LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_F_SEND|LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_F_RECEIVE)

/* parameterization to register customer's tlv on specific port. TYPE = LLDP_APP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT */
typedef __PACKED_PRE struct __PACKED_POST LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_PORT_Ttag
{
  TLR_UINT32  ulPortNum;       /* on which port is the uiTxInterval_ms applied. [0 - till tStartUpParam.uiPortsNum) */
  TLR_UINT32  ulOUC_ST;        /* Organization Unique Code  [3 high bytes] and TLV SubType [lowest byte] */
  TLR_UINT16  usDataLen;       /* the length of "process" data (TLV values, transfered in frame after Organization Unique Code) */
  TLR_UINT16  usFlags;         /* flags: is this TLV for sending, receiving or both directions */
}LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_PORT_T;

/* parameterization to update customer's tlv data to sending on specific port. TYPE = LLDP_APP_SET_PARAM_TYPE_UPDATE_DATA_CUSTOM_TLV_PORT */
typedef __PACKED_PRE struct __PACKED_POST LLDP_SET_PARAM_UPDATE_CUSTOM_TLV_DATA_Ttag
{
  TLR_UINT32  ulPortNum;       /* on which port is the uiTxInterval_ms applied. [0 - till tStartUpParam.uiPortsNum) */
  TLR_UINT32  ulOUC_ST;        /* Organization Unique Code  [3 high bytes] and TLV SubType [lowest byte] */
  TLR_UINT16  usDataLen;       /* the length of "process" data (TLV values, transfered in frame after Organization Unique Code) */
  TLR_UINT8   abData[1];       /* data to update: real length is "usDataLen" */
}LLDP_SET_PARAM_UPDATE_CUSTOM_TLV_DATA_T;



/****************************************************************************************/
/* Customer's registered TLV - data change indication */


/* data block for indication on data change in the customer's registered TLV  */
typedef __PACKED_PRE struct __PACKED_POST LLDP_CUSTOM_REGISTERED_TLV_BLOCK_Ttag
{
  /* Organization Unique Code (3 bytes) and TLV SubType (value used on LLDP_SET_PARAM_REGISTER_CUSTOM_TLV_PORT_T) */
  TLR_UINT32    ulOUC_ST;
  /* Length of data */
  TLR_UINT16    usLength;
  /* Data: real length of this array is "usLength" */
  TLR_UINT8     abData[];

}LLDP_CUSTOM_REGISTERED_TLV_BLOCK_T;

/* data of the packet assigned to indicate an application about changes in the customer's registered TLV  */
typedef __PACKED_PRE struct __PACKED_POST LLDP_CUSTOM_REGISTERED_TLV_DATA_CHANGE_DATA_Ttag
{
  /* Local Port ID */
  TLR_UINT32    ulPortNum;
  /* Blocks of data of the customer's TLV. Defined only one but it can have more. Each following block is 4 bytes aligned! */
  LLDP_CUSTOM_REGISTERED_TLV_BLOCK_T atTLVBlock[1];

}LLDP_CUSTOM_REGISTERED_TLV_DATA_CHANGE_DATA_T;

/* Data change indication packet for customer's registered TLV */
typedef struct LLDP_CUSTOM_REGISTERED_TLV_DATA_CHANGE_IND_Ttag
{
  /* packet header */
  TLR_PACKET_HEADER_T             tHead;
  /* packet data */
  LLDP_CUSTOM_REGISTERED_TLV_DATA_CHANGE_DATA_T    tData;
}LLDP_CUSTOM_REGISTERED_TLV_DATA_CHANGE_IND_T;



/***************************************************************************************/
/** ERROR codes **/


//
// MessageId: TLR_E_CONFIG_MIN_TX_INTERVAL
//
// MessageText:
//
//  Configured a too short TX interval
//
#define TLR_E_CONFIG_MIN_TX_INTERVAL     ((TLR_RESULT)0xC03E0018L)

//
// MessageId: TLR_E_LENGTH_PARAM_TYPE_TX_INTERVAL_PORT
//
// MessageText:
//
//  One of parameters has wrong type (length) in the request TLR_CMD_SET_PARAM_REQ for parameter LLDP_SET_PARAM_TYPE_TX_INTERVAL_PORT
//
#define TLR_E_LENGTH_PARAM_TYPE_TX_INTERVAL_PORT ((TLR_RESULT)0xC03E0061L)

//
// MessageId: TLR_E_LENGTH_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT
//
// MessageText:
//
//  One of parameters has wrong type (length) in the request TLR_CMD_SET_PARAM_REQ for parameter LLDP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT
//
#define TLR_E_LENGTH_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT ((TLR_RESULT)0xC03E0062L)

//
// MessageId: TLR_E_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT_WRONG_DATALEN
//
// MessageText:
//
//  Wrong value in length of data for custom TLV in the request TLR_CMD_SET_PARAM_REQ for parameter LLDP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT
//
#define TLR_E_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT_WRONG_DATALEN ((TLR_RESULT)0xC03E0063L)

//
// MessageId: TLR_E_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT_WRONG_FLAGS
//
// MessageText:
//
//  Wrong flags in the request TLR_CMD_SET_PARAM_REQ for parameter LLDP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT
//
#define TLR_E_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT_WRONG_FLAGS ((TLR_RESULT)0xC03E0064L)

//
// MessageId: TLR_E_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT_ALREADY_REGISTERED_RX
//
// MessageText:
//
//  TLV in the request TLR_CMD_SET_PARAM_REQ for parameter LLDP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT already registered for receiving
//
#define TLR_E_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT_ALREADY_REGISTERED_RX ((TLR_RESULT)0xC03E0065L)

//
// MessageId: TLR_E_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT_ALREADY_REGISTERED_TX
//
// MessageText:
//
//  TLV in the request TLR_CMD_SET_PARAM_REQ for parameter LLDP_SET_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT already registered for sending
//
#define TLR_E_PARAM_TYPE_REGISTER_CUSTOM_TLV_PORT_ALREADY_REGISTERED_TX ((TLR_RESULT)0xC03E0066L)

//
// MessageId: TLR_E_LENGTH_PARAM_TYPE_UPDATE_CUSTOM_TLV_DATA
//
// MessageText:
//
//  Wrong length of data for custom TLV in the request TLR_CMD_SET_PARAM_REQ for parameter LLDP_SET_PARAM_TYPE_UPDATE_DATA_CUSTOM_TLV_PORT
//
#define TLR_E_LENGTH_PARAM_TYPE_UPDATE_CUSTOM_TLV_DATA ((TLR_RESULT)0xC03E0067L)

//
// MessageId: TLR_E_PARAM_TYPE_UPDATE_CUSTOM_TLV_DATA_TLVNOTFOUND
//
// MessageText:
//
//  Required TLV not found for data update. Wrong TLV in the request TLR_CMD_SET_PARAM_REQ for parameter LLDP_SET_PARAM_TYPE_UPDATE_DATA_CUSTOM_TLV_PORT
//
#define TLR_E_PARAM_TYPE_UPDATE_CUSTOM_TLV_DATA_TLVNOTFOUND ((TLR_RESULT)0xC03E0068L)

#endif /* #ifndef __LLDP_APPLICATION_H */
