/************************************************************************
 *
 * Purpose: Program extracts information from the X server and displays
 *          it on the screen.
 *
 * Notes:   Use the following command to compile. 
 *
 *                      gcc hardware.c -o hardware -lX11
 *
 * Author:  M.J. Leslie
 *
 * Date:    26-Mar-95
 *
 ************************************************************************/

/****************** Includes ********************************************/
/* These are in /usr/X386		*/
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>

main()
{
	Display * display;
	int       screen;
	char *    display_name=NULL;
	Window    root;
	Visual*   visual;

	/* Connect to X display server.		*/
	display=XOpenDisplay(display_name);

	/* Get screen ID			*/
	screen=DefaultScreen(display);


	printf("\n\tInformation extracted from the X server\n");
	printf("\t---------------------------------------\n\n");

	printf(" X server by \'%s\'\n",        ServerVendor(display));

	printf(" X Server protocol %d\n",      ProtocolVersion(display));

	printf(" X server Release %d\n",       VendorRelease(display));

	printf(" Screen is %dmm high.\n",      DisplayHeightMM(display, screen));

	printf(" Screen is %dmm wide.\n",      DisplayWidthMM(display, screen));

	printf(" Screen is %d pixels high.\n", DisplayHeight(display, screen));

	printf(" Screen is %d pixels wide.\n", DisplayWidth(display, screen));

	visual = DefaultVisual(display,screen);
	printf(" %3d Colour map entries", visual->map_entries);
	printf(" (Number of colours on the screen at one time).\n");

	printf(" %3d Display planes (bits per screen pixel).\n", DisplayPlanes(display, screen));

	printf(" There is %d screen(s).\n", ScreenCount (display));
}
