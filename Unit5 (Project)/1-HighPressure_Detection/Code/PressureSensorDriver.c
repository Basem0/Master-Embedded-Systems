/*
 * PressureSensorDriver.c
 *
 *  Created on: 19 Jul 2024
 *      Author: Ahmed Basem
 */

#include "PressureSensorDriver.h"
#include "driver.h"

//variables
static int PressureSensorDriver_pValue = 0;

//STATE Pointer to function
void (*PressureSensorDriver_state)();

void PressureSensorDriver_init()
{
	//init PressureSensorDriver
	GPIO_INITIALIZATION();
}
STATE_define(PressureSensorDriver_reading)
{
	//state_Name
	PressureSensorDriver_state_id = PressureSensorDriver_reading ;

	//state_Action
	PressureSensorDriver_pValue = getPressureVal();
	set_pressure_val(PressureSensorDriver_pValue); //send signal
	Delay(10000); //100 sec
}