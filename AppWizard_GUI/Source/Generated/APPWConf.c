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
File        : APPWConf.c
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#include "AppWizard.h"
#include "Resource.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define XSIZE_PHYS 320
#define YSIZE_PHYS 240
#define COLOR_CONVERSION GUICC_8666
#define DISPLAY_DRIVER GUIDRV_WIN32
#define NUM_BUFFERS   2

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
*       _apRootList
*/
static APPW_ROOT_INFO * _apRootList[] = {
  &ID_SCREEN_00_RootInfo,
  &ID_SCREEN_01_RootInfo,
  &ID_SCREEN_02_RootInfo,
  &ID_SCREEN_03_RootInfo,
  &ID_SCREEN_04_RootInfo,
  &ID_SCREEN_05_RootInfo,
  &ID_SCREEN_06_RootInfo,
  &ID_SCREEN_07_RootInfo,
  &ID_SCREEN_08_RootInfo,
  &ID_SCREEN_09_RootInfo,
  &ID_SCREEN_10_RootInfo,
};

/*********************************************************************
*
*       _NumScreens
*/
static unsigned _NumScreens = GUI_COUNTOF(_apRootList);

/*********************************************************************
*
*       _aVarList
*/
static APPW_VAR_OBJECT _aVarList[] = {
  { ID_VAR_00, 0, 0, NULL },
};

/*********************************************************************
*
*       _NumVars
*/
static unsigned _NumVars = GUI_COUNTOF(_aVarList);

/*********************************************************************
*
*       _aID_ANIM_000_Items
*/
static const APPW_ANIM_ITEM _aID_ANIM_000_Items[] = {
  { ANIM_LINEAR,
    { 0x0000, 0x7fff },
    { { 0x00000000, 0, ATOM_CONSTANT, 0 },
      { 0x00000064, 0, ATOM_CONSTANT, 0 },
      { 0x00001000, 0, ATOM_VARIABLE, 0 }
    }
  }
};

/*********************************************************************
*
*       ID_ANIM_000_Data
*/
const APPW_ANIM_DATA ID_ANIM_000_Data = { ID_ANIM_000, 1000, 1, 1, GUI_COUNTOF(_aID_ANIM_000_Items), _aID_ANIM_000_Items };

/*********************************************************************
*
*       ID_DRAW_001
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_21, 5) {
  APPW_ID_FILL_ROUNDED_RECT,
  (const APPW_DRAWING_ITEM *)NULL,
  { { 0x000000b4, 0, ATOM_CONSTANT, 0 },
    { 0x00000096, 0, ATOM_CONSTANT, 0 },
    { 0x0000012c, 0, ATOM_CONSTANT, 0 },
    { 0x000000d2, 0, ATOM_CONSTANT, 0 },
    { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_20, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_21,
  { { 0x0000010e, 0, ATOM_CONSTANT, 0 },
    { 0x0000001e, 0, ATOM_CONSTANT, 0 },
    { 0x0000010e, 0, ATOM_CONSTANT, 0 },
    { 0x00000064, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_19, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_20,
  { { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_18, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_19,
  { { 0x000000ff, 0, ATOM_CONSTANT, 0 },
    { 0x0000001e, 0, ATOM_CONSTANT, 0 },
    { 0x000000ff, 0, ATOM_CONSTANT, 0 },
    { 0x00000064, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_17, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_18,
  { { 0x00000004, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_16, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_17,
  { { 0x000000f0, 0, ATOM_CONSTANT, 0 },
    { 0x0000001e, 0, ATOM_CONSTANT, 0 },
    { 0x000000f0, 0, ATOM_CONSTANT, 0 },
    { 0x00000064, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_15, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_16,
  { { 0x00000003, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_14, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_15,
  { { 0x000000e1, 0, ATOM_CONSTANT, 0 },
    { 0x0000001e, 0, ATOM_CONSTANT, 0 },
    { 0x000000e1, 0, ATOM_CONSTANT, 0 },
    { 0x00000064, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_13, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_14,
  { { 0x00000002, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_12, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_13,
  { { 0x000000d2, 0, ATOM_CONSTANT, 0 },
    { 0x0000001e, 0, ATOM_CONSTANT, 0 },
    { 0x000000d2, 0, ATOM_CONSTANT, 0 },
    { 0x00000064, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_11, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_12,
  { { 0x00000001, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_10, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_11,
  { { 0x0000000a, 0, ATOM_CONSTANT, 0 },
    { 0x0000005f, 0, ATOM_CONSTANT, 0 },
    { 0x00000096, 0, ATOM_CONSTANT, 0 },
    { 0x0000005f, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_9, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_10,
  { { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_8, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_9,
  { { 0x0000000a, 0, ATOM_CONSTANT, 0 },
    { 0x00000050, 0, ATOM_CONSTANT, 0 },
    { 0x00000096, 0, ATOM_CONSTANT, 0 },
    { 0x00000050, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_7, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_8,
  { { 0x00000004, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_6, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_7,
  { { 0x0000000a, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x00000096, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_5, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_6,
  { { 0x00000003, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_4, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_5,
  { { 0x0000000a, 0, ATOM_CONSTANT, 0 },
    { 0x00000032, 0, ATOM_CONSTANT, 0 },
    { 0x00000096, 0, ATOM_CONSTANT, 0 },
    { 0x00000032, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_3, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_4,
  { { 0x00000002, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_2, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_3,
  { { 0x0000000a, 0, ATOM_CONSTANT, 0 },
    { 0x00000023, 0, ATOM_CONSTANT, 0 },
    { 0x00000096, 0, ATOM_CONSTANT, 0 },
    { 0x00000023, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_1, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_2,
  { { 0x00000001, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_0, 1) {
  APPW_ID_SET_COLOR,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_1,
  { { 0x00808080, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       ID_DRAW_002
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_9, 6) {
  APPW_ID_DRAW_GRADIENT_V,
  (const APPW_DRAWING_ITEM *)NULL,
  { { 0x000000b4, 0, ATOM_CONSTANT, 0 },
    { 0x00000096, 0, ATOM_CONSTANT, 0 },
    { 0x0000012c, 0, ATOM_CONSTANT, 0 },
    { 0x000000d2, 0, ATOM_CONSTANT, 0 },
    { 0x000000ff, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_8, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_9,
  { { 0x00000014, 0, ATOM_CONSTANT, 0 },
    { 0x00000096, 0, ATOM_CONSTANT, 0 },
    { 0x0000008c, 0, ATOM_CONSTANT, 0 },
    { 0x000000d2, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00ff0000, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_7, 4) {
  APPW_ID_DRAW_ELLIPSE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_8,
  { { 0x000000f0, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x0000001e, 0, ATOM_CONSTANT, 0 },
    { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_6, 4) {
  APPW_ID_DRAW_ELLIPSE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_7,
  { { 0x000000f0, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x00000028, 0, ATOM_CONSTANT, 0 },
    { 0x0000000f, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_5, 4) {
  APPW_ID_DRAW_ELLIPSE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_6,
  { { 0x000000f0, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x00000032, 0, ATOM_CONSTANT, 0 },
    { 0x00000019, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_4, 4) {
  APPW_ID_DRAW_ELLIPSE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_5,
  { { 0x000000f0, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000023, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_3, 3) {
  APPW_ID_DRAW_CIRCLE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_4,
  { { 0x00000050, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_2, 3) {
  APPW_ID_DRAW_CIRCLE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_3,
  { { 0x00000050, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x0000000f, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_1, 3) {
  APPW_ID_DRAW_CIRCLE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_2,
  { { 0x00000050, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x00000019, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_0, 3) {
  APPW_ID_DRAW_CIRCLE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_1,
  { { 0x00000050, 0, ATOM_CONSTANT, 0 },
    { 0x00000041, 0, ATOM_CONSTANT, 0 },
    { 0x00000023, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       ID_DRAW_003
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_003_Item_3, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)NULL,
  { { 0x0000013f, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x0000004f, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_003_Item_2, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_003_Item_3,
  { { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x0000013f, 0, ATOM_CONSTANT, 0 },
    { 0x0000004f, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_003_Item_1, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_003_Item_2,
  { { 0x00000003, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_003_Item_0, 1) {
  APPW_ID_SET_COLOR,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_003_Item_1,
  { { 0x000000ff, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       ID_DRAW_000
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_11, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)NULL,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x000000cd, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x000000dc, 0, ATOM_CONSTANT, 0 },
    { 0x00ff00ff, 0, ATOM_CONSTANT, 0 },
    { 0x00ffffff, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_10, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_11,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x000000be, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x000000cc, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00ff00ff, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_9, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_10,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000091, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x0000009f, 0, ATOM_CONSTANT, 0 },
    { 0x00ffff00, 0, ATOM_CONSTANT, 0 },
    { 0x00ffffff, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_8, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_9,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000082, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x00000090, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00ffff00, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_7, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_8,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x000000af, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x000000bd, 0, ATOM_CONSTANT, 0 },
    { 0x0000ffff, 0, ATOM_CONSTANT, 0 },
    { 0x00ffffff, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_6, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_7,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x000000a0, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x000000ae, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x0000ffff, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_5, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_6,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000037, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x00000045, 0, ATOM_CONSTANT, 0 },
    { 0x00ff0000, 0, ATOM_CONSTANT, 0 },
    { 0x00ffffff, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_4, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_5,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000028, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x00000036, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00ff0000, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_3, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_4,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000055, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x00000063, 0, ATOM_CONSTANT, 0 },
    { 0x0000ff00, 0, ATOM_CONSTANT, 0 },
    { 0x00ffffff, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_2, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_3,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000046, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x00000054, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x0000ff00, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_1, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_2,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000073, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x00000081, 0, ATOM_CONSTANT, 0 },
    { 0x000000ff, 0, ATOM_CONSTANT, 0 },
    { 0x00ffffff, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_0, 6) {
  APPW_ID_DRAW_GRADIENT_H,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_1,
  { { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000064, 0, ATOM_CONSTANT, 0 },
    { 0x00000140, 0, ATOM_CONSTANT, 0 },
    { 0x00000072, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x000000ff, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       ID_DRAW_004
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_004_Item_0, 3) {
  APPW_ID_FILL_CIRCLE,
  (const APPW_DRAWING_ITEM *)NULL,
  { { 0x000000a0, 0, ATOM_CONSTANT, 0 },
    { 0x00000082, 0, ATOM_CONSTANT, 0 },
    { 0x00000064, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       ID_DRAW_005
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_005_Item_4, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)NULL,
  { { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000094, 0, ATOM_CONSTANT, 0 },
    { 0x000000d2, 0, ATOM_CONSTANT, 0 },
    { 0x00000094, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_005_Item_3, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_005_Item_4,
  { { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000077, 0, ATOM_CONSTANT, 0 },
    { 0x000000a0, 0, ATOM_CONSTANT, 0 },
    { 0x00000077, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_005_Item_2, 4) {
  APPW_ID_DRAW_LINE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_005_Item_3,
  { { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000074, 0, ATOM_CONSTANT, 0 },
    { 0x000000aa, 0, ATOM_CONSTANT, 0 },
    { 0x00000074, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_005_Item_1, 1) {
  APPW_ID_SET_PENSIZE,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_005_Item_2,
  { { 0x00000002, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_005_Item_0, 1) {
  APPW_ID_SET_COLOR,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_005_Item_1,
  { { 0x00ffffff, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       _appDrawing
*/
static const APPW_DRAWING_ITEM * _appDrawing[] = {
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_0,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_0,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_003_Item_0,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_0,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_004_Item_0,
  (const APPW_DRAWING_ITEM *)&_aID_DRAW_005_Item_0
};

/*********************************************************************
*
*       _NumDrawings
*/
static unsigned _NumDrawings = GUI_COUNTOF(_appDrawing);

/*********************************************************************
*
*       Multibuffering
*/
static U8 _MultibufEnable = 0;

/*********************************************************************
*
*       _ShowMissingCharacters
*/
static U8 _ShowMissingCharacters = 0;

/*********************************************************************
*
*       _apLang
*/
static const char * _apLang[] = {
  (const char *)acAPPW_Language_0,
};

/*********************************************************************
*
*       _TextInit
*/
static const APPW_TEXT_INIT _TextInit = {
  _apLang,
  GUI_COUNTOF(_apLang),
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _InitText
*/
static void _InitText(void) {
  APPW_TextInitMem(&_TextInit);
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       APPW_X_Setup
*/
void APPW_X_Setup(void) {
  APPW_SetpfInitText(_InitText);
  APPW_X_FS_Init();
  APPW_MULTIBUF_Enable(_MultibufEnable);
  APPW_SetData(_apRootList, _NumScreens, _aVarList, _NumVars, (APPW_DRAWING_ITEM **)_appDrawing, _NumDrawings);
  GUI_ShowMissingCharacters(_ShowMissingCharacters);
}

/*********************************************************************
*
*       APPW_X_Config
*/
#ifdef WIN32
void APPW_X_Config(void) {
  GUI_MULTIBUF_Config(NUM_BUFFERS);
  GUI_DEVICE_CreateAndLink(DISPLAY_DRIVER, COLOR_CONVERSION, 0, 0);
  if (LCD_GetSwapXY()) {
    LCD_SetSizeEx (0, YSIZE_PHYS, XSIZE_PHYS);
    LCD_SetVSizeEx(0, YSIZE_PHYS, XSIZE_PHYS);
  } else {
    LCD_SetSizeEx (0, XSIZE_PHYS, YSIZE_PHYS);
    LCD_SetVSizeEx(0, XSIZE_PHYS, YSIZE_PHYS);
  }
}
#endif

/*************************** End of file ****************************/
