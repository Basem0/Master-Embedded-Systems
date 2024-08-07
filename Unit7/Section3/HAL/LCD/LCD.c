/*
 * LCD.C
 *
 *  Created on: July 4, 2024
 *      Author: Ahmed Basem
 */

// =======================================================================================
// ===================================== INCLUDES ========================================
// =======================================================================================
#include "LCD.h"
#include "LCD_CFG.h"
// =======================================================================================
// ================================= Data Type Declartion ================================
// =======================================================================================



// =======================================================================================
// =============================== Private Functions =====================================
// =======================================================================================
static void HAL_LCD_KICK(void);

// Function to make delay_ms 1ms
static void delay_ms(uint32_t delay)
{
	uint32_t i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
}
#if LCD_MODE == LCD_8_BIT_MODE
static void LCD_8BIT_INIT(void)
{
	// ======================= Set CTRL Switches to Output ===================

	// RS_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinConfig.GPIO_PinNumber = LCD_RS_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_RS_PORT, &PinConfig);

	//RW_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinConfig.GPIO_PinNumber = LCD_RW_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_RW_PORT, &PinConfig);

	//Enable_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinConfig.GPIO_PinNumber = LCD_EN_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_EN_PORT, &PinConfig);

	// =================== Set LCD Port to Output with Speed 10 MHz (push-pull) mode ==============

	PinConfig.GPIO_PinNumber = LCD_D0_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D0_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D1_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D1_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D2_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D2_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D3_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D3_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D4_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D4_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D5_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D5_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D6_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D6_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D7_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D7_PORT, &PinConfig);

	// Reset EN_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
	// Reset RS_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
	// Reset RW_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
}

static void HAL_8BIT_LCD_KICK(void)
{
	// Set Enable bit
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_SET);

	// AC Characteristics : Enable cycle time (R & W ) = 500 ns
	delay_ms(50);

	// Reset Enable bit
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
}

#elif LCD_MODE == LCD_4_BIT_MODE

static void LCD_4BIT_INIT(void)
{
	// ======================= Set CTRL Switches to Output ===================

	// RS_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinConfig.GPIO_PinNumber = LCD_RS_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_RS_PORT, &PinConfig);

	//RW_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinConfig.GPIO_PinNumber = LCD_RW_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_RW_PORT, &PinConfig);

	//Enable_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinConfig.GPIO_PinNumber = LCD_EN_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_EN_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D4_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D4_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D5_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D5_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D6_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D6_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D7_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D7_PORT, &PinConfig);

	// Reset EN_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
	// Reset RS_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
	// Reset RW_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
}

static void HAL_4BIT_LCD_KICK(void)
{
	// Set Enable bit
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_SET);

	// AC Characteristics : Enable cycle time (R & W ) = 500 ns
	delay_ms(2);

	// Reset Enable bit
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
}
#endif
// =======================================================================================
// =============================== APIs Functions Definitions ============================
// =======================================================================================

// Function to clear screen of LCD
void HAL_LCD_CLEAR_SCREEN(void)
{
	HAL_LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

void HAL_LCD_GOTO_XY(uint8_t line, uint8_t position)
{
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void HAL_LCD_INIT(void)
{

#if LCD_MODE == LCD_8_BIT_MODE
	delay_ms(20);
	LCD_8BIT_INIT();
	delay_ms(15);
	HAL_LCD_CLEAR_SCREEN();
	HAL_LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
#elif LCD_MODE == LCD_4_BIT_MODE
	delay_ms(20);
	LCD_4BIT_INIT();
	delay_ms(15);
	HAL_LCD_WRITE_COMMAND(0x02); // As data sheet
	HAL_LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
#endif
}

// Check if LCD is Busy
void HAL_LCD_ISBUSY(void)
{
	//============== Set Port to Receive Data (input) ===============

    // DataDir_LCD_PORT &= ~(0xFF << DATA_shift);
#if LCD_MODE == LCD_8_BIT_MODE
	// Set next 8 pins as input
	PinConfig.GPIO_PinNumber = LCD_D0_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D0_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D1_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D1_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D2_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D2_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D3_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D3_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D4_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D4_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D5_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D5_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D6_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D6_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D7_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D7_PORT, &PinConfig);

	// === Put LCD on read mode ===
	// LCD_CTRL |= (1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_SET);
	// LCD_CTRL &= ~(1 << RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
	HAL_8BIT_LCD_KICK();
#elif LCD_MODE == LCD_4_BIT_MODE
	PinConfig.GPIO_PinNumber = LCD_D4_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D4_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D5_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D5_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D6_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D6_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D7_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_D7_PORT, &PinConfig);

	// LCD_CTRL |= (1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_SET);
	// LCD_CTRL &= ~(1 << RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);

	HAL_4BIT_LCD_KICK();
	// LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

	PinConfig.GPIO_PinNumber = LCD_D4_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D4_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D5_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D5_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D6_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D6_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = LCD_D7_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D7_PORT, &PinConfig);
#endif
}

// Function to write commands for LCD
void HAL_LCD_WRITE_COMMAND(uint8_t command)
{
#if LCD_MODE == LCD_8_BIT_MODE
/* ====== LCD is in 8 bit Mode ====== */

	// Set LCD Port using command variable
    MCAL_GPIO_WritePin(LCD_D0_PORT, LCD_D0_PIN, (command >> 0) & 0x01);
    MCAL_GPIO_WritePin(LCD_D1_PORT, LCD_D1_PIN, (command >> 1) & 0x01);
    MCAL_GPIO_WritePin(LCD_D2_PORT, LCD_D2_PIN, (command >> 2) & 0x01);
    MCAL_GPIO_WritePin(LCD_D3_PORT, LCD_D3_PIN, (command >> 3) & 0x01);
    MCAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (command >> 4) & 0x01);
    MCAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (command >> 5) & 0x01);
    MCAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (command >> 6) & 0x01);
    MCAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (command >> 7) & 0x01);

	// Port Direction is set to Output in LCD_init()

	// Turn RW off so you can write
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

	// Turn RS off for command mode
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);

	delay_ms(1);
	HAL_8BIT_LCD_KICK();

#elif LCD_MODE == LCD_4_BIT_MODE
	/* ====== LCD is in 4 bit Mode ====== */

	// Send last four bits of command
    MCAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (command >> 4) & 0x01);
    MCAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (command >> 5) & 0x01);
    MCAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (command >> 6) & 0x01);
    MCAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (command >> 7) & 0x01);
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
	HAL_4BIT_LCD_KICK();

	// Send first four bits of command
	MCAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (command >> 0) & 0x01);
	MCAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (command >> 1) & 0x01);
	MCAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (command >> 2) & 0x01);
	MCAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (command >> 3) & 0x01);
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
	HAL_4BIT_LCD_KICK();
#endif

}

void HAL_LCD_WRITE_CHAR(uint8_t character)
{
#if LCD_MODE == LCD_8_BIT_MODE
	/* ====== LCD is in 8 bit Mode ====== */
	// Turn RS on for data mode
	//MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);

	// Set LCD Port using character variable
	MCAL_GPIO_WritePin(LCD_D0_PORT, LCD_D0_PIN, (character >> 0) & 0x01);
	MCAL_GPIO_WritePin(LCD_D1_PORT, LCD_D1_PIN, (character >> 1) & 0x01);
	MCAL_GPIO_WritePin(LCD_D2_PORT, LCD_D2_PIN, (character >> 2) & 0x01);
	MCAL_GPIO_WritePin(LCD_D3_PORT, LCD_D3_PIN, (character >> 3) & 0x01);
	MCAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (character >> 4) & 0x01);
	MCAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (character >> 5) & 0x01);
	MCAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (character >> 6) & 0x01);
	MCAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (character >> 7) & 0x01);


	// Turn RW off so you can write
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

	// Turn RS on for data mode
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_SET);

	delay_ms(1);
	HAL_8BIT_LCD_KICK();

#elif LCD_MODE == LCD_4_BIT_MODE
	/* ====== LCD is in 4 bit Mode ====== */


	// Send last four bits of command
    MCAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (character >> 4) & 0x01);
    MCAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (character >> 5) & 0x01);
    MCAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (character >> 6) & 0x01);
    MCAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (character >> 7) & 0x01);
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_SET);
	HAL_4BIT_LCD_KICK();

	// Send first four bits of command
    MCAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (character >> 0) & 0x01);
    MCAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (character >> 1) & 0x01);
    MCAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (character >> 2) & 0x01);
    MCAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (character >> 3) & 0x01);
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_SET);
	HAL_4BIT_LCD_KICK();
#endif

}

void HAL_LCD_WRITE_STRING(char* string)
{
	// Counter to avoid writing bigger word size than LCD screen
	int count = 0;
	while (*string > 0)
	{
		count++;
		HAL_LCD_WRITE_CHAR(*string++);
		if (count == 16) // Counter reached the end of the first row
		{
			HAL_LCD_GOTO_XY(2, 0); // Line : row num 2 , starts from position 0
		} else if (count == 32)
		{
			HAL_LCD_CLEAR_SCREEN();
			HAL_LCD_GOTO_XY(1, 0); // go to line 1 , position 0
			count = 0;
		}
	}
}

/*
void HAL_LCD_custom_characters(void)
{
	HAL_LCD_WRITE_COMMAND(64);
	HAL_LCD_WRITE_CHAR(0);
	HAL_LCD_WRITE_CHAR(14);
	HAL_LCD_WRITE_CHAR(17);
	HAL_LCD_WRITE_CHAR(2);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_CHAR(0);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_CHAR(0);
	delay_ms(10);
}
*/
