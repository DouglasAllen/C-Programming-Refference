/************************************************************************ 
 *
 * Purpose: Create an array of structures.
 * Author:  M.J. Leslie
 * Date:    09-May-95
 *
 ************************************************************************/

#include <stdio.h>
					/* Declare a structure. It MUST 
					 * be declared before use.
					 */	
struct record_format
{
  char name[20];
  int age;
}; 

/************************************************************************/

main ()
{
  int count=0;

  struct record_format record[]=
  {
    {"Joe Brown", 21},
    {"James Dean", 34},
    {"David Williams", 54},
    {"Neil Harrison", 62},
    {"EOF", -1}
  };

				/*
				 * Print the contents of the  structure. 
				 */
  while( record[count].age != -1)
  {
    printf("name is %s \tage is %d \n", record[count].name, record[count].age);
    count++;
  }
}

/************************************************************************
 *
 * Program will produce:
 *
 * name is Joe Brown       age is 21 
 * name is James Dean      age is 34 
 * name is David Williams  age is 54 
 * name is Neil Harrison   age is 62 
 *
 *************************************************************************/



