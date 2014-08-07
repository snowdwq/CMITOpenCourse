#include <stdlib.h>
#include <stdio.h>

struct list_node
{
    int data;
    struct list_node* next;
};

struct list_node* stack_buffer = NULL; // Initialize here in order to be sure that the if in pop works correctly */

void push(int element)
{
    struct list_node* new_node;
    new_node = malloc(sizeof(struct list_node));
    new_node->data = element;
    new_node->next = stack_buffer;
    stack_buffer = new_node;
}

int pop()
{
    if(stack_buffer)
    {
        int element = stack_buffer->data;
        struct list_node* nToDel = stack_buffer;
        stack_buffer = nToDel->next;
        free(nToDel);
        return element;
    }
    else
        return 0;
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
    printf("%d\n", pop());

    return 0;
}
