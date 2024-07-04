/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103c6_gpio.h"

void clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void GPIO_init()
{
	GPIO_PinConfig_t Pincfg;

	// Configure GPIOA Pin 1 as input floating
	Pincfg.GPIO_PinNumber = GPIO_PIN_1;
	Pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &Pincfg);

	// Configure GPIOB Pin 1 as output push-pull
	Pincfg.GPIO_PinNumber = GPIO_PIN_1;
	Pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pincfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &Pincfg);



	// Configure GPIOA Pin 13 as input floating
	Pincfg.GPIO_PinNumber = GPIO_PIN_13;
	Pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &Pincfg);

	// Configure GPIOB Pin 13 as output push-pull
	Pincfg.GPIO_PinNumber = GPIO_PIN_13;
	Pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pincfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &Pincfg);
}

void delay(uint32_t time)
{
	uint32_t i, j;
	for (i = 0; i < time; i++)
	{
		for (j = 0; j < 255; j++);
	}
}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) // Press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0); // Single-press
		}

		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) // Multi-presses
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		delay(1);
	}
}
