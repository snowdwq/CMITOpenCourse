#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int asc(int* a, int* b)
{
    return *a-*b;
}

int desc(const void* a, const void* b)
{
    return (*((int*)b)- (*(int*)a));
}

int main(void)
{
    qsort(values, 5, sizeof(int), asc);
    printf("\nAfter sorting the list is: \n");
    int n;
    for(n = 0 ; n < 5; n++ )
    {
        printf("%d ", values[n]);
    }

    qsort(values, sizeof(values)/sizeof(int), sizeof(int), desc);
    printf("\nAfter sorting the list is: \n");
    for(n = 0 ; n < 5; n++ )
    {
        printf("%d ", values[n]);
    }

    return 0;
}
