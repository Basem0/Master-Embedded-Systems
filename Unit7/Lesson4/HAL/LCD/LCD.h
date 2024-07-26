/*
 * LCD.h
 *
 *  Created on: Jul 21, 2024
 *      Author: Ahmed Basem
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

// =========================================================================================================
// ================================================ INCLUDES ===============================================
// =========================================================================================================
#include "GPIO.h"

// =========================================================================================================
// ============================================ MACRO Declartion ===========================================
// =========================================================================================================
#define F_CPU 1000000UL
#define LCD_8_BIT_MODE  	1
#define LCD_4_BIT_MODE  	2


// =========================================================================================================
// ============================================= LCD Commands ==============================================
// =========================================================================================================
#define LCD_CMD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_CMD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_CMD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_CMD_MOVE_DISP_LEFT   						(0x18)
#define LCD_CMD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_CMD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_CMD_DISP_OFF   								(0x08)
#define LCD_CMD_DISP_ON_CURSOR   						(0x0E)
#define LCD_CMD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_CMD_DISP_ON_BLINK   						(0x0D)
#define LCD_CMD_DISP_ON   								(0x0C)
#define LCD_CMD_ENTRY_DEC   							(0x04)
#define LCD_CMD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_CMD_ENTRY_INC_   							(0x06)
#define LCD_CMD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_CMD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_CMD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CMD_CLEAR_SCREEN							(0x01)
#define LCD_CMD_ENTRY_MODE								(0x06)


// =========================================================================================================
// =================================== APIs Supported by "HAL LCD DRIVER" ==================================
// =========================================================================================================
void HAL_LCD_INIT(void);
void HAL_LCD_WRITE_COMMAND(uint8 command);
void HAL_LCD_WRITE_CHAR(uint8 character);
void HAL_LCD_WRITE_STRING(char* string);
void HAL_LCD_ISBUSY(void);
void HAL_LCD_CLEAR_SCREEN(void);
void HAL_LCD_GOTO_XY(uint8 line, uint8 position);
//void HAL_LCD_custom_characters(void);

// =========================================================================================================
// ========================================== Data Type Declartion =========================================
// =========================================================================================================
GPIO_PinConfig_t PinConfig ;

#endif /* LCD_LCD_H_ */
