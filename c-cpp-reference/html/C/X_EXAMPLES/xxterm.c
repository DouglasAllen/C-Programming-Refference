/***********************************************************************
 * Purpose: To provide a tool that allows people to login to machines.
 *
 * Compile: Edit BUTTONS    - Number of machines.
 *      Edit XTERM      - Location of the xterm command.
 *      Edit 'machines' - Names of the machines.
 *
 *      Compile command for Linux and Sun
 *
 *      gcc xxterm.c -o xxterm -lX11
 * User notes:
 *      This is only of use to people running UNIX boxes on a LAN.
 *
 * History: 
 *
 * Rev Date      Author Comments.
 * --- ----      ------ ---------
 * 1.0 30-May-95 MJL    Inital Release.
 */
/****************** Includes ********************************************/
                /* These are in /usr/X386       */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>
#include <unistd.h>     /* setuid               */

/****************** Defines *********************************************/

#define  BUTTONS  7     /* <<<<<--- number of machines.     */

                /* VVVVV--- Location of the xterm comnd */
#define  XTERM              "/usr/X11R5/bin/xterm -sb -e rlogin"

                /* window background colour */
#define  BACKGROUND_COLOUR  "light grey"
#define  BUTTON_COLOUR      "blue"  

#define  DOWN           "down"
#define  ACTIVE         "active"

/****************** Global Variables ************************************/

Display *display;
int      screen;
Colormap colormap;
                /* <<<<<---- Machines you want to access */
char * machines[] = {
    "marin",
    "xarque",
    "dragon",
    "saturn",
    "sentinel",
    "silver",
    "sirius"
    };

/****************** Structures ******************************************/
                /* Hold the co-ordinates of the buttons */
struct {
    XPoint topleft;
    XPoint topright;
    XPoint botleft;
    XPoint botright;
       } buttons[BUTTONS+1];


struct window_info
      {
      Window win;
      GC     gc;
      };

/****************** Functions *******************************************/

void init_buttons(char *button_caps[]);

void draw_image (Window, GC *, char *button_caps[]);

int  draw_button 
    (Window,
     GC *gc, 
     char *text,        /* Text to put on screen button cap */
     int x, int y,      /* Position of button in window     */
     int width, int height, 
     int,
         char button_caps[]);
                /* Change the colour in the graphics
                 * context. 
                 */                 
void set_colour (GC *gc, char *, Colormap);

int  where_am_i (Window, GC *gc);

                /* Take an action based on the 
                 * button ID.
                 */
int process_button
    (Window win, 
     GC *gc, 
     char *button_caps[], 
     int button);       /* Button ID.       */

void press_button 
    (Window, 
     GC *gc, 
     char *button_caps[], 
     char *text );

struct window_info create_window
    (int x,         /* Window size              */
     int y);

                /* Execute system commands      */
void execute_command
    (int root,      /* 1 == must be run by root
                 * 0 == Can be run by anyone        */
     char *command,     /* Command              */
         char *machine);

/************************************************************************/

main()
   {
   unsigned int width, height;      /* Size of the window.      */
   int          x=0, y=0;       /* x is across, y is down!  */
   unsigned int border_width=4;     /* Window border.      */

                /* Array of pointers, one for each screen
                 * button, they point to a string constant
                 * describing their status, active, down,
                 * inactive
                 */
   char *button_caps[BUTTONS+1];

   struct window_info window;

   Window       win;
   GC           gc;
   XEvent       report;
   XFontStruct *font_info;
   XColor       colour;

   char *       display_name=NULL;

   /*********************************************************************
    *
    *   Setup the window environment 
    *
    *********************************************************************/

                /* Connect to X display server.     */
   display=XOpenDisplay(display_name);  

                /* Get screen ID            */
   screen=DefaultScreen(display);

                                /* Load the default colour map          */
   colormap = DefaultColormap(display, screen);

                /* Create the new window with the same 
                   attributes as the parent.        */
                /* Put the info window on the screen    */
   width = 90; height = (BUTTONS+1)* 30 +15+5;
   window=create_window(width, height);
   win = window.win;
   gc  = window.gc;

/************************************************************************
 *
 *      Window environment has been setup.
 *
 *  We must now define the attributes required by the graphics that 
 *  will be placed inside the window.
 *
 ************************************************************************/

   {
   int exit_prog=1;

                /* Initalize the screen buttons     */
   init_buttons(button_caps);

                /* Will stop looping when the 'exit' button
                 * is pressed.
                 */
   while (exit_prog)
      {
                /* Wait for an event....        
                   These are documented in Xlib Programming
                   Manual Volume 1 P.223        */
      XNextEvent(display, &report);   

      switch (report.type)
         {
                /* drawing can only be done on an 'Expose'
                   event                */

     case Expose:       /* Event No. ?              */
            {
                /* Redraw the whole screen.     */
            draw_image(win, &gc, button_caps);
            break;
            }
     case ButtonPress:  /* Event No. 4              */
        {
        int button;
                /* Act on a mouse button press. If the 'exit'
                 * screen button has been pressed, 'exit_prog'
                 * will be set to 0.
                 */
        button=where_am_i(win, &gc);
        process_button(win, &gc, button_caps, button);

                /* Test for exit.           */

        if ( button == BUTTONS)  exit_prog=0;

        break;
            }
     case KeyPress:     /* Event No. 2                          */
        {
        break;      /* Not realy interested....     */
            }
     case 22:       /* Event No. 22                         */
        {
        break;      /* Window moved, i think...     */
            }
         default:
            {
        printf ("Unexpected Event occoured in xxterm window. Event No. is %i\n",
                 report.type);
            break;
            }
         }
      }
   }  
   }
/************************************************************************
 *
 *  root == 1 Command can only be executed by root
 *  root >= 0 Command can be executed by anyone.
 *
 ************************************************************************/
void execute_command(int root, char *command, char *machine)
   {
   char full_cmd[100];
                /* Q. Does this command 'root' authority*/
   if (root)
      {
      if (getuid()) 
         {
         printf("You are not authorised to execute this command\n");
         return;
         }
      }
   strcpy( full_cmd, command);
   strcat( full_cmd, " ");
   strcat( full_cmd, machine);
   strcat( full_cmd, " &");
   system(full_cmd);
   }
/************************************************************************
 *
 *
 *
 *
 *
 ************************************************************************/

int process_button (Window win, GC *gc, char *button_caps[], int button)
   {

                /* locate the button the pointer is in  */
   if (button >= 0 && button < BUTTONS)
      {

      button_caps[button] = DOWN; 
      press_button(win, gc, button_caps, "          " );

      execute_command(0, XTERM, machines[button]);

      sleep(1);

      button_caps[button] = ACTIVE; 
      press_button(win, gc, button_caps, "          " );

      }

                /* Check for exit           */
   if ( button == BUTTONS)
      {
      button_caps[button] = DOWN; 
      press_button(win, gc, button_caps, "          " );

      sleep(1);

      button_caps[button] = ACTIVE; 
      press_button(win, gc, button_caps, "          " );

      }
   return (1);
   }

/****************** Build an image onto the window **********************/

void draw_image (Window win, GC *gc, char *button_caps[])
   {
   int i, x;
                /* Build the screen buttons
                 */

                /* Button states are:
                 *  active (up)
                 *  down
                 *  inactive
                 */
   for (i=0, x=15; i< BUTTONS; i++, x+=30)
      {
     /* Draw_box parms are:
      *      Graphic Context 
      *      |          Text on the button
      *      |          |    x indent from left side
      *      |          |    |    y indent from top
      *      |          |    |    |   width
      *           |          |    |    |   |   height
      *           V          V    V    V   V   V
      */
      draw_button(win, gc, machines[i], 15,  x, 60, 20, i, button_caps[i]) ;
      }
   draw_button(win, gc, "Exit"     , 15, x, 60, 20, i, button_caps[i]) ;

   }
/****************** Draw button with text in it *************************
 *
 *  Draw a button with texted on its cap.
 *
 *  win     Window ID
 *  gc      Graphics context.
 *  text        text to put in the box.
 *  x,y     top left hand corner of the box. x is across the screen
 *      width
 *  height
 *  box     identifing number.
 *  button_state    state of screen button, active, inactive or down
 *
 ************************************************************************/

draw_button(Window win, GC *gc, char *text, int x, int y, 
    int width, int height, int box,
    char button_cap[])
   {

                /* variables to hold the colour names.  
                 ****************************************/
   char top_left_col[80];   /* button shading           */
   char bottom_right_col[80];   /* more button shading.         */
   char text_col[80];       /* Text on button.          */

   int yfudge=height-5;     /* Text location            */
   int xfudge=x+6;

struct {
       XPoint p;
       } points[6];

   int thickness=2;     /* Thickness of the button edge.    */

                /* Co-ordinates for the inner box.  */
   int xinner=x+thickness;
   int yinner=y+thickness;
   int hinner=height-(thickness*2);
   int winner=width-(thickness*2);

                /* Set colours for an "active" button   */
   if (!strcmp(button_cap, ACTIVE))
      {
      strcpy(top_left_col, "white");
      strcpy(bottom_right_col, "slategrey");
      }

                /* Set colours for a "down" button
                 * the button has been pressed.
                 */
   if (!strcmp(button_cap, DOWN))
      {
      strcpy(top_left_col, "slategrey");
      strcpy(bottom_right_col, "white");
      }


                                /* set the border colour.              */

   set_colour(gc, top_left_col, colormap);

                /* Top Left border          */

   points[0].p.x=x;             points[0].p.y=y;
   points[1].p.x=x+width;       points[1].p.y=y;
   points[2].p.x=xinner+winner;     points[2].p.y=yinner;
   points[3].p.x=xinner;        points[3].p.y=yinner;
   points[4].p.x=xinner;        points[4].p.y=yinner+hinner;
   points[5].p.x=x;             points[5].p.y=y+height;

   XFillPolygon( 
    display,
    win,
    *gc,
    points,
    6,
    Nonconvex,
    CoordModeOrigin);

                                /* set the border colour.              */
   set_colour(gc, bottom_right_col, colormap);

                /* Bottom right             */ 
   points[0].p.x=x;             points[0].p.y=y+height;
   points[1].p.x=xinner;        points[1].p.y=yinner+hinner;
   points[2].p.x=xinner+winner;     points[2].p.y=yinner+hinner;
   points[3].p.x=xinner+winner;     points[3].p.y=yinner;
   points[4].p.x=x+width;       points[4].p.y=y;
   points[5].p.x=x+width;       points[5].p.y=y+height;

   XFillPolygon( 
    display,
    win,
    *gc,
    points,
    6,
    Nonconvex,
    CoordModeOrigin);

                                /* set the text colour.             */

   set_colour(gc, BUTTON_COLOUR, colormap);

                /* draw the text that will be on the screen
                 * button cap.
                 */

   XDrawString    (display, win, *gc, 
            xfudge, y+yfudge, /* Bottom left of text    */
            text,  
            strlen(text));

                /* Store the button location        */
   
   buttons[box].topleft.x=x;        buttons[box].topleft.y=y;
   buttons[box].topright.x=x+width; buttons[box].topright.y=y;
   buttons[box].botright.x=x+width; buttons[box].botright.y=y+height;
   buttons[box].botleft.x=x;        buttons[box].botleft.y=y+height;

   }

/************************************************************************
 *
 *  Returns
 *      -1 == Not on a screen button or the screen button is not active
 *        ge 0 == Button number.
 *
 ************************************************************************/
int where_am_i(Window win, GC *gc)
   {

   Window root, child;
   int root_x, root_y;      /* Cursor location on the screen.   */
   int win_x, win_y;        /* Cursor location in the window.   */
   int mask;
   int inc;
   int button;

                /* Get pointer location on the screen
                 * and within the window from the top left
                 * corner. 
                 *  x left to right.
                 *      y top to bottom.
                 */
   XQueryPointer( display, win,
        &root, &child,
        &root_x, &root_y,
        &win_x, &win_y,
        &mask);

                /* win_x and win_y give the usefull position
                 * within the window.
                 */

                /* Scan through each of the button positions
                 * and see if the pointer is in one of them
                 */
   button=-1;
   for (inc = 0 ; inc <= BUTTONS && button == -1; inc++)
      {
      if ( win_x > buttons[inc].topleft.x && win_x <  buttons[inc].topright.x
        && win_y > buttons[inc].topleft.y && win_y <  buttons[inc].botleft.y)
         {
         button = inc;      /* Store the button ID.         */
         }
      }

   return(button);
   }

/************************************************************************
 *
 *  press - status of button then we start the routine.
 *  release - Status of button when we exit the routine (active/inactive)
 *
 ************************************************************************/
void press_button(Window win, GC *gc, char *button_caps[], char *text )
   {

   draw_image(win, gc, button_caps);    /* redraw all the buttons   */
   }
/************************************************************************
 *
 *  Change the colour of any graphics that are drawn after this 
 *  function has been called.
 *
 *  colour - Name of the colour to change to.
 *
 *  For a list of valid colour names:
 *      Use the Unix command 'showrgb'
 *      or look in /usr/lib/X11/rgb
 *      or on Suns you can try the unix command 'xco'.
 *
 ************************************************************************/
void set_colour (GC *gc, char * colour, Colormap colormap)
   {
   XColor   xcolour;
                /* Convert the Colour name into RGB values.
                 */
   XParseColor(display, colormap, colour, &xcolour);
                /* Convert the RGB values into a pixel value.
                 */
   XAllocColor(display, colormap, &xcolour);
                /* Use the pixel value to set the foreground
                 * colour.
                 */
   XSetForeground(display, *gc, xcolour.pixel);
   }

/************************************************************************
 *
 *  Initalise the screen buttons.
 *
 ************************************************************************/
void init_buttons(char *button_caps[])
   {
   int i;

   for (i=0; i <= BUTTONS; i++) button_caps[i] = ACTIVE;

   }
/************************************************************************
 *
 *  Put a window on the screen.
 *
 *  x & y are the size of the window.
 *
 ************************************************************************/
struct window_info create_window(int x, int y)
   {
   struct window_info window;
   XColor             colour;

   
                /* Build background colour 
                 * XParseColor gets rgb values for the named
                 * colour, then XAllocColor gets the pixel 
                 * value from the rgb values.
                 */
   XParseColor(display, colormap, BACKGROUND_COLOUR, &colour);
   XAllocColor(display, colormap, &colour);

                                /* Create the new window with the same 
                                   attributes as the parent.            */
   window.win = XCreateSimpleWindow(display,
                RootWindow(display, screen),
                0, 0,           /* Position                             */
                x, y,           /* Size                                 */
                4,
                WhitePixel(display, screen),    /* Window Border color  */
                colour.pixel);          /* Window Background color */

                                /* Select the event types we want the 
                                 * window to respond to.
                                 * XSelectInput(display,
                 */
   XSelectInput(display,
                window.win,
                ExposureMask |
                KeyPressMask |
                ButtonPressMask |
                StructureNotifyMask );
                

                                /* Make window visable  - this does not 
                                   actually make the window visable 
                                   until we start looking for 'events'  */      
   XMapWindow (display, window.win);

                                /* Create a 'Graphics Context' used to 
                                   hold common attributes requires by 
                                   graphic images, for example colour and 
                                   line thickness.                      */
   window.gc = XCreateGC(display, 
               RootWindow(display, screen), 
               0,
               NULL);

   return window;
   }
