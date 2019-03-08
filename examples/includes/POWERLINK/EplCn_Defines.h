/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: EplCn_Defines.h 3176 2017-07-05 15:26:30Z Ricky $:

Description:
  Public definitions for Powerlink Controlled Node
**************************************************************************************/

#ifndef EPLCN_DEFINES_H_
#define EPLCN_DEFINES_H_

/*************************************************************************************/
/* Error Entry                                                                       */
/*************************************************************************************/
/* Error Entry Type */
#define EPLCN_NMT_ERROR_ENTRY_TYPE_STATUS                           0x8000
#define EPLCN_NMT_ERROR_ENTRY_TYPE_SEND                             0x4000

#define EPLCN_NMT_ERROR_ENTRY_TYPE_MODE_MASK_IN_TYPE                0x3000
#define EPLCN_NMT_ERROR_ENTRY_TYPE_MODE_ERROR_STATUS_CLEARED        0x0000
#define EPLCN_NMT_ERROR_ENTRY_TYPE_MODE_ERROR_OCCURED_AND_ACTIVE    0x1000
#define EPLCN_NMT_ERROR_ENTRY_TYPE_MODE_ERROR_WAS_CLEARED           0x2000
#define EPLCN_NMT_ERROR_ENTRY_TYPE_MODE_ERROR_OCCURED               0x3000

#define EPLCN_NMT_ERROR_ENTRY_TYPE_PROFILE_MASK_IN_TYPE             0x0FFF
#define EPLCN_NMT_ERROR_ENTRY_TYPE_PROFILE_VENDOR_SPECIFIC          0x0001
#define EPLCN_NMT_ERROR_ENTRY_TYPE_PROFILE_COMMUNICATION            0x0002

/* Error Entry Code */
/* Triggered by IF-Task */
#define EPLCN_NMT_ERROR_ENTRY_E_PDO_SHORT_RX                        0x8210
#define EPLCN_NMT_ERROR_ENTRY_E_PDO_MAP_VERS                        0x8211
/* Triggered by Stack */
#define EPLCN_NMT_ERROR_ENTRY_E_DLL_COLLISION_TH                    0x8163
#define EPLCN_NMT_ERROR_ENTRY_E_DLL_CRC_TH                          0x8164
#define EPLCN_NMT_ERROR_ENTRY_E_DLL_LOSS_OF_LINK                    0x8165
#define EPLCN_NMT_ERROR_ENTRY_E_DLL_JITTER_TH                       0x8235
#define EPLCN_NMT_ERROR_ENTRY_E_DLL_LOSS_PREQ_TH                    0x8242
#define EPLCN_NMT_ERROR_ENTRY_E_DLL_LOSS_SOA_TH                     0x8244
#define EPLCN_NMT_ERROR_ENTRY_E_DLL_LOSS_SOC_TH                     0x8245


#endif /* EPLCN_DEFINES_H_ */
/*************************************************************************************/
/*-----------------------------------------------------------------------------------*/
/*------------------- EOF -----------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/
/*************************************************************************************/
