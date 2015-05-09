/****************************************************************
 *
 * Purpose: Basic example of fork.
 * Author:  M J Leslie
 * Date:    01 Apr 96
 *
 ****************************************************************/

#include <unistd.h>

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

  printf("forkPID is %d \n", ForkPID);	/* Child execution starts here. */

  printf("Program end. \n");
}  
  
