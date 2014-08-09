#include <stdio.h>

int main(void)
{
    int arr[ ] = {1,2,3,4,5,2};
    printf("sizeof(arr) = %lu\n",sizeof(arr));
    printf("arr = %p, arr+1 = %p\n\n", arr, (arr+1));
    printf("sizeof(&arr) = %lu\n",sizeof(&arr));
    printf("&arr = %p, (&arr)+1 = %p\n", &arr, (&arr+1));
    return 0;
}
