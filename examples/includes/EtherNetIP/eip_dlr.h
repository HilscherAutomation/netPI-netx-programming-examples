/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of CIP DLR Object

   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2014-05-22  RH            Created
**************************************************************************************/
#ifndef _EIP_DLR_H_
#define _EIP_DLR_H_

#include <stdint.h>
#include "PS_Toolbox_Public.h"
#include "Drv_Eth_public.h"
#include "Drv_Eth_Adapter_2ps_Public.h"

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific defines
  ************************************************************
  */

  #define EIP_DLR_CLASS_NUMBER       0x47
  #define EIP_DLR_REVISION           0x03
  #define EIP_DLR_MAX_INSTANCE       0x01
  #define EIP_DLR_MAX_CLASS_ATTR     7
  #define EIP_DLR_MAX_INSTANCE_ATTR  12


  /* attributes of identity object */
  #define EIP_DLR_ATTR_1_NETWORK_TOPOLOGY                1
  #define EIP_DLR_ATTR_2_NETWORK_STATUS                  2
  #define EIP_DLR_ATTR_3_RING_SUPERVISOR_STATUS          3
  #define EIP_DLR_ATTR_4_RING_SUPERVISOR_CONFIG          4
  #define EIP_DLR_ATTR_5_RING_FAULTS_COUNT               5
  #define EIP_DLR_ATTR_6_LAST_ACTIVE_NODE_PORT1          6
  #define EIP_DLR_ATTR_7_LAST_ACTIVE_NODE_PORT2          7
  #define EIP_DLR_ATTR_8_PARTICIPANTS_COUNT              8
  #define EIP_DLR_ATTR_9_PARTICIPANTS_LIST               9
  #define EIP_DLR_ATTR_10_ACTIVE_SUPERVISOR_ADDRESS     10
  #define EIP_DLR_ATTR_11_ACTIVE_SUPERVISOR_PRECEDENCE  11
  #define EIP_DLR_ATTR_12_CAPABILITY_FLAGS              12
  #define EIP_DLR_ATTR_13_REDUNDANT_GATEWAY_CONFIG      13
  #define EIP_DLR_ATTR_14_REDUNDANT_GATEWAY_STATUS      14
  #define EIP_DLR_ATTR_15_ACTIVE_GATEWAY_ADDRESS        15
  #define EIP_DLR_ATTR_16_ACTIVE_GATEWAY_PRECEDENCE     16

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Object specific types
  ************************************************************
  */

  typedef struct EIP_DLR_CLASS_ATTR_Ttag
  {
    uint16_t  usRevision;
    uint16_t  usMaxInstance;
    uint16_t  usMaxClassAttr;
    uint16_t  usMaxInstanceAttr;
    uint16_t  usNumInstance;
  } EIP_DLR_CLASS_ATTR_T;

  /*#####################################################################################*/

#pragma pack(1)

#define EIP_DLR_TOPOLOGY_LINEAR       0
#define EIP_DLR_TOPOLOGY_RING         1

#define EIP_DLR_NETWORKSTATUS_NORMAL                  0
#define EIP_DLR_NETWORKSTATUS_RINGFAULT               1
#define EIP_DLR_NETWORKSTATUS_UNEXPECTEDLOOP          2
#define EIP_DLR_NETWORKSTATUS_PARTIALNETWORKFAULT     3
#define EIP_DLR_NETWORKSTATUS_RAPIDFAULT_RESTORECYCLE 4

#define EIP_DLR_RINGSUPERVISOR_BACKUP             0
#define EIP_DLR_RINGSUPERVISOR_ACTIVE             1
#define EIP_DLR_RINGSUPERVISOR_NORMALNODE         2
#define EIP_DLR_RINGSUPERVISOR_NONDLR             3
#define EIP_DLR_RINGSUPERVISOR_NOSUPPORT          4

/* capability flags */
#define EIP_DLR_CAPABILITY_ANNOUNCE_BASED       0x01
#define EIP_DLR_CAPABILITY_BEACON_BASED         0x02
#define EIP_DLR_CAPABILITY_SUPERVISOR_POSSIBLE  0x20
#define EIP_DLR_CAPABILITY_REDUNDANT_GATEWAY    0x40
#define EIP_DLR_CAPABILITY_FLUSH_TABLE          0x80

#define EIP_DLR_NEIGHBOR_STATUS_PORT1_UP        0x01
#define EIP_DLR_NEIGHBOR_STATUS_PORT2_UP        0x02
#define EIP_DLR_NEIGHBOR_STATUS_FLAGS           0x80


typedef void ( * EIP_DLR_STATE_CHANGE_CALLBACK )( uint8_t  bNetworkTopology,
                                                  uint8_t  bNetworkStatus,
                                                  void*    pvUserData);

  typedef struct EIP_DLR_NODE_Ttag
  {
    uint32_t ulIPAddress;
    uint8_t  abMAC[6];
  } EIP_DLR_NODE_T;

  typedef struct EIP_DLR_INST_ATTR_Ttag
  {
    uint8_t bNetworkTopology;
    uint8_t bNetworkStatus;
#if 0
    uint8_t bRingSupervisorStatus;
    struct {
      bool fRingSupervisorEnable;
      uint8_t bRingSupervisiorPrecedence;
      uint32_t ulBeaconInterval;
      uint32_t ulBeaconTimeout;
      uint16_t usDLR_VLAN_ID;
    } tRingSupervisorConfig;
    uint16_t usRingFaultsCount;
    EIP_DLR_NODE_T atLastActiveNodePort[2];
    uint16_t usParticipantsCount;
    EIP_DLR_NODE_T *ptParticipantList;
#else
    uint8_t abReserved1[37];
#endif
    EIP_DLR_NODE_T tActiveSupervisorAddress;
#if 0
    uint8_t bActiveSupervisorPrecedence;
#else
    uint8_t abReserved2[1];
#endif
    uint32_t ulCapabilityFlags;
  }  EIP_DLR_INST_ATTR_T;


#pragma pack()

  /*#####################################################################################*/

  typedef struct EIP_DLR_Ttag
  {
    EIP_DLR_CLASS_ATTR_T tClass;
    EIP_DLR_INST_ATTR_T  atInstance[1];

  }EIP_DLR_T;


  /*
  ****************************************************************************
  *  Object specific macros
  ****************************************************************************
  */

  typedef struct EIP_DLR_RSC_Ttag* EIP_DLR_H;

  /*#####################################################################################*/

  /*
  ************************************************************
  *  Task Function Prototypes
  ************************************************************
  */
  typedef struct EIP_DLR_INIT_PARAM_Ttag
  {
    void* hDrvEth;
    void* hTimer;
    void* hTask;
  } EIP_DLR_INIT_PARAM_T;

    /** Creates the device ring layer object (DLR).
   *
   * \param pvRsc   [in] Task Resources
   *        ptParam [in] settings for DLR object
   *
   * \return Description of return value, if any
   */
  uint32_t
  EipDlr_ObjectCreate( void* pvRsc, EIP_DLR_INIT_PARAM_T *ptParam );


  /** Get a handle to the DLR component.
  *
  * \param  pvObjDir   [in] Pointer to CIP object dictionary
  *
  * \return Handle to DLR component
  */
  EIP_DLR_H EipDLR_GetHandle( void* pvObjDir );


  /** Register Callback function to signal state change of DLR.
 *
 * \param hDLR        [in] Handle of DLR object
 *        pfnCallback [in] callback for DLR state change
 *        pvUserData  [in] User data returned with callback
 *
 * \return Description of return value, if any
 */
  uint32_t
  EipDLR_RegisterCallback_StateChange( EIP_DLR_H                       hDLR,
                                       EIP_DLR_STATE_CHANGE_CALLBACK   pfnCallback,
                                       void*                           pvUserData);

  /*#####################################################################################*/

#endif /* _EIP_DLR_H_ */
