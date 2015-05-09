/* static.c */
/* Compile with:
  make static CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>

int count() {
    static int n = 0;
    return ++n;
}

int main() {
    int i;
    for (i = 0; i < 5; ++i)
        printf("%d ", count());
    return 0;
}

