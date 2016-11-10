/************************************************************************
 *
 * Purpose: Program to demonstrate functions that have a variable
 *	    number of parameters.
 * Author:  M J Leslie.
 * Date:    28-Mar-94
 *
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>			/* va_list, va_arg, va_end	*/

int set(char *item, int num, ...);	/* Declare the function.        */

/************************************************************************/

main()
{
    char *item="pear";

    int   Ret;
     
    Ret = set (item,4, "apple", "pear", "banana", "grape");
     
    if (Ret)
    {
        printf ("%s found\n", item);
    }
    else
    {
        printf("%s not found\n", item);
    }
}

/************************************************************************/

int set(char *item, int num, ...)
{
    va_list ap;				/* define 'ap' It acts as a
					 * pointer to the undefined 
					 * variables.			*/
    int Ret=0;
    int Inc=0;                          /* Assume the worst.            */
    va_start(ap, num);			/* seed 'ap'			*/

    do
    {
        if ( item == va_arg(ap, char *))
        {
            Ret = 1;
        }
    } while ( Ret==0 && ++Inc < num);

    va_end(ap);				/* tidy up.			*/
    return (Ret);
}
