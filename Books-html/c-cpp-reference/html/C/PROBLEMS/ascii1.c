/************************************************************************
 * 
 * problem: Display an Ascii table. Basic version
 *
 * Author:  M J Leslie
 * Date:    12-Mar-94
 *
 ************************************************************************/
/* gcc ascii1.c -o ascii1 */

#include <stdio.h>			/* printf, putchar, fopen, fclose */

main()
{
	int count;
	printf("%d\t%x\t%s\n", 0, 0, "NULL");
	for (count=1; count<=8; count++) 
	{
		printf("%d\t%x\t%c\n", count, count, count); /* O/P hex and character formats */
	}
	printf("%d\t%x\t%s\n", 9, 9, "TAB");
	printf("%d\t%x\t%s\n", 10, 10, "NL");
	for (count=11; count<=12; count++) 
	{
		printf("%d\t%x\t%c\n", count, count, count); /* O/P hex and character formats */
	}
	printf("%d\t%x\t%s\n", 13, 13, "CR");
	for (count=14; count<=31; count++) 
	{
		printf("%d\t%x\t%c\n", count, count, count); /* O/P hex and character formats */
	}
	printf("%d\t%x\t%s\n", 32, 32, "SPACE");
	for (count=33; count<=126; count++) 
	{
		printf("%d\t%x\t%c\n", count, count, count); /* O/P hex and character formats */
	}
	printf("%d\t%x\t%s\n", 127, 127, "DEL");
	/* just for fun */
	//~ for (count=128; count<=512; count++) 
	//~ {
	//~ printf("%d\t%x\t%c\n", count, count, count); /* O/P hex and character formats */
	//~ }
}
