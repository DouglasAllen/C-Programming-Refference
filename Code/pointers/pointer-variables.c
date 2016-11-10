#include <stdio.h>

int main()
{
	int x;
  printf("size of int pointer %i\n", sizeof(&x));
	char *mystring;
	printf("size of char pointer %i\n", sizeof(&mystring));
	long *along;
	printf("size of long pointer %i\n", sizeof(&along));
	short *ashort;
	printf("size of short pointer %i\n", sizeof(&ashort));
}