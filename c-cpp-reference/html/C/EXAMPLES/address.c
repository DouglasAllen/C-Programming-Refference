/************************************************************************
 *
 * Purpose: Demonstrate the Unary '&'  and '*' operators.
 *          Unary & - Address of a variable.
 *          Unary * - Data at the address.
 *	
 *	    These are not to be confused with their binary equivalents
 *	    that perform bitwise AND and OR.
 *
 * Author:  M J Leslie.
 * Date:    16-Apr-94
 *
 ************************************************************************/

main()
{
    int i=4;				/* variable declaration 	*/
    int* ptr;				/* int pointer			*/

    ptr = &i;				/* 'ptr' now contains the
					   address of 'i'		*/

    printf("  i is  %d.\n", i);
    printf("*ptr is %d.\n", *ptr);
}
