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

// Function to initialize the AppGui struct & initialize the GTK library
void initializeAppGui(GtkGui *appGui, int argc, char *argv[]) {
    appGui->window = NULL;
    appGui->on_gtkgui_init = gtkgui_init;
    appGui->on_gtkcreate_window = gtkcreate_window;
    appGui->on_gtkshow_window = gtkshow_window;
    appGui->on_main = gtkgui_main;

    appGui->on_gtkgui_init(argc, argv);
}

int main(int argc, char *argv[])
{
    GtkGui appGui;

    // Initialize the AppGui 
    initializeAppGui(&appGui, argc, argv);

    // Create the window
    appGui.window = appGui.on_gtkcreate_window();

    // Show the window
    appGui.on_gtkshow_window(appGui.window);

    // Run the main loop
    appGui.on_main();
    
    return 0;
}