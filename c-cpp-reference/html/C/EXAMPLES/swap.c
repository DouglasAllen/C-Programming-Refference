/******************************************************************
 *
 * Purpose: Program to demonstrate the use of ^ (XOR).
 * Date:    03-Dec-96
 * Author:  M J Leslie.
 * Descrip: The contents of two variables are swapped without
 *          the use of a temorary variable  
 *
 ******************************************************************/

#include <stdio.h>

main()
{

  int    	One = 20;
  int		Two = 12;

  printf("One = %d Two = %d\n", One, Two);

  One ^= Two;
  Two ^= One;
  One ^= Two;

  printf("One = %d Two = %d\n", One, Two);
}
