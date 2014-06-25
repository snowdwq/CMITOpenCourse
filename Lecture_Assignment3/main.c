/* main.c */
#include"header.h"

int global = 1; // the definition reserves space for the variable

int main(void)
{
    printf("\nInside main()\n");
    func();
    return 0;
}
