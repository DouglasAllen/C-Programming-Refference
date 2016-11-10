/************************************************************************
 *
 * Purpose: Program to demonstrate passing a pointer to an array 
 *	    to a function.
 * Author:  M J Leslie.
 * Date:    14-Apr-94
 *
 ************************************************************************/
#define I_SIZE 2

void add(int*); 			/* Function declaration 	*/

main()
   {
   int i[I_SIZE]={4,6};			/* array declaration 		*/
   int count=0;

   for (count=0;count<I_SIZE;count++) 
      printf("i starts out life as %d.\n", i[count]);

   add(i); 				/* Function call       		*/

   for (count=0;count<I_SIZE;count++) \
      printf("            i is now %d.\n", i[count]);

   }

/************************************************************************/

void add(int *ptr)	 		/* Function definition 		*/
   {
   ++*ptr;				/* Add 1 to the first element in 
					   the array			*/
   ++*(ptr+1);				/* And the second element	*/
   return;
   }
