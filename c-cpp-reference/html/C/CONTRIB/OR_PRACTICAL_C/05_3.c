#include <stdio.h>
char  line[100];   /* line from input */

/* Running total of all numbers so far */
int   total;       

/* next item to add to the list */
int   item;        

/* number of negative items */
int   minus_items; 

main()
{
    total = 0;
    minus_items = 0;
    while (1) {
        (void) printf("Enter # to add\n");
        (void) printf("  or 0 to stop:");
        (void) fgets(line, sizeof(line), stdin);
        (void) sscanf(line, "%d", &item);

        if (item == 0)
            break;

        if (item < 0) {
            minus_items++;
            continue;
        }
        total += item;
        (void) printf("Total: %d\n", total);
    }

    (void) printf("Final total %d\n", total);
    (void) printf("with %d negative items omitted\n",
                   minus_items);
    return (0);
}
