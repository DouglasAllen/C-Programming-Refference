/************************************************************************
 *
 * Purpose:
 * Author:  M J Leslie
 * Date:    26-Oct-98
 *
 ************************************************************************/


#include <iostream.h>               // cout, cin

main()
{
  char buf[255];
  
  cout << "Please enter a string ==> ";     // O/P to STDOUT (screen).
  cin  >> buf;                  // I/P from STDIN (keyboard).
  cout << "Entered string is " << buf << endl;  
}
