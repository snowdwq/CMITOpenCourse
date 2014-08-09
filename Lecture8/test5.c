#include <stdlib.h>
#include <stdio.h>

#define MULTIPLIER 31
#define MAX_BUCKETS 1000

unsigned long hashstring(const char* str)
{
  unsigned long hash=0;
  while(*str)
    {
      hash= hash*MULTIPLIER+*str;
      printf("%s\n", str);
      printf("%c\n", *str);
      str++;
    }

  return hash%MAX_BUCKETS;
}

void test(char* str) // problematic when passing string literals, it should be const
{
    str[0] = 'b'; // str should be const in order to prohibit us to change it
}

int main(void)
{
    // int n = 50;
    // int array[n]; // gcc extension

    char* str = "alexis";

    int ints[] = {1, 2, 3}; // it is copies from read only .data (maybe .rodata) to array ints
    ints[1] = 5;
    printf("%d\n", *ints);

    int *arr = (int[]){3,1,4,5,2}; // (int[]) tells explicitly to the compiler to create an array of integers
    arr[2] = 11;
    int z;
    for(z=0;z<5;z++) {
        printf("%d ",arr[z]);
    }

    ++arr;
    printf("\ntest test %d\n", *arr);

    hashstring(str);

    // test("alexis"); // not permitted

    return 0;
}
