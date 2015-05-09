#include <stdio.h>
#include <string.h>

char first[100];        /* first name of person we are working with */
char last[100];         /* His last name */

/* First and last name of the person (computed) */
char full[100];         
main() {
    (void)printf("Enter first name: ");
    (void)fgets(first, sizeof(first), stdin);
    /* trim off last character */
    first[strlen(first)-1] = '\0';

    (void)printf("Enter last name: ");
    (void)fgets(last, sizeof(last), stdin);
    /* trim off last character */
    last[strlen(last)-1] = '\0';

    (void)strcpy(full, first);
    (void)strcat(full, " ");
    (void)strcat(full, last);

    (void)printf("The name is %s\n", full);
    return (0);
}
