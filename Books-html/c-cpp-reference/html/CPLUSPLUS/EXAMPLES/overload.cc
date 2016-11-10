    
   #include <iostream.h>
    
    void Add(int Left,   int Right);
    void Add(double Left, double Right);

    main ()
    {
        
        Add(5, 9);
        Add(3.2, 7.1);
    }
 
    // integer version of Add.
       
    void Add(int Left, int Right)
    {
        cout << Left << " + " << Right << " = " << Left+Right << endl;
    }
    
    // float version of Add.
    
    void Add(double Left, double Right)
    {
        cout << Left << " + " << Right << " = " << Left+Right << endl;
    }
     
