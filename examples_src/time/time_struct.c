#include <stdio.h>
#include <time.h>

void print_time(const struct tm* t)
{
	printf("%i\n%i\n%i\n%i\n%i\n%i\n%i\n",
	       t->tm_wday, t->tm_mon, t->tm_mday,
	       t->tm_hour, t->tm_min, t->tm_sec, t->tm_year);
}

struct get_time
{
	
};

int main()
{
	time_t now = time(NULL);
  struct tm * tp = gmtime(&now);
	/* quick check of time expected */
	puts(asctime(tp));

	print_time(tp);
}
