/*
Purpose: To display the times table. Fabber version with annotation.
Author:  M J leslie
Date:    26-Feb-94
*/

main()
{
				/* Define the variables			*/
int count1,count2;		/* General purpose counters 		*/
int value;			/* result of a multiply calc 		*/

				/* O/P a top bar			*/
printf("     "); 
for (count1 = 1 ; count1 <= 12 ; count1++)
   {
   printf ("%3d ",count1);
   }
printf("\n\n");

				/* O/P the table with a side bar.	*/

for (count1 = 1 ; count1 <= 12 ; count1++)
   {
   printf("%2d   ",count1); 
   for (count2 = 1 ; count2 <= 12 ; count2++)
      {
      value = count1 * count2;
      printf ("%3d ",value);
      }
   printf("\n");
   }
}
