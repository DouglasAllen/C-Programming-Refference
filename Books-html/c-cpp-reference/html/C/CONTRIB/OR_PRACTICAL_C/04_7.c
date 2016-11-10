#include <stdio.h>
char  line[100];   /* input line from console */
int   value;       /* a value to double */

main()
{
    (void) printf("Enter a value: ");
    (void) fgets(line, sizeof(line), stdin);
    (void) sscanf(line, "%d", &value);
    (void) printf("Twice %d is %d\n",
                  value, value * 2);
    return (0);
}
