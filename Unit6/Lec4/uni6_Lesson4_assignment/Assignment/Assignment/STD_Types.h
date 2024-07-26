/*
 * STB_Types.h

 *
 *  Created on: Jul 13, 2024
 *      Author: Ahmed Basem
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

typedef unsigned char 			u8;
typedef unsigned short int 		u16;
typedef unsigned long int 		u32;

typedef signed char 			s8;
typedef signed short int 		s16;
typedef signed long int 		s32;
typedef  float                  f32;
typedef  double                 f64;


#define NULL     ((void*)0)

typedef void(*func_ptr)(void);

typedef void(*func_ptr_one_argument)(u16* ptr);

#endif /* LIB_STD_TYPES_H_ */
