/************************************************************************
 *
 * Purpose:
 * Author:  M J Leslie
 * Date:    26-Oct-98
 *
 ************************************************************************/


#include <stdlib.h>
#include <iostream.h>               // Instead of stdio.h


// ... The base class 'Fabric'
// ... is no different to normal.


class Fabric
{
public:

    Fabric() {};
    ~Fabric(){};

    SetSize(int x, int y)
    {
        Length = x;
        Width  = y;
    }

    SetColour(char *C)
    {
        strcpy(Colour, C);
    }

private:
    int  Length;
    int  Width;
    char Colour[20];
};



// ... The derived class 'Tent'
// ... names 'Fabric' as a base class.


class Tent : public Fabric
{
public:

    Tent() {};
    ~Tent() {};

    SetNumOfPoles(int P)
    {
        Poles = P;
    }

private:
    int  Poles;
};


// ... The derived class 'Clothes' also
// ... names 'Fabric' as a base class.


class Clothes : public Fabric
{
    public:

    Clothes() {};
    ~Clothes() {};
    
    void SetNumOfButtons(int B)
    {
    Buttons = B;
    };
    
    int GetNumOfButtons(void)
    {
    return (Buttons);
    };
    
    private:
    int  Buttons;
};


// ...    Function definitions.

void Init(Fabric &Material);

main()
{  
    Tent       Frame;
    Clothes    Jacket;

    // ... Initialise using the derived methods.
    
    Init(Frame);
    Init(Jacket);

    // .. Initialise using the unique methods.
    
    Frame.SetNumOfPoles(5);
    Jacket.SetNumOfButtons(2);

}

void Init(Fabric &Material)
{
    Material.SetColour("Red");
    Material.SetSize  (10, 20);
}
