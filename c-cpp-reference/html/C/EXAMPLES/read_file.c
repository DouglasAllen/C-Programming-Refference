/************************************************************************
 *
 * Purpose: To display a file on the screen  (Unix 'cat' command).
 *	    Version 1
 *
 * to do:   Read file name from command line.
 *
 * Author:  M J Leslie
 * Date:    06-Feb-94
 *
 ************************************************************************/

#include <stdio.h>

main()
{
  int c;				/* Character read from the file.	*/
  FILE *ptr;			/* Pointer to the file. FILE is a
				   structure  defined in <stdio.h>	*/

				/* Open the file - no error checking done */
  ptr = fopen("/etc/hosts","r");
				/* Read one character at a time, checking 
				   for the End of File. EOF is defined 
				   in <stdio.h>  as -1 			*/
  while ((c = fgetc(ptr)) != EOF)
  {
    printf("%c",c);		/* O/P the character to the screen	*/
  }

  fclose(ptr);			/* Close the file.			*/
}
