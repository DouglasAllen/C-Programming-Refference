/*************************************************************************
 *
 * Purpose: To find a # in a string. If found, it is removed along all text
 *          to the right of it. 
 * Author:  Dave Doolin
 * Date:    03-Jun-95
 *
 *
 * Notes:   This is NOT a complete program. It is provided as a function
 *	    for inclusion into your code.
 *
 *************************************************************************/

#include <stdio.h>
#include <string.h>		/* For the `strchr' synonym for `index'. */


/*
 * FIND_COMMENT will replace the octothorpe ("#") with a null character to
 * get rid of comments in a line.  Later need to add `stopchar' for more
 * flexibility, instead of just using "#".  Need also to find a way to
 * collapse initial spaces and tabs, in case I want to clean up the line as
 * well.
 */

void find_comment(char *tline)
{
  char *comment;

  comment = strchr(tline, '#');
  if (comment != 0)		/* If STRCHR returns an address for # then */
    *comment = '\0';		/* stick a null character at that address. */

  comment = strchr(tline, '\n');/* Replace \n with \0 for  consistency.  */
  if (comment != 0)
    *comment = '\0';
}

