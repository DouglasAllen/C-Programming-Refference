#include <stdio.h>
#include <time.h>

int main ()
{
   time_t seconds;

   seconds = time(NULL);
   printf("Hours since January 1, 1970 = %ld\n", seconds / 3600.0);
	
	time_t sec;
  time(&sec);
  printf("This line executed at %.24s.\n", ctime(&sec));
	puts(ctime(&sec));
  
   return(0);
}