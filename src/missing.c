/* missing.c */
/* Compile with:
  make missing CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>
#include <limits.h>

main() {
    float x = ULONG_MAX;    /* 4,294,967,295 */
    double y = ULONG_MAX;
    long double z = ULONG_MAX;

    printf("%f\n%f\n%Lf\n",x,y,z);

    while( getchar() != '\n' ) { /*do nothing*/} ;
    getchar() ; /* wait */
    return 0;
}

