#ifndef DICT_H // include guard
#define DICT_H

#include<stdio.h>

/* data structure
for the dictionary */
// char* the_dictionary[100]; // array of 100 pointers to char*
extern char the_dictionary[100];
// if char the_dictionary[100]
// No, something worse happens.
// Each source file that includes the header will have its own variable, so each source file will compile
// independently but the linker will complain because two source files will have the same global identifiers.
/* declarations */
void load_dictionary();
char* lookup(char []);

#endif
