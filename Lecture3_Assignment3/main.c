/* main.c */
#include"header.h"

int global = 1; // the definition reserves space for the variable
static int global2 = 3; // cannot extern it because it is static

int main(void)
{
    printf("%d\n", global2);
    printf("\nInside main()\n");
    func();
    func();
    return 0;
}
