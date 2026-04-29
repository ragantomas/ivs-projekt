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
void on_button_clicked(GtkWidget *button, GtkWidget *display) {
    const char *button_text = gtk_button_get_label(GTK_BUTTON(button));
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(display));
    // if error message is displayed, clear it first
    if (current_text[0] == 'E') {
        current_text = "";
    }

    char new_text[256];
    if (button_text[0] == '=') {
        unsigned int error = 0;
        double num = 0; //parse_equation(current_text, strlen(current_text), 0, &error)
        snprintf(new_text, sizeof(new_text), "%f", current_text);
    } else {
        snprintf(new_text, sizeof(new_text), "%s%c", current_text, button_text[0]);
    }

    gtk_entry_set_text(GTK_ENTRY(display), new_text);
    gtk_editable_set_position(GTK_EDITABLE(display), -1);
}

/**
 * Clears the display
 */
void on_clear_clicked(GtkWidget *button, GtkWidget *display) {
    gtk_entry_set_text(GTK_ENTRY(display), "");
    gtk_editable_set_position(GTK_EDITABLE(display), -1);
}

/**
 * Deletes last character on the display
 */
void on_backspace_clicked(GtkWidget *button, GtkWidget *display) {
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(display));
    int len = strlen(current_text);

    if (len > 0) {
        char new_text[256];
        strncpy(new_text, current_text, len - 1);
        new_text[len - 1] = '\0';
        gtk_entry_set_text(GTK_ENTRY(display), new_text);
        gtk_editable_set_position(GTK_EDITABLE(display), -1);
    }
}

gboolean on_key_press(GtkWidget *window, GdkEventKey *event, GtkWidget *display) {
    gunichar c = gdk_keyval_to_unicode(event->keyval);

    // Get current text
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(display));
    char new_text[256];

    // if error message is displayed, clear it first
    if (current_text[0] == 'E') {
        current_text = "";
    }

    // Digits and operators
    if (g_unichar_isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '.' || c == '!' || c == '^') {
        snprintf(new_text, sizeof(new_text), "%s%c", current_text, (char)c);
        gtk_entry_set_text(GTK_ENTRY(display), new_text);
    }
    // Enter → equals
    else if (event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_KP_Enter) {
        //TODO: add parsing the expresion
    }
    else if (event->keyval == GDK_KEY_BackSpace) {
        on_backspace_clicked(NULL, display);
        return TRUE;
    }
    // clear (c or C)
    else if (c == 'c' || c == 'C') {
        gtk_entry_set_text(GTK_ENTRY(display), "");
    }
    // Square root (r or R)
    else if (c == 'r' || c == 'R') {
        snprintf(new_text, sizeof(new_text), "%sr", current_text);
        gtk_entry_set_text(GTK_ENTRY(display), new_text);
    }
    // log (l key)
    else if (c == 'l' || c == 'L') {
        snprintf(new_text, sizeof(new_text), "%sl", current_text);
        gtk_entry_set_text(GTK_ENTRY(display), new_text);
    }

    gtk_editable_set_position(GTK_EDITABLE(display), -1);
    return TRUE;
}

/**
 * Initializes and runs the calculator GUI
 */
int run_calculator(int argc, char *argv[]) {
    GtkWidget *window, *grid, *display;

    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 150, 200);

    // Create grid layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create display entry
    display = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(display), 1.0);
    gtk_grid_attach(GTK_GRID(grid), display, 0, 0, 4, 1);

    // Create event handlers
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), display);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Button layout
    const char *buttons[] = {
        "C",      "B", "/",
        "7", "8", "9", "*",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "0", ".", "!", "log",
        "r", "^", "="
    };
    // Tooltip strings with descrioptions of buttons
    const char *tooltips[] = {
    "[C] Clear the display",
    "[B] Delete the last character",
    "[L] Calculate base-10 logarithm: log(x)",
    "[/] Division operator: x/y",

    "[7] Digit 7",
    "[8] Digit 8",
    "[9] Digit 9",
    "[*] Multiplication operator: x*y",

    "[4] Digit 4",
    "[5] Digit 5",
    "[6] Digit 6",
    "[-] Subtraction operator: x-y",

    "[1] Digit 1",
    "[2] Digit 2",
    "[3] Digit 3",
    "[+] Addition operator: x+y",

    "[0] Digit 0",
    "[.] Decimal point",
    "[Enter] Evaluate the expression and display the result",
    "[^] Power function: x^y",

    "[R] Square root function: y√x",
    "[!] Factorial: x!"
};

    int row = 1, col = 0;
    // Create buttons
    for (int i = 0; i < 22; i++) {
        GtkWidget *button = gtk_button_new_with_label(buttons[i]);
        gtk_widget_set_tooltip_text(button, tooltips[i]);

        if (buttons[i][0] == 'C') {
            g_signal_connect(button, "clicked", G_CALLBACK(on_clear_clicked), display);
        } else if (buttons[i][0] == 'B') {
            g_signal_connect(button, "clicked", G_CALLBACK(on_backspace_clicked), display);
        } else {
            g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), display);
        }
        // Buttons C and = are wider
        if(i == 0 || i == 21) {
            gtk_grid_attach(GTK_GRID(grid), button, col, row, 2, 1);
            col++;
        } else {
            gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
        }

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
