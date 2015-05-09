/************************************************************************
 *
 * Purpose: Program to demonstrate functions.
 * Author:  M J Leslie.
 * Date:    28-Feb-94
 *
 ************************************************************************/

int add( int, int); 			/* Function declaration 	*/

main()
{
  int i=1;
  printf("i starts out life as %d.", i);

  i = add(1, 1);			/* Function call       		*/

  printf(" And becomes %d after function is executed.\n", i);
}

/************************************************************************/

int add( int a, int b) 			/* Function definition 		*/
{
  int c;
  c = a + b;
  return c;
}
