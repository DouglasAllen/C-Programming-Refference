/* gcc -o ex02 ex02.c */
/* from pages 12 & 13 Ch 4.2 Function examples & 4.3 Functions with values */ 

#include <stdio.h>

/**************************************/
/* Add a and b */
void add_two_numbers (int a, int b)
{
  int c;
  c = a + b;
  printf ("%d\n", c);
}

int calculate_bill (int a, int b, int c)
{
  int total;
  total = a + b + c;
  return total;
}


int main()
{
  int var1, var2;
  var1 = 1;
  var2 = 53;
  add_two_numbers (var1, var2);
  add_two_numbers (1, 2);
	
	int bill = calculate_bill (1, 2, 3);

  return 0;
}

