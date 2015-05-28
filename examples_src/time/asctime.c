//~ struct tm {
   //~ int tm_sec;         /* seconds,  range 0 to 59          */
   //~ int tm_min;         /* minutes, range 0 to 59           */
   //~ int tm_hour;        /* hours, range 0 to 23             */
   //~ int tm_mday;        /* day of the month, range 1 to 31  */
   //~ int tm_mon;         /* month, range 0 to 11             */
   //~ int tm_year;        /* The number of years since 1900   */
   //~ int tm_wday;        /* day of the week, range 0 to 6    */
   //~ int tm_yday;        /* day in the year, range 0 to 365  */
   //~ int tm_isdst;       /* daylight saving time             */
//~ };

#include <stdio.h>
#include <string.h>
#include <time.h>

void print_date (char * title, struct tm* t)
{
	printf ("%s\n", title);
	printf ("Date : %d/%d/%d\n", t->tm_year, t->tm_mon, t->tm_mday);
	printf ("Time : %d:%d:%d\n\n", t->tm_hour, t->tm_min, t->tm_sec);
}

int main()
{
	time_t now;
  time( &now );
	
	struct tm t;	
  t.tm_year   = 115;
	t.tm_mon    = 4;
	t.tm_mday   = 19;
	t.tm_hour   = 13;
	t.tm_min    = 20;
  t.tm_sec    = 10.0;  
	t.tm_wday   = 1;

	puts(asctime(&t));	
	
	print_date("from struct tm t", &t);	
	
  /* Get the time (seconds since 1/1/70) */
  printf( "Date: %.24s GMT\n", asctime( gmtime( &now ) ));
	
	puts(asctime( gmtime( &now )));
   
  return(0);
}