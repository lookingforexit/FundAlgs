#include <stdio.h>
#include <math.h>
#include "print_calculations.h"
#include "calc_integrals.h"

void print_calculations(long double eps)
{
    int precision = ceil(-log10(eps));
    printf("Integral log(1+x)/x from 0 to 1 equals to %.*Lf\n", precision, calc_integral(eps, first_math_func));
    printf("Integral e^(-x^2/2) from 0 to 1 equals to %.*Lf\n", precision, calc_integral(eps, second_math_func));
    printf("Integral log(1/(1-x)) from 0 to 1 equals to %.*Lf\n", precision, calc_integral(eps, third_math_func));
    printf("Integral x^x from 0 to 1 equals to %.*Lf\n", precision, calc_integral(eps, fourth_math_func));
}