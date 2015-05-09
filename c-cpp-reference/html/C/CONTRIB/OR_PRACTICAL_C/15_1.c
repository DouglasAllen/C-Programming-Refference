#include <stdio.h>
main()
{
    /* two numbers to work with */
    float number1, number2;
    float result;               /* result of calculation */
    int   counter;              /* loop counter and accuracy check */

    number1 = 1.0;
    number2 = 1.0;
    counter = 0;

    while (number1 + number2 != number1) {
        counter++;
        number2 = number2 / 10.0;
    }
    (void) printf("%2d digits accuracy in calculations\n", counter);

    number2 = 1.0;
    counter = 0;

    while (1) {
        result = number1 + number2;
        if (result == number1)
            break;
        counter++;
        number2 = number2 / 10.0;
    }
    (void) printf("%2d digits accuracy in storage\n", counter);
    return (0);
}
