/************************************************************************
 *
 * Purpose: Find the length of a string.
 *	    This duplicates the  strlen function found in string.h
 * Author:  M J Leslie
 * Date:    20-Mar-94
 *
 ************************************************************************/

#include <stdio.h>

int lenstr(const char *text);

main()
{
  char kb_buf[80];				/* Keyboard buffer	*/

  puts(" Please enter some text ");
  printf("Text is %d characters long.\n", lenstr(gets(kb_buf)));
}

/************************************************************************
 *
 *	Find the length of a string - does not check if we fall off
 *	the end of the text buffer. oops.
 *
 ************************************************************************/

int lenstr(const char *text)
{
  int  count=-1;				/* Character counter	*/

  while(text[++count] != '\0') ;		/* Serach for a null	*/

  return(count);				/* Return the position 
						 * of the NULL-1	*/
}
