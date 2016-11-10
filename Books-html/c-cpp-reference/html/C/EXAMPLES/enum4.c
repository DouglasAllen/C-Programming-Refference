/****************************************************************************
 *
 *  Enumeration example: This program will fail to compile because the 
 *  preprocessor will change the FALSE to 1 on the enum statement....
 *
 ****************************************************************************/

#define FALSE 1

main()
{

  enum Boolian_t {FALSE=0, TRUE} Boolian;
    
  printf("False has a value of %d", FALSE);
  printf(" True has a value of %d", TRUE);
}
