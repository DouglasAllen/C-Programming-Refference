/************************************************************************ 
 *
 * Purpose: Passing a copy of a structure to a function.
 * Author:  M.J. Leslie
 * Date:    13-Jun-94
 *
 ************************************************************************/

#include <stdio.h>
					/* Declare a structure. It MUST 
					 * be declared before its use in
					 * function declarations.
					 */	
struct record_format { char name[20]; int age;}; 

void display(struct record_format);	/* function declaration		*/

/************************************************************************/

main ()
{
  struct record_format record;

  strcpy(record.name, "Joe Brown");
  record.age = 21;

  display (record);

				/*
				 * Print the contents of the  structure. 
				 * The original value of record.age has been
				 * retained.
				 */
  printf("name is %s \nage is %d \n", record.name, record.age);

}

/************************************************************************/

void display(struct record_format rec)
{
  printf("name is %s \nage is %d \n", rec.name, rec.age);
  rec.age=31;				/* change the value of a structure
					 * member.			*/
}
