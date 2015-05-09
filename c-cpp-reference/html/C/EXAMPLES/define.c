/********************************************************************* 
 *
 * Purpose: Demonstrate the #define pre-processor.
 * Author:  M J Leslie
 * Date:    26-Jun-94
 *
 *********************************************************************/

#define EQ ==

main ()
{
				/* the EQ is translated to == by 
				 * the C pre-processor.	COOL!
				 */
  if ( 5 EQ 5 ) printf("define works...\n");
}
