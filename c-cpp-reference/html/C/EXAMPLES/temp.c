/*
Purpose: Find out the size of the different data types
Author:  M J Leslie
Date:    27-feb-94
*/

#include <stdio.h>
main()
{
					/*
					int/char   are 'type specifiers'
					short/long are 'type qualifiers'
					*/
  int i;

  printf("    short int is %2d bytes \n", sizeof(short int));
  printf("          int is %2d bytes \n", sizeof(int));
  printf("     long int is %2d bytes \n", sizeof(long int));
  printf("   signed int is %2d bytes \n", sizeof(signed int));
  printf(" unsigned int is %2d bytes \n", sizeof(unsigned int));
  printf("\n");
  printf("        float is %2d bytes \n", sizeof(float));
  printf("       double is %2d bytes \n", sizeof(double));
  printf("  long double is %2d bytes \n", sizeof(long double));
  printf("\n");
  printf("  signed char is %2d bytes \n", sizeof(signed char));
  printf("         char is %2d bytes \n", sizeof(char));
  printf("unsigned char is %2d bytes \n", sizeof(unsigned char));
}
