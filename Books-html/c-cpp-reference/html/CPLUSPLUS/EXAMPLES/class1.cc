/************************************************************************
 *
 * Purpose: First example of the class statement.
 * Author:  M J Leslie
 * Date:    26-Oct-98
 *
 ************************************************************************/


#include <stdlib.h>
#include <iostream.h>               // Instead of stdio.h

class String 
{
public:

    void Set(char *InputStr)   // Declare an Access function
    { 
        strcpy(Str, InputStr); 
    }
      
    char *Get(void)                // Declare an Access function
    { 
        return(Str); 
    }

    private:

    char Str[80];      // Declare a hidden variable.
};

main()
{
    String Title;

    Title.Set("My First Masterpiece.");

    cout << Title.Get() << endl;
}
