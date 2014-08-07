#include <stdio.h>

int i;
int k;

int main(void)
{
    extern int i;
    int l;
    printf("%d %d\n", k, l);
    if (i == 0)
        printf("scope rules\n");

    return 0;
}
