/*
 * Utils.h
 *
 * Created: 5/5/2024 10:34:12 PM
 *  Author: ahmed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(Register , Bit)      (Register |= (1<<Bit))  // set Determined Bit In Register
#define ClearBit(Register , Bit)    (Register &= ~(1<<Bit)) // Clear Determined Bit In Register
#define ToggleBit(Register , Bit)   (Register ^= (1<<Bit))  // Toggle Determined Bit In Register
#define ReadBit(Register , Bit)     ((Register>>Bit)&1)     // Read Determined Bit From Register


#endif /* UTILS_H_ */