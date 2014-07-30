#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int l[5] = {1, 2, 3, 4, 5};

void arraytest(int a[]) // array always decays to a pointer when passed
{
    a = l; // the array here is a pointer. So, I can change where it points to.
    printf("%lu %d %d\n", sizeof(a), a[0], l[0]);
}

void stringTest(char a[])
{
    a[2] = 'v';
}

int main(void)
{
    int a = 5;
    int b = 7;
    swap(&a, &b);
    printf("%d %d\n", a, b);

    int k[5] = {5, 6, 7, 8, 9};
    // k = l; not happening in c. You can't change where the array points
    printf("%lu\n", sizeof(k));
    arraytest(k);

    char string[] = "alexis"; // the literal is first copies to the array (that's what happens in c)
    string[2] = 'p';
    stringTest(string);
    // string literals are in the read only memory :)
    // char* string2 = "alexis"; it doesn't happen what happens with array :)
    // string2[2] = 'p';

    return 0;
}
