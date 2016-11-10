/************************************************************************
 *
 * Purpose: To copy a file  (Unix 'cp' command).
 * Author:  M J Leslie
 * Date:    16-May-96
 *
 ************************************************************************/

#include <stdio.h>

main()
{
  int c;			/* Character read/written between files */
  FILE *IPFile;			/* Pointer to the I/P file. FILE is a 
				   structure  defined in <stdio.h>	*/
  FILE *OPFile;

				/* Open the file - no error checking done */
  IPFile = fopen("/etc/hosts","r");
  OPFile = fopen("/tmp/hosts","w");

				/* Read one character at a time, checking 
				   for the End of File. EOF is defined 
				   in <stdio.h>  as -1 			*/
  while ((c = fgetc(IPFile)) != EOF)
   {
   fputc(c, OPFile);		/* O/P the character 			*/
   }

  fclose(IPFile);		/* Close the files.			*/
  fclose(OPFile);		/* Close the files.			*/
}
