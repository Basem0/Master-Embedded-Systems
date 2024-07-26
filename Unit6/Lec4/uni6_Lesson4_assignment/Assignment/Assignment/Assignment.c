/*
 * Assignment.c
 *
 *  Created on: Jul 13, 2024
 *      Author: Ahmed Basem
 */ 

#define F_CPU   8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "BIT_utils.h"
#include "STD_Types.h"
#include "EXT_INT_int.h"

void Handler_EXT0();
void Handler_EXT1();
void Handler_EXT2();

int main(void)
{
	EXT_INT_enuEnable(EXT_INT_u8_INT0,EXT_INT_u8_LOGICAL_CHANGE_INT0);
	EXT_INT_enuEnable(EXT_INT_u8_INT1,EXT_INT_u8_RISING_EDGE_INT1);
	EXT_INT_enuEnable(EXT_INT_u8_INT2,EXT_INT_u8_FALLING_EDGE_INT2);
	
	EXT_INT_enuRegisterCBF(EXT_INT_u8_INT0, Handler_EXT0);
	EXT_INT_enuRegisterCBF(EXT_INT_u8_INT1, Handler_EXT1);
	EXT_INT_enuRegisterCBF(EXT_INT_u8_INT2, Handler_EXT2);
	
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	
	sei();
	
    while(1)
    {
        CLR_BIT(PORTD, 5);
	    CLR_BIT(PORTD, 6);
		CLR_BIT(PORTD, 7);	
    }
}

void Handler_EXT0()
{
	SET_BIT(PORTD,5);
	_delay_ms(1000);
}

void Handler_EXT1()
{
	SET_BIT(PORTD,6);
	_delay_ms(1000);	
}

void Handler_EXT2()
{
	SET_BIT(PORTD,7);
	_delay_ms(1000);
}


