/************************************************************************
 *
 * Purpose: To read numbers entered by the user and sort them.
 * Author:  M.J.Leslie
 * Date:    30-Nov-94
 *
 ************************************************************************/

/********** Preprocessor  ***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/********** Functions ***************************************************/

int read_nums(int *);
void display_nums(int *);
int comp_nums(const int *, const int *);

/********** main ********************************************************/

main()
{
  int numbers[30];			/* Numbers to be sorted.	*/
  int how_many=0;			/* Number of numbers entered	*/

					/* Get the numbers		*/
  how_many = read_nums(numbers);

  puts("\nThese are the unsorted numbers\n");
  display_nums(numbers);

					/* SORT the numbers held in 
					 * 'numbers'.			*/
  qsort(
	numbers, 			/* Pointer to elements		*/
	how_many, 			/* Number of elements		*/
	sizeof(int),  			/* size of one element.		*/
	(void *)comp_nums		/* Pointer to comparison function */
	);

  puts("\nThese are the sorted numbers\n");
  display_nums(numbers);
}

/************************************************************************
 *
 * comp_nums: Compare two numbers.
 *
 ************************************************************************/

int comp_nums(const int *num1, const int *num2)
{
  if (*num1 <  *num2) return -1;
  if (*num1 == *num2) return  0;
  if (*num1 >  *num2) return  1;
}

/************************************************************************
 *
 * readnums: read numbers from the keyboard and put them into an array.
 *
 ************************************************************************/

int read_nums(int *array)
{

  char data[80];			/* Data entered by the user	*/
  int inc=0;

  puts("\n\tPlease enter some integer numbers");
  puts("\tno checking is made on the data you enter....");
  printf("\t==> ");

  gets(data);
					/* Assume we have valid data.	
					 * Put it into an array.	*/
  *(array+inc) = atoi(strtok(data," "));
  inc++;
   
  while ( *(array+inc) = atoi(strtok(NULL," "))) inc++;

					/* Return the number of items
					 * stored in 'array'.		*/
  return inc++;
}

/************************************************************************
 *
 * display_nums: Display the numbers
 *
 ************************************************************************/

void display_nums(int *array)
{
					/* NULL is a pointer to 0, 
					 * so it must be cast to an
					 * integer			*/
  while ( *array != (int)NULL)
  {
    printf("%d ",*array);
    array++;
  }

  puts("");
}
