/*
 * LIFO.h
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdint.h"
#include <stdlib.h>


#define ELEMENT_TYPE	uint32_t

// attributes of the LIFO
typedef struct{
	ELEMENT_TYPE* base;
	ELEMENT_TYPE* head;
	unsigned int length;
	unsigned int count;
}LIFO_t;

//LIFO status
typedef enum{
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL,
	LIFO_NO_ERROR

}LIFO_status;



//interfaces
LIFO_status LIFO_init(LIFO_t * _stack, unsigned int length);
LIFO_status LIFO_push(LIFO_t* _stack, ELEMENT_TYPE item);
LIFO_status LIFO_pop(LIFO_t* _stack, ELEMENT_TYPE* item);
uint8_t  LIFO_is_full(LIFO_t* _stack);
uint8_t LIFO_is_empty(LIFO_t* _stack);



#endif /* LIFO_H_ */