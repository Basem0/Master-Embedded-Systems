#include "FIFO.h"

FIFO_status FIFO_init(FIFO_t *_stack, unsigned int length)
{
	if (!_stack)
	{
		return FIFO_NULL;
	}
	else
	{
		_stack->base = (ELEMENT_TYPE *)(malloc(length * sizeof(ELEMENT_TYPE)));
		if (NULL == _stack->base)
		{
			return FIFO_NULL;
		}
		else
		{
			_stack->head = _stack->base;
			_stack->tail = _stack->base;
			_stack->length = length;
			_stack->count = 0;
			return FIFO_NO_ERROR;
		}
	}
}

FIFO_status FIFO_enqueue(FIFO_t *_stack, ELEMENT_TYPE item)
{
	if (!_stack || !_stack->base)
	{
		return FIFO_NULL;
	}
	else
	{
		if (FIFO_is_full(_stack))
		{
			// Optionally handle full queue overflow here
			// For circular FIFO, you might wrap around tail to base
			// and overwrite the oldest element if necessary.
			// Example:
			if (_stack->tail == _stack->base + _stack->length)
				_stack->tail = _stack->base;

			// Or alternatively, you can return FIFO_FULL and handle overflow
			// in the calling code if required.
			return FIFO_FULL;
		}
		else
		{
			*(_stack->tail) = item;
			(_stack->tail)++;
			if (_stack->tail == _stack->base + _stack->length)
			{
				_stack->tail = _stack->base;
			}
			_stack->count++;
			return FIFO_NO_ERROR;
		}
	}
}

FIFO_status FIFO_dequeue(FIFO_t *_stack, ELEMENT_TYPE *item)
{
	if (!_stack)
	{
		return FIFO_NULL;
	}
	else
	{
		if (FIFO_is_empty(_stack))
		{
			return FIFO_EMPTY;
		}
		else
		{
			*item = *(_stack->head);
			(_stack->head)++;
			if (_stack->head == _stack->base + _stack->length)
			{
				_stack->head = _stack->base;
			}
			_stack->count--;
			return FIFO_NO_ERROR;
		}
	}
}

uint8_t FIFO_is_full(FIFO_t *_stack)
{
	if (!_stack)
	{
		return FIFO_NULL;
	}
	else
	{
		if (_stack->count == _stack->length)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

uint8_t FIFO_is_empty(FIFO_t *_stack)
{
	if (!_stack)
	{
		return FIFO_NULL;
	}
	else
	{
		if (_stack->count == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
