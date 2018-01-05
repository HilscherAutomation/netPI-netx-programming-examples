/**********************************************************************************************

  Copyright (C) 2013 Hilscher Gesellschaft fuer Systemautomation mbH.
  This program can be used by everyone according the "industrialNETworX Public License INPL".
  The license can be downloaded under <http://www.industrialNETworX.com>.

***********************************************************************************************

   Last Modification:
    @version $Id:  $

   Description:
     Header of EtherNet/IP Timer


   Changes:

     Date        Author        Description
     ----------------------------------------------------------------------------------
     2013-11-12  RH            Created
**************************************************************************************/
#ifndef EIP_HW_ADAPTION_H
#define EIP_HW_ADAPTION_H

#include "eip_en.h"

  /* Callback function definitions */
  typedef void (*EIP_HW_1MS_CB_FN) ( void* pvArg );

  /* Handler types */
  typedef struct EIP_HW_1MS_CBK_CONFIG_Ttag           EIP_HW_1MS_CBK_CONFIG_T;
  typedef struct EIP_HW_1MS_CBK_RSC_Ttag              EIP_HW_1MS_CBK_RSC_T;

  /*#####################################################################################*/

  /** Initializes hardware dependent resources to allow for a precise function call every millisecond.
   *
   * \param pvHw        [in] Parameter set used to initialize the resources
   * \param fnCyclicFct [in] Callback function that needs to be called every millisecond
   * \param pvArg       [in] Parameter that must be passed with the call of fnCyclicFct
   *                         --> fnCyclicFct( pvArg )
   *
   * \return                 Pointer to resources.
   *                         - NULL in case the initialization failed.
   */

  EIP_HW_1MS_CBK_RSC_T*
  EipHw_1msCbk_Init( EIP_HW_1MS_CBK_CONFIG_T* ptConfig,
                     EIP_HW_1MS_CB_FN         fnCyclicFct,
                     void*                    pvArg );

  /*#####################################################################################*/

  /** De-Initializes resources that have been initialized with EipHw_1msCbk_Init
   *
   * \param pvHwRsc   [in] Pointer to resources privided by EipHw_1msCbk_Init
   */

  void
  EipHw_1msCbk_DeInit( EIP_HW_1MS_CBK_RSC_T* pvHwRsc );

  /*#####################################################################################*/

  /** Retrieves hardware depending interface counters.
   *
   * \param   ulPort               [in]  Port (1,2) for which the interface counters shall be read.
   * \param   ptInterfaceCounters  [out] Interface Counters
   *
   * \return  true if retrieving counters has been successful, otherwise false.
   */

  bool
  EipHw_GetInterfaceCounters( uint32_t                ulPort,
                              EIP_EN_INTERFACE_CNT_T* ptInterfaceCounters );

  /*#####################################################################################*/

  /** Retrieves hardware depending media counters.
   *
   * \param ulPort           [in]  Port (1,2) for which the interface counters shall be read.
   * \param ptMediaCounters  [out] Media Counters
   *
   * \return  true if retrieving counters has been successful, otherwise false.
   */

  uint32_t
  EipHw_GetMediaCounters( uint32_t            ulPort,
                          EIP_EN_MEDIA_CNT_T* ptMediaCounters );

  /*******************************************************************************/

#endif /* EIP_HW_ADAPTION_H */
