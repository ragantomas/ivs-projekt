//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     Matematicka knihovna pro kalkulacku
//
// $NoKeywords: $ivs_project_2 $math_lib.c
// $Authors:    Radek <xzakrad00@stud.fit.vut.cz>
// $Date:       $2026-04-25
//============================================================================//

#include "math_lib.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double logarithm(double x) {
    if (x <= 0) {
        return 0.0; 
    }
    
    double result = 0.0;
    double term = (x - 1.0) / (x + 1.0);
    double term_squared = term * term;
    double numerator = term;

    for (int i = 1; i < 40; i += 2) {
        result += numerator / i;
        numerator *= term_squared;
    }
    return 2.0 * result;
}

double multiply(double a, double b) {
    // TODO
    return 0.0; 
}

double divide(double a, double b) {
    // TODO
    return 0.0;
}

double factorial(int n) {
    // TODO
    return 0.0; 
}

double power(double base, double exponent) {
    // TODO
    return 0.0;
}

double root(double degree, double radicand) {
    // TODO
    return 0.0;
}