#include <stdio.h>

int total;      /* total of all the numbers */
int current;    /* current value from the user */
int counter;    /* while loop counter */

char line[80];  /* Line from keyboard */

main() {
    total = 0;

    counter = 0;
    while (counter < 5) {
        (void)printf("Number? ");

        (void)fgets(line, sizeof(line), stdin);
        (void)sscanf(line, "%d", &current);
        total += current;

        counter++;
    }
    (void)printf("The grand total is %d\n", total);
    return (0);
}
