/* gcc -o ex01 ex01.c */
/* from pages 8 & 9 CH 3.3 Example 1 */

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