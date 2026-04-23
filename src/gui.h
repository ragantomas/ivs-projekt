//======= Copyright (c) 2026, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     calculator GUI
//
// $NoKeywords: $ivs_project_2 $gui.h
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-22
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

#include <gtk/gtk.h>

/**
 * @brief Global pointer to the calculator display entry widget
 *
 * This widget is used to display user input and results.
 */
extern GtkWidget *entry;

/**
 * @brief Handles button clicks (numbers and operators)
 *
 * Appends the pressed button's label to the display.
 *
 * @param widget Pointer to the button widget
 * @param data Optional user data (unused)
 */
void on_button_clicked(GtkWidget *widget, gpointer data);

/**
 * @brief Clears the display
 *
 * Sets the display text to an empty string.
 *
 * @param widget Pointer to the button widget
 * @param data Optional user data (unused)
 */
void on_clear_clicked(GtkWidget *widget, gpointer data);

/**
 * @brief Deletes the last character from the display
 *
 * Removes the last character in the entry field if it exists.
 *
 * @param widget Pointer to the button widget
 * @param data Optional user data (unused)
 */
void on_backspace_clicked(GtkWidget *widget, gpointer data);

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
