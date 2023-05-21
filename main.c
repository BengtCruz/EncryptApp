/**
 * @file main.c
 * @author Bengt Svedling Cruz (bengtsvedling@hotmail.com)
 * @brief Main program run file for EncryptApp.
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "AesManager.h"
#include "GtkGui.h"

// Function to initialize the AppGui struct
void initializeAppGui(GtkGui *appGui) {
    appGui->window = NULL;
    appGui->on_gtkgui_init = gtkgui_init;
    appGui->on_gtk_create_window = gtkcreate_window;
    appGui->on_gtkshow_window = gtkshow_window;
    appGui->on_main = gtkgui_main;
}

int main(int argc, char *argv[])
{
    GtkGui appGui;

    // Initialize the AppGui struct
    initializeAppGui(&appGui);
    
    // Initialize the GTK gui
    appGui.on_gtkgui_init(argc, argv);

    // Create the window
    appGui.window = appGui.on_gtk_create_window();

    // Show the window
    appGui.on_gtkshow_window(appGui.window);

    // Run the main loop
    appGui.on_main();
    return 0;
}