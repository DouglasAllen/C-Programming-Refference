#include <stdio.h>
main()
{
    int i,j;    /* two random integers */

    i = 1;
    j = 0;
    (void)printf("Starting\n");
    (void)fflush(stdout);
    (void)printf("Before divide...");
    (void)fflush(stdout);
    i = i / j;  /* divide by zero error */
    (void)printf("After\n");
    (void)fflush(stdout);
    return(0);
}
