/*************************************************************************
 *
 * Purpose: Clear the screen with VT100 escape codes. This can be done
 *          with conio.h on PCs - non standard code. Or curses.h, bit of 
 * 	    a fag...
 * Author:  M.J. Leslie
 * Date:    22-Jun-94
 *
 ************************************************************************/

void clrscr(void);

main()
{
    clrscr();
}

void clrscr(void)
{
    printf("\033[2J");		        /* Clear the entire screen.		*/
    printf("\033[0;0f");		/* Move cursor to the top left hand corner */
}
