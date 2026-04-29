//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     math library
//
// $NoKeywords: $ivs_project_2 $math.c
// $Authors:    Radek Zak <xzakrad00@stud.fit.vut.cz>, Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-24
//============================================================================//
/**
 * @file math.c
 * @author Daniel Kratky, Radek Zak
 *
 * @brief Library for calculting math functions
 */
#include "math.h"
#include <math.h>

double add(double a, double b, int *error) {
    double result = a + b;

    if(error){
    // overflow check (positive and negative)
    if (isinf(result)) {
        *error = 1; // overflow error
    } else {
        *error = 0;
    }
    }

    return result;
}
double sub(double a, double b, int *error) {
    double result = a - b;

    if(error){
    // overflow check (positive and negative)
    if (isinf(result)) {
        *error = 1; // overflow error
    } else {
        *error = 0;
    }
    }

    return result;
}
double mul(double a, double b, int *error) {
    double result = a * b;

    if(error){
    // overflow check (positive and negative)
    if (isinf(result)) {
        *error = 1; // overflow error
    } else {
        *error = 0;
    }
    }

    return result;
}
double divide(double a, double b, int *error) {
    if (b == 0.0) {
        if (error) {
            *error = 1; // error: div by zero
            }    
        return 0.0;
        } 
        else {
        if (error) {
            *error = 0;
            }
    double result = a / b;
    return result;
    }
}
long long factorial(int n, int *error) {
    if (n < 0){
        if (error){
            *error = 1;
        }
        return 0;
    }
    if (n == 0 || n == 1) {
        if (error){
            *error = 0;}
        return 1;
    }
    //overflow check (21! doesn't fit long long)
    if (n > 20) {
        if (error){
            *error = 1; // overflow error
        }
        return 0; 
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }   

    if (error) {
        *error = 0; 
    }
    return result; 
}
double power(double base, int exponent, int *error) {
    if (exponent == 0) {
        if (error) {
            *error = 0;
        }
        return 1.0;
    }
    // error div by zero
    if (base == 0.0 && exponent < 0) {
        if (error){
            *error = 1;
        }
        return 0.0;
    }
    
    double result = 1.0;
   
    if (exponent > 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        
    }
    else {
        for (int i = 0; i < -exponent; i++) {
            result *= base;
        }
        
        result = 1.0 / result;
    }
    if (error) {
        if (isinf(result)) {
            *error = 1;
        } 
        else {
            *error = 0;
        }
    }
    return result;
}
double root(int degree, double radicand, int *error) {
    if (degree <= 0) {
        if (error) {
            *error = 1;}
        return 0.0;
    }

    if (radicand < 0 && degree % 2 == 0) {
        if (error) {
            *error = 1;
        }
        return 0.0;
    }

    if (radicand == 0.0) {
        if (error) {
            *error = 0;}
        return 0.0;
    }

    double x = radicand;
    double precision = 0.00001;

    for (int i = 0; i < 50; i++) {
        double prev = x;

        double previous_power = 1.0;
        for (int j = 0; j < degree - 1; j++) {
            previous_power *= x;
        }

        if (previous_power == 0.0) {
            break;
        }

        x = ((degree - 1) * x + radicand / previous_power) / degree;

        double diff = x - prev;
        if (diff < 0) {
            diff = -diff;
        }

        if (diff < precision) {
            break;
        }
    }

    if (error) {
        *error = 0;}

    return x;
}
double logarithm(double x, int *error) {
    if (x <= 0) {
        if (error) {
            *error = 1;}
        return 0.0; 
    }
    
    if (error) {
        *error = 0;}
    
    double result = 0.0;
    double fraction = (x - 1.0) / (x + 1.0);
    double fraction_power = fraction * fraction;
    double numerator = fraction;

    for (int i = 1; i < 40; i += 2) {
        result += numerator / i;
        numerator *= fraction_power;
    }
    return 2.0 * result;
}
