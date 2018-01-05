/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of EtherNet/IP Message Router Object

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2013-11-12  RH            Created
**************************************************************************************/
#ifndef CIP_MR_H
#define CIP_MR_H

#include <stdint.h>


  /*#####################################################################################*/

  #define CIP_MR_MAX_SERVICES         10    /* number of parallel CIP services        */


  /************************************************************
  *  Object specific defines
  ************************************************************
  */
  #define CIP_MR_CLASS_NUMBER            0x02
  #define CIP_MR_REVISION                1
  #define CIP_MR_MAX_INSTANCE            1
  #define CIP_MR_MAX_CLASS_ATTR          7
  #define CIP_MR_MAX_INSTANCE_ATTR       0

  #define CIP_CMD_SYMBOLIC_TRANSLATION   ( 0x4B )


  /*#####################################################################################*/

  typedef void(*CIP_MR_SENDRESP_FUNC)(void * pvParam, CIP_OBJ_RESPONSE_T *tCIPResponse);

  typedef struct CIP_MR_SERVICE_Ttag
  {
    CIP_OBJ_ASYNC_REQUEST_T tCIPRequest;
    CIP_OBJ_RESPONSE_T tCIPResponse;
    uint16_t ausAddErrCode[2];
    CIP_MR_SENDRESP_FUNC pfCallback;
    void* pvParam;
  }CIP_MR_SERVICE_T;


  /*#####################################################################################*/

  #pragma pack(1)

  typedef __PACKED_PRE struct __PACKED_POST CIP_MR_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;
    uint16_t  usMaxInstance;
    uint16_t  usNumInstance;
    uint16_t  usMaxClassAttr;
    uint16_t  usMaxInstanceAttr;
  } CIP_MR_CLASS_ATTR_T;

  /*#####################################################################################*/

  typedef __PACKED_PRE struct __PACKED_POST CIP_MR_INST_ATTR_Ttag
  {
    uint32_t   ulDummy;
  } CIP_MR_INST_ATTR_T;

  #pragma pack()

  /*#####################################################################################*/

  typedef struct CIP_MR_Ttag
  {
    CIP_MR_CLASS_ATTR_T tClass;
    CIP_MR_INST_ATTR_T  atInstance[1];
  }CIP_MR_T;

  /*#####################################################################################*/


  typedef struct CIP_MR_RSC_Ttag
  {
    CIP_MR_T tObjData;
    CIP_OBJ_ENTRY_T tObjEntry;
    CIP_OBJECT_ATTRIBUTE_DIR_T atClassAttrDir[CIP_MR_MAX_CLASS_ATTR];
    CIP_OBJECT_ATTRIBUTE_DIR_T atInstanceAttrDir[1][CIP_MR_MAX_INSTANCE_ATTR];

    CIP_MR_SERVICE_T atActiveServices[CIP_MR_MAX_SERVICES];
    void *ptObjRsc;
  } CIP_MR_RSC_T;


  /*#####################################################################################*/


  uint32_t
  CipMRHandleRequest( CIP_MR_RSC_T*        ptRsc,
                      uint16_t             usLength,
                      uint8_t*             pbData,
                      CIP_MR_SENDRESP_FUNC pfCallback,
                      void*                pvParam );

  uint32_t
  CipMR_ObjectCreate( void*         pvRsc,
                      CIP_MR_RSC_T* ptObjRsc );

#endif /* CIP_MR_H */
