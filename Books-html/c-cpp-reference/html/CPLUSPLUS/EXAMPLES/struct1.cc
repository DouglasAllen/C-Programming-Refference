/******************************************************************
 *
 * Purpose: Program to demonstrate struct in C++.
 * Date:    04-Aug-97
 * Author:  M J Leslie.
 * Descrip:
 *
 ******************************************************************/

#include <stdio.h>                          // printf

struct Person
{
    // ... Declare the variables in the 'Person' structure.
    // ... This is normal C syntax.
        
    char Name[35];
    int  Age;

    // ... Declare a function within the structure. This is
    // ... new to C++
    
    int  YearsToRetire(void)         // \
    {                                // ---  Function in a structure.
        return 65-Age;               // ---
    }                                // /
};

// ... Program to test the 'Person' structure.

int main(int argc, char **argc )
{
    // ...  Create a person called Mr Leslie.
        
    Person Mr_Leslie;

    // ...  Put some data into the structure.
        
    strcpy(Mr_Leslie.Name, "Martin");
        
    Mr_Leslie.Age=36;

    // ...  Extract data from the structure.
    // ...  Use the 'YearsToRetire' function to
    // ...  Calculate the number of years this poor
    // ...  soul has to work before retirement.
    
    printf("%s will retire in %d years\n",
           Mr_Leslie.Name,
           Mr_Leslie.YearsToRetire());    // <--  Call the function.

    return (0);
}
