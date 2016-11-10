#include <sys/types.h>
#include <unistd.h>
main()
{

	/* Identify the person logged in (real ID). */

  printf("getuid = %d\n", getuid());

	/* Get the ID in use by this process (effective ID).
	 * Normally this is the same as above but if the program is:
	 *
	 * o Owned by root (chown root progname).
	 * o Had 'Set owner' set in the permissions (chmod u+s progname).
	 * o The disk is not mounted 'nosetuid'.
	 *
	 * We can use 'setuid' and 'seteuid'.
	 */

  printf("geteuid = %d\n", geteuid());

  (!geteuid())
      ?
      puts("setuid//setruid/seteuid will work.")
      :
      puts("setuid/setruid/seteuid will fail.");

					/*  0 = OK
					 * -1 = Fail
					 */
/*
   printf("seteuid return code  = %d\n", seteuid(3570));

   printf("getuid = %d\n", getuid());
   printf("geteuid = %d\n", geteuid());

   printf("seteuid return code  = %d\n", seteuid(0));

   printf("getuid = %d\n", getuid());
   printf("geteuid = %d\n", geteuid());
*/

  printf("setuid return code  = %d\n", setuid(4261));

  printf("getuid = %d\n", getuid());
  printf("geteuid = %d\n", geteuid());
}
