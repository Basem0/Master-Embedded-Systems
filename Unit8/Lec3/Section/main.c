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
void ISR_Uart()
{
	uint8 data = MCAL_UART_ReceiveData(USART_disable);
	MCAL_UART_SendData(data,USART_enable);
	HAL_LCD_WRITE_CHAR(data);
}

int main(void)
{
	USART_Config_t UartCfg;
	UartCfg.USART_Baudrate = USART_BAUD_RATE_9600;
	UartCfg.USART_Databits = USART_8_DATA_BITS;
	UartCfg.USART_IRQ_Enable = USART_IRQ_RXCIE;
	UartCfg.USART_Mode = USART_MODE_ASYNC;
	UartCfg.USART_Paritybit = USART_NO_PARITY;
	UartCfg.USART_Stopbits = USART_1_STOP_BIT;
	UartCfg.P_IRQ_CallBack = ISR_Uart;
	MCAL_USART_Init(&UartCfg);
	HAL_LCD_INIT();
	
	while (1)
	{
		
	}
	return 0;
}
