/* gcc -o ex03 ex03.c */
/* from pages 13 & 14 Ch 4.4 Function prototyping */

#include <stdio.h>

/********************************************/
/* Prototypes */
void print_stuff (int foo, int bar);
int calc_value (int bas, int quux);

void print_stuff (int foo, int bar)
{
  int var_to_print;
  var_to_print = calc_value (foo, bar);
  printf ("var_to_print = %d\n", var_to_print);
}

int calc_value (int bas, int quux)
{
  return bas * quux;
}

/* Main */
int main()
{
  print_stuff (23, 5);
  return 0;
}

