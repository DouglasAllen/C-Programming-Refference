/********************************************************
 * words -- scan a file and print out a list of words   *
 *              in ASCII order.                         *
 *                                                      *
 * Usage:                                               *
 *      words <file>                                    *
 ********************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>     /* ANSI Standard only */

struct node {
    struct node    *right;      /* tree to the right */
    struct node    *left;       /* tree to the left */
    char           *word;       /* word for this tree */
};

/* the top of the tree */
static struct node *root = NULL;

main(int argc, char *argv[])
{
    void scan(char *);  /* scan the files for words */
    void print_tree(struct node *);/* print the words in the file */

    if (argc != 2) {
        (void) fprintf(stderr, "Error:Wrong number of parameters\n");
        (void) fprintf(stderr, "      on the command line\n");
        (void) fprintf(stderr, "Usage is:\n");
        (void) fprintf(stderr, "    words 'file'\n");
        exit(8);
    }
    scan(argv[1]);
    print_tree(root);
    return (0);
}
/********************************************************
 * scan -- scan the file for words                      *
 *                                                      *
 * Parameters                                           *
 *      name -- name of the file to scan                *
 ********************************************************/
void scan(char *name)
{
    char word[100];     /* word we are working on */
    int  index;         /* index into the word */
    int  ch;            /* current character */
    FILE *in_file;      /* input file */

    /* enter a word into the tree */
    void enter(struct node **, char *);

    in_file = fopen(name, "r");
    if (in_file == NULL) {
        (void) fprintf(stderr, 
            "Error:Unable to open %s\n", name);
        exit(8);
    }
    while (1) {
        /* scan past the whitespace */
        while (1) {
            ch = fgetc(in_file);

            if (isalpha(ch) || (ch == EOF))
                break;
        }

        if (ch == EOF)
            break;

        word[0] = ch;
        for (index = 1; index < sizeof(word); index++) {
            ch = fgetc(in_file);
            if (!isalpha(ch))
                break;
            word[index] = ch;
        }
        /* put a null on the end */
        word[index] = '\0';

        enter(&root, word);
    }
    (void) fclose(in_file);
}
/********************************************************
 * enter -- enter a word into the tree                  *
 *                                                      *
 * Parameters                                           *
 *      node -- current node we are looking at          *
 *      word -- word to enter                           *
 ********************************************************/
void enter(struct node **node, char *word)
{
    int  result;        /* result of strcmp */

    char *save_string(char *);  /* save a string on the heap */
    void memory_error(void);    /* tell user no more room */

    /* see if we have reached the end */
    if ((*node) == NULL) {
        (*node) = (struct node *) malloc(sizeof(struct node));
        if ((*node) == NULL)
            memory_error();
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->word = save_string(word);
    }
    result = strcmp((*node)->word, word);
    if (result == 0)
        return;
    if (result < 0)
        enter(&(*node)->right, word);
    else
        enter(&(*node)->left, word);
}
/********************************************************
 * save_string -- save a string on the heap             *
 *                                                      *
 * Parameters                                           *
 *      string -- string to save                        *
 *                                                      *
 * Returns                                              *
 *      pointer to malloc-ed section of memory with     *
 *      the string copied into it.                      *
 ********************************************************/
char *save_string(char *string)
{
    char *new_string;   /* where we are going to put string */

    new_string = malloc((unsigned) (strlen(string) + 1));
    if (new_string == NULL)
        memory_error();
    (void) strcpy(new_string, string);
    return (new_string);
}
/********************************************************
 * memory_error -- write error and die                  *
 ********************************************************/
void memory_error(void)
{
    (void) fprintf(stderr, "Error:Out of memory\n");
    exit(8);
}
/********************************************************
 * print_tree -- print out the words in a tree          *
 *                                                      *
 * Parameters                                           *
 *      top -- the root of the tree to print            *
 ********************************************************/
void print_tree(struct node *top)
{
    if (top == NULL)
        return;                 /* short tree */

    print_tree(top->left);
    (void) printf("%s\n", top->word);
    print_tree(top->right);
}
