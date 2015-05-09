/*****************************************************************
 *
 * Purpose: Program to demonstrate the 'strtok' function.
 * Author:  M J Leslie
 * Date:    23-Apr-94
 *
 ****************************************************************/

#include <stdio.h>
#include <string.h>

main()
{
				/* Copy the constant into the memory
				 * pinted to by 'test_string' 		*/
  char test_string[50]="string to split up";

	/* if 'test_string' is declared as below and the program will give a 
 	 * 'Segmentation fault' This is because test_string' is pointing
 	 * to a constant i.e. somethin that cant be changed. 	

	   char *test_string="string to split up"; 		*/
			
  char *sub_string;

					/* Extract first string	*/
  printf("%s\n", strtok(test_string, " "));

					/* Extract remaining 
					 * strings 		*/
  while ( (sub_string=strtok(NULL, " ")) != NULL)
  {
    printf("%s\n", sub_string);
  }
}
/*****************************************************************
 *
 * Program O/P will look like this...
 *
 *   string
 *   to
 *   split
 *   up
 *
 *****************************************************************/


