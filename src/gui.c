//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     calculator GUI
//
// $NoKeywords: $ivs_project_2 $gui.c
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-23
//============================================================================//
/**
 * @file gui.c
 * @author Daniel Kratky
 *
 * @brief graphical user interface of the calculator app
 */
#include "gui.h"
/**
 * Handles button clicks (numbers and operators)
 */
void on_button_clicked(GtkWidget *button, GtkWidget *entry) {
    const char *button_text = gtk_button_get_label(GTK_BUTTON(button));
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(entry));

    char new_text[256];
    snprintf(new_text, sizeof(new_text), "%s%s", current_text, button_text);

    gtk_entry_set_text(GTK_ENTRY(entry), new_text);
    gtk_editable_set_position(GTK_EDITABLE(entry), -1);
}

/**
 * Clears the display
 */
void on_clear_clicked(GtkWidget *button, GtkWidget *entry) {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    gtk_editable_set_position(GTK_EDITABLE(entry), -1);
}

/**
 * Deletes last character on the display
 */
void on_backspace_clicked(GtkWidget *button, GtkWidget *entry) {
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(entry));
    int len = strlen(current_text);

    if (len > 0) {
        char new_text[256];
        strncpy(new_text, current_text, len - 1);
        new_text[len - 1] = '\0';
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
        gtk_editable_set_position(GTK_EDITABLE(entry), -1);
    }
}

gboolean on_key_press(GtkWidget *window, GdkEventKey *event, GtkWidget *entry) {
    gunichar c = gdk_keyval_to_unicode(event->keyval);

    // Get current text
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(entry));
    char new_text[256];

    // Digits and operators
    if (g_unichar_isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '.' || c == '!' || c == '^') {
        snprintf(new_text, sizeof(new_text), "%s%c", current_text, (char)c);
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
    }
    // Enter → equals
    else if (event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_KP_Enter) {
        //TODO: add parsing the expresion
    }
    // Backspace TODO: backspace could delete characters based on pointer in display
    else if (event->keyval == GDK_KEY_BackSpace) {
        on_backspace_clicked(NULL, entry);
        return TRUE;
    }
    // clear (c or C)
    else if (c == 'c' || c == 'C') {
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    }
    // Square root (r or R)
    else if (c == 'r' || c == 'R') {
        snprintf(new_text, sizeof(new_text), "%s√", current_text);
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
    }
    // log (l key)
    else if (c == 'l' || c == 'L') {
        snprintf(new_text, sizeof(new_text), "%slog", current_text);
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
    }

    gtk_editable_set_position(GTK_EDITABLE(entry), -1);
    return TRUE;
}

/**
 * Initializes and runs the calculator GUI
 */
int run_calculator(int argc, char *argv[]) {
    GtkWidget *window, *grid, *entry;

    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 350);

        // Create grid layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create display entry
    entry = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(entry), 1.0);
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

    // Create event handlers
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), entry);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Button layout
    const char *buttons[] = {
        "C", "B", "log", "/",
        "7", "8", "9", "*",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "0", ".", "=", "^",
        "√", "!"
    };

    const char *tooltips[] = {
    "Clear the display",
    "Delete the last character",
    "Calculate base-10 logarithm: log(x)",
    "Division operator: x/y",

    "Digit 7",
    "Digit 8",
    "Digit 9",
    "Multiplication operator: x*y",

    "Digit 4",
    "Digit 5",
    "Digit 6",
    "Subtraction operator: x-y",

    "Digit 1",
    "Digit 2",
    "Digit 3",
    "Addition operator: x+y",

    "Digit 0",
    "Decimal point",
    "Evaluate the expression and display the result",
    "Power function: x^y",

    "Square root function: y√x",
    "Factorial: x!"
};

    int row = 1, col = 0;

    for (int i = 0; i < 22; i++) {
        GtkWidget *button = gtk_button_new_with_label(buttons[i]);
        gtk_widget_set_tooltip_text(button, tooltips[i]);

        if (buttons[i][0] == 'C') {
            g_signal_connect(button, "clicked", G_CALLBACK(on_clear_clicked), entry);
        } else if (buttons[i][0] == 'B') {
            g_signal_connect(button, "clicked", G_CALLBACK(on_backspace_clicked), entry);
        } else {
            g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry);
        }

        gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);

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
 * Program entry point
 */
int main(int argc, char *argv[]) {
    return run_calculator(argc, argv);
}
