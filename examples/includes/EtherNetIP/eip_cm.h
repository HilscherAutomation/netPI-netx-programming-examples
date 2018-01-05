/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of EtherNet/IP Connection Manager Object

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2014-01-16  RH            Created
**************************************************************************************/
#ifndef EIP_CM_H
#define EIP_CM_H


  /*#####################################################################################*/

  /*
    ************************************************************
    *  Object specific defines
    ************************************************************
  */
  #define EIP_CM_CLASS_NUMBER            0x06
  #define EIP_CM_REVISION                1
  #define EIP_CM_MAX_INSTANCE            1
  #define EIP_CM_MAX_CLASS_ATTR          7
  #define EIP_CM_MAX_INSTANCE_ATTR       1

    /* attributes of identity object */
  #define EIP_CM_ATTR_1_OPEN_REQUESTS     1

  #define CIP_CMD_FORWARD_CLOSE           ( 0x4E )
  #define CIP_CMD_UNCONNECTED_SEND        ( 0x52 )
  #define CIP_CMD_FORWARD_OPEN            ( 0x54 )
  #define CIP_CMD_GET_CONNECTION_DATA     ( 0x56 )
  #define CIP_CMD_SEARCH_CONNECTION_DATA  ( 0x57 )
  #define CIP_CMD_GET_CONNECTION_OWNER    ( 0x5A )
  #define CIP_CMD_LARGE_FORWARD_OPEN      ( 0x5B )

  /* Connection parameter */
  #define EIP_CM_PARAM_REDUNDANT_MASK     0x8000
  #define EIP_CM_PARAM_EXCLUSIVE_OWNER    0x0000
  #define EIP_CM_PARAM_REDUNDANT_OWNER    0x8000

  #define EIP_CM_PARAM_TYPE_MASK          0x6000
  #define EIP_CM_PARAM_TYPE_NULL          0x0000
  #define EIP_CM_PARAM_TYPE_MULTICAST     0x2000
  #define EIP_CM_PARAM_TYPE_POINT         0x4000
  #define EIP_CM_PARAM_TYPE_RESERVED      0x6000

  #define EIP_CM_PARAM_PRIORITY_MASK      0x0C00
  #define EIP_CM_PARAM_PRIORITY_LOW       0x0000
  #define EIP_CM_PARAM_PRIORITY_HIGH      0x0400
  #define EIP_CM_PARAM_PRIORITY_SCHEDULED 0x0800
  #define EIP_CM_PARAM_PRIORITY_URGENT    0x0C00

  #define EIP_CM_PARAM_FIXED_VAR_MASK     0x0200
  #define EIP_CM_PARAM_VARIABLE_SIZE      0x0200
  #define EIP_CM_PARAM_FIXED_SIZE         0x0000

  #define EIP_CM_PARAM_SIZE_MASK          0x01FF

  /* transportClass_Trigger */
  #define EIP_CM_TYPTRIG_DIR_MASK         0x80
  #define EIP_CM_TYPTRIG_DIR_CLIENT       0x00
  #define EIP_CM_TYPTRIG_DIR_SERVER       0x80

  #define EIP_CM_TYPTRIG_TRIG_MASK        0x70
  #define EIP_CM_TYPTRIG_TRIG_CYCLIC      0x00
  #define EIP_CM_TYPTRIG_TRIG_COF         0x10
  #define EIP_CM_TYPTRIG_TRIG_APP         0x20

  #define EIP_CM_TYPTRIG_TYP_MASK         0x0F
  #define EIP_CM_TYPTRIG_TYP_CL0          0x00
  #define EIP_CM_TYPTRIG_TYP_CL1          0x01
  #define EIP_CM_TYPTRIG_TYP_CL2          0x02
  #define EIP_CM_TYPTRIG_TYP_CL3          0x03


  #define EIP_DEFAULT_PATH_LEN              16
  #define EIP_DEFAULT_ADDSTATUS_IDX          1

  #define EIP_FWDOPEN_SIZE_MSK            0x01FF
  #define EIP_FWDOPEN_PARAM_MSK           0xFE00
  #define EIP_LFWDOPEN_SIZE_MSK           0x0000FFFF
  #define EIP_LFWDOPEN_PARAM_MSK          0xFE000000


  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific types
  ************************************************************
  */

#pragma pack(1)

  /* Connection Manager Object - Class Attributes */
  typedef __PACKED_PRE struct  EIP_CM_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;        /* 1 */
    uint16_t  usMaxInstance;     /* 2 */
    uint16_t  usNumInstance;     /* 3 */
    uint16_t  usMaxClassAttr;    /* 6 */
    uint16_t  usMaxInstanceAttr; /* 7 */
  } __PACKED_POST EIP_CM_CLASS_ATTR_T;

  /*#####################################################################################*/

  /* Connection Manager Object - Instance Attributes */
  typedef __PACKED_PRE struct EIP_CM_INST_ATTR_Ttag
  {
    uint16_t                    usOpenRequests;
  } __PACKED_POST EIP_CM_INST_ATTR_T;

  /*#####################################################################################*/

  /* Forward Open Service - Request Data */
  typedef __PACKED_PRE struct EIP_CM_FWOPEN_REQ_Ttag
  {
    uint8_t   bPriority;          /* used to calculate request timeout information   */
    uint8_t   bTimeOutTicks;      /* used to calculate request timeout information   */
    uint32_t  ulOTConnID;         /* Network connection ID orginator to target       */
    uint32_t  ulTOConnID;         /* Network connection ID target to orginator       */
    uint16_t  usConnSerialNum;    /* Connection serial number                        */
    uint16_t  usVendorId;         /* Orginator Vendor ID                             */
    uint32_t  ulOSerialNum;       /* Orginator serial number                         */
    uint8_t   bTimeoutMultiple;   /* Connection timeout multiple                     */
    uint8_t   abReserved1[3];     /* reserved                                        */
    uint32_t  ulOTRpi;            /* orginator to target requested packet rate in us */
    uint16_t  usOTConnParam;      /* orginator to target connection parameter        */
    uint32_t  ulTORpi;            /* target to orginator requested packet rate in us */
    uint16_t  usTOConnParam;      /* target to orginator connection parameter        */
    uint8_t   bTriggerType;       /* Transport type/trigger                          */
    uint8_t   bConnPathSize;      /* Connection path size                            */
    uint8_t   bConnPath[EIP_DEFAULT_PATH_LEN];        /* connection path             */
  }__PACKED_POST  EIP_CM_FWOPEN_REQ_T;


  /*#####################################################################################*/

  /* Forward Open Service - Successful Response  */
  typedef __PACKED_PRE struct EIP_CM_FWOPEN_RESP_Ttag
  {
    uint32_t  ulOTConnID;         /* Network connection ID orginator to target      */
    uint32_t  ulTOConnID;         /* Network connection ID target to orginator      */
    uint16_t  usConnSerialNum;    /* Connection serial number                       */
    uint16_t  usVendorId;         /* Orginator Vendor ID                            */
    uint32_t  ulOSerialNum;       /* Orginator serial number                        */
    uint32_t  ulOTApi;            /* orginator to target actual packet rate         */
    uint32_t  ulTOApi;            /* target to orginator actual packet rate         */
    uint8_t   bAppReplySize;      /* Number of 16Bit words in the application reply */
    uint8_t   bReserved1;
    uint16_t  ausAppReply[EIP_DEFAULT_ADDSTATUS_IDX];
  }__PACKED_POST  EIP_CM_FWOPEN_RESP_T;

  /*#####################################################################################*/

  /* Large Forward Open Service - Request Data */
  typedef __PACKED_PRE struct EIP_CM_LARGEFWOPEN_REQ_Ttag
  {
    uint8_t   bPriority;          /* used to calculate request timeout information   */
    uint8_t   bTimeOutTicks;      /* used to calculate request timeout information   */
    uint32_t  ulOTConnID;         /* Network connection ID orginator to target       */
    uint32_t  ulTOConnID;         /* Network connection ID target to orginator       */
    uint16_t  usConnSerialNum;    /* Connection serial number                        */
    uint16_t  usVendorId;         /* Orginator Vendor ID                             */
    uint32_t  ulOSerialNum;       /* Orginator serial number                         */
    uint8_t   bTimeoutMultiple;   /* Connection timeout multiple                     */
    uint8_t   abReserved1[3];     /* reserved                                        */
    uint32_t  ulOTRpi;            /* orginator to target requested packet rate in us */
    uint32_t  ulOTConnParam;      /* orginator to target connection parameter        */
    uint32_t  ulTORpi;            /* target to orginator requested packet rate in us */
    uint32_t  ulTOConnParam;      /* target to orginator connection parameter        */
    uint8_t   bTriggerType;       /* Transport type/trigger                          */
    uint8_t   bConnPathSize;      /* Connection path size                            */
    uint8_t   bConnPath[EIP_DEFAULT_PATH_LEN];        /* connection path             */
  }__PACKED_POST  EIP_CM_LARGEFWOPEN_REQ_T;

  /*#####################################################################################*/

  /* Forward Open/Close Service - Unsuccessful Response  */
  typedef __PACKED_PRE struct EIP_CM_FW_FAIL_RESP_Ttag
  {
    uint16_t  usConnSerialNum;    /* Connection serial number */
    uint16_t  usVendorId;         /* Orginator Vendor ID      */
    uint32_t  ulOSerialNum;       /* Orginator serial number  */
    uint8_t   bConnPathSize;      /* Connection path size     */
    uint8_t   bReserved1;         /* connection path           */
  }__PACKED_POST EIP_CM_FWOPEN_FAIL_RESP_T;

  /*#####################################################################################*/

  /* Forward Close Service - Request Data  */
  typedef __PACKED_PRE struct EIP_CM_FWCLOSE_REQ_Ttag
  {
    uint8_t   bPriority;          /* used to calculate request timeout information  */
    uint8_t   bTimeOutTicks;      /* used to calculate request timeout information  */
    uint16_t  usConnSerialNum;    /* Connection serial number                       */
    uint16_t  usVendorId;         /* Orginator Vendor ID                            */
    uint32_t  ulOSerialNum;       /* Orginator serial number                        */
    uint8_t   bConnPathSize;      /* Connection path size                           */
    uint8_t   bReserved1;
    uint8_t   bConnPath[EIP_DEFAULT_PATH_LEN];  /* connection path                  */
  }__PACKED_POST EIP_CM_FWCLOSE_REQ_T;

  /*#####################################################################################*/

  /* Forward Close Service - Successful Response  */
  typedef __PACKED_PRE struct EIP_CM_FWCLOSE_RESP_Ttag
  {
    uint16_t  usConnSerialNum;    /* Connection serial number */
    uint16_t  usVendorId;         /* Orginator Vendor ID      */
    uint32_t  ulOSerialNum;       /* Orginator serial number  */
    uint8_t   bAppReplySize;      /* Number of 16Bit words in the application reply */
    uint8_t   bReserved1;
    uint8_t   abAppReply[EIP_DEFAULT_ADDSTATUS_IDX];
  }__PACKED_POST  EIP_CM_FWCLOSE_RESP_T;

#pragma pack()

  /*#####################################################################################*/

  typedef struct EIP_CM_Ttag
  {
    EIP_CM_CLASS_ATTR_T tClass;
    EIP_CM_INST_ATTR_T  atInstance[1];
  }EIP_CM_T;


  /*
  ****************************************************************************
  *  Object specific macros
  ****************************************************************************
  */


  /*#####################################################################################*/

  /*
  ************************************************************
  *  Task Function Prototypes
  ************************************************************
  */

  typedef struct EIP_CM_INIT_PARAM_Ttag
  {

  }EIP_CM_INIT_PARAM_T;


  uint32_t
  EipCm_ObjectCreate( void*    pvObjRsc,
                      void*    pvEipRsc,
                      uint16_t usMaxConnections );


#endif /* EIP_CM_H */
