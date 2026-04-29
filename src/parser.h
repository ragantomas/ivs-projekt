//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     calculator parser
//
// $NoKeywords: $ivs_project_2 $parser.h
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-28
//============================================================================//
#ifndef PARSER_H
#define PARSER_H
/**
 * @file parser.h
 * @author Daniel Kratky
 *
 * @brief parser of the calculator app
 *
 * This file declares function prototypes for functions that handle user input
 */

#include <stdbool.h>
#include "math.c"

/**
 * @brief searches the string equation for factorials and evaluates them
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param error Pointer to error code (0 if no error occurred)
 * @param parsed Pointer bool set to true if the function parsed anythng, false otherwise
 *
 * @return value of the equation
 */
double parse_factorial(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed);

/**
 * @brief searches the string equation for powers and evaluates them
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param error Pointer to error code (0 if no error occurred)
 * @param parsed Pointer bool set to true if the function parsed anythng, false otherwise
 *
 * @return value of the equation
 */
double parse_power(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed);

/**
 * @brief searches the string equation for roots and evaluates them
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param error Pointer to error code (0 if no error occurred)
 * @param parsed Pointer bool set to true if the function parsed anythng, false otherwise
 *
 * @return value of the equation
 */
double parse_root(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed);

/**
 * @brief searches the string equation for logarithms and evaluates them
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param error Pointer to error code (0 if no error occurred)
 * @param parsed Pointer bool set to true if the function parsed anythng, false otherwise
 *
 * @return value of the equation
 */
double parse_log(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed);

/**
 * @brief searches the string equation for multiplications and evaluates them
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param error Pointer to error code (0 if no error occurred)
 * @param parsed Pointer bool set to true if the function parsed anythng, false otherwise
 *
 * @return value of the equation
 */
double parse_mul(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed);

/**
 * @brief searches the string equation for divisions and evaluates them
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param error Pointer to error code (0 if no error occurred)
 * @param parsed Pointer bool set to true if the function parsed anythng, false otherwise
 *
 * @return value of the equation
 */
double parse_div(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed);

/**
 * @brief searches the string equation for additions and evaluates them
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param error Pointer to error code (0 if no error occurred)
 * @param parsed Pointer bool set to true if the function parsed anythng, false otherwise
 *
 * @return value of the equation
 */
double parse_add(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed);

/**
 * @brief searches the string equation for subtractions and evaluates them
 *
 * @param equation Pointer to the string containing the equation
 * @param lenght Lenght of the string containing the equation
 * @param error Pointer to error code (0 if no error occurred)
 * @param parsed Pointer bool set to true if the function parsed anythng, false otherwise
 *
 * @return value of the equation
 */
double parse_sub(const char *equation, unsigned int lenght, unsigned int *error, bool *parsed);

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
double parse_equation(const char *equation, unsigned int lenght, unsigned int depth, unsigned int *error);

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
double parse_number(const char *number, unsigned int lenght, unsigned int *error);
#endif // PARSER_H
