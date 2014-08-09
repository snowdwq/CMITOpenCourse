#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void apply(struct node* head, void (*fp)(void*, void*), void* arg)
{
    struct node* p = head;
    while(p!=NULL)
    {
        fp(p, arg);
        p = p->next;
    }
}

void print(void* head, void* arg)
{
    struct node* np = (struct node*)head;
    printf("%d ", np->data);
}

void dototal(void* head, void* arg)
{
    struct node* np = (struct node*)head;
    int* ptotal = (int*)arg;
    *ptotal += np->data;
}

enum TYPE{PRINT, TOTAL};
void (*fp[2])(void*, void*) = {print, dototal};

void test(void* p, void* arg, enum TYPE type)
{
    apply(p, (*fp[type]), arg);
}

int main(void)
{
    struct node* head = NULL;
    head = malloc(sizeof(struct node));
    head->data = 6;
    struct node* toAdd = malloc(sizeof(struct node));
    toAdd->data = 7;
    toAdd->next = NULL;
    head->next = toAdd;

    apply(head, print, NULL);
    int total = 0;
    apply(head, dototal, &total);

    printf("\nTotal is %d\n", total);

    test(head, NULL, PRINT);
    total = 0;
    test(head, &total, TOTAL);
    printf("\nTotal is %d\n", total);
    return 0;
}
