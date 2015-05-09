/****************************************************************
 *
 * Purpose: Program to demonstrate the 'if' statement.
 * Author:  M J Leslie
 * Date:    26-Feb-94
 *
 ****************************************************************/

#include <stdio.h>

main()
{
  int i=1;	/* Define an integer variable. 			*/

		/*
		 * i == 1 expression is evaluated. If TRUE the 
		 * first block is executed.
		 * if i == 1 is FALSE the optional else block 
		 * is executed 					*/

  if (i == 1)
  {
    puts ("i is equal to 1\n");
  }
  else
  {
    puts("i is NOT equal to 1");
  }
}
