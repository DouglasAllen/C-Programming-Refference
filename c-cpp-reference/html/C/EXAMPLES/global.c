/************************************************************************
 *
 * Purpose: Demonstrate global and internal variables
 * Author:  M J Leslie
 * date:    02-Feb-94
 *
 ************************************************************************/

int counter = 0;			/* global because we are outside
					   all blocks.			*/
int func(void);

main()
{
  counter++;				/* global because it has not been
					   declared within this block	*/
  printf("counter is %2d before the call to func\n", counter);

  func();					/* call a function.		*/

  printf("counter is %2d after the call to func\n", counter);
}

int func(void)
{
  int counter = 10;			/* local.			*/
  printf("counter is %2d within func\n", counter);
}
