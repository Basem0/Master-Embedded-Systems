/*
 * Atmega32_Drivers.c
 *
 * Created: 6/28/2024 12:17:47 AM
 * Author : ahmed
 */ 

/* ================================================================ */
/* ======================== Includes ============================== */
/* ================================================================ */
//#include "MCAL/GPIO/GPIO.h"
//#include "HAL/LCD/LCD.h"
//#include "MCAL/USART/USART.h"
//#include "MCAL/SPI/SPI.h"	

#include <avr/io.h>
#include "util/delay.h"

#define F_CPU 8000000UL

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
void SPI_MasterInit(void)
{
	/* Set MOSI, SCK and SS output, all others input */
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	
	/* Set MISO input */
	DDRB &= ~(1<<MISO);
	
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

uint8_t SPI_MasterTransmit(uint8_t data)
{
	/* Start transmission, Write data to SPI data register */
	SPDR = data;
	
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	
	/* Return to read the data transmitted */
	return data;
}

int main(void)
{
	uint8_t ch = 0;
	
	DDRA = 0xFF;
	
	SPI_MasterInit();
	
	for (ch = 0; ch <=255; ch++)
	{
		_delay_ms(1000);
		PORTA = SPI_MasterTransmit(ch);
	}
}
