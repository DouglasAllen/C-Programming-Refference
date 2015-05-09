#include <stdio.h>

main() {
    int counter;    /* loop counter */
    for (counter = 0; counter < 3; counter++) {
        int temporary = 1;
        static int permanent = 1;

        (void)printf("Temporary %d Permanent %d\n",
            temporary, permanent);
        temporary++;
        permanent++;
    }
    return (0);
}
