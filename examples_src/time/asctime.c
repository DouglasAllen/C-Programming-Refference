/* gcc -Wall -g -o asctime asctime.c */

#include <stdio.h>
#include <string.h>
#include <time.h>

void print_date (char * title, struct tm * t)
{
	printf ("%s\n", title);
	printf ("Date : %d/%d/%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	printf ("Time : %d:%d:%d\n\n", t->tm_hour, t->tm_min, t->tm_sec);
}

int main()
{
	time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
	printf ("The current local time is: %s", ctime (&rawtime));
  timeinfo = localtime ( &rawtime );	
	/* quick check of time expected */	
	puts(asctime(timeinfo));	
  printf ( "The current local date/time is: %s", asctime (timeinfo) );
	print_date ("From tm struct", timeinfo);
	
	timeinfo = gmtime ( &rawtime );
	/* quick check of time expected */	
	puts(asctime(timeinfo));	
  printf ( "The current UTC date/time is: %s", asctime (timeinfo) );
	print_date ("From tm struct", timeinfo);
   
  return(0);
}