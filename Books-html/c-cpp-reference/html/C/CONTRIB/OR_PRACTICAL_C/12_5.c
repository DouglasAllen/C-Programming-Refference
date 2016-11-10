#include <stdio.h>

int array[10] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int *array_ptr;

main()
{
    array_ptr = array;

    while ((*array_ptr) != 0)
        array_ptr++;

    (void) printf("Number of elements before zero %d\n",
                  array_ptr - array);
    return (0);
}
