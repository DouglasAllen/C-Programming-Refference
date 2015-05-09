/************************************************************************
 * 
 * problem: Display an Ascii table. Basic version
 * Author:  M J Leslie
 * Date:    12-Mar-94
 *
 ************************************************************************/

#include <stdio.h>			/* printf, putchar, fopen, fclose */

main()
{
int count;

for (count=0; count<=127; count++) 
   {
   printf("%2x %c \n", count, count); 	/* O/P hex and character formats */
   }
}
