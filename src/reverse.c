/* reverse.c */
/* Prints an input sequence backwards. */
/* Compile with:
  make reverse CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>
#define SIZE 20

int main() {
    int i, n;
    int nums[SIZE];
    
    /* Read numbers into array. */
    /* Stop when 0 is found */
    for (n = 0; n < SIZE; ++n) {
        int input;
        scanf("%d", &input);
        if (input == 0)
            break;
        nums[n] = input;
    }
    
    for (i = n-1; i >= 0; --i)
        printf("%d ", nums[i]);
    return 0;
}

