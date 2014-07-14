#include <stdio.h>

int main()
{
    char c;
    while((c=getchar())!=EOF/*1*/)
    {
        //c=getchar();
        if(c>='A' && c<='Z')
            c=c-'A'+'a';
        putchar(c);
    }

    /*c=getchar();
    putchar(c);
    c=getchar();
    putchar(c);*/

    printf("%d %% \\ \"\n", 10);

    char str[] = "hello"; // the compiler makes everything
    char str2[10] = "hello"; // make sure that the array is big enough
    char str3[] = {'h','e','l','l', 'o','\0'};

    printf("%s, %s, %s \n", str, str2, str3);
    // str = "test"; not correct, see previous lecture about differences of pointers and arrays

    printf("%d\n", strcmp("A","a"));
    printf("%d\n", strcmp("IRONMAN","BATMAN"));
    printf("%d\n", strcmp("aA","aA"));
    printf("%d\n", strcmp("aA","a"));


    char str4[20], str5[30];

    printf("Enter name: ");
    scanf("%s", str4);

    printf("Enter your website name: ");
    scanf("%s", str5);

    printf("Entered Name: %s\n", str4);
    printf("Entered Website:%s", str5);

    return 0;
}
