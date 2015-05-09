#include <stdio.h>

int total;      /* total of all the numbers */
int current;    /* current value from the user */
int counter;    /* for loop counter */

char line[80];  /* Input from keyboard */

main() {
    total = 0;
    for (counter = 0; counter < 5; counter++) {
        (void)printf("Number? ");

        (void)fgets(line, sizeof(line), stdin);
        (void)sscanf(line, "%d", &current);
        total += current;
    }
    (void)printf("The grand total is %d\n", total);
    return (0);
}
