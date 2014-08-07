#include <stdlib.h>
#include <stdio.h>

struct list_node
{
    int data;
    struct list_node* next;
};

struct list_node* queue_buffer = NULL; // Initialize here in order to be sure that the if in pop works correctly */
struct list_node* rear = NULL; // Rear is at the end

void enqueue(float element)
{
    struct list_node* new_node = malloc(sizeof(struct list_node));
    new_node->data = element;
    new_node->next = NULL;
    if(rear)
        rear->next = new_node;
    else /*empty*/
        queue_buffer = new_node;
    rear = new_node;
}

float dequeue()
{
    if(queue_buffer)
    {
        struct list_node* toDel = queue_buffer;
        float element = toDel->data;
        queue_buffer = queue_buffer->next;
        if(toDel == rear)
            rear = NULL;
        free(toDel);
        return element;
    }
    else
        return 0; // or other special value
}

int main(void)
{
    enqueue(7);
    enqueue(5);
    enqueue(6);

    printf("%f\n", dequeue());
    printf("%f\n", dequeue());
    printf("%f\n", dequeue());

    return 0;
}
