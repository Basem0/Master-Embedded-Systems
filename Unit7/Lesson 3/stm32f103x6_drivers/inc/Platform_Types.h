/*
 * Platform_Types.h
 *
 * Created on : July 3, 2024
 *     Author : Ahmed Basem
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

// Unsigned integer data types
typedef unsigned char               uint8;
typedef unsigned short              uint16;
typedef unsigned int                uint32;
typedef unsigned long long int      uint64;

// Signed integer data types
typedef signed char                 sint8;
typedef signed short                sint16;
typedef signed int                  sint32;
typedef signed long long int        sint64;

// volatile unsigned integer data types
typedef volatile unsigned char              vuint8;
typedef volatile unsigned short             vuint16;
typedef volatile unsigned int               vuint32;
typedef volatile unsigned long long int     vuint64;

// volatile signed integer data types
typedef volatile signed char                vsint8;
typedef volatile signed short               vsint16;
typedef volatile signed int                 vsint32;
typedef volatile signed long long int       vsint64;

// Float data types
typedef float       float32;
typedef double      float64;

// Boolean date types
typedef enum
{
	false,
	ture,
}bool;

// Error types which used in ErrorIndication Function in any Default Case in Switch
typedef enum
{
	InvalidArgument,    //in any configuration to Pins or Ports
	OverFlow            //in any configuration to LEDs For Example
}ErrorType;

#define NULL ((void *)0)

#endif /* PLATFORM_TYPES_H_ */
