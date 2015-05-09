
/**********************************************************************
 *
 *   Description: If a text string is created outside of C, the 
 *                escape codes are not correctly stored. This 
 *                routine will prepare them for C's use.
 *             
 *   Author :     M.J. Leslie
 *   Date:        25-Feb-96
 *
 *********************************************************************/

void mos_ConvertEscapeCode(char *String, char *Code);

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    puts("\n\tPlease provide a text string on the command line.");
  }
  else
  {
    printf("I/P string is: %s\n", argv[1]);
    mos_ConvertEscapeCode(argv[1], "\\n");
    mos_ConvertEscapeCode(argv[1], "\\t");
    mos_ConvertEscapeCode(argv[1], "\\v");
    mos_ConvertEscapeCode(argv[1], "\\b");
    mos_ConvertEscapeCode(argv[1], "\\r");
    mos_ConvertEscapeCode(argv[1], "\\f");
    printf("O/P string is: %s\n", argv[1]);
  }
}

/**********************************************************************
 *
 *   Purpose: To convert escape codes in text form into
 *            actual codes. 
 *
 *   I/P       -------------------------------
 *            | A | B | C | \ | n | D | E | F |
 *             -------------------------------
 *
 *   O/P       ----------------------------
 *            | A | B | C | \n | D | E | F |
 *             ----------------------------
 *
 **********************************************************************/

void mos_ConvertEscapeCode(char *String, char *Code)
{
  char *Ptr1;
  char *Ptr2;
  char  EscCode = ' ';
  
  /* ...	Make sure the Code is long enough */

  if (strlen(Code) == 2)
  {

    /* ...	Find the right escape code. */

    switch(Code[1])
    {
    case 'n':			/* New line */
      EscCode = '\n';
      break;    
    case 't':			/* Horizontal tab */
      EscCode = '\t';
      break;
    case 'v':			/* Vertical tab */
      EscCode = '\v';
      break;    
    case 'b':			/* Backspace */
      EscCode = '\b';
      break;    
    case 'r':			/* Return */
      EscCode = '\r';
      break;    
    case 'f':			/* Form feed */
      EscCode = '\f';
      break;
    default:
      break;
    }
    
    /* ...	If the escape code has been found */

    if (EscCode != ' ')
    {
      
      /* ...	Copy each character until the text code is found, 
	 ...	insert the escape code and copy the remaining chars. */

      for (Ptr1=Ptr2=String; Ptr2 < (String+strlen(String)+1); Ptr1++, Ptr2++)
      {
	if ((*Ptr2 == '\\') && (*(Ptr2+1) == Code[1])) 
	{
	  *Ptr1 = EscCode;
	  Ptr2++;
	}
	else
	{
	  *Ptr1 = *Ptr2;
	}
      }
    }
  }
}










