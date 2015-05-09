/********************************************************************
 *
 * Purpose: Demonstrate getting parameters from the command line.
 * Author:  M J Leslie
 * Date:    27-Mar-94
 *
 ********************************************************************/

#include <stdio.h>

main(int argc, char *argv[])
{
  int count;

   /*  Main takes two variables 'argc' is the number of parms on the 
    *  command line and 'argv' is a pointer to each of the parameters.
    *
    *	int argc    -- integer number called 'argc'
    *	char *argv[] -- Character pointer array!
    */

  printf("%i parameters entered on the command line.\n", argc);

				/*
				 * progname		argc = 1
				 * progname parm1 parm2	argc = 3
				 */

				/* 
				 * We take 1 from argc because 
				 * the argv array starts at zero 
				 * an ends at argc -1
				 */

  for ( count = 0; count <= argc -1 ; count++)
  {
				/* printf expects a pointer 
				 * to the text 
				 */

    printf("parm %d is %s\n", count, argv[count]);
  }
}
