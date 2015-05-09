/********************************************************
 * tlint -- check troff files for problems              *
 *                                                      *
 * Usage:                                               *
 *      tlint [options] [files]                         *
 *                                                      *
 * Options                                              *
 *      -m<file>        Add the data from <file>        *
 *                      to the tables used for syntax   *
 *                      checking.                       *
 *      -f<file>        Add font data from <file>       *
 *                      to list of legal fonts.         *
 *                                                      *
 *      [files] is a list of files to check.            *
 *              (none=check standard in.)               *
 *                                                      *
 ********************************************************/
#include <stdio.h>
#include "gen.h"
#include "macro.h"
#include "font.h"
#include <stdlib.h>

#define MAX_LINE 100            /* longest line we can expect */

#define MACRO_START_1   '.'     /* Macros can begin with a dot */
#define MACRO_START_2   '\''    /* or an apostrophe */

main(int argc, char *argv[])
{
    void usage(void);   /* Tell the user what to do */
    void do_file(char *, FILE *); /* Process a file */

    load_macros("standard.mac");
    load_fonts("standard.fonts");

    while ((argc > 1) && (argv[1][0] == '-')) {
        switch (argv[1][1]) {
            case 'm':
                load_macros(&argv[1][2]);
                break;
            case 'f':
                load_fonts(&argv[1][2]);
                break;
            default:
                usage();
        }
        argc--;
        argv++;
    }
    if (argc == 1) {
        do_file("standard-in", stdin);
    } else {
        while (argc > 1) {
            FILE *in_file;   /* File for reading data */

            in_file = fopen(argv[1], "r");
            if (in_file == NULL) {
                (void)fprintf(stderr,"Unable to open %s\n", argv[1]);
            } else {
                do_file(argv[1], in_file);
                (void)fclose(in_file);
            }
            argc--;
            argv++;
        }
    }
    return (0);
}
/********************************************************
 * usage -- tell the user what to do                    *
 ********************************************************/
static void usage(void)
{
    (void)printf("Usage is:\n");
    (void)printf("   tlint [options] [file1] [file2] ...\n");
    (void)printf("Options:\n");
    (void)printf("      -m<file> -- add <file> to list\n");
    (void)printf("                  of macro files\n");
    (void)printf("      -f<file> -- specify additional font file\n");
    exit (8);
}
static char *file_name; /* Name of the file we are processing */
static int line_number; /* Current line number */
static char line[MAX_LINE];     /* A line from the input file */
static int line_out;    /* True if a line has been output */
/********************************************************
 * do_file -- process a single file                     *
 *                                                      *
 * Parameters                                           *
 *      name -- name of the file to use                 *
 *      in_file -- file to check                        *
 ********************************************************/
static void do_file(char *name, FILE *in_file)
{

    file_name = name;
    line_number = 0;
    while (1) {
        if (fgets(line, sizeof(line), in_file) == NULL)
            break;
        line_out = 0;   /* We have not written the line */
        line_number++;
        
        if ((line[0] == MACRO_START_1) || (line[0] == MACRO_START_2))
            macro_check(line);
    }
}
/********************************************************
 * error -- tell the user that there is an error        *
 *                                                      *
 * Parameters                                           *
 *      message -- error message                        *
 ********************************************************/
void error(char *message)
{
    if (line_out == 0) {
        (void)fprintf(stderr,"%s", line);
        line_out = 1;
    }
    (void)fprintf(stderr,"Error %s in file %s Line %d\n", 
        message, file_name, line_number);
}
