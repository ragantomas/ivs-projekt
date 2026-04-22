//======= Copyright (c) 2026, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     calculator GUI
//
// $NoKeywords: $ivs_project_2 $gui.h
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-22
//============================================================================//
/**
 * @file gui.h
 * @author Daniel Kratky
 *
 * @brief header file of graphical user interface of the calculator app
 * This file declares the global variables and function prototypes
 * used in the calculator program. The calculator provides a basic
 * graphical user interface (GUI) with buttons and a display field
 */
#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

/**
 * @brief Global pointer to the calculator display entry widget
 *
 * This widget is used to show user input and results
 * It is updated when buttons are clicked
 */
extern GtkWidget *entry;

/**
 * @brief Callback function for handling button clicks
 *
 * This function is triggered whenever a calculator button
 * (numbers or operators) is pressed.
 *
 * @param widget Pointer to the GTK widget that triggered the event
 * @param data Optional user data (not used here)
 */
void on_button_clicked(GtkWidget *widget, gpointer data);

/**
 * @brief Callback function for clearing the display.
 *
 * This function is triggered when the "C" (clear) button is pressed
 * It resets the display to an empty string
 *
 * @param widget Pointer to the GTK widget that triggered the event
 * @param data Optional user data (not used here)
 */
void on_clear_clicked(GtkWidget *widget, gpointer data);

/**
 * @brief Initializes and runs the calculator application
 *
 * This function sets up the GTK environment, creates the main window,
 * initializes all UI components (grid, buttons, display), and starts
 * the GTK main event loop
 *
 * @param argc Argument count from main()
 * @param argv Argument vector from main()
 * @return int Exit status of the application
 */
int run_calculator(int argc, char *argv[]);

#endif
