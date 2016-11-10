
/************************************************************************
 *
 * Purpose: 1. Define a pointer to a function.
 *          2. Point at a function.
 *          3. Execute the function.
 *
 * Author:  M.J. Leslie
 *
 * Date:    04-Jun-95
 *
 ************************************************************************/

int (*fpointer)(void);		/* Define a pointer to a function	*/

int func1(void);		/* Define a few functions.		*/
int func2(void);

main()
{
    fpointer = func1;		/* Put the address of 'func1' in 'fpointer' */
    fpointer();			/* Execute 'func1'			*/

    fpointer = func2;		/* Repeat for 'func2'			*/
    fpointer();
}

/************************************************************************/

int func1(void)
{
    puts("martin was ere");
}

/************************************************************************/

int func2(void)
{
    puts("alex was ere");
}
