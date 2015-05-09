/************************************************************************
 *
 * Purpose: To show fprintf in action.
 * Author:  M J Leslie
 * Date:    15-May-96
 * Use:     The program takes data from STDIN and sends it to a file.
 *          An example use would be.
 *	    
 *          	cat /etc/hosts | fprintf
 *
 ************************************************************************/

#include <stdio.h>

main()
{

  FILE 	*Ptr;

  char	 Line[256];

  /* ...	Open a file for output. */

  Ptr = fopen("/tmp/OutputFile", "w");

  while(gets(Line))		/* Get data from stdin */
  {
    fprintf(Ptr, "%s\n", Line);	/* Send data to file.  */
  }

  fclose(Ptr);
}
