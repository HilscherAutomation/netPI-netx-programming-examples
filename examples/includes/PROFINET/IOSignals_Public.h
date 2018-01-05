/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: IOSignals_Public.h 48786 2014-10-22 11:06:36Z Benjamin $:

Description:
    IO Signal Swap Component

    This module can be used to make a stack capable of swapping IO-data while copying
    it from source to destination without changing the stack.
    Out of a well defined, stack comprehensive configuration packet it
    generates an internal CopyCode which allows this TLR-module to swap IO-data.

    The module is also capable of copying IO-data without swapping.

   Usage:

    If this module shall be used for swapping and copying IO-data some steps have to be done.
    For every module which consists of several signals the ByteCode has to be generated.

    1. Therefore first create the TLR_CONFIGURE_SIGNAL_REQ_T describing the signals.
       Note: For modules which have both, input and output signals  two packets have to be sent.
    2. Call TLR_IO_Signal_GetByteCodeLength() to get the required length of the ByteCode.
    3. Reserve this amount of memory.
    4. Call TLR_IO_Signal_GenerateBytecode() and hand over the pointer to the reserved memory.
    5. Internally store the pointer.
    6. Whenever the IO-data shall be copied and swapped call TLR_IO_Signal_CopyData().


    If this module shall be used for only copying IO-data it is possible to directly call
    TLR_IO_Signal_CopyData() without handling over the ByteCode.
    In this case TLR_IO_Signal_CopyData() will simply perform a regular memcpy.


Changes:
 Date          Description
 -----------------------------------------------------------------------------------
 2010-02-03    some adjustments in naming
 2010-01-26    initial version
**************************************************************************************/

#ifndef IOSIGNALS_PUBLIC_H_
#define IOSIGNALS_PUBLIC_H_


/* command code definition */
enum {
  /* IO_SIGNALS_PACKET_COMMAND_START = 0x00006100 */
  IO_SIGNALS_CONFIGURE_SIGNAL_REQ = 0x00006100,
  IO_SIGNALS_CONFIGURE_SIGNAL_CNF
};

/*************************************************************************************/
/* packets */
/*************************************************************************************/


/* pragma pack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(__PNSIF_API_PACKET)
#endif


typedef enum
{
  IO_SIGNALS_TYPE_BIT = 0,            /*  0 */
  IO_SIGNALS_TYPE_BOOLEAN,            /*  1 */
  IO_SIGNALS_TYPE_BYTE,               /*  2 */
  IO_SIGNALS_TYPE_SIGNED8,            /*  3 */
  IO_SIGNALS_TYPE_UNSIGNED8,          /*  4 */
  IO_SIGNALS_TYPE_WORD,               /*  5 */
  IO_SIGNALS_TYPE_SIGNED16,           /*  6 */
  IO_SIGNALS_TYPE_UNSIGNED16,         /*  7 */
  IO_SIGNALS_TYPE_SIGNED24,           /*  8 */
  IO_SIGNALS_TYPE_UNSIGNED24,         /*  9 */
  IO_SIGNALS_TYPE_DWORD,              /* 10 */
  IO_SIGNALS_TYPE_SIGNED32,           /* 11 */
  IO_SIGNALS_TYPE_UNSIGNED32,         /* 12 */
  IO_SIGNALS_TYPE_SIGNED40,           /* 13 */
  IO_SIGNALS_TYPE_UNSIGNED40,         /* 14 */
  IO_SIGNALS_TYPE_SIGNED48,           /* 15 */
  IO_SIGNALS_TYPE_UNSIGNED48,         /* 16 */
  IO_SIGNALS_TYPE_SIGNED56,           /* 17 */
  IO_SIGNALS_TYPE_UNSIGNED56,         /* 18 */
  IO_SIGNALS_TYPE_LWORD,              /* 19 */
  IO_SIGNALS_TYPE_SIGNED64,           /* 20 */
  IO_SIGNALS_TYPE_UNSIGNED64,         /* 21 */
  IO_SIGNALS_TYPE_REAL32,             /* 22 */
  IO_SIGNALS_TYPE_REAL64,             /* 23*/
  IO_SIGNALS_TYPE_STRING,             /* 24 */
  IO_SIGNALS_TYPE_WSTRING,            /* 25 */
  IO_SIGNALS_TYPE_STRING_UUID,        /* 26 */
  IO_SIGNALS_TYPE_STRING_VISIBLE,     /* 27 */
  IO_SIGNALS_TYPE_STRING_OCTET,       /* 28 */
  IO_SIGNALS_TYPE_REAL32_STATE8,      /* 29 */
  IO_SIGNALS_TYPE_DATE,               /* 30 */
  IO_SIGNALS_TYPE_DATE_BINARY,        /* 31 */
  IO_SIGNALS_TYPE_TIME_OF_DAY,        /* 32 */
  IO_SIGNALS_TYPE_TIME_OF_DAY_NODATE, /* 33 */
  IO_SIGNALS_TYPE_TIME_DIFF,          /* 34 */
  IO_SIGNALS_TYPE_TIME_DIFF_NODATE,   /* 35 */
  IO_SIGNALS_TYPE_NETWORK_TIME,       /* 36 */
  IO_SIGNALS_TYPE_NETWORK_TIME_DIFF,  /* 37 */
  IO_SIGNALS_TYPE_F_MSGTRAILER4,      /* 38 */
  IO_SIGNALS_TYPE_F_MSGTRAILER5,      /* 39 */
  IO_SIGNALS_TYPE_ENGINEERING_UINT,   /* 40 */
  IO_SIGNALS_TYPE_MAX

} IO_SIGNALS_TYPES_E;


/*
 * CONFIGURE SIGNAL SERVICE
 *
 * This service can be used to configure signals inside the IO-data.
 * In case of e.g. PROFINET every submodule may contains different signals which have
 * to be configured separately.
 *
 */

#define IO_SIGNALS_DIRECTION_CONSUMER   (1)
#define IO_SIGNALS_DIRECTION_PROVIDER   (2)

/* Request packet */
typedef __PACKED_PRE struct IO_SIGNALS_CONFIGURE_SIGNAL_REQ_DATA_Ttag
{
  /* see fieldbus specific API Manual for a definition how this */
  /* fieldbus specific fields shall be filled. */
  TLR_UINT32                                ulFieldbusSpecific1; /* e.g. Slave Handle */
  TLR_UINT32                                ulFieldbusSpecific2;
  TLR_UINT32                                ulFieldbusSpecific3; /* e.g. Slot */
  TLR_UINT32                                ulFieldbusSpecific4; /* e.g. SubSlot */
  TLR_UINT32                                ulFieldbusSpecific5;
  TLR_UINT32                                ulFieldbusSpecific6;
  TLR_UINT32                                ulFieldbusSpecific7;
  TLR_UINT32                                ulFieldbusSpecific8;
  /* signal direction described in this packet */
  TLR_UINT32                                ulSignalsDirection;
  /* amount of signals contained in abSignals */
  TLR_UINT32                                ulTotalSignalCount;
  /* array of signals - packet definition only contains the first signal, all other follow */
  __PACKED_PRE struct
  {
    /* type of signal - see IO_SIGNALS_TYPES_E */
    TLR_UINT8                               bSignalType;
    /* amount of signal (e.g. 16 for a "16 Byte Input module") */
    TLR_UINT8                               bSignalAmount;
  } __PACKED_POST atSignals[1];
} __PACKED_POST IO_SIGNALS_CONFIGURE_SIGNAL_REQ_DATA_T;

typedef struct IO_SIGNALS_CONFIGURE_SIGNAL_REQ_Ttag
{
  TLR_PACKET_HEADER_T                       tHead;
  IO_SIGNALS_CONFIGURE_SIGNAL_REQ_DATA_T    tData;
} IO_SIGNALS_CONFIGURE_SIGNAL_REQ_T;

/* Confirmation packet */
typedef TLR_EMPTY_PACKET_T                  IO_SIGNALS_CONFIGURE_SIGNAL_CNF_T;

/* packet union */
typedef union IO_SIGNALS_CONFIGURE_SIGNAL_PCK_Ttag
{
  IO_SIGNALS_CONFIGURE_SIGNAL_REQ_T                tReq;
  IO_SIGNALS_CONFIGURE_SIGNAL_CNF_T                tCnf;
} IO_SIGNALS_CONFIGURE_SIGNAL_PCK_T;


/* pragma unpack */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(__PNSIF_API_PACKET)
#endif


/*************************************************************************************/
/* usable functions of this module */
/*************************************************************************************/

/* call this function first to get the length of the bytecode which will be generated */
TLR_RESULT IO_Signal_GetByteCodeLength(CONST IO_SIGNALS_CONFIGURE_SIGNAL_REQ_T* ptPck, TLR_UINT32* pulLength);
TLR_RESULT IO_Signal_GenerateBytecode(CONST IO_SIGNALS_CONFIGURE_SIGNAL_REQ_T* ptPck, TLR_VOID* pvCopycode);
TLR_RESULT IO_Signal_CopyData(TLR_VOID* pvDest, TLR_VOID* pvSrc, TLR_UINT32 ulLength, TLR_VOID* pvCopyCode);



#endif /* IOSIGNALS_PUBLIC_H_ */
