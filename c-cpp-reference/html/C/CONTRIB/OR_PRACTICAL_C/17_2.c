/********************************************************
 * hist -- generate a histogram of an array of numbers  *
 *                                                      *
 * Usage                                                *
 *      hist <file>                                     *
 *                                                      *
 * Where                                                *
 *      file is the name of the file to work on         *
 ********************************************************/
#include "ia.h"
#include <stdio.h>
#include <stdlib.h>     /* ANSI Standard only */
#include <mem.h>
/*
 * the following definitions define the histogram
 */
#define NUMBER_OF_LINES 50
#define LOW_BOUND 0.0
#define HIGH_BOUND 99.0
/*
 * if we have NUMBER_OF_LINES data to 
 * output then each item must use
 * the following factor
 */
#define FACTOR \
  ((HIGH_BOUND - LOW_BOUND) / ((float) (NUMBER_OF_LINES-1)))

/* number of characters wide to make the histogram */
#define WIDTH 60   

static struct infinite_array data_array;
static int data_items;

main(int argc, char *argv[])
{
    void  read_data(char *);    /* get the data into the array */
    void  print_histogram(void);/* print the data */

    if (argc != 2) {
        (void) fprintf(stderr, 
               "Error:Wrong number of arguments\n");
        (void) fprintf(stderr, 
               "Usage is:\n");
        (void) fprintf(stderr, 
               "  hist <data-file>\n");
        exit(8);
    }
    ia_init(&data_array);
    data_items = 0;

    read_data(argv[1]);
    print_histogram();
    return (0);
}
/********************************************************
 * read_data -- read data from the input file into      *
 *              the data_array.                         *
 *                                                      *
 * Parameters                                           *
 *      name -- the name of the file to read            *
 ********************************************************/
void read_data(char *name)
{
    char  line[100];    /* line from input file */
    FILE *in_file; /* input file */
    float data;    /* data from input */

    in_file = fopen(name, "r");
    if (in_file == NULL) {
        (void) fprintf(stderr, 
               "Error:Unable to open %s\n", name);
        exit(8);
    }
    while (1) {
        if (fgets(line, sizeof(line), in_file) == NULL)
            break;

        if (sscanf(line, "%f", &data) != 1) {
            (void) fprintf(stderr,
              "Error: Input data not floating point number\n");
            (void) fprintf(stderr, "Line:%s", line);
        }
        ia_store(&data_array, data_items, data);
        data_items++;
    }
    fclose(in_file);
}
/********************************************************
 * print_histogram -- print the histogram output.       *
 ********************************************************/
void  print_histogram(void)
{
    /* upper bound for printout */
    int   counters[NUMBER_OF_LINES];    
    float low;          /* lower bound for printout */
    int   out_of_range = 0;/* number of items out of bounds */
    int   max_count = 0;/* biggest counter */
    float scale;        /* scale for outputting dots */
    int   index;        /* index into the data */

    (void) memset((char *) counters, '\0', sizeof(counters));

    for (index = 0; index < data_items; index++) {
        float data;/* data for this point */

        data = ia_get(&data_array, index);

        if ((data < LOW_BOUND) || (data > HIGH_BOUND))
            out_of_range++;
        else {
            /* index into counters array */
            int   count_index;

            count_index = (data - LOW_BOUND) / FACTOR;

            counters[count_index]++;
            if (counters[count_index] > max_count)
                max_count = counters[count_index];
        }
    }

    scale = ((float) max_count) / ((float) WIDTH);

    low = LOW_BOUND;
    for (index = 0; index < NUMBER_OF_LINES; index++) {
        /* index for outputting the dots */
        int   char_index;
        int   number_of_dots;   /* number of * to output */

        (void) printf("%2d:%3.0f-%3.0f (%4d): ",
                      index, low, low + FACTOR -1, 
                      counters[index]);

        number_of_dots = (int) (((float) counters[index]) / scale);
        for (char_index = 0; char_index < number_of_dots;
             char_index++)
            (void) printf("*");
        (void) printf("\n");
        low += FACTOR;
    }
    (void) printf("%d items out of range\n", out_of_range);
}
