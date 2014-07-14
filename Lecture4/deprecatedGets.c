#include <stdio.h>
#include <string.h>

int main(void)
{
    char  b1[] = "ABCD\n";
    char  b2[] = "LMNOE";
    char  b3[] = "ZYXW";

    puts(b1);
    puts(b2);
    puts(b3);
    putchar('\n');

    puts("Enter some characters:");
    gets(b2);
    b3[1] = 'l';

    putchar('\n');
    puts(b1);
    puts(b2);
    puts(b3);

    b2[0] = 0;
    putchar('\n');
    puts(b1);
    puts(b2);
    puts(b3);

    return(0);
}
