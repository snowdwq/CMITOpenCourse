#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    void* p;
    int* k = malloc(sizeof(int));
    *k = 5;
    p = k;

    printf("%d\n", *((int*)p));
    printf("%lu\n", sizeof(p));

    float f = 4.5;
    p = &f;
    printf("%lu\n", sizeof(p));

    // printf("%d\n", *p); // undefined behaviour

    void* ptr;
    //int* num = malloc(sizeof(int));
    //*num = 6;
    int num = 5;
    ptr = &num;
    printf("%lu", sizeof(ptr));
    /* Output the size   */
    // printf("Size of Pointer : %lu Bytes",sizeof(ptr));

    return 0;
}
