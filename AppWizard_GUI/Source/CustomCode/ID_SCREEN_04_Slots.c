/*********************************************************************
*                     SEGGER Microcontroller GmbH                    *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2023  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
File        : ID_SCREEN_04_Slots.c
Purpose     : AppWizard managed file, function content could be changed
---------------------------END-OF-HEADER------------------------------
*/

#include "Application.h"
#include "../Generated/Resource.h"
#include "../Generated/ID_SCREEN_04.h"

/*** Begin of user code area ***/
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "../../source/tft_task.h"
/*** End of user code area ***/

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       cbID_SCREEN_04
*/
void cbID_SCREEN_04(WM_MESSAGE * pMsg) {
  GUI_USE_PARA(pMsg);
}

/*********************************************************************
*
*       ID_SCREEN_04__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_00__APPW_JOB_START
*/
void ID_SCREEN_04__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_00__APPW_JOB_START(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult) {
  GUI_USE_PARA(pAction);
  GUI_USE_PARA(hScreen);
  GUI_USE_PARA(pMsg);
  GUI_USE_PARA(pResult);
}

/*********************************************************************
*
*       ID_SCREEN_04__ID_TIMER_00__APPW_NOTIFICATION_TIMER
*/
void ID_SCREEN_04__ID_TIMER_00__APPW_NOTIFICATION_TIMER(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult) {
  GUI_USE_PARA(pAction);
  GUI_USE_PARA(hScreen);
  GUI_USE_PARA(pMsg);
  GUI_USE_PARA(pResult);
  cyhal_gpio_write( CYBSP_USER_LED, CYBSP_LED_STATE_OFF);
  wait_for_switch_press_and_release();
  cyhal_gpio_write( CYBSP_USER_LED, CYBSP_LED_STATE_ON);
}

/*************************** End of file ****************************/
