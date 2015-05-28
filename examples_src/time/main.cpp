// compile with
// g++ -x c -std=c11  -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors main.cpp -lm  && ./a.out

#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>
#include <stdio.h>
 
int main(void)
{
    struct tm 
	  tm = *localtime(&(time_t){time(NULL)});
    printf("%s", asctime(&tm));
		
		char *asctime(const struct tm *timeptr);
 
#ifdef __STDC_LIB_EXT1__
    char str[26];
    asctime_s(str, sizeof str, &tm);
    printf("%s", str);
#endif
}