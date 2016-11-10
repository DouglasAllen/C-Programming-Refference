	// current_gmtime_struct_builder.c
	// compile with :
	// gcc -Wall -g current_time_struct_builder.c -o current_time_struct_builder
	
	#include <time.h>
	#include <stdio.h>

	#define LEN 3 /* at least 3 for the NULL end */

	/* function declarations */
	void print_date (struct tm* t);

	int toInteger(char a[]);

	int main()
	{
		/* set up a small string buffer */
		//~ char buf[LEN];
		/* an array of time formats for strftime */
		//~ char *formats[7] = {"%w", "%m", "%d", "%H", "%M", "%S", "%y"};
		//~ int count = sizeof formats / sizeof *formats;
		
		time_t now;
		/* set the time for now */
		now = time( NULL ); /* NULL is a control character */
		
		/* set up time ponter */
		struct tm *tp;
		tp = gmtime(&now);
		/* quick check of time expected */	
		printf("%s\n", asctime(tp));
		
		/* gather the time parts into an array of integers */
		//~ int t_parts[7];
		//~ int i;
		//~ for(i=0; i < count; i++) 
		//~ {
			//~ strftime(buf, LEN, formats[i], tp);
			//~ t_parts[i] = toInteger(buf); 
		//~ }

		/* build the current time struct from the time parts */
		struct tm t = *tp;
		//~ struct tm t;
		//~ t.tm_wday = t_parts[0]; 
		//~ t.tm_mon = t_parts[1] - 1; 
		//~ t.tm_mday = t_parts[2];  
		//~ t.tm_hour =  t_parts[3]; 
		//~ t.tm_min =  t_parts[4]; 
		//~ t.tm_sec =  t_parts[5];
		//~ t.tm_year = t_parts[6] + 100;
		
		//~ puts(asctime(&t));
		//~ print_date(&t);
	  printf("%i\n", t.tm_year);
		return 0;	
	}

	/* seperate time struct parts to date and time */
	void print_date (struct tm* t)
	{
		printf ("Date : %i/%i/%i\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
		printf ("Time : %i:%i:%i\n\n", t->tm_hour, t->tm_min, t->tm_sec);
	}

	/* convert numeric strings to their integer values */
	int toInteger(char a[])
	{
		int c, n = 0;

		for (c =0; a[c] != '\0'; c++) {
			n = n * 10 + a[c] - '0';
		}
	 
		return n;
	}