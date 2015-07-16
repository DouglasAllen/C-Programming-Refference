/* gcc -o ex04 ex04.c */

#include <stdio.h>

void main(void){
	struct list_elem{
    int data;
    struct list_elem* next;
  };

	struct list_elem le={ 10, NULL };
  struct list_elem* ptr_le = &le;
  printf("The data is %d\n", ptr_le->data);

}