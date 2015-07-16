/* gcc -o func_pointerex02 func_pointerex02.c */

#include <stdio.h>

int add (int, int);
int subtract (int, int);
int do_math (int (*math_fn_ptr) (int, int), int, int);
int main();

int main()
{
  int result;
	
  result = do_math (add, 10, 5);
  printf ("Addition = %d.\n", result);
	
  result = do_math (subtract, 40, 5);
  printf ("Subtraction = %d.\n\n", result);
	
  return 0;
}

int add (int num1, int num2)
{
  return (num1 + num2);
}

int subtract (int num1, int num2)
{
  return (num1 - num2);
}

int do_math (int (*math_fn_ptr) (int, int), int num1, int num2)
{
  int result;
  printf ("\ndo_math here.\n");
  /* Call one of the math functions passed to us:
      either add or subtract. */
  result = (*math_fn_ptr) (num1, num2);
  return result;
}
