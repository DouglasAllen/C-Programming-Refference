/************************************************************************
 * 
 * Purpose: To test the system function.
 *
 * Author:  M J Leslie
 * Date:    23-Oct-95
 *
 ************************************************************************/

#include <stdlib.h>

main()
{
				/* Execute an system command and wait 
				 * for it to end.
				 * DO NOT ATTEMPT TO RUN INERACTIVE CMDS*/
  system("ls -l");
}
