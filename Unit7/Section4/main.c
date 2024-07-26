/*
 * Atmega32_Drivers.c
 *
 * Created: 6/28/2024 12:17:47 AM
 * Author : ahmed
 */ 

/* ================================================================ */
/* ======================== Includes ============================== */
/* ================================================================ */
#include "MCAL/GPIO/GPIO.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/USART/USART.h"
#include "MCAL/SPI/SPI.h"	


#define F_CPU 8000000UL



int main(void)
{
	HAL_LCD_INIT();
	
	HAL_LCD_WRITE_STRING("Learn in Depth");
	while(1)
	{
		
	}
}
