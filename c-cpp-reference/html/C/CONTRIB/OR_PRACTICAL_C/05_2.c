#include <stdio.h>
char  line[100];/* line of data for input */

/* Running total of all numbers so far */
int   total;  

/* next item to add to the list */
int   item;   

main()
{
    total = 0;
    while (1) {
        (void) printf("Enter # to add \n");
        (void) printf("  or 0 to stop:");
        (void) fgets(line, sizeof(line), stdin);
        (void) sscanf(line, "%d", &item);
        if (item == 0)
            break;
        total += item;
        (void) printf("Total: %d\n", total);
    }
    (void) printf("Final total %d\n", total);
    return (0);
}
