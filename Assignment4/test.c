#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// just wanted to find the "problems" of strtok()
int main(void)
{
   const char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;

   /* get the first token */
   token = strtok(str, s);

   /* walk through other tokens */
   while( token != NULL )
   {
      printf( "%s: %s\n", str, token );

      token = strtok(NULL, s);
   }

   return(0);
}

