GTK = `pkg-config --cflags gtk+-2.0 --libs gtk+-2.0`

all :   helloworld hellobuttons packbox table pixmaped_buttons radio_buttons \
        range_controls label arrow_buttons GtkProgressBar rulers Statusbar_example \
	GTK_Entry Spin_Button GtkCalendar_Example Color_selection_test File_selection \
	Event_Box Fixed_Container GTK_Frame_Widget Aspect_Frame Paned_Windows \
	GtkScrolledWindow_example Button_Boxes Notebooks GTK_Menu_Test Item_Factory \
	Event_Box2 Event_Box3 TicTacToe GTK_Dialog Scribble1 Scribble2

helloworld :
	gcc -Wall -g helloworld.c -o helloworld $(GTK)

hellobuttons :
	gcc -Wall -g hellobuttons.c -o hellobuttons $(GTK)

packbox :
	gcc -Wall -g packbox.c -o packbox $(GTK)

table :
	gcc -Wall -g table.c -o table $(GTK)

pixmaped_buttons :
	gcc -Wall -g pixmaped_buttons.c -o pixmaped_buttons $(GTK) 

radio_buttons :
	gcc -Wall -g radio_buttons.c -o radio_buttons $(GTK)

range_controls :
	gcc -Wall -g range_controls.c -o range_controls $(GTK)

label : 
	gcc -Wall -g label.c -o label $(GTK)

arrow_buttons :
	gcc -Wall -g arrow_buttons.c -o arrow_buttons $(GTK)

GtkProgressBar :
	gcc -Wall -g GtkProgressBar.c -o GtkProgressBar $(GTK)

rulers :
	gcc -Wall -g rulers.c -o rulers $(GTK)

 Statusbar_example :
	gcc -Wall -g Statusbar_example.c -o Statusbar_example $(GTK)

GTK_Entry :
	gcc -Wall -g GTK_Entry.c -o GTK_Entry $(GTK)

Spin_Button :
	gcc -Wall -g Spin_Button.c -o Spin_Button $(GTK)

GtkCalendar_Example :
	gcc -Wall -g GtkCalendar_Example.c -o GtkCalendar_Example $(GTK)

Color_selection_test :
	gcc -Wall -g Color_selection_test.c -o Color_selection_test $(GTK)

File_selection :
	gcc -Wall -g File_selection.c -o File_selection $(GTK)

Event_Box :
	gcc -Wall -g Event_Box.c -o Event_Box $(GTK)

Fixed_Container :
	gcc -Wall -g Fixed_Container.c -o Fixed_Container $(GTK)

GTK_Frame_Widget :
	gcc -Wall -g GTK_Frame_Widget.c -o GTK_Frame_Widget $(GTK)

Aspect_Frame :
	gcc -Wall -g Aspect_Frame.c -o Aspect_Frame $(GTK)

Paned_Windows :
	gcc -Wall -g Paned_Windows.c -o Paned_Windows $(GTK)

GtkScrolledWindow_example :
	gcc -Wall -g GtkScrolledWindow_example.c -o GtkScrolledWindow_example $(GTK)

Button_Boxes :
	gcc -Wall -g Button_Boxes.c -o Button_Boxes $(GTK)

Notebooks :
	gcc -Wall -g Notebooks.c -o Notebooks $(GTK)

GTK_Menu_Test :
	gcc -Wall -g GTK_Menu_Test.c -o GTK_Menu_Test $(GTK)

Item_Factory :
	gcc -Wall -g Item_Factory.c -o Item_Factory $(GTK)

Event_Box2 :
	gcc -Wall -g Event_Box2.c -o Event_Box2 $(GTK)

Event_Box3 :
	gcc -Wall -g Event_Box3.c -o Event_Box3 $(GTK)

TicTacToe : tictactoetest.c tictactoe.c tictactoe.h
	gcc -Wall -g tictactoetest.c tictactoe.c tictactoe.h -o tictactoetest $(GTK)

GTK_Dialog : dial_test.c gtkdial.c gtkdial.h
	gcc -Wall -g dial_test.c gtkdial.c gtkdial.h -o dial_test $(GTK)

Scribble1 : scribble-simple.c
	gcc -Wall -g scribble-simple.c -o scribble-simple $(GTK)

Scribble2 : scribble-xinput.c
	gcc -Wall -g scribble-xinput.c -o scribble-xinput $(GTK)
