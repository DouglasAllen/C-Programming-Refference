/* lab2.c */
/* Compile with:
  make lab2 CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>

int main()
{
    float x;
    int n;
    
    printf("Enter a real number: ");
    fflush(stdout);
    scanf("%f", &x);
    n = (int)(x + 0.5);
    printf("%f rounded == %d\n", x, n);
    while( getchar() != '\n' ) { /*do nothing*/} ;
    getchar() ; /* wait */
    return 0;
}

