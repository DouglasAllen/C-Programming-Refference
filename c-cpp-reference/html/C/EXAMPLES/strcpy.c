/*
 * Purpose: Program to demonstrate the 'strcpy' function.
 * Author:  M J Leslie
 * Date:    12-Mar-94
*/

#include <string.h>	/* strcpy */

main()
{
  char text1[20]="martin";		/* string buffer	*/
  char text2[20]="leslie";		/* string buffer	*/

  printf (" original string contents are: %s\n", text1);
					/* Copy text2 into text1. 
					   If text1 is smaller that text2
					   it will probably overwrite
					   something!		*/
  strcpy(text1, text2);
  printf (" new string contents are: %s\n", text1);

  strcpy(text1, "linux");
  printf (" final string contents are: %s\n", text1);

}
