/****************************************************************************
 *
 *  Enumeration example: This program will compile but the #define statement 
 *  will cause FALSE and TRUE to have a value of 1
 *
 ****************************************************************************/

enum Boolian_t {FALSE=0, TRUE} Boolian;

#define FALSE 1

main()
{

  enum Boolian_t Boolian;
    
  printf("False has a value of %d\n", FALSE);
  printf(" True has a value of %d\n", TRUE);
}
/****************************************************************************
 *
 *	Results:
 *
 *	False has a value of 1
 *	 True has a value of 1
 *
 ****************************************************************************/
