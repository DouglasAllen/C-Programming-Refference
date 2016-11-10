/*********************************************************************
 *
 * Purpose: Demonstrate the 'srand' and 'rand' functions
 * Author:  M.J. Leslie.
 * Date:    11=Nov-94
 *
 *********************************************************************/

#include <time.h>
#include <stdlib.h>

main()
{
  int rolls=4;
					/* This looks DISCUSTING!
					 * time returns a different value 
					 * on every execution. And so 
					 * changes the value passed to 
					 * srand. See CAST
					 * for an explanation of 
					 * (unsigned int) and (time_t)	*/
  srand((unsigned int)time((time_t *)NULL));

					/* Roll the dice.		*/
  while(rolls--)
  {
    printf("Dice value is %d\n", (rand()%6)+1);
  }
}
