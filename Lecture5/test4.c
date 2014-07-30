#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[] = "This is a sample string";
    char * pch;
    printf ("Looking for the 's' character in \"%s\"...\n",str);
    pch=strchr(str,'s');

    while (pch!=NULL)
    {
        printf ("found at %lu\n",pch-str+1);
        pch=strchr(pch+1,'s');
    }

    char str2[20]; //  = "This is a test";
    str2[0] = '1';
    str2[1] = '2';
    // str2[2] = '\0';
    // maybe compiler here puts '\0' in the end or there is not anything else after local variable str2 in the stack

    printf("%s\n hm:%lu\n", str2, strlen(str2));

    // interesting things happen when I don't terminate strings with null characters
    // char arrays in different position in the stack compared to ints :)
    // http://stackoverflow.com/questions/1102049/order-of-local-variable-allocation-on-the-stack

    // int o = 5;
    // int h = 6;
    // int h2[20];
    /* char str3[20];

    int i = 0;
    char c;

    while(c = getchar() != '4')
    {
        str3[i] = c;
        i++;
    }

    str3[i] = '\0';
    printf("%d %lu", i, strlen(str3));
    */
    return 0;
}
