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
  $Id: PacketHandlerPNS.h 2491 2017-01-19 09:07:26Z Jin $:

  Description:
    Protocol PacketHandler header file

  Changes:
    Date        Description
    -----------------------------------------------------------------------------------
    2016-10-21  initial version

**************************************************************************************/

/*****************************************************************************/
/*! \file PacketHandlerPNS.h
*   Protocol PacketHandler header file                                       */
/*****************************************************************************/

#ifndef COMPONENTS_CIFXAPPLICATIONDEMOPNS_INCLUDES_PACKETHANDLERPNS_H_
#define COMPONENTS_CIFXAPPLICATIONDEMOPNS_INCLUDES_PACKETHANDLERPNS_H_

long SetConfigParams( void* pvPck, uint16_t usDeviceClass );
long SetModulConfig( void* pvPck );

int32_t Pns_SetConfigReq(CIFXHANDLE hChannel, CIFX_PACKET *ptPkt, uint32_t ulId);


#endif /* COMPONENTS_CIFXAPPLICATIONDEMOPNS_INCLUDES_PACKETHANDLERPNS_H_ */
