/**************************************************************************
 *
 * Purpose: Give the exponent of a number.
 * Author:  M. J. Leslie
 * Date:    05-Apr-94
 *
 **************************************************************************/

#include <stdio.h>

int exponent(int);

main(int argc,char *argv[])
{
    int   user_val;
    char *progname;

    progname=argv[0];
					/* have we got one command line
					   parameter?  			*/
    if (argc != 2)
    {
        printf("%s syntax is:\n", progname);
        printf("\t%s num - where num is the number you ", progname);
        printf("require the exponent of.\n");
        exit();
    }
					/* y. Put it in a suitable variable */
    user_val = atoi(argv[1]);
					/* get and O/P its exponent.	*/
    printf(" The exponent of %d is %d \n", user_val, exponent(user_val));
}

/************************************************************************
		Get the exponent of an integer number.
*************************************************************************/

int exponent(int input)
{
    int count, result=1;
			/* 'result *= count' means 'result = result * count'
			    to fortran programmers...			*/
    for(count=1; count<=input; count++) result *= count;

    return result;
}
