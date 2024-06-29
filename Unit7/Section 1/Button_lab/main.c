/*
 * main.c
 *
 * Created: 6/29/2024 11:30:02 PM
 *  Author: ahmed
 */ 

#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0xFF;
    ClearBit(DDRC, 0);
    int status;

    int flag = 0; // 0 set 1 Clear
    int i = 0;
    while (1)
    {
        status = ReadBit(PINC, 0);
        if (status && flag == 0)
        {
            SetBit(PORTA, i++);
        }
        else if (status && flag == 1)
        {
            ClearBit(PORTA, i--);
        }

        if (flag == 0 && i == 8)
        {
            flag = 1;
            i = 7;
        }
        if (flag == 1 && i == -1)
        {
            flag = 0;
            i = 0;
        }
		_delay_ms(100);
    }
}
