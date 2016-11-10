/* gcc -o func_pointerex01 func_pointerex01.c */

#include <stdio.h>

//~ void fred();
void fred()
{
  printf("fred here!\n");
}

//~ void barbara ( void (*function_ptr)() );
void barbara ( void (*function_ptr)() )
{
  /* Call fred */
  (*function_ptr)();
}

int main();

int main()
{
  barbara (fred);
  return 0;
}
