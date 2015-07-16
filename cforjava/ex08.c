/* gcc -o ex08 ex08.c */

#include <stdio.h>

void swap(int*, int*);

void main(void){
  int num1=5, num2=10;
  int* ptr = &num1;
  swap(ptr, &num2);
  printf("num1=%d and num2=%d\n", num1, num2);
}

void swap(int* p1, int* p2){ /* pass by reference */
  int temp;
  temp = *p1;
  (*p1) = *p2;
  (*p2) = temp;
}
