#include <stdlib.h>
#include <stdio.h>

struct foo
{
    short s;
    union
    {
        int i;
        char c;
    } u;
    unsigned int flag_s:1;
    unsigned int flag_u:2;
    unsigned int bar;
};


struct foo2
{
    union
    {
        int i;
        char c;
    } u;
    unsigned int bar;
    short s;
    unsigned int flag_s:1;
    unsigned int flag_u:2;
};

void swap(int** a, int** b)
{
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    printf("%lu\n%lu\n", sizeof(struct foo), sizeof(struct foo2));

    int k = 4;
    int l = 5;

    int* pk = &k;
    int* pl = &l;

    swap(&pk, &pl);

    printf("%d %d\n", *pk, *pl);

    return 0;
}
