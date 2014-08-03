#include <stdlib.h>

int main(void)
{
    int l;
    for(l = 0; l < 1000; l++)
    {
        int* mpool = malloc(sizeof(int)*100000);
        long i;
        for(i = 0; i < 100000; i++)
        {
            int* k = &mpool[i];
            *k = 4;
        }
        free(mpool);
    }

    return 0;
}
