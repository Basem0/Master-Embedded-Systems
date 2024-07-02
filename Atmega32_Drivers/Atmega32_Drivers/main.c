/*
 * Atmega32_Drivers.c
 *
 * Created: 6/28/2024 12:17:47 AM
 * Author : ahmed
 */ 

#include "MCAL/GPIO/gpio.h"
#include "HAL/LCD/lcd.h"
#include "HAL/KEYPAD/keypad.h"

chr_lcd_4bit_t _lcd = {
	.lcd_rs.port = PORTC_INDEX,
	.lcd_rs.pin = GPIO_PIN0,
	.lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
	.lcd_rs.logic = GPIO_LOW,

	.lcd_en.port = PORTC_INDEX,  // Example port assignment, change as needed
	.lcd_en.pin = GPIO_PIN1,
	.lcd_en.direction = GPIO_DIRECTION_OUTPUT,
	.lcd_en.logic = GPIO_LOW,

	.lcd_data[0].port = PORTC_INDEX,  // Example port assignment, change as needed
	.lcd_data[0].pin = GPIO_PIN2,
	.lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[0].logic = GPIO_LOW,

	.lcd_data[1].port = PORTC_INDEX,  // Example port assignment, change as needed
	.lcd_data[1].pin = GPIO_PIN3,
	.lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[1].logic = GPIO_LOW,

	.lcd_data[2].port = PORTC_INDEX,  // Example port assignment, change as needed
	.lcd_data[2].pin = GPIO_PIN4,
	.lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[2].logic = GPIO_LOW,

	.lcd_data[3].port = PORTC_INDEX,  // Example port assignment, change as needed
	.lcd_data[3].pin = GPIO_PIN5,
	.lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[3].logic = GPIO_LOW
};


int main(void)
{
    /* Replace with your application code */
	lcd_4bit_init(&_lcd);
	char message[11] = "HELLO LCD!";
	lcd_4bit_send_string(&_lcd,message);
    while (1) 
    {
		
    }
}

