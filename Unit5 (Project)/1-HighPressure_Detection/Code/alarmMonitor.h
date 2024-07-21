/*
 * AlarmMonitor.h
 *
 *  Created on: 19 Jul 2024
 *      Author: Ahmed Basem
 */

#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_

#include "state.h"

//Define States
enum {
	AlarmMonitor_alarmOff,
	AlarmMonitor_alarmOn
}AlarmMonitor_state_id;


//declare states functions AlarmMonitor
STATE_define(AlarmMonitor_alarmOff);
STATE_define(AlarmMonitor_alarmOn);

//STATE Pointer to function
extern void (*AlarmMonitor_state)();

#endif /* ALARMMONITOR_H_ */