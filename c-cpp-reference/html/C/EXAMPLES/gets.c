/**************************************************************************
 *
 * Purpose: Compare the action of gets and fgets reading data from STDIN.
 * Author:  M J Leslie
 * Date:    22-Apr-95
 *
 *************************************************************************/

#include <stdio.h>

main()
{
  char buff[80];			/* Input buffer.		*/

					/* Get data from the keyboard.	*/
  printf("\nplease enter text => ");

  gets(buff);
  
  printf("\nlength is %d #%s#\n", strlen(buff), buff);

					/* Get data from the keyboard.	*/
  printf("\nplease enter text => ");

  fgets(buff, sizeof(buff), stdin);
  
  printf("\nlength is %d #%s#\n\n",strlen(buff),  buff);
}

/*************************************************************************
 * 
 *  Example program run.
 *  --------------------
 * 
 * please enter text => abcd
 * 
 * length is 4 #abcd# 
 * 
 * please enter text => abcd
 * 
 * length is 5 #abcd
 * #
 *
 *************************************************************************/


