/************************************************************************ 
 *
 * Purpose: Demonstrate structures.
 * Author:  M.J. Leslie.
 * Date:    13-June-94
 *
 *
 ************************************************************************/

#include <stdio.h>
#include <string.h>

main ()
{
	/* Declare the structure.	*/
	struct { char name[20]; int age;} record ;

	/* Put some values into the 
	 * structure.			*/
	strcpy(record.name, "Joe Brown");
	record.age = 21;

	/* Display the contents of the
	 * structure.			*/

	printf("name is %s \nage is %d \n", record.name, record.age);
}

/************************************************************************
 *
 * Here is the result.
 *
 * 		name is Joe Brown 
 * 		age is 21 
 *
 ************************************************************************/

