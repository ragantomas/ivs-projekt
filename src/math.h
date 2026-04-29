//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     math library
//
// $NoKeywords: $ivs_project_2 $math.h
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-24
//============================================================================//
#ifndef MATH_H
#define MATH_H
/**
 * @file math.h
 * @author Daniel Kratky
 *
 * @brief Library for calculating mathematical functions
 *
 * This file declares function prototypes for basic arithmetic
 * and advanced mathematical operations used in the calculator.
 */

#include <math.h>

/**
 * @brief Adds two numbers
 *
 * @param a First addend
 * @param b Second addend
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return Sum of a and b
 */
double add(double a, double b, int *error);

/**
 * @brief Subtracts two numbers
 *
 * @param a Minuend
 * @param b Subtrahend
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return Difference (a - b)
 */
double sub(double a, double b, int *error);

/**
 * @brief Multiplies two numbers
 *
 * @param a First factor
 * @param b Second factor
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return Product of a and b
 */
double mul(double a, double b, int *error);

/**
 * @brief Divides two numbers
 *
 * @param a Numerator
 * @param b Denominator
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return Result of division (a / b)
 */
double divide(double a, double b, int *error);

/**
 * @brief Computes factorial of a number
 *
 * @param n Non-negative integer
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return n!
 */
double factorial(double n, int *error);

/**
 * @brief Computes power function
 *
 * @param base Base value
 * @param exponent Integer exponent
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return base raised to the power exponent
 */
double power(double base, double exponent, int *error);

/**
 * @brief Computes n-th root of a number
 *
 * @param degree Root degree (e.g., 2 for square root)
 * @param radicand Value under the root
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return n-th root of radicand
 */
double n_root(double degree, double radicand, int *error);

/**
 * @brief Computes base-10 logarithm
 *
 * @param x Input value (must be > 0)
 * @param error Pointer to error code (0 if no error occurred)
 *
 * @return log10(x)
 */
double logarithm(double x, int *error);

#endif // MATH_H
