/* gcc -o ex01 ex01.c */

#include <stdio.h>

/***********************************/
/* Funtion declaration */
do_little()
{
	/* This function does little. */
	printf("Function 'do_little' completing.\n");
}
/***********************************/

int main()
{
	do_little();
	printf("Function 'main' completing.\n");
	return 0;
}