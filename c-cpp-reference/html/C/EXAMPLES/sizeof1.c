/***************************************************************
 *
 * Purpose: Find out the size of the different data objects
 * Author:  M J Leslie
 * Date:    03-Sep-94
 *
 ***************************************************************/

#include <stdio.h>


main()
{
  char array[10];
  struct s 
  {  
    int a;
    float b;
  } structure;


  printf(" array  is %i\n", sizeof array);
  printf(" struct is %i\n", sizeof structure);
}

/*****************************************************************
 * array  is 10
 * struct is 8
 *****************************************************************/
