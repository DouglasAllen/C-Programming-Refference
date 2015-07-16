/************************************************************************
 * 
 * Purpose: Extract the directory information from a file name.
 *
 *          /etc/local/bin/fdmount --> fdmount
 *
 *          This mimics the unix command 'basename'.
 *
 * Author:  M J Leslie
 * Date:    29-Feb-96
 *
 ************************************************************************/

#include <string.h>

char *basename(const char *FullName);

main()
{
	char *FullName = "/usr/local/bin/fdmount";

	printf("Full name is %s \n", FullName);

	printf("File name is %s \n", basename(FullName));
}

/************************************************************************/

char *basename(const char *FullName)
{
	static char *File;

	/* ...        I guess DOS users will have to change the direction of
	   ...        the slash. */

	File = strrchr(FullName, '/');

	/* ...        If no slashes have been found, Return the full file name */

	if (File == NULL)
	{
		File = FullName;
	}
	else
	{
		File++;
	}

	return(File);
}

