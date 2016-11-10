#include <stdio.h>

int term;       /* term used in two expressions */
main()
{

    term = 3 * 5;
    (void)printf("Twice %d is %d\n", term, 2*term);
    (void)printf("Three time %d is %d\n", term, 3*term);
    return (0);
}
