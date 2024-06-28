#include "uart.h"


unsigned char name[] = "ahmed basem mohamed";
int  main()
{
	Uart_Send(name);
	return 0;
}