/* limits.c: Illustrates integral limits */
/* Compile with:
  make limits CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("char: [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("short: [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("int: [%d, %d]\n", INT_MIN,  INT_MAX);
    printf("long: [%ld, %ld]\n", LONG_MIN, LONG_MAX);
    while( getchar() != '\n' ) { /*do nothing*/} ;
    getchar() ; /* wait */
    return 0;
}

