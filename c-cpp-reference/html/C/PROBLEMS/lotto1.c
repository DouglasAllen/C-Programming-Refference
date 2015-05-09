/************************************************************************
 *
 * Purpose: First attempt at a lottery number selector.
 * Author:  M.J. Leslie.
 * Date:    17-Nov-94
 * Description: Any 6 random numbers from 1 to 49 are displayed. 
 * Futures: Filter duplicates.
 * 	    Sort the result.
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERS 6

/************************************************************************/
main()
   {
   int num;

   printf("\n\nLOTTERY CRACKER V1.0\n");
   printf("--------------------\n\n");
   printf("\tPossible winning ticket number is ");
						/* New starting point
						 * for the random numbers
						 */
   srand((unsigned int)time((time_t *)NULL));

						/* Display any 6 numbers.
						 * Duplicates are not filtered.
						 */
   for (num=0; num < NUMBERS; num++) 
      {
      printf(" %02d", (rand()%49)+1);
      }

   puts("");
   puts("");
   }
