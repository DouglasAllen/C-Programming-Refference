#include <stdio.h>
main()
{
    int  count = 0;     /* number of times through */

    void inc_count(int *);/* update the counter */

    while (count < 10)
        inc_count(&count);

    return (0);
}

void inc_count(int *count_ptr)
{
    (*count_ptr)++;
}
