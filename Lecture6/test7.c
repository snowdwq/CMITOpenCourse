#include <stdlib.h>

int main(void)
{
    long i;
    for(i = 0; i < 100000000; i++)
    {
        int* k = malloc(sizeof(int));
        *k = 4;
        free(k);
    }

    return 0;
}
