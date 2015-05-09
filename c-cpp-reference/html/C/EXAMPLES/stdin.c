/************************************************************************ 
 *
 * Purpose: To read data fron 'stdin' (by default the keyboard) 
 *
 * Author:  M. J. Leslie
 *
 * Date:    01-Sep-95
 *
 ************************************************************************/

#include <stdio.h>

void read_stdin(void);

main()
{
  read_stdin();
}

/************************************************************************/

void read_stdin(void)
{
  char line[256];

  while (gets(line))
  {
    printf("%s\n", line);
  }
}
