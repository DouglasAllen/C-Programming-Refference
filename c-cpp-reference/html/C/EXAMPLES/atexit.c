
/******************************************************************
 *
 * Purpose: Program to demonstrate the use of atexit.
 * Date:    17-Feb-97
 * Author:  M J Leslie.
 * Descrip: Regester a function to be executed when a program normally
 *          terminates.
 *
 ******************************************************************/

#include <stdlib.h>

void End(void);

main()
{
	atexit(End);

	printf("Program is about to end\n");
}

void End(void)
{
	printf("Program ended\n");
}
