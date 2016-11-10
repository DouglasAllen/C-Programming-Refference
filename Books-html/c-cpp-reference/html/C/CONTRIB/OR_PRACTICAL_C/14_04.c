#include <stdio.h>
FILE *save_file = NULL;         /* Save input in this file */
FILE *playback_file = NULL;     /* Playback data from this file */
/********************************************************
 * extended_fgets -- get a line from the input file     *
 *              and record it in a save file if needed  *
 *                                                      *
 * Parameters                                           *
 *      line -- the line to read                        *
 *      size -- sizeof(line) -- maximum number of       *
 *                      characters to read              *
 *      file -- file to read data from                  *
 *              (normally stdin)                        *
 *                                                      *
 * Returns                                              *
 *      NULL -- error or end of file in read            *
 *      otherwise line (just like fgets)                *
 ********************************************************/
char *extended_fgets(char *line, int size, FILE *file)
{
    extern FILE *save_file;     /* file to save strings in */
    extern FILE *playback_file; /* file for alternate input */

    char *result;               /* result of fgets */

    if (playback_file != NULL) {
        result = fgets(line, size, file);
        /* echo the input to the standard out so the user sees it */
        (void)fputs(line, stdout);
    } else
        result = fgets(line, size, file);

    /* did someone ask for a save file */
    if (save_file != NULL) 
        (void)fputs(line, save_file);

    return (result);
}
