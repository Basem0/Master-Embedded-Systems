/*
 * atmega32_device_header.h
 *
 * Created: 7/2/2024 3:34:29 AM
 *  Author: ahmed
 */

#ifndef ATMEGA32_DEVICE_HEADER_H_
#define ATMEGA32_DEVICE_HEADER_H_

/************************************************************************/
/*                              Includes                                */
/************************************************************************/
#include "Utils.h"           /* Utility macros and functions */
#include "Platform_Types.h"  /* Platform-specific type definitions */

/************************************************************************/
/*                        GPIO Registers Definitions                    */
/************************************************************************/
/* Port A Registers */
#define PORTA  ((vuint8_t*)0x3B)  /* Data Register for Port A */
#define PINA   ((vuint8_t*)0x39)  /* Input Pins Address for Port A */
#define DDRA   ((vuint8_t*)0x3A)  /* Data Direction Register for Port A */

/* Port B Registers */
#define PORTB  ((vuint8_t*)0x38)  /* Data Register for Port B */
#define PINB   ((vuint8_t*)0x36)  /* Input Pins Address for Port B */
#define DDRB   ((vuint8_t*)0x37)  /* Data Direction Register for Port B */

/* Port C Registers */
#define PORTC  ((vuint8_t*)0x35)  /* Data Register for Port C */
#define PINC   ((vuint8_t*)0x33)  /* Input Pins Address for Port C */
#define DDRC   ((vuint8_t*)0x34)  /* Data Direction Register for Port C */

/* Port D Registers */
#define PORTD  ((vuint8_t*)0x32)  /* Data Register for Port D */
#define PIND   ((vuint8_t*)0x30)  /* Input Pins Address for Port D */
#define DDRD   ((vuint8_t*)0x31)  /* Data Direction Register for Port D */

#endif /* ATMEGA32_DEVICE_HEADER_H_ */
