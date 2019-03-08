#ifndef __SOCK_ERROR_H
#define __SOCK_ERROR_H

/////////////////////////////////////////////////////////////////////////////////////
// Socket Api Error Codes
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: TLR_E_SOCK_UNSUPPORTED_SOCKET
//
// MessageText:
//
//  Unsupport socket domain, type and protocol combination.
//
#define TLR_E_SOCK_UNSUPPORTED_SOCKET    ((TLR_RESULT)0xC0C90001L)

//
// MessageId: TLR_E_SOCK_INVALID_SOCKET_HANDLE
//
// MessageText:
//
//  Invalid socket handle.
//
#define TLR_E_SOCK_INVALID_SOCKET_HANDLE ((TLR_RESULT)0xC0C90002L)

//
// MessageId: TLR_E_SOCK_SOCKET_CLOSED
//
// MessageText:
//
//  Socket was closed.
//
#define TLR_E_SOCK_SOCKET_CLOSED         ((TLR_RESULT)0xC0C90003L)

//
// MessageId: TLR_E_SOCK_INVALID_OP
//
// MessageText:
//
//  The command is invalid for the particular socket.
//
#define TLR_E_SOCK_INVALID_OP            ((TLR_RESULT)0xC0C90004L)

//
// MessageId: TLR_E_SOCK_INVALID_ADDRESS_FAMILY
//
// MessageText:
//
//  An invalid address family was used for this socket
//
#define TLR_E_SOCK_INVALID_ADDRESS_FAMILY ((TLR_RESULT)0xC0C90005L)

//
// MessageId: TLR_E_SOCK_IN_USE
//
// MessageText:
//
//  The specified address is already in use.
//
#define TLR_E_SOCK_IN_USE                ((TLR_RESULT)0xC0C90006L)

//
// MessageId: TLR_E_SOCK_HUP
//
// MessageText:
//
//  The remote side closed the connection
//
#define TLR_E_SOCK_HUP                   ((TLR_RESULT)0xC0C90007L)

//
// MessageId: TLR_E_SOCK_WOULDBLOCK
//
// MessageText:
//
//  The operation would block
//
#define TLR_E_SOCK_WOULDBLOCK            ((TLR_RESULT)0xC0C90008L)




#endif  //__SOCK_ERROR_H

