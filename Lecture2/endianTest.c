#include <stdio.h>

int main(void)
{
    int num = 1;

    printf("%d\n",(char)num);
    printf("%d\n",*(char *)&num);

    if(*(char *)&num == 1)
    {
        printf("\nLittle-Endian\n");
    }
    else
    {
        printf("Big-Endian\n");
    }

    return 0;
}
