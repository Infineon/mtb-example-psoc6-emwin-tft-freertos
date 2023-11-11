/******************************************************************************
*
* File Name: tft_task.c
*
* Description: This file contains task and functions related to the tft_task
* that demonstrates controlling a TFT display using the EmWin Graphics Library
* and AppWizard GUI design tool.
* The project displays a start up screen with Infineon logo and
* text "INFINEON EMWIN GRAPHICS DEMO TFT DISPLAY".
*
* The project then displays the following screens in a loop
*
*   1. A screen showing text alignment, styles, and modes
*   2. A screen showing text colors
*   3. A screen showing normal fonts
*   4. A screen showing bold fonts
*   5. A screen showing color gradients
*   6. A screen showing 2D graphics with horizontal lines, vertical lines
*       arcs and filled rounded rectangle
*   7. A screen showing 2D graphics with concentric circles and ellipses
*   8. A screen showing colorful concentric circles
*   9. A screen showing a bitmap image
*
*******************************************************************************
* Copyright 2021-2023, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "GUI.h"
#include "mtb_st7789v.h"
#include "tft_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/*******************************************************************************
* Macros
*******************************************************************************/
#define GPIO_INTERRUPT_PRIORITY (3u)


/*******************************************************************************
* Global Variables
*******************************************************************************/
/* The pins are defined by the st7789v library. If the display is being used
 *  on different hardware the mappings will be different. */
const mtb_st7789v_pins_t tft_pins =
{
    .db08 = CYBSP_J2_2,
    .db09 = CYBSP_J2_4,
    .db10 = CYBSP_J2_6,
    .db11 = CYBSP_J2_10,
    .db12 = CYBSP_J2_12,
    .db13 = CYBSP_D7,
    .db14 = CYBSP_D8,
    .db15 = CYBSP_D9,
    .nrd  = CYBSP_D10,
    .nwr  = CYBSP_D11,
    .dc   = CYBSP_D12,
    .rst  = CYBSP_D13
};

SemaphoreHandle_t xSwitchSemaphore = NULL;

/* Configure GPIO interrupt */
cyhal_gpio_callback_data_t switch_cb_data =
{
    .callback     = btn_interrupt_handler,
    .callback_arg = NULL
};

/*******************************************************************************
* Function Prototypes
*******************************************************************************/


/*******************************************************************************
* Function Name: void tft_task(void *arg)
********************************************************************************
*
* Summary: The Following functions are performed in this task
*           1. Initializes the EmWin display engine
*           2. Displays startup screen for 3 seconds
*           3. In an infinite loop, displays the following screens on
               key press and release
*               a. Text alignment, styles and modes
*               b. Text color
*               c. Normal fonts
*               d. Bold fonts
*               e. Color bars
*               f. 2D graphics #1
*               g. 2D graphics #2
*               h. Concentric circles
*               i. Bitmap image
*
* Parameters:
*  arg: task argument (unused)
*
* Return:
*  None
*
*******************************************************************************/
void tft_task(void *arg)
{
    cy_rslt_t result;

    /* Initialize the User Button */
    result = cyhal_gpio_init(CYBSP_USER_BTN, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_PULLUP, CYBSP_BTN_OFF);

    /* Register callback function - btn_interrupt_handler and pass the value global_count */
    cyhal_gpio_register_callback(CYBSP_USER_BTN, &switch_cb_data);

    /* Enable falling edge interrupt event with interrupt priority set to 3 */
    cyhal_gpio_enable_event(CYBSP_USER_BTN, CYHAL_GPIO_IRQ_FALL, GPIO_INTERRUPT_PRIORITY, true);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    /* Create a semaphore */
    xSwitchSemaphore = xSemaphoreCreateBinary();

    /* Initialize the User LED */
    result = cyhal_gpio_init( CYBSP_USER_LED, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG,
                     CYBSP_LED_STATE_OFF);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    /* Initialize the display controller */
    result = mtb_st7789v_init8(&tft_pins);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    /* To avoid compiler warning */
    (void)result;

    /* Calling the AppWizard application entry point*/
    MainTask();
}


/*******************************************************************************
* Function Name: void btn_interrupt_handler(void* handler_arg, cyhal_gpio_event_t event)
********************************************************************************
*
* Summary: GPIO interrupt handler.
*
* Parameters:
*  handler_arg: (unused)
*  event: (unused)
*
* Return:
*  None
*
*******************************************************************************/
void btn_interrupt_handler(void* handler_arg, cyhal_gpio_event_t event)
{
    CY_UNUSED_PARAMETER(event);
    xSemaphoreGiveFromISR(xSwitchSemaphore, NULL);
    portYIELD_FROM_ISR(pdTRUE);
}

/*******************************************************************************
* Function Name: void wait_for_switch_press_and_release(void)
********************************************************************************
*
* Summary: This implements a semaphore wait.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void wait_for_switch_press_and_release(void)
{
    /* Semaphore wait (wait for switch to be released) */
    xSemaphoreTake(xSwitchSemaphore, portMAX_DELAY);
}

/* END OF FILE */
