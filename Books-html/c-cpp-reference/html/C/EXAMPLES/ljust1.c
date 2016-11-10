#include <stdio.h>
#include <ctype.h>

void ljust(char *String);
  
main()
{
  char                  Str[]="     Martin    ";

  puts("Function to left justify text.");
  
  printf("*%s*\n", Str);

  ljust(Str);

  printf("*%s*\n", Str);
}

/*****************************************************************/

void ljust(
  char                 *String)
{
  int                   Pos;
  
  /* ...        Keep looping until a non space
     ...        character appears in the first byte. */
  
  while(isspace(String[0]))
  {
    /* ...      Move all the characters left one place. */
    
    for(Pos=0; Pos < strlen(String)-1; Pos++)
    {
      String[Pos] = String[Pos+1];
    }
    
    String[strlen(String)-1] = ' ';
  }
}
