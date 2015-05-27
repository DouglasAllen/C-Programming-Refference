// is_alphanumeric.c

#include <stdio.h>          /* printf   */
#include <ctype.h>      /* isalpha isdigit isspace etc      */

/* function declarations        */
int char_type(char);

main()
{
  int i;
  char ch;

  for (i=0; i<128; i++)
  {
   ch = i;
   if (ch == 127) printf("DEL is a Control Character\n");
   if (ch != 0)
     char_type(ch);
   else
     if (ch == 0) printf("NUL is a Control Character\n");               
  }

  return 0;
}

/****************************************************************
        decide the character type.
*****************************************************************/
int char_type(char ch)
{
  /* Test to see if this character is alphanumeric */
  if (isalnum(ch)) printf("%c is Alphanumeric\n", ch);

  /* Test to see if this is a alphabet character */
  if (isalpha(ch)) printf("%c is Alphabetic\n", ch);

  /* Test to see if this is a control character */
  if (iscntrl(ch)) printf("%c is a Control Character\n", ch);

  /* Test to see if this is a decimal digit character */
  if (isdigit(ch)) printf("%c is a Digit\n", ch);

  /* Test to see if this character is a printing character */
  if (isgraph(ch)) printf("%c is a Graphical Character\n", ch);

  /* Test to see if the letter provided is lowercase */
  if (islower(ch)) printf("'%c' is a Lowercase Letter\n", ch);

  /* Test to see if this character is a printing character */
  if (isprint(ch)) printf("%c is a Printing Character\n", ch);

  /* Test to see if this character is a punctuation character */
  if (ispunct(ch)) printf("%c is a Punctuation Character\n", ch);

  /* Test to see if this character is a space character */
  if (isspace(ch)) printf("%c is a White-Space Character\n", ch);  
  /* returns non zero if a space, CR, Tab, NL FF  */    

  /* Test to see if the letter provided is uppercase */
  if (isupper(ch)) printf("'%c' is a Uppercase Letter\n", ch);

  /* Test to see if the first value contains hexideciaml values */
  if (isxdigit(ch)) printf("%c is a Hexadecimal Digit\n", ch);  
}