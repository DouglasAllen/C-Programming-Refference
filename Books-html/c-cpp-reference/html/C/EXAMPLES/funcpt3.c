
/************************************************************************
 *
 * Purpose: 1. Define a pointer to a function with parameters.
 *          2. Point at the function.
 *          3. Execute the function passing char and string parameters to it.
 *
 * Author:  M.J. Leslie
 *
 * Date:    04-Jun-95
 *
 ************************************************************************/

char * (*fpointer)(char *, char);	/* Define a pointer to a function	*/

char * prefix(char *, char);		/* Define a few functions.		*/
char * suffix(char *, char);

main()
{
    fpointer = prefix;		/* Put the address of 'add' in 'fpointer' */
    printf("%s ", fpointer("artin", 'M'));

    fpointer = suffix;		/* Repeat for 'suffix'			*/
    printf("%s \n", fpointer("lesli", 'e'));
}

/************************************************************************/

char * prefix(char *str, char c)
{
    char result[100];
   
    result[0] = c;
    strcpy(result+1, str);

    return(result);
}

/************************************************************************/

char * suffix(char *str, char c)
{
    char result[100];
    int eol;

    strcpy(result, str);

    eol=strlen(result);
    result[eol] = c;
    result[eol+1] = '\0';

    return(result);
}
