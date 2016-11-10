#include <stdio.h>
main()
{
    int i,j;    /* two random integers */

    i = 1;
    j = 0;
    (void)printf("Starting\n");
    (void)printf("Before divide...");
    i = i / j;  /* divide by zero error */
    (void)printf("After\n");
    return(0);
}
