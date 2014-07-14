#ifndef STDIO_H // include guard
#define STDIO_H

#include<stdio.h>

extern int global; // the declaration merely introduces the variable into the symbol table (and will cause the linker to go looking for it when it comes to link time).
// we should define global in only one source file and include o.h to all the source file that have global
// extern int global2; we cannot extern it because it is static
int func(void);

#endif
