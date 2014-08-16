#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

int main(void)
{
    int i = 0;
    printf("%d\n", ++i);
    printf("%f\n", atof("4.567"));
    printf("%d\n", atoi("44"));
    printf("%ld\n", atol("4567"));
    printf("%lld\n", atoll("344657"));

    char szOrbits[] = "686.97 365.24";
    char* pEnd;
    float f1, f2;
    f1 = strtof (szOrbits, &pEnd);
    printf("%s\n", pEnd);
    f2 = strtof (pEnd, NULL);
    printf ("One martian year takes %.2f Earth years.\n", f1/f2);

    char szNumbers[] = "1856892505 17b00a12b -01100011010110000010001101100 0x6fffff";
    char* pEnd2;
    long long int li1, li2, li3, li4;
    li1 = strtol (szNumbers, &pEnd2, 10);
    li2 = strtol (pEnd2, &pEnd2, 16);
    li3 = strtol (pEnd2, &pEnd2, 2);
    li4 = strtol (pEnd2, NULL, 0);
    printf ("The decimal equivalents are: %lld, %lld, %lld and %lld.\n", li1, li2, li3, li4);
    // strtoll
    // strtoul
    // strtoull
    // strtod
    // strtold

    printf("%d\n", RAND_MAX);

    int number;
    srand(5);
    number = rand() % 10 + 1;
    printf("%d\n", number);
    number = rand() % 10 + 1;
    printf("%d\n", number);
    number = rand() % 10 + 1;
    printf("%d\n", number);

    srand(time(NULL));
    number = rand() % 10 + 1;
    printf("%d\n", number);
    number = rand() % 10 + 1;
    printf("%d\n", number);

    assert(1);
    assert(0);

    return 0;
}
