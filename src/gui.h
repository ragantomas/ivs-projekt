//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     calculator GUI
//
// $NoKeywords: $ivs_project_2 $gui.h
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-23
//============================================================================//
#ifndef GUI_H
#define GUI_H

/**
 * @file gui.h
 * @author Daniel Kratky
 *
 * @brief Header file for the graphical user interface of the calculator app
 *
 * This file declares the global variables and function prototypes
 * used in the calculator program. The calculator provides a basic
 * graphical user interface (GUI) with buttons and a display field
 */

#include <stdio.h>
#include <string.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

/**
 * @brief Handles button clicks (numbers and operators)
 *
 * Appends the pressed button's label to the display.
 *
 * @param button Pointer to the button widget
 * @param display Pointer to the display entry
 * both parameters are necessary to folow the gtk conventions and work with other functions
 * they can accept null pointers if unused
 */
void on_button_clicked(GtkWidget *button, GtkWidget *display);

/**
 * @brief Clears the display
 *
 * Sets the display text to an empty string.
 *
 * @param button Pointer to the button widget
 * @param display Pointer to the display entry
 * both parameters are necessary to folow the gtk conventions and work with other functions
 * they can accept null pointers if unused
 */
void on_clear_clicked(GtkWidget *button, GtkWidget *display);

/**
 * @brief Deletes the last character from the display
 *
 * Removes the last character in the entry field if it exists.
 *
 * @param button Pointer to the button widget
 * @param display Pointer to the display entry
 * both parameters are necessary to folow the gtk conventions and work with other functions
 * they can accept null pointers if unused
 */
void on_backspace_clicked(GtkWidget *button, GtkWidget *display);

/**
 * @brief Deletes the last character from the display
 *
 * Removes the last character in the entry field if it exists.
 *
 * @param window Pointer to the window widget
 * @param event Pointer to the event that triggered the signal
 * @param display Pointer to the display entry
 * all three parameters are necessary to folow the gtk conventions and work with other functions
 * they can accept null pointers if unused
 */
gboolean on_key_press(GtkWidget *window, GdkEventKey *event, GtkWidget *display);

/**
 * @brief Initializes and runs the calculator GUI
 *
 * Creates the window, sets up all widgets, and starts
 * the GTK main event loop.
 *
 * @param argc Argument count from main()
 * @param argv Argument vector from main()
 * @return int Exit status
 */
int run_calculator(int argc, char *argv[]);

#endif // GUI_H
