/* gcc -Wall -g -o gmtime_struct gmtime_struct.c */

#include <time.h>
#include <stdio.h>

/********** prototype **************/
void print_struct_parts(struct tm* t);
/* print the struct parts */
void print_struct_parts(struct tm * t)
{
	printf("%s\n", "From tm struct");
	printf ("\tWeek Day\t\t: %i\n", t->tm_wday + 1);
	printf ("\tMonth num\t\t: %i\n", t->tm_mon + 1);
	printf ("\tMonth Day\t\t: %i\n", t->tm_mday);
	printf ("\tHour\t\t\t: %i\n", t->tm_hour);
	printf ("\tMinute\t\t\t: %i\n", t->tm_min);
	printf ("\tSecond\t\t\t: %i\n", t->tm_sec);
	printf ("\tYear\t\t\t\t: %i\n", t->tm_year + 1900);
	printf ("\tYear day\t\t\t: %i\n", t->tm_yday + 1);
	printf ("\tDaylight savings?\t: %i\n\n", t->tm_isdst);
}

int main()
{
	
	time_t now;	
	/* set the time for now */
	time(&now);
	printf ("The current local time is: %s", ctime (&now));
	/* time pointer */	
	struct tm * tp;
	
	/* time pointer to local time */
  tp = localtime(&now);
	/* quick check of time expected */
  puts(asctime(tp));
	/* print the parts */
	print_struct_parts(tp);
	
	/* change time pointer to UTC time */
	tp = gmtime(&now);	
	/* quick check of time expected */		
	puts(asctime(tp));		
	/* print the parts */
	print_struct_parts(tp);
	
	return 0;	
}
//