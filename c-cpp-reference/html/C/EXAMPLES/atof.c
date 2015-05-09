/****************************************************************
 *
 * Purpose: Program to demonstrate the 'atof' and 'gets' functions.
 * Author:  M J Leslie
 * Date:    08/05/94
 *
 ****************************************************************/

#include <stdio.h> 		/* puts gets			*/
#include <stdlib.h>		/* atof				*/

main()
{
    char str1[80], str2[80];	/* define a couple o' strings.	*/
    double result;		/* Result of multiplication.	*/

    puts ("This program will multiply two floating point numbers.");
    puts ("Warning: The program will accept invalid data, and give");
    puts ("you crap results in return.\n");
    puts ("Please enter the first number.");
    gets(str1);

    puts ("And the second.");
    gets(str2);

    result = atof(str1) * atof(str2);
    printf("Answer is %8.2f\n", result);
}

/********************************************************************
 *
 * Here is an example run.
 * 
 * This program will multiply two floating point numbers.
 * Warning: The program will accept invalid data, and give
 * you crap results as a result.
 * 
 * Please enter the first number.
 * 20
 * And the second.
 * .5
 * Answer is    10.00
 * 
 ********************************************************************/
