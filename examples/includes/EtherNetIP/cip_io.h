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
#ifndef CIP_IO_H
#define CIP_IO_H

#include <stdint.h>


  /*#####################################################################################*/

  /*
    ************************************************************
    *  Object specific defines
    ************************************************************
    */


  #define CIP_IO_CLASS_NUMBER             0x402
  #define CIP_IO_REVISION                 0x01
  #define CIP_IO_MAX_INSTANCE             0x01
  #define CIP_IO_MAX_CLASS_ATTR           7
  #define CIP_IO_MAX_INSTANCE_ATTR        10

  /* attributes of predefined connection object */
  #define CIP_IO_ATTR_1_STATUS            1
  #define CIP_IO_ATTR_2_LEN               2
  #define CIP_IO_ATTR_3_DATA              3

  #define CIPHIL_IO_CMD_CREATE_MEMBER     0xFF01
  #define CIPHIL_IO_CMD_DELETE_MEMBER     0xFF02

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific types
  ************************************************************
  */
#pragma pack(1)
  typedef __PACKED_PRE struct CIP_IO_CREATE_MEMBER_REQ_Ttag
  {
    uint16_t  usDataLen;
    uint8_t   *pbData;

    uint8_t   bDirection;
    #define CIP_IO_DIRECTION_PRODUCER  0x01
    #define CIP_IO_DIRECTION_CONSUMER  0x02

  }__PACKED_POST  CIP_IO_CREATE_MEMBER_REQ_T;

#pragma pack(0)

  /*#####################################################################################*/

  typedef struct CIP_IO_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;
    uint16_t  usMaxInstance;
    uint16_t  usMaxClassAttr;
    uint16_t  usMaxInstanceAttr;
    uint16_t  usNumInstance;
  } CIP_IO_CLASS_ATTR_T;

  /*#####################################################################################*/

#pragma pack(1)

  typedef __PACKED_PRE struct CIP_IO_INST_ATTR_Ttag
  {
    uint16_t  usStatus;
    #define CIP_IO_STATUS_PRODUCER  0x01
    #define CIP_IO_STATUS_CONSUMER  0x02
    #define CIP_IO_STATUS_CONNECTED 0x10

    uint16_t  usDataLen;
    uint8_t*  pbData;
  }__PACKED_POST  CIP_IO_INST_ATTR_T;
#pragma pack()

  /*#####################################################################################*/

  typedef struct CIP_IO_Ttag
  {
    CIP_IO_CLASS_ATTR_T tClass;
    CIP_IO_INST_ATTR_T* patInstance;
  }CIP_IO_T;

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

  typedef struct CIP_IO_INIT_PARAM_Ttag
    {
      uint16_t usMaxInstance;
    }CIP_IO_INIT_PARAM_T;

  uint32_t
  CipIO_ObjectCreate( void*                pvRsc,
                      CIP_IO_INIT_PARAM_T* ptParam );

#endif /* CIP_IO_H */
