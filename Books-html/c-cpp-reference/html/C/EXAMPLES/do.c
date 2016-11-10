/************************************************************************
 *
 * Purpose: Program to demonstrate the 'do' statement.
 * Author:  M J Leslie
 * Date:    26-Jan-94
 *
 ************************************************************************/

#include <stdio.h>

main()
{
  int i=1;		/* Define an integer variable.  		*/

			/*
			 * The block is executed. Then the i <= 10 
			 * expression is evaluated. If TRUE the block 
			 * is executed again.
			 */
  do
  {
    printf ("i is %i\n", i);
    i++;
  } while (i <= 10);

}
