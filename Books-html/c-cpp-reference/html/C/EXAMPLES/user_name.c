 
/************************************************************************
 *
 * Purpose: Get the users real name with the 'getpwuid' function.
 * Notes:   This is a UNIX only program. It will not work on DOS machines
 *          as 'getpwuid' gets its information from /etc/passwd.
 * Author:  M J Leslie
 * Date:    13-Jan-95
 *
 ************************************************************************/

#include <pwd.h>			/* getpwuid			*/
#include <sys/types.h>

/************************************************************************/

void user_name(void);

/************************************************************************/

main()
{
  user_name();
}

/************************************************************************/

void user_name(void)
{
					/* See the getpwuid man page 
					 * for a description of the
					 * structure.			*/
  struct passwd *passwd;
					/* Get the uid of the running
					 * process and use it to get
					 * a record from /etc/passwd
					 */ 
  passwd=getpwuid(getuid());

  printf("Users Real name is %s\n", passwd->pw_gecos);
}
