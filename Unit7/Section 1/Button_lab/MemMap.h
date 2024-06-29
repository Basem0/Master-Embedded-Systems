/*
 * MemMap.h
 *
 * Created: 5/5/2024 10:19:20 PM
 *  Author: ahmed
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

// DDR = 0 >> Pin Input    ||    DDR = 1 >> Pin Output
// PORT = 1 >> Pin HIGH        ||    PORT = 0 >> Pin LOW
#define DDRA  *((volatile unsigned char *)(0x3A)) // Data Direction Register For Port A
#define PORTA *((volatile unsigned char *)(0x3B)) // Output Register For Port A
#define PINA  *((volatile unsigned char *)(0x39))  // Input Register For Port A

#define DDRB  *((volatile unsigned char *)(0x37)) // Data Direction Register For Port A
#define PORTB *((volatile unsigned char *)(0x38)) // Output Register For Port A
#define PINB  *((volatile unsigned char *)(0x36))  // Input Register For Port A

#define DDRC  *((volatile unsigned char *)(0x34)) // Data Direction Register For Port A
#define PORTC *((volatile unsigned char *)(0x35)) // Output Register For Port A
#define PINC  *((volatile unsigned char *)(0x33))  // Input Register For Port A


#endif /* MEMMAP_H_ */