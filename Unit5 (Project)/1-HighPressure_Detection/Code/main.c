#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "PressureSensorDriver.h"
#include "AlarmMonitor.h"
#include "MainAlg.h"
#include "AlarmActuatorDriver.h"

void setup()
{
	AlarmActuatorDriver_init();
	PressureSensorDriver_state = STATE(PressureSensorDriver_reading);
	MainAlg_state = STATE(MainAlg_high_pressure_detection);
	AlarmMonitor_state = STATE(AlarmMonitor_alarmOff);
	StopAlarm();
}
int main (){
	// GPIO_INITIALIZATION ();
	// GPIOA_BRR = 0x8000;
	setup();
	while (1)
	{
		//Implement your Design 
		PressureSensorDriver_state();
		MainAlg_state();
		AlarmMonitor_state();
	}

}