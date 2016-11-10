/*************************************************************************
 * 
 * problem: Convert Unix files to DOS format.
 * Method:  Program scans for hex '0A' (LF) and replaces it with hex '0D0A' (CRLF)
 * todo:	 Prompt the user for a filename, and check it exists.
 * Author:  M J Leslie
 * Date:    12-Mar-94
 *
 *************************************************************************/

#include <stdio.h>			/* printf, putchar, fopen, fclose */

#define LF	 10
#define CR	 13
#define FILENAME "unix2dos.c"

main()
{
FILE *fptr;				/* Pointer to file		*/
char ch;				/* File buffer			*/

fptr = fopen(FILENAME, "r");

while ( (ch = fgetc(fptr)) != EOF )	/* read characters until EOF 	*/
   {
   if ( ch == LF ) printf("%c", CR);	/* add CR if we see an LF	*/
   putchar(ch);				/* write byte		  	*/
   }
fclose(fptr);
}
