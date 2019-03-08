/**************************************************************************************
Copyright c Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: Epl_Common_Defines.h 3176 2017-07-05 15:26:30Z Ricky $:

Description:
  General defines for Ethernet Powerlink (from EPSG)
**************************************************************************************/

#ifndef EPL_COMMON_DEFINES_H_
#define EPL_COMMON_DEFINES_H_

/*************************************************************************************/
/* EPSG Defines                                                                      */
/*************************************************************************************/
/** EPL Message Type */
#define EPL_MSG_TYPE_SOC                         0x01
#define EPL_MSG_TYPE_PREQ                        0x03
#define EPL_MSG_TYPE_PRES                        0x04
#define EPL_MSG_TYPE_SOA                         0x05
#define EPL_MSG_TYPE_ASND                        0x06

/** EPL ASND Service ID */
#define EPL_ASND_SVC_ID_IDENT_RES                0x01
#define EPL_ASND_SVC_ID_STATUS_RES               0x02
#define EPL_ASND_SVC_ID_NMT_REQ                  0x03
#define EPL_ASND_SVC_ID_NMT_CMD                  0x04
#define EPL_ASND_SVC_ID_SDO                      0x05

/** EPL SoA Requested Service ID */
#define EPL_SOA_REQ_SVC_ID_NO_SERVICE            0x00
#define EPL_SOA_REQ_SVC_ID_IDENT_REQUEST         0x01
#define EPL_SOA_REQ_SVC_ID_STATUS_REQUEST        0x02
#define EPL_SOA_REQ_SVC_ID_NMT_REQUEST_INVITE    0x03

/** EPL Object Dictionary object types */
#define EPL_OD_OBJECT_TYPE_NULL                  0x00
#define EPL_OD_OBJECT_TYPE_DEFTYPE               0x05
#define EPL_OD_OBJECT_TYPE_DEFSTRUCT             0x06
#define EPL_OD_OBJECT_TYPE_VAR                   0x07
#define EPL_OD_OBJECT_TYPE_ARRAY                 0x08
#define EPL_OD_OBJECT_TYPE_RECORD                0x09

/** NMT states */
/* MN and CN states */
#define EPL_NMT_GS_OFF                           0x00      /* 0000 0000b */
#define EPL_NMT_GS_POWERED                       0x08      /* xxxx 1xxxb, super state, only for checks */
#define EPL_NMT_GS_INITIALISATION                0x09      /* xxxx 1001b, super state, only for checks */
#define EPL_NMT_GS_INITIALISING                  0x19      /* 0001 1001b */
#define EPL_NMT_GS_RESET_APPLICATION             0x29      /* 0010 1001b */
#define EPL_NMT_GS_RESET_COMMUNICATION           0x39      /* 0011 1001b */
#define EPL_NMT_GS_RESET_CONFIGURATION           0x79      /* 0111 1001b */
#define EPL_NMT_GS_COMMUNICATING                 0x0c      /* xxxx 11xxb, super state, only for checks */
/* CN states */
#define EPL_NMT_CS_NOT_ACTIVE                    0x1c      /* 0001 1100b */
#define EPL_NMT_CS_EPL_MODE                      0x0d      /* xxxx 1101b, super state, only for checks */
#define EPL_NMT_CS_PRE_OPERATIONAL_1             0x1d      /* 0001 1101b */
#define EPL_NMT_CS_PRE_OPERATIONAL_2             0x5d      /* 0101 1101b */
#define EPL_NMT_CS_READY_TO_OPERATE              0x6d      /* 0110 1101b */
#define EPL_NMT_CS_OPERATIONAL                   0xfd      /* 1111 1101b */
#define EPL_NMT_CS_STOPPED                       0x4d      /* 0100 1101b */
#define EPL_NMT_CS_BASIC_ETHERNET                0x1e      /* 0001 1110b */
/* MN states */
#define EPL_NMT_MS_NOT_ACTIVE                    0x1c      /* 0001 1100b, same as CN state code */
#define EPL_NMT_MS_EPL_MODE                      0x0d      /* xxxx 1101b, super state, only for checks  */
#define EPL_NMT_MS_PRE_OPERATIONAL_1             0x1d      /* 0001 1101b, same as CN state code  */
#define EPL_NMT_MS_PRE_OPERATIONAL_2             0x5d      /* 0101 1101b, same as CN state code */
#define EPL_NMT_MS_READY_TO_OPERATE              0x6d      /* 0110 1101b, same as CN state code */
#define EPL_NMT_MS_OPERATIONAL                   0xfd      /* 1111 1101b, same as CN state code */

/** General Purpose Constants */
#define EPL_C_ADR_BROADCAST                      0xFF      /* EPL broadcast address */
#define EPL_C_ADR_DIAG_DEF_NODE_ID               0xFD      /* EPL default address of diagnostic device */
#define EPL_C_ADR_DUMMY_NODE_ID                  0xFC      /* EPL dummy node address */
#define EPL_C_ADR_SELF_ADR_NODE_ID               0xFB      /* EPL pseudo node address to be used by a node to address itself */
#define EPL_C_ADR_INVALID                        0x00      /* EPL invalid address */
#define EPL_C_ADR_MN_DEF_NODE_ID                 0xF0      /* EPL default address of MN */
#define EPL_C_ADR_RT1_DEF_NODE_ID                0xFE      /* EPL default address of router 1 */

#define EPL_C_DLL_ASND_PRIO_NMTRQST              7         /* increased ASnd request priority to be used by NMT requests */
#define EPL_C_DLL_ASND_PRIO_STD                  0         /* standard ASnd request priority */

#define EPL_C_DLL_ETHERTYPE_EPL                  0x88AB
#define EPL_C_DLL_ETHERTYPE_IP                   0x0800

#define EPL_C_DLL_ISOCHR_MAX_PAYL                1490      /* maximum size of PReq and PRes payload data in Bytes , requires EPL_C_DLL_MAX_ASYNC_MTU */
#define EPL_C_DLL_MAX_ASYNC_MTU                  1500      /* maximum asynchronous payload in bytes including all headers exclusive the Ethernet header */
#define EPL_C_DLL_MAX_PAYL_OFFSET                1499      /* maximum offset of Ethernet frame payload in bytes, requires EPL_C_DLL_MAX_ASYNC_MTU */
#define EPL_C_DLL_MAX_RS                         7
#define EPL_C_DLL_MIN_ASYNC_MTU                  300       /* minimum asynchronous payload in bytes including all headers exclusive the Ethernet header */
#define EPL_C_DLL_MIN_PAYL_OFFSET                45        /* minimum offset of Ethernet frame payload in Bytes */

#define EPL_C_DLL_MULTICAST_AMNI                 {0x01,0x11,0x1E,0x00,0x00,0x05} /* EPL Active Managing Node Indication, canonical form. Used by EPSG DS302-A */
#define EPL_C_DLL_MULTICAST_ASND                 {0x01,0x11,0x1E,0x00,0x00,0x04} /* EPL ASnd multicast MAC address */
#define EPL_C_DLL_MULTICAST_PRES                 {0x01,0x11,0x1E,0x00,0x00,0x02} /* EPL PRes multicast MAC address */
#define EPL_C_DLL_MULTICAST_SOA                  {0x01,0x11,0x1E,0x00,0x00,0x03} /* EPL SoA multicast MAC address */
#define EPL_C_DLL_MULTICAST_SOC                  {0x01,0x11,0x1E,0x00,0x00,0x01} /* EPL SoC multicast MAC address */

#define EPL_C_DLL_PREOP1_START_CYCLES            10        /* number of unassigned SoA frames at start of NMT_MS_PRE_OPERATIONAL_1 */
#define EPL_C_DLL_T_BITTIME                      10        /* Transmission time per bit on 100 Mbit/s network in ns */
#define EPL_C_DLL_T_EPL_PDO_HEADER               10        /* EPL size of PReq and PRes PDO message header in Bytes */
#define EPL_C_DLL_T_ETH2_WRAPPER                 18        /* size of Ethernet type II wrapper consisting of header and checksum in Bytes */

#define EPL_C_DLL_T_IFG                          960       /* Ethernet Interframe Gap in ns */
#define EPL_C_DLL_T_MIN_FRAME                    5120      /* size of minimum Ethernet frame without preamble and start-of-frame-delimiter in ns */
#define EPL_C_DLL_T_PREAMBLE                     80        /* Size of Ethernet frame preamble plus start-of-frame-delimiter in ns */

#define EPL_C_ERR_MONITOR_DELAY                  10        /* Error monitoring start delay */

#define EPL_C_IP_ADR_INVALID                     0x00000000  /* invalid IP address 0.0.0.0 used to indicate no change */
#define EPL_C_IP_INVALID_MTU                     0         /* invalid MTU size used to indicate no change */

#define EPL_C_NMT_STATE_TOLERANCE                5         /* maximum reaction time to NMT state commands in cycles */
#define EPL_C_NMT_STATREQ_CYCLE                  5         /* StatusRequest cycle time to be applied to AsyncOnly CNs */

#define EPL_C_SDO_EPL_PORT                       3819      /* port to be used EPL specific UDP/IP frames */

#define EPL_C_SDO_CMDLAYERTIMEOUT                30000     /* Command layer timeout in ms */
#define EPL_C_SDO_SEQULAYERNOACK                 2         /* Number of acknowledge requests */
#define EPL_C_SDO_SEQULAYERTIMEOUT               15000     /* Sequence layer timeout in ms */

/*************************************************************************************/
/* IP configuration defines                                                          */
/*************************************************************************************/
/** EPL base IP address */
#define EPL_IP_NET_ID                            0xC0A86400  /* EPL network id class C 192.168.100.0 */
#define EPL_IP_SUBNET_MASK                       0xFFFFFF00  /* EPL subnet mask 255.255.255.0 */
#define EPL_IP_DEFAULT_GATEWAY                   0xC0A864FE  /* EPL default gateway address 192.168.100.254 */

/*************************************************************************************/
/* EPL Feature Flags                                                                 */
/*************************************************************************************/
#define EPL_FEATURE_FLAGS_ISOCHRONOUS                             0x00000001
#define EPL_FEATURE_FLAGS_SDO_VIA_UDP                             0x00000002
#define EPL_FEATURE_FLAGS_SDO_VIA_ASND                            0x00000004
#define EPL_FEATURE_FLAGS_EXTENDED_NMT_STATE_COMMANDS             0x00000020
#define EPL_FEATURE_FLAGS_DYNAMIC_PDO_MAPPING                     0x00000040
#define EPL_FEATURE_FLAGS_NMT_SERVICE_VIA_UDP                     0x00000080
#define EPL_FEATURE_FLAGS_CONFIGURATION_MANAGER                   0x00000100
#define EPL_FEATURE_FLAGS_NODEID_SETUP_BY_SOFTWARE                0x00000400 /* Not implemented */
#define EPL_FEATURE_FLAGS_SDO_READ_WRITE_ALL_BY_INDEX             0x00004000 /* Not implemented */
#define EPL_FEATURE_FLAGS_MULTIPLE_ASND                           0x00010000

#endif /* EPL_COMMON_DEFINES_H_ */
/*************************************************************************************/
/*-----------------------------------------------------------------------------------*/
/*------------------- EOF -----------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/
/*************************************************************************************/
