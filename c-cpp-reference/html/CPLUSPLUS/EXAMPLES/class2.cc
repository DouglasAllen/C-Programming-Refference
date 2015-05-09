/************************************************************************
 *
 * Purpose:
 * Author:  M J Leslie
 * Date:    26-Oct-98
 *
 ************************************************************************/


#include <stdlib.h>
#include <iostream.h>               // Instead of stdio.h

class string 
{
    public:
  
    // Constructor.

    string()
    {  
    Age=35;
    }
   
    // Destructors (Clear storage - free()).

    ~String()
    {}
    
    // ... Overloaded functions.
     
    void print()           
    { 
    cout << "Martin is " << Age << endl ; 
    }
    
    void print(char * str) 
    { 
    cout << "** " << str << " **\n"; 
    }

    private:
        
    int Age;                    // Declare Age
  
};

main()
{
    string test;    // Constructor inserted by the compiler here.
    
    test.print();
    test.print("Leslie");
}
