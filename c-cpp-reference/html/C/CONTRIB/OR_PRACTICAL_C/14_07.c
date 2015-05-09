/********************************************************
 * search -- Search a set of numbers.                   *
 *                                                      *
 * Usage:                                               *
 *      search                                          *
 *              you will be asked numbers to lookup     *
 *                                                      *
 * Files:                                               *
 *      numbers.dat -- numbers 1 per line to search     *
 *                      (Numbers must be ordered)       *
 ********************************************************/
#include <stdio.h>
#define MAX_NUMBERS     1000           /* Max numbers in file */
#define DATA_FILE       "numbers.dat"  /* File with numbers */

int data[MAX_NUMBERS];  /* Array of numbers to search */
int max_count;          /* Number of valid elements in data */
main()
{
    FILE *in_file;      /* Input file */
    int middle;         /* Middle of our search range */
    int low, high;      /* Upper/lower bound */
    int search;         /* number to search for */
    char line[80];      /* Input line */

    in_file = fopen(DATA_FILE, "r");
    if (in_file == NULL) {
        (void)fprintf(stderr,"Error:Unable to open %s\n", DATA_FILE);
        exit (8);
    }

    /*
     * Read in data 
     */

    max_count = 0;
    while (1) {
        if (fgets(line, sizeof(line),  in_file) == NULL)
            break;

        /* convert number */
        (void)sscanf(line, "%d", data[max_count]);
        max_count++;
    }

    while (1) {
        (void)printf("Enter number to search for or -1 to quit:" );
        (void)fgets(line, sizeof(line), stdin);
        (void)sscanf(line, "%d", &search);

        if (search == -1)
            break;

        low = 0;
        high = max_count;

        while (1) {
            middle = (low + high) / 2;

            if (data[middle] == search) {
                (void)printf("Found at index %d\n", middle);
            }

            if (low == high) {
                (void)printf("Not found\n");
                break;
            }

            if (data[middle] < search)
                low = middle;
            else
                high = middle;
        }
   }
   return (0);
}
