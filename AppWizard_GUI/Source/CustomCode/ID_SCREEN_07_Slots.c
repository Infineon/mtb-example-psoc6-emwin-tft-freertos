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
File        : ID_SCREEN_07_Slots.c
Purpose     : AppWizard managed file, function content could be changed
---------------------------END-OF-HEADER------------------------------
*/

#include "Application.h"
#include "../Generated/Resource.h"
#include "../Generated/ID_SCREEN_07.h"

/*** Begin of user code area ***/
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "../../source/tft_task.h"
static WM_CALLBACK * _pcbBox;
static void _cbBox(WM_MESSAGE * pMsg);
/*********************************************************************
*
*       _cbBox
*/
static void _cbBox(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  case WM_PAINT:
    /* Call default callback */
    _pcbBox(pMsg);
    /* Draw arc */
    GUI_SetPenSize(2);
    GUI_DrawArc(80, 210, 10, 10, 0, 180);
    GUI_DrawArc(80, 210, 20, 20, 0, 180);
    GUI_DrawArc(80, 210, 30, 30, 0, 180);
    GUI_DrawArc(80, 210, 40, 40, 0, 180);
    GUI_DrawArc(80, 210, 50, 50, 0, 180);
    GUI_DrawArc(80, 210, 60, 60, 0, 180);
    break;
  default:
    _pcbBox(pMsg);
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
*       cbID_SCREEN_07
*/
void cbID_SCREEN_07(WM_MESSAGE * pMsg) {
  WM_HWIN hBox; 
  GUI_USE_PARA(pMsg);
  switch(pMsg->MsgId) {
  case WM_INIT_DIALOG:
    hBox    = WM_GetDialogItem(pMsg->hWin, ID_BOX_00);
    _pcbBox = WM_GetCallback(hBox);
    WM_SetCallback(hBox, _cbBox);
    break;
   default:
    break;
  }
}

/*********************************************************************
*
*       ID_SCREEN_07__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_00__APPW_JOB_START
*/
void ID_SCREEN_07__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_00__APPW_JOB_START(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult) {
  GUI_USE_PARA(pAction);
  GUI_USE_PARA(hScreen);
  GUI_USE_PARA(pMsg);
  GUI_USE_PARA(pResult);
}

/*********************************************************************
*
*       ID_SCREEN_07__ID_TIMER_00__APPW_NOTIFICATION_TIMER
*/
void ID_SCREEN_07__ID_TIMER_00__APPW_NOTIFICATION_TIMER(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult) {

  GUI_USE_PARA(pAction);
  GUI_USE_PARA(hScreen);
  GUI_USE_PARA(pMsg);
  GUI_USE_PARA(pResult);
  cyhal_gpio_write( CYBSP_USER_LED, CYBSP_LED_STATE_OFF);
  wait_for_switch_press_and_release();
  cyhal_gpio_write( CYBSP_USER_LED, CYBSP_LED_STATE_ON);
}

/*************************** End of file ****************************/
