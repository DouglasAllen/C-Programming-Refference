/* float.c: Illustrates floating-pt. limits */
/* Compile with:
  make float CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>
#include <float.h>

int main()
{
    printf("radix: %d\n", FLT_RADIX);
    printf("float: %d radix digits\n",FLT_MANT_DIG);
    printf("\t[%g, %g]\n", FLT_MIN, FLT_MAX);
    printf("double: %d radix digits\n",DBL_MANT_DIG);
    printf("\t[%g, %g]\n", DBL_MIN, DBL_MAX);
    printf("long double: %d radix digits\n",LDBL_MANT_DIG);
    printf("\t[%Lg, %Lg]\n", LDBL_MIN, LDBL_MAX);
    //~ while( getchar() != '\n' ) { /*do nothing*/} ;
    getchar() ; /* wait */
    return 0;
}

