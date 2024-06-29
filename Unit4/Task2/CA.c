/*
 * CA.c
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */

#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
#include "state.h"

// Define state_id here
int state_id;

// Global variables
unsigned int speed = 0;
unsigned int distance = 0;
unsigned int threshold = 50;

// Global pointer to function
void (*CA_state)();

STATE_DEFINE(CA_waiting)
{
    state_id = waiting;
    printf("CA Waiting state : distance = %d speed = %d\n", distance, speed);
    speed = 0;
    DC_set_speed(speed);
}

STATE_DEFINE(CA_driving)
{
    state_id = driving;
    printf("CA Driving state : distance = %d speed = %d\n", distance, speed);
    speed = 30;
    DC_set_speed(speed);
}

void US_set_distance(int d)
{
    distance = d;
    // Check event
    CA_state = (distance <= threshold) ? STATE(CA_waiting) : STATE(CA_driving);
    printf("US ----------- distance = %d --------------> CA\n", distance);
}
