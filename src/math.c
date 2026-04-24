//======= Copyright (c) 2026, FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     math library
//
// $NoKeywords: $ivs_project_2 $math.c
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>
// $Date:       $2026-04-24
//============================================================================//
/**
 * @file math.c
 * @author Daniel Kratky
 *
 * @brief Library for calculting math functions
 */
#include "math.h"

double add(double a, double b, int *error) {
    double result = a + b;

    // overflow check (positive and negative)
    if (isinf(result)) {
        *error = 1; // overflow error
    } else {
        *error = 0;
    }

    return result;
}
