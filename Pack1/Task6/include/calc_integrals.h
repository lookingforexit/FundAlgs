#ifndef CALC_INTEGRALS_H
#define CALC_INTEGRALS_H

long double calc_trapezoid(long double (*math_func) (long double), long long steps);

long double first_math_func(long double x);

long double second_math_func(long double x);

long double third_math_func(long double x);

long double fourth_math_func(long double x);

long double calc_integral(long double eps, long double (*math_func) (long double));

#endif