#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int
main()
{
	struct timeval t0;
	struct timeval t1;
	gettimeofday(&t0, 0);
	
	char buffer[30];
	time_t curtime;
	struct timeval tv;
	gettimeofday(&tv, NULL); 
	curtime=tv.tv_sec;
	
	strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curtime));
	printf("%s%ld\n",buffer,tv.tv_usec);
	
  gettimeofday(&t1, 0);
  long elapsed1 = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
	long long elapsed2 = (t1.tv_sec-t0.tv_sec)*1000000LL + t1.tv_usec-t0.tv_usec;
	printf("%ld\n", elapsed1);
	printf("%ld\n", elapsed2);
	
}
