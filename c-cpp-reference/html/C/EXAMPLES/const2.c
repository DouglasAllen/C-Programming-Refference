/*******************************************************************
 *
 * Purpose: 'const' example. This code shows that making a
 *          variable 'const' only tells the compiler to not
 *          allow reassignment of the variable. The data is not
 *          in a special location, it can still be altered.
 *
 *          This code may cause compiler warning messages
 *          but will compile and run.
 *
 * Author:  M J Leslie.
 * Date:    03-Mar-97
 *
 *******************************************************************/

main()
{
  const int  Men   = 10;
  int       *Women = &Men;

  *Women = 20;

  printf("There are %d men\n", Men);
  
}

/******************************************************************* 
 *
 * Result.
 *
 * There are 20 men
 *
 *******************************************************************/
