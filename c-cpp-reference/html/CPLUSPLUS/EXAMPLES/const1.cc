
/**************************************************************************
 *
 * Language: C++
 * Purpose:  Program to demonstrate the 'new' statement.
 * Author:   M J Leslie
 * Date:     27-Sep-98
 *
 * Initialise a constant within a class.
 *
 **************************************************************************/

#include <iostream.h>                  // For cout.

class Math
{
public:
   
    // Constructor contains the definition of PI.

    Math() : PI(3.142) {}

    ~Math() {}
    
    float Diameter (float Radius)
    {
        return (Radius * PI);
    }

private:

    // Declare PI. We can not assign a value here.

    const float PI;
      
};

main()
{
    Math    Formula;
    float   Radius = 5;

    cout << " Radius is   " << Radius << endl;
    cout << " Diameter is " << Formula.Diameter(Radius) << endl;
}

