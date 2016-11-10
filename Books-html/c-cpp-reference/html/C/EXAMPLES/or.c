/****************************************************************************
 *
 * Purpose: To show the effect of a bitwise OR (|) by converting 
 * 	    an ASCII character to its graphic extension equivalent.
 * Author:  M.J. Leslie.
 * Date:    04-Mar-95
 *
 ****************************************************************************/

main()
{
					/* Hex 66 (f) looks like this in binary
					 *  
					 * 0110 0110
					 */
  unsigned char value='\x66';

					/* Hex 80 looks like this in binary
					 *
					 * 1000 0000
					 */

  printf("%2X %2X \n", value, (value | (unsigned char)'\x80'));

					/* A bitwise OR has the effect of 
					 * adding wanted bits.      
					 *
					 * 0110 0110 (66) OR
					 * 1000 0000 (80)
					 * --------- 
					 * 1110 0110 (E6)
					 */
}

/****************************************************************************
 *
 * Program results are:
 *
 *	66 E6
 *
 ****************************************************************************/
