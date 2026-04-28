//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     calculator parser
//
// $NoKeywords: $ivs_project_2 $parser.c
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-27
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

double parse_factorial(char *equation, unsigned int lenght, unsigned int *error) {
    for (unsigned int character = 0; character < lenght; character++) {
        if (equation[character] == '!') {
            char *equation_r = equation + character + 1;
            unsigned int lenght_r = lenght - character - 1;
            if (lenght_r == 0) {
                *error = 3;
                return 0;
            }
            double num = parse_equation(equation_r, lenght_r, 0, error);
            if(*error) {
                return 0;
            }
            return 1.0 + num;
            //factorial(parse_equation(equation_r, lenght_r, 0, error));
        }
    }
}

double parse_equation(char *equation, unsigned int lenght,
                     unsigned int depth, unsigned int *error) {
    const char *operations[] = {"!","^","√","log","*","/","-","+"};
    switch(depth) {
        case 0:
            return parse_factorial(equation, lenght, error);
        case 1:
            /*for (unsigned int character = 0; character < lenght; character++) {
                if (equation[character] == '^') {
                    char *new_equation = equation + character + 1;
                    unsigned int lenght_r = lenght - character - 1;
                    if (lenght_r == 0) {
                        *error = 3;
                        return 0;
                    }
                    double num_r = parse_equation(new_equation, lenght_r, 0, error);
                    if(error) {
                        return 0;
                    }
                    return 1.0 + num_r;
                }
            }*/
        case 2:
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
        if (number[character] == '.') {
            decimal_points++;
        }
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
    char *equation1 = "!!3";
    double num1 = parse_equation(equation1, 3, 0, &error1);
    printf("%f Error: %i \n", num1, error1);
    return 0;
}

