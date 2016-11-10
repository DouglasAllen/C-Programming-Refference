#include <stdio.h>
#include <string.h>

char first[100];        /* first name of person we are working with */
char last[100];         /* His last name */

/* First and last name of the person (computed) */
char full[200];         
main() {
    (void)printf("Enter first name: ");
    (void)fgets(first, sizeof(first), stdin);

    (void)printf("Enter last name: ");
    (void)fgets(last, sizeof(last), stdin);

    (void)strcpy(full, first);
    (void)strcat(full, " ");
    (void)strcat(full, last);

    (void)printf("The name is %s\n", full);
    return (0);
}
