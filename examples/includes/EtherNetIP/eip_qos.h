/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of CIP QoS Object

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2014-05-22  RH            Created
**************************************************************************************/
#ifndef _EIP_QOS_H_
#define _EIP_QOS_H_

#include <stdint.h>

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific defines
  ************************************************************
  */

  #define EIP_QOS_CLASS_NUMBER       0x48
  #define EIP_QOS_REVISION           0x01
  #define EIP_QOS_MAX_INSTANCE       0x01
  #define EIP_QOS_MAX_CLASS_ATTR     7
  #define EIP_QOS_MAX_INSTANCE_ATTR  8


  /* attributes of identity object */
  #define EIP_QOS_ATTR_1_TAG_ENABLE       1
  #define EIP_QOS_ATTR_2_DSCP_PTP_EVENT   2
  #define EIP_QOS_ATTR_3_DSCP_PTP_GENERAL 3
  #define EIP_QOS_ATTR_4_DSCP_URGENT      4
  #define EIP_QOS_ATTR_5_DSCP_SCHEDULED   5
  #define EIP_QOS_ATTR_6_DSCP_HIGH        6
  #define EIP_QOS_ATTR_7_DSCP_LOW         7
  #define EIP_QOS_ATTR_8_DSCP_EXPLICIT    8

  /*#####################################################################################*/

  #define EIP_QOS_TAG_ENABLED               1
  #define EIP_QOS_TAG_DISABLED              0
  #define EIP_QOS_DSCP_PTP_EVENT_DEFAULT   59
  #define EIP_QOS_DSCP_PTP_GENERAL_DEFAULT 47
  #define EIP_QOS_DSCP_URGENT_DEFAULT      55
  #define EIP_QOS_DSCP_SCHEDULED_DEFAULT   47
  #define EIP_QOS_DSCP_HIGH_DEFAULT        43
  #define EIP_QOS_DSCP_LOW_DEFAULT         31
  #define EIP_QOS_DSCP_EXPLICIT_DEFAULT    27


  /*
  ************************************************************
  *  Object specific types
  ************************************************************
  */

  typedef struct EIP_QOS_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;
    uint16_t  usMaxInstance;
    uint16_t  usMaxClassAttr;
    uint16_t  usMaxInstanceAttr;
    uint16_t  usNumInstance;
  } EIP_QOS_CLASS_ATTR_T;

  /*#####################################################################################*/

#pragma pack(1)


  typedef struct EIP_QOS_INST_ATTR_Ttag
  {
    uint8_t b802_1TagEnable;
    uint8_t bDSCP_PTP_Event;
    uint8_t bDSCP_PTP_General;
    uint8_t bDSCP_Urgent;
    uint8_t bDSCP_Scheduled;
    uint8_t bDSCP_High;
    uint8_t bDSCP_Low;
    uint8_t bDSCP_Explicit;
  }  EIP_QOS_INST_ATTR_T;


#pragma pack()

  /*#####################################################################################*/

  typedef struct EIP_QOS_Ttag
  {
    EIP_QOS_CLASS_ATTR_T tClass;
    EIP_QOS_INST_ATTR_T  atInstance[1];

  }EIP_QOS_T;

  /*#####################################################################################*/


  typedef struct EIP_QOS_RSC_Ttag* EIP_QOS_H;

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
  typedef struct EIP_QOS_INIT_PARAM_Ttag
  {
    void* hDrvEth;
    void* hTimer;
    void* hTask;
  } EIP_QOS_INIT_PARAM_T;

    /** Creates the Quality of Service object (QoS).
   *
   * \param pvRsc   [in] Task Resources
   *        ptParam [in] settings for QoS object
   *
   * \return Description of return value, if any
   */
  uint32_t
  EipQoS_ObjectCreate( void* pvRsc, EIP_QOS_INIT_PARAM_T *ptParam );

  /*#####################################################################################*/

#endif /* _EIP_QOS_H_ */
