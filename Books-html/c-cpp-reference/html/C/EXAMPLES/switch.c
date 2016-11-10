/**************************************************************************
 *
 * Purpose: Program to demonstrate the 'switch/case' structure.
 * Method:  Prog looks at the number of parameters passed to it and 
 *          tells the user how many its got.
 * Author:  M J Leslie
 * Date:    09-Apr-94
 *
 **************************************************************************/

main(int argc, char *argv[])
{

  switch (argc)			/* Switch evaluates an expression (argc)  */
  {
				/* If expression resolves to 1, jump here */
  case 1:
    puts("Only the command was entered.");
    break;		        /* break - cases the execution to jump
				   out of the 'switch' block.             */
   
				/* If expression resolves to 2, jump here */
  case 2:
    puts("Command plus one parm entered");
    break;
   
				/* If expression resolves to 3, jump here */
  case 3:
    puts("Command plus two parm entered");
    break;

				/* Any other value jumps here.            */
  default:
    printf("Command plus %d parms entered\n", argc-1);
    break;
  }
}
