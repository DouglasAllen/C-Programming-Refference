/********************************************************
 * macros.h -- Definitions for the macro lookup         *
 *              package.                                *
 *                                                      *
 * Procedures                                           *
 *      load_macros -- load a macro onto the symbol tbl *
 *                                                      *
 *      macro_check -- check a macro line for           *
 *                      correctness                     *
 ********************************************************/

/********************************************************
 * load_macros -- load macros into symbol table         *
 *                                                      *
 * Parameters                                           *
 *      name -- filename of file to load                *
 ********************************************************/
void load_macros(char *name);

/********************************************************
 * macro_check -- check a macro line for correctness    *
 *                                                      *
 * Parameters                                           *
 *      line -- line to check                           *
 ********************************************************/
void macro_check(char *name);
