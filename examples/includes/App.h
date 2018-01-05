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
  $Id: App.h 2608 2017-06-28 11:35:17Z AB $:

  Description:
    Application Demo header file

  Changes:
    Date        Description
    -----------------------------------------------------------------------------------
    2017-06-28  initial version

**************************************************************************************/

/*****************************************************************************/
/*! \file  App.h
*   Application Demo header file                                             */
/*****************************************************************************/


/*****************************************************************************/
/*! typedef                                                                  */
/*****************************************************************************/
typedef struct APP_INPUT_DATA_Ttag {
  uint8_t abApp_Inputdata[10];
} APP_INPUT_DATA_T;


typedef struct APP_OUTPUT_DATA_Ttag {
  uint8_t abApp_Outputdata[4];
} APP_OUTPUT_DATA_T;


typedef struct APP_DATA_Ttag {
  int fRunning;

  CIFXHANDLE hChannel[1];  /* handle to channel */
  CIFX_PACKET tPkt;       /** Buffer for mailbox packets, dual usage send and receive */
  uint32_t ulSendPktCnt;  /** global send packet counter*/

  APP_INPUT_DATA_T tInputData;
  APP_OUTPUT_DATA_T tOutputData;
} APP_DATA_T;

