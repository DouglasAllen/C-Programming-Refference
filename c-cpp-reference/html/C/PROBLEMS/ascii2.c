/************************************************************************
 *
 * problem: Display an Ascii table. Fab version
 * Author:  M J Leslie
 * Date:    12-Mar-94
 *
 ************************************************************************/

#include <stdio.h>			/* printf, putchar, fopen, fclose */

					/* Function declarations	*/
int ascii(int);

main()
{
ascii('h');				/* ascii table in Hex		*/
ascii('d');				/* ascii table in decimal	*/
ascii('r');				/* test invalid option		*/
}

/*************************************************************************
	O/P an ascii table 						
	Parms:	int - O/P type 'h' hex  
			       'd' decimal
			           any other value not allowed.
	Return codes: 0 = OK
		      1 = Invalid parms passed.				
*************************************************************************/

#define LINEBREAK 8
#define FALSE     0
#define TRUE      1

int ascii(int type)
{
int  ascii, inc=0;				
char ch;				/* 'ascii' in char format.	*/
char format[10];			/* Format statement for printf  */

					/* Are we to O/P in hex or decimal?
					   h - hex
					   d - decimal */
switch(type)
   {
   case 'h' : strcpy(format,"%02X %c  ");	/* hex     */
		break;
   case 'd' : strcpy(format,"%03d %c  ");	/* decimal */
		break;
   default :  printf("\n Function syntax:\n");    /* error   */
              printf("    ascii('h') for hex O/P\n");
              printf("    ascii('d') for decimal O/P\n");
	      return(1);
   }
					/* O/P a table heading		*/
printf("\n\tAscii table");
printf("\n\t-----------\n\n");

					/* O/P the table		*/
for (ascii=0; ascii<=127; ascii++) 	/* loop through the Ascii codes */
   {
					/* Check that the character is 
					   printable...			*/	
   ch = ascii;
   if ( isprint(ch) == FALSE )
      ch = ' ';				/* Replace with ' ' if not printable */

   printf(format, ascii, ch);  		/* O/P numeric and character format */
   
					/* count # of codes O/P and insert
					   L/F when required		*/	
   if ( ++inc%LINEBREAK == 0 ) printf("\n");
   }
return(0);
}
