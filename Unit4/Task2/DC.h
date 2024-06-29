/*
 * DC.h
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */


#ifndef DC_H_
#define DC_H_


#include "state.h"

extern int DC_state_id;
//define states
enum
{
	dc_idle,
	dc_busy
};


//functions prototypes
STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);

void DC_init();


//global pointer to function
extern void (*DC_state)();


#endif // DC_H_
