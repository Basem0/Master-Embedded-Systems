/*
 * FIFO.h
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"
#include <stdlib.h>

#define ELEMENT_TYPE uint32_t

// attributes of the LIFO
typedef struct
{
	ELEMENT_TYPE *base;
	ELEMENT_TYPE *head;
	ELEMENT_TYPE *tail;
	unsigned int length;
	unsigned int count;
} FIFO_t;

// LIFO status
typedef enum
{
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL,
	FIFO_NO_ERROR
} FIFO_status;

// interfaces
FIFO_status FIFO_init(FIFO_t *_stack, unsigned int length);
FIFO_status FIFO_enqueue(FIFO_t *_stack, ELEMENT_TYPE item);
FIFO_status FIFO_dequeue(FIFO_t *_stack, ELEMENT_TYPE *item);
uint8_t FIFO_is_full(FIFO_t *_stack);
uint8_t FIFO_is_empty(FIFO_t *_stack);

#endif /* FIFO_H_ */