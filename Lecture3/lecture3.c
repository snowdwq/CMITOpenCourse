#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int gcd (int a ,int b)
{

    int i , ret = 1 , minval = min(a ,b);

    for(i = 2; i <= minval; i ++)
    {
        if(a % i)/* i not divisor of a */
        continue ;
        if(b % i == 0)/* i is divisor of both a and b */
        ret = i;
    }

    return ret;
}

int factorial(int n)
{
    int i , j = 1;

    for(i = 1 ; i <= n ; i ++)
        j *= i ;

    return j ;
}

int main(void)
{
    int k = 1;
    char c = 2;
    char d = 'Y';

    switch(k)
    {
        case 0:
            printf("%d\n", 0);
            break;
        case 1:
            printf("%d\n", 1);
            break;
        default:
            printf("%d\n", k);
    }

    switch(c)
    {
        case 0:
            printf("%d\n", 0);
            break;
        case 1:
            printf("%d\n", 1);
            break;
        default:
            printf("%d\n", c);
    }

    switch(d)
    {
        case 'Y':
            printf("%d\n", 13);
            break;
        case 1:
            printf("%d\n", 111);
            break;
        default:
            printf("%d\n", 666);
    }

    printf("%d\n", factorial(3));

    char c2 ;
    do {
    /*loop body*/
    puts("Keep going? (y/n)");

    c2 = getchar();

    /* other processing */
    } while (c2 == 'y' /* && other conditions */); // Control+d to work (not enter)

    return 0;
}
