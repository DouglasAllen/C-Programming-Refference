/*********************************************************************
 *
 * Purpose: Reverse characters in a string.
 * Author:  K&R
 * Date:    
 *
 *********************************************************************/

void reverse(char s[]);

main()
{
  char text[80]="martin";

  printf("string is %s\n", text);
  reverse(text);
  printf("string is %s\n", text);
}

void reverse(char s[])
{
  int c, i, j;
   
  for (i=0, j=strlen(s)-1; i < j;i++, j--)
  {
    c = s[i];
    s[i] = s [j];
    s[j] = c;
  }
}
