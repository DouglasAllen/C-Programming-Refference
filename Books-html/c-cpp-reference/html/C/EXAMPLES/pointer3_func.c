/*
 * Purpose: Program to demonstrate passing apointer to a character    
 *	    string to a function.
 * Author:  M J Leslie.
 * Date:    21-Apr-94
 */

int function1(char * array);

main()
{
  char array1[10]="987654321";	/* one less so the \0 will fit  */

  function1(array1);		/* call function		*/

  printf("%s\n", array1);	/* O/P the altered array. '5' will
				 * have been changed to 'x'     */
}

/************************************************************************/

function1(char * array)
{
  printf("%s\n", array); 	/* printf expects a pointer.	*/

  array +=4;			/* Modify the pointer.		*/
  *array = 'x';		        /* Modify the data pointed to
				 * by 'array'			*/
}
