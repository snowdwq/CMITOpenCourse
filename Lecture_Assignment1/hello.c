#include <stdio.h> // looks first the path and then the current directory
//#include "stdio.h" // looks first the current directory and then the path
// in order to avoid malicious libraries in the current directory

int main(void)
{
	puts("HELLO WORLD");

	const char msg[] = "Hello world";

	puts(msg);

	return 0;
}
