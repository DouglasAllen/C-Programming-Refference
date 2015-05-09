
/*
 * field.c
 * 
 * Dave Doolin     12 May, 1995
 * 
 * Turns miscellaneous field separators into just a space separating tokens for
 * easy parsing by SSCANF.  Eventually, the character separators and
 * replacement character will be passed in as strings.
 * 
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>

#define LINE_BUF  100

void find_comment(char *);

main()
{
  char  line[LINE_BUF];
  char *sep;
  int   var1, var2;

  while (fgets(line, LINE_BUF, stdin))
  {

	/*
	 * Check this out:  Since SEP is a pointer to type char, when line is
	 * assigned to sep, really the first address is assigned to sep. LINE
	 * is the address of the start of the string.  In contrast, LINE[0]
	 * is the first character of the string.
	 */

    sep = line;

    while (sep != 0)
    {
      sep = strpbrk(line, ";.&:,");
      if (sep != 0)
        *sep = ' ';
    }
    fputs(line, stdout);
  }
  return 0;
}
