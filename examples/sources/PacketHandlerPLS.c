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
  $Id: PacketHandlerECS.c 2305 2016-11-23 13:05:55Z Jin $:

  Description:
    Protocol PacketHandler

  Changes:
    Date        Description
    -----------------------------------------------------------------------------------
    2016-11-23  initial version

**************************************************************************************/

/*****************************************************************************/
/*! \file PacketHandlerPLS.c
*   Protocol PacketHandler                                                   */
/*****************************************************************************/

#include "SystemPackets.h"
#include "PacketHandlerPLS.h"

#include "EplCn_If_Public.h"
#include "Epl_Common_Defines.h"
#include "App.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Identity Information */
#define VENDOR_ID           0x00000044 /* Hilscher Verndor ID */
#define PRODUCT_CODE        0x00000001 /* CIFX */
#define SERIAL_NUMBER       0x00000000 /* Use serial number from SecMem or FDL */
#define REVISION_NUMBER     0x00000000

/*******************************************************************************
 *                                   _
 *   ____ ____ ____ _   _  ____  ___| |_   ___
 *  / ___) _  ) _  | | | |/ _  )/___)  _) /___)
 * | |  ( (/ / | | | |_| ( (/ /|___ | |__|___ |
 * |_|   \____)_|| |\____|\____|___/ \___|___/
 *               |_|
 * http://www.network-science.de/ascii/  font stop
 ******************************************************************************/
static uint32_t PowerlinkSetConfigReq(APP_DATA_T *ptAppData, CIFX_PACKET *ptPkt, uint32_t ulId)
{
  uint32_t lRet = RCX_S_OK;

  EPLCN_IF_SET_CONFIG_REQ_T* ptConfigReq = (EPLCN_IF_SET_CONFIG_REQ_T*) ptPkt;

  ptConfigReq->tHead.ulDest                 = LOCAL_CHANNEL;
  ptConfigReq->tHead.ulLen                  = sizeof(ptConfigReq->tData);
  ptConfigReq->tHead.ulCmd                  = EPLCN_IF_SET_CONFIG_REQ;
  ptConfigReq->tHead.ulSta                  = 0;
  ptConfigReq->tHead.ulExt                  = 0;

  ptConfigReq->tData.ulSystemFlags          = 0;                                    /* Auto-Start */
  ptConfigReq->tData.ulWatchdogTime         = 2000;                                 /* Watchdog = 2000ms */
  ptConfigReq->tData.ulStackCfgFlags        = 0;                                    /* Stack creates default PDO objects */
  ptConfigReq->tData.ulVendorId             = VENDOR_ID;
  ptConfigReq->tData.ulProductCode          = PRODUCT_CODE;
  ptConfigReq->tData.ulRevisionNumber       = REVISION_NUMBER;
  ptConfigReq->tData.ulSerialNumber         = SERIAL_NUMBER;
  ptConfigReq->tData.ulCycleLength          = 1000;                                 /* 1ms */
  ptConfigReq->tData.ulDeviceType           = 0;                                    /* No standard profile */
  ptConfigReq->tData.ulFeatureFlags         = 0;                                    /* Simple configuration. Stack will set the common supported features */
  ptConfigReq->tData.usPReqDataSize         = sizeof(ptAppData->tOutputData);       /* Data length Master->Slave */
  ptConfigReq->tData.usPResDataSize         = sizeof(ptAppData->tInputData);        /* Data length Slave->Master */
  ptConfigReq->tData.bPReqMappingVersion    = 0;                                    /* Mapping version of data Master->Slave */
  ptConfigReq->tData.bPResMappingVersion    = 0;                                    /* Mapping version of data Slave->Master */
  ptConfigReq->tData.usMaxPReqDataSize      = EPL_C_DLL_ISOCHR_MAX_PAYL;            /* >= ptConfigReq->tData.usPReqDataSize */
  ptConfigReq->tData.usMaxPResDataSize      = EPL_C_DLL_ISOCHR_MAX_PAYL;            /* >= ptConfigReq->tData.usPResDataSize */
  ptConfigReq->tData.bNodeId                = 1;                                    /* NodeId */
  ptConfigReq->tData.ulGatewayAddress       = 0;                                    /* Stack configures default value (192.168.100.254) */
  memset(ptConfigReq->tData.abNodeName, 0, 32);                                     /* Stack configures the Host Name in form <nodeId>-<vendorId> */
  ptConfigReq->tData.bNumberOfStatusEntries = 0;                                    /* No status entries managed by the application */
  ptConfigReq->tData.bUseCustomThreshold    = 0;                                    /* Use default Thresholds */
  ptConfigReq->tData.ulThresholdCollision   = 0;                                    /* Not evaluated, since we use default thresholds */
  ptConfigReq->tData.ulThresholdLossSoC     = 0;                                    /* Not evaluated, since we use default thresholds */
  ptConfigReq->tData.ulThresholdLossSoA     = 0;                                    /* Not evaluated, since we use default thresholds */
  ptConfigReq->tData.ulThresholdLossPReq    = 0;                                    /* Not evaluated, since we use default thresholds */
  ptConfigReq->tData.ulThresholdSoCJitter   = 0;                                    /* Not evaluated, since we use default thresholds */
  ptConfigReq->tData.ulThresholdCrcError    = 0;                                    /* Not evaluated, since we use default thresholds */
  ptConfigReq->tData.ulMinCycleLength       = 0;                                    /* Use minimum cycle length supported by the hardware */
  ptConfigReq->tData.ulThresholdSoCJitter   = 0;                                    /* Not evaluated, since we use default thresholds */

  /* Set the reserved block to 0 to ensure the compatibility with future versions of the stack */
  memset((void*)ptConfigReq->tData.aulReserved, 0, sizeof(ptConfigReq->tData.aulReserved));


  lRet = Pkt_SendPacket(ptAppData->hChannel[0], (CIFX_PACKET*)ptConfigReq, ulId, TX_TIMEOUT);
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
static uint32_t Powerlink_StateChangeInd(APP_DATA_T *ptAppData)
{
  uint32_t lRet = RCX_S_OK;
  EPLCN_IF_NMT_STATE_CHANGE_IND_T* ptStateChangeInd = (EPLCN_IF_NMT_STATE_CHANGE_IND_T*) &(ptAppData->tPkt);

  if(ptStateChangeInd->tHead.ulLen != sizeof(ptStateChangeInd->tData))
  {
    lRet = RCX_E_INVALID_PACKET_LEN;
  }
  else
  {
    ptAppData->fRunning = false;
    switch(ptStateChangeInd->tData.bCurrentState)
    {
      case EPL_NMT_GS_OFF:
        printf("State changed to EPL_NMT_GS_OFF");
        break;
      case EPL_NMT_GS_INITIALISING:
        printf("State changed to EPL_NMT_GS_INITIALISING");
        break;
      case EPL_NMT_GS_RESET_APPLICATION:
        printf("State changed to EPL_NMT_GS_RESET_APPLICATION");
        break;
      case EPL_NMT_GS_RESET_COMMUNICATION:
        printf("State changed to EPL_NMT_GS_RESET_COMMUNICATION");
        break;
      case EPL_NMT_GS_RESET_CONFIGURATION:
        printf("State changed to EPL_NMT_GS_RESET_CONFIGURATION");
        break;
      case EPL_NMT_CS_NOT_ACTIVE:
        printf("State changed to EPL_NMT_CS_NOT_ACTIVE");
        break;
      case EPL_NMT_CS_PRE_OPERATIONAL_1:
        printf("State changed to EPL_NMT_CS_PRE_OPERATIONAL_1");
        break;
      case EPL_NMT_CS_PRE_OPERATIONAL_2:
        printf("State changed to EPL_NMT_CS_PRE_OPERATIONAL_2");
        break;
      case EPL_NMT_CS_READY_TO_OPERATE:
        printf("State changed to EPL_NMT_CS_READY_TO_OPERATE");
        break;
      case EPL_NMT_CS_OPERATIONAL:
        printf("State changed to EPL_NMT_CS_OPERATIONAL");
        ptAppData->fRunning = true;
        break;
      case EPL_NMT_CS_STOPPED:
        printf("State changed to EPL_NMT_CS_STOPPED");
        break;
      case EPL_NMT_CS_BASIC_ETHERNET:
        break;
    }
  }

  return lRet;
}

/*****************************************************************************/
/** Sends first packet to begin startup sequence.
further packets are sent in Protocol_PacketHandler() if response came in     */
/*****************************************************************************/
uint32_t Protocol_SendFirstPacket(APP_DATA_T *ptAppData)
{
  uint32_t lRet = RCX_S_OK;
  uint8_t abMacAddr[6] = { 0x00, 0x02, 0xA2, 0x2F, 0x90, 0x58 };
  lRet = Sys_SetMacAddressReq(ptAppData->hChannel[0], &ptAppData->tPkt, ptAppData->ulSendPktCnt++, &abMacAddr[0]);

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


/******************************************************************************/
/** Handles every incoming response and indication.
Startup sequence is finished if RCX_START_STOP_COMM_CNF came in.              */
/******************************************************************************/
uint32_t Protocol_PacketHandler( APP_DATA_T *ptAppData )
{
  int32_t lRet = CIFX_NO_ERROR;

  lRet = Pkt_ReceivePacket(ptAppData->hChannel[0],&ptAppData->tPkt,0);

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

    case RCX_REGISTER_APP_CNF:
      lRet = Sys_RegisterAppCnf( &ptAppData->tPkt );
      if(CIFX_NO_ERROR == lRet)
      {
        lRet = PowerlinkSetConfigReq(ptAppData,
                                     &ptAppData->tPkt,
                                     ptAppData->ulSendPktCnt++);
      }
      break;

    case RCX_UNREGISTER_APP_CNF:
      lRet = ptAppData->tPkt.tHeader.ulState;
      if(CIFX_NO_ERROR == lRet)
      {
        ptAppData->fRunning = false;
      }
      break;      

    case EPLCN_IF_SET_CONFIG_CNF:
      lRet = ptAppData->tPkt.tHeader.ulState;
      if(CIFX_NO_ERROR == lRet)
      {
        Sys_EmptyPacketReq(ptAppData->hChannel[0],
                           &ptAppData->tPkt,
                           ptAppData->ulSendPktCnt++,
                           RCX_CHANNEL_INIT_REQ);

        sleep(50);
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

    case RCX_START_STOP_COMM_CNF:
      lRet = ptAppData->tPkt.tHeader.ulState;
      break;

    case RCX_FIRMWARE_IDENTIFY_CNF:
      lRet = Sys_FirmwareIdentifyCnf(&ptAppData->tPkt);
      break;

    case RCX_HW_HARDWARE_INFO_CNF:
      lRet = Sys_HardwareInfoCnf(&ptAppData->tPkt);
      break;

    case RCX_LINK_STATUS_CHANGE_IND:
      lRet = Sys_LinkStatusChangeInd(ptAppData->hChannel[0], &ptAppData->tPkt);
      break;

    case EPLCN_IF_NMT_STATE_CHANGE_IND:
      lRet = Powerlink_StateChangeInd(ptAppData);
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
        printf("warning: unhandled confirmation packet: 0x%08x\r\n", (unsigned int)ptAppData->tPkt.tHeader.ulCmd);
#endif
      }
      break;

    } /*switch*/

  } /* CIFX_NO_ERROR xChannelGetPacket */
  else if( CIFX_DEV_GET_NO_PACKET == lRet )
  {
    lRet = CIFX_NO_ERROR;
  }
  return lRet;
}


