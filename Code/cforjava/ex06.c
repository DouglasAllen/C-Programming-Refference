/* gcc -o ex06 ex06.c */

#include <stdio.h>

int sum(int a, int b); /* function declaration or prototype */
int psum(int* pa, int* pb);

void main(void){
  int total=sum(2+2, 5); /* call function sum with parameters 4 and 5 */
  printf("The total is %d.\n", total);
	
}

/* definition of function sum; has to match declaration signature */
int sum(int a, int b){ /* arguments passed by value */
  return (a+b); /* return by value */
}

int psum(int* pa, int* pb){ /* arguments passed by reference */
  return ((*pa)+(*pb));
}

