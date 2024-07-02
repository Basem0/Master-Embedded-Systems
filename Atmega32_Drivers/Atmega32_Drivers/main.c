/*
 * Atmega32_Drivers.c
 *
 * Created: 6/28/2024 12:17:47 AM
 * Author : ahmed
 */ 
#define F_CPU 1000000UL
#include "MCAL/GPIO/gpio.h"
#include "HAL/LCD/lcd.h"
#include "HAL/KEYPAD/keypad.h"

chr_lcd_4bit_t _lcd = {
	.lcd_rs.port = PORTC_INDEX,
	.lcd_rs.pin = GPIO_PIN0,
	.lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
	.lcd_rs.logic = GPIO_LOW,

	.lcd_en.port = PORTC_INDEX,
	.lcd_en.pin = GPIO_PIN1,
	.lcd_en.direction = GPIO_DIRECTION_OUTPUT,
	.lcd_en.logic = GPIO_LOW,

	.lcd_data[0].port = PORTC_INDEX,
	.lcd_data[0].pin = GPIO_PIN2,
	.lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[0].logic = GPIO_LOW,

	.lcd_data[1].port = PORTC_INDEX,
	.lcd_data[1].pin = GPIO_PIN3,
	.lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[1].logic = GPIO_LOW,

	.lcd_data[2].port = PORTC_INDEX,
	.lcd_data[2].pin = GPIO_PIN4,
	.lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[2].logic = GPIO_LOW,

	.lcd_data[3].port = PORTC_INDEX,
	.lcd_data[3].pin = GPIO_PIN5,
	.lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[3].logic = GPIO_LOW
};

keypad_t _keypad = {
	.keypad_row_pins[0].port = PORTD_INDEX,
	.keypad_row_pins[0].pin = GPIO_PIN0,
	.keypad_row_pins[0].direction = GPIO_DIRECTION_OUTPUT,
	.keypad_row_pins[0].logic = GPIO_LOW,

	.keypad_row_pins[1].port = PORTD_INDEX,
	.keypad_row_pins[1].pin = GPIO_PIN1,
	.keypad_row_pins[1].direction = GPIO_DIRECTION_OUTPUT,
	.keypad_row_pins[1].logic = GPIO_LOW,

	.keypad_row_pins[2].port = PORTD_INDEX,
	.keypad_row_pins[2].pin = GPIO_PIN2,
	.keypad_row_pins[2].direction = GPIO_DIRECTION_OUTPUT,
	.keypad_row_pins[2].logic = GPIO_LOW,

	.keypad_row_pins[3].port = PORTD_INDEX,
	.keypad_row_pins[3].pin = GPIO_PIN3,
	.keypad_row_pins[3].direction = GPIO_DIRECTION_OUTPUT,
	.keypad_row_pins[3].logic = GPIO_LOW,

	.keypad_column_pins[0].port = PORTD_INDEX,
	.keypad_column_pins[0].pin = GPIO_PIN4,
	.keypad_column_pins[0].direction = GPIO_DIRECTION_INPUT,
	.keypad_column_pins[0].logic = GPIO_LOW,

	.keypad_column_pins[1].port = PORTD_INDEX,
	.keypad_column_pins[1].pin = GPIO_PIN5,
	.keypad_column_pins[1].direction = GPIO_DIRECTION_INPUT,
	.keypad_column_pins[1].logic = GPIO_LOW,

	.keypad_column_pins[2].port = PORTD_INDEX,
	.keypad_column_pins[2].pin = GPIO_PIN6,
	.keypad_column_pins[2].direction = GPIO_DIRECTION_INPUT,
	.keypad_column_pins[2].logic = GPIO_LOW,

	.keypad_column_pins[3].port = PORTD_INDEX,
	.keypad_column_pins[3].pin = GPIO_PIN7,
	.keypad_column_pins[3].direction = GPIO_DIRECTION_INPUT,
	.keypad_column_pins[3].logic = GPIO_LOW
};


int main(void)
{
	/* Initialize LCD and Keypad */
	lcd_4bit_init(&_lcd);
	keypad_init(&_keypad);

	char message[11] = "HELLO LCD!";
	lcd_4bit_send_string(&_lcd, message);

	char input_buffer[5] = {0};  // Buffer to store numeric input from keypad
	int buffer_index = 0;        // Index to track buffer position
	char key;
	
	while (1)
	{
		/* Scan keypad for input */
		keypad_get_value(&_keypad,&key);

		if (key >= '0' && key <= '9')
		{
			/* Valid numeric key pressed, store in buffer and display on LCD */
			input_buffer[buffer_index++] = key;
			input_buffer[buffer_index] = '\0';  // Ensure null-terminated string

			/* Display the number on LCD */
			lcd_4bit_send_command(&_lcd,_LCD_CLEAR);
			lcd_4bit_set_cursor(&_lcd, 1, 1);  // Move cursor to the second line
			lcd_4bit_send_string(&_lcd, input_buffer);

			/* Reset buffer after displaying */
			if (buffer_index >= 4)  // Assuming a maximum of 4 digits
			{
				buffer_index = 0;
				for (int i = 0; i < 5; ++i)
				input_buffer[i] = 0;
			}
		}

		/* Delay to prevent multiple detections */
		_delay_ms(100);
	}
	return 0;
}
