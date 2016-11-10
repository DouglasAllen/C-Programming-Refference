/*
 * Purpose: Program to demonstrate passing an int array to a function.
 * Author:  M J Leslie.
 * Date:    14-Apr-94
 */

void add(int swap[3][2]); 		/* Function declaration	*/
void display(int array[3][2]); 		/* Function declaration	*/

main()
{
  int i[3][2]=
  {
    {1,2},			/* array declaration 	*/
    {3,4},
    {5,6}
  };

  display(i);				/* i is a pointer	*/

  add(i);

  display(i);
}

/***************************************************************/

void add(int swap[3][2]) 		/* Function definition 	*/
{
  int temp,i;

  for (i=0; i<3; i++)
  {
    temp       = swap[i][0];
    swap[i][0] = swap[i][1];
    swap[i][1] = temp;
  }
  return;
}

/***************************************************************/

void display(int array[3][2]) 		/* Function definition 	*/
{
  int count=0,count1=0;

  for (count=0;count<3;count++)
    for (count1=0;count1<2;count1++)
      printf("%d ", array[count][count1]);
  puts("");
}
