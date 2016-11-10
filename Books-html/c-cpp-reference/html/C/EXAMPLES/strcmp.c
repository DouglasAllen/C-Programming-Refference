/******************************************************************
 *
 * Purpose: Program to demonstrate the use of strcmp.
 * Date:    05-Dec-96
 * Author:  M J Leslie.
 * Descrip: The standard strcmp returns 0 when the strings match 
 *          and indicates which string is lexigraphically greater.
 *          Every time I have used strcmp, I have never been interested
 *          in which string is greater and always frustrated that the 
 *          return code is inverted. This function tidys things up.  
 *
 ******************************************************************/

#include <string.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0

int StringCompare(char *s1, char *s2);

main()
{
    char   	One[] = "Bartman";
    char	Two[] = "Batman";

    int		Ret;

    Ret = StringCompare(One, Two);

    if (Ret == TRUE)
    {
        puts("The Strings match");
    }
    else
    {
        puts("The Strings do not match");
    }
}

/**************************************************************/

int StringCompare(char *s1, char *s2)
{
    int Ret;

    if (strcmp(s1, s2))
    {
        Ret = 0;
    }
    else
    {
        Ret = 1;
    }

    return (Ret);
}
