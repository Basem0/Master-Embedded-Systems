/*
 * AlarmMonitor.c
 *
 *  Created on: 19 Jul 2024
 *      Author: Ahmed Basem
 */

#include "AlarmMonitor.h"
#include "driver.h"

//variables
static int AlarmMonitor_period = 60000;


//STATE Pointer to function
void (*AlarmMonitor_state)();


// interface between this moduel and MainAlg
void high_pressure_detected()
{
	AlarmMonitor_state = STATE(AlarmMonitor_alarmOn);
}

STATE_define(AlarmMonitor_alarmOff)
{
	//state_Name
	AlarmMonitor_state_id = AlarmMonitor_alarmOff ;

	//state_Action
	StopAlarm();
}
STATE_define(AlarmMonitor_alarmOn)
{
	//state_Name
	AlarmMonitor_state_id = AlarmMonitor_alarmOn ;

	//state_Action
	StartAlarm();
	Delay(AlarmMonitor_period); //60 sec
	StopAlarm();
	AlarmMonitor_state = STATE(AlarmMonitor_alarmOff);
}