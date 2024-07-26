/*
 * Platform_Types.h
 *
 * Created: 6/28/2024 12:33:40 AM
 *  Author: Ahmed Basem
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/************************************************************************/
/*                        Unsigned Integer Types                        */
/************************************************************************/
typedef unsigned char               uint8;    /* 8-bit unsigned integer */
typedef unsigned short              uint16;   /* 16-bit unsigned integer */
typedef unsigned int                uint32;   /* 32-bit unsigned integer */
typedef unsigned long long int      uint64;   /* 64-bit unsigned integer */

/************************************************************************/
/*                         Signed Integer Types                         */
/************************************************************************/
typedef signed char                 sint8;    /* 8-bit signed integer */
typedef signed short                sint16;   /* 16-bit signed integer */
typedef signed int                  sint32;   /* 32-bit signed integer */
typedef signed long long int        sint64;   /* 64-bit signed integer */

/************************************************************************/
/*              Volatile Unsigned Integer Types                         */
/************************************************************************/
typedef volatile unsigned char              vuint8;    /* 8-bit volatile unsigned integer */
typedef volatile unsigned short             vuint16;   /* 16-bit volatile unsigned integer */
typedef volatile unsigned int               vuint32;   /* 32-bit volatile unsigned integer */
typedef volatile unsigned long long int     vuint64;   /* 64-bit volatile unsigned integer */

/************************************************************************/
/*               Volatile Signed Integer Types                          */
/************************************************************************/
typedef volatile signed char                vsint8;    /* 8-bit volatile signed integer */
typedef volatile signed short               vsint16;   /* 16-bit volatile signed integer */
typedef volatile signed int                 vsint32;   /* 32-bit volatile signed integer */
typedef volatile signed long long int       vsint64;   /* 64-bit volatile signed integer */

/************************************************************************/
/*                         Floating Point Types                         */
/************************************************************************/
typedef float       f32;   /* 32-bit floating point */
typedef double      f64;   /* 64-bit floating point */

/************************************************************************/
/*                      Standard Return Type                            */
/************************************************************************/
typedef uint8 Std_ReturnType;    /* Standard Return Type */

/************************************************************************/
/*                          Macro Declarations                          */
/************************************************************************/
#define STD_HIGH       0x01   /* Standard HIGH */
#define STD_LOW        0x00   /* Standard LOW */

#define STD_ON         0x01   /* Standard ON */
#define STD_OFF        0x00   /* Standard OFF */

#define STD_ACTIVE     0x01   /* Standard ACTIVE */
#define STD_IDLE       0x00   /* Standard IDLE */

#define E_OK           (Std_ReturnType)0x01   /* Standard Return OK */
#define E_NOT_OK       (Std_ReturnType)0x00   /* Standard Return NOT OK */

#define ZERO_INIT      0     /* Zero Initialization */

#define NULL ((void *)0)    /* Null Pointer */

#endif /* PLATFORM_TYPES_H_ */
