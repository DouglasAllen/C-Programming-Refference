/* bitwise.c: Illustrates bitwise ops */
/* Compile with:
  make bitwise CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>

int main() {
    short int n = 0x00a4;   /* 00000000 10100100 */
    short int m = 0x00b7;   /* 00000000 10110111 */
    
    printf("n = %04x\n", n);
    printf("m = %04x\n", m);
    printf("n & m == %04x\n", n & m);
    printf("n | m == %04x\n", n | m);
    printf("n ^ m == %04x\n", n ^ m);
    printf("~n == %04x\n", ~n);
    printf("~m == %04x\n", ~m);
    printf("n << 3 == %04x\n", n << 3);
    printf("m << 3 == %04x\n", m << 3);
    printf("n >> 3 == %04x\n", n >> 3);
    printf("m >> 3 == %04x\n", m >> 3);
    //~ while( getchar() != '\n' ) { /*do nothing*/} ;
    getchar() ; /* wait */
    return 0;
}

