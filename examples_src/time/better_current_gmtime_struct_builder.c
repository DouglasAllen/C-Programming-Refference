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
	now = time( NULL ); /* NULL is a control character */
	
	/* set up time ponter */
	struct tm *tp;
	tp = gmtime(&now);
	
	/* quick check of time expected */	
	printf("%s\n", asctime(tp));

	/* assign the current time struct from the time pointer */
	struct tm t = *tp;
	
	/* print the parts */
	print_struct_parts(&t);
	return 0;	
}

/* check the struct parts */
void print_struct_parts(struct tm* t)
{
	printf ("%i\n", t->tm_wday);
	printf ("%i\n", t->tm_mon);
	printf ("%i\n", t->tm_mday);
	printf ("%i\n", t->tm_hour);
	printf ("%i\n", t->tm_min);
	printf ("%i\n", t->tm_sec);
	printf ("%i\n", t->tm_year);
}
