#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char k = '\n';
    char k2 = ' ';
    char k3 = '\t';

    printf("a%ca a%ca a%ca", k , k2, k3);

    char k4 = '\0'; // backslash let us take character with ascii code 0 instead of '0'. Consequently '\0' == (char)0 or (int)0. Char is an int remember.....


    return 0;
}
