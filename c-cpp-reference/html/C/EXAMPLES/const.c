/******************************************************************
 *
 * Purpose: Program to demonstrate const
 * Date:    03-Dec-96
 * Author:  M J Leslie.
 * Descrip: To be written.
 *
 ******************************************************************/

#include <stdio.h>

main()
{
  const int Men=10;

  Men = 20;             /* This will be failed by the compiler. */
}
