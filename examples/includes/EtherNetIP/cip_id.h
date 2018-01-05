/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of CIP Identity Object

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2013-11-12  RH            Created
**************************************************************************************/
#ifndef CIP_ID_H
#define CIP_ID_H

#include <stdint.h>


  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific defines
  ************************************************************
  */

  #define CIP_ID_SERIAL_NUMBER      0x12345678L
  #define CIP_ID_CLASS_NUMBER       0x01
  #define CIP_ID_REVISION           0x01
  #define CIP_ID_MAX_INSTANCE       0x01
  #define CIP_ID_MAX_CLASS_ATTR     7
  #define CIP_ID_MAX_INSTANCE_ATTR  10

  #define CIP_ID_MAX_PRODUKTNAME_LEN  32

  /*
  ** State defines
  */

  #define CIP_ID_STATE_NONEXISTENT        0
  #define CIP_ID_STATE_DEVICESELFTEST     1
  #define CIP_ID_STATE_STANDBY            2
  #define CIP_ID_STATE_OPERATIONAL        3
  #define CIP_ID_STATE_MAJRECOVERFLT      4
  #define CIP_ID_STATE_MAJUNRECOVERFLT    5
  #define CIP_ID_STATE_DEFAULT          255

  /*
  ** Defines of the status bits
  */

  #define CIP_ID_STATUS_OWNED_MASK                 0x0001
  #define CIP_ID_STATUS_OWNED                      0x0001
  #define CIP_ID_STATUS_UNOWNED                    0x0000

  #define CIP_ID_STATUS_CONFIGURED_MASK            0x0004
  #define CIP_ID_STATUS_UNCONFIGURED               0x0000
  #define CIP_ID_STATUS_CONFIGURED                 0x0004

  /* Device state bits.*/
  #define CIP_ID_STATUS_STATE_MASK                 0x00F0
  #define CIP_ID_STATUS_SELF_TESTING               0x0000
  #define CIP_ID_STATUS_NVS_UPDATE                 0x0010
  #define CIP_ID_STATUS_COMM_FAULT                 0x0020
  #define CIP_ID_STATUS_AWAIT_CONN                 0x0030
  #define CIP_ID_STATUS_NVS_BAD_CONFIG             0x0040
  #define CIP_ID_STATUS_MAJOR_FAULT                0x0050
  #define CIP_ID_STATUS_CONNECTED                  0x0060
  #define CIP_ID_STATUS_IDLE                       0x0070
  #define CIP_ID_STATUS_IP_ADDRESS                 0x0080
  #define CIP_ID_STATUS_IP_ADDRESS_CONFLICT        0x0090

  /* Fault bits.*/
  #define CIP_ID_STATUS_FAULT_MASK                 0x0F00
  #define CIP_ID_STATUS_MINOR_RECOVERABLE_FAULT    0x0100
  #define CIP_ID_STATUS_MINOR_UNRECOVERABLE_FAULT  0x0200
  #define CIP_ID_STATUS_MAJOR_RECOVERABLE_FAULT    0x0400
  #define CIP_ID_STATUS_MAJOR_UNRECOVERABLE_FAULT  0x0800

  /* attributes of identity object */
  #define CIP_ID_ATTR_1_VENDOR_ID                   1
  #define CIP_ID_ATTR_2_DEVICE_TYPE                 2
  #define CIP_ID_ATTR_3_PRODUCT_CODE                3
  #define CIP_ID_ATTR_4_REVISION                    4
  #define CIP_ID_ATTR_5_STATUS                      5
  #define CIP_ID_ATTR_6_SERIAL_NUMBER               6
  #define CIP_ID_ATTR_7_PRODUCT_NAME                7
  #define CIP_ID_ATTR_8_STATE                       8
  #define CIP_ID_ATTR_9_CFG_CONSIST_VALUE           9
  #define CIP_ID_ATTR_10_HEARTBEAT_INTERVAL         10

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific types
  ************************************************************
  */

  typedef struct CIP_ID_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;
    uint16_t  usMaxInstance;
    uint16_t  usMaxClassAttr;
    uint16_t  usMaxInstanceAttr;
    uint16_t  usNumInstance;
  } CIP_ID_CLASS_ATTR_T;

  /*#####################################################################################*/

#pragma pack(1)

  typedef __PACKED_PRE struct CIP_ID_INST_ATTR_Ttag
  {
    uint16_t  usVendor;
    uint16_t  usProductType;
    uint16_t  usProductCode;
    struct
    {
      uint8_t   bMajorRevision;
      uint8_t   bMinorRevision;
    } tRevision;
    uint16_t  usStatus;
    uint32_t  ulSerialNumber;
    uint8_t   abProductName[CIP_ID_MAX_PRODUKTNAME_LEN];
    uint8_t   abReserved[4];                  /* reserved for get attribute all */
    uint8_t   bState;
    uint16_t  usConfigConsistent;
    uint8_t   bHeartBeatInterval;
  }__PACKED_POST  CIP_ID_INST_ATTR_T;

#pragma pack()

  /*#####################################################################################*/

  typedef struct CIP_IDENTITY_Ttag
  {
    CIP_ID_CLASS_ATTR_T tClass;
    CIP_ID_INST_ATTR_T  atInstance[1];

  }CIP_IDENTITY_T;

  /*#####################################################################################*/

  /*
  ****************************************************************************
  *  Object specific macros
  ****************************************************************************
  */
  #define CIPID_STATUS_MODIFY_OWNED(        pvObjDir, value )  CipId_ModifyStatus( pvObjDir, 0x0001, value );
  #define CIPID_STATUS_MODIFY_CONFIGURED(   pvObjDir, value )  CipId_ModifyStatus( pvObjDir, 0x0004, value );
  #define CIPID_STATUS_MODIFY_EXTDEVSTATUS( pvObjDir, value )  CipId_ModifyStatus( pvObjDir, 0x00F0, value );
  #define CIPID_STATUS_MODIFY_MINORRECOV(   pvObjDir, value )  CipId_ModifyStatus( pvObjDir, 0x0100, value );
  #define CIPID_STATUS_MODIFY_MINORUNRECOV( pvObjDir, value )  CipId_ModifyStatus( pvObjDir, 0x0200, value );
  #define CIPID_STATUS_MODIFY_MAJORRECOV(   pvObjDir, value )  CipId_ModifyStatus( pvObjDir, 0x0400, value );
  #define CIPID_STATUS_MODIFY_MAJORUNRECOV( pvObjDir, value )  CipId_ModifyStatus( pvObjDir, 0x0800, value );
  #define CIPID_STATUS_MODIFY_EXTDEVSTAT2(  pvObjDir, value )  CipId_ModifyStatus( pvObjDir, 0xF000, value );

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Task Function Prototypes
  ************************************************************
  */

  /** Short function description.
   *
   * \param pvRsc [in] Description
   *
   * \return Description of return value, if any
   */
  uint32_t
  CipId_ObjectCreate( void* pvRsc );


  /*#####################################################################################*/

  /** Short function description.
   *
   * \param pvObjDir [in] Description
   * \param usMask   [in] Description
   * \param usValue  [in] Description
   *
   * \return Description of return value, if any
   */
  void
  CipId_ModifyStatus( void*    pvObjDir,
                      uint16_t usMask,
                      uint16_t usValue );


  /*#####################################################################################*/

  /** Short function description.
   *
   * \param pvObjDir [in] Description
   * \param bState   [in] Description
   *
   * \return Description of return value, if any
   */
  void
  CipId_SetState( void*   pvObjDir,
                  uint8_t bState );

  /*#####################################################################################*/

#endif /* CIP_ID_H */
