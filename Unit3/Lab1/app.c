#include <uart.h>

unsigned char *string_buffer = "Ahmed Basem";
void main()
{
	Uart_Send_string(string_buffer);
}
