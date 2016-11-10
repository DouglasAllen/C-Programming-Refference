/************************************************************************
 *
 * Purpose: Program to demonstrate the 'getchar' function.
 * 	    The prog will read data entered via the keyboard. And return
 * 	    the number of characters entered. 
 * Author:  M. J. Leslie
 * Date:    08-May-94
 *
 ************************************************************************/

#include <stdio.h>

#define RETURN '\n'			/* \n == return in UNIX
					   \r == return in DOS		*/

main()
{
  int count=0;
  puts("Please enter some text.");
					/* Count the letters in the 'stdin'
					   buffer.			*/
  while ( getchar() != RETURN) count++;

  printf("You entered %d characters\n", count);
}
