//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     calculator parser
//
// $NoKeywords: $ivs_project_2 $parser.c
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-28
//============================================================================//
/**
 * @file parser.c
 * @author Daniel Kratky
 *
 * @brief parser of the calculator app
 */
#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


double parse_factorial(char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (unsigned int character = 0; character < lenght; character++) {
        if (equation[character] == '!') {
            *parsed = true;

            // if there is nothing as input
            if (character == 0) {
                *error = 3;
                return 0;
            }

            double num_l = parse_equation(equation, character, 0, error);
            if(*error) {
                return 0;
            }

            // TODO: change for factorial(num_r, error); once implemented
            return 1.0 + num_l;

        }
    }
    *parsed = false;
    return 0;
}

double parse_power(char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (unsigned int character = 0; character < lenght; character++) {
        if (equation[character] == '^') {
            *parsed = true;

            char *equation_r = equation + character + 1;
            char *equation_l = equation;
            unsigned int lenght_r = lenght - character - 1;
            unsigned int lenght_l = character;

            // if there is nothing as input
            if (lenght_r == 0 || lenght_l == 0) {
                *error = 3;
                return 0;
            }

            double num_r = parse_equation(equation_r, lenght_r, 1, error);
            if(*error) {
                return 0;
            }

            double num_l = parse_equation(equation_l, lenght_l, 2, error);
            if(*error) {
                return 0;
            }

            // TODO: change for power(num_l, num_r, error); once implemented
            return 1.0 + num_r + num_l;
        }
    }
    *parsed = false;
    return 0;
}

double parse_root(char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (unsigned int character = 0; character < lenght; character++) {
        if (equation[character] == 'r') { //TODO: this wil need fixing in gui
            *parsed = true;

            char *equation_r = equation + character + 1;
            unsigned int lenght_r = lenght - character - 1;

            // if there is nothing as input
            if (lenght_r == 0) {
                *error = 3;
                return 0;
            }

            double num_r = parse_equation(equation_r, lenght_r, 2, error);
            if(*error) {
                return 0;
            }

            // TODO: change for root(num_r, error); once implemented
            return 1.0 + num_r;
        }
    }
    *parsed = false;
    return 0;
}
double parse_log(char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (unsigned int character = 0; character < lenght; character++) {
        if (equation[character] == 'l') {
            *parsed = true;
            if (character >= lenght - 2 || equation[character + 1] != 'o' || equation[character + 2] != 'g') {
                *error = 99; // TODO: we ight be able to remove this
                return 0;
            }
            char *equation_r = equation + character + 3;
            unsigned int lenght_r = lenght - character - 3;
            if (lenght_r == 0) {
                *error = 3;
                return 0;
            }
            double num_r = parse_equation(equation_r, lenght_r, 3, error);
            if(*error) {
                return 0;
            }
            // TODO: change for log(num_r, error); once implemented
            return 1.0 + num_r;
        }
    }
    *parsed = false;
    return 0;
}

double parse_equation(char *equation, unsigned int lenght, unsigned int depth, unsigned int *error) {
    //"!","^","√","log","*","/","-","+"
    bool parsed;
    double value;
    // parses for each operator, ignores the one for which it already checked
    switch(depth) {
        case 0:
            value = parse_factorial(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        case 1:
            value = parse_power(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        case 2:
            value = 0; //parse_root(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        default:
            return parse_number(equation, lenght, error);
    }
}

double parse_number(char *number, unsigned int lenght, unsigned int *error) {
    int decimal_points = 0;
    for (unsigned int character = 0; character < lenght; character++) {
        // Catch multiple decimals in one number
        if (number[character] == '.') {
            decimal_points++;
        }
        // Catch nonstandard characters
        if (!(number[character] == '.' ||
              number[character] == '0' ||
              number[character] == '1' ||
              number[character] == '2' ||
              number[character] == '3' ||
              number[character] == '4' ||
              number[character] == '5' ||
              number[character] == '6' ||
              number[character] == '7' ||
              number[character] == '8' ||
              number[character] == '9')) {
            *error = 2;
            return 0;
        }
    }
    if (decimal_points > 1) {
        *error = 1;
        return 0;
    }
    return strtod(number, NULL);
}

int main(int argc, char *argv[]) {
   /* nuber test
    unsigned int error1 = 0;
    unsigned int error2 = 0;
    unsigned int error3 = 0;
    unsigned int error4 = 0;
    char *number1 = "123";
    char *number2 = "123.00";
    char *number3 = "123.0.";
    char *number4 = "12a3";
    double num1 = parse_number(number1, 3, &error1);
    double num2 = parse_number(number2, 6, &error2);
    double num3 = parse_number(number3, 6, &error3);
    double num4 = parse_number(number4, 4, &error4);
    printf("%f Error: %i \n", num1, error1);
    printf("%f Error: %i \n", num2, error2);
    printf("%f Error: %i \n", num3, error3);
    printf("%f Error: %i \n", num4, error4);*/
    unsigned int error1 = 0;
    char *equation1 = "3^2!";
    double num1 = parse_equation(equation1, 4, 0, &error1);
    printf("%f Error: %i \n", num1, error1);
    return 0;
}

