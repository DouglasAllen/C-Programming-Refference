/***********************************************************************
 *
 * Purpose: Program to demonstrate the 'sprintf' statement. This example 
 *          is a bit lame as the same effect can be seen with a 'printf'.
 *	    But, it does show a string being built and passed into a 
 *          function.
 * Author:  M J Leslie
 * Date:    10-Jul-94
 *
 ************************************************************************/

#include <stdio.h>

main()
{
    int i=1;		/* Define an integer variable.  		*/
    char message[80];	/* Text string 					*/

			/* format text and put into 'message' this a great
			 * improvement over using 'strcpy' and 'strcat' to
			 * build a text string.
			 */
    sprintf (message, "i is %i", i);
			/* I may be stating the obvious but a '\0' is
			 * put on the end of the string.		*/

    puts(message);	/* Display message				*/
}
