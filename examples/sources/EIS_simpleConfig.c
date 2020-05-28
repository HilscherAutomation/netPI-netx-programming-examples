/**************************************************************************************

   Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.

 **************************************************************************************

   Filename:
    $Workfile: EIS_simpleConfig.c $
   Last Modification:
    $Author : AB$
    $Modtime: 28.05.20 09:40 $
    $Revision$

   Targets:
     Linux : yes

   Description:
     Linux I/O test application configuring netX as EtherNet/IP adapter with 
     10 bytes produce and 4 bytes consume data across the 'cifX API' (netX driver API)

   Preconditions:
     The EtherNet/IP controller addresses adapters over their IP addresses. The
     demo configures the adapter to the IP address 192.168.210.13. Make sure your 
     controller is in the same subnetwork. e.g. 192.168.210.1

   Changes:

     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
     11        28.05.2020  AB       - changed to latest driver
     10        08.04.2019  PST      - example simplified
      9        22.06.2018  AB       - add function prototypes to prevent compiler warnings
      8        05.01.2018  AB       - new netx driver 1.1.3
      7        17.11.2017  AB       - copying controller outputs to inputs correctly
      6        26.07.2017  AB       - clear receive mailbox before starting initialization
      5        25.07.2017  AB       - checking if root
      4        16.06.2017  AB       - added EtherNet/IP adapter PacketHandlerEIS.c example 
                                      from team netX support to demo
      3        08.11.2011  SD       - support of new initialization parameter (card number)
      2        27.05.2010  SD       - Display driver version
                                    - Routine added to demonstrate event handling
                                    - Routine added to demonstrate host/bus state functions
      1        ??.??.????  ??       - Initial Version

**************************************************************************************/

#include "cifxlinux.h"
#include "cifXEndianess.h"
#include "SystemPackets.h"
#include "rcX_Public.h"

#define LOCAL_CHANNEL 0x20
#include "App.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>


#define CIFX_DEV "cifX0" /* name of the first netX device on the system */

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(a) (a=a)
#endif

typedef struct SYNC_CALLBACK_DATAtag {
  CIFXHANDLE hDevice;
} SYNC_CALLBACK_DATA;

APP_DATA_T tAppData = {0};



/*****************************************************************************/
/*! Callback rountine for events
*   \param ulNotification Sync command
*   \param ulDataLen      Length of buffer referenced by pvData
*   \param pvData         Data
*   \param pvUser         User pointer                                       */
/*****************************************************************************/
void APIENTRY EventCallback (uint32_t ulNotification, uint32_t ulDataLen, void* pvData, void* pvUser)
{
  UNREFERENCED_PARAMETER(pvData);
  UNREFERENCED_PARAMETER(ulDataLen);

  switch (ulNotification)
  {
    case CIFX_NOTIFY_RX_MBX_FULL:
      printf("EventCallback(): CIFX_NOTIFY_RX_MBX_FULL\n");
    break;

    case CIFX_NOTIFY_TX_MBX_EMPTY:
      printf("EventCallback(): CIFX_NOTIFY_TX_MBX_EMPTY\n");
    break;

    case CIFX_NOTIFY_PD0_IN:
      printf("EventCallback(): CIFX_NOTIFY_PD0_IN\n");
    break;

    case CIFX_NOTIFY_PD0_OUT:
      printf("EventCallback(): CIFX_NOTIFY_PD0_OUT\n");
    break;

    case CIFX_NOTIFY_PD1_IN:
      printf("EventCallback(): CIFX_NOTIFY_PD1_IN\n");
    break;

    case CIFX_NOTIFY_PD1_OUT:
      printf("EventCallback(): CIFX_NOTIFY_PD1_OUT\n");
    break;

    default:
      printf("EventCallback(): UNKNOWN Event, Event number %lu, pvUser 0x%08lx \n", (long unsigned int)ulNotification, (unsigned long)pvUser);
    break;
  }
}


/*****************************************************************************/
/*! Callback rountine for sync events
*   \param ulNotification Sync command
*   \param ulDataLen      Length of buffer referenced by pvData
*   \param pvData         Data
*   \param pvUser         User pointer                                       */
/*****************************************************************************/
void APIENTRY SyncEventCallback (uint32_t ulNotification, uint32_t ulDataLen, void* pvData, void* pvUser)
{
  int32_t             lRet         = 0;
  uint32_t            ulErrorCount = 0;
  SYNC_CALLBACK_DATA* ptSynchData  = (SYNC_CALLBACK_DATA*)pvUser;

  UNREFERENCED_PARAMETER(pvData);
  UNREFERENCED_PARAMETER(ulDataLen);
  UNREFERENCED_PARAMETER(ulNotification);

  printf("SyncCallback()\n");

  lRet = xChannelSyncState( ptSynchData->hDevice, CIFX_SYNC_ACKNOWLEDGE_CMD, 1000, &ulErrorCount);
  if(CIFX_NO_ERROR != lRet)
  {
    printf("Error signaling the Sync, lRet = 0x%08X\n", (unsigned int)lRet);
  }
}


static int kbhit()
{
  struct termios oldt, newt;
  int    ch;
  int    oldf;
  int    iRet = 0;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    iRet = 1;
  }
  return iRet;
}


/*****************************************************************************/
/*! Displays cifX error
*   \param lError     Error code                                             */
/*****************************************************************************/
void ShowError( int32_t lError )
{
  if( lError != CIFX_NO_ERROR)
  {
    char szError[1024] ={0};
    xDriverGetErrorDescription( lError,  szError, sizeof(szError));
    printf("Error: 0x%X, <%s>\n", (unsigned int)lError, szError);
  }
}

/*****************************************************************************/
/*! Function to demonstrate the board/channel enumeration
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t EnumBoardDemo(void)
{
#ifdef DEBUG
	printf("%s() called\n", __FUNCTION__);
#endif
  CIFXHANDLE hDriver = NULL;
  int32_t    lRet    = xDriverOpen(&hDriver);

  printf("---------- Board/Channel enumeration demo ----------\r\n");

  if(CIFX_NO_ERROR == lRet)
  {
    /* Driver/Toolkit successfully opened */
    unsigned long     ulBoard    = 0;
    BOARD_INFORMATION tBoardInfo = {0};

    /* Iterate over all boards */
    while(CIFX_NO_ERROR == xDriverEnumBoards(hDriver, ulBoard, sizeof(tBoardInfo), &tBoardInfo))
    {
      printf("Found Board %s\r\n", tBoardInfo.abBoardName);
      if(strlen( (char*)tBoardInfo.abBoardAlias) != 0)
        printf(" Alias        : %s\r\n", tBoardInfo.abBoardAlias);

      printf(" DeviceNumber : %lu\r\n",(long unsigned int)tBoardInfo.tSystemInfo.ulDeviceNumber);
      printf(" SerialNumber : %lu\r\n",(long unsigned int)tBoardInfo.tSystemInfo.ulSerialNumber);
      printf(" Board ID     : %lu\r\n",(long unsigned int)tBoardInfo.ulBoardID);
      printf(" System Error : 0x%08lX\r\n",(long unsigned int)tBoardInfo.ulSystemError);
      printf(" Channels     : %lu\r\n",(long unsigned int)tBoardInfo.ulChannelCnt);
      printf(" DPM Size     : %lu\r\n",(long unsigned int)tBoardInfo.ulDpmTotalSize);

      unsigned long       ulChannel    = 0;
      CHANNEL_INFORMATION tChannelInfo = {{0}};

      /* iterate over all channels on the current board */
      while(CIFX_NO_ERROR == xDriverEnumChannels(hDriver, ulBoard, ulChannel, sizeof(tChannelInfo), &tChannelInfo))
      {
        printf(" - Channel %lu:\r\n", ulChannel);
        printf("    Firmware : %s\r\n", tChannelInfo.abFWName);
        printf("    Version  : %u.%u.%u build %u\r\n",
               tChannelInfo.usFWMajor,
               tChannelInfo.usFWMinor,
               tChannelInfo.usFWRevision,
               tChannelInfo.usFWBuild);
        printf("    Date     : %02u/%02u/%04u\r\n",
               tChannelInfo.bFWMonth,
               tChannelInfo.bFWDay,
               tChannelInfo.usFWYear);

        printf("  Device Nr. : %lu\r\n",(long unsigned int)tChannelInfo.ulDeviceNumber);
        printf("  Serial Nr. : %lu\r\n",(long unsigned int)tChannelInfo.ulSerialNumber);
        printf("  netX Flags : 0x%08X\r\n", tChannelInfo.ulNetxFlags);
        printf("  Host Flags : 0x%08X\r\n", tChannelInfo.ulHostFlags);
        printf("  Host COS   : 0x%08X\r\n", tChannelInfo.ulHostCOSFlags);
        printf("  Device COS : 0x%08X\r\n", tChannelInfo.ulDeviceCOSFlags);

        ++ulChannel;
      }

      ++ulBoard;
    }

    /* close previously opened driver */
    xDriverClose(hDriver);
  }

  printf(" State = 0x%08X\r\n", (unsigned int)lRet);
  printf("----------------------------------------------------\r\n");

  return lRet;
}

/*****************************************************************************/
/*! Function to demonstrate communication channel functionality
*   Packet Transfer and I/O Data exchange
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
int32_t ChannelDemo()
{
#ifdef DEBUG
	printf("%s() called\n", __FUNCTION__);
#endif
  CIFXHANDLE hDriver = NULL;
  int32_t    lRet    = xDriverOpen(&hDriver);

  printf("---------- Communication Channel demo ----------\r\n");

  if(CIFX_NO_ERROR == lRet)
  {
    /* Driver/Toolkit successfully opened */
    CIFXHANDLE hChannel = NULL;
    lRet = xChannelOpen(NULL, CIFX_DEV, 0, &hChannel);

    if(CIFX_NO_ERROR != lRet)
    {
      printf("Error opening Channel!");
      return lRet;

    } else
    {

      tAppData.hChannel[0] = hChannel; 
      CHANNEL_INFORMATION tChannelInfo = {{0}};

      /* Channel successfully opened, so query basic information */
      if( CIFX_NO_ERROR != (lRet = xChannelInfo(hChannel, sizeof(CHANNEL_INFORMATION), &tChannelInfo)))
      {
        printf("Error querying system information block\r\n");
        xChannelClose(hChannel);
        return lRet;
      } else
      {
        printf("Communication Channel Info:\r\n");
        printf("Device Number    : %lu\r\n",(long unsigned int)tChannelInfo.ulDeviceNumber);
        printf("Serial Number    : %lu\r\n",(long unsigned int)tChannelInfo.ulSerialNumber);
        printf("Firmware         : %s\r\n", tChannelInfo.abFWName);
        printf("FW Version       : %u.%u.%u build %u\r\n",
                tChannelInfo.usFWMajor,
                tChannelInfo.usFWMinor,
                tChannelInfo.usFWRevision,
                tChannelInfo.usFWBuild);
        printf("FW Date          : %02u/%02u/%04u\r\n",
                tChannelInfo.bFWMonth,
                tChannelInfo.bFWDay,
                tChannelInfo.usFWYear);

        printf("Mailbox Size     : %lu\r\n",(long unsigned int)tChannelInfo.ulMailboxSize);
      }

      unsigned long ulIOCycles = 0;
      unsigned long ulTrigger = 0;
      unsigned long ulTriggerTmp = 0;

      printf("\nSending EtherNet/IP adapter configuration request!\n");
      printf("\nConnect your EtherNet/IP controller now to any of the two Industrial Ethernet ports.\n");
      printf("\nThe demo is waiting for the controller starting communication.\n");

      /* check and process incoming packets first to make receive mailbox empty */
      while(CIFX_NO_ERROR == (lRet = Pkt_ReceivePacket(hChannel,&tAppData.tPkt,0)));

      tAppData.fRunning = false;

      lRet = Protocol_SendFirstPacket(&tAppData);

      while(lRet == CIFX_NO_ERROR)
      {
	if(tAppData.fRunning == true)
        {
          /* slow down a second just for the purpose not to overload the console's output with IO data */
          sleep(1); 

          ++ulIOCycles;

          /* read data coming from network */
          if(CIFX_NO_ERROR != (lRet = xChannelIORead(hChannel, 0, 0, sizeof(APP_OUTPUT_DATA_T), tAppData.tOutputData.abApp_Outputdata, 10)))
          {
            if(CIFX_DEV_NO_COM_FLAG != lRet)
            {
              printf("Error reading output data values received from network!\r\n");
              break;
            }
          } else
          {
            printf("Read Data:");
            DumpData(tAppData.tOutputData.abApp_Outputdata, sizeof(APP_OUTPUT_DATA_T));

            /* copy inputs to outputs, as most simplest application*/
            memcpy(tAppData.tInputData.abApp_Inputdata,tAppData.tOutputData.abApp_Outputdata, sizeof(APP_OUTPUT_DATA_T));

            /* write data to network */
            if(CIFX_NO_ERROR != (lRet = xChannelIOWrite(hChannel, 0, 0, sizeof(APP_INPUT_DATA_T), tAppData.tInputData.abApp_Inputdata, 10)))
            {
              if(CIFX_DEV_NO_COM_FLAG != lRet)
              {

                printf("Error writing input data values that shall be transferred to the network!\r\n");
                break;
              }
            } else
            {
#ifdef DEBUG
              printf("Write Data:");
              DumpData(tAppData.tInputData.abApp_Inputdata, sizeof(APP_INPUT_DATA_T));
#endif
            }
          }

          /* save the current watchdog value */
          ulTriggerTmp = ulTrigger;

          /* call the watchdog triggering function to make sure we are alive */
          if( CIFX_NO_ERROR != (lRet = xChannelWatchdog(hChannel,CIFX_WATCHDOG_START,(TLR_UINT32*)&ulTrigger)))
          {
            printf("Error triggering the watchdog lRet = 0x%08X!!\r\n", (unsigned int)lRet);
            break;
          } else 
          {
            if(ulTrigger != ulTriggerTmp)
            {
              /* netX is alive */
              printf("\nnetX watchdog is alive: %d\n\n",ulTrigger);
            } else
            {
              printf("\nError netX watchdog is not alive\n");
              break;
            }
          }
        }

        if(kbhit())
        {
          break;
        }

        /* check and process incoming packets */
        lRet = Protocol_PacketHandler(&tAppData);
      }

      if(lRet != CIFX_NO_ERROR)
      {
        /* Read driver error description */
        ShowError( lRet);
      }

      /* stop triggering the watchdog, else netX will recognize missing trigger */
      if( CIFX_NO_ERROR != (lRet = xChannelWatchdog(hChannel,CIFX_WATCHDOG_STOP,(TLR_UINT32*)&ulTrigger)))
      {
        printf("Error stopping the watchdog lRet = 0x%08X!!\r\n", (unsigned int)lRet);
      }

      lRet = Protocol_SendLastPacket(&tAppData);

      while(lRet == CIFX_NO_ERROR) 
      {
        if(tAppData.fRunning == false)
        {
          break;
        }
        lRet = Protocol_PacketHandler(&tAppData);
      }

      if(lRet != CIFX_NO_ERROR)
      {
        /* Read driver error description */
        ShowError( lRet);
      }

      printf("IODemo ended. Total cycles %lu\n", ulIOCycles);

      xChannelClose(hChannel);
    }

    xDriverClose(hDriver);
  }

  printf(" State = 0x%08X\r\n", (unsigned int)lRet);
  printf("----------------------------------------------------\r\n");

  return lRet;

}

/*****************************************************************************/
/*! Main entry function
*   \return 0                                                                */
/*****************************************************************************/
int main(int argc, char* argv[])
{
  int32_t lRet = 0;
  struct stat buffer;

  struct CIFX_LINUX_INIT init =
  {
    .init_options        = CIFX_DRIVER_INIT_AUTOSCAN,
    .iCardNumber         = 0,
    .fEnableCardLocking  = 0,
    .base_dir            = NULL,
    .poll_interval       = 0,
    .poll_StackSize      = 0,   /* set to 0 to use default */
    .trace_level         = 255,
    .user_card_cnt       = 0,
    .user_cards          = NULL,
  };

#ifdef DEBUG
	printf("%s() called\n", __FUNCTION__);
#endif

  if(geteuid() != 0)
  {
    printf("Program did not run as root. Exiting now.\n");
    return(-1);
  }
	
  printf("\nThis demo application demonstrates the use of the socalled cifX API (netX driver API).\n\n");
  printf("It configures the netX as EtherNet/IP adapter in the length of 10 bytes consume and 4 bytes produce data.\n\n");
  printf("An EtherNet/IP controller addresses the adapter over its IP address.\n");
  printf("The demo configures the adapter to the IP address 192.168.210.13.\n");
  printf("Make sure your controller is in the same subnetwork. e.g. 192.168.210.1.\n"); 
  printf("\nPress any key to start the demo.\n");

  /* wait for user input */
  while(!kbhit());
  getchar();

  /* check if netX driver has been installed properly on the system, else install its package */
  while( (lRet = stat("/opt/cifx/plugins/netx-spm/config0",&buffer)) != 0) {
    printf("\nThe netX driver has not been found installed.\n");
    printf("Installing the driver now.\n");
    if( system("dpkg -i ./driver/netx-docker-pi-drv-2.0.1-r0.deb") == -1 ) {
      printf("Installing the driver failed. Check if driver package 'netx-docker-pi-drv-2.0.1-r0.deb' is located in folder './driver'(relative path to demo app).\n");
      return 0;
    }
  }

  /* check if the EtherNet/IP adapter has been installed properly on the system, else install its package */
  while( (lRet = stat("/opt/cifx/deviceconfig/FW/channel0/R160H000.nxf",&buffer)) != 0) {
    printf("\nThe EtherNet/IP adapter firmware has not been found installed.\n");
    printf("Installing the firmware now.\n");
    if( system("dpkg -i ./firmwares/netx-docker-pi-eis-2.12.5.0.deb") == -1) {
      printf("Installing the firmware failed. Check if firmware 'netx-docker-pi-eis-2.12.5.0.deb' package is located in folder './firmwares'(relative path to demo app).\n");
      return 0;
    }
  }


  /* Initialize the cifX device driver */
  lRet = cifXDriverInit(&init);

  if(CIFX_NO_ERROR == lRet)
  {

    /* Demonstrate the board/channel enumeration */
    EnumBoardDemo();

    /* Demonstrate communication channel functionality */
    ChannelDemo();

  }

  cifXDriverDeinit();
  return 0;
}


