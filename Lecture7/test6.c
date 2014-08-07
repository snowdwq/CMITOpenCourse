#include <stdlib.h>
#include <stdio.h>

float queue_buffer[100];
int front = 0;
int count = 0;
int capacity; /* I don't use it here but if we used a dynamic array we would need a capacity field in order to increase the size of the array when we need */

void enqueue(float element)
{
    if(count < 100)
    {
        queue_buffer[(front+count)%100] = element;
        count++;
    }
}

float dequeue()
{
    if(count > 0)
    {
        float toReturn = queue_buffer[front];
        count--;
        front++;

        if(front == 100)
        {
            front = 0;
        }

        return toReturn;
    }
    else
        return 0; /* or other special value */
}

int main(void)
{
    enqueue(7);
    enqueue(5);
    enqueue(6);

    int h = 0;
    printf("%d %d %d\n", h++, h++, h++); // undefined behaviour in function parameters sequence

    int i =1;
    // i = (++i); undefined behaviour
    // i = i++; undefined behaviour
    i = i+1;

    printf("%d\n", i);

    printf("%f\n", dequeue());
    printf("%f\n", dequeue());
    printf("%f\n", dequeue());

    return 0;
}
