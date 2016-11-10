/************************************************************************
 *
 * Purpose: To show ... in action. This operator (?) allows us to pass
 *	    a variable number of parameters to a function, 'printf' 
 *	    uses ...
 * Author:  M.J. Leslie
 * Date:    09-Jul-94
 *
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>			/* va_list, va_arg, va_end	*/

int set(char *item, int, num, ...);

/************************************************************************/

main()
   {
   char *item="pear";

   (set (item,4, "apple", "pear", "banana", "grape") )
	? printf ("%s found\n", item) : printf("%s not found\n", item);

   }

/************************************************************************/

int set(char *item, int num, ...)
   {
   va_list ap;				/* define 'ap' It acts as a pointer 
					 * to the undefined variables.	*/
   int ok=0;
   int inc=0;
   va_start(ap, num);			/* seed 'ap'			*/

   do {
      if ( item == va_arg(ap, char *)) ok=1;
      } while ( ok==0 && ++inc < num);

   va_end(ap);				/* tidy up.			*/
   return (ok);
   }
