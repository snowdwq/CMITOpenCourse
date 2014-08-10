#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

int system(const char *command)
{
    printf("%s\n", command);
    return 0;
}