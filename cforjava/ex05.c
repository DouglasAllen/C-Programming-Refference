/* gcc -o ex05 ex05.c */

#include <stdio.h>
#include <stdlib.h>

int no_alloc_var; /* global variable counting number of allocations */

void main(void){
  int* ptr; /* local variable of type int* */
	
  /* allocate space to hold an int */
  ptr = (int*) malloc(sizeof(int));
  no_alloc_var++;
	
  /* check if successfull */
  if (ptr == NULL)
    exit(1); /* not enough memory in the system, exiting */
	
	*ptr = 4; /* use the memory allocated to store value 4 */
  free(ptr); /* dealocate memory */
  no_alloc_var--;
}
