/************************************************************************
 *
 * Purpose: To read and verify a password.
 * Compile: gcc password.c -lcurses
 * Notes:   To read text from the keyboard on a UNIX system without 
 *	    it being echoed to the screen you can use noecho() and 
 *	    getch() from curses.h In DOS you can use getch() in conio.h
 * Author:  M. J. Leslie
 * Date:    12-Mar-94
 *
 ************************************************************************/

#include <curses.h>

main()
{
  int  i;
  char buffer[80];			/* work buffer			*/

  initscr();				/* initialize the screen	*/

  printw("Please enter a password => ");	/* update screen image		*/
  refresh();				/* Update screen with screen image */
  noecho();				/* Suppress echo to the screen	*/
					/* Read characters until C/R	*/ 
  while((buffer[i] = getch()) != '\n') i++;

  printw("\nPassword is %s - press return to continue.",buffer);
  refresh();
  getch();

  endwin();				/* Shut down curses		*/
}
