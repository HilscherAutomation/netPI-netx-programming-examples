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
#ifndef _EIP_DLR_ERROR_H_
#define _EIP_DLR_ERROR_H_

#define EIP_DLR_OK                              (0x00000000L)
#define EIP_DLR_X_COMMAND_INVALID               (0xC0950001L)
#define EIP_DLR_X_NOT_INITIALIZED               (0xC0950002L)
#define EIP_DLR_E_FNC_API_INVALID_HANDLE        (0xC0950003L)
#define EIP_DLR_X_INVALID_ATTRIBUTE             (0xC0950004L)
#define EIP_DLR_E_INVALID_PORT                  (0xC0950005L)
#define EIP_DLR_E_LINK_DOWN                     (0xC0950006L)
#define EIP_DLR_X_MAX_NUM_OF_TASK_INST_EXCEEDED (0xC0950007L)
#define EIP_DLR_X_INVALID_TASK_INST             (0xC0950008L)
#define EIP_DLR_X_CALLBACK_NOT_REGISTERED       (0xC0950009L)
#define EIP_DLR_X_WRONG_DLR_STATE               (0xC095000AL)
#define EIP_DLR_X_NOT_CONFIGURED_AS_SUPERVISOR  (0xC095000BL)
#define EIP_DLR_X_INVALID_CONFIG_PARAM          (0xC095000CL)
#define EIP_DLR_X_NO_STARTUP_PARAM_AVAIL        (0xC095000DL)
#define EIP_DLR_E_NO_ETH_BUFFER                 (0xC095000EL)

#endif /* _EIP_DLR_ERROR_H_ */
