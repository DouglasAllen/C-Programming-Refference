/************************************************************************
 *
 * Purpose: To demonstrate the 'bsearch' function.
 *
 * Author:  M.J. Leslie
 *
 * Date:    04-Jun-95
 *
 ************************************************************************/

#include <stdlib.h>

#define NUM 11

static int func (void *, void *);

/************************************************************************/

main()
{
	/* List of numbers.		*/
	int numbers[NUM]={3,4,7,9,11,13,15,17,19,21,23};
	int key=22;				/* number to find.		*/
	int * result;			/* Result of 'bsearch'		*/

	/* Search for 'key' in 'numbers'*/

	result = bsearch (&key, numbers, NUM, sizeof(numbers[0]), (void *)func);

	printf("%d ", key);
	(result) ? puts("found") : puts("not found"); 
}

/************************************************************************/

static int func (void *a, void *b)
{
	printf("%d %d \n", *(int *)a, *(int *)b);	/* Diagnistics.		*/

	/* Compare the two numbers	*/
	if (*(int *)a == *(int *)b) return(0);
	if (*(int *)a <  *(int *)b) return(-1);
	return (1);
}
