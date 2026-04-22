//======= Copyright (c) 2026, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     calculator GUI
//
// $NoKeywords: $ivs_project_2 $gui.c
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-22
//============================================================================//
/**
 * @file gui.c
 * @author Daniel Kratky
 *
 * @brief graphical user interface of the calculator app
 */
#include "gui.h"
#include <stdio.h>

/**
 * @brief Global entry widget (defined here, declared in header)
 */
GtkWidget *entry = NULL;

/**
 * @brief Handles button clicks (numbers and operators)
 */
void on_button_clicked(GtkWidget *widget, gpointer data) {
    const char *button_text = gtk_button_get_label(GTK_BUTTON(widget));
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(entry));

    char new_text[256];
    snprintf(new_text, sizeof(new_text), "%s%s", current_text, button_text);

    gtk_entry_set_text(GTK_ENTRY(entry), new_text);
}

/**
 * @brief Clears the display
 */
void on_clear_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

/**
 * @brief Initializes and runs the calculator GUI
 */
int run_calculator(int argc, char *argv[]) {
    GtkWidget *window, *grid;

    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 300);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create grid layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create display entry
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

    // Button labels
    const char *buttons[] = {
        "7","8","9","/",
        "4","5","6","*",
        "1","2","3","-",
        "0","C","=","+"
    };

    int row = 1, col = 0;

    for (int i = 0; i < 16; i++) {
        GtkWidget *btn = gtk_button_new_with_label(buttons[i]);

        if (buttons[i][0] == 'C') {
            g_signal_connect(btn, "clicked", G_CALLBACK(on_clear_clicked), NULL);
        } else {
            g_signal_connect(btn, "clicked", G_CALLBACK(on_button_clicked), NULL);
        }

        gtk_grid_attach(GTK_GRID(grid), btn, col, row, 1, 1);

        col++;
        if (col == 4) {
            col = 0;
            row++;
        }
    }

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

/**
 * @brief Program entry point
 */
int main(int argc, char *argv[]) {
    return run_calculator(argc, argv);
}
