/*
 * US.h
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */
#ifndef US_H_
#define US_H_


#include "state.h"

extern int US_state_id;
//define states
enum
{
	us_busy
};


//functions prototypes
STATE_DEFINE(US_busy);

void US_init();

//global pointer to function
extern void (*US_state)();


#endif // US_H_
