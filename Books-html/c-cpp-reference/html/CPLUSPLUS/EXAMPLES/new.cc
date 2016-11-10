
/**************************************************************************
 *
 * Language: C++
 * Purpose:  Program to demonstrate the 'new' statement.
 * Author:   M J Leslie
 * Date:     14-Feb-96
 *
 **************************************************************************/

#include <iostream.h>                  // For cout.

typedef struct
  {
    char Model[256];
    int  Wheels;
    int  Doors;
    int  EngineSize;
  } Car_t;

main()
{
  Car_t *Models;                       // Create a pointer.

  Models = new Car_t;                  // Allocate stoarage.

                                       // Load with data.
  strcpy(Models->Model, "Escort");
  Models->Wheels = 4;
  Models->Doors  = 3;
  Models->EngineSize = 1499;

                                       // Display data.

   cout << Models->Model << " has " << Models->Doors << "doors" << endl;

   delete Models;                      // Free the storage. 
}

