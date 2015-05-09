#include <stdio.h>
char  line[100];/* line of text from input */

int   result;   /* the result of the calculations */
char  operator; /* operator the user specified */
int   value;    /* value specified after the operator */
main()
{
    result = 0; /* initialize the result */

    /* loop forever (or until break reached) */
    while (1) {
        (void) printf("Result: %d\n", result);
        (void) printf("Enter operator and number: ");

        (void) fgets(line, sizeof(line), stdin);
        (void) sscanf(line, "%c %d", &operator, &value);

        if ((operator == 'q') || (operator == 'Q'))
            break;

        if (operator == '+') {
            result += value;
        } else if (operator == '-') {
            result -= value;
        } else if (operator == '*') {
            result *= value;
        } else if (operator == '/') {
            if (value == 0) {
                (void)printf("Error:Divide by zero\n");
                (void)printf("   operation ignored\n");
            } else
                result /= value;
        } else {
            (void) printf("Unknown operator %c\n", operator);
        }
    }
    return (0);
}
