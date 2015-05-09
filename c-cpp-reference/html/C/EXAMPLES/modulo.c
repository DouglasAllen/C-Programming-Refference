 
/************************************************************************
 *
 * Purpose: Program to demonstrate the '%' operator.
 * Author:  M J Leslie
 * Date:    19-Mar-94
 *
 ************************************************************************/

#include <stdio.h>

main()
{
  int i,j;
				/* The modulo is the remainder of 
				   after an integer division	*/

  printf("14 modulo 7 (14%%7) is %i\n", 14%7);		/* answer is 0 	*/
  printf("15 modulo 7 (15%%7) is %i\n", 15%7);		/* answer is 1 	*/

  i=10; j=6;
  
  printf("%i modulo %i (%i%%%i) is %i\n",i,j,i,j,i%j);	/* answer is 4 	*/
}
