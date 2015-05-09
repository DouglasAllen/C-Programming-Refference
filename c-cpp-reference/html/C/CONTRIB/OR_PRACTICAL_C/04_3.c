#include <string.h>
#include <stdio.h>

char first[100];        /* first name */
char last[100];         /* last name */
char full_name[200];    /* full version of first and last name */

main()
{
    (void)strcpy(first, "Steve");       /* Initialize first name */
    (void)strcpy(last, "Oualline");     /* Initialize last name */

    (void)strcpy(full_name, first);     /* full = "Steve" */
    /* Note: strcat not strcpy */
    (void)strcat(full_name, " ");       /* full = "Steve " */
    (void)strcat(full_name, last);      /* full = "Steve Oualline" */

    (void)printf("The full name is %s\n", full_name);
    return (0);
}
