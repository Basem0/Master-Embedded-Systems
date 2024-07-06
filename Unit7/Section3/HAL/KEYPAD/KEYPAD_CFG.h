/*
 * KEYPAD_CFG.h
 *
 *  Created on: July 4, 2024
 *      Author: Ahmed Basem
 */
 
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

// =======================================================================================
// ===================================== INCLUDES ========================================
// =======================================================================================
#include "stm32f103x6.h"
#include "stm32f103c6_gpio.h"

// =======================================================================================
// ===================================== KEYPAD Config ===================================
// =======================================================================================
//#define KEYPAD_PORT    GPIOB


// =======================================================================================
// ===================================== ROWS OF KEYPAD ==================================
// =======================================================================================

#define R0_PORT  GPIOB
#define R0_PIN   GPIO_PIN_0

#define R1_PORT  GPIOB
#define R1_PIN   GPIO_PIN_1

#define R2_PORT  GPIOB
#define R2_PIN   GPIO_PIN_2

#define R3_PORT  GPIOB
#define R3_PIN   GPIO_PIN_3

// =======================================================================================
// ===================================== COLS OF KEYPAD ==================================
// =======================================================================================
#define C0_PORT   GPIOB
#define C0_PIN    GPIO_PIN_4

#define C1_PORT   GPIOB
#define C1_PIN    GPIO_PIN_5

#define C2_PORT   GPIOB
#define C2_PIN    GPIO_PIN_6

#define C3_PORT   GPIOB
#define C3_PIN    GPIO_PIN_7

/*NUMBER OF ROWS AND COLUMS*/
#define  KEYPAD_ROWS   4
#define  KEYPAD_COLUMS 4




#endif // KEYPAD_CFG_H_
