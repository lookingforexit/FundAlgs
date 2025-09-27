#include <stdio.h>
#include <math.h>
#include "math_calculations.h"
#include "print_calculations.h"

void print_calculations(const int input_precision)
{
    long double eps = calc_eps(input_precision);
    int precision = (int)ceil(-log10(eps));

    printf("\n");

    printf("e limit calculated: %.*Lf\n", precision, calc_e_lim(eps));
    printf("e series calculated: %.*Lf\n", precision, calc_e_series(eps));
    printf("e equation calculated: %.*Lf\n", precision, calc_e_equation(eps));
    printf("\n");

    printf("pi limit calculated: %.*Lf\n", precision, calc_pi_lim(eps));
    printf("pi series calculated: %.*Lf\n", precision, calc_pi_series(eps));
    printf("pi equation calculated: %.*Lf\n", precision, calc_pi_equation(eps));
    printf("\n");

    printf("ln2 limit calculated: %.*Lf\n", precision, calc_ln2_lim(eps));
    printf("ln2 series calculated: %.*Lf\n", precision, calc_ln2_series(eps));
    printf("ln2 equation calculated: %.*Lf\n", precision, calc_ln2_equation(eps));
    printf("\n");

    printf("root of two limit calculated: %.*Lf\n", precision, calc_root_of_two_lim(eps));
    printf("root of two series calculated: %.*Lf\n", precision, calc_root_of_two_series(eps));
    printf("root of two equation calculated: %.*Lf\n", precision, calc_root_of_two_equation(eps));
    printf("\n");

    printf("gamma limit calculated: %.*Lf\n", precision, calc_gamma_lim(eps));
    printf("gamma series calculated: %.*Lf\n", precision, calc_gamma_series(eps));
    printf("gamma equation calculated: %.*Lf\n", precision, calc_gamma_equation(eps));
    printf("\n");
}