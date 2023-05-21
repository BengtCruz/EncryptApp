#include "GtkGui.h"
#include <gtk-3.0/gtk/gtk.h>

// Callback function to handle the "destroy" event
void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

void gtkgui_init(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
}

GtkWidget *gtkcreate_window() {
    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "My Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Connect the "destroy" event to the callback function
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    return window;
}

void gtkshow_window(GtkWidget *window)
{
    // Show the window
    gtk_widget_show(window);
}

void gtkgui_main() {
    gtk_main();
}
