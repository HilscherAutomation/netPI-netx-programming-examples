/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of EtherNet/IP Assembly Object

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2014-01-16  RH            Created
**************************************************************************************/
#ifndef CIP_AS_H
#define CIP_AS_H

#include <stdint.h>

  /*#####################################################################################*/

  /*
    ************************************************************
    *  Object specific defines
    ************************************************************
    */

  #define CIP_AS_CLASS_NUMBER       0x04
  #define CIP_AS_REVISION           0x02
  #define CIP_AS_MAX_INSTANCE       0xFFFFF
  #define CIP_AS_MAX_CLASS_ATTR     7
  #define CIP_AS_MAX_INSTANCE_ATTR  7


  /* attributes of identity object */
  #define CIP_AS_ATTR_1_NUM_MEMBER                  1
  #define CIP_AS_ATTR_2_MEMBER_LIST                 2
  #define CIP_AS_ATTR_3_DATA                        3
  #define CIP_AS_ATTR_4_SIZE                        4

  #define CIP_AS_ATTR_300_MEMBER_DATA_LIST          300
  #define CIP_AS_ATTR_301_PARAMETER                 301
  #define CIP_AS_ATTR_302_STATUS                    302

  #define CIP_AS_MAX_MEMBER_PATH_SIZE               9 /* 3 segments a 9 bytes (support of 16bit segments) */

  #define CIPHIL_CMD_AS_CREATE     0x0401
  #define CIPHIL_CMD_AS_DELETE     0x0402
  #define CIPHIL_CMD_AS_ADD_MEMBER 0x0403
  #define CIPHIL_CMD_AS_DEL_MEMBER 0x0404
  #define CIPHIL_CMD_AS_UPDATE_CONSUMING 0x0405   /* update consuming data to host application  */
  #define CIPHIL_CMD_AS_UPDATE_PRODUCING 0x0406   /* update producing data to host application  */
  #define CIPHIL_CMD_AS_GET_CONSUMING    0x0407   /* get consuming data from bus                */
  #define CIPHIL_CMD_AS_BIND             0x0408   /* bind assembly to a connection              */
  #define CIPHIL_CMD_AS_UNBIND           0x0409   /* unbind assembly to a connection            */
  #define CIPHIL_CMD_AS_CHANGE_RUNIDLE   0x040A   /* Change state of assembly to RUN or IDLE    */

  #define CIP_AS_PARAM_FIX_SIZE           0x0001
  #define CIP_AS_PARAM_TYPE_MSK           0xF000
  #define CIP_AS_PARAM_TYPE_CONSUMER      0x0000
  #define CIP_AS_PARAM_TYPE_PRODUCER      0x1000
  #define CIP_AS_PARAM_TYPE_HB_LISTENONLY 0x2000
  #define CIP_AS_PARAM_TYPE_HB_INPUTONLY  0x3000
  #define CIP_AS_PARAM_TYPE_CONFIG        0x4000
  #define CIP_AS_PARAM_RT_FORMAT_MSK      0x0F00
  #define CIP_AS_PARAM_RT_FORMAT_PURE     0x0000
  #define CIP_AS_PARAM_RT_FORMAT_NULL     0x0100
  #define CIP_AS_PARAM_RT_FORMAT_HB       0x0300
  #define CIP_AS_PARAM_RT_FORMAT_RUNIDLE  0x0400
  #define CIP_AS_PARAM_RT_FORMAT_SAFETY   0x0500

  /*#####################################################################################*/

  /*
    ************************************************************
    *  Object specific types
    ************************************************************
    */

#pragma pack(1)


  typedef __PACKED_PRE struct CIPHIL_AS_RUNIDLE_REQ_Ttag
  {
    #define CIP_AS_IDLE 0x00
    #define CIP_AS_RUN  0x01

    uint8_t bRunIdle;

  }__PACKED_POST CIPHIL_AS_RUNIDLE_REQ_T;


  /*#####################################################################################*/

  typedef void (* CIP_AS_EVENT_UPDATE_CB)( void*    pvHandle,
                                           uint8_t* pbData,
                                           uint16_t usDataLen );

  typedef __PACKED_PRE struct CIPHIL_AS_BIND_REQ_Ttag
  {
    void*                   pvHandle; /* Handle to the connection */
    CIP_AS_EVENT_UPDATE_CB  fnUpdate; /* Update function for process data . Used only for producing assemblies. */
    uint16_t                usParam;  /* CIP_AS_PARAM_TYPE_... */
    uint16_t                usSize;   /* Connection size for the assembly as requested from the network (including sequence count and run/idle size). */
  }__PACKED_POST CIPHIL_AS_BIND_REQ_T;

  /*#####################################################################################*/

  typedef __PACKED_PRE struct CIPHIL_AS_CREATE_REQ_Ttag
  {
    uint32_t ulInstanceId;
    uint16_t usMinSize;
    uint16_t usMaxSize;
    uint16_t usParam;
  }__PACKED_POST CIPHIL_AS_CREATE_REQ_T;

  /*#####################################################################################*/

  typedef __PACKED_PRE struct CIPHIL_AS_ADD_MEMBER_REQ_Ttag
  {
    uint16_t usDataSize;
    uint16_t usPathSize;
    uint8_t  abPath[CIP_AS_MAX_MEMBER_PATH_SIZE];
  }__PACKED_POST CIPHIL_AS_ADD_MEMBER_REQ_T;

  /*#####################################################################################*/

  typedef __PACKED_PRE struct CIPHIL_AS_DEL_MEMBER_REQ_Ttag
  {
    uint16_t usPathSize;
    uint8_t  abPath[CIP_AS_MAX_MEMBER_PATH_SIZE];
  }__PACKED_POST CIPHIL_AS_DEL_MEMBER_REQ_T;

#pragma pack(0)

  /*#####################################################################################*/

  typedef struct CIP_AS_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;         /* 1 */
    uint16_t  usMaxInstance;      /* 2 */
    uint16_t  usNumInstance;      /* 3 */
    uint16_t  usMaxClassAttr;     /* 6 */
    uint16_t  usMaxInstanceAttr;  /* 7 */
  } CIP_AS_CLASS_ATTR_T;

  /*#####################################################################################*/


#pragma pack(1)
  typedef __PACKED_PRE struct CIP_AS_MEMBER_LIST_ENTRY_Ttag
  {
    uint16_t usDataSize;
    uint16_t usPathSize;
    uint8_t  abPath[CIP_AS_MAX_MEMBER_PATH_SIZE];
  }__PACKED_POST CIP_AS_MEMBER_LIST_ENTRY_T;
#pragma pack(0)

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

  typedef struct CIP_AS_INIT_PARAM_Ttag
  {
    uint16_t usMaxInstance;     /* maximal number of assemblies */
    uint16_t usMaxMembers;      /* maximal number of members (sum of all members) */
    uint16_t usMaxConnections;  /* maximal number of IO connections */
  }CIP_AS_INIT_PARAM_T;


  uint32_t
  CipAs_ObjectCreate( void*                pvRsc,
                      CIP_AS_INIT_PARAM_T* ptParam );

#endif /* CIP_AS_H */
