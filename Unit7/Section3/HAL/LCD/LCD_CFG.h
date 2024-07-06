/*
 * LCD_CFG.h
 *
 *  Created on: July 4, 2024
 *      Author: Ahmed Basem
 */

#ifndef _LCD_CFG_H_
#define _LCD_CFG_H_

// =======================================================================================
// ===================================== INCLUDES ========================================
// =======================================================================================
#include "stm32f103x6.h"
#include "stm32f103c6_gpio.h"

// =======================================================================================
// ===================================== RS CONFIG =======================================
// =======================================================================================
#define LCD_RS_PORT           GPIOA
#define LCD_RS_PIN            GPIO_PIN_8

// =======================================================================================
// ===================================== RW CONFIG =======================================
// =======================================================================================
#define LCD_RW_PORT           GPIOA
#define LCD_RW_PIN            GPIO_PIN_9

// =======================================================================================
// ===================================== EN CONFIG =======================================
// =======================================================================================
#define LCD_EN_PORT           GPIOA
#define LCD_EN_PIN            GPIO_PIN_10


// =======================================================================================
// ================================= DATA PINS CONFIG ====================================
// =======================================================================================
#define LCD_MODE              LCD_8_BIT_MODE


#if LCD_MODE == LCD_8_BIT_MODE
#define LCD_D0_PORT            GPIOA
#define LCD_D0_PIN             GPIO_PIN_0

#define LCD_D1_PORT            GPIOA
#define LCD_D1_PIN             GPIO_PIN_1

#define LCD_D2_PORT            GPIOA
#define LCD_D2_PIN             GPIO_PIN_2

#define LCD_D3_PORT            GPIOA
#define LCD_D3_PIN             GPIO_PIN_3
#endif

#define LCD_D4_PORT            GPIOA
#define LCD_D4_PIN             GPIO_PIN_4

#define LCD_D5_PORT            GPIOA
#define LCD_D5_PIN             GPIO_PIN_5

#define LCD_D6_PORT            GPIOA
#define LCD_D6_PIN             GPIO_PIN_6

#define LCD_D7_PORT            GPIOA
#define LCD_D7_PIN             GPIO_PIN_7


#endif // _LCD_CFG_H_
