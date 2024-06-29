/*
 * LIFO.h
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */

#include "LIFO.h"

LIFO_status LIFO_init(LIFO_t* _stack, unsigned int length){
	if(!_stack)
		return LIFO_NULL;

	_stack->base = (ELEMENT_TYPE *)(malloc(length * sizeof(ELEMENT_TYPE)));
 	if(NULL == _stack->base)
 	{
   		return LIFO_NULL;
 	}
 	else
 	{
		_stack->head = _stack->base;
		_stack->length = length;
		_stack->count = 0;
	 }

	return LIFO_NO_ERROR;
}

LIFO_status LIFO_push(LIFO_t* _stack, ELEMENT_TYPE item){
	if(!_stack->base || !_stack->head || !_stack)
		return LIFO_NULL;

	if(LIFO_is_full(_stack))
	{
		return LIFO_FULL;
	}

	*(_stack->head) = item;
	_stack->head++;
	_stack->count++;
	return LIFO_NO_ERROR;


}

LIFO_status LIFO_pop(LIFO_t* _stack, ELEMENT_TYPE* item){
	if(!_stack->base || !_stack->head || !_stack)
		return LIFO_NULL;

	if(LIFO_is_empty(_stack))
	{
		return LIFO_EMPTY;
 	}

	_stack->head--;
	_stack->count--;
	*item = *(_stack->head);
	return LIFO_NO_ERROR;

}

uint8_t  LIFO_is_full(LIFO_t* _stack)
{
	if(!_stack->base || !_stack->head || !_stack)
		return LIFO_NULL;

	if(_stack->length == _stack->count)
		return 1;

	return 0;
}

uint8_t LIFO_is_empty(LIFO_t* _stack)
{
	if(!_stack->base || !_stack->head)
		return LIFO_NULL;

	if(_stack->count == 0)
		return 1;

	return 0;
}