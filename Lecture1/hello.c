#include <stdio.h> // looks first the path and then the current directory
//#include "stdio.h" // looks first the current directory and then the path
// in order to avoid malicious libraries in the current directory

int main(void)
{
	puts("HELLO WORLD");

    #ifdef _TEST1
	const char msg[] = "Hello world";
    puts(msg);

    #endif
    // do nothing

	return 0;
}
