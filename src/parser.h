//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     calculator parser
//
// $NoKeywords: $ivs_project_2 $parser.h
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-27
//============================================================================//
/**
 * @file parser.h
 * @author Daniel Kratky
 *
 * @brief parser of the calculator app
 *
 * This file declares function prototypes for functions that handle user input
 */

double parse_factorial(char *equation, unsigned int lenght, unsigned int *error);

/**
 * @brief parses a string into a mathematical equation and returns its value
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param depth Second addend
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return value of the equation
 */

double parse_equation(char *equation, unsigned int lenght, unsigned int depth, unsigned int *error);

/**
 * @brief parses a string into decimal number
 *
 * @param number Pointer to the string containing the number
 * @param lenght Lenght of the string containing the equation
 * @param depth Second addend
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return decimal value of the number
 */

double parse_number(char *number, unsigned int lenght, unsigned int *error);
