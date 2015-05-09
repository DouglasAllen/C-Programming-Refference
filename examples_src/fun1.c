/* fun1.c: Illustrates a C function */
/* Compile with:
  make fun1 CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>

float avg(int n, int m)
{
    return (n + m) / 2.0;
}

int main()
{
    int x, y;
    
    puts("Enter the 1st number:");
    scanf("%d", &x);
    puts("Enter the 2nd number:");
    scanf("%d", &y);
    printf("The average is %.2f\n", avg(x,y));
    return 0;
}

