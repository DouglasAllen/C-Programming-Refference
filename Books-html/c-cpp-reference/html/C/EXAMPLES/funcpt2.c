
/************************************************************************
 *
 * Purpose: 1. Define a pointer to a function with parameters.
 *          2. Point at the function.
 *          3. Execute the function passing parameters to it.
 *
 * Author:  M.J. Leslie
 *
 * Date:    04-Jun-95
 *
 ************************************************************************/

int (*fpointer)(int, int);	/* Define a pointer to a function	*/

int add(int, int);		/* Define a few functions.		*/
int sub(int, int);

main()
{
    fpointer = add;		/* Put the address of 'add' in 'fpointer' */
    printf("%d \n", fpointer(4, 5));	/* Execute 'add' and print results */

    fpointer = sub;		/* Repeat for 'sub'			*/
    printf("%d \n", fpointer(6, 2));
}

/************************************************************************/

int add(int a, int b)
{
    return(a + b);
}

/************************************************************************/

int sub(int a, int b)
{
    return(a - b);
}
