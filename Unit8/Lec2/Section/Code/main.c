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

#define F_CPU 8000000UL


int main(void)
{
	USART_Config_t UartCfg;
	UartCfg.USART_Baudrate = USART_BAUD_RATE_9600;
	UartCfg.USART_Databits = USART_8_DATA_BITS;
	UartCfg.USART_IRQ_Enable = USART_IRQ_DISABLE;
	UartCfg.USART_Mode = USART_MODE_ASYNC;
	UartCfg.USART_Paritybit = USART_NO_PARITY;
	UartCfg.USART_Stopbits = USART_1_STOP_BIT;
	UartCfg.P_IRQ_CallBack = NULL;
	MCAL_USART_Init(&UartCfg);
	HAL_LCD_INIT();
	MCAL_UART_SendData('A',USART_enable);
	MCAL_UART_SendData('H',USART_enable);
	MCAL_UART_SendData('M',USART_enable);
	MCAL_UART_SendData('E',USART_enable);
	MCAL_UART_SendData('D',USART_enable);
	
	while (1)
	{
		HAL_LCD_WRITE_CHAR(MCAL_UART_ReceiveData(USART_enable));
	}
	return 0;
}
