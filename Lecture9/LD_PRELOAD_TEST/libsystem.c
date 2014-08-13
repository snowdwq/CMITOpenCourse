#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int system(const char *command)
{
    printf("%s\n", command);
    int (*original_system)(const char*);
    original_system = dlsym(RTLD_NEXT, "system");
    return original_system(command);
}
