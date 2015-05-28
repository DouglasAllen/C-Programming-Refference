#include <time.h>
#include <stdio.h>
time_t start, stop;
clock_t ticks; long count;
int main()
{
	time(&start);
	
	ticks = clock( );
	//... do work here
	printf("I prefer sleeping to work...\n");
	sleep(1);
	
	time(&stop);
	
	double time_elapsed_in_seconds = (stop - start)/(double)CLOCKS_PER_SEC;
	printf("%.6f\n", difftime(stop, start));
	printf("%.6f\n", time_elapsed_in_seconds);
	
	return 0;
}