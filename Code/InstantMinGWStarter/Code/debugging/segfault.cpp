#include <string.h>

void bar()
{
	int* pointer = NULL;
	*pointer = 10;
}

void foo()
{
	bar();
}

int main()
{
	foo();
	
	return 0;
}
