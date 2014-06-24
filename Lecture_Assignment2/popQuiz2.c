#include <stdio.h>

int main(void)
{
    // puts("hel"+"lo"); + is for strings in java and c++ not for char *
    puts("hel""lo");

    // short int s=0xFFFF12; overflow
    enum sz{S=0,L=3,XL};
    // S, L, XL are enumators which are always ints
    printf("%d\n", S);
    printf("%d\n", L);
    printf("%d\n", XL);

    enum sz var = S; // enumumaration variables may not be ints
    printf("%d\n", (int)var); // better cast

    if(4 == XL)
    {
        printf("True\n");
    }
    // enum sz{S=0,L=−3,XL}; wrong of course

    return 0;
}
