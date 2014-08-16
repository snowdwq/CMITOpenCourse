#include <stdio.h>

int main()
{
    FILE *st;
    char  buf[20];

    st = fopen("feof.fil", "r");
    if (st != NULL)
    {
        // it is wrong in case an error happens EOF never reached
        while (!feof(st))
        {
            fgets(buf, 20, st);
            puts(buf);
        }
        fclose(st);
    }
    return 0;
}
