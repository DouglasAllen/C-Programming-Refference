/********************************************************
 *  symbol -- handle the symbol table                   *
 *                                                      *
 * Functions                                            *
 *      enter  -- put a symbol in a symbol table        *
 *      lookup -- get the data associated with a symbol *
 ********************************************************/
#include <stdio.h>
#include "symbol.h"
#include <string.h>
#include <stdlib.h>

/********************************************************
 * enter -- enter a word into the symbol table          *
 *                                                      *
 * Parameters                                           *
 *      node -- top node of the symbol table for add    *
 *      symbol -- symbol name to add (1 or 2 chars)     *
 *      data -- data associated with the symbol         *
 ********************************************************/
void enter(struct symbol **node_ptr, char *symbol, generic *data)
{
    int  result;        /* result of strcmp */
    /* New node that we are creating */
    struct symbol *new_node_ptr;

    /* see if we have reached the end */
    if ((*node_ptr) == NULL) {
        new_node_ptr = (struct symbol *) malloc(sizeof(struct symbol));
        (void)strcpy(new_node_ptr->name, symbol);
        new_node_ptr->data = data;
        new_node_ptr->left_ptr = NULL;
        new_node_ptr->right_ptr = NULL;
        *node_ptr = new_node_ptr;
        return;
    }
    /*
     * Need to sub-divide the symbol table and try again
     */
    result = strcmp((*node_ptr)->name, symbol);

    if (result == 0)
        return;

    if (result > 0)
        enter(&(*node_ptr)->left_ptr, symbol, data);
    else
        enter(&(*node_ptr)->right_ptr, symbol, data);
}
/********************************************************
 * lookup -- lookup a symbol in a table                 *
 *                                                      *
 * Parameters                                           *
 *      root -- root of the symbol table to search      *
 *      name -- name to lookup.                         *
 *                                                      *
 * Returns                                              *
 *      Pointer to the data or NULL if not found.       *
 ********************************************************/
generic *lookup(struct symbol *root_ptr, char *name)
{
    int result; /* Result of string compare */

    if (root_ptr == NULL) 
        return (NULL);

    result = strcmp(root_ptr->name, name);

    if (result == 0) {
        return (root_ptr->data);
    }

    if (result > 0)
        return (lookup(root_ptr->left_ptr, name));
    else 
        return (lookup(root_ptr->right_ptr, name));
}
