/********************************************************
 * gen.h -- general purpose macros.                     *
 ********************************************************/

/*
 * Define a boolean type 
 */
#ifndef TRUE
typedef int boolean;
#define TRUE 1
#define FALSE 0
#endif /* TRUE */

/********************************************************
 * SKIP_WHITESPACE -- move a character pointer          *
 *      past whitespace                                 *
 *                                                      *
 * Parameters                                           *
 *      cur_char -- pointer to current character        *
 *              (will be moved)                         *
 ********************************************************/
/* Move past whitespace */
#define SKIP_WHITESPACE(cur_char) \
    while ((*(cur_char) <= ' ') && (*(cur_char) != '\0')) \
        (cur_char)++;
