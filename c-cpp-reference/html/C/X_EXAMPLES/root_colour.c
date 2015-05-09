/************************************************************************
 *
 * Purpose: Program to randomly change the root window colour on X Displays.
 *
 * Description. 
 *	    The program randomly selects a target colour and then 
 *          performs a basic interpolation to move from the current 
 *          colour to the target colour. When the target has been
 *	    reached, a new target is selected and the process is 
 *	    repeated.
 *
 * Notes:   1) No attempt is made to see if the client supports colour.
 *	    2) Other applications may cause problems if they have allocated
 *	       all the available colour cells in the colour map.
 *	    3) Use the following command to compile. 
 *
 *			gcc root_col.c -lX11
 *	    4) Tested on Linux running XFree386 and FVWM
 *	       and SunOS 4.1.3 running X11R5 and Motif.
 *
 * Author:  M.J. Leslie
 *
 * Date:    26-Mar-95
 *
 ************************************************************************/
/****************** Includes ********************************************/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>
#include <stdlib.h>

/************************************************************************/

#define INC     512			/* Increments between colours.	*/
#define MAX_COL 65536			/* Max number of colours.	*/
#define SECONDS 2			/* # of seconds between updates	*/

/****************** Functions *******************************************/

void help(char * proganme);		/* Give some help on syntax.	*/

					/* Used to see if a colour gun has 
					 * reached its required intensity
					 */
int reached_target( unsigned short colour, unsigned short target_colour);

void root_colour(int seconds); 		/* Where the real work starts.	*/

					/* Change the colour of the 
					 * root window			*/
void change_colour(Display * display, 	
	           Window root, 
	           Colormap colormap, 
	           XColor colour);

/************************************************************************/

main(int argc, char * argv[])
   {
   int seconds=SECONDS;
					/* Have we got cmd line parms?	*/
   if (argc > 1 )
      {
					/* Yes. Is Help Required?	*/
      if ( !strcmp(argv[1], "-h"))
         {
         help(argv[0]);			/* Yes.				*/
         exit(0);
         }
					/* Do we have an integer.	*/
      if (!sscanf(argv[1], "%u", &seconds))
         {
         help(argv[0]);			/* No.				*/
         exit(0);
         }
         
      }

   root_colour(seconds);		/* Start colouring the 
					 * root window.
					 * 'seconds' is the # of seconds 
					 * between updates.		*/
   }

/************************************************************************/

void root_colour(int seconds)
   {
   Display * display;
   int       screen;
   char *    display_name=NULL;
   Window    root;
   Colormap  colormap;
   XColor    colour, target_colour;

				/****************************************
				 *
				 * Initalise the X environment.
				 *
				 ****************************************/

   				/* Connect to X display server.		*/
   display=XOpenDisplay(display_name);	

				/* Get screen ID			*/
   screen=DefaultScreen(display);

   root=RootWindow(display, screen); 

				/* Load the default colour map 		*/
   colormap = DefaultColormap(display, screen);

				/* Starting colour - Grey		*/
   colour.red=MAX_COL/2; colour.green=MAX_COL/2; colour.blue=MAX_COL/2;

   colour.flags = DoRed|DoGreen|DoBlue;

				/****************************************
				 *
				 * Loop forever.
				 *
				 ****************************************/

   while(1)			
      {
				/* Increments used to go from the current
				 * colour to the target colour.		*/

      int red_inc, green_inc, blue_inc;

				/* Flags used to show when the target 
				 * colour has been reached.
				 *
				 * 0 = Arrived at the target colour.
				 * 1 = Not arrived at the target colour.
				 *					*/
      int red=1, green=1, blue=1;

				/* Random selection of a new target 
				 * colour 				*/

      target_colour.red=rand()%MAX_COL;
      target_colour.green=rand()%MAX_COL;
      target_colour.blue=rand()%MAX_COL;

				/* Calculate the direction to go in 
				 * to reach the new target colour.	*/

      red_inc   = ( target_colour.red   > colour.red  ) ? INC : INC * -1;
      green_inc = ( target_colour.green > colour.green) ? INC : INC * -1;
      blue_inc  = ( target_colour.blue  > colour.blue ) ? INC : INC * -1;


				/* Loop until all three colours have 
				 * reached their required value.	*/

      while(red || green || blue)
         {
				/* Change the colour of the root window */

	 change_colour(display, root, colormap, colour);

				/* Increment onto the next colour.	*/

         if (  red=reached_target(colour.red,   target_colour.red))   
		colour.red   += red_inc;
         if (green=reached_target(colour.green, target_colour.green)) 
		colour.green += green_inc;
         if ( blue=reached_target(colour.blue,  target_colour.blue))  
		colour.blue  += blue_inc;

         sleep(seconds); 	/* Pause......				*/

         }

      }

   XCloseDisplay(display);
   }

/************************************************************************/

int reached_target( unsigned short colour, unsigned short target_colour)
   {
   return (( colour >= target_colour-INC && colour <= target_colour+INC) ?0:1);
   }

/************************************************************************/

void change_colour(Display * display, 
                   Window root, 
                   Colormap colormap, 
                   XColor colour)
   {
				/* Reserve a cell in the colour map	*/

   XAllocColorCells(display, colormap, False, NULL, 0, &colour.pixel, 1);

				/* Place the required colour in the map.*/

   XStoreColor(display, colormap, &colour);

				/* Free the cell so it can be reused.	*/

   XFreeColors(display, colormap, &colour.pixel, 1, 0);

				/* Set the root window colour.		*/

   XSetWindowBackground(display, root, colour.pixel);

				/* Refresh the root window (with the new
				 * colour).				*/

   XClearWindow(display, root);

   }

/************************************************************************/

void help(char * progname)
   {

   printf("\n%s information\n\n", progname);

   puts(" This program randomly changes the color of the screen background.");
   puts("\n Syntax:\n");

   printf("\t%s   \tRun the program with with a default update time\n", progname);
   printf("\t\t     \tof %d seconds.\n", SECONDS);
   printf("\t%s  3\tRun the program specifing the delay between updates.\n", progname);
   printf("\t%s -h\tHelp. you are reading it.\n\n", progname);
   }
