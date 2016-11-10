
#include <stdio.h>

main()
{
	char Host[64];
	char User[64];
  char *Buff = "Jobname=job1 Hostname=arnamul User=leslim Time=11:15";
  /*            <---------->          <-----> <---------> <-------->
   *              |                      |         |           |
   *              |           ------------         |           |
   *              |           |   ------------------           V
   *              |           |   |	                      NULL
   *              V           V   V                                    */
  sscanf (Buff, "%*s Hostname=%s %s", Host, User);

  printf("Host is %s\n", Host);
  printf("User is %s\n", User);
  exit(0);
}

/************************************************************************
 *
 *	Job Output is:
 *
 *  Host is arnamul
 *  User is User=leslim
 *
 ************************************************************************/


