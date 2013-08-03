/* hello.c */
/* Compile with:
  make hello CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>

int main(void)
{
  printf("\nHello, world!\n");
  //~ while( getchar() != '\n' ) { /*do nothing*/} ;
	getchar() ; /* wait */
  return 0;
}