/* fun3.c: Illustrates a function prototype */
/* Compile with:
  make fun3 CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>

float avg(int, int);	/* Prototype */

int main() {
    int x, y;
    
    puts("Enter the first number:");
    scanf("%d", &x);
    puts("Enter the second number:");
    scanf("%d", &y);
    printf("The average is %.2f\n", avg(x,y));
    return 0;
}

float avg(int n, int m) {
    return (n + m) / 2.0;
}
