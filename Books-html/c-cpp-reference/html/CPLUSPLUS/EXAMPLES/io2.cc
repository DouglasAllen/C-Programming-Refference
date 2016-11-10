/************************************************************************
 *
 * Purpose:
 * Author:  M J Leslie
 * Date:    26-Oct-98
 *
 ************************************************************************/


#include <fstream.h>                // ifstream, ofstream, fstream
#include <iostream.h>               // cin, cout

main()
{
  char buf[255];
  char File[]="tempfile";
  
  cout << "Please enter a string => ";      // O/P to STDOUT (screen).
  cin >> buf;                   // Read from STDIN (keyboard).
  
  cout << " Writing string to " << File << "\n";
  
  ofstream fp(File);                    // Open file for O/P
  fp << buf << "\n";                // Write to the file.

        // ... File is closed at program end.
}
