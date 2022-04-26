/*********************************************************************
*                     SEGGER Microcontroller GmbH                    *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2022  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
File        : ID_SCREEN_02_Slots.c
Purpose     : AppWizard managed file, function content could be changed
---------------------------END-OF-HEADER------------------------------
*/

#include "Application.h"
#include "../Generated/Resource.h"
#include "../Generated/ID_SCREEN_02.h"

/*** Begin of user code area ***/
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "../../source/tft_task.h"
static WM_CALLBACK * _pcbText4;
static WM_CALLBACK * _pcbText5;
static WM_CALLBACK * _pcbText6;
static void _cbText4(WM_MESSAGE * pMsg);
static void _cbText5(WM_MESSAGE * pMsg);
static void _cbText6(WM_MESSAGE * pMsg);
/*********************************************************************
*
*       _cbText4
*/
static void _cbText4(WM_MESSAGE * pMsg) {
  char OldTS;   
  switch (pMsg->MsgId) {
  case WM_PAINT:
    OldTS = GUI_SetTextStyle(GUI_TS_UNDERLINE);
    _pcbText4(pMsg);
    GUI_SetTextStyle(OldTS);    
    break;
  default:
    _pcbText4(pMsg);
  }
}
/*********************************************************************
*
*       _cbText5
*/
static void _cbText5(WM_MESSAGE * pMsg) {
  char OldTS;       
  switch (pMsg->MsgId) {
  case WM_PAINT:
    OldTS = GUI_SetTextStyle(GUI_TS_OVERLINE);
    _pcbText5(pMsg);
    GUI_SetTextStyle(OldTS);    
    break;
  default:
    _pcbText5(pMsg);
  }
}
/*********************************************************************
*
*       _cbText6
*/
static void _cbText6(WM_MESSAGE * pMsg) {
  char OldTS;       
  switch (pMsg->MsgId) {
  case WM_PAINT:
    OldTS = GUI_SetTextStyle(GUI_TS_STRIKETHRU);
    _pcbText6(pMsg);
    GUI_SetTextStyle(OldTS);      
    break;
  default:
    _pcbText6(pMsg);
  }
}
/*** End of user code area ***/

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       cbID_SCREEN_02
*/
void cbID_SCREEN_02(WM_MESSAGE * pMsg) {
  WM_HWIN hText; 
  GUI_USE_PARA(pMsg);
  switch(pMsg->MsgId) {
  case WM_INIT_DIALOG:
    hText    = WM_GetDialogItem(pMsg->hWin, ID_TEXT_04);
    _pcbText4 = WM_GetCallback(hText);
    WM_SetCallback(hText, _cbText4);
    hText    = WM_GetDialogItem(pMsg->hWin, ID_TEXT_05);
    _pcbText5 = WM_GetCallback(hText);
    WM_SetCallback(hText, _cbText5);
    hText    = WM_GetDialogItem(pMsg->hWin, ID_TEXT_06);
    _pcbText6 = WM_GetCallback(hText);
    WM_SetCallback(hText, _cbText6);    
    break;
   default:
    break;
  }
}

/*********************************************************************
*
*       ID_SCREEN_02__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_00__APPW_JOB_START
*/
void ID_SCREEN_02__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_00__APPW_JOB_START(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult) {
  GUI_USE_PARA(pAction);
  GUI_USE_PARA(hScreen);
  GUI_USE_PARA(pMsg);
  GUI_USE_PARA(pResult);
}

/*********************************************************************
*
*       ID_SCREEN_02__ID_TIMER_00__APPW_NOTIFICATION_TIMER
*/
void ID_SCREEN_02__ID_TIMER_00__APPW_NOTIFICATION_TIMER(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult) {
  GUI_USE_PARA(pAction);
  GUI_USE_PARA(hScreen);
  GUI_USE_PARA(pMsg);
  GUI_USE_PARA(pResult);
  cyhal_gpio_write( CYBSP_USER_LED, CYBSP_LED_STATE_OFF);
  wait_for_switch_press_and_release();
  cyhal_gpio_write( CYBSP_USER_LED, CYBSP_LED_STATE_ON);
}

/*************************** End of file ****************************/
