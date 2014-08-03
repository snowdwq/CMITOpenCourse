#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct flag
{
    unsigned int is_colour:1;
    unsigned int has_sound:1;
    unsigned int is_ntsc:1;
};

struct
{
  unsigned int age : 3;
} Age;

int main(void)
{
    struct flag myflag;
    printf("%lu\n", sizeof(struct flag) /*, sizeof(myflag.has_sound) not even compiled */);

    Age.age = 4;
    printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
    printf( "Age.age : %d\n", Age.age );

    Age.age = 7;
    printf( "Age.age : %d\n", Age.age );

    Age.age = 8;
    printf( "Age.age : %d\n", Age.age );

    int i,n;
    int * pData;
    printf ("Amount of numbers to be entered: ");
    scanf ("%d",&i);
    pData = (int*) calloc (i,sizeof(int));
    if (pData==NULL) exit (1);
    for (n=0;n<i;n++)
    {
        printf ("Enter number #%d: ",n+1);
        scanf ("%d",&pData[n]);
    }
    printf ("You have entered: ");
    for (n=0;n<i;n++) printf ("%d ",pData[n]);
        free (pData);

    return 0;
}
