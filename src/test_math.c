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

double add(double a, double b, int *error);
double sub(double a, double b, int *error);
double mul(double a, double b, int *error);
double divide(double a, double b, int *error);
double factorial(double n, int *error);
double power(double base, double exponent, int *error);
double n_root(double degree, double radicand, int *error);
double absolute(double a, int *error);
double logarithm(double x, int *error);

// Porovnani desetinnych cisel
int is_equal(double a, double b) {
    return fabs(a - b) < 0.0001;
}

int main() {
    int err = 0;
    
    // Scitani
    assert(is_equal(add(2.0, 3.0, &err), 5.0));assert(err == 0);
    assert(is_equal(add(-2.0, 2.0, &err), 0.0));assert(err == 0);

    // Odcitani
    assert(is_equal(sub(5.0, 3.0, &err), 2.0));assert(err == 0);
    assert(is_equal(sub(0.0, 5.0, &err), -5.0));assert(err == 0);

    // Nasobeni
    assert(is_equal(mul(4.0, 2.5, &err), 10.0));assert(err == 0);
    assert(is_equal(mul(-2.0, 3.0, &err), -6.0));assert(err == 0);

    // Deleni
    assert(is_equal(divide(10.0, 2.0, &err), 5.0));assert(err == 0);
    divide(10.0, 0.0, &err);assert(err == 5); // Deleni nulou

    // Faktorial
    assert(factorial(0.0, &err) == 1);assert(err == 0);
    assert(factorial(5.0, &err) == 120);assert(err == 0);
    factorial(-2.0, &err); assert(err == 7); // Zaporne cislo
    factorial(2.5, &err); assert(err == 6);  // Desetinne cislo

    // Mocnina
    assert(is_equal(power(2.0, 3, &err), 8.0));assert(err == 0);
    assert(is_equal(power(5.0, 0, &err), 1.0));assert(err == 0);
    power(2.0, 2.5, &err); assert(err == 11); // Desetinny exponent

    // Odmocnina
    assert(is_equal(n_root(2.0, 9.0, &err), 3.0));assert(err == 0);
    assert(is_equal(n_root(3.0, 8.0, &err), 2.0));assert(err == 0);
    n_root(2.0, -4.0, &err);assert(err == 9); // Suda odmocnina ze zaporneho cisla

    // Logaritmus
    assert(is_equal(logarithm(1.0, &err), 0.0));assert(err == 0);
    assert(is_equal(logarithm(10.0, &err), 1.0));assert(err == 0);
    logarithm(0.0, &err);assert(err == 10); // Log nuly
    logarithm(-1.0, &err);assert(err == 10); // Log zaporneho cisla

    printf("Testovani dokonceno vporadku.\n");
    return 0;
}
