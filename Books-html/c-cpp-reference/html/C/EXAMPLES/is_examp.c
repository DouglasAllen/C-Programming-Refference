/************************************************************************
 *
 * Purpose: Program to demonstrate the following functions:
 *	    isalpha, isdigit, isspace. 
 *	    The same principles apply to isalnum, iscntrl, isgraph, 
 *          islower, isprint, ispunct, isupper, isxdigit
 *
 * Author:  M. J. Leslie
 * Date:    09-Mar-94
 *
 ************************************************************************/

#include <stdio.h>					/* printf 	*/
#include <ctype.h> 		/* isalpha isdigit isspace etc 		*/

#define FALSE 0
#define TRUE  1

				/* function declarations 		*/
int char_type(char);

main()
{
  char ch;
			/* get a character from the keyboard 	*/
  printf(" Please enter a charcater => ");
  ch = getc(stdin);

  char_type(ch);	/* Figure out the character type 	*/
}

/****************************************************************
		decide the character type.
*****************************************************************/
int char_type(char ch)
{
			/* returns non zero if A-Z or a-z 	*/
  if ( isalpha(ch) != FALSE)
    printf("%c is an Alpha character.\n",ch);

			/* returns non zero if 0-9  		*/
  if ( isdigit(ch) != FALSE)
    printf("%c is a numeric character.\n",ch);

			/* returns non zero if a space, CR, Tab, NL FF  */
  if ( isspace(ch) != FALSE)
    printf("%c is white space\n", ch);

}
