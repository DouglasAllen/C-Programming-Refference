
/**************************************************************************
 *
 * Language: C++
 * Purpose:  Program to demonstrate the 'try', 'catch' and 'throw' statements.
 * Author:   M J Leslie
 * Date:     21-Mar-98
 *
 * Compile:  The following command was used to compile.
 *
 *                  g++ -fhandle-exceptions throw.cc -o throw
 *
 **************************************************************************/

#include <iostream.h>                  // For cout.

void ErrorFunc(int Error);

main()
{
    ErrorFunc(0);
    ErrorFunc(1);
}
void ErrorFunc(int Error)
{
    try
    {
        cout << "Error code is " << Error << endl;

        if (Error > 0 )
        {
            throw(Error);        // This statement causes control to jump
                                 // to the 'catch' statement
        }

        cout << "No Error occoured" << endl;

    }
    catch(int n)
    {
        cout << "Error number is " << n << endl;;
    }
}
