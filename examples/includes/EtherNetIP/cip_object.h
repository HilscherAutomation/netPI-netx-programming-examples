/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of Object directory description

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2013-11-12  RH            Created
**************************************************************************************/
#ifndef CIP_OBJECT_H
#define CIP_OBJECT_H

#include "eip_public.h"
#include "PS_Toolbox_Public.h"

  /*#####################################################################################*/

  typedef struct CIP_OBJ_ENTRY_Ttag         CIP_OBJ_ENTRY_T;
  typedef struct CIP_OBJ_REQUEST_Ttag       CIP_OBJ_REQUEST_T;
  typedef struct CIP_OBJ_ASYNC_REQUEST_Ttag CIP_OBJ_ASYNC_REQUEST_T;
  typedef struct CIP_OBJ_RESPONSE_Ttag      CIP_OBJ_RESPONSE_T;

  typedef void      (*CIP_OBJ_CREATE_FUNC)          ( void* pvUser,   CIP_OBJ_ENTRY_T*    ptObjEntry );
  typedef void      (*CIP_OBJ_DELETE_FUNC)          ( void* ptObjRsc );
  typedef void      (*CIP_OBJ_RESPONSE_CB)          ( void* pvParam,  CIP_OBJ_RESPONSE_T* ptResponse );
  typedef uint32_t  (*CIP_OBJ_CALL_FUNC)            ( void* ptObjRsc, CIP_OBJ_REQUEST_T*  ptRequest, CIP_OBJ_RESPONSE_T* ptResponse, CIP_OBJ_RESPONSE_CB fnCallback, void* pvParam);
  typedef uint8_t   (*CIP_OBJ_UPDATE_ATTR_FUNC)     ( void* ptObjRsc, CIP_OBJ_RESPONSE_T* ptResponse, CIP_OBJ_REQUEST_T* ptRequest);
  typedef void      (*CIP_OBJ_NOTIFICATION_CALLBACK)( void* pvParam,  CIP_OBJ_REQUEST_T*  ptRequest );
  typedef void      (*CIP_OBJ_SERVICE_CALLBACK)     ( void* pvParam,  CIP_OBJ_REQUEST_T*  ptRequest, CIP_OBJ_RESPONSE_CB fnCallback, void* pvCbParam);

  /*#####################################################################################*/

  /* Flags for compability reason */
  #define CIP_FLG_STORE_REMANENT      0x0001
  #define CIP_FLG_CHANGE_INTERNAL     0x0002

  /* Attribute update strategy */
  #define CIP_FLG_UPD_STRAT_MASK       0x000C
  #define CIP_FLG_UPD_STRAT_SETBYUSER  0x0000 /* value need to be set by User                 */
  #define CIP_FLG_UPD_STRAT_RESERVED   0x0004 /* reserved for future use                      */
  #define CIP_FLG_UPD_STRAT_AFTERRESET 0x0008 /* value is only allowed to change after reset  */
  #define CIP_FLG_UPD_STRAT_ONTHEFLY   0x000C /* value is changed on the fly                  */

  /* Flags for access control */
  #define CIP_FLG_SET_ACCESS_MASK     0x0030
  #define CIP_FLG_SET_ACCESS_BUS      0x0000
  #define CIP_FLG_SET_ACCESS_USER     0x0010
  #define CIP_FLG_SET_ACCESS_ADMIN    0x0020
  #define CIP_FLG_SET_ACCESS_NONE     0x0030

  #define CIP_FLG_GET_ACCESS_MASK     0x00C0
  #define CIP_FLG_GET_ACCESS_BUS      0x0000
  #define CIP_FLG_GET_ACCESS_USER     0x0040
  #define CIP_FLG_GET_ACCESS_ADMIN    0x0080
  #define CIP_FLG_GET_ACCESS_NONE     0x00C0

  #define CIP_FLG_FORWARD_ENABLE      0x2000 /* Service to attribute will be forwarded */
  #define CIP_FLG_NOTIFICATION_ENABLE 0x4000 /* Change of attribute data will be forwarded */
  #define CIP_FLG_ATTRIBUTE_DISABLE   0x8000

  #define CIP_OBJ_VALID_FLAG  0x8000
  #define CIP_OBJ_IDX_MASK    0x7FFF

  #define CIP_OBJ_ROUTE_INVALID      0x0000
  #define CIP_OBJ_ROUTE_DIRECT_RES   0x0001
  #define CIP_OBJ_ROUTE_CALLBACK_RES 0x0002


  /*#####################################################################################*/

  struct CIP_OBJ_REQUEST_Ttag
  {
    void*     pvHandle;           /* Fieldbus specific handle to identify incoming connection (transport) */
    uint16_t  usService;
    uint32_t  ulClass;
    uint32_t  ulInstance;
    uint32_t  ulAttribute;
    uint32_t  ulFlags;
    uint32_t  ulReqDataLen;
    uint8_t*  pbReqData;
  };

  struct CIP_OBJ_ASYNC_REQUEST_Ttag
  {
    CIP_OBJ_REQUEST_T           tRequest;
    PS_JOB_T                    tJob;
    void *                      pvJobParam;
    CIP_OBJ_RESPONSE_CB         fnCallback;
    void*                       pvCbParam;
  };

  /*#####################################################################################*/

  typedef struct CIP_ERROR_Ttag
  {
    uint8_t   bGrc;
    uint8_t   bAddErrorSize;
    uint16_t* pusAddError;
  } CIP_ERROR_T;


  /*#####################################################################################*/

  struct CIP_OBJ_RESPONSE_Ttag
  {
    uint16_t      usDataLen;
    uint8_t*      pbData;
    CIP_ERROR_T   tError;
  };

  /*#####################################################################################*/

  struct CIP_OBJ_ENTRY_Ttag
  {
    uint32_t ulClass;
    uint32_t ulObjHandle;
    void*    pvRsc;

    struct
    {
      CIP_OBJ_DELETE_FUNC  pfDelete;
      CIP_OBJ_CALL_FUNC    pfCall;
    } tFunc;
  };

  /*#####################################################################################*/
  typedef struct CIP_OBJECT_RSC_Ttag CIP_OBJECT_RSC_T;

  struct CIP_OBJECT_RSC_Ttag
  {
    uint32_t          ulMaxObjEntries;
    CIP_OBJ_ENTRY_T** aptObjEntries;

    uint32_t          ulMaxRegisteredServices;
    uint16_t*         pusRegisteredService;

    struct
    {
      CIP_OBJ_NOTIFICATION_CALLBACK pfCallback;
      void*                         pvParam;
    } tNotify;

    struct
    {
      CIP_OBJ_SERVICE_CALLBACK pfCallback;
      void*                    pvParam;
    } tService;

    OSAL_MUTEX_H        hLock;
    CIP_OBJ_RESPONSE_T  tResponse;
    PS_WORKER_H         hTask;
  };


  /*#####################################################################################*/

  typedef struct CIP_OBJECT_ATTRIBUTE_DIR_Ttag
  {
    uint8_t*                 pbData;
    CIP_OBJ_UPDATE_ATTR_FUNC pfUpdate;
    void*                    pvParam;
    uint16_t                 usSize;
    uint16_t                 usFlags;
  } CIP_OBJECT_ATTRIBUTE_DIR_T;

  /*#####################################################################################*/

  uint8_t
  CipObj_SetAttributeOption( CIP_OBJECT_RSC_T*   ptRsc,
                             uint16_t*           pusFlags,
                             CIP_OBJ_RESPONSE_T* ptResponse,
                             CIP_OBJ_REQUEST_T*  ptRequest );

  uint8_t
  CipObj_GetAttribute(  CIP_OBJECT_RSC_T*           ptRsc,
                        CIP_OBJECT_ATTRIBUTE_DIR_T* pAttributeDir,
                        uint32_t                    ulNumEntries,
                        uint32_t                    ulEntry,
                        CIP_OBJ_RESPONSE_T*         ptResponse,
                        CIP_OBJ_REQUEST_T*          ptRequest );

  uint8_t
  CipObj_SetAttribute(  CIP_OBJECT_RSC_T*           ptRsc,
                        CIP_OBJECT_ATTRIBUTE_DIR_T* pAttributeDir,
                        uint32_t                    ulNumEntries,
                        uint32_t                    ulEntry,
                        CIP_OBJ_RESPONSE_T*         ptResponse,
                        CIP_OBJ_REQUEST_T*          ptRequest );

  uint8_t
  CipObj_NotifyAttribute( CIP_OBJECT_RSC_T*           ptRsc,
                          CIP_OBJECT_ATTRIBUTE_DIR_T* pAttributeDir,
                          CIP_OBJ_REQUEST_T*          ptRequest );

  void
  CipObj_NotifyService( CIP_OBJECT_RSC_T*   ptRsc,
                        CIP_OBJ_REQUEST_T*  ptRequest,
                        CIP_OBJ_RESPONSE_CB fnCallback,
                        void*               pvParam );

  uint32_t
  CipObj_RegisterObject( CIP_OBJECT_RSC_T* ptRsc,
                         CIP_OBJ_ENTRY_T*  ptObjEntry );

  void
  CipObj_UnregisterObject( CIP_OBJECT_RSC_T* ptRsc,
                           uint32_t          ulObjIdx );

  uint32_t
  CipObj_RegisterService( CIP_OBJECT_RSC_T* ptRsc,
                          uint16_t          usService );

  void
  CipObj_UnregisterService( CIP_OBJECT_RSC_T* ptRsc,
                            uint16_t          usService );

  uint32_t
  CipObj_RegisterNotifyCallback( CIP_OBJECT_RSC_T*             ptRsc,
                                 CIP_OBJ_NOTIFICATION_CALLBACK pfCallback,
                                 void*                         pvParam );

  uint32_t
  CipObj_RegisterServiceCallback( CIP_OBJECT_RSC_T*        ptRsc,
                                  CIP_OBJ_SERVICE_CALLBACK pfCallback,
                                  void*                    pvParam );

  void
  CipObj_ResetObjects( CIP_OBJECT_RSC_T* ptRsc );

  void
  CipObj_StartObjects( CIP_OBJECT_RSC_T* ptRsc );

  void
  CipObj_StopObjects( CIP_OBJECT_RSC_T* ptRsc );

  void
  CipObj_Lock( CIP_OBJECT_RSC_T* ptRsc );

  void
  CipObj_Unlock( CIP_OBJECT_RSC_T* ptRsc );

  void
  CipObj_RequestSync( CIP_OBJECT_RSC_T*   ptRsc,
                      CIP_OBJ_REQUEST_T*  ptRequest,
                      CIP_OBJ_RESPONSE_T* ptResponse );

  void
  CipObj_RequestAsync( CIP_OBJECT_RSC_T*   ptRsc,
                       CIP_OBJ_ASYNC_REQUEST_T*  ptRequest,
                       CIP_OBJ_RESPONSE_CB fnCallback,
                       void*               pvParam );

  uint32_t
  CipObj_HandleUserService( CIP_OBJECT_RSC_T*   ptRsc,
                            CIP_OBJ_REQUEST_T*  ptRequest,
                            CIP_OBJ_RESPONSE_CB fnCallback,
                            void*               pvParam );

  CIP_OBJ_ENTRY_T*
  CipObj_GetObject( CIP_OBJECT_RSC_T* ptRsc,
                    uint32_t          ulClass );

#endif /* CIP_OBJECT_H */
