#include <string.h>
#include <stdio.h>
char name[30];    /* First name of someone */
main()
{
    (void)strcpy(name, "Sam");    /* Initialize the name */
    (void)printf("The name is %s\n", name);
    return (0);
}
