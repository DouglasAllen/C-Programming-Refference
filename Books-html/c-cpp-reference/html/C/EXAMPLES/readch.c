/*
 * Purpose: Program to demonstrate the 'getchar' function.
 *	The prog will read data entered via the keyboard. And return
 *	the number of characters entered. 
 * Author:  M J Leslie
 * Date:    08-May-94
 */

#include <stdio.h>
#include <unistd.h>

int readch(void);

main()
{
  printf("%c",readch()+1);
}

int readch(void)
{
  char ch;

  read(0, &ch, 1);
  return (ch);
}
