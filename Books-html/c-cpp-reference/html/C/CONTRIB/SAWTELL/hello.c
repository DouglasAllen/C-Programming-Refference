#ident "@(#) Hello World - my first program"

#include <stdio.h>

char *format = "%s",
     *hello = "Hello World...\n";

main()
{
  printf ( format, hello );
  }