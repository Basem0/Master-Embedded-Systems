/*
 * MainAlg.c
 *
 *  Created on: 19 Jul 2024
 *      Author: Ahmed Basem
 */

#include "MainAlg.h"


//variables
static int MainAlg_pValue = 0;
static int MainAlg_threshold = 20;

//STATE Pointer to function
void (*MainAlg_state)();


// interface between this moduel and PressureSensorDriver
void set_pressure_val (int pValue)
{
	MainAlg_pValue = pValue;
}
STATE_define(MainAlg_high_pressure_detection)
{
	//state_Name
	MainAlg_state_id = MainAlg_high_pressure_detection ;

	//state_Action
	if(MainAlg_pValue > MainAlg_threshold)
		high_pressure_detected();
}