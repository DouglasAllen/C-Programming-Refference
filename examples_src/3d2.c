/* 3d2.c: Illustrates linear initialization */
/* Compile with:
   make 3d2 CFLAGS="-g -Wall -std=gnu11 -O3"
   */
#include <stdio.h>

int main()
{
  // compiler warnings will result from this syntax
	int a[][3][2] = {1,2,3,4,5,6,7,8,9,0,1,2};
	int i, j, k;

	for (i = 0; i < 2; ++i)             
	{ 
		for (j = 0; j < 3; ++j)
		{
			for (k = 0; k < 2; ++k)
				printf("%d ", a[i][j][k]);
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}

