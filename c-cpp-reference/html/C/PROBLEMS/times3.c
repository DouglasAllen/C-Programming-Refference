#include <stdio.h>

main()
{
  unsigned Inc;

  for (Inc=1; Inc <= 144; Inc++)
  {
    printf("%3d%c", Inc, (Inc%12)?' ':'\n');
  }

