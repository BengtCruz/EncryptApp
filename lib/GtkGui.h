#ifndef GTKGUI_H
#define GTKGUI_H

#include <gtk-3.0/gtk/gtk.h>

typedef struct
{
    GtkWidget *window;
    void (*on_gtkgui_init)(int argc, char *argv[]);
    GtkWidget *(*on_gtkcreate_window)();
    void (*on_gtkshow_window)();
    void (*on_main)();
    
}GtkGui;

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 */
void gtkgui_init(int argc, char *argv[]);

/**
 * @brief 
 * 
 * @return GtkWidget* 
 */
GtkWidget *gtkcreate_window();

/**
 * @brief 
 * 
 * @param window 
 */
void gtkshow_window(GtkWidget *window);

/**
 * @brief 
 * 
 */
void gtkgui_main();


#endif // GTKGUI_H
