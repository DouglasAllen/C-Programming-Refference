/* Purpose: Demonstrate #if, #else & #endif preprocessors.
 * Author:  M J Leslie    
 * Date:    28-Jun-94
 */

#define SWITCH 0

			/* The #if can only perform 
			 * INTEGER tests!!!!
			 */
#if  ( SWITCH == 1 )
   #define TEXT "Carabanger\n"
#else
   #define TEXT "Hip Dude\n"
#endif

main ()
{
  printf(TEXT);
}
