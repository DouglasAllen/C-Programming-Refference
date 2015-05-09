/************************************************************************
 *
 * Purpose: Program to demonstrate the 'for' statement.
 * Author:  M J Leslie
 * Date:    08/04/94
 *
 ************************************************************************/

#include <stdio.h>

main()
{
  int i,j;		/* Define integers 				*/
			  
			/* 'i' and 'j' get initalised on the 'for'.
			 * Then they both are incremented and decremented
			 * before 'i' is tested.
			 */
  for (i=1, j=10; i<=10; ++i, --j)
  {
    printf ("   i = %02d  j = %02d\n", i, j);
  }
}
/************************************************************************ 
   O/P will look like this:

   i = 01  j = 10
   i = 02  j = 09
   i = 03  j = 08
   i = 04  j = 07
   i = 05  j = 06
   i = 06  j = 05
   i = 07  j = 04
   i = 08  j = 03
   i = 09  j = 02
   i = 10  j = 01
**************************************************************************/
