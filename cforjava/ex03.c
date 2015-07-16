/* gcc -o ex03 ex03.c */

#include <stdio.h>

void main(void){
	int i = 16;
  int* ptr_int; /* ptr_int points to some random location */
	
	printf("int i = %d\n", i);
	
	ptr_int = &i; /* ptr_int points to integer i */
	
	printf("int i memory location = %p\n", ptr_int);
	
	(*ptr_int) = 3; /* variable pointed by ptr_int takes value 3 */
	
	printf("int i = %d\n", i);
	
	printf("int i memory location = %p\n", ptr_int);
	
	int* p = NULL;

  if (p == NULL){
    printf("Cannot dereference pointer p.\n");
	}

}
