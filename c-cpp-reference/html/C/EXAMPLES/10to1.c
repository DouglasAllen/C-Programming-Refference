
/******************************************************************* 
 *
 * Purpose: Count down from 10 to 1 in steps of 1
 * Author:  M J Leslie.
 * Date:    02-Feb-94
 *
 *******************************************************************/

   			/*			version 1          */

#include <stdio.h>

main()
{
    int a=10;
    while (a >= 1)
    {
        printf("a is %2d\n",a);
        a=a-1;
    }
}

/*******************************************************************/

   			/*			version 2          */

main()
{
    a =11;
    while (0 < (a = a - 1) )
    {
        printf("a is %2d\n",a);
    }
}

/*******************************************************************/

   			/*			version 3          */

main()
{
   			/*
			 * This works because the 'while' loop
			 * will keep spinning while 'i' is TRUE.
        		 * That is while 'i' is NOT equal to 0
   			 */

    a=11;
    while (i)
    {
        printf ("%i",i=i-1);
    }
}
