/* extern.c */
#include"header.h"
// extern int global; not the best practice

int func(void)
{
    static int test = 1;
    test++;
    printf("\n value of extern variable is [%d]\n",global);
    printf("\n value of static variable is [%d]\n", test);
    return 0;
}
