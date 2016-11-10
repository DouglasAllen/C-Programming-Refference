int function1(char* array);

main()
{
					/* The array MUST be initalised
					   otherwise the pointer will not 
					   be defined. 	                */
					/* We have one less so the \0 
					   will fit 			*/
  char array1[10]="987654321";

  function1(array1);			/* Pass the pointer to the array */

  printf("%s\n", array1);			/* O/P the altered array.	*/

}
 
/************************************************************************/
 
function1(char * array)
{
					/* Pass a pointer to the string.*/
  printf("%s\n", array);

  array +=4;				/* Modify the pointer.		*/
  *array = 'x';				/* Modify the data pointed to
					   by 'array'			*/

}

