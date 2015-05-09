/**************************************************************************
 *
 * Purpose: Program to demonstrate the 'for' statement.
 * Author:  M J Leslie
 * Date:    26/01/94
 *
 **************************************************************************/

#include <stdio.h>

main()
{
  int i;			/* Define an integer */
			/*
			 * i=1 is executed the first time into the loop.
			 * i<=10 is then tested, if true, the block is executed. 
			 * ++1 is the increment, before i<=10 is retested.
			 */
  for (i=1; i<=10; ++i)
  {
    printf ("loop counter = %i\n", i);
  }
}
