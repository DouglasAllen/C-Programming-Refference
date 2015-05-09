/********************************************************
 *  fonts -- handle font-related data structures        *
 *                                                      *
 * Functions                                            *
 *      load_fonts -- load a font file                  *
 ********************************************************/
#include <stdio.h>
#include "gen.h"
#include "symbol.h"
#include <string.h>
#include <stdlib.h>

/* the top of the symbol table */
struct symbol *font_symbol_ptr = NULL;
/********************************************************
 * load_fonts -- load fonts into symbol table           *
 *                                                      *
 * Parameters                                           *
 *      file_name -- filename of file to load           *
 *                                                      *
 * Aborts on error.                                     *
 ********************************************************/
void load_fonts(char *file_name)
{
    FILE *in_file; /* Input file */
    char  name[3]; /* Name of the current font */
    /* We have to point to something for our data */
    static char *an_object = "an object";       

    in_file = fopen(file_name, "r");
    if (in_file == NULL) {
        (void) fprintf(stderr, "Error:Can't open %s for reading\n", file_name);
        exit(8);
    }

    while (1) {
        char  line[80]; /* Input line from data file */
        char *cur_char; /* Pointer to current input character */

        if (fgets(line, sizeof(line), in_file) == NULL) {
            (void) fclose(in_file);
            return;
        }
        cur_char = line;

        while (*cur_char != '\0') {
            SKIP_WHITESPACE(cur_char);

            if (*cur_char == '\0')
                break;

            /* Copy two-character macro name */
            name[0] = *cur_char;
            cur_char++;
            if (*cur_char > ' ') {
                name[1] = *cur_char;
                cur_char++;
                name[2] = '\0';
            } else
                name[1] = '\0';

            enter(&font_symbol_ptr, name, (generic *) an_object);
        }
    }
}
