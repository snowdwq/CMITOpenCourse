#include <stdio.h>
#define MSG1 "All your base belongs to us"
#define MSG2 "All your"
#define squared(x) x*x
#define squared2(x) (x*x)
#define squared3(x) (x)*(x)
#define squared4(x) ((x)*(x))

int main(void)
{
	puts("HELLO WORLD");

    char msg[] = "Hello world";

	puts(msg);
	// msg = "Hello worlD"; // not possible because arrays are constant pointers, same as say char const *msg = "Hello world";
    // puts(msg);

	puts("\x41");
	puts("\060");

	char msg2[] = MSG1;
	puts(msg2);

    // macro is just an alias for what it has defined
	double ans = 18.0/squared(2+1);
	double ans2 = 18.0/squared2(2+1);
	double ans3 = 18.0/squared3(2+1);
	double ans4 = 18.0/squared4(2+1);

	printf("%f\n", ans);
	printf("%f\n", ans2);
	printf("%f\n", ans3);
	printf("%f\n", ans4);

	return 0;
}
