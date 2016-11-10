/*****************************************************************
 *
 * Purpose: Program to demonstrate the 'strstr' function.
 * Author:  M J Leslie
 * Date:    18-Jun-94
 *
 *****************************************************************/

#include <stdio.h>
#include <string.h>

main()
{
  char string[]="string to search";
  char   test[]="sear";
			
			/* strstr returns a pointer into 'string'
			 * if 'test' is found' if not found, NULL 
			 * is returned.				*/
 
  if (strstr(string, test)) puts("String found");
	
}
