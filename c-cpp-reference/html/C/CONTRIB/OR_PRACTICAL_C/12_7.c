/********************************************************
 * split -- split an entry of the form Last/First       *
 *      into two parts.                                 *
 ********************************************************/
#include <stdio.h>
#include <string.h>

/* Our version of the library function */
char *strchr(char *, char);

main()
{
    char line[80];      /* The input line */
    char *first_ptr;    /* pointer to the first name */
    char *last_ptr;     /* pointer to the last name */

    (void)fgets(line, sizeof(line), stdin);

    /* Get rid of trailing newline */
    line[strlen(line)-1] = '\0';        

    last_ptr = line;    /* last name is at beginning of line */

    first_ptr = strchr(line, '/');      /* Find slash */

    /* Check for an error */
    if (first_ptr == NULL) {
        (void)fprintf(stderr,
            "Error: Unable to find slash in %s\n", line);
        exit (8);
    }

    *first_ptr = '\0';  /* Zero out the slash */

    first_ptr++;        /* Move to first character of name */

    (void)printf("First:%s Last:%s\n", first_ptr, last_ptr);
    return (0);
}
/********************************************************
 * strchr -- find a character in a string               *
 *      Duplicate of a standard library function,       *
 *      put here for illustrative purposes.             *
 *                                                      *
 * Parameters                                           *
 *      string_ptr -- string to look through            *
 *      find -- character to find                       *
 *                                                      *
 * Returns                                              *
 *      pointer to 1st occurrence of character          *
 *      in string or NULL for error                     *
 ********************************************************/
char *strchr(char * string_ptr, char find)
{
    while (*string_ptr != find) {

       /* Check for end */

       if (*string_ptr == '\0')
           return (NULL);       /* not found */

        string_ptr++;
    }
    return (string_ptr);        /* Found */
}
