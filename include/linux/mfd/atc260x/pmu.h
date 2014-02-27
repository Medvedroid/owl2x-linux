/*
 * Copyright 2011 Actions Semi Inc.
 * Author: Actions Semi, Inc.
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 */

#ifndef __MFD_ATC260X_PMU_H__
#define __MFD_ATC260X_PMU_H__

#include <linux/mfd/atc260x/reg.h>

#define PSY_NAME_WALL  "atc260x-wall"
#define PSY_NAME_USB   "atc260x-usb"

/**
 * R0 (0x00) - PMU System Control 0
 */
#define ATC260X_USB_WK_EN                       0x8000  /* USB_WK */
#define ATC260X_USB_WK_EN_MASK                  0x8000  /* USB_WK */
#define ATC260X_USB_WK_EN_SHIFT                     15  /* USB_WK */
#define ATC260X_USB_WK_EN_WIDTH                      1  /* USB_WK */
#define ATC260X_WALL_WK_EN                      0x4000  /* WALL_WK */
#define ATC260X_WALL_WK_EN_MASK                 0x4000  /* WALL_WK */
#define ATC260X_WALL_WK_EN_SHIFT                    14  /* WALL_WK */
#define ATC260X_WALL_WK_EN_WIDTH                     1  /* WALL_WK */
#define ATC260X_ONOFF_LONG_WK_EN                0x2000  /* ONOFF_LONG_WK */
#define ATC260X_ONOFF_LONG_WK_EN_MASK           0x2000  /* ONOFF_LONG_WK */
#define ATC260X_ONOFF_LONG_WK_EN_SHIFT              13  /* ONOFF_LONG_WK */
#define ATC260X_ONOFF_LONG_WK_EN_WIDTH               1  /* ONOFF_LONG_WK */
#define ATC260X_ONOFF_SHORT_WK_EN               0x1000  /* ONOFF_SHORT_WK */
#define ATC260X_ONOFF_SHORT_WK_EN_MASK          0x1000  /* ONOFF_SHORT_WK */
#define ATC260X_ONOFF_SHORT_WK_EN_SHIFT             12  /* ONOFF_SHORT_WK */
#define ATC260X_ONOFF_SHORT_WK_EN_WIDTH              1  /* ONOFF_SHORT_WK */
#define ATC260X_WKIRQ_WK_EN                     0x0800  /* WKIRQ_WK */
#define ATC260X_WKIRQ_WK_EN_MASK                0x0800  /* WKIRQ_WK */
#define ATC260X_WKIRQ_WK_EN_SHIFT                   11  /* WKIRQ_WK */
#define ATC260X_WKIRQ_WK_EN_WIDTH                    1  /* WKIRQ_WK */
#define ATC260X_TP_WK_EN                        0x0400  /* TP_WK */
#define ATC260X_TP_WK_EN_MASK                   0x0400  /* TP_WK */
#define ATC260X_TP_WK_EN_SHIFT                      10  /* TP_WK */
#define ATC260X_TP_WK_EN_WIDTH                       1  /* TP_WK */
#define ATC260X_REM_CON_WK_EN                   0x0200  /* REM_CON_WK */
#define ATC260X_REM_CON_WK_EN_MASK              0x0200  /* REM_CON_WK */
#define ATC260X_REM_CON_WK_EN_SHIFT                  9  /* REM_CON_WK */
#define ATC260X_REM_CON_WK_EN_WIDTH                  1  /* REM_CON_WK */
#define ATC260X_ALARM_WK_EN                     0x0100  /* ALARM_WK */
#define ATC260X_ALARM_WK_EN_MASK                0x0100  /* ALARM_WK */
#define ATC260X_ALARM_WK_EN_SHIFT                    8  /* ALARM_WK */
#define ATC260X_ALARM_WK_EN_WIDTH                    1  /* ALARM_WK */
#define ATC260X_HDSW_WK_EN                      0x0080  /* HDSW_WK(Hard Switch) */
#define ATC260X_HDSW_WK_EN_MASK                 0x0080  /* HDSW_WK(Hard Switch) */
#define ATC260X_HDSW_WK_EN_SHIFT                     7  /* HDSW_WK(Hard Switch) */
#define ATC260X_HDSW_WK_EN_WIDTH                     1  /* HDSW_WK(Hard Switch) */
#define ATC260X_RESET_WK_EN                     0x0040  /* RESET_WK */
#define ATC260X_RESET_WK_EN_MASK                0x0040  /* RESET_WK */
#define ATC260X_RESET_WK_EN_SHIFT                    6  /* RESET_WK */
#define ATC260X_RESET_WK_EN_WIDTH                    1  /* RESET_WK */
#define ATC260X_IR_WK_EN                        0x0020  /* IR_WK */
#define ATC260X_IR_WK_EN_MASK                   0x0020  /* IR_WK */
#define ATC260X_IR_WK_EN_SHIFT                       5  /* IR_WK */
#define ATC260X_IR_WK_EN_WIDTH                       1  /* IR_WK */
#define ATC260X_VBUS_WK_TH                      0x0018  /* VBUS_WK_TH - [4:3] */
#define ATC260X_VBUS_WK_TH_MASK                 0x0018  /* VBUS_WK_TH - [4:3] */
#define ATC260X_VBUS_WK_TH_SHIFT                     3  /* VBUS_WK_TH - [4:3] */
#define ATC260X_VBUS_WK_TH_WIDTH                     2  /* VBUS_WK_TH - [4:3] */
#define ATC260X_WALL_WK_TH                      0X0006  /* WALL_WK_TH - [2:1] */
#define ATC260X_WALL_WK_TH_MASK                 0X0006  /* WALL_WK_TH - [2:1] */
#define ATC260X_WALL_WK_TH_SHIFT                     1  /* WALL_WK_TH - [2:1] */
#define ATC260X_WALL_WK_TH_WIDTH                     2  /* WALL_WK_TH - [2:1] */
#define ATC260X_ONOFF_MUXKEY_EN                 0X0001  /* ONOFF_MUXKEY */
#define ATC260X_ONOFF_MUXKEY_EN_MASK            0X0001  /* ONOFF_MUXKEY */
#define ATC260X_ONOFF_MUXKEY_EN_SHIFT                0  /* ONOFF_MUXKEY */
#define ATC260X_ONOFF_MUXKEY_EN_WIDTH                1  /* ONOFF_MUXKEY */

/**
 * R1 (0x01) - PMU System Control 1
 */
#define ATC260X_USB_WK_EN                       0x8000  /* USB_WK */
#define ATC260X_USB_WK_EN_MASK                  0x8000  /* USB_WK */
#define ATC260X_USB_WK_EN_SHIFT                     15  /* USB_WK */
#define ATC260X_USB_WK_EN_WIDTH                      1  /* USB_WK */
#define ATC260X_WALL_WK_EN                      0x4000  /* WALL_WK */
#define ATC260X_WALL_WK_EN_MASK                 0x4000  /* WALL_WK */
#define ATC260X_WALL_WK_EN_SHIFT                    14  /* WALL_WK */
#define ATC260X_WALL_WK_EN_WIDTH                     1  /* WALL_WK */
#define ATC260X_ONOFF_LONG_WK_EN                0x2000  /* ONOFF_LONG_WK */
#define ATC260X_ONOFF_LONG_WK_EN_MASK           0x2000  /* ONOFF_LONG_WK */
#define ATC260X_ONOFF_LONG_WK_EN_SHIFT              13  /* ONOFF_LONG_WK */
#define ATC260X_ONOFF_LONG_WK_EN_WIDTH               1  /* ONOFF_LONG_WK */
#define ATC260X_ONOFF_SHORT_WK_EN               0x1000  /* ONOFF_SHORT_WK */
#define ATC260X_ONOFF_SHORT_WK_EN_MASK          0x1000  /* ONOFF_SHORT_WK */
#define ATC260X_ONOFF_SHORT_WK_EN_SHIFT             12  /* ONOFF_SHORT_WK */
#define ATC260X_ONOFF_SHORT_WK_EN_WIDTH              1  /* ONOFF_SHORT_WK */
#define ATC260X_WKIRQ_WK_EN                     0x0800  /* WKIRQ_WK */
#define ATC260X_WKIRQ_WK_EN_MASK                0x0800  /* WKIRQ_WK */
#define ATC260X_WKIRQ_WK_EN_SHIFT                   11  /* WKIRQ_WK */
#define ATC260X_WKIRQ_WK_EN_WIDTH                    1  /* WKIRQ_WK */
#define ATC260X_TP_WK_EN                        0x0400  /* TP_WK */
#define ATC260X_TP_WK_EN_MASK                   0x0400  /* TP_WK */
#define ATC260X_TP_WK_EN_SHIFT                      10  /* TP_WK */
#define ATC260X_TP_WK_EN_WIDTH                       1  /* TP_WK */
#define ATC260X_REM_CON_WK_EN                   0x0200  /* REM_CON_WK */
#define ATC260X_REM_CON_WK_EN_MASK              0x0200  /* REM_CON_WK */
#define ATC260X_REM_CON_WK_EN_SHIFT                  9  /* REM_CON_WK */
#define ATC260X_REM_CON_WK_EN_WIDTH                  1  /* REM_CON_WK */
#define ATC260X_ALARM_WK_EN                     0x0100  /* ALARM_WK */
#define ATC260X_ALARM_WK_EN_MASK                0x0100  /* ALARM_WK */
#define ATC260X_ALARM_WK_EN_SHIFT                    8  /* ALARM_WK */
#define ATC260X_ALARM_WK_EN_WIDTH                    1  /* ALARM_WK */
#define ATC260X_HDSW_WK_EN                      0x0080  /* HDSW_WK(Hard Switch) */
#define ATC260X_HDSW_WK_EN_MASK                 0x0080  /* HDSW_WK(Hard Switch) */
#define ATC260X_HDSW_WK_EN_SHIFT                     7  /* HDSW_WK(Hard Switch) */
#define ATC260X_HDSW_WK_EN_WIDTH                     1  /* HDSW_WK(Hard Switch) */
#define ATC260X_RESET_WK_EN                     0x0040  /* RESET_WK */
#define ATC260X_RESET_WK_EN_MASK                0x0040  /* RESET_WK */
#define ATC260X_RESET_WK_EN_SHIFT                    6  /* RESET_WK */
#define ATC260X_RESET_WK_EN_WIDTH                    1  /* RESET_WK */
#define ATC260X_IR_WK_EN                        0x0020  /* IR_WK */
#define ATC260X_IR_WK_EN_MASK                   0x0020  /* IR_WK */
#define ATC260X_IR_WK_EN_SHIFT                       5  /* IR_WK */
#define ATC260X_IR_WK_EN_WIDTH                       1  /* IR_WK */
#define ATC260X_LB_S4                           0x0018  /* LB_S4 - [4:3] (Low power S4 Voltage) */
#define ATC260X_LB_S4_MASK                      0x0018  /* LB_S4 - [4:3] (Low power S4 Voltage) */
#define ATC260X_LB_S4_SHIFT                          3  /* LB_S4 - [4:3] (Low power S4 Voltage) */
#define ATC260X_LB_S4_WIDTH                          2  /* LB_S4 - [4:3] (Low power S4 Voltage) */
#define ATC260X_LB_S4_EN                        0x0004  /* LB_S4_EN (Enable S4 detection) */
#define ATC260X_LB_S4_EN_MASK                   0x0004  /* LB_S4_EN (Enable S4 detection) */
#define ATC260X_LB_S4_EN_SHIFT                       2  /* LB_S4_EN (Enable S4 detection) */
#define ATC260X_LB_S4_EN_WIDTH                       1  /* LB_S4_EN (Enable S4 detection) */
#define ATC260X_ENRTCOSC                        0x0002  /* ENRTCOSC (Enable 32k internal clock) */
#define ATC260X_ENRTCOSC_MASK                   0x0002  /* ENRTCOSC (Enable 32k internal clock) */
#define ATC260X_ENRTCOSC_SHIFT                       1  /* ENRTCOSC (Enable 32k internal clock) */
#define ATC260X_ENRTCOSC_WIDTH                       1  /* ENRTCOSC (Enable 32k internal clock) */
#define ATC260X_EN_S1                           0x0001  /* EN_S1 */
#define ATC260X_EN_S1_MASK                      0x0001  /* EN_S1 */
#define ATC260X_EN_S1_SHIFT                          0  /* EN_S1 */
#define ATC260X_EN_S1_WIDTH                          1  /* EN_S1 */

/**
 * R2 (0x02) - PMU System Control 2
 */
#define ATC260X_ONOFF_PRESS                     0x8000  /* ONOFF_PRESS */
#define ATC260X_ONOFF_PRESS_MASK                0x8000  /* ONOFF_PRESS */
#define ATC260X_ONOFF_PRESS_SHIFT                   15  /* ONOFF_PRESS */
#define ATC260X_ONOFF_PRESS_WIDTH                    1  /* ONOFF_PRESS */
#define ATC260X_ONOFF_SHORT_PRESS               0x4000  /* ONOFF_SHORT_PRESS */
#define ATC260X_ONOFF_SHORT_PRESS_MASK          0x4000  /* ONOFF_SHORT_PRESS */
#define ATC260X_ONOFF_SHORT_PRESS_SHIFT             14  /* ONOFF_SHORT_PRESS */
#define ATC260X_ONOFF_SHORT_PRESS_WIDTH              1  /* ONOFF_SHORT_PRESS */
#define ATC260X_ONOFF_LONG_PRESS                0x2000  /* ONOFF_LONG_PRESS */
#define ATC260X_ONOFF_LONG_PRESS_MASK           0x2000  /* ONOFF_LONG_PRESS */
#define ATC260X_ONOFF_LONG_PRESS_SHIFT              13  /* ONOFF_LONG_PRESS */
#define ATC260X_ONOFF_LONG_PRESS_WIDTH               1  /* ONOFF_LONG_PRESS */
#define ATC260X_ONOFF_INT_EN                    0x1000  /* ONOFF_INT_EN */
#define ATC260X_ONOFF_INT_EN_MASK               0x1000  /* ONOFF_INT_EN */
#define ATC260X_ONOFF_INT_EN_SHIFT                  12  /* ONOFF_INT_EN */
#define ATC260X_ONOFF_INT_EN_WIDTH                   1  /* ONOFF_INT_EN */
#define ATC260X_ONOFF_PRESS_TIME                0x0C00  /* ONOFF_PRESS_TIME - [11:10] */
#define ATC260X_ONOFF_PRESS_TIME_MASK           0x0C00  /* ONOFF_PRESS_TIME - [11:10] */
#define ATC260X_ONOFF_PRESS_TIME_SHIFT              10  /* ONOFF_PRESS_TIME - [11:10] */
#define ATC260X_ONOFF_PRESS_TIME_WIDTH               2  /* ONOFF_PRESS_TIME - [11:10] */
#define ATC260X_ONOFF_RESET_EN                  0x0200  /* ONOFF_RESET_EN */
#define ATC260X_ONOFF_RESET_EN_MASK             0x0200  /* ONOFF_RESET_EN */
#define ATC260X_ONOFF_RESET_EN_SHIFT                 9  /* ONOFF_RESET_EN */
#define ATC260X_ONOFF_RESET_EN_WIDTH                 1  /* ONOFF_RESET_EN */
#define ATC260X_ONOFF_RESET_TIME_SEL            0x0180  /* ONOFF_RESET_TIME_SEL - [8:7] */
#define ATC260X_ONOFF_RESET_TIME_SEL_MASK       0x0180  /* ONOFF_RESET_TIME_SEL - [8:7] */
#define ATC260X_ONOFF_RESET_TIME_SEL_SHIFT           7  /* ONOFF_RESET_TIME_SEL - [8:7] */
#define ATC260X_ONOFF_RESET_TIME_SEL_WIDTH           2  /* ONOFF_RESET_TIME_SEL - [8:7] */

#define ATC260X_S2_TIMER_EN                     0x0040  /* S2_TIMER_EN */
#define ATC260X_S2_TIMER_EN_MASK                0x0040  /* S2_TIMER_EN */
#define ATC260X_S2_TIMER_EN_SHIFT                    6  /* S2_TIMER_EN */
#define ATC260X_S2_TIMER_EN_WIDTH                    1  /* S2_TIMER_EN */
#define ATC260X_S2TIMER                         0x0038  /* S2TIMER - [5:3] */
#define ATC260X_S2TIMER_MASK                    0x0038  /* S2TIMER - [5:3] */
#define ATC260X_S2TIMER_SHIFT                        3  /* S2TIMER - [5:3] */
#define ATC260X_S2TIMER_WIDTH                        3  /* S2TIMER - [5:3] */
/* These are reserved and their use is unknown */
#define ATC260X_RESERVED                        0x0007  /* RESERVED - [2:0] */
#define ATC260X_RESERVED_MASK                   0x0007  /* RESERVED - [2:0] */
#define ATC260X_RESERVED_SHIFT                       0  /* RESERVED - [2:0] */
#define ATC260X_RESERVED_WIDTH                       3  /* RESERVED - [2:0] */

/**
 * R3 (0x03) - PMU System Control 3
 */
#define ATC260X_EN_S2                           0x8000  /* EN_S2 */
#define ATC260X_EN_S2_MASK                      0x8000  /* EN_S2 */
#define ATC260X_EN_S2_SHIFT                         15  /* EN_S2 */
#define ATC260X_EN_S2_WIDTH                          1  /* EN_S2 */
#define ATC260X_EN_S3                           0x4000  /* EN_S3 */
#define ATC260X_EN_S3_MASK                      0x4000  /* EN_S3 */
#define ATC260X_EN_S3_SHIFT                         14  /* EN_S3 */
#define ATC260X_EN_S3_WIDTH                          1  /* EN_S3 */
#define ATC260X_S3_TIMER_EN                     0x2000  /* S3_TIMER_EN */
#define ATC260X_S3_TIMER_EN_MASK                0x2000  /* S3_TIMER_EN */
#define ATC260X_S3_TIMER_EN_SHIFT                   13  /* S3_TIMER_EN */
#define ATC260X_S3_TIMER_EN_WIDTH                    1  /* S3_TIMER_EN */
#define ATC260X_S3TIMER                         0x1C00  /* S3TIMER - [12:10] */
#define ATC260X_S3TIMER_MASK                    0x1C00  /* S3TIMER - [12:10] */
#define ATC260X_S3TIMER_SHIFT                       10  /* S3TIMER - [12:10] */
#define ATC260X_S3TIMER_WIDTH                        3  /* S3TIMER - [12:10] */
/* RESERVED has unknown use */
#define ATC260X_RESERVED                        0x03F0  /* RESERVED - [9:4] */
#define ATC260X_RESERVED_MASK                   0x03F0  /* RESERVED - [9:4] */
#define ATC260X_RESERVED_SHIFT                       4  /* RESERVED - [9:4] */
#define ATC260X_RESERVED_WIDTH                       6  /* RESERVED - [9:4] */
#define ATC260X_IR_PIN_TYPE                     0x0008  /* IR_PIN_TYPE */
#define ATC260X_IR_PIN_TYPE_MASK                0x0008  /* IR_PIN_TYPE */
#define ATC260X_IR_PIN_TYPE_SHIFT                    3  /* IR_PIN_TYPE */
#define ATC260X_IR_PIN_TYPE_WIDTH                    1  /* IR_PIN_TYPE */
#define ATC260X_IR_GPIO_OUTPUT_EN               0x0004  /* IR_GPIO_OUTPUT_EN */
#define ATC260X_IR_GPIO_OUTPUT_EN_MASK          0x0004  /* IR_GPIO_OUTPUT_EN */
#define ATC260X_IR_GPIO_OUTPUT_EN_SHIFT              2  /* IR_GPIO_OUTPUT_EN */
#define ATC260X_IR_GPIO_OUTPUT_EN_WIDTH              1  /* IR_GPIO_OUTPUT_EN */
#define ATC260X_IR_GPIO_INPUT_EN                0x0002  /* IR_GPIO_INPUT_EN */
#define ATC260X_IR_GPIO_INPUT_EN_MASK           0x0002  /* IR_GPIO_INPUT_EN */
#define ATC260X_IR_GPIO_INPUT_EN_SHIFT               1  /* IR_GPIO_INPUT_EN */
#define ATC260X_IR_GPIO_INPUT_EN_WIDTH               1  /* IR_GPIO_INPUT_EN */
#define ATC260X_IR_GPIO_DATA                    0x0001  /* IR_GPIO_DATA */
#define ATC260X_IR_GPIO_DATA_MASK               0x0001  /* IR_GPIO_DATA */
#define ATC260X_IR_GPIO_DATA_SHIFT                   0  /* IR_GPIO_DATA */
#define ATC260X_IR_GPIO_DATA_WIDTH                   1  /* IR_GPIO_DATA */                              

/**
 * R4 (0x04) - PMU System Control 4
 */
#define ATC260X_WKIRQ_PIN_TYPE                  0x8000  /* WKIRQ_PIN_TYPE */
#define ATC260X_WKIRQ_PIN_TYPE_MASK             0x8000
#define ATC260X_WKIRQ_PIN_TYPE_SHIFT                15
#define ATC260X_WKIRQ_PIN_TYPE_WIDTH                 1
#define ATC260X_WKIRQ_GPIO_OUTPUT_EN            0x4000  /* WKIRQ_GPIO_OUTPUT_EN */
#define ATC260X_WKIRQ_GPIO_OUTPUT_EN_MASK       0x4000
#define ATC260X_WKIRQ_GPIO_OUTPUT_EN_SHIFT          14
#define ATC260X_WKIRQ_GPIO_OUTPUT_EN_WIDTH           1
#define ATC260X_WKIRQ_GPIO_INPUT_EN             0x2000  /* WKIRQ_GPIO_INPUT_EN */
#define ATC260X_WKIRQ_GPIO_INPUT_EN_MASK        0x2000
#define ATC260X_WKIRQ_GPIO_INPUT_EN_SHIFT           13
#define ATC260X_WKIRQ_GPIO_INPUT_EN_WIDTH            1
#define ATC260X_WKIRQ_GPIO_DATA                 0x1000  /* WKIRQ_GPIO_DATA */
#define ATC260X_WKIRQ_GPIO_DATA_MASK            0x1000
#define ATC260X_WKIRQ_GPIO_DATA_SHIFT               12
#define ATC260X_WKIRQ_GPIO_DATA_WIDTH                1
#define ATC260X_WKIRQ_TYPE                      0x0C00  /* WKIRQ_TYPE [11:10] */
#define ATC260X_WKIRQ_TYPE_MASK                 0x0C00
#define ATC260X_WKIRQ_TYPE_SHIFT                    10
#define ATC260X_WKIRQ_TYPE_WIDTH                     2
#define ATC260X_WKIRQ_32K_EN                    0x0200  /* WKIRQ_32K_EN */
#define ATC260X_WKIRQ_32K_EN_MASK               0x0200
#define ATC260X_WKIRQ_32K_EN_SHIFT                   9
#define ATC260X_WKIRQ_32K_EN_WIDTH                   1
#define ATC260X_RESERVED                        0x0100  /* RESERVED */
#define ATC260X_RESERVED_MASK                   0x0100
#define ATC260X_RESERVED_SHIFT                       8
#define ATC260X_RESERVED_WIDTH                       1
#define ATC260X_LOWP_GPIO_OUTPUT_EN             0x0080  /* LOWP_GPIO_OUTPUT_EN */
#define ATC260X_LOWP_GPIO_OUTPUT_EN_MASK        0x0080
#define ATC260X_LOWP_GPIO_OUTPUT_EN_SHIFT            7
#define ATC260X_LOWP_GPIO_OUTPUT_EN_WIDTH            1
#define ATC260X_LOWP_GPIO_INPUT_EN              0x0040  /* LOWP_GPIO_INPUT_EN */
#define ATC260X_LOWP_GPIO_INPUT_EN_MASK         0x0040
#define ATC260X_LOWP_GPIO_INPUT_EN_SHIFT             6
#define ATC260X_LOWP_GPIO_INPUT_EN_WIDTH             1
#define ATC260X_LOWP_GPIO_DATA                  0x0020  /* LOWP_GPIO_DATA */
#define ATC260X_LOWP_GPIO_DATA_MASK             0x0020
#define ATC260X_LOWP_GPIO_DATA_SHIFT                 5
#define ATC260X_LOWP_GPIO_DATA_WIDTH                 1
#define ATC260X_LOWP_32K_EN                     0x0010  /* LOWP_32K_EN */
#define ATC260X_LOWP_32K_EN_MASK                0x0010
#define ATC260X_LOWP_32K_EN_SHIFT                    4
#define ATC260X_LOWP_32K_EN_WIDTH                    1
#define ATC260X_RESERVED                        0x000C  /* RESERVED_EN [3:2] */
#define ATC260X_RESERVED_MASK                   0x000C
#define ATC260X_RESERVED_SHIFT                       2
#define ATC260X_RESERVED_WIDTH                       2
#define ATC260X_WKIRQ_EN                        0x0002  /* WKIRQ_EN */
#define ATC260X_WKIRQ_EN_MASK                   0x0002
#define ATC260X_WKIRQ_EN_SHIFT                       1
#define ATC260X_WKIRQ_EN_WIDTH                       1
#define ATC260X_WKIRQ_PD                        0x0001  /* WKIRQ_PD */
#define ATC260X_WKIRQ_PD_MASK                   0x0001
#define ATC260X_WKIRQ_PD_SHIFT                       0
#define ATC260X_WKIRQ_PD_WIDTH                       1

/**
 * R5 (0x05) - PMU System Control 5
 */
#define ATC260X_RESERVED                        0xF800  /* RESERVED [15:11] */
#define ATC260X_RESERVED_MASK                   0xF800
#define ATC260X_RESERVED_SHIFT                      11
#define ATC260X_RESERVED_WIDTH                       6
#define ATC260X_TP_DECT_EN                      0x0400  /* TP_DECT_EN */
#define ATC260X_TP_DECT_MASK                    0x0400
#define ATC260X_TP_DECT_SHIFT                       10
#define ATC260X_TP_DECT_WIDTH                        1
#define ATC260X_REMCON_DECT_EN                  0x0200  /* REMCON_DECT_EN */
#define ATC260X_REMCON_DECT_EN_MASK             0x0200
#define ATC260X_REMCON_DECT_EN_SHIFT                 9
#define ATC260X_REMCON_DECT_EN_WIDTH                 1
#define ATC260X_VBUSWKDTEN                      0x0100  /* VBUS_WK_DECT_EN */
#define ATC260X_VBUSWKDTEN_MASK                 0x0100
#define ATC260X_VBUSWKDTEN_SHIFT                     8
#define ATC260X_VBUSWKDTEN_WIDTH                     1
#define ATC260X_WALLWKDTEN                      0x0080  /* WALL_WK_DECT_EN */
#define ATC260X_WALLWKDTEN_MASK                 0x0080
#define ATC260X_WALLWKDTEN_SHIFT                     7
#define ATC260X_WALLWKDTEN_WIDTH                     1
#define ATC260X_RESERVED                        0x007F  /* RESERVED [6:0] */
#define ATC260X_RESERVED_MASK                   0x007F
#define ATC260X_RESERVED_SHIFT                       0
#define ATC260X_RESERVED_WIDTH                       7

/**
 * R6:R9 (0x06:0x09) - PMU System Control 6-9
 *
 * PMU SYS CONTROLS R6 THROUGH R9 ARE RESERVED
 */

/**
 * R10 (0x0A) - PMU Battery Control 0
 */
#define ATC260X_BAT_UV_VOL                      0xC000  /* ATC260X_BAT_UV_VOL [15:14] */
#define ATC260X_BAT_UV_VOL_MASK                 0xC000
#define ATC260X_BAT_UV_VOL_SHIFT                    14
#define ATC260X_BAT_UV_VOL_WIDTH                     2
#define ATC260X_BAT_OV_VOL                      0x3000  /* BAT_OV_VOL [13:12] */
#define ATC260X_BAT_OV_VOL_MASK                 0x3000
#define ATC260X_BAT_OV_VOL_SHIFT                    12
#define ATC260X_BAT_OV_VOL_WIDTH                     2
#define ATC260X_BAT_OV_SET                      0x0F00  /* BAT_OC_SET [11:8] */
#define ATC260X_BAT_OV_SET_MASK                 0x0F00
#define ATC260X_BAT_OV_SET_SHIFT                     8
#define ATC260X_BAT_OV_SET_WIDTH                     4
#define ATC260X_BAT_OC_SHUTOFF_SET              0x00C0  /* BAT_OC_SHUTOFF_SET [7:6] */
#define ATC260X_BAT_OC_SHUTOFF_SET_MASK         0x00C0
#define ATC260X_BAT_OC_SHUTOFF_SET_SHIFT             6
#define ATC260X_BAT_OC_SHUTOFF_SET_WIDTH             2
#define ATC260X_BAT_RESERVED                    0X003F  /* RESERVED [5:0] */
#define ATC260X_BAT_RESERVED_MASK               0X003F
#define ATC260X_BAT_RESERVED_SHIFT                   0
#define ATC260X_BAT_RESERVED_WIDTH                   6

/**
 * R11 (0x0B) - PMU Battery Control 1
 */
#define ATC260X_BAT_OC_EN                       0x8000  /* BAT_OC_EN */
#define ATC260X_BAT_OC_EN_MASK                  0x8000
#define ATC260X_BAT_OC_EN_SHIFT                     15
#define ATC260X_BAT_OC_EN_WIDTH                      1
#define ATC260X_BAT_OV_EN                       0x4000  /* BAT_OV_EN */
#define ATC260X_BAT_OV_EN_MASK                  0x4000
#define ATC260X_BAT_OV_EN_SHIFT                     14
#define ATC260X_BAT_OV_EN_WIDTH                      1
#define ATC260X_BAT_UV_EN                       0x2000  /* BAT_UV_EN */
#define ATC260X_BAT_UV_EN_MASK                  0x2000
#define ATC260X_BAT_UV_EN_SHIFT                     13
#define ATC260X_BAT_UV_EN_WIDTH                      1
#define ATC260X_BAT_OC_INT_EN                   0x1000  /* BAT_OC_INT_EN */
#define ATC260X_BAT_OC_INT_EN_MASK              0x1000
#define ATC260X_BAT_OC_INT_EN_SHIFT                 12
#define ATC260X_BAT_OC_INT_EN_WIDTH                  1
#define ATC260X_BAT_OV_INT_EN                   0x0800  /* BAT_OV_INT_EN */
#define ATC260X_BAT_OV_INT_EN_MASK              0x0800
#define ATC260X_BAT_OV_INT_EN_SHIFT                 11
#define ATC260X_BAT_OV_INT_EN_WIDTH                  1
#define ATC260X_BAT_UV_INT_EN                   0x0400  /* BAT_UV_INT_EN */
#define ATC260X_BAT_UV_INT_EN_MASK              0x0400
#define ATC260X_BAT_UV_INT_EN_SHIFT                 10
#define ATC260X_BAT_UV_INT_EN_WIDTH                  1
#define ATC260X_BAT_OC_SHUTOFF_EN               0x0200  /* BAT_OC_SHUTOFF_EN */
#define ATC260X_BAT_OC_SHUTOFF_EN_MASK          0x0200
#define ATC260X_BAT_OC_SHUTOFF_EN_SHIFT              9
#define ATC260X_BAT_OC_SHUTOFF_EN_WIDTH              1
#define ATC260X_BATOVUVOC_RESERVED              0x01FF  /* BATOVUVOC_RESERVED [8:0] */
#define ATC260X_BATOVUVOC_RESERVED_MASK         0x01FF
#define ATC260X_BATOVUVOC_RESERVED_SHIFT             0
#define ATC260X_BATOVUVOC_RESERVED_WIDTH             9

/**
 * R12 (0x0C) - PMU VBUS Control 0
 */
#define ATC260X_VBUS_UV_VOL                     0xC000 /* VBUS_UV_VOL [15:14] */
#define ATC260X_VBUS_UV_VOL_MASK                0xC000
#define ATC260X_VBUS_UV_VOL_SHIFT                   14
#define ATC260X_VBUS_UV_VOL_WIDTH                    2
#define ATC260X_VBUS_OV_VOL                     0x3000 /* VBUS_OV_VOL [13:12] */
#define ATC260X_VBUS_OV_VOL_MASK                0x3000
#define ATC260X_VBUS_OV_VOL_SHIFT                   12
#define ATC260X_VBUS_OV_VOL_WIDTH                    2
#define ATC260X_VBUS_OC_SET                     0x0F00 /* VBUS_OC_SET [11:8] */
#define ATC260X_VBUS_OC_SET_MASK                0x0F00
#define ATC260X_VBUS_OC_SET_SHIFT                    8
#define ATC260X_VBUS_OC_SET_WIDTH                    4
#define ATC260X_VBUS_OC_SHUTOFF_SET             0x00C0 /* VBUS_OC_SHUTOFF_SET [7:6] */
#define ATC260X_VBUS_OC_SHUTOFF_SET_MASK        0x00C0
#define ATC260X_VBUS_OC_SHUTOFF_SET_SHIFT            6
#define ATC260X_VBUS_OC_SHUTOFF_SET_WIDTH            2
#define ATC260X_VBUS_OC_RESERVED                0x003F /* RESERVED [5:0] */
#define ATC260X_VBUS_OC_RESERVED_MASK           0x003F
#define ATC260X_VBUS_OC_RESERVED_SHIFT               0
#define ATC260X_VBUS_OC_RESERVED_WIDTH               6

/**
 * R13 (0x0D) - PMU VBUS Control 1
 */
#define ATC260X_VBUS_OC_EN                      0x8000  /* VBUS_OC_EN */
#define ATC260X_VBUS_OC_EN_MASK                 0x8000
#define ATC260X_VBUS_OC_EN_SHIFT                    15
#define ATC260X_VBUS_OC_EN_WIDTH                     1
#define ATC260X_VBUS_OV_EN                      0x4000  /* VBUS_OV_EN */
#define ATC260X_VBUS_OV_EN_MASK                 0x4000
#define ATC260X_VBUS_OV_EN_SHIFT                    14
#define ATC260X_VBUS_OV_EN_WIDTH                     1
#define ATC260X_VBUS_UV_EN                      0x2000  /* VBUS_UV_EN */
#define ATC260X_VBUS_UV_EN_MASK                 0x2000
#define ATC260X_VBUS_UV_EN_SHIFT                    13
#define ATC260X_VBUS_UV_EN_WIDTH                     1
#define ATC260X_VBUS_OC_INT_EN                  0x1000  /* VBUS_OC_INT_EN */
#define ATC260X_VBUS_OC_INT_EN_MASK             0x1000
#define ATC260X_VBUS_OC_INT_EN_SHIFT                12
#define ATC260X_VBUS_OC_INT_EN_WIDTH                 1
#define ATC260X_VBUS_OV_INT_EN                  0x0800  /* VBUS_OV_INT_EN */
#define ATC260X_VBUS_OV_INT_EN_MASK             0x0800
#define ATC260X_VBUS_OV_INT_EN_SHIFT                11
#define ATC260X_VBUS_OV_INT_EN_WIDTH                 1
#define ATC260X_VBUS_UV_INT_EN                  0x0400  /* VBUS_UV_INT_EN */
#define ATC260X_VBUS_UV_INT_EN_MASK             0x0400
#define ATC260X_VBUS_UV_INT_EN_SHIFT                10
#define ATC260X_VBUS_UV_INT_EN_WIDTH                 1
#define ATC260X_VBUS_OC_SHUTOFF_EN              0x0200  /* VBUS_OC_SHUTOFF_EN */
#define ATC260X_VBUS_OC_SHUTOFF_EN_MASK         0x0200
#define ATC260X_VBUS_OC_SHUTOFF_EN_SHIFT             9
#define ATC260X_VBUS_OC_SHUTOFF_EN_WIDTH             1
#define ATC260X_VBUSOVUVOC_RESERVED             0x01FF  /* VBUSOVUVOC_RESERVED [8:0] */
#define ATC260X_VBUSOVUVOC_RESERVED_MASK        0x01FF
#define ATC260X_VBUSOVUVOC_RESERVED_SHIFT            0
#define ATC260X_VBUSOVUVOC_RESERVED_WIDTH            9

/**
 * R14 (0x0E) - PMU WALL Control 0
 */
#define ATC260X_WALL_UV_VOL                     0xC000  /* WALL_UV_VOL [15:14] */
#define ATC260X_WALL_UV_VOL_MASK                0xC000
#define ATC260X_WALL_UV_VOL_SHIFT                   14
#define ATC260X_WALL_UV_VOL_WIDTH                    2
#define ATC260X_WALL_OV_VOL                     0x3000  /* WALL_OV_VOL [13:12] */
#define ATC260X_WALL_OV_VOL_MASK                0x3000
#define ATC260X_WALL_OV_VOL_SHIFT                   12
#define ATC260X_WALL_OV_VOL_WIDTH                    1
#define ATC260X_WALL_OC_SET                     0x0F00  /* WALL_OC_SET [11:8] */
#define ATC260X_WALL_OC_SET_MASK                0x0F00
#define ATC260X_WALL_OC_SET_SHIFT                    8
#define ATC260X_WALL_OC_SET_WIDTH                    4
#define ATC260X_WALL_OC_SHUTOFF_SET             0x00C0  /* WALL_OC_SHUTOFF_SET [7:6] */
#define ATC260X_WALL_OC_SHUTOFF_SET_MASK        0x00C0
#define ATC260X_WALL_OC_SHUTOFF_SET_SHIFT            6
#define ATC260X_WALL_OC_SHUTOFF_SET_WIDTH            2
#define ATC260X_WALLOVUVOC_RESERVED             0x003F  /* WALLOVUVOC_RESERVED [5:0] */
#define ATC260X_WALLOVUVOC_RESERVED_MASK        0x003F
#define ATC260X_WALLOVUVOC_RESERVED_SHIFT            0
#define ATC260X_WALLOVUVOC_RESERVED_WIDTH            6

/**
 * R15 (0x0F) - PMU WALL Control 1
 */
#define ATC260X_WALL_OC_EN                      0x8000  /* WALL_OC_EN */
#define ATC260X_WALL_OC_EN_MASK                 0x8000
#define ATC260X_WALL_OC_EN_SHIFT                    15
#define ATC260X_WALL_OC_EN_WIDTH                     1
#define ATC260X_WALL_OV_EN                      0x4000  /* WALL_OV_EN */
#define ATC260X_WALL_OV_EN_MASK                 0x4000
#define ATC260X_WALL_OV_EN_SHIFT                    14
#define ATC260X_WALL_OV_EN_WIDTH                     1
#define ATC260X_WALL_UV_EN                      0x2000  /* WALL_UV_EN */
#define ATC260X_WALL_UV_EN_MASK                 0x2000
#define ATC260X_WALL_UV_EN_SHIFT                    13
#define ATC260X_WALL_UV_EN_WIDTH                     1
#define ATC260X_WALL_OC_INT_EN                  0x1000  /* WALL_OC_INT_EN */
#define ATC260X_WALL_OC_INT_EN_MASK             0x1000
#define ATC260X_WALL_OC_INT_EN_SHIFT                12
#define ATC260X_WALL_OC_INT_EN_WIDTH                 1
#define ATC260X_WALL_OV_INT_EN                  0x0800  /* WALL_OV_INT_EN */
#define ATC260X_WALL_OV_INT_EN_MASK             0x0800
#define ATC260X_WALL_OV_INT_EN_SHIFT                11
#define ATC260X_WALL_OV_INT_EN_WIDTH                 1
#define ATC260X_WALL_UV_INT_EN                  0x0400  /* WALL_UV_INT_EN */
#define ATC260X_WALL_UV_INT_EN_MASK             0x0400
#define ATC260X_WALL_UV_INT_EN_SHIFT                10
#define ATC260X_WALL_UV_INT_EN_WIDTH                 1
#define ATC260X_WALL_OC_SHUTOFF_EN              0x0200  /* WALL_OC_SHUTOFF_EN */
#define ATC260X_WALL_OC_SHUTOFF_EN_MASK         0x0200
#define ATC260X_WALL_OC_SHUTOFF_EN_SHIFT             9
#define ATC260X_WALL_OC_SHUTOFF_EN_WIDTH             1
#define ATC260X_WALLOVER_RESERVED               0x01FF  /* WALLOVER_RESERVED [8:0] */
#define ATC260X_WALLOVER_RESERVED_MASK          0x01FF
#define ATC260X_WALLOVER_RESERVED_SHIFT              0
#define ATC260X_WALLOVER_RESERVED_WIDTH              9

/**
 * R16 (0x10) - PMU System Status
 */
#define ATC260X_BAT_OV_STATUS                   0x8000  /* BAT_OV_STATUS */
#define ATC260X_BAT_OV_STATUS_MASK              0x8000
#define ATC260X_BAT_OV_STATUS_SHIFT                 15
#define ATC260X_BAT_OV_STATUS_WIDTH                  1
#define ATC260X_BAT_UV_STATUS                   0x4000  /* BAT_UV_STATUS */
#define ATC260X_BAT_UV_STATUS_MASK              0x4000
#define ATC260X_BAT_UV_STATUS_SHIFT                 14
#define ATC260X_BAT_UV_STATUS_WIDTH                  1
#define ATC260X_BAT_OC_STATUS                   0x2000  /* BAT_OC_STATUS */
#define ATC260X_BAT_OC_STATUS_MASK              0x2000
#define ATC260X_BAT_OC_STATUS_SHIFT                 13
#define ATC260X_BAT_OC_STATUS_WIDTH                  1
#define ATC260X_VBUS_OV_STATUS                  0x1000  /* VBUS_OV_STATUS */
#define ATC260X_VBUS_OV_STATUS_MASK             0x1000
#define ATC260X_VBUS_OV_STATUS_SHIFT                12
#define ATC260X_VBUS_OV_STATUS_WIDTH                 1
#define ATC260X_VBUS_UV_STATUS                  0x0800  /* VBUS_UV_STATUS */
#define ATC260X_VBUS_UV_STATUS_MASK             0x0800
#define ATC260X_VBUS_UV_STATUS_SHIFT                11
#define ATC260X_VBUS_UV_STATUS_WIDTH                 1
#define ATC260X_VBUS_OC_STATUS                  0x0400  /* VBUS_OC_STATUS */
#define ATC260X_VBUS_OC_STATUS_MASK             0x0400
#define ATC260X_VBUS_OC_STATUS_SHIFT                10
#define ATC260X_VBUS_OC_STATUS_WIDTH                 1
#define ATC260X_WALL_OV_STATUS                  0x0200  /* WALL_OV_STATUS */
#define ATC260X_WALL_OV_STATUS_MASK             0x0200
#define ATC260X_WALL_OV_STATUS_SHIFT                 9
#define ATC260X_WALL_OV_STATUS_WIDTH                 1
#define ATC260X_WALL_UV_STATUS                  0x0100  /* WALL_UV_STATUS */
#define ATC260X_WALL_UV_STATUS_MASK             0x0100
#define ATC260X_WALL_UV_STATUS_SHIFT                 8
#define ATC260X_WALL_UV_STATUS_WIDTH                 1
#define ATC260X_WALL_OC_STATUS                  0x0080  /* WALL_OC_STATUS */
#define ATC260X_WALL_OC_STATUS_MASK             0x0080
#define ATC260X_WALL_OC_STATUS_SHIFT                 7
#define ATC260X_WALL_OC_STATUS_WIDTH                 1
#define ATC260X_STATUS_RESERVED                 0x007E  /* WALL_STATUS_RESERVED [6:1] */
#define ATC260X_STATUS_RESERVED_MASK            0x007E
#define ATC260X_STATUS_RESERVED_SHIFT                1
#define ATC260X_STATUS_RESERVED_WIDTH                6
#define ATC260X_STATUS_CLEAR1                   0x0001  /* WALL_STATUS_RESERVED [6:0] */
#define ATC260X_STATUS_CLEAR1_MASK              0x0001  /* FLAG TO CLEAR BITS 15-7 */
#define ATC260X_STATUS_CLEAR1_SHIFT                  0
#define ATC260X_STATUS_CLEAR1_WIDTH                  1






/* ATC260X device */
struct atc260x_dev;

/*
 * ATC260X register interface
 */
int atc260x_reg_read(struct atc260x_dev *atc260x, unsigned short reg);
int atc260x_reg_write(struct atc260x_dev *atc260x, unsigned short reg,
         unsigned short val);
int atc260x_set_bits(struct atc260x_dev *atc260x, unsigned short reg,
            unsigned short mask, unsigned short val);

/* 
 * ATC260X SPI interface access mode
 */
#define ATC260X_SPI_ACCESS_MODE_NORMAL      (0)     /* access by standard SPI driver interface */
#define ATC260X_SPI_ACCESS_MODE_DIRECT      (1)     /* access SPI controller directly */
int atc260x_set_access_mode(struct atc260x *atc260x, int mode);

/* ATC260X AuxADC interface */
enum atc260x_auxadc {
        ATC260X_AUX_IREF     = 0,
        ATC260X_AUX_CHGI     = 1,
        ATC260X_AUX_VBUSI    = 2,
        ATC260X_AUX_WALLI    = 3,
        ATC260X_AUX_BATI     = 4,
        ATC260X_AUX_REMCON   = 5,
        ATC260X_AUX_TEMP     = 6,
        ATC260X_AUX_BATV     = 7,
        ATC260X_AUX_BAKBATV  = 8,
        ATC260X_AUX_SYSPWRV  = 9,
        ATC260X_AUX_WALLV    = 10,
        ATC260X_AUX_VBUSV    = 11,
        ATC260X_AUX_AUX3     = 12,
        ATC260X_AUX_AUX2     = 13,
        ATC260X_AUX_AUX1     = 14,
        ATC260X_AUX_AUX0     = 15,
};

int atc260x_auxadc_reg_read(struct atc260x *atc260x, enum atc260x_auxadc input);
int atc260x_auxadc_read(struct atc260x *atc260x, enum atc260x_auxadc input);

/* ATC260X chip version */ 
enum ATC260X_CHIP_VERSION {
        ATC260X_VER_A = 0x0000,
        ATC260X_VER_B = 0x0001,
        ATC260X_VER_C = 0x0002,
};

int atc260x_get_version(void);

/* ATC260X CMU interface */ 
#define ATC260X_CMU_MODULE_TP            (0)
#define ATC260X_CMU_MODULE_MFP           (1)
#define ATC260X_CMU_MODULE_INTS          (2)
#define ATC260X_CMU_MODULE_ETHPHY        (3)
#define ATC260X_CMU_MODULE_AUDIO         (4)
#define ATC260X_CMU_MODULE_NUM           (5) // CMU module count

int atc260x_cmu_reset(struct atc260x *atc260x, int cmu_module);
int atc260x_cmu_enable(struct atc260x *atc260x, int cmu_module);
int atc260x_cmu_disable(struct atc260x *atc260x, int cmu_module);

/* ATC260X MFD interface */ 
enum atc260x_mfp_mod_id {
        MOD_ID_RMII,
        MOD_ID_SMII,
        MOD_ID_REMCON,
        MOD_ID_TP,
        MOD_ID_LED0,
        MOD_ID_LED1,
};

#define  ATC260X_MFP_OPT_CAN_SLEEP       (0)
#define  ATC260X_MFP_OPT_CANNOT_SLEEP    (1)

int atc260x_mfp_lock (enum atc260x_mfp_mod_id mod_id, int opt, struct device *dev);
int atc260x_mfp_locked (enum atc260x_mfp_mod_id mod_id, int opt);
int atc260x_mfp_unlock (enum atc260x_mfp_mod_id mod_id, int opt);

/* ATC260X IRQ interface */
#define ATC260X_IRQ_AUDIO                (0)
#define ATC260X_IRQ_TP                   (1)
#define ATC260X_IRQ_ETHERNET             (2)
#define ATC260X_IRQ_OV                   (3)
#define ATC260X_IRQ_OC                   (4)
#define ATC260X_IRQ_OT                   (5)
#define ATC260X_IRQ_UV                   (6)
#define ATC260X_IRQ_ALARM                (7)
#define ATC260X_IRQ_ONOFF                (8)
#define ATC260X_IRQ_WKUP                 (9)
#define ATC260X_IRQ_IR                   (10)
/* internal IRQ source count */
#define ATC260X_IRQ_NUM                  (11)

/* ATC260X internal GPIO count */ 
#define ATC260X_GPIO_NUM                 (32)        /* internal GPIO count */

/* ATC260X Power Management */ 
#define POWER_MODE_WORKING              (0)     /* S1 */
#define POWER_MODE_STANDBY              (1)     /* S2 */
#define POWER_MODE_SLEEP                (2)     /* S3 */
#define POWER_MODE_DEEP_SLEEP           (3)     /* S4 */

/* wakeup sources */
#define WAKEUP_SRC_IR                   (1 << 0)
#define WAKEUP_SRC_RESET                (1 << 1)
#define WAKEUP_SRC_HDSW                 (1 << 2)
#define WAKEUP_SRC_ALARM                (1 << 3)
#define WAKEUP_SRC_REMCON               (1 << 4)
#define WAKEUP_SRC_TP                   (1 << 5)
#define WAKEUP_SRC_WKIRQ                (1 << 6)
#define WAKEUP_SRC_ONOFF_SHORT          (1 << 7)
#define WAKEUP_SRC_ONOFF_LONG           (1 << 8)
#define WAKEUP_SRC_WALL_IN              (1 << 9)
#define WAKEUP_SRC_VBUS_IN              (1 << 10)
#define WAKEUP_SRC_ALL                  (0x7ff)

struct pmic_suspend_ops {
        int (*set_wakeup_src)(int wakeup_mask, int wakeup_src);
    int (*get_wakeup_src)(void);
    int (*get_wakeup_flag)(void);       /* wakeup reason flag */
    void (*prepare)(int mode);
    void (*enter)(int mode);
    void (*wake)(void);
    void (*finish)(void);
};

/* gl5302_PMU_SYS_CTL3 FW reserved flag */
#define PMU_SYS_CTL3_FW_FLAG_S2         (1 << 4)    /* suspend to S2 flag */

/* ATC260X misc interface */ 
int atc260x_enable_vbusotg(int on);

#endif /* __ATC260X_H__ */

