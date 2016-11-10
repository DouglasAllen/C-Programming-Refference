/************************************************************************
 *
 * Description: Try out the 'uname' function.
 * Author:      M.J. Leslie
 * Date:        28-12-94
 *
 ************************************************************************/

#include <sys/utsname.h>		/* Header for 'uname'		*/

main()
{
  struct utsname uname_pointer;

  uname(&uname_pointer);

  printf("System name - %s \n", uname_pointer.sysname);
  printf("Nodename    - %s \n", uname_pointer.nodename);
  printf("Release     - %s \n", uname_pointer.release);
  printf("Version     - %s \n", uname_pointer.version);
  printf("Machine     - %s \n", uname_pointer.machine);
  printf("Domain name - %s \n", uname_pointer.domainname);
}

/***********************************************************************
 *
 * system name - Linux 
 * Nodename    - norma2 
 * Release     - 1.1.54 
 * Version     - #5 Sat Dec 3 15:08:21 GMT 1994 
 * Machine     - i486 
 * Domain name - (none) 
 *
 ***********************************************************************/
