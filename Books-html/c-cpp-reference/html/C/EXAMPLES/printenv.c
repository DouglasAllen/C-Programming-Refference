/******************************************************************
 *
 * Purpose: Program to demonstrate the 'environ' variable
 *          by emulating the Unix printenv command.
 * Date:    21-May-96
 * Author:  M J Leslie.
 * Descrip: 'environ' is declared in stdlib.h and points to 
 *          a list of environmental variables.
 *
 ******************************************************************/

#include <stdlib.h>

main()
{
  int    Count;
  char   *Line;

  while(Line = *(environ+Count))
  {
    printf("%s \n", Line);
    Count++;
  }
}
