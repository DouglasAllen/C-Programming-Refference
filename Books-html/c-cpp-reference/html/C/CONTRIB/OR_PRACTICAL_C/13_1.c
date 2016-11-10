#include <stdio.h>
#define FILE_NAME "input.txt"
#include <stdlib.h>     /* ANSI Standard C file */

main()
{
    int             count = 0;  /* number of characters seen */
    FILE           *in_file;    /* input file */

    /* character or EOF flag from input */
    int             ch;

    in_file = fopen(FILE_NAME, "r");
    if (in_file == NULL) {
        (void)printf("Can not open %s\n", FILE_NAME);
        exit(8);
    }

    while (1) {
        ch = fgetc(in_file);
        if (ch == EOF)
            break;
        count++;
    }
    (void) printf("Number of characters in %s is %d\n",
                  FILE_NAME, count);

    (void) fclose(in_file);
    return (0);
}
