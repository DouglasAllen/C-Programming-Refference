#include <stdio.h>

int y = 1;

void
skip(char *msg)
{
  puts((msg + 6));
}

void
go_south_east(int lat, int lon)
{
  lat = lat - 1;
  lon = lon + 1;
}

void
fix_go_south_east(int *lat, int *lon)
{
  *lat = *lat - 1;
  *lon = *lon + 1;
}

/* If you declare an array argument 
    to a function, it will be treated as a 
    pointer. 
*/
void fortune_cookie(char msg[])
{
  printf("Message reads: %s\n", msg);
	/* sizeof(a pointer) returns
     4 on 32-bit operating systems and 8
     on 64-bit.
  */
	printf("msg occupies %i bytes\n", sizeof(msg));
}

int main()
{
	/* Variables are allocated storage in memory. */
	
	/* Local variables live in the stack. */ 

	/* x is stored in the stack */
	int x = 4;
  printf("x is stored at %p\n", &x);
	
	/* Global variables live in the globals section. */
	/* y is a global variable. see above. */
	printf("y is stored at %p\n", &y);
	
	/* Let's set sail. */
	int latitude = 32;
  int longitude = -64;
  go_south_east(latitude, longitude);
	/* Arrr! We haven't moved. */
  printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
	
	printf("x lives at %p\n", &x);

	/* Pointers are just variables that store memory addresses.  */
  /* The & operator finds the address of a variable.  */

	/* Get the address of x */
	int *address_of_x = &x;
	printf("address_of_x = %p\n", address_of_x);
	
	/* The * operator can read the contents
      of a memory address.
  */
	/* Read the contents of an address. */
	int value_stored = *address_of_x;
	printf("read address_of_x contents = %i\n", value_stored);
	
	/* The * operator can also set the
      contents of a memory address.
  */ 
	/* Change the contents of an address. */
	*address_of_x = 99;
	int new_value_stored = *address_of_x;
	printf("read address_of_x contents after change = %i\n", new_value_stored);

	/* Wind in the sails now, cap'n! */
	fix_go_south_east(&latitude, &longitude);
  printf("Avast! Now at: [%i, %i]\n", latitude, longitude); 

  char quote[] = "Cookies make you fat";
  fortune_cookie(quote);

  /* The sizeof operator returns the
      space taken by a piece of data.
  */
	/* You can also call sizeof for a data
      type, such as sizeof(int).
  */
  printf("size of int = %i\n", sizeof(int));
	printf("size of string = %i\n", sizeof("Turtles!"));
	
	/* The array variable points to the first 
      element in the array. 
  */
  printf("The quote string is stored at: %p\n", quote);
	printf("The quote string stored: %i bytes of data\n", sizeof(quote));
	printf("The quote string stored: %s at location %i\n", quote[sizeof(quote) - 1], sizeof(quote));

  int contestants[] = {1, 2, 3};
  int *choice = contestants;
  contestants[0] = 2;
  contestants[1] = contestants[2];
  contestants[2] = *choice;
  printf("I'm going to pick contestant number %i\n", contestants[2]);

	char s[] = "How big is it?";
  char *t = s;
	
	/* sizeof is different for array and 
      pointer variables. 
  */
	printf("size of s = %i\n", sizeof(s));
  printf("size of t = %i\n", sizeof(t));
	
	int doses[] = {1, 3, 2, 1000};
	 /* An array variable can be used as a pointer. */ 
	/* ...but array variables are not quite the same. */
  printf("Issue dose %i\n", 3[doses]);
	/* doses[3] == *(doses + 3) == *(3 + doses) == 3[doses] */

  int drinks[] = {4, 2, 3};

	printf("1st order: %i drinks\n", drinks[0]);
  printf("1st order: %i drinks\n", *drinks);
	
	printf("3rd order: %i drinks\n", drinks[2]);
  printf("3rd order: %i drinks\n", *(drinks + 2));

  char *msg_from_amy = "Don't call me!";
  skip(msg_from_amy);

  int nums[] = {1, 2, 3};
  printf("nums is at %p\n", nums);
  printf("nums + 1 is at %p\n", nums + 1);

  /* Array variables can't point to
      anything else.
  */
  /* This will give a compile error. */
  /* s = t; */
	
	char name[40];
  printf("Enter your name: ");
	scanf("%39s", name);
	
	int age;
  printf("Enter your age: ");
  scanf("%i", &age);

	


	return 0;
}
