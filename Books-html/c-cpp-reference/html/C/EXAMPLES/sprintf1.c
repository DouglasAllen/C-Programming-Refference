/***********************************************************************
 *
 * Purpose: Program to demonstrate the * flag limiting a string field width
 *          in a 'sprintf' statement.
 *
 *          This example shows an alternative way of performing a strncpy.
 *
 * Author:  M J Leslie
 * Date:    18-Mar-98
 *
 ************************************************************************/

#include <stdio.h>

main()
{
    char Dest[10] = "";
    char Src[]    = "Ski on Whistler Mountain";
                                                  /* Populate Dest */
    memset  (Dest, 0, sizeof(Dest));
    sprintf (Dest, "%.*s", sizeof(Dest)-1, Src);
                                                  /* Show the results. */
    printf("Src string : %s\n", Src);
    printf("Dest string: %s\n", Dest);
}
