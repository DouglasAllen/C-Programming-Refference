/************************************************************************
 *
 * Purpose: Program to demonstrate passing a pointer to a scalar to 
 *	    a function.
 * Author:  M J Leslie.
 * Date:    11-Apr-94
 *
 ************************************************************************/

void add(int*); 			/* Function declaration 	*/

main()
{
  int i=4;				/* variable declaration 	*/
  int* ptr;				/* int pointer			*/

  ptr = &i;				/* 'ptr' now contains the
					   address of 'i'		*/

  printf("i starts out life as %d.\n", i);
  printf("             *ptr is %d.\n", *ptr);

  add(ptr); 				/* Function call       		*/

  printf("            i is now %d.\n", i);
}

/************************************************************************/

void add(int *ptr)	 		/* Function definition 		*/
{
  ++*ptr;				/* Add 1 to the value
					 * pointed too by 'ptr'		*/
  return;
}
