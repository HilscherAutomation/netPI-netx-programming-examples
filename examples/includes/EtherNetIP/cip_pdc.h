/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of CIP Hischer Object Predefined Connections

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2013-11-12  RH            Created
**************************************************************************************/
#ifndef CIP_PDC_H
#define CIP_PDC_H

#include <stdint.h>


  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific defines
  ************************************************************
  */

  #define CIP_PDC_CLASS_NUMBER       0x401
  #define CIP_PDC_REVISION           0x01
  #define CIP_PDC_MAX_INSTANCE       0x03
  #define CIP_PDC_MAX_CLASS_ATTR     7
  #define CIP_PDC_MAX_INSTANCE_ATTR  10

  /* attributes of predefined connection object */
  #define CIP_PDC_ATTR_1_STATE      1
  #define CIP_PDC_ATTR_2_COUNT      2
  #define CIP_PDC_ATTR_3_CONFIG     3

  #define CIP_PDC_DUMMY_INSTANCE    0xFFFFFFFF

  #define CIPHIL_PDC_CMD_OPEN_CONNECTION   0xFF01
  #define CIPHIL_PDC_CMD_CLOSE_CONNECTION  0xFF02

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific types
  ************************************************************
  */

  typedef struct CIP_PDC_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;
    uint16_t  usMaxInstance;
    uint16_t  usMaxClassAttr;
    uint16_t  usMaxInstanceAttr;
    uint16_t  usNumInstance;
  } CIP_PDC_CLASS_ATTR_T;

  /*#####################################################################################*/

//#pragma pack(1) //AL

  typedef __PACKED_PRE struct CIP_PDC_CONNECTION_CFG_Ttag
  {
    uint32_t ulConsumerPoint;
    uint32_t ulProducerPoint;
    uint32_t ulConfigPoint;
    uint32_t ulMinOTRpi;
    uint32_t ulMaxOTRpi;
    uint32_t ulMinTORpi;
    uint32_t ulMaxTORpi;

    uint8_t  bSuppTrigTypes;
    #define CIP_PDC_TTYPE_CYCLIC         0x01
    #define CIP_PDC_TTYPE_COS            0x02
    #define CIP_PDC_TTYPE_APPLICATION    0x04

    uint8_t  bConnType;
  } __PACKED_POST CIP_PDC_CONNECTION_CFG_T;

  /*#####################################################################################*/

  typedef __PACKED_PRE struct CIP_PDC_INST_ATTR_Ttag
  {
    uint8_t                  bState;           /* State of the connection */
    #define CIP_PDC_STATE_FREE          0
    #define CIP_PDC_STATE_UNCONNECTED   1
    #define CIP_PDC_STATE_CONNECTED     2
    #define CIP_PDC_STATE_TIMEOUT       3

    uint8_t                  bConnectionCnt;   /* How many connection of these type exist
                                                 (listen only/input only)*/

    CIP_PDC_CONNECTION_CFG_T tConfig;

  }__PACKED_POST  CIP_PDC_INST_ATTR_T;

///#pragma pack() //AL

  /*#####################################################################################*/

  typedef struct CIP_PDC_Ttag
  {
    CIP_PDC_CLASS_ATTR_T tClass;
    CIP_PDC_INST_ATTR_T* patInstance;
  }CIP_PDC_T;



  /*#####################################################################################*/

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

  typedef struct CIP_PDC_INIT_PARAM_Ttag
    {
      uint16_t usMaxInstance;
    }CIP_PDC_INIT_PARAM_T;

  uint32_t
  CipPDC_ObjectCreate( void*                 pvRsc,
                       CIP_PDC_INIT_PARAM_T* ptParam );


#endif /* CIP_PDC_H */
