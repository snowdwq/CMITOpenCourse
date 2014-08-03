#include <stdlib.h>

int main(void)
{
    int l;
    for(l = 0; l < 10; l++)
    {
        int* mpool = (int* ) malloc(sizeof(int)*10000000);
        long i;
        for(i = 0; i < 10000000; i++)
        {
            int* k = &mpool[i];
            *k = 4;
        }
    }

    return 0;
}
