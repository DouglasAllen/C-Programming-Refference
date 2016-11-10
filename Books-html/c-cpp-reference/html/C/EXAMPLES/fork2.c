/****************************************************************
 *
 * Purpose: Basic example of fork.
 * Author:  M J Leslie
 * Date:    01 Apr 96
 *
 ****************************************************************/

#include <unistd.h>

int       Value = 5;
main()
{

  pid_t   ForkPID;
  
  printf("Program start. \n");

  ForkPID = fork();			/* Create a child and copy the parents
  					 * parent data space, heap and stack.
					 */

  /* ForkPID == -1 Fork failure.
   *         ==  0 This is the child process.
   *	      >  0 This is the parent process. The number given is the
   *               PID of the child.
   */

  if (ForkPID == 0)
  {
    Value += 4;
  }
  else
  {
    sleep (5);
  }
  printf("Value is %d\n", Value);
  printf("forkPID is %d \n", ForkPID);

  printf("Program end. \n");
}  
  
