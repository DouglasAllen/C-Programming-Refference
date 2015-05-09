/*************************************************************************
 *
 * Purpose: Demonstrate the increment and decrement operators.
 * 
 * Author:  M.J. Leslie.
 *
 * Date:    07-Apr-94
 *
 *************************************************************************/
main()
{

   		/*
    		 *	++i - i incremented before i is used.
    		 *	--i - i decremented before i is used.
    		 *	j++ - j is incremented AFTER j has been used. 
    		 *	j-- - j is decremented AFTER j has been used. 
    		 */

  int i=1,j=1;

  puts("\tDemo 1");
  printf("\t%d %d\n",++i, j++);			/* O/P 	2 1	*/
  printf("\t%d %d\n",i, j);				/* O/P  2 2	*/

  i=1;j=1;

  puts("\n\tDemo 2");
  printf("\t%d \n",i=j++);				/* O/P 	1	*/
  printf("\t%d \n",i=++j);				/* O/P 	3	*/


/************************************************************************

		This is a GOT YA

*************************************************************************/

   						  /* Consider this code */

  i = 0; j = 0;

  puts("\n\tDemo 3");
  if ( (i++ == 1) && (j++ == 1)) puts("Some text");

   	/* Will i and j get incremented? The answer is NO! Because 
     	 * the expression in the left of '&&' resolves to false the 
    	 * compiler does NOT execute the expression on the right and 
    	 * so 'j' does not get executed!!!!! */


  printf("\t%d %d\n",i, j);				/* O/P 1 0	*/

}
