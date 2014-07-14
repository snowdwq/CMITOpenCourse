#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    char pf[LINE_MAX];
    printf("%d", LINE_MAX);

    char* string;
    // segmentation fault because unallocated space char test = string[1];

    char string2[20]; //= "hello";

    // string2 = "hello";
    string2[1] = 'E'; //it works because the string literal is copies to the array (it is not the original one)

    char* s = "Hello"; // string literal is const char[], The conversion is deprecated, and only exists for backwards compatibility.
    // *s = 'H'; segmentation fault
    // s[1] = 'E'; segmentation fault again

    int var = 5;
    /*int* k;
    const int* k2 = &var;
    int* const k3 = &var;

    k = k2;
    k = k3;*/

    int * pointer;
    int * const const_pointer = &var;
    const int * pointer_to_const;

    /* a */
    pointer = const_pointer; // OK, no cast (same type)
    /* b */
    pointer_to_const = pointer; // OK, casting 'int*' to 'const int*'
    /* c */
    pointer = pointer_to_const; // Illegal, casting 'const int*' to 'int*'

    return 0;
}
