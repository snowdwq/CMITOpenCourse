/* fopen example */
#include <stdio.h>

int main (void)
{
    FILE * pFile;
    pFile = fopen("file1.txt","w");
    if(pFile!=NULL)
    {
        fputs("fopen example", pFile);
        fclose(pFile);
    }

    printf("This text is redirected to stdout\n");
    pFile = freopen("file.txt", "w+", stdout);
    printf("This text is redirected to file.txt\n");
    fclose(pFile);

    return 0;
}
