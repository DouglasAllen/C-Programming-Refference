/********************************************************
 * font.h -- Definitions for the font package           *
 *              package.                                *
 *                                                      *
 * Procedures                                           *
 *      load_fonts -- load a font file onto the symbol  *
 *                              table                   *
 ********************************************************/

extern struct symbol *font_symbol_ptr;  /* A list of
                                legal fonts */
/********************************************************
 * load_fonts -- load fonts into symbol table           *
 *                                                      *
 * Parameters                                           *
 *      file_name -- filename of file to load           *
 *                                                      *
 * Aborts on error                                      *
 ********************************************************/
void load_fonts(char *name);
