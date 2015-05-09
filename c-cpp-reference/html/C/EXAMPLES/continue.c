/**************************************************************************
 *
 * Purpose: To filter some records. 
 * 	    Demonstrates the 'continue', 'feof' & 'fgets' statemnts.
 * Author:  M J Leslie
 * Date:    07-Jun-94
 *
 *************************************************************************/

#include <stdio.h>

main()
{
  char data[80];		/* Record read from the file.		*/
  FILE *ptr;			/* Pointer to the file. FILE is a 
				   structure  defined in <stdio.h>	*/

				/* Open the file - no error checking done */
  ptr = fopen("/etc/hosts","r");
				/* Read one record at a time, checking 
				   for the End of File. EOF is defined 
				   in <stdio.h>  as -1 			*/

  while (feof(ptr) == 0)
  {
    fgets(data, 80, ptr);	/* Read next record			*/
    if (data[0] == '#') continue; /* filter out the comments		*/
    printf("%s",data);	/* O/P the record to the screen		*/
  }

  fclose(ptr);			/* Close the file.			*/
}
