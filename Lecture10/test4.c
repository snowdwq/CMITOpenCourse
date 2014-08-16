#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "memmove can be very useful......";
    puts(str+20);
    puts(str+15);
    memmove (str+20,str+15,11);
    puts (str);
    return 0;
}
