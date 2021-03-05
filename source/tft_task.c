/******************************************************************************
*
* File Name: tft_task.c
*
* Description: This file contains task and functions related to the tft-task
* that demonstrates controlling a tft display using the EmWin Graphics Library.
* The project displays a start up screen with Cypress logo and
* text "CYPRESS EMWIN GRAPHICS DEMO tft DISPLAY".
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
* (c) 2020, Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
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
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/

#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "GUI.h"
#include "mtb_st7789v.h"
#include "bitmaps.h"
#include "tft_task.h"
#include "FreeRTOS.h"
#include "task.h"

#define STARTUP_DELAY               (2000/*ms*/) /* Amount of time to show the startup logo */
#define NUMBER_OF_DEMO_PAGES        (9u)


/* The pins are defined by the st7789v library. If the display is being used on different hardware the mappings will be different. */
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


/*******************************************************************************
* Forward Function Prototypes
*******************************************************************************/
void show_startup_screen(void);
void show_instructions_screen(void);
void wait_for_switch_press_and_release(void);
void show_text_modes(void);
void show_text_colors(void);
void show_font_sizes_normal(void);
void show_font_sizes_bold(void);
void show_color_bar(void);
void show_2d_graphics1(void);
void show_2d_graphics2(void);
void show_concentric_circles(void);
void show_bitmap(void);

/* Array of demo pages functions */
void (*demo_page_array[NUMBER_OF_DEMO_PAGES])(void) = {
    show_text_modes,
    show_text_colors,
    show_font_sizes_normal,
    show_font_sizes_bold,
    show_color_bar,
    show_2d_graphics1,
    show_2d_graphics2,
    show_concentric_circles,
    show_bitmap
};

/*******************************************************************************
* Function Name: void tft_task(void *arg)
********************************************************************************
*
* Summary: The Following functions are performed in this task
*           1. Initializes the EmWin display engine
*           2. Displays startup screen for 3 seconds
*           3. In an infinite loop, displays the following screens on
               key press and release
*               a. Text alignement, styles and modes
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
*  None
*
* Return:
*  None
*
*******************************************************************************/
void tft_task(void *arg)
{
    cy_rslt_t result;
    uint8_t page_number = 0;

    /* Array of demo pages functions */
    void (*demo_page_array[NUMBER_OF_DEMO_PAGES])(void) = {
        show_text_modes,
        show_text_colors,
        show_font_sizes_normal,
        show_font_sizes_bold,
        show_color_bar,
        show_2d_graphics1,
        show_2d_graphics2,
        show_concentric_circles,
        show_bitmap
    };
    uint8_t num_of_demo_pages = (sizeof(demo_page_array)/sizeof(demo_page_array[0]));

    /* Initialize the User Button */
    cyhal_gpio_init(CYBSP_USER_BTN, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_PULLUP, CYBSP_BTN_OFF);

    /* Initialize the display controller */
    result = mtb_st7789v_init8(&tft_pins);
    CY_ASSERT(result == CY_RSLT_SUCCESS);
    
    /* To avoid compiler warning */
    (void)result;
    
    GUI_Init();

    /* Show the startup screen */
    show_startup_screen();
    vTaskDelay(STARTUP_DELAY);

    /* Show the instructions screen */
    show_instructions_screen();
    wait_for_switch_press_and_release();

    for(;;)
    {
        cyhal_gpio_write( CYBSP_USER_LED, CYBSP_LED_STATE_ON);

        /* Using page_number as index, update the display with a demo screen
            Following are the functions that are called in sequence
                show_font_sizes_normal()
                show_font_sizes_bold()
                show_text_modes()
                show_text_wrap_and_orientation()
                show_2d_graphics_1()
                show_2d_graphics_2()
        */
        (*demo_page_array[page_number])();
        
        cyhal_gpio_write( CYBSP_USER_LED, CYBSP_LED_STATE_OFF);

        /* Wait for a switch press event */
        wait_for_switch_press_and_release();

        /* Cycle through demo pages */
        page_number = (page_number+1) % num_of_demo_pages;
    }
}

/*******************************************************************************
* Function Name: void show_startup_screen(void)
********************************************************************************
*
* Summary: This function displays the startup screen.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_startup_screen(void)
{
    /* Set font size, foreground color, and background color */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);

    /* Clear the screen */
    GUI_Clear();

    /* Draw the Cypress Logo */
    GUI_DrawBitmap(&bmCypressLogoFullColor_PNG_316pixels, 4, 4);

    /* Print the text Cypress EMWIN GRAPHICS DEMO TFT DISPLAY */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("CYPRESS", 160, 120);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("EMWIN GRAPHICS DEMO", 160, 140);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("TFT DISPLAY", 160, 160);
}

/*******************************************************************************
* Function Name: void show_instructions_screen(void)
********************************************************************************
*
* Summary: This function shows screen with instructions to press SW2 to
*           scroll through various display pages
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_instructions_screen(void)
{
    /* Set font size, background color and text mode */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_NORMAL);

    /* Clear the display */
    GUI_Clear();

    /* Display instructions text */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("PRESS SW2 ON THE KIT", 160, 90);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("TO SCROLL THROUGH ", 160, 110);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("DEMO PAGES!", 160, 130);
}

/*******************************************************************************
* Function Name: void wait_for_switch_press_and_release(void)
********************************************************************************
*
* Summary: This implements a simple "Wait for button press and release"
*           function.  It first waits for the button to be pressed and then
*           waits for the button to be released.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This is a blocking function and exits only on a button press and release
*
*******************************************************************************/
void wait_for_switch_press_and_release(void)
{
    /* Wait for SW2 to be pressed */
    while(cyhal_gpio_read(CYBSP_USER_BTN) == CYBSP_BTN_PRESSED);

    /* Wait for SW2 to be released */
    while(cyhal_gpio_read(CYBSP_USER_BTN) == CYBSP_BTN_OFF);
}

/*******************************************************************************
* Function Name: void show_text_modes(void)
********************************************************************************
*
* Summary: This function displays the following
*           1. Left, Center and Right aligned text
*           2. Underline, overline and strikethrough style text
*           3. Normal, reverse, transparent and XOR text modes
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_text_modes(void)
{
    /* Set font size, foreground and background colors */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Clear the screen */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_DispStringAt("1 OF 9: TEXT ALIGNMENTS, STYLES AND MODES", 160, 10);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Display left aligned text */
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt("TEXT ALIGNMENT LEFT", 0, 40);

    /* Display center aligned text */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("TEXT ALIGNMENT CENTER", 160, 60);

    /* Display right aligned text */
    GUI_SetTextAlign(GUI_TA_RIGHT);
    GUI_DispStringAt("TEXT ALIGNMENT RIGHT", 319, 80);

    /* Display underlined text */
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt("TEXT STYLE UNDERLINE", 0, 100);

    /* Display overlined text */
    GUI_SetTextStyle(GUI_TS_OVERLINE);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt("TEXT STYLE OVERLINE", 0, 120);

    /* Display strikethrough text */
    GUI_SetTextStyle(GUI_TS_STRIKETHRU);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt("TEXT STYLE STRIKETHROUGH", 0, 140);

    /* Create a rectangle filled with blue color */
    GUI_SetColor(GUI_BROWN);
    GUI_FillRect(0, 160, 319, 239);

    /* Draw two diagonal lines */
    GUI_SetColor(GUI_BLUE);
    GUI_SetPenSize(3);
    GUI_DrawLine(0, 160, 319, 239);
    GUI_DrawLine(0, 239, 319, 160);

    /* Set text color to white with black background */
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);

    /* Set text style to normal */
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Display text in normal mode. This will print white text in
        a black box */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_DispStringAt("TEXT MODE NORMAL", 160, 165);

    /* Display text in reverse mode. This will print black text n
        a white box */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextMode(GUI_TM_REV);
    GUI_DispStringAt("TEXT MODE REVERSE", 160, 185);

    /* Display transparent text.  This will display white text
        on the blue background already present in the rectangle */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringAt("TEXT MODE TRANSPARENT", 160, 205);

    /* Display XOR text.  This will XOR the blue background with
        the white text */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextMode(GUI_TM_XOR);
    GUI_DispStringAt("TEXT MODE XOR", 160, 225);
}

/*******************************************************************************
* Function Name: void show_text_colors(void)
********************************************************************************
*
* Summary: This function displays text in various colors
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_text_colors(void)
{
    /* Set font size, background color and text mode */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);

    /* Clear the display */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringAt("2 OF 9: TEXT COLORS", 160, 10);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* White */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringAt("TEXT COLOR WHITE", 160, 40);

    /* Gray */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_GRAY);
    GUI_DispStringAt("TEXT COLOR GRAY", 160, 60);

    /* Red */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_RED);
    GUI_DispStringAt("TEXT COLOR RED", 160, 80);

    /* Green */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_GREEN);
    GUI_DispStringAt("TEXT COLOR GREEN", 160, 100);

    /* Blue */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_BLUE);
    GUI_DispStringAt("TEXT COLOR BLUE", 160, 120);

    /* Yellow */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_YELLOW);
    GUI_DispStringAt("TEXT COLOR YELLOW", 160, 140);

    /* Brown */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_BROWN);
    GUI_DispStringAt("TEXT COLOR BROWN", 160, 160);

    /* Magenta */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_MAGENTA);
    GUI_DispStringAt("TEXT COLOR MAGENTA", 160, 180);

    /* Cyan */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_CYAN);
    GUI_DispStringAt("TEXT COLOR CYAN", 160, 200);

    /* Orange */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetColor(GUI_ORANGE);
    GUI_DispStringAt("TEXT COLOR ORANGE", 160, 220);
}

/*******************************************************************************
* Function Name: void show_font_sizes_normal(void)
********************************************************************************
*
* Summary: This function shows various font sizes
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_font_sizes_normal(void)
{
    /* Set font size, background color and text mode */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetColor(GUI_GRAY);

    /* Clear the display */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_DispStringAt("3 OF 9: NORMAL FONTS", 160, 10);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Font8_1*/
    GUI_SetFont(GUI_FONT_8_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_GRAY);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_DispStringAt("GUI_Font8_1", 10, 40);

    /* Font10_1*/
    GUI_SetFont(GUI_FONT_10_1);
    GUI_DispStringAt("GUI_Font10_1", 10, 50);

    /* Font13_1*/
    GUI_SetFont(GUI_FONT_13_1);
    GUI_DispStringAt("GUI_Font13_1", 10, 62);

    /* Font16_1*/
    GUI_SetFont(GUI_FONT_16_1);
    GUI_DispStringAt("GUI_Font16_1", 10, 77);

    /* Font20_1*/
    GUI_SetFont(GUI_FONT_20_1);
    GUI_DispStringAt("GUI_Font20_1", 10, 95);

    /* Font24_1*/
    GUI_SetFont(GUI_FONT_24_1);
    GUI_DispStringAt("GUI_Font24_1", 10, 117);

    /* Font32_1*/
    GUI_SetFont(GUI_FONT_32_1);
    GUI_DispStringAt("GUI_Font32_1", 10, 143);
}


/*******************************************************************************
* Function Name: void show_font_sizes_bold(void)
********************************************************************************
*
* Summary: This function shows various font sizes
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_font_sizes_bold(void)
{
    /* Set font size, background color and text mode */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_GRAY);
    GUI_SetTextMode(GUI_TM_NORMAL);

    /* Clear the display */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_DispStringAt("4 OF 9: BOLD FONTS", 160, 10);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Font13B_1*/
    GUI_SetFont(GUI_FONT_13B_1);
    GUI_DispStringAt("GUI_Font13B_1", 10, 40);

    /* Font13HB_1*/
    GUI_SetFont(GUI_FONT_13HB_1);
    GUI_DispStringAt("GUI_Font13HB_1", 10, 55);

    /* Font16B_1*/
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_DispStringAt("GUI_Font6B_1", 10, 70);

    /* FontComic18B_1*/
    GUI_SetFont(GUI_FONT_COMIC18B_1);
    GUI_DispStringAt("GUI_FontComic18B_1", 10, 88);

    /* Font20B_1*/
    GUI_SetFont(GUI_FONT_20B_1);
    GUI_DispStringAt("GUI_Font20B_1", 10, 108);

    /* Font24B_1*/
    GUI_SetFont(GUI_FONT_24B_1);
    GUI_DispStringAt("GUI_Font24B_1", 10, 130);

    /* Font32B_1*/
    GUI_SetFont(GUI_FONT_32B_1);
    GUI_DispStringAt("GUI_Font32B_1", 10, 156);
}


/*******************************************************************************
* Function Name: void show_color_bar(void)
********************************************************************************
*
* Summary: This function displays displays horizontal color bars.  For each
*           color, two bars are printed, one bar that has a gradient from
*           black to the color and another bar that has a gradient from white
*           to the color.
*
* Note: This function is provided by EmWin as a demo code.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_color_bar(void)
{
    /* Local variables */
    int x0;
    int y0;
    int yStep;
    int i;
    int xsize;
    U16 cs;
    U16 x;

    /* Initialize parameters */
    x0        = 60;
    y0        = 40;
    yStep     = 15;
    xsize     = LCD_GetDevCap(LCD_DEVCAP_XSIZE) - x0;

    /* Clear the screen */
    GUI_Clear();

    /* Display page title */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_DispStringAt("5 OF 9: COLOR BARS", 160, 5);

    /* Set text mode to normal and left alignment */
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Display labels for the bars */
    GUI_SetFont(&GUI_Font8x16);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_DispStringAt("Blue",     0, y0 +      yStep);
    GUI_DispStringAt("Green",   0, y0 +  3 * yStep);
    GUI_DispStringAt("Red",    0, y0 +  5 * yStep);
    GUI_DispStringAt("Cyan",  0, y0 +  7 * yStep);
    GUI_DispStringAt("Yellow",    0, y0 + 9 * yStep);
    GUI_DispStringAt("Magenta", 0, y0 + 11 * yStep);

    /* Draw the color bars */
    for (i = 0; i < xsize; i++)
    {
        cs = (0xFF * (U32)i) / xsize;
        x = x0 + i;;

        /* Red */
        GUI_SetColor(cs);
        GUI_DrawVLine(x, y0             , y0 +     yStep - 1);
        GUI_SetColor(0xff + (255 - cs) * 0x10100uL);
        GUI_DrawVLine(x, y0 +      yStep, y0 + 2 * yStep - 1);

        /* Green */
        GUI_SetColor(cs<<8);
        GUI_DrawVLine(x, y0 +  2 * yStep, y0 + 3 * yStep - 1);
        GUI_SetColor(0xff00 + (255 - cs) * 0x10001uL);
        GUI_DrawVLine(x, y0 +  3 * yStep, y0 + 4 * yStep - 1);

        /* Blue */
        GUI_SetColor(cs * 0x10000uL);
        GUI_DrawVLine(x, y0 +  4 * yStep, y0 + 5 * yStep - 1);
        GUI_SetColor(0xff0000 + (255 - cs) * 0x101uL);
        GUI_DrawVLine(x, y0 +  5 * yStep, y0 + 6 * yStep - 1);

        /* Yellow */
        GUI_SetColor(cs * 0x101uL);
        GUI_DrawVLine(x, y0 +  6 * yStep, y0 + 7 * yStep - 1);
        GUI_SetColor(0xffff + (255 - cs) * 0x10000uL);
        GUI_DrawVLine(x, y0 +  7 * yStep, y0 + 8 * yStep - 1);

        /* Cyan */
        GUI_SetColor(cs * 0x10100uL);
        GUI_DrawVLine(x, y0 +  8 * yStep, y0 + 9 * yStep - 1);
        GUI_SetColor(0xffff00 + (255 - cs) * 0x1L);
        GUI_DrawVLine(x, y0 + 9 * yStep, y0 + 10 * yStep - 1);

        /* Magenta */
        GUI_SetColor(cs * 0x10001uL);
        GUI_DrawVLine(x, y0 + 10 * yStep, y0 + 11 * yStep - 1);
        GUI_SetColor(0xff00ff + (255 - cs) * 0x100uL);
        GUI_DrawVLine(x, y0 + 11 * yStep, y0 + 12 * yStep - 1);
    }
}


/*******************************************************************************
* Function Name: void show_2d_graphics1(void)
********************************************************************************
*
* Summary: This function displays the following 2D graphics
*           1. Horizontal lines with various pen widths
*           2. Vertical lines with various pen widths
*           3. Arcs
*           4. Filled rounded rectangle
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_2d_graphics1(void)
{
    /* Set font size, foreground and background colors */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Clear the screen */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_DispStringAt("6 OF 9: 2D GRAPHICS - 1", 160, 10);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Set drawing color to gray */
    GUI_SetColor(GUI_GRAY);

    /* Display labels */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("H-LINES", 80, 110);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("V-LINES", 240, 110);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("ARCS", 80, 220);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("ROUNDED RECT", 240, 220);

    /* Horizontal lines */
    GUI_SetPenSize(1);
    GUI_DrawLine(10, 35, 150, 35);
    GUI_SetPenSize(2);
    GUI_DrawLine(10, 50, 150, 50);
    GUI_SetPenSize(3);
    GUI_DrawLine(10, 65, 150, 65);
    GUI_SetPenSize(4);
    GUI_DrawLine(10, 80, 150, 80);
    GUI_SetPenSize(5);
    GUI_DrawLine(10, 95, 150, 95);

    /* Vertical lines */
    GUI_SetPenSize(1);
    GUI_DrawLine(210, 30, 210, 100);
    GUI_SetPenSize(2);
    GUI_DrawLine(225, 30, 225, 100);
    GUI_SetPenSize(3);
    GUI_DrawLine(240, 30, 240, 100);
    GUI_SetPenSize(4);
    GUI_DrawLine(255, 30, 255, 100);
    GUI_SetPenSize(5);
    GUI_DrawLine(270, 30, 270, 100);

    /* Arcs */
    GUI_SetPenSize(2);
    GUI_DrawArc(80, 210, 10, 10, 0, 180);
    GUI_DrawArc(80, 210, 20, 20, 0, 180);
    GUI_DrawArc(80, 210, 30, 30, 0, 180);
    GUI_DrawArc(80, 210, 40, 40, 0, 180);
    GUI_DrawArc(80, 210, 50, 50, 0, 180);
    GUI_DrawArc(80, 210, 60, 60, 0, 180);

    /* Rounded rectangle */
    GUI_FillRoundedRect(180, 150, 300, 210, 5);
}


/*******************************************************************************
* Function Name: void show_2d_graphics2(void)
********************************************************************************
*
* Summary: This function displays the following 2D graphics
*           1. Concentric circles
*           2. Concentric ellipses
*           3. Filled rectangle with horizontal color gradient
*           4. Filled rectangle with vertical color gradient
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_2d_graphics2(void)
{
    /* Set font size, foreground and background colors */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Clear the screen */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_DispStringAt("7 OF 9: 2D GRAPHICS - 2", 160, 10);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Set drawing color to gray */
    GUI_SetColor(GUI_GRAY);

    /* Display labels */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("CIRCLE", 80, 110);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("ELLIPSE", 240, 110);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("RECT-HGRAD", 80, 220);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("RECT-VGRAD", 240, 220);

    /* Concentric Circles */
    GUI_DrawCircle(80, 65, 35);
    GUI_DrawCircle(80, 65, 25);
    GUI_DrawCircle(80, 65, 15);
    GUI_DrawCircle(80, 65, 5);

    /* Concentric Ellipses */
    GUI_DrawEllipse(240, 65, 60, 35);
    GUI_DrawEllipse(240, 65, 50, 25);
    GUI_DrawEllipse(240, 65, 40, 15);
    GUI_DrawEllipse(240, 65, 30, 5);

    /* Rectangle horizontal gradient */
    GUI_DrawGradientH(20, 150, 140, 210, GUI_BLACK, GUI_GREEN);

    /* Rectangle vertical gradient */
    GUI_DrawGradientV(180, 150, 300, 210, GUI_RED, GUI_BLACK);
}


/*******************************************************************************
* Function Name: void show_concentric_circles(void)
********************************************************************************
*
* Summary: This function displays a short animation by drawing concentric circles
*           with color gradients
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_concentric_circles(void)
{
    #define NUMBER_OF_COLORS    (3u)
    #define MAX_RADIUS          (100u)

    uint16 radius = 0;
    uint16 colorIndex = 0;

    const uint32 colorArray[NUMBER_OF_COLORS] =
    {
        GUI_RED,
        GUI_BLUE,
        GUI_GREEN,
    };

    /* Set font size, background color and text mode */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);

    /* Clear the display */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringAt("8 OF 9: CONCENTRIC CIRCLES", 160, 10);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Draw concentric circles with color gradient */
    /* Cycle through number of colors */
    for(colorIndex = 0; colorIndex < NUMBER_OF_COLORS; colorIndex++)
    {
        /* Draw circles with increasing radius */
        for(radius = 0; radius < MAX_RADIUS; radius++)
        {
            GUI_SetColor(radius*colorArray[colorIndex]);
            GUI_DrawCircle(160, 130, radius);
            vTaskDelay(2);
        }
    }
}


/*******************************************************************************
* Function Name: void show_bitmap(void)
********************************************************************************
*
* Summary: This function displays a bitmap image with an overlay text
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void show_bitmap(void)
{
    /* Set background color to black and clear screen */
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();

    /* Display the bitmap image on the screen */
    GUI_DrawBitmap(&bmKS1241172, 0, 4);

    /* Set font size, font color to black */
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_SetColor(GUI_BLACK);

    /* Set text mode to transparent, underlined and center aligned */
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_SetTextStyle(GUI_TS_UNDERLINE);

    /* Print the page title text */
    GUI_DispStringAt("9 OF 9: BITMAP IMAGE", 160, 10);
}

/* END OF FILE */
