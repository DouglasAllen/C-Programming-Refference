#include <string.h>
#include <stdio.h>

char line[100];

main()
{
    (void)printf("Enter a line: ");
    (void)fgets(line, sizeof(line), stdin);

    (void)printf("The length of the line is: %d\n", strlen(line));
    return (0);
}
