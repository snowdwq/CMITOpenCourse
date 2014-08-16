// In files open for update (i.e., open for both reading and writing), the stream shall be flushed after an output operation before performing an input operation. This can be done either by repositioning (fseek, fsetpos, rewind)
// or by calling explicitly fflush, like in this example:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char mybuffer[80];
int main()
{

    int k = 1;
    k = k << 1;

    printf("%d\n", k);

    FILE * pFile;
    pFile = fopen ("example3.txt","r+");
    if(pFile == NULL) perror("Error opening file");
    else
    {
        fputs("test", pFile); // every write/read moves the position indicator
        fflush(pFile);    // flushing or repositioning required
        printf("%ld\n", ftell(pFile));
        fseek(pFile, 0, SEEK_SET /*SEEK_CUR*/); // need to go to the beginning of the file.
        // fseek (pFile, 0, SEEK_END);
        printf("%ld\n", ftell(pFile));
        // fflush(NULL);
        fgets(mybuffer,80,pFile);
        printf("%ld\n", ftell(pFile));
        fseek (pFile, 0, SEEK_END);
        printf("%ld\n", ftell(pFile));
        puts(mybuffer);
        fclose(pFile);
    }

    char buff[1024];

    memset(buff, '\0', sizeof(buff));

    fprintf(stdout, "Going to set full buffering on\n");
    setvbuf(stdout, buff, _IOFBF, 1024);

    fprintf(stdout, "This is tutorialspoint.com\n");
    fprintf(stdout, "This output will go into buff\n");
    fflush(stdout);

    fprintf(stdout, "and this will appear when programm\n");
    fprintf(stdout, "will come after sleeping 5 seconds\n");

    sleep(5);

    return 0;
}
