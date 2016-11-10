/************************************************************************
 *
 * Purpose:
 * Author:  M J Leslie
 * Date:    26-Oct-98
 *
 ************************************************************************/


#include <iostream.h>                           // cout, cin

int Counter = 1;
        
main()     
{
            
   int Counter = 1;
            
   for (int i=0; i< 10; i++)
   {
       cout << Counter << " " << ::Counter << endl;
       Counter++; 
   }
            
   return 0;
}

