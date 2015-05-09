/****************************************************************
 *
 * Purpose: Program to demonstrate the 'execl' function.
 * Author:  M J Leslie
 * Date:    21-Apr-96
 *
 ****************************************************************/


main(int argc, char *argv[])
{
  execl("exec_two", "exec_two", (char *) 0);
}
