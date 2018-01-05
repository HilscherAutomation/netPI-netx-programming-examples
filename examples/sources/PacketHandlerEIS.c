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
  $Id: PacketHandlerEIS.c 2458 2017-01-13 11:18:07Z Jin $:

  Description:
    Protocol PacketHandler

  Changes:
    Date        Description
    -----------------------------------------------------------------------------------
    2016-11-23  initial version
    2017-01-27  EIS specific configuration

**************************************************************************************/

/*****************************************************************************/
/*! \file PacketHandlerEIS.c
*   Protocol PacketHandler                                                   */
/*****************************************************************************/

#include "SystemPackets.h"
#include "PacketHandlerEIS.h"
#include "EipAps_Public.h"
#include "cip_common.h"
#include "eip_qos.h"
#include "eip_tcp.h"
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

#define MAC_NOT_AVAILABLE

/* Default static IP address */
#define STATIC_IP 0xC0A8D20D   /* 192.168.210.13 */

/* Identity Information */
#define VENDOR_ID                            0x11b
#define PRODUCT_TYPE_COMMUNICATION_ADAPTER   0x0c
#define PRODUCT_CODE                         0x02
#define SERIAL_NUMBER                        0
#define MINOR_REVISION                       1
#define MAJOR_REVISION                       1

/* TCP/IP Interface object related definitions */
char s_abProductName[] = "EIS_V3_SetConfigExample";
char s_abDomainName[]  = "DomainName";
char s_abHostName[]    = "HostName";

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
static uint32_t Eis_SendConfig_req(CIFXHANDLE hChannel, CIFX_PACKET *ptPkt, uint32_t ulId)
{
  uint32_t lRet = RCX_S_OK;
  EIP_APS_PACKET_SET_CONFIGURATION_PARAMETERS_REQ_T* ptConfigReq = (EIP_APS_PACKET_SET_CONFIGURATION_PARAMETERS_REQ_T*)ptPkt;

  ptConfigReq->tHead.ulDest             = LOCAL_CHANNEL;
  ptConfigReq->tHead.ulLen              = sizeof(ptConfigReq->tData);
  ptConfigReq->tHead.ulCmd              = EIP_APS_SET_CONFIGURATION_PARAMETERS_REQ;
  ptConfigReq->tHead.ulSta              = 0;
  ptConfigReq->tHead.ulExt              = 0;
  ptConfigReq->tData.ulParameterVersion = EIP_APS_CONFIGURATION_PARAMETER_SET_V3;

  ptConfigReq->tData.unConfig.tV3.ulSystemFlags = 0;
  ptConfigReq->tData.unConfig.tV3.ulWdgTime     = 2000;

#ifdef STATIC_IP
  ptConfigReq->tData.unConfig.tV3.ulTcpFlag = (IP_CFG_FLAG_AUTO_NEGOTIATE | IP_CFG_FLAG_IP_ADDR | IP_CFG_FLAG_NET_MASK | IP_CFG_FLAG_GATEWAY);
  ptConfigReq->tData.unConfig.tV3.ulIpAddr  = STATIC_IP;
  ptConfigReq->tData.unConfig.tV3.ulNetMask = 0xFFFFFF00;
  ptConfigReq->tData.unConfig.tV3.ulGateway = (STATIC_IP & ptConfigReq->tData.unConfig.tV3.ulNetMask) | 0x64;
#else
  ptConfigReq->tData.unConfig.tV3.ulTcpFlag = IP_CFG_FLAG_AUTO_NEGOTIATE | IP_CFG_FLAG_DHCP;
  /* Set to 0 we use DHCP */
  ptConfigReq->tData.unConfig.tV3.ulIpAddr  = 0;
  ptConfigReq->tData.unConfig.tV3.ulGateway = 0;
  ptConfigReq->tData.unConfig.tV3.ulNetMask = 0;
#endif

  ptConfigReq->tData.unConfig.tV3.usVendId        = VENDOR_ID;
  ptConfigReq->tData.unConfig.tV3.usProductType   = PRODUCT_TYPE_COMMUNICATION_ADAPTER;
  ptConfigReq->tData.unConfig.tV3.usProductCode   = PRODUCT_CODE;
  ptConfigReq->tData.unConfig.tV3.ulSerialNumber  = SERIAL_NUMBER;
  ptConfigReq->tData.unConfig.tV3.bMinorRev       = MINOR_REVISION;
  ptConfigReq->tData.unConfig.tV3.bMajorRev       = MAJOR_REVISION;
  ptConfigReq->tData.unConfig.tV3.abDeviceName[0] = sizeof(s_abProductName) - 1;

  memcpy( &ptConfigReq->tData.unConfig.tV3.abDeviceName[1],
          &s_abProductName[0],
          ptConfigReq->tData.unConfig.tV3.abDeviceName[0] );

  ptConfigReq->tData.unConfig.tV3.abDomainName[0] = sizeof(s_abDomainName)-1;
  ptConfigReq->tData.unConfig.tV3.abDomainName[1] = 0;

  memcpy( &ptConfigReq->tData.unConfig.tV3.abDomainName[2],
          &s_abDomainName[0],
          ptConfigReq->tData.unConfig.tV3.abDomainName[0] );

  ptConfigReq->tData.unConfig.tV3.abHostName[0] = sizeof(s_abHostName)-1;
  ptConfigReq->tData.unConfig.tV3.abHostName[1] = 0;

  memcpy( &ptConfigReq->tData.unConfig.tV3.abHostName[2],
          &s_abHostName[0],
          ptConfigReq->tData.unConfig.tV3.abHostName[0] );

  ptConfigReq->tData.unConfig.tV3.bQuickConnectFlags = 0; /* Quick Connect not supported yet */
  ptConfigReq->tData.unConfig.tV3.bSelectAcd         = 1; /* Address Conflict Detection activated by default */

  memset( &ptConfigReq->tData.unConfig.tV3.tLastConflictDetected,
          0,
          sizeof(ptConfigReq->tData.unConfig.tV3.tLastConflictDetected) );

  memset( &ptConfigReq->tData.unConfig.tV3.tQoS_Config,
          0,
          sizeof(ptConfigReq->tData.unConfig.tV3.tQoS_Config) );

  ptConfigReq->tData.unConfig.tV3.tQoS_Config.bTag802Enable     = EIP_QOS_TAG_DISABLED;
  ptConfigReq->tData.unConfig.tV3.tQoS_Config.bDSCP_PTP_Event   = EIP_QOS_DSCP_PTP_EVENT_DEFAULT;
  ptConfigReq->tData.unConfig.tV3.tQoS_Config.bDSCP_PTP_General = EIP_QOS_DSCP_PTP_GENERAL_DEFAULT;
  ptConfigReq->tData.unConfig.tV3.tQoS_Config.bDSCP_Urgent      = EIP_QOS_DSCP_URGENT_DEFAULT;
  ptConfigReq->tData.unConfig.tV3.tQoS_Config.bDSCP_Scheduled   = EIP_QOS_DSCP_SCHEDULED_DEFAULT;
  ptConfigReq->tData.unConfig.tV3.tQoS_Config.bDSCP_High        = EIP_QOS_DSCP_HIGH_DEFAULT;
  ptConfigReq->tData.unConfig.tV3.tQoS_Config.bDSCP_Low         = EIP_QOS_DSCP_LOW_DEFAULT;
  ptConfigReq->tData.unConfig.tV3.tQoS_Config.bDSCP_Explicit    = EIP_QOS_DSCP_EXPLICIT_DEFAULT;

  /* Assembly instance 100 (O2T): Run/idle header format  */
  /* ulInputXxx because from DPM point of view, actually Output from PLC point of view. The same equivalence at T2O */
  ptConfigReq->tData.unConfig.tV3.ulInputAssInstance            = 100;
  ptConfigReq->tData.unConfig.tV3.ulInputLen                    = sizeof(APP_OUTPUT_DATA_T);
  ptConfigReq->tData.unConfig.tV3.ulInputAssFlags               = EIP_AS_FLAG_READONLY;

  /* Assembly instance 101 (T2O): modeless format  */
  ptConfigReq->tData.unConfig.tV3.ulOutputAssInstance           = 101;
  ptConfigReq->tData.unConfig.tV3.ulOutputLen                   = sizeof(APP_INPUT_DATA_T);
  ptConfigReq->tData.unConfig.tV3.ulOutputAssFlags              = EIP_AS_FLAG_RUNIDLE;

  ptConfigReq->tData.unConfig.tV3.ulNameServer                  = 0;
  ptConfigReq->tData.unConfig.tV3.ulNameServer_2                = 0;

  ptConfigReq->tData.unConfig.tV3.bTTLValue                     = 1;

  ptConfigReq->tData.unConfig.tV3.tMCastConfig.bAllocControl    = EIP_TCP_ALLOCCONTROL_DEFAULT;
  ptConfigReq->tData.unConfig.tV3.tMCastConfig.ulMcastStartAddr = 0;
  ptConfigReq->tData.unConfig.tV3.tMCastConfig.usNumMCast       = 0;

  ptConfigReq->tData.unConfig.tV3.abAdminState[0]               = 1; /* Ethernet Port 1 enabled */
  ptConfigReq->tData.unConfig.tV3.abAdminState[1]               = 1; /* Ethernet Port 2 enabled */

  ptConfigReq->tData.unConfig.tV3.usEncapInactivityTimer        = EIP_TCP_ENCAP_TIMEOUT_DEFAULT;

  lRet = Pkt_SendPacket(hChannel, (CIFX_PACKET*)ptConfigReq, ulId, TX_TIMEOUT_EIS);
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
  lRet = Sys_EmptyPacketReq(ptAppData->hChannel[0], &ptAppData->tPkt, ptAppData->ulSendPktCnt++, RCX_REGISTER_APP_REQ, LOCAL_CHANNEL);
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
static void Eis_HandleConnectionInd(APP_DATA_T *ptAppData)
{
  EIP_OBJECT_PACKET_CONNECTION_IND_T* ptInd = (EIP_OBJECT_PACKET_CONNECTION_IND_T*) &(ptAppData->tPkt);

#ifndef DEMO_QUIET
  printf("Connection changed: Type %d, State %d\n\r", ptInd->tData.bConnType, (int)ptInd->tData.ulConnectionState);
#endif

  ptInd->tHead.ulLen = 0;
  ptInd->tHead.ulSta = RCX_S_OK;

  Pkt_ReturnPacket(ptAppData->hChannel[0], &ptAppData->tPkt, TX_TIMEOUT_EIS);
}


/*******************************************************************/
static void Eis_HandleResetInd(APP_DATA_T *ptAppData)
{
  EIP_OBJECT_PACKET_RESET_IND_T* ptInd  = (EIP_OBJECT_PACKET_RESET_IND_T*) &(ptAppData->tPkt);
  bool                           fRestartConfig = false;
  CIFX_PACKET                    tTemp_Packet;

#ifndef DEMO_QUIET
  printf("Reset Type %d Indication\n\r", (int)ptInd->tData.ulResetTyp );
#endif

  if( ptInd->tData.ulResetTyp == 1 )
  {
    /* store indication packet */
    tTemp_Packet = ptAppData->tPkt;

    /* send delete config request */
    memset(&ptAppData->tPkt, 0x00, sizeof(ptAppData->tPkt) );

    ptAppData->tPkt.tHeader.ulDest = LOCAL_CHANNEL;
    ptAppData->tPkt.tHeader.ulLen  = 0;
    ptAppData->tPkt.tHeader.ulCmd  = RCX_DELETE_CONFIG_REQ;

    Pkt_SendPacket(ptAppData->hChannel[0], (CIFX_PACKET*)&ptAppData->tPkt, ptAppData->ulSendPktCnt++, TX_TIMEOUT_EIS);

    /* restore indication packet */
    ptAppData->tPkt = tTemp_Packet;

    /* re-configuration necessary */
    fRestartConfig = true;
  }

  ptInd->tHead.ulLen = 0;
  ptInd->tHead.ulSta = RCX_S_OK;
  Pkt_ReturnPacket(ptAppData->hChannel[0], &ptAppData->tPkt, TX_TIMEOUT_EIS);

  if(true == fRestartConfig)
  {
    Eis_SendConfig_req(ptAppData->hChannel[0],
                       &ptAppData->tPkt,
                       ptAppData->ulSendPktCnt++);
  }
}


/**************************************************************************************/
/*! in this basic example we wont handle/support additional object classes,
 * thus we return fail */
/**************************************************************************************/
static void Eis_HandleCl3Ind(APP_DATA_T *ptAppData)
{
  EIP_OBJECT_PACKET_CL3_SERVICE_IND_T* ptInd = (EIP_OBJECT_PACKET_CL3_SERVICE_IND_T*) &(ptAppData->tPkt);
  EIP_OBJECT_PACKET_CL3_SERVICE_RES_T* ptRes = (EIP_OBJECT_PACKET_CL3_SERVICE_RES_T*) &(ptAppData->tPkt);

#ifndef DEMO_QUIET
  printf("Explicit Message Received\n\r");
  printf("Service %x, Class %x, Instance %d, Attribute %d\n\r", (int)ptInd->tData.ulService,
                                                                (int)ptInd->tData.ulObject,
                                                                (int)ptInd->tData.ulInstance,
                                                                (int)ptInd->tData.ulAttribute );
#endif


  ptRes->tHead.ulLen = EIP_OBJECT_CL3_SERVICE_RES_SIZE;
  ptRes->tHead.ulSta = RCX_E_FAIL;

  ptRes->tData.ulGRC = CIP_GSR_BAD_CLASS_INSTANCE;
  ptRes->tData.ulERC = 0;

  Pkt_ReturnPacket(ptAppData->hChannel[0], &ptAppData->tPkt, TX_TIMEOUT_EIS);
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
        lRet = Eis_SendConfig_req(ptAppData->hChannel[0],
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
                             2);
      }
      break;
    case EIP_APS_SET_CONFIGURATION_PARAMETERS_CNF:
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
        Sys_StartStopCommReq(ptAppData->hChannel[0],
                             &ptAppData->tPkt,
                             ptAppData->ulSendPktCnt++,
                             1);
      }
      break;
    case EIP_OBJECT_CONNECTION_IND:
      Eis_HandleConnectionInd(ptAppData);
      break;

    case EIP_OBJECT_RESET_IND:
      Eis_HandleResetInd(ptAppData);
      break;

    case EIP_OBJECT_CL3_SERVICE_IND:
      Eis_HandleCl3Ind(ptAppData);
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
  } /* CIFX_DEV_NOT_READY is possible and acceptable in EIS */
  else if( CIFX_DEV_NOT_READY == lRet)
  {
    lRet = CIFX_NO_ERROR;
  }
  else{}

  return lRet;
}

