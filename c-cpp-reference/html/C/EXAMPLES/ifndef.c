#include <stdio.h>

					/* Create NULL if NULL was not 
					 * created by stdio.h 		*/
#ifndef NULL
   #define NULL '\0'
#endif

main()
{
  printf("%c \n", NULL);
}
