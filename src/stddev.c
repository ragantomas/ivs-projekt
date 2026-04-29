//======= FIT VUT Brno, GNU GPL V3.0 ============//
//
// Purpose:     Standard deviation calculation for profiling
//
// $NoKeywords: $ivs_project_2 $stddev.c
// $Authors:    Daniel Kratky <xkratkd00@stud.fit.vut.cz>, Radek Žák <xzakrad00@stud.fit.vut.cz>, Tomáš Ragan <xragant00@stud.fit.vut.cz>
// $Date:       $2026-04-29
//============================================================================//

/**
 * @file stddev.c
 * @author Daniel Kratky, Radek Žák, Tomáš Ragan
 *
 * @brief Program for calculating standard deviation from standard input
 *
 * This program reads a sequence of numbers from standard input (stdin) until EOF.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math.h"

/**
 * @brief Main function of the standard deviation calculator
 *
 * Implements the single-pass algorithm for standard deviation:
 * sigma = sqrt( (sum(x^2) / n) - (mean^2) )
 *
 * @return int Returns 0 on success
 */
int main() {
    double sum = 0;
    double sum_sq = 0;
    double x;
    int count = 0;
    int error = 0;

    // Read numbers from stdin until end of file
    while (scanf("%lf", &x) != EOF) {
        // Accumulate sum of values: sum = sum + x
        sum = add(sum, x, &error);
        
        // Accumulate sum of squares: sum_sq = sum_sq + x^2
        double x_sq = mul(x, x, &error);
        sum_sq = add(sum_sq, x_sq, &error);
        
        count++;
    }

    // Exit if no numbers were provided
    if (count == 0) {
        return 0;
    }

    // Calculate arithmetic mean: mean = sum / count
    double mean = divide(sum, count, &error);
    // Calculate mean squared: mean_sq = mean * mean
    double mean_sq = mul(mean, mean, &error);
    // Calculate variance: variance = (sum_sq / count) - mean_sq
    double variance = sub(divide(sum_sq, count, &error), mean_sq, &error);
    double res = n_root(2, variance, &error);

    // Print the result with high precision
    printf("%.10g\n", res);
    
    return 0;
}