#include <stdio.h>
char  line[100];/* line of data from the input */

int   result;   /* the result of the calculations */
char  operator; /* operator the user specified */
int   value;    /* value specified after the operator */
main()
{
    result = 0; /* initialize the result */

    /* Loop forever (or till we hit the break statement) */
    while (1) {
        (void) printf("Result: %d\n", result);

        (void) printf("Enter operator and number: ");
        (void) fgets(line, sizeof(line), stdin);
        (void) sscanf(line, "%c %d", &operator, &value);

        if (operator = '+') {
            result += value;
        } else {
            (void) printf("Unknown operator %c\n", operator);
        }
    }
}
