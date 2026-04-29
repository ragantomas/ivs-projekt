//======= FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     math test
//
// $NoKeywords: $ivs_project_2 $test_math.c
// $Authors:    Radek Zak <xzakrad00@stud.fit.vut.cz>
// $Date:       $2026-04-10
//============================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divide(double a, double b);
long long factorial(int n);
double power(double base, int exponent);
double n_root(double degree, double radicand);
double absolute(double a);
double logarithm(double x);

// Porovnani desetinnych cisel
int is_equal(double a, double b) {
    return fabs(a - b) < 0.0001;
}

int main() {
    // Scitani
    assert(is_equal(add(2.0, 3.0), 5.0));
    assert(is_equal(add(-2.0, 2.0), 0.0));

    // Odcitani
    assert(is_equal(sub(5.0, 3.0), 2.0));
    assert(is_equal(sub(0.0, 5.0), -5.0));

    // Nasobeni
    assert(is_equal(mul(4.0, 2.5), 10.0));
    assert(is_equal(mul(-2.0, 3.0), -6.0));

    // Deleni
    assert(is_equal(divide(10.0, 2.0), 5.0));
    assert(isinf(divide(10.0, 0.0))); // Deleni nulou

    // Faktorial
    assert(factorial(0) == 1);
    assert(factorial(5) == 120);

    // Mocnina
    assert(is_equal(power(2.0, 3), 8.0));
    assert(is_equal(power(5.0, 0), 1.0));

    // Odmocnina
    assert(is_equal(n_root(2.0, 9.0), 3.0));
    assert(is_equal(n_root(3.0, 8.0), 2.0));
    assert(isnan(n_root(2.0, -4.0))); // Suda odmocnina ze zaporneho cisla

    // Absolutni hodnota
    assert(is_equal(absolute(-5.5), 5.5));
    assert(is_equal(absolute(3.0), 3.0));

    // Logaritmus
    assert(is_equal(logarithm(1.0), 0.0));
    assert(is_equal(logarithm(exp(1.0)), 1.0));
    assert(isinf(logarithm(0.0))); // Log nuly
    assert(isnan(logarithm(-1.0))); // Log zaporneho cisla

    printf("Testovani dokonceno vporadku.\n");
    return 0;
}
