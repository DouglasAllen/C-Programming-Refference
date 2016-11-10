/****************************************************************************
 *
 * Purpose: To show the effect of a bitwise AND (&) by converting 
 * 	    an ASCII graphic extension into its character equivalent.
 * Author:  M.J. Leslie.
 * Date:    04-Mar-95
 *
 ****************************************************************************/

main()
{
	/*
	 * Hex E6 looks like this in binary
	 *  
	 * 1110 0110
	 *  
	 * UNSIGNED is used to stop C using    
	 * first 1 as an indicator of the sign
	 */
	unsigned char value='\xE6';

	/* Hex 7F looks like this in binary
	 *
	 * 0111 1111
	 */

	printf("%2X %2X \n", value, (value & '\x7F'));

	/* A bitwise AND has the effect of 
	 * filtering unwanted bits. 
	 *
	 * 1110 0110 (E6) AND
	 * 0111 1111 (7F)
	 * --------- 
	 * 0110 0110 (66)
	 */
}
/****************************************************************************
 *
 * Program results are:
 *
 *	E6 66
 *
 ****************************************************************************/
