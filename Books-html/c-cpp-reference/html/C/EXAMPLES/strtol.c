/****************************************************************
 *
 * Purpose: To show examples of the strtol function.
 * Author:  M.J. Leslie
 * Date:    06-Nov-94
 *
 ****************************************************************/

#include <stdlib.h>

main()
{
  char num[10];

				/* Test a valid number		*/
  strcpy(num,"13");

  printf("%s(Oct) is %i(Dec)\n", num, strtol(num, NULL,  8));
  printf("%s(Dec) is %i(Dec)\n", num, strtol(num, NULL, 10));
  printf("%s(hex) is %i(Dec)\n", num, strtol(num, NULL, 16));

  puts("----------------------------------");

				/* Test a slightly valid number
				 * Returns the same results as 
				 * above. 			*/
  strcpy(num, "13hzcd");

  printf("%s(Oct) is %i(Dec)\n", num, strtol(num, NULL,  8));
  printf("%s(Dec) is %i(Dec)\n", num, strtol(num, NULL, 10));
  printf("%s(hex) is %i(Dec)\n", num, strtol(num, NULL, 16));

  puts("----------------------------------");

				/* Test an invalid number
				 * Returns ZERO			*/
  strcpy(num, "hzcd");

  printf("%s(Oct) is %i(Dec)\n", num, strtol(num, NULL,  8));
  printf("%s(Dec) is %i(Dec)\n", num, strtol(num, NULL, 10));
  printf("%s(hex) is %i(Dec)\n", num, strtol(num, NULL, 16));


  puts("----------------------------------");

				/* Test 0 base.
				 * This will look at the number 
				 * and decide the base for its self!
				 */
  strcpy(num, "13");
  printf("%s is %i(Dec)\n", num, strtol(num, NULL, 0));

  strcpy(num, "013");
  printf("%s is %i(Dec)\n", num, strtol(num, NULL, 0));

  strcpy(num, "0x13");
  printf("%s is %i(Dec)\n", num, strtol(num, NULL, 0));

}

/****************************************************************
 *
 * Results of the program:
 *
 *	13(Oct) is 11(Dec)
 *	13(Dec) is 13(Dec)
 *	13(hex) is 19(Dec)
 *	----------------------------------
 *	13hzcd(Oct) is 11(Dec)
 *	13hzcd(Dec) is 13(Dec)
 *	13hzcd(hex) is 19(Dec)
 *	----------------------------------
 *	hzcd(Oct) is 0(Dec)
 *	hzcd(Dec) is 0(Dec)
 *	hzcd(hex) is 0(Dec)
 *	----------------------------------
 *	13 is 13(Dec)
 *	013 is 11(Dec)
 *	0x13 is 19(Dec)
 *
 ****************************************************************/
