/************************************************************************
 *
 * Purpose: Demonstrate the use of reference variables.
 * Author:  M J Leslie
 * Date:    26-Oct-98
 *
 ************************************************************************/


#include <stdio.h>

int Square(int &Val);

main()
{
    int Number=10;

    Square(Number);

    printf("Number is %d\n", Number);
}

int Square(int &Val)
{
    Val *= Val;
}
