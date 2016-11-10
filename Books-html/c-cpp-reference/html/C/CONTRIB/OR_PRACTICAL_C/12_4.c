#include <stdio.h>

int array[10] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int index;

main()
{
    index = 0;
    while (array[index] != 0)
        index++;

    (void) printf("Number of elements before zero %d\n",
                  index);
    return (0);
}
