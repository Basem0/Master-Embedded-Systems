#include "FIFO.h"

int main()
{

    FIFO_t numbers;

    FIFO_init(&numbers, 5);
    unsigned int i;
    for (i = 0; i < 7; i++)
    {
        if (FIFO_enqueue(&numbers, i) == FIFO_NO_ERROR)
            printf("item : %d is enqueued\n", i);

        else
            printf("FAILED to enqueued \n\n");
    }

    unsigned int temp;
    for (i = 0; i < 7; i++)
    {
        if (FIFO_dequeue(&numbers, &temp) == FIFO_NO_ERROR)
            printf("Item : %d is dequeued \n", temp);

        else
            printf("FALIED to dequeued\n");
    }
    return 0;
}