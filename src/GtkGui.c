#include "GtkGui.h"


void gtkgui_set_encrypt_tab(GtkWidget *tab);

void gtkgui_set_decrypt_tab(GtkWidget *tab);

// Callback function to handle the "destroy" event
void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

void on_button_clicked()
{

}

void gtkgui_init(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
}

GtkWidget *gtkcreate_window() {
    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "EncryptApp");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a notebook to hold the tabs
    GtkWidget *notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    // Create the encrypt GUI tab
    GtkWidget *encryptTab = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *encryptLabel = gtk_label_new("Encrypt");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), encryptTab, encryptLabel);

    // Create the decrypt GUI tab
    GtkWidget *decryptTab = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *decryptLabel = gtk_label_new("Decrypt");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), decryptTab, decryptLabel);

    // Create the about GUI tab
    GtkWidget *aboutTab = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *aboutLabel = gtk_label_new("About");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), aboutTab, aboutLabel);

    // Set the encrypt tab as the default tab
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 0);

    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    gtkgui_set_encrypt_tab(encryptTab);

    gtkgui_set_decrypt_tab(decryptTab);

    return window;
}


void gtkshow_window(GtkWidget *window)
{
    // Show the window
    gtk_widget_show_all(window);
}

void gtkgui_main() {
    gtk_main();
}

void gtkgui_set_encrypt_tab(GtkWidget *tab) {

    // Create a vertical box container
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(tab), vbox);

    // Create a label for the key input
    GtkWidget *keylabel = gtk_label_new("Key:(max 16 chars)");
    gtk_box_pack_start(GTK_BOX(vbox), keylabel, FALSE, FALSE, 0);

    // Create a texbox for key input
    GtkWidget *keybox = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), keybox, FALSE, FALSE, 0);

    // Create a label for the input
    GtkWidget *encryptlabel = gtk_label_new("Encrypt this:");
    gtk_box_pack_start(GTK_BOX(vbox), encryptlabel, FALSE, FALSE, 0);

    // Create a textbox for input
    GtkWidget *textbox = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), textbox, FALSE, FALSE, 0);

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Encrypt");
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

    // Connect the button to a callback function
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), textbox);

}

void gtkgui_set_decrypt_tab(GtkWidget *tab) {

    // Create a vertical box container
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(tab), vbox);

    // Create a label for the key input
    GtkWidget *keylabel = gtk_label_new("Key:(max 16 chars)");
    gtk_box_pack_start(GTK_BOX(vbox), keylabel, FALSE, FALSE, 0);

    // Create a texbox for key input
    GtkWidget *keybox = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), keybox, FALSE, FALSE, 0);

    // Create a label for the input
    GtkWidget *encryptlabel = gtk_label_new("Decrypt this:");
    gtk_box_pack_start(GTK_BOX(vbox), encryptlabel, FALSE, FALSE, 0);

    // Create a textbox for input
    GtkWidget *textbox = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), textbox, FALSE, FALSE, 0);

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Decrypt");
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

    // Connect the button to a callback function
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), textbox);

}