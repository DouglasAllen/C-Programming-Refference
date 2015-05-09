/******************************************************************
 *
 * Purpose: Program to demonstrate the 'while' statement.
 * Date:    20-Feb-94
 * Author:  M J Leslie.
 *
 ******************************************************************/

#include <stdio.h>

main()
{
    int i=1;  /* Define an integer variable. */
         
    /*
     * i <= 10 expression is evaluated. If TRUE the 
     * block is executed.
     */

    while (i <= 10)
    {
        printf ("i is %i\n", i);
        i++;
    }
}
