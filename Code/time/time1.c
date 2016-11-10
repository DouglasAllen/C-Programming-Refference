#include <stdio.h>
#include <time.h>
int main ()
{
	time_t seconds;
	seconds = time (NULL);
	seconds = time (1);

	printf ("Number of hours since 1970 Jan 1st " \
             "is %ld \n", seconds/3600);
	return 0;
}