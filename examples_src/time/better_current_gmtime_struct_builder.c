// better_current_gmtime_struct_builder.c
// compile with :
// gcc -Wall -g better_current_time_struct_builder.c -o better_current_time_struct_builder
#include <sys/time.h>
#include <time.h>
#include <stdio.h>

/* function declarations */
void print_struct_parts(struct tm* t);

int main()
{
	
	time_t now;
	
	/* set the time for now */
	now = time( NULL );	
	
	/* assign the current time struct from the time pointer */
	struct tm t = *tp;
	//~ struct tm *tp;
	tp = gmtime(&now);
	
	/* quick check of time expected */	
	printf("%s\n", asctime(tp));	
	
	/* print the parts */
	print_struct_parts(&t);
	
	return 0;	
}

/* check the struct parts */
void print_struct_parts(struct tm* t)
{
	printf("%s\n", "From tm struct");
	printf ("\tWeek Day\t: %i\n", t->tm_wday);
	printf ("\tMonth num\t: %i\n", t->tm_mon);
	printf ("\tMonth Day\t: %i\n", t->tm_mday);
	printf ("\tHour\t\t: %i\n", t->tm_hour);
	printf ("\tMinute\t\t: %i\n", t->tm_min);
	printf ("\tSecond\t\t: %i\n", t->tm_sec);
	printf ("\tYear\t\t\t: %i\n", t->tm_year);
}
