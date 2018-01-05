/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: IOSignals_error.h 48786 2014-10-22 11:06:36Z Benjamin $:

Description:
 IO Signal Swap Component
 Includes IO Signal Swap error codes
**************************************************************************************/

#ifndef __IO_SIGNALS_ERROR_H
#define __IO_SIGNALS_ERROR_H

/////////////////////////////////////////////////////////////////////////////////////
// IO Signal task  ERROR codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_IO_SIGNAL_COMMAND_INVALID
//
// MessageText:
//
//  Invalid command received.
//
#define TLR_E_IO_SIGNAL_COMMAND_INVALID  ((TLR_RESULT)0xC0910001L)

//
// MessageId: TLR_E_IO_SIGNAL_INVALID_SIGNAL_DIRECTION
//
// MessageText:
//
//  The value of signal direction is invalid.
//
#define TLR_E_IO_SIGNAL_INVALID_SIGNAL_DIRECTION ((TLR_RESULT)0xC0910002L)

//
// MessageId: TLR_E_IO_SIGNAL_INVALID_SIGNAL_AMOUNT
//
// MessageText:
//
//  The value of signal amountis is invalid.
//
#define TLR_E_IO_SIGNAL_INVALID_SIGNAL_AMOUNT ((TLR_RESULT)0xC0910003L)

//
// MessageId: TLR_E_IO_SIGNAL_INVALID_SIGNAL_TYPE
//
// MessageText:
//
//  The value of signal type is invalid.
//
#define TLR_E_IO_SIGNAL_INVALID_SIGNAL_TYPE ((TLR_RESULT)0xC0910004L)

//
// MessageId: TLR_E_IO_SIGNAL_UNSUPPORTED_SIGNAL_TYPE
//
// MessageText:
//
//  The value of signal type is unsupported.
//
#define TLR_E_IO_SIGNAL_UNSUPPORTED_SIGNAL_TYPE ((TLR_RESULT)0xC0910005L)




#endif  //__IO_SIGNALS_ERROR_H

