#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strpos(char *haystack, char *needle)
{
    char *p = strstr(haystack, needle);
    if(p)
    {
        return p - haystack;
    }

    return -1;   // Not found = -1.
}

int main(void)
{
    int* p = (int*)malloc(50*sizeof(int));
    printf("%lu\n", sizeof(p)); // 8 bytes at 64 bit OS and 4 bytes at 32 bit OS

    char str[] = "This is a test";
    char str2[] = "is a";
    printf("%d\n", strpos(str, str2)); // if I don't include string.h we have implicit declaration

    return 0;
}
