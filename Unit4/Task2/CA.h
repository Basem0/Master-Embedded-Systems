/*
 * CA.h
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */


#ifndef CA_H_
#define CA_H_

#include "state.h"
extern int state_id;
//define states
enum
{
	waiting,
	driving
};


//functions prototypes
STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);


//global pointer to function
extern void (*CA_state)();


#endif // CA_H_
