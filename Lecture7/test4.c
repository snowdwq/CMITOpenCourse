#include <stdlib.h>
#include <stdio.h>

int stack_buffer[100];
int itop = 0;

void push(int elem)
{
    stack_buffer[itop++] = elem;
}

int pop()
{
    if(itop == 0)
    {
        return 0; /* or other special value , if it was a pointer I could return NULL */
    }
    else
    {
        return stack_buffer[--itop];
    }
}

/* I prefer this method :), NULL rules */
int* pop2()
{
    if(itop == 0)
    {
        return NULL;
    }
    else
    {
        return &(stack_buffer[itop--]);
    }
}

int main(void)
{
    push(1);
    push(2);
    push(5);
    push(-20);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}
