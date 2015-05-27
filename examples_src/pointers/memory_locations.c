#include <stdio.h>
#include <stdlib.h>

int 
func(void *Ptr);

void 
Func(char **DoublePtr);

int
main()
{
	int *Width;
	Width  = (int *)malloc(sizeof(int));
	
	printf("Address stored at Width = %p\n",  Width);
	printf("           Address of Width = %p\n", &Width);
	
	*Width = 34;

	printf("    Data stored at *Width = %d\n", *Width); 
	
	int    count;		/* an integer variable              */
	int   *pcount;		/* a pointer to an integer variable */
	float  miles;		/* a floating point variable.	    */
	float *m;			/* a pointer			    */
	char   ans;			/* character variable		    */ 	
	char  *charpointer;		/* pointer to a character variable  */
	
	char colours[3][6]={"red","green","blue"};
	printf("%s \n", colours[0]);
	printf("%s \n", colours[1]);
	printf("%s \n", colours[2]);
	printf("%s \n", *(colours+0));
	printf("%s \n", *(colours+1));
	printf("%s \n", *(colours+2));
	
	char *colors[]={"red","green","blue"};
	printf("%s \n", colors[0]);
	printf("%s \n", colors[1]);
	printf("%s \n", colors[2]);
	printf("%s \n", *(colors+0));
	printf("%s \n", *(colors+1));
	printf("%s \n", *(colors+2));
	
	char colour[]="red";		
	printf("%s \n",colour);
	
	char *color="red";
	printf("%s \n",color);
	
	char *Str = "abc";

	print(Str);
	
	char **DoublePtr;
	
	char *Ptr;
	Func(&Ptr);
	
	return 0;
}

int 
print(void *Ptr)
{
	printf("%s\n", Ptr);
}

void 
Func(char **DoublePtr)
{
	*DoublePtr = malloc(50);
}