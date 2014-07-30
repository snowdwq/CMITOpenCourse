#include <stdio.h>
#include <stdlib.h>

int getn(int n)
{
    return n;
}

int getk()
{
    int k = 7;
    return k;
}

char* getmsg()
{
    char msg[] = "Hello world";
    return msg;
}

int main(void)
{

    int k = 5;
    printf("%d\n%d\n", getn(k), getk()); // why it works? // return by value :)
    puts(getmsg()); // it prints trash
    printf("%s\n", getmsg()); // it prints trash

    int arr[5] = {1, 2, 3, 4, 5};
    int* pa = arr;
    printf("%p \n %p\n", pa, &pa[1]);
    char* pc = (char*)pa;
    printf("%p \n %p\n %p\n", pc, &pc[1], &pc[4]);
    printf("%p \n %p\n", (int*)(pc+12), pa+3);
    printf("%p \n %p\n", (int*)(&pc[12]), &pa[3]);
    printf("%d\n", *(pa+4));
    return 0;
}
