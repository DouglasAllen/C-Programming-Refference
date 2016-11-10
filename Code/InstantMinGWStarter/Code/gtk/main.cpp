#include <gtk/gtk.h>
#include <cairo.h>
#include <pango/pangocairo.h>
#include <gdk/gdk.h>
#include <curl/curl.h>
#include <curl/easy.h>

GtkWidget* CreateWindow()
{
	GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW (window), "Gtk+ Sample Application");
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	return window;
}

void ShowMessage(GtkWidget* widget, gpointer data)
{
	GtkWidget* message = gtk_message_dialog_new((GtkWindow*)data, GTK_DIALOG_MODAL,
											    GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Message is a string of text");
	gtk_dialog_run(GTK_DIALOG(message));
	gtk_widget_destroy(message);
}

void CreateMsgButton(GtkWidget* box)
{
	GtkWidget* button = gtk_button_new_with_label("Show Message"); 
    gtk_widget_show(button);	
    g_signal_connect(G_OBJECT(button), "clicked",
                     G_CALLBACK(ShowMessage), NULL);
	gtk_container_add(GTK_CONTAINER(box), button);
}

void CreateQuitButton(GtkWidget* box)
{
	GtkWidget* button = gtk_button_new_with_label("Exit Program"); 
    gtk_widget_show(button);	
    g_signal_connect(G_OBJECT(button), "clicked",
                     G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_add(GTK_CONTAINER(box), button);
}

int main(int argc, char* argv[])
{
	/* Initialize i18n support */
  gtk_set_locale ();
	
  /* Initialize the widget set */
	gtk_init(&argc, &argv);
	
  /* Create the main window */
	GtkWidget* mainwin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	//~ GtkWidget* window = CreateWindow();
	
	GtkWidget* box = gtk_vbox_new(FALSE, 0);
	gtk_widget_show(box);

	CreateMsgButton(box);
	
	CreateQuitButton(box);

	gtk_container_add(GTK_CONTAINER(mainwin), box);	
	//~ gtk_container_add(GTK_CONTAINER(window), box);	
	
	/* Show the application window */
  gtk_widget_show_all (mainwin);
	//~ gtk_widget_show_all(window);
	
  /* Enter the main event loop, and wait for user interaction */
  gtk_main ();
  
  /* The user lost interest */
	return 0;
}
