/* 
 * Date 13-Jun-94
 *
 * 	Pass 'struct' elements to a function.
 */
#include <stdio.h>

void display(char *name, int age);

/************************************************************************/

main ()
{
  struct { char name[20]; int age;} record;

  strcpy(record.name, "Joe Brown");
  record.age = 21;

  display (record.name, record.age);
}

/************************************************************************/

void display(char *name, int age)
{
  printf("name is %s \nage is %d \n", name, age);
}
