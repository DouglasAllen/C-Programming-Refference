/********************************************************
 *  macros -- Handle macro related data structure.      *
 *                                                      *
 * Functions                                            *
 *      load_macros -- load a macro file into the macro *
 *                              symbol table            *
 *      macro_check -- check macro line                 *
 ********************************************************/
#include <stdio.h>
#include "gen.h"
#include "symbol.h"
#include "macro.h"
#include "font.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
extern void error(char *);      /* Write error message */

/*
 * Each argument to a macro has the following structure 
 */
struct arg {
    char type;          /* Type of argument */
    boolean many;       /* True if we can repeat this argument */
};

#define MAX_ARGS 10     /* Max arguments for each macro */

struct arg_list {
    int num_args;       /* Number of arguments */
    struct arg args[MAX_ARGS];  /* The arguments */
};

/* the top of the symbol table */
static struct symbol *macro_symbol_ptr = NULL;

/*
 * Skip past remaining argument
 */
#define SKIP_ARG(cur_char) \
    while (*(cur_char) > ' ') \
        (cur_char)++;

/********************************************************
 * load_macros -- load macros into symbol table         *
 *                                                      *
 * Parameters                                           *
 *      name -- filename of file to load                *
 *                                                      *
 * Aborts on error.                                     *
 *------------------------------------------------------*
 * Input file format:                                   *
 *      # line -- comment                               *
 *      mac arg arg # comment                           *
 *                                                      *
 *      mac -- one or two-character macro name          *
 *      arg -- argument type letter                     *
 *              | -- vertical bar                       *
 *              s -- string                             *
 *              n -- number                             *
 *              c -- single character                   *
 *              f -- font specification                 *
 *              t -- three-part title                   *
 *                                                      *
 *      If followed by a star, set the many flag.       *
 ********************************************************/
void  load_macros(char *name)
{
    FILE *in_file; /* Input file */
    int   line_number;  /* Line number of the input file */
    char *type_list = "|sncft"; /* Characters for argument type */
    int   num_args;/* Number of arguments we've seen */
    char  macro_name[3];        /* Name of the current macro */

    /* The macro we are working on */
    struct arg_list *arg_list_ptr;

    in_file = fopen(name, "r");
    if (in_file == NULL) {
        (void) fprintf(stderr, "Error:Can't open %s for reading\n", name);
        exit(8);
    }
    line_number = 0;

    while (1) {
        char  line[80]; /* Input line from data file */
        char *cur_char; /* Pointer to current input character */

        if (fgets(line, sizeof(line), in_file) == NULL) {
            (void) fclose(in_file);
            return;
        }
        line_number++;

        cur_char = line;
        /* Trim off leading whitespace */
        SKIP_WHITESPACE(cur_char);

        /* Continue on comment or blank line */
        if ((*cur_char == '#') || (cur_char == '\0'))
            continue;

        /* Copy two-character macro name */
        macro_name[0] = *cur_char;
        cur_char++;
        if (*cur_char > ' ') {
            macro_name[1] = *cur_char;
            cur_char++;
            macro_name[2] = '\0';
        } else
            macro_name[1] = '\0';

        /*
         * create new argument list
         */
        arg_list_ptr = (struct arg_list *) malloc(sizeof(struct arg_list));

        for (num_args = 0; num_args < MAX_ARGS; num_args++) {

            /* Move past whitespace */
            SKIP_WHITESPACE(cur_char);

            /* End of list? */
            if ((*cur_char == '#') || (cur_char == '\0'))
                break;

            /* Check for legal character */
            if (strchr(type_list, *cur_char) == NULL) {
                (void) fprintf(stderr,
                     "Error on line %d:Bad argument character %c\n",
                               line_number, *cur_char);
            }
            arg_list_ptr->args[num_args].type = *cur_char;
            cur_char++;

            if (*cur_char == '*') {
                arg_list_ptr->args[num_args].many = TRUE;
                cur_char++;
            } else
                arg_list_ptr->args[num_args].many = FALSE;

        }
        arg_list_ptr->num_args = num_args;
        enter(&macro_symbol_ptr, macro_name, (generic *) arg_list_ptr);
    }
}
/********************************************************
 * macro_check -- check a macro line for correctness    *
 *                                                      *
 * Parameters                                           *
 *      line -- line to check                           *
 ********************************************************/
void  macro_check(char *line)
{
    char *cur_char = &line[1];  /* Pointer to current character */
    char  name[3]; /* Macro name */
    struct arg_list *arg_list_ptr;      /* The argument list */
    int   arg_index;    /* Index into argument list */

    extern char *check_string(char *);  /* String? */
    extern char *check_number(char *);  /* Number? */
    extern char *check_char(char *);    /* Character? */
    extern char *check_font(char *);    /* Font specification? */
    extern char *check_title(char *);   /* Three-part title? */

    SKIP_WHITESPACE(cur_char);

    /* Copy two-character macro name */
    name[0] = *cur_char;
    cur_char++;
    if (*cur_char > ' ') {
        name[1] = *cur_char;
        cur_char++;
        name[2] = '\0';
    } else
        name[1] = '\0';

    arg_list_ptr = (struct arg_list *) lookup(macro_symbol_ptr, name);

    if (arg_list_ptr == NULL) {
        char  error_msg[30];
        (void) sprintf(error_msg, "No such macro %s", name);
        error(error_msg);
        return;
    }
    arg_index = 0;
    while (1) {
        if (arg_index >= arg_list_ptr->num_args)
            break;

        /* Start at beginning of next macro */
        SKIP_WHITESPACE(cur_char);

        /* Check for end of string */
        if (*cur_char == '\0')
            break;

        switch (arg_list_ptr->args[arg_index].type) {
            /* Vertical Bar (optional) */
        case '|':
            if (*cur_char == '|')
                cur_char++;
            break;

            /* s -- a string */
        case 's':
            cur_char = check_string(cur_char);
            break;

            /* n -- number */
        case 'n':
            cur_char = check_number(cur_char);
            break;

            /* c -- character */
        case 'c':
            cur_char = check_char(cur_char);
            break;

            /* f -- font specification */
        case 'f':
            cur_char = check_font(cur_char);
            break;

            /* t -- three-part title */
        case 't':
            cur_char = check_title(cur_char);
            break;

        default:
            (void) printf("Internal error, bad type %c\n",
                          arg_list_ptr->args[arg_index].type);
            break;
        }

        if (arg_list_ptr->args[arg_index].many == FALSE)
            arg_index++;

    }
    SKIP_WHITESPACE(cur_char);
    if (*cur_char != '\0')
        error("Too many arguments");
}
/********************************************************
 * check_string -- check argument to make sure it's     *
 *              pointing to a string                    *
 *                                                      *
 * A string is a word or a set of words enclosed in     *
 *      double quotes.                                  *
 *                                                      *
 * I.E.   sam    "This is a test"                       *
 *                                                      *
 * Parameters                                           *
 *      cur_char -- pointer to the string               *
 *                                                      *
 * Returns                                              *
 *      pointer to character after the string           *
 ********************************************************/
char *check_string(char *cur_char)
{
    /* What type of string is it? */

    /* Quoted string? */
    if (*cur_char == '"') {
        cur_char++;

        /* Move to end of string */
        while ((*cur_char != '"') && (*cur_char != '\0'))
            cur_char++;

        /* Check for proper termination */
        if (*cur_char == '\0')
            error("Missing closing \" on string parameter");
        else
            cur_char++;         /* Move past closing quote */

    } else {
        /* Simple word string */
        while (!isspace(*cur_char))
            cur_char++;
    }
    return (cur_char);
}
/********************************************************
 * check_number -- check argument to make sure it's     *
 *              pointing to a expression                *
 *                                                      *
 * Parameters                                           *
 *      cur_char -- pointer to the integer expression   *
 *                                                      *
 *                                                      *
 * Returns                                              *
 *      pointer to character after the integer exp      *
 ********************************************************/
char *check_number(char *cur_char)
{
    /* Characters allowed in expressions */
    static char *number_chars = "0123456789+-*/%.";

    if (strchr(number_chars, *cur_char) == NULL) {
        error("Expression expected");
        SKIP_ARG(cur_char);
        return (cur_char);
    }
    while (strchr(number_chars, *cur_char) != NULL)
        cur_char++;

    if (!(isspace(*cur_char) || (*cur_char == '\0'))) {
        SKIP_ARG(cur_char);
        error("Illegal expression");
    }

    return (cur_char);
}
/********************************************************
 * check_char -- check argument to make sure it's       *
 *              pointing to a char                      *
 *                                                      *
 * Parameters                                           *
 *      cur_char -- pointer to the char                 *
 *                                                      *
 * Returns                                              *
 *      pointer to character after the char             *
 *                                                      *
 * Note: This is a simple character check and does not  *
 *       try to figure out all of the crazy \           *
 *       characters that can be used in troff.          *
 ********************************************************/
char *check_char(char *cur_char)
{
    cur_char++;

    if (!(isspace(*cur_char) || (*cur_char == '\0')))
        error("Expected single character");

    return (cur_char);
}
/********************************************************
 * check_font -- check argument to make sure it's       *
 *              pointing to a legal font                *
 *                                                      *
 * Parameters                                           *
 *      cur_char -- pointer to the font                 *
 *                                                      *
 * Returns                                              *
 *      pointer to character after the font             *
 ********************************************************/
char *check_font(char *cur_char)
{
    char  name[3]; /* Font name */

    name[0] = *cur_char;
    cur_char++;

    if (isalnum(*cur_char)) {
        name[1] = *cur_char;
        cur_char++;
        name[2] = '\0';
    } else
        name[1] = '\0';

    if (lookup(font_symbol_ptr, name) == NULL)
        error("Expected font");

    return (cur_char);
}

/********************************************************
 * check_title -- check argument to make sure it's      *
 *              pointing to a three-part title          *
 *              of the form:  'xxxx'yyyy'zzz'.          *
 *                                                      *
 * Parameters                                           *
 *      cur_char -- pointer to the title                *
 *                                                      *
 * Returns                                              *
 *      pointer to character after the title            *
 ********************************************************/
char *check_title(char *cur_char)
{
    if (*cur_char != '\'') {
        error("Expected beginning of three-part title");
        SKIP_ARG(cur_char);
        return (cur_char);
    }
    cur_char++;

    while ((*cur_char != '\'') && (*cur_char != '\0'))
        cur_char++;

    if (*cur_char != '\'') {
        error("Expected middle part of three-part title");
        SKIP_ARG(cur_char);
        return (cur_char);
    }
    cur_char++;

    while ((*cur_char != '\'') && (*cur_char != '\0'))
        cur_char++;

    if (*cur_char != '\'') {
        error("Expected third part of three-part title");
        SKIP_ARG(cur_char);
        return (cur_char);
    }
    cur_char++;

    while ((*cur_char != '\'') && (*cur_char != '\0'))
        cur_char++;

    if (*cur_char != '\'') {
        error("Expected end of three-part title");
        SKIP_ARG(cur_char);
        return (cur_char);
    }
    cur_char++;
    return (cur_char);
}
