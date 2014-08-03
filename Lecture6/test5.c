#include<stdlib.h>
#define BLOCK_SIZE 1024*1024*256
int main()
{
    int i=0;
    char *buf[10];
    while(i<10)
    {
        buf[i] = calloc(1, BLOCK_SIZE);
        i++;
    }
}
