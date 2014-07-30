#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int n = 4;
    int* pn = &n;
    double* ppi;
    ppi = (double*)pn;
    // *ppi = 4.4;

    printf("%lu %lu %lu\n", sizeof(double), sizeof(float), sizeof(int)); // double is 8 bytes, int is 4, ohhhhhhh!!!! Problem!!!
    // printf("%f\n", *ppi); // any float is promoted in double in printf

    int*    x;  // Allocate the pointers x and y
    int*    y;  // (but not the pointees)

    x = malloc(sizeof(int));    // Allocate an int pointee,
                                // and set x to point to it
    *x = 42;    // Dereference x to store 42 in its pointee
    // *y = 13;    // CRASH -- y does not have a pointee yet. Constants don't have a memory address (where the constant will be saved?)
    y = &n;     // it works because we give the pointer a place that has memory (the variable n)
    printf("\n%d\n", *y);
    y = x;      // Pointer assignment sets y to point to x's pointee
    *y = 13;    // Dereference y to store 13 in its (shared) pointee

    return 0;
}
