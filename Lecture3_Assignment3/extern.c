/* extern.c */
#include"header.h"
// extern int global; not the best practice

int func(void)
{
    printf("\n value of extern variable is [%d]\n",global);
    return 0;
}
