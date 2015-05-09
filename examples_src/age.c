/* age.c: Comments on your age  */
/* Compile with:
  make age CFLAGS="-g -Wall -std=gnu11 -O3"
*/
#include <stdio.h>

int main()
{
    int age;
    puts("Enter your age:");
    scanf("%d", &age);
    if (age < 20)
        puts("youth");
    else if (age < 40)
        puts("prime");
    else if (age < 60)
        puts("aches and pains");
    else if (age < 80)
        puts("golden");
    else
    {
        char really;
        printf("Are you really %d?\n", age);
        scanf(" %c", &really);
        if (really == 'Y' || really == 'y')
            puts("Congratulations!");
        else
            puts("I didn't think so!");
    }
    return 0;
}

            
