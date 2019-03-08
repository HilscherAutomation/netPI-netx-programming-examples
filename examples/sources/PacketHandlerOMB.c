/**************************************************************************************
Exclusion of Liability for this demo software:
  The following software is intended for and must only be used for reference and in an
  evaluation laboratory environment. It is provided without charge and is subject to
  alterations. There is no warranty for the software, to the extent permitted by
  applicable law. Except when otherwise stated in writing the copyright holders and/or
  other parties provide the software "as is" without warranty of any kind, either
  expressed or implied.
  Please refer to the Agreement in README_DISCLAIMER.txt, provided together with this file!
  By installing or otherwise using the software, you accept the terms of this Agreement.
  If you do not agree to the terms of this Agreement, then do not install or use the
  Software!
**************************************************************************************/

/**************************************************************************************

Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.

***************************************************************************************
  $Id: PacketHandlerOMB.c 2458 2017-01-13 11:18:07Z Jin $:

  Description:
    Protocol PacketHandler

  Changes:
    Date        Description
    -----------------------------------------------------------------------------------
    2016-11-23  initial version
    2017-01-27  OMB specific configuration

**************************************************************************************/

/*****************************************************************************/
/*! \file PacketHandlerOMB.c
*   Protocol PacketHandler                                                   */
/*****************************************************************************/

#include "SystemPackets.h"
#include "PacketHandlerOMB.h"
#include "OmbOmbTask_Public.h"
#include "App.h"

#include <stdio.h>
#include <string.h>

/*******************************************************************************
*      _        ___ _       _      _
*     | |      / __|_)     (_)_   (_)
*   _ | | ____| |__ _ ____  _| |_  _  ___  ____   ___
*  / || |/ _  )  __) |  _ \| |  _)| |/ _ \|  _ \ /___)
* ( (_| ( (/ /| |  | | | | | | |__| | |_| | | | |___ |
*  \____|\____)_|  |_|_| |_|_|\___)_|\___/|_| |_(___/
*
* http://www.network-science.de/ascii/  font stop
*******************************************************************************/
/*
#define MAC_NOT_AVAILABLE
*/
/* Default static IP address */
#define STATIC_IP 0xC0A80002   /* 192.168.0.2 */
#define NETMASK   0xFFFFFF00   /* 255.255.255.0 */
#define GATEWAY   0xC0A800FE   /* 192.168.0.254 */


/*******************************************************************************
 *                                   _
 *   ____ ____ ____ _   _  ____  ___| |_   ___
 *  / ___) _  ) _  | | | |/ _  )/___)  _) /___)
 * | |  ( (/ / | | | |_| ( (/ /|___ | |__|___ |
 * |_|   \____)_|| |\____|\____|___/ \___|___/
 *               |_|
 * http://www.network-science.de/ascii/  font stop
 ******************************************************************************/

/*****************************************************************************/
/*! set firmware confirmation data */
/*****************************************************************************/
static uint32_t Omb_SendConfig_req(CIFXHANDLE hChannel, CIFX_PACKET *ptPkt, uint32_t ulId)
{
  uint32_t lRet = RCX_S_OK;
  OMB_OMBTASK_PACKET_CMD_SET_CONFIGURATION_REQ_T* ptConfigReq = (OMB_OMBTASK_PACKET_CMD_SET_CONFIGURATION_REQ_T*)ptPkt;

  memset(ptConfigReq, 0, sizeof(*ptConfigReq));

  ptConfigReq->tHead.ulDest             = LOCAL_CHANNEL;
  ptConfigReq->tHead.ulLen              = OMB_OMBTASK_DATA_CMD_SET_CONFIGURATION_REQ_SIZE;
  ptConfigReq->tHead.ulCmd              = OMB_OMBTASK_CMD_OMB_SET_CONFIGURATION_REQ;
  ptConfigReq->tHead.ulSta              = 0;
  ptConfigReq->tHead.ulExt              = 0;

  ptConfigReq->tData.ulSystemFlags      = OMB_OMBTASK_SYS_FLAG_COM_CONTROLLED_RELEASE;
  ptConfigReq->tData.ulWdgTime          = 1000;  /* Host watchdog time in ms */

  ptConfigReq->tData.tOmbConfig.ulOpenServerSockets = 16;
  ptConfigReq->tData.tOmbConfig.ulAnswerTimeout = 20;
  ptConfigReq->tData.tOmbConfig.ulOmbOpenTime = 10;
  ptConfigReq->tData.tOmbConfig.ulMode = OMB_IO_MODE;
  ptConfigReq->tData.tOmbConfig.ulSendTimeout = 31000;
  ptConfigReq->tData.tOmbConfig.ulConnectTimeout = 31000;
  ptConfigReq->tData.tOmbConfig.ulCloseTimeout = 13000;
  ptConfigReq->tData.tOmbConfig.ulSwap =  1;

  ptConfigReq->tData.tTcpConfig.ulFlags = IP_CFG_FLAG_IP_ADDR
      | IP_CFG_FLAG_NET_MASK | IP_CFG_FLAG_GATEWAY;
  ptConfigReq->tData.tTcpConfig.ulIpAddr = STATIC_IP;
  ptConfigReq->tData.tTcpConfig.ulNetMask = NETMASK;
  ptConfigReq->tData.tTcpConfig.ulGateway = GATEWAY;

  ptConfigReq->tData.ulFlags  = 0;

  ptConfigReq->tData.tOmbConfigExt.ulProcessWatchdog  = 0;
  ptConfigReq->tData.tOmbConfigExt.ulInactiveTimeout  = 0;
  ptConfigReq->tData.tOmbConfigExt.usMaxRegisterNumber  = 2880;
  ptConfigReq->tData.tOmbConfigExt.usMaxCoilsNumber  = 46080;

  lRet = Pkt_SendPacket(hChannel, (CIFX_PACKET*)ptConfigReq, ulId, TX_TIMEOUT_OMB);
  return lRet;
}


/*******************************************************************************
 *                    ___ _                        _
 *                   / __|_)                  _   (_)
 *   ____ ___  ____ | |__ _  ____ ____   ____| |_  _  ___  ____   ___
 *  / ___) _ \|  _ \|  __) |/ ___)    \ / _  |  _)| |/ _ \|  _ \ /___)
 * ( (__| |_| | | | | |  | | |   | | | ( ( | | |__| | |_| | | | |___ |
 *  \____)___/|_| |_|_|  |_|_|   |_|_|_|\_||_|\___)_|\___/|_| |_(___/
 *
 * http://www.network-science.de/ascii/  font stop
 ******************************************************************************/




/*******************************************************************************
 *  _           _ _                 _
 * (_)         | (_)           _   (_)
 *  _ ____   _ | |_  ____ ____| |_  _  ___  ____   ___
 * | |  _ \ / || | |/ ___) _  |  _)| |/ _ \|  _ \ /___)
 * | | | | ( (_| | ( (__( ( | | |__| | |_| | | | |___ |
 * |_|_| |_|\____|_|\____)_||_|\___)_|\___/|_| |_(___/
 *
 * http://www.network-science.de/ascii/  font stop
 ******************************************************************************/


/*******************************************************************/
uint32_t Protocol_SendFirstPacket(APP_DATA_T *ptAppData)
{
  uint32_t lRet=RCX_S_OK;

#ifdef MAC_NOT_AVAILABLE
  uint8_t abMacAddr[6] = { 0x00, 0x02, 0xA2, 0x2F, 0x90, 0x58 };
  lRet = Sys_SetMacAddressReq(ptAppData->hChannel[0], &ptAppData->tPkt, ptAppData->ulSendPktCnt++, &abMacAddr[0]);
#else
  lRet = Sys_EmptyPacketReq(ptAppData->hChannel[0], &ptAppData->tPkt, ptAppData->ulSendPktCnt++, RCX_REGISTER_APP_REQ);
#endif

  return lRet;
}

/*******************************************************************/
uint32_t Protocol_SendLastPacket(APP_DATA_T *ptAppData)
{
  uint32_t lRet=RCX_S_OK;

  lRet = Sys_EmptyPacketReq(ptAppData->hChannel[0],
                            &ptAppData->tPkt,
                            ptAppData->ulSendPktCnt++,
                            RCX_UNREGISTER_APP_REQ);
  return lRet;
}


/*******************************************************************/
uint32_t Protocol_PacketHandler( APP_DATA_T *ptAppData )
{
  static uint32_t lRet = CIFX_NO_ERROR;

  lRet = Pkt_ReceivePacket(ptAppData->hChannel[0], &ptAppData->tPkt, 0);

  if( CIFX_NO_ERROR == lRet )
  {
    switch( ptAppData->tPkt.tHeader.ulCmd )
    {
    case RCX_SET_MAC_ADDR_CNF:
      lRet = Sys_SetMacAddressCnf(&ptAppData->tPkt);
      if(CIFX_NO_ERROR == lRet)
      {
        lRet = Sys_EmptyPacketReq(ptAppData->hChannel[0],
                                  &ptAppData->tPkt,
                                  ptAppData->ulSendPktCnt++,
                                  RCX_REGISTER_APP_REQ);
      }
      break;
    case RCX_START_STOP_COMM_CNF:
      lRet = ptAppData->tPkt.tHeader.ulState;
      if(ptAppData->fRunning == false)
      {
        ptAppData->fRunning = true;
      } 
      else 
      {
        ptAppData->fRunning = false;
      }
      break;

    case RCX_FIRMWARE_IDENTIFY_CNF:
      lRet = Sys_FirmwareIdentifyCnf(&ptAppData->tPkt);
      break;

    case RCX_HW_HARDWARE_INFO_CNF:
      lRet = Sys_HardwareInfoCnf(&ptAppData->tPkt);
      break;

    case RCX_REGISTER_APP_CNF:
      lRet = Sys_RegisterAppCnf(&ptAppData->tPkt );
      if(CIFX_NO_ERROR == lRet)
      {
        lRet = Omb_SendConfig_req(ptAppData->hChannel[0],
                                  &ptAppData->tPkt,
                                  ptAppData->ulSendPktCnt++);
      }
      break;
    case RCX_UNREGISTER_APP_CNF:
      lRet = ptAppData->tPkt.tHeader.ulState;
      if(CIFX_NO_ERROR == lRet)
      {
        Sys_StartStopCommReq(ptAppData->hChannel[0],
                             &ptAppData->tPkt,
                             ptAppData->ulSendPktCnt++,
                             false);
      }
      break;

    case OMB_OMBTASK_CMD_OMB_SET_CONFIGURATION_CNF:
      lRet = ptAppData->tPkt.tHeader.ulState;
      if(CIFX_NO_ERROR == lRet)
      {
        Sys_EmptyPacketReq(ptAppData->hChannel[0],
                           &ptAppData->tPkt,
                           ptAppData->ulSendPktCnt++,
                           RCX_CHANNEL_INIT_REQ);
      }
      break;

    case RCX_CHANNEL_INIT_CNF:
      lRet = ptAppData->tPkt.tHeader.ulState;
      if(CIFX_NO_ERROR == lRet)
      {
        lRet = Sys_StartStopCommReq(ptAppData->hChannel[0],
                                    &ptAppData->tPkt,
                                    ptAppData->ulSendPktCnt++,
                                    true);
      }
      break;

    case RCX_LINK_STATUS_CHANGE_IND:
      Sys_LinkStatusChangeInd(ptAppData->hChannel[0], &ptAppData->tPkt);
      break;

    default:
      if( (ptAppData->tPkt.tHeader.ulCmd & 0x1) == 0 ) /* received an indication*/
      {
        ptAppData->tPkt.tHeader.ulLen   = 0;
        ptAppData->tPkt.tHeader.ulState = RCX_E_UNKNOWN_COMMAND;
        lRet = Pkt_ReturnPacket(ptAppData->hChannel[0], &ptAppData->tPkt, TX_TIMEOUT);
      }
      else{ /* received a confirmation */
#ifndef DEMO_QUIET
        printf("warning: unhandled confirmation packet\n\r");
#endif
      }
      break;

    } /*switch*/

  } /* CIFX_NO_ERROR xChannelGetPacket */
  else if( CIFX_DEV_GET_NO_PACKET == lRet )
  {
    lRet = CIFX_NO_ERROR;
  } /* CIFX_DEV_NOT_READY is possible and acceptable in OMB */
  else if( CIFX_DEV_NOT_READY == lRet)
  {
    lRet = CIFX_NO_ERROR;
  }
  else{}

  return lRet;
}

