#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef union
{
    int idata;
    float fdata;
    char* sdata;
} Data;

enum dtype {INT, FLOAT, CHAR};

typedef struct
{
    Data data;
    enum dtype t;
} variant;

int main(void)
{
    Data data;
    printf( "Memory size occupied by data : %lu\n", sizeof(data));
    data.idata = 10;
    data.fdata = 220.5;
    data.sdata = "Hello World"; // malloc(sizeof(char)*30);

    //strcpy( data.sdata, "C Programming");

    printf( "data.i : %d\n", data.idata);
    printf( "data.f : %f\n", data.fdata);
    printf( "data.str : %s\n", data.sdata);

    // free(data.sdata);

    variant var;
    printf("%lu\n", sizeof(var));

    return 0;
}
