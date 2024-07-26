/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Basem
 * @brief          : Main program body
 ******************************************************************************
 */
#define F_CPU  8000000UL
#include "MemMap.h""
#include "Utils.h"
#include <util/delay.h>

void init(void)
{
	DDRA = 0xff;
}

int main(void)
{
	
	init();
	  int i;
    while (1) 
    {
	 
				 for(i=0;i<8;i++)
				 {
					 SetBit(PORTA,i);
					 _delay_ms(20);
				 }
				 
				 for(i=7;i>=0;i--)
				 {
					 ClearBit(PORTA,i);
					 _delay_ms(20);
				 }
	 }
	return 0;
}