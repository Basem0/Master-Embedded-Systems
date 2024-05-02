#include <uart.h>
unsigned char string_buffer[100] = "Ahmed Basem";
void main()
{
	Uart_Send_string(string_buffer);
}
