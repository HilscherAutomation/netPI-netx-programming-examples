/**************************************************************************************

Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.

***************************************************************************************
$Id: Epl_Common_ObjDict.h 3176 2017-07-05 15:26:30Z Ricky $:

Description:
  Powerlink definitions used for Object Dictionary handling
**************************************************************************************/

#ifndef EPL_COMMON_OBJDICT_H_
#define EPL_COMMON_OBJDICT_H_

/*************************************************************************************/
/* Access rights for ODV3 objects                                                    */
/*************************************************************************************/
#define EPL_OD_READ_PRE_OPERATIONAL_1                               0x0001
#define EPL_OD_READ_PRE_OPERATIONAL_2                               0x0002
#define EPL_OD_READ_READY_TO_OPERATE                                0x0004
#define EPL_OD_READ_OPERATIONAL                                     0x0008
#define EPL_OD_READ_STOPPED                                         0x0010
#define EPL_OD_READ_BASIC_ETHERNET                                  0x0020
#define EPL_OD_READ_NOT_ACTIVE                                      0x0040
#define EPL_OD_READ_DURING_RESET                                    0x0080

#define EPL_OD_WRITE_PRE_OPERATIONAL_1                              0x0100
#define EPL_OD_WRITE_PRE_OPERATIONAL_2                              0x0200
#define EPL_OD_WRITE_READY_TO_OPERATE                               0x0400
#define EPL_OD_WRITE_OPERATIONAL                                    0x0800
#define EPL_OD_WRITE_STOPPED                                        0x1000
#define EPL_OD_WRITE_BASIC_ETHERNET                                 0x2000
#define EPL_OD_WRITE_NOT_ACTIVE                                     0x4000
#define EPL_OD_WRITE_DURING_RESET                                   0x8000

#define EPL_OD_READ_ALL                                             0x00FF
#define EPL_OD_WRITE_ALL                                            0xFF00

#define EPL_OD_ACCESS_ALL                                           0xFFFF

/*************************************************************************************/
/* Data types for Powerlink ODV3 objects                                             */
/*************************************************************************************/
#define EPL_OD_DATA_TYPE_BOOLEAN                                    0x0001
#define EPL_OD_DATA_TYPE_INTEGER8                                   0x0002
#define EPL_OD_DATA_TYPE_INTEGER16                                  0x0003
#define EPL_OD_DATA_TYPE_INTEGER32                                  0x0004
#define EPL_OD_DATA_TYPE_UNSIGNED8                                  0x0005
#define EPL_OD_DATA_TYPE_UNSIGNED16                                 0x0006
#define EPL_OD_DATA_TYPE_UNSIGNED32                                 0x0007
#define EPL_OD_DATA_TYPE_REAL32                                     0x0008
#define EPL_OD_DATA_TYPE_VISIBLE_STRING                             0x0009
#define EPL_OD_DATA_TYPE_OCTET_STRING                               0x000A
#define EPL_OD_DATA_TYPE_UNICODE_STRING                             0x000B
#define EPL_OD_DATA_TYPE_TIME_OF_DAY                                0x000C
#define EPL_OD_DATA_TYPE_TIME_DIFFERENCE                            0x000D
#define EPL_OD_DATA_TYPE_DOMAIN                                     0x000F
#define EPL_OD_DATA_TYPE_INTEGER24                                  0x0010
#define EPL_OD_DATA_TYPE_REAL64                                     0x0011
#define EPL_OD_DATA_TYPE_INTEGER40                                  0x0012
#define EPL_OD_DATA_TYPE_INTEGER48                                  0x0013
#define EPL_OD_DATA_TYPE_INTEGER56                                  0x0014
#define EPL_OD_DATA_TYPE_INTEGER64                                  0x0015
#define EPL_OD_DATA_TYPE_UNSIGNED24                                 0x0016
#define EPL_OD_DATA_TYPE_UNSIGNED40                                 0x0018
#define EPL_OD_DATA_TYPE_UNSIGNED48                                 0x0019
#define EPL_OD_DATA_TYPE_UNSIGNED56                                 0x001A
#define EPL_OD_DATA_TYPE_UNSIGNED64                                 0x001B
#define EPL_OD_DATA_TYPE_IDENTITY                                   0x0023
#define EPL_OD_DATA_TYPE_MAC_ADDRESS                                0x0401
#define EPL_OD_DATA_TYPE_IP_ADDRESS                                 0x0402
#define EPL_OD_DATA_TYPE_NETTIME                                    0x0403
#define EPL_OD_DATA_TYPE_PDO_COMM_PARAM_RECORD                      0x0420
#define EPL_OD_DATA_TYPE_DLL_ERROR_CNT_REC                          0x0424
#define EPL_OD_DATA_TYPE_NWL_IP_GROUP                               0x0425
#define EPL_OD_DATA_TYPE_NWL_IP_ADDR_TABLE                          0x0426
#define EPL_OD_DATA_TYPE_NMT_PARAMETER_STORAGE                      0x0429
#define EPL_OD_DATA_TYPE_NMT_INTERFACE_GROUP                        0x042B
#define EPL_OD_DATA_TYPE_NMT_CYCLE_TIMING                           0x042C
#define EPL_OD_DATA_TYPE_CFM_VERIFYCONFIGURATION                    0x0435
#define EPL_OD_DATA_TYPE_NMT_EPL_NODE_ID                            0x0439


#endif /* EPL_COMMON_OBJDICT_H_ */

/*************************************************************************************/
/*-----------------------------------------------------------------------------------*/
/*------------------- EOF -----------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/
/*************************************************************************************/
