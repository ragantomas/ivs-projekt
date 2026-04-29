#include "math.h"

int main() {
    int error = 0;
    
    add(5.0, 3.0, &error);
    sub(10.0, 4.0, &error);
    mul(2.0, 3.0, &error);
    divide(10.0, 2.0, &error);
    factorial(5, &error);
    power(2.0, 3.0, &error);
    n_root(2, 16.0, &error);
    logarithm(10.0, &error);
    
    return 0;
}