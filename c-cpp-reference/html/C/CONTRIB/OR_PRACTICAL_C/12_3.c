#define ARRAY_SIZE 10   /* Number of characters in array */
/* Array to print */
char array[ARRAY_SIZE] = "012345678";   

main()
{
    int index;  /* Index into the array */

    for (index = 0; index < ARRAY_SIZE; index++) {
        (void)printf(
            "&array[index]=0x%x (array+index)=0x%x array[index]=0x%x\n",
            &array[index], (array+index), array[index]);
    }
    return (0);
}
