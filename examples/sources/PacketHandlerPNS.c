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
  $Id: PacketHandlerPNS.c 2628 2017-02-06 10:52:10Z stefanspoerl $:

  Description:
    Protocol PacketHandler

  Changes:
    Date        Description
    -----------------------------------------------------------------------------------
    2016-11-23  initial version

**************************************************************************************/

/*****************************************************************************/
/*! \file PacketHandlerPNS.c
*   Protocol PacketHandler                                                   */
/*****************************************************************************/

#include "SystemPackets.h"
#include "PacketHandlerPNS.h"
#include "App.h"

#include <string.h>
#include <stdio.h>

#include "PNSIF_API.h"      

/*******************************************************************************
 *                                   _
 *   ____ ____ ____ _   _  ____  ___| |_   ___
 *  / ___) _  ) _  | | | |/ _  )/___)  _) /___)
 * | |  ( (/ / | | | |_| ( (/ /|___ | |__|___ |
 * |_|   \____)_|| |\____|\____|___/ \___|___/
 *               |_|
 * http://www.network-science.de/ascii/  font stop
 ******************************************************************************/

/**************************************************************************************
 function:    SetConfigParams
 description: Fills all necessary device parameters in set configuration packet.

 global:      none
 input:       PNS_IF_DEVICE_PARAMETER_T FAR* ptSetConfig    - pointer to the packet
              UINT16 usDeviceClass                          - netX device class

 output:      none
 return:      long ( size of pointer to the packet )
 **************************************************************************************/
long SetConfigParams( void* pvPck, uint16_t usDeviceClass )
{

  PNS_IF_DEVICE_PARAMETER_T FAR* ptSetConfig = pvPck;

  /* First set arrays to zero */
    memset( ptSetConfig->abNameOfStation, 0x00, 240 );             /* The NameOfStation as ASCII char-array  */
    memset( ptSetConfig->abTypeOfStation, 0x00, 240);             /* The TypeOfStation as ASCII char-array  */
    memset( ptSetConfig->abDeviceType, 0x00, 28);              /* The DeviceType as ASCII char-array     */
    memset( ptSetConfig->abOrderId, 0x00, 20);                          /* The OrderId as ASCII char-array        */

    ptSetConfig->ulSystemFlags        = PNS_IF_SYSTEM_START_AUTO_START |
                                        PNS_IF_SYSTEM_STACK_HANDLE_I_M_ENABLED  |
                                        PNS_IF_SYSTEM_ARDY_WOUT_APPL_REG_ENABLED |
                                        PNS_IF_SYSTEM_NAME_IP_HANDLING_BY_STACK_ENABLED;       /* Flags to use are defined in this file  */
    ptSetConfig->ulWdgTime            = 1000;                                           /* Watchdog time (in milliseconds)        */
    ptSetConfig->ulVendorId           = 0x011E;                                         /* Vendor ID                              */
    ptSetConfig->ulMaxAr              = 0;                                              /* Currently not used                     */
    ptSetConfig->ulCompleteInputSize  = sizeof(APP_INPUT_DATA_T);                       /* Maximum amount of allowed input data   */
    ptSetConfig->ulCompleteOutputSize = sizeof(APP_OUTPUT_DATA_T);                      /* Maximum amount of allowed output data  */


    if (usDeviceClass == RCX_HW_DEV_CLASS_CHIP_NETX_51)
    {

      ptSetConfig->ulDeviceId = 0x0115;                                                   /* Device ID                              */
      printf("DeviceID: %u\r\n", (unsigned int)ptSetConfig->ulDeviceId);

      memcpy( ptSetConfig->abNameOfStation, "netx51repns", sizeof( "netx51repns" ) );     /* The NameOfStation as ASCII char-array  */
      ptSetConfig->ulNameOfStationLen = sizeof( "netx51repns" ) - 1;                      /* Length of NameOfStation                */
      memcpy( ptSetConfig->abTypeOfStation, "NETX 51 RE/PNS", sizeof( "NETX 51 RE/PNS" ) );
                                                /* The TypeOfStation as ASCII char-array  */
      ptSetConfig->ulTypeOfStationLen = sizeof( "NETX 51 RE/PNS" ) - 1;                   /* Length of TypeOfStation                */
      memcpy( ptSetConfig->abDeviceType, "NETX 51 RE/PNS", sizeof( "NETX 51 RE/PNS" ) - 1 );
                                              /* The DeviceType as ASCII char-array     */
      memcpy( ptSetConfig->abOrderId, "2231.000", sizeof( "2231.000" ) - 1 );             /* The OrderId as ASCII char-array        */
    }

    ptSetConfig->ulIpAddr           = 0;                                                /* IP address, default: 0.0.0.0                         */
    ptSetConfig->ulNetMask          = 0;                                                /* Network mask, default: 0.0.0.0                       */
    ptSetConfig->ulGateway          = 0;                                                /* Gateway address, default: 0.0.0.0                    */
    ptSetConfig->usHwRevision       = 0;                                                /* Hardware Revision, default: 0                        */
    ptSetConfig->usSwRevision1      = 0;                                                /* Software Revision 1, default: 0                      */
    ptSetConfig->usSwRevision2      = 0;                                                /* Software Revision 2, default: 0                      */
    ptSetConfig->usSwRevision3      = 0;                                                /* Software Revision 3, default: 0                      */
    ptSetConfig->bSwRevisionPrefix  = 'V';                                              /* Software Revision Prefix, default: 0                 */
    ptSetConfig->bReserved          = 0;                                                /* Reserved, set to zero                                */
    ptSetConfig->usMaxDiagRecords   = 256;                                              /* The number of diagnosis records, default: 256        */
    ptSetConfig->usInstanceId       = 1;                                                /* Instance ID, GSDML ObjectUUID_LocalIndex, default: 1 */
    ptSetConfig->usReserved         = 0;                                                /* Reserved for future use, set to zero                 */

    return sizeof( *ptSetConfig );

} /* SetConfigParams */


/**************************************************************************************
 function:    SetModulConfig
 description: Fills all necessary information about module configuration.

 global:      none
 input:       PNS_IF_MODULE_CFG_REQ_DATA_T FAR* ptModule    - pointer to the packet

 output:      none
 return:      long (Pointer to the packet)
 **************************************************************************************/
long SetModulConfig( void* pvPck )
{

  PNS_IF_MODULE_CFG_REQ_DATA_T FAR* ptModule=pvPck;

  PNS_IF_API_STRUCT_T *ptApi = NULL;
  PNS_IF_SUBMODULE_STRUCT_T *ptSubmod = NULL;

  ptModule->ulNumApi = 0x01;                                                          /* Number of API elements to follow */
  ptApi = ( PNS_IF_API_STRUCT_T FAR* ) ( ptModule + 1 );                              /* Pointer to Module configuration  */

  ptApi->ulApi = 0x00;                                                                /* Number of the API profile to be configured   */
  ptApi->ulNumSubmodItems = 0x06;                                                     /* Number of submodule-items this API contains  */

  ptSubmod = ( PNS_IF_SUBMODULE_STRUCT_T FAR* ) ( ptApi + 1 );                        /* Pointer to Submodule configuration           */

  /* Configure the DAP V3.5 */
  ptSubmod->usSlot                = 0x0000;                                           /* Slot this submodule belongs to                                         */
  ptSubmod->usSubslot             = 0x0001;                                           /* Subslot of this submodule                                              */
  ptSubmod->ulModuleId            = 0x00002081;                                       /* Module ID to which this submodule belongs                              */
  ptSubmod->ulSubmodId            = 0x00002080;                                       /* Submodule ID                                                           */
  ptSubmod->ulProvDataLen         = 0x00000000;                                       /* Length of provider data (sent by IO-Device, received by IO-Controller) */
  ptSubmod->ulConsDataLen         = 0x00000000;                                       /* Length of consumer data (sent by IO-Controller, received by IO-Device) */
  ptSubmod->ulDPMOffsetOut        = 0x00000000;                                       /* Offset in DPM OutputArea or in Output-image, where provided data of the*/
  /* submodule shall be taken from                                          */
  ptSubmod->ulDPMOffsetIn         = 0x00000000;                                       /* Offset in DPM InputArea or in Input-image, where consumed data for the */
  /* submodule shall be copied to                                           */
  ptSubmod->usOffsetIOPSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOPS provider state for this     */
  /* submodule relative to beginning of IOPS block in DPM output area from  */
  ptSubmod->usOffsetIOPSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOPS consumer state of this       */
  /* submodule relative to beginning of IOPS block in DPM input area to     */
  ptSubmod->usOffsetIOCSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOCS provider state for this     */
  /* submodule relative to beginning of IOCS block in DPM output area from  */
  ptSubmod->usOffsetIOCSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOCS consumer state for this      */
  /* submodule relative to beginning of IOCS block in DPM input area to     */
  ptSubmod->ulReserved            = 0x00000000;                                       /* Reserved for future usage                                              */
  ptSubmod++;                                                                         /* Increment submodule                                                    */

  /* Configure PDEV PN-IO */
  ptSubmod->usSlot                = 0x0000;                                             /* Slot this submodule belongs to                                         */
  ptSubmod->usSubslot             = 0x8000;                                             /* Subslot of this submodule                                              */
  ptSubmod->ulModuleId            = 0x00002081;                                         /* Module ID to which this submodule belongs                              */
  ptSubmod->ulSubmodId            = 0x00002081;                                         /* Submodule ID                                                           */
  ptSubmod->ulProvDataLen         = 0x00000000;                                       /* Length of provider data (sent by IO-Device, received by IO-Controller) */
  ptSubmod->ulConsDataLen         = 0x00000000;                                       /* Length of consumer data (sent by IO-Controller, received by IO-Device) */
  ptSubmod->ulDPMOffsetOut        = 0x00000000;                                       /* Offset in DPM OutputArea or in Output-image, where provided data of the*/
  /* submodule shall be taken from                                          */
  ptSubmod->ulDPMOffsetIn         = 0x00000000;                                       /* Offset in DPM InputArea or in Input-image, where consumed data for the */
  /* submodule shall be copied to                                           */
  ptSubmod->usOffsetIOPSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOPS provider state for this     */
  /* submodule relative to beginning of IOPS block in DPM output area from  */
  ptSubmod->usOffsetIOPSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOPS consumer state of this       */
  /* submodule relative to beginning of IOPS block in DPM input area to     */
  ptSubmod->usOffsetIOCSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOCS provider state for this     */
  /* submodule relative to beginning of IOCS block in DPM output area from  */
  ptSubmod->usOffsetIOCSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOCS consumer state for this      */
  /* submodule relative to beginning of IOCS block in DPM input area to     */
  ptSubmod->ulReserved            = 0x00000000;                                       /* Reserved for future usage                                              */
  ptSubmod++;                                                                         /* Increment submodule                                                    */

  /* Configure PDEV Port 1 */
  ptSubmod->usSlot                = 0x0000;                                             /* Slot this submodule belongs to                                         */
  ptSubmod->usSubslot             = 0x8001;                                             /* Subslot of this submodule                                              */
  ptSubmod->ulModuleId            = 0x00002081;                                         /* Module ID to which this submodule belongs                              */
  ptSubmod->ulSubmodId            = 0x00002082;                                         /* Submodule ID                                                           */
  ptSubmod->ulProvDataLen         = 0x00000000;                                       /* Length of provider data (sent by IO-Device, received by IO-Controller) */
  ptSubmod->ulConsDataLen         = 0x00000000;                                       /* Length of consumer data (sent by IO-Controller, received by IO-Device) */
  ptSubmod->ulDPMOffsetOut        = 0x00000000;                                       /* Offset in DPM OutputArea or in Output-image, where provided data of the*/
  /* submodule shall be taken from                                          */
  ptSubmod->ulDPMOffsetIn         = 0x00000000;                                       /* Offset in DPM InputArea or in Input-image, where consumed data for the */
  /* submodule shall be copied to                                           */
  ptSubmod->usOffsetIOPSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOPS provider state for this     */
  /* submodule relative to beginning of IOPS block in DPM output area from  */
  ptSubmod->usOffsetIOPSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOPS consumer state of this       */
  /* submodule relative to beginning of IOPS block in DPM input area to     */
  ptSubmod->usOffsetIOCSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOCS provider state for this     */
  /* submodule relative to beginning of IOCS block in DPM output area from  */
  ptSubmod->usOffsetIOCSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOCS consumer state for this      */
  /* submodule relative to beginning of IOCS block in DPM input area to     */
  ptSubmod->ulReserved            = 0x00000000;                                       /* Reserved for future usage                                              */
  ptSubmod++;                                                                         /* Increment submodule                                                    */

  /* Configure PDEV Port 2 */
  ptSubmod->usSlot                = 0x0000;                                             /* Slot this submodule belongs to                                         */
  ptSubmod->usSubslot             = 0x8002;                                             /* Subslot of this submodule                                              */
  ptSubmod->ulModuleId            = 0x00002081;                                         /* Module ID to which this submodule belongs                              */
  ptSubmod->ulSubmodId            = 0x00002083;                                         /* Submodule ID                                                           */
  ptSubmod->ulProvDataLen         = 0x00000000;                                       /* Length of provider data (sent by IO-Device, received by IO-Controller) */
  ptSubmod->ulConsDataLen         = 0x00000000;                                       /* Length of consumer data (sent by IO-Controller, received by IO-Device) */
  ptSubmod->ulDPMOffsetOut        = 0x00000000;                                       /* Offset in DPM OutputArea or in Output-image, where provided data of the*/
  /* submodule shall be taken from                                          */
  ptSubmod->ulDPMOffsetIn         = 0x00000000;                                       /* Offset in DPM InputArea or in Input-image, where consumed data for the */
  /* submodule shall be copied to                                           */
  ptSubmod->usOffsetIOPSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOPS provider state for this     */
  /* submodule relative to beginning of IOPS block in DPM output area from  */
  ptSubmod->usOffsetIOPSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOPS consumer state of this       */
  /* submodule relative to beginning of IOPS block in DPM input area to     */
  ptSubmod->usOffsetIOCSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOCS provider state for this     */
  /* submodule relative to beginning of IOCS block in DPM output area from  */
  ptSubmod->usOffsetIOCSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOCS consumer state for this      */
  /* submodule relative to beginning of IOCS block in DPM input area to     */
  ptSubmod->ulReserved            = 0x00000000;                                       /* Reserved for future usage                                              */
  ptSubmod++;                                                                         /* Increment submodule                                                    */

  /* Configure Unsigned16 Input module */
  ptSubmod->usSlot                = 0x0001;                                             /* Slot this submodule belongs to                                         */
  ptSubmod->usSubslot             = 0x0001;                                             /* Subslot of this submodule                                              */
  /* PNS SET CONFIG Dirk */
  ptSubmod->ulModuleId            = 0x00000001;                                         /* Module ID to which this submodule belongs                              */
  ptSubmod->ulSubmodId            = 0x00000001;                                         /* Submodule ID                                                           */
  ptSubmod->ulProvDataLen         = sizeof(APP_INPUT_DATA_T);                                       /* Length of provider data (sent by IO-Device, received by IO-Controller) */
  ptSubmod->ulConsDataLen         = 0x00000000;                                       /* Length of consumer data (sent by IO-Controller, received by IO-Device) */
  ptSubmod->ulDPMOffsetOut        = 0x00000000;                                       /* Offset in DPM OutputArea or in Output-image, where provided data of the*/
  /* submodule shall be taken from                                          */
  ptSubmod->ulDPMOffsetIn         = 0x00000000;                                       /* Offset in DPM InputArea or in Input-image, where consumed data for the */
  /* submodule shall be copied to                                           */
  ptSubmod->usOffsetIOPSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOPS provider state for this     */
  /* submodule relative to beginning of IOPS block in DPM output area from  */
  ptSubmod->usOffsetIOPSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOPS consumer state of this       */
  /* submodule relative to beginning of IOPS block in DPM input area to     */
  ptSubmod->usOffsetIOCSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOCS provider state for this     */
  /* submodule relative to beginning of IOCS block in DPM output area from  */
  ptSubmod->usOffsetIOCSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOCS consumer state for this      */
  /* submodule relative to beginning of IOCS block in DPM input area to     */
  ptSubmod->ulReserved            = 0x00000000;                                       /* Reserved for future usage                                              */
  ptSubmod++;                                                                         /* Increment submodule                                                    */

  /* Configure Unsigned16 Output module */
  ptSubmod->usSlot                = 0x0002;                                             /* Slot this submodule belongs to                                         */
  ptSubmod->usSubslot             = 0x0001;                                             /* Subslot of this submodule                                              */
  /* PNS SET CONFIG Dirk */
  ptSubmod->ulModuleId            = 0x00000002;                                         /* Module ID to which this submodule belongs                              */
  ptSubmod->ulSubmodId            = 0x00000001;                                         /* Submodule ID                                                           */
  ptSubmod->ulProvDataLen         = 0x00000000;                                       /* Length of provider data (sent by IO-Device, received by IO-Controller) */
  ptSubmod->ulConsDataLen         = sizeof(APP_OUTPUT_DATA_T);                                       /* Length of consumer data (sent by IO-Controller, received by IO-Device) */
  ptSubmod->ulDPMOffsetOut        = 0x00000000;                                       /* Offset in DPM OutputArea or in Output-image, where provided data of the*/
  /* submodule shall be taken from                                          */
  ptSubmod->ulDPMOffsetIn         = 0x00000000;                                       /* Offset in DPM InputArea or in Input-image, where consumed data for the */
  /* submodule shall be copied to                                           */
  ptSubmod->usOffsetIOPSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOPS provider state for this     */
  /* submodule relative to beginning of IOPS block in DPM output area from  */
  ptSubmod->usOffsetIOPSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOPS consumer state of this       */
  /* submodule relative to beginning of IOPS block in DPM input area to     */
  ptSubmod->usOffsetIOCSProvider  = 0x0000;                                           /* Offset where the stack shall take the IOCS provider state for this     */
  /* submodule relative to beginning of IOCS block in DPM output area from  */
  ptSubmod->usOffsetIOCSConsumer  = 0x0000;                                           /* Offset where the stack shall put the IOCS consumer state for this      */
  /* submodule relative to beginning of IOCS block in DPM input area to     */
  ptSubmod->ulReserved            = 0x00000000;                                       /* Reserved for future usage                                              */
  ptSubmod++;                                                                         /* Increment submodule                                                    */

  return ( long ) ptSubmod - ( long ) ptModule;

} /* SetModulConfig */



/*******************************************************************/
int32_t Pns_SetConfigReq(CIFXHANDLE hChannel, CIFX_PACKET *ptPkt, uint32_t ulId){
  uint32_t lRet=CIFX_NO_ERROR;
    uint16_t usDeviceClass=RCX_HW_DEV_CLASS_CHIP_NETX_51;
//    uint16_t usDeviceClass=RCX_HW_DEV_CLASS_COMX_51;

  PNS_IF_SET_CONFIGURATION_REQUEST_REQ_T *ptSetConfigReq = ( PNS_IF_SET_CONFIGURATION_REQUEST_REQ_T* )ptPkt;
  memset(ptSetConfigReq, 0, sizeof(PNS_IF_SET_CONFIGURATION_REQUEST_REQ_T));

  ptSetConfigReq->tHead.ulDest = LOCAL_CHANNEL;
  ptSetConfigReq->tHead.ulCmd  = PNS_IF_SET_CONFIGURATION_REQ;
  ptSetConfigReq->tHead.ulLen  = sizeof( ptSetConfigReq->tData.ulTotalConfigPckLen );


  /* Fills all necessary device parameters in set configuration packet */
  ptSetConfigReq->tHead.ulLen += SetConfigParams( &ptSetConfigReq->tData.tDeviceParameters, usDeviceClass );
  /* Fills all necessary information about module configuration */
  ptSetConfigReq->tHead.ulLen += SetModulConfig( &ptSetConfigReq->tData.tModuleConfig );

  ptSetConfigReq->tData.ulTotalConfigPckLen = ptSetConfigReq->tHead.ulLen;            /* Maximum amount of allowed input data */

  lRet = Pkt_SendPacket(hChannel, ptPkt, ulId, TX_TIMEOUT);

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

static uint32_t Pns_SetConfigCnf(CIFXHANDLE hChannel, APP_DATA_T *ptAppData){

  uint32_t lRet = CIFX_NO_ERROR;
  uint32_t ulBusState = CIFX_NO_ERROR;

  /* Reset the given communication channel, after Set Configuration packet */
  lRet = xChannelReset(hChannel, CIFX_CHANNELINIT, 1000);

  /* Wait for about 5 Minutes for a PROFINET controller communication with device */
  lRet = xChannelBusState(hChannel, CIFX_BUS_STATE_ON, &ulBusState, 5*6000);

  if(lRet == CIFX_NO_ERROR || lRet == CIFX_DEV_NO_COM_FLAG){
    /* OK, BUS_ON is set now, continue */
    ptAppData->fRunning = true;
 
  }
  else {
#ifndef DEMO_QUIET
    printf("error: device cannot switch bus on\n\r");
#endif
    ptAppData->fRunning=false; /* leave main loop */
  }

  return lRet;
}

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
uint32_t Protocol_SendFirstPacket(APP_DATA_T *ptAppData){

  uint32_t lRet=RCX_S_OK;
  uint8_t abMacAddr[6] = { 0x00, 0x02, 0xA2, 0x2F, 0x90, 0x58 };
  lRet=Sys_SetMacAddressReq(ptAppData->hChannel[0], &ptAppData->tPkt, ptAppData->ulSendPktCnt++, &abMacAddr[0]);

  return lRet;
}

/*******************************************************************/
uint32_t Protocol_SendLastPacket(APP_DATA_T *ptAppData)
{
  uint32_t lRet=RCX_S_OK;

  lRet=  Sys_StartStopCommReq(ptAppData->hChannel[0],
                             &ptAppData->tPkt,
                             ptAppData->ulSendPktCnt++,
                             2);

  return lRet;
}

/*******************************************************************/
uint32_t Protocol_PacketHandler( APP_DATA_T *ptAppData )
{
  uint32_t lRet = CIFX_NO_ERROR;

  lRet = Pkt_ReceivePacket(ptAppData->hChannel[0],&ptAppData->tPkt,0);

  if( CIFX_NO_ERROR == lRet )
  {
    switch( ptAppData->tPkt.tHeader.ulCmd )
    {
    case RCX_SET_MAC_ADDR_CNF:
      Sys_SetMacAddressCnf(&ptAppData->tPkt);
      Pns_SetConfigReq(ptAppData->hChannel[0], &ptAppData->tPkt, ptAppData->ulSendPktCnt++);
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
      Sys_FirmwareIdentifyCnf( &ptAppData->tPkt);
      break;

    case RCX_HW_HARDWARE_INFO_CNF:
      Sys_HardwareInfoCnf( &ptAppData->tPkt);
      break;

    case PNS_IF_SET_CONFIGURATION_CNF:
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

    case RCX_REGISTER_APP_CNF:
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
  }

  return lRet;
}


