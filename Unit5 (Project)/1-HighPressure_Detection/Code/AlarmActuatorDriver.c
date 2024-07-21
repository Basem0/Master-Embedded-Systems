/*
 * AlarmActuatorDriver.c
 *
 *  Created on: 19 Jul 2024
 *      Author: Ahmed Basem
 */

#include "AlarmActuatorDriver.h"
#include "driver.h"

#define ALARM_OFF 1
#define ALARM_ON  0

//STATE Pointer to function
void (*AlarmActuatorDriver_state)();


void AlarmActuatorDriver_init()
{
	GPIO_INITIALIZATION();
}

// interface between this moduel and AlarmMonitor
void StartAlarm()
{
	AlarmActuatorDriver_state = STATE(AlarmActuatorDriver_AlarmOn);
	AlarmActuatorDriver_state();
}
void StopAlarm()
{
	AlarmActuatorDriver_state = STATE(AlarmActuatorDriver_AlarmOff);
	AlarmActuatorDriver_state();
}


STATE_define(AlarmActuatorDriver_waiting)
{
	//state_Name
	AlarmActuatorDriver_state_id = AlarmActuatorDriver_waiting ;
}

STATE_define(AlarmActuatorDriver_AlarmOn)
{
	//state_Name
	AlarmActuatorDriver_state_id = AlarmActuatorDriver_AlarmOn ;

	//state_Action
	Set_Alarm_actuator(ALARM_ON);
	AlarmActuatorDriver_state = STATE(AlarmActuatorDriver_waiting);

}

STATE_define(AlarmActuatorDriver_AlarmOff)
{
	//state_Name
	AlarmActuatorDriver_state_id = AlarmActuatorDriver_AlarmOff ;

	//state_Action
	Set_Alarm_actuator(ALARM_OFF);
	AlarmActuatorDriver_state = STATE(AlarmActuatorDriver_waiting);
}


