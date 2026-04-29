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


double parse_factorial(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (int character = lenght - 1; character >= 0; character--) {
        if (equation[character] == '!') {
            *parsed = true;

            // if there is nothing as input
            if (character == 0) {
                *error = 3;
                return 0.0;
            }

            double num_l = parse_equation(equation, character, 0, error);
            if(*error) {
                return 0.0;
            }
            return factorial(num_l, error);
        }
    }
    *parsed = false;
    return 0.0;
}

double parse_power(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (int character = lenght - 1; character >= 0; character--) {
        if (equation[character] == '^') {
            *parsed = true;

            const char *equation_r = equation + character + 1;
            const char *equation_l = equation;
            unsigned int lenght_r = lenght - character - 1;
            unsigned int lenght_l = character;

            // if there is nothing as input
            if (lenght_r == 0 || lenght_l == 0) {
                *error = 3;
                return 0.0;
            }

            double num_r = parse_equation(equation_r, lenght_r, 2, error);
            if(*error) {
                return 0.0;
            }

            double num_l = parse_equation(equation_l, lenght_l, 1, error);
            if(*error) {
                return 0.0;
            }
            return power(num_l, num_r, error);
        }
    }
    *parsed = false;
    return 0.0;
}

double parse_root(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (int character = lenght - 1; character >= 0; character--) {
        if (equation[character] == 'r') {
            *parsed = true;

            const char *equation_r = equation + character + 1;
            const char *equation_l = equation;
            unsigned int lenght_r = lenght - character - 1;
            unsigned int lenght_l = character;

            // if there is nothing as input
            if (lenght_r == 0) {
                *error = 3;
                return 0.0;
            }

            double num_r = parse_equation(equation_r, lenght_r, 3, error);
            if(*error) {
                return 0.0;
            }

            double num_l = parse_equation(equation_l, lenght_l, 2, error);
            if(*error) {
                return 0.0;
            }
            return n_root(num_l, num_r, error);
        }
    }
    *parsed = false;
    return 0.0;
}

double parse_log(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (int character = lenght - 1; character >= 0; character--) {
        if (equation[character] == 'l') {
            *parsed = true;
            const char *equation_r = equation + character + 3;
            unsigned int lenght_r = lenght - character - 3;
            if (lenght_r == 0) {
                *error = 3;
                return 0.0;
            }
            double num_r = parse_equation(equation_r, lenght_r, 3, error);
            if(*error) {
                return 0.0;
            }
            return logarithm(num_r, error);
        }
    }
    *parsed = false;
    return 0.0;
}

double parse_mul(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (int character = lenght - 1; character >= 0; character--) {
        if (equation[character] == '*') {
            *parsed = true;

            const char *equation_r = equation + character + 1;
            const char *equation_l = equation;
            unsigned int lenght_r = lenght - character - 1;
            unsigned int lenght_l = character;

            // if there is nothing as input
            if (lenght_r == 0 || lenght_l == 0) {
                *error = 3;
                return 0.0;
            }

            double num_r = parse_equation(equation_r, lenght_r, 5, error);
            if(*error) {
                return 0.0;
            }

            double num_l = parse_equation(equation_l, lenght_l, 4, error);
            if(*error) {
                return 0.0;
            }

            return mul(num_l, num_r, error);
        }
    }
    *parsed = false;
    return 0.0;
}

double parse_div(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (int character = lenght - 1; character >= 0; character--) {
        if (equation[character] == '/') {
            *parsed = true;

            const char *equation_r = equation + character + 1;
            const char *equation_l = equation;
            unsigned int lenght_r = lenght - character - 1;
            unsigned int lenght_l = character;

            // if there is nothing as input
            if (lenght_r == 0 || lenght_l == 0) {
                *error = 3;
                return 0.0;
            }

            double num_r = parse_equation(equation_r, lenght_r, 6, error);
            if(*error) {
                return 0.0;
            }

            double num_l = parse_equation(equation_l, lenght_l, 5, error);
            if(*error) {
                return 0.0;
            }

            return divide(num_l, num_r, error);
        }
    }
    *parsed = false;
    return 0.0;
}

double parse_add(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (int character = lenght - 1; character >= 0; character--) {
        if (equation[character] == '+') {
            *parsed = true;

            const char *equation_r = equation + character + 1;
            const char *equation_l = equation;
            unsigned int lenght_r = lenght - character - 1;
            unsigned int lenght_l = character;

            // if there is nothing as input
            if (lenght_r == 0 || lenght_l == 0) {
                *error = 3;
                return 0.0;
            }

            double num_r = parse_equation(equation_r, lenght_r, 7, error);
            if(*error) {
                return 0.0;
            }

            double num_l = parse_equation(equation_l, lenght_l, 6, error);
            if(*error) {
                return 0.0;
            }

            return add(num_l, num_r, error);
        }
    }
    *parsed = false;
    return 0.0;
}

double parse_sub(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed) {
    for (int character = lenght - 1; character >= 0; character--) {
        if (equation[character] == '-') {
            *parsed = true;

            const char *equation_r = equation + character + 1;
            const char *equation_l = equation;
            unsigned int lenght_r = lenght - character - 1;
            unsigned int lenght_l = character;

            // if there is nothing as input
            if (lenght_r == 0) {
                *error = 3;
                return 0.0;
            }

            double num_r = parse_equation(equation_r, lenght_r, 7, error);
            if(*error) {
                return 0.0;
            }
            // parsing possible negative numbers
            double num_l;
            if (lenght_l == 0) {
                num_l = 0.0;
            } else {
                num_l = parse_equation(equation_l, lenght_l, 7, error);
            }
            if(*error) {
                return 0.0;
            }

            return sub(num_l, num_r, error);
        }
    }
    *parsed = false;
    return 0.0;
}

double parse_equation(const char *equation, unsigned int lenght, unsigned int depth, unsigned int *error) {
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
            value = parse_root(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        case 3:
            value = parse_log(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        case 4:
            value = parse_mul(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        case 5:
            value = parse_div(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        case 6:
            value = parse_add(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        case 7:
            value = parse_sub(equation, lenght, error, &parsed);
            if (parsed) {
                return value;
            }
        default:
            return parse_number(equation, lenght, error);
    }
}

double parse_number(const char *number, unsigned int lenght, unsigned int *error) {
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
            return 0.0;
        }
    }
    if (decimal_points > 1) {
        *error = 1;
        return 0.0;
    }
    return strtod(number, NULL);
}

/*int main(int argc, char *argv[]) {
    nuber test
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
    printf("%f Error: %i \n", num4, error4);
    unsigned int error1 = 0;
    char *equation1 = "123-7*12.5+-14/11r3^2!";
    double num1 = parse_equation(equation1, 22, 0, &error1);
    printf("%f Error: %i \n", num1, error1);
    return 0; //
}*/

