#include <stdio.h>
#define SQR(x) (x * x)

main()
{
    int counter;    /* counter for loop */

    for (counter = 0; counter < 5; counter++) {
        (void)printf("x %d, x squared %d\n",
            counter+1, SQR(counter+1));
    }
    return (0);
}
