#include "LIFO.h"

int main(){

	LIFO_t numbers;

	LIFO_init(&numbers, 5);
	unsigned int i;
	for(i = 0; i < 7; i++){
		if(LIFO_push(&numbers,i) == LIFO_NO_ERROR)
			printf("item : %d is pushed\n", i);

		else
			printf("FAILED to push \n\n");
	}

	unsigned int temp;
	for(i = 0; i < 7; i++){
		if(LIFO_pop(&numbers,&temp) == LIFO_NO_ERROR)
			printf("Item : %d is popped \n",temp);

		else
			printf("FALIED to pop\n");

	}
	return 0;

}