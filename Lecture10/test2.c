#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...)
{
    va_list ap;
    int total = 0;
    va_start(ap, num);

    while(num > 0)
    {
        total += va_arg(ap, int);
        num--;
    }

    va_end(ap);
    return total;
}

int main(void)
{
    int suma = sum(4, 2, 5, 5, 1);
    int sumb = sum(2, 4, 79);

    printf("%d %d", suma, sumb);

    return 0;
}
