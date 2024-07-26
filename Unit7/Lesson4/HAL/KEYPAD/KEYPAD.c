/*
 * KEYPAD.c
 *
 *  Created on: Jul 21, 2024
 *      Author: Ahmed Basem
 */

// =========================================================================================================
// ============================================== INCLUDES =================================================
// =========================================================================================================
#include "KEYPAD_CFG.h"
#include "KEYPAD.h"
#include "PLATFORM_TYPES.h"

// =========================================================================================================
// ============================================== GLOBAL VARIABLES =========================================
// =========================================================================================================
GPIO_PinConfig_t pinconfg;

uint16 KEYPAD_ROW_PIN[KEYPAD_ROWS] = {R0_PIN, R1_PIN, R2_PIN, R3_PIN};
GPIO_PinConfig_t * KEYPAD_ROW_PORT[KEYPAD_ROWS] = {R0_PORT, R1_PORT, R2_PORT, R3_PORT};
uint16 KEYPAD_COL_PIN[KEYPAD_COLUMS] = {C0_PIN, C1_PIN, C2_PIN, C3_PIN};
GPIO_PinConfig_t * KEYPAD_COL_PORT[KEYPAD_COLUMS] = {C0_PORT, C1_PORT, C2_PORT, C3_PORT};

// =========================================================================================================
// ========================================== KEYPAD Keys ==================================================
// =========================================================================================================
uint8 KEYPAD_keys[KEYPAD_ROWS][KEYPAD_COLUMS] = {
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'C','0','=','+'}
};

static void delay_ms(uint32 delay) {
	uint32 i, j;
	for (i = 0; i < delay; i++) {
		for (j = 0; j < 255; j++);
	}
}

void HAL_KEYPAD_INIT(void) {
	GPIO_PinConfig_t PinConfig;

	// Initialize rows as input with pull-up resistors
	PinConfig.GPIO_PinNumber = R0_PIN;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(R0_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R1_PIN;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(R1_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R2_PIN;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(R2_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R3_PIN;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(R3_PORT, &PinConfig);

	// Initialize columns as output

	PinConfig.GPIO_PinNumber = C0_PIN;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(C0_PORT, &PinConfig);
	MCAL_GPIO_WritePin(C0_PORT, C0_PIN, GPIO_PIN_RESET);

	PinConfig.GPIO_PinNumber = C1_PIN;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(C1_PORT, &PinConfig);
	MCAL_GPIO_WritePin(C1_PORT, C1_PIN, GPIO_PIN_RESET);

	PinConfig.GPIO_PinNumber = C2_PIN;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(C2_PORT, &PinConfig);
	MCAL_GPIO_WritePin(C2_PORT, C2_PIN, GPIO_PIN_RESET);

	PinConfig.GPIO_PinNumber = C3_PIN;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(C3_PORT, &PinConfig);
	MCAL_GPIO_WritePin(C3_PORT, C3_PIN, GPIO_PIN_RESET);
}

char HAL_KEYPAD_GET_KEY(void) {

	for(volatile uint8 col = 0; col < KEYPAD_COLUMS; col++)
	{
		MCAL_GPIO_WritePin(C0_PORT, C0_PIN, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(C1_PORT, C1_PIN, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(C2_PORT, C2_PIN, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(C3_PORT, C3_PIN, GPIO_PIN_SET);

		MCAL_GPIO_WritePin(KEYPAD_COL_PORT[col], KEYPAD_COL_PIN[col], GPIO_PIN_RESET);

		for(volatile uint8 row = 0; row < KEYPAD_ROWS; row++)
		{
			if(MCAL_GPIO_ReadPin(KEYPAD_ROW_PORT[row], KEYPAD_ROW_PIN[row]) == GPIO_PIN_RESET)
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_ROW_PORT[row], KEYPAD_ROW_PIN[row]) == GPIO_PIN_RESET);
				return KEYPAD_keys[row][col];
			}
			delay_ms(25);
		}
	}
	return 0;

}
