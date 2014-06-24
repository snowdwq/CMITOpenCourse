#include <stdio.h>

int main(void)
{
    float x=3/2;
    float x2=3.0/2;
    int x3=3.0/2;

    printf("%f\n", x);
    printf("%f\n", x2);
    printf("%d\n", x3);

    int x4 = 0x770 ^ 0x773;
    int x5 = 0x33 ^ 0x33;
    printf("%d\n", x4);
    printf("%d\n", x5);

    int x6 = 0x01<<4;
    int x7 = 1<<2;
    int x8 = 0x010>>4;
    int x9 = 4>>1;

    printf("%d\n", x6);
    printf("%d\n", x7);
    printf("%d\n", x8);
    printf("%d\n", x9);

    int x10 = 5; // zugos = even, monos = odd

    int sign=x10>0?1:-1;
    int isodd=x10%2==1?1:0;

    printf("%d\n", sign);
    printf("%d\n", isodd);

    return 0;
}
