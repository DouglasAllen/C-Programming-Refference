#include <stdio.h>
#include <stdlib.h>

int main()
{
  // If you want to use strings, use %s
  // Good for programs where users can enter their name
  // will replace %s with Bucky
  printf("%s is best person ever \n", "Bucky");

  // Use %d for integers
  // will replace %d with 9
  printf("I ate %d corn-dogs last night \n", 9);

  // %f for numbers with decimal places (floating point values)
  // 6 decimal places by default
  // will replace %f with 3.141590
  printf("Value of pi is %f \n", 3.14159);

  // will replace %f with 3.14 (2 decimal)
  printf("Value of pi is %.2f \n", 3.14159);

  // will replace %f with 3.142  (3 decimal
  printf("Value of pi is %.3f \n", 3.14159);

  return 0;

}
