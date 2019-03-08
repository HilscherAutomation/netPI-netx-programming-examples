/**************************************************************************************

Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.

***************************************************************************************

  $Id: rX_Macros.h 1892 2014-10-08 06:50:54Z stephans $:

  Description:
    rcX helper macros

  Changes:
    Date        Description
    -----------------------------------------------------------------------------------
    2011-05-20  ported from rcX V2

**************************************************************************************/

#ifndef __RX_MACROS_H
#define __RX_MACROS_H

  /*                                                               
  ************************************************************     
  *  Word manipulations
  ************************************************************     
  */
  
  #define SWAP_UINT32(a) ((((UINT32)(a) & 0x000000FF)<<24) | \
                          (((UINT32)(a) & 0x0000FF00)<<8)  | \
                          (((UINT32)(a) & 0x00FF0000)>>8)  | \
                          (((UINT32)(a) & 0xFF000000)>>24))
                          
  /*
  ************************************************************
  *  Double-Link List manipulations
  ************************************************************
  */
  /* Unlink Element from Doubly Linked List */
  #define RX_DBLY_REMOVE(Elmt) {(Elmt)->tDblyLnk.ptPrv->ptNxt = (Elmt)->tDblyLnk.ptNxt; \
                                (Elmt)->tDblyLnk.ptNxt->ptPrv = (Elmt)->tDblyLnk.ptPrv; \
                               }
  /* Link Element to End of Doubly Linked List */
  #define RX_DBLY_APPEND(Elmt,Sntl) {(Elmt)->tDblyLnk.ptNxt = &(Sntl);                        \
                                     (Elmt)->tDblyLnk.ptPrv = (Sntl).ptPrv;                   \
                                     (Sntl).ptPrv->ptNxt = (RX_DOUBLE_LINK_T FAR*)(Elmt);  \
                                     (Sntl).ptPrv = (RX_DOUBLE_LINK_T FAR*)(Elmt);         \
                                    }
  /* Link Element ahead of destination Element */
  #define RX_DBLY_INSERT_BEFORE(ElmtSrc,ElmtDst) {(ElmtSrc)->tDblyLnk.ptNxt = (RX_DOUBLE_LINK_T FAR*)(ElmtDst);              \
                                                  (ElmtSrc)->tDblyLnk.ptPrv = (RX_DOUBLE_LINK_T FAR*)(ElmtDst)->tDblyLnk.ptPrv; \
                                                  (ElmtDst)->tDblyLnk.ptPrv->ptNxt = (RX_DOUBLE_LINK_T FAR*)(ElmtSrc);       \
                                                  (ElmtDst)->tDblyLnk.ptPrv = (RX_DOUBLE_LINK_T FAR*)(ElmtSrc);              \
                                                 }
  /* Link Element after the destination Element */
  #define RX_DBLY_INSERT_AFTER(ElmtSrc,ElmtDst) {(ElmtSrc)->tDblyLnk.ptNxt = (RX_DOUBLE_LINK_T FAR*)(ElmtDst)->tDblyLnk.ptNxt; \
                                                 (ElmtSrc)->tDblyLnk.ptPrv = (RX_DOUBLE_LINK_T FAR*)(ElmtDst);              \
                                                 (ElmtDst)->tDblyLnk.ptNxt->ptPrev = (RX_DOUBLE_LINK_T FAR*)ElmtSrc);       \
                                                 (ElmtDst)->tDblyLnk.ptNxt = (RX_DOUBLE_LINK_T FAR*)(ElmtSrc);              \
                                                }


  /* Reset Doubly Linked List and make it empty */
  #define RX_DBLY_RESET(Sntl) { (Sntl).ptPrv = &(Sntl);  \
                                (Sntl).ptNxt = &(Sntl); \
                              }

  /* Tests if Sentinel is filled */
  #define IS_DBLY_FILLED(Sntl) ((Sntl).ptNxt != &(Sntl))

  /*
  *****************************************************
  *   MIN, MAX Macros
  *****************************************************
  */

  #ifndef MAX
    #define MAX(a,b)    (((a) > (b)) ? (a) : (b))
  #endif

  #ifndef MIN
    #define MIN(a,b)    (((a) > (b)) ? (b) : (a))
  #endif

  #ifndef MAX_CNT
    #define MAX_CNT(x)  (sizeof(x) / sizeof(x[0]))
  #endif

  /*
  *****************************************************
  *   PEEK, POKE Macros
  *****************************************************
  */
  
  #define POKE(addr, val) (*(volatile UINT *)(addr) = (UINT)(val))
  #define POKE_AND(addr, val) (*(volatile UINT *)(addr) &= (UINT)(val))
  #define POKE_OR(addr, val) (*(volatile UINT *)(addr) |= (UINT)(val))
  #define PEEK(addr) (*(volatile UINT *)(addr))

  /*
  *****************************************************
  *   rcX Version Macro
  *****************************************************
  */
  #define MAKE_RCX_VERSION(major,minor,build) ( ((major&0xFF)<<24) | \
                                                ((minor&0xFF)<<16) | \
                                                 (build&0xFFFF))

#endif
