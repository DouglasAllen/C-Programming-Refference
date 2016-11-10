#include <stdio.h>
#define SQR(x) ((x) * (x))

main()
{
    int counter;    /* counter for loop */

    counter = 0;
    while (counter < 5)
        (void)printf("x %d square %d\n",
            counter, SQR(counter++));
    return (0);
}
