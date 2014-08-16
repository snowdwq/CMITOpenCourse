#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLUSH_STDIN(x) {if(x[strlen(x)-1]!='\n'){do fgets(Junk,16,stdin);while(Junk[strlen(Junk)-1]!='\n');}else x[strlen(x)-1]='\0';}

char Junk[16]; // buffer for discarding excessive user input,
               // used by "FLUSH_STDIN" macro

int main(void)
{
    char userInput[8]; // change array size to any arbitrary value
    printf("input a string and hit <enter>.  A maximum of %lu characters will be recorded.\n",sizeof(userInput)-1);
    fgets(userInput,sizeof(userInput),stdin);
    // FLUSH_STDIN(userInput);    // strip newline, flush extra chars
    printf("the first %lu characters are \"%s\", characters still there.\n", strlen(userInput),userInput);
    fgets(userInput,sizeof(userInput),stdin);
    printf("the first %lu characters are \"%s\", characters still there .\n", strlen(userInput),userInput);
    fgets(userInput,sizeof(userInput),stdin);
    FLUSH_STDIN(userInput);    // strip newline, flush extra chars
    printf("the first %lu characters are \"%s\", any others have been discarded.\n", strlen(userInput),userInput);
    fgets(userInput,sizeof(userInput),stdin);
    FLUSH_STDIN(userInput);    // strip newline, flush extra chars
    printf("the first %lu characters are \"%s\", any others have been discarded.\n", strlen(userInput),userInput);

    return 0;
}
