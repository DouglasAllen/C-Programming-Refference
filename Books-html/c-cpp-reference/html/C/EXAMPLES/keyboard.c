/****************************************************************************
 *
 * Purpose: Reset the keyboard from line mode to character mode and
 *          suppress the echo when a key is entered. This allow the
 *          program to get a character without the user pressing ENTER.
 *
 *          This is for UNIX systems. DOS users have getch and getche.
 *          Unix programers can also use curses.
 *
 * Author:  M.J. Leslie.
 * Date:    30-Mar-97
 *
 ****************************************************************************/

void SetKeyboard  (void);
void ResetKeyboard(void);

main()
{
  char          Characters[1024];
  int           Inc=0;

  memset(Characters, 0, 1024);
  
  printf("Press a load of characters (q=exit)\n");

  SetKeyboard();

  for(Inc = 0; (Characters[Inc] = getchar()) != 'q'; Inc++);
  
  ResetKeyboard();

  printf("You Pressed %s\n", Characters);
}

/* Set the keyboard. */

void SetKeyboard(void)
{
  system("stty raw -echo");
}

/* Return the keyboard to its original state. If this is not called
 * before the program ends, the keyboard will remain in its reconfigured
 * state.
 */

void ResetKeyboard(void)
{
  system("stty -raw echo");
}
