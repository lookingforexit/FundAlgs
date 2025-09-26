#include <stdio.h>
#include <math.h>
#include "calc_integrals.h"

long double calc_trapezoid(long double (*math_func) (long double), long long steps)
{
    long double delta = 1.0 / steps; 
    long double x;
    long double sum = (math_func(0) + math_func(1)) / 2.0;

    for (long long i = 1; i < steps; ++i)
    {
        x = i * delta;
        sum += math_func(x);
    }

    return delta * sum;
}

long double first_math_func(long double x)
{
    if (x == 0)
    {
        return 1;
    }

    return logl(1.0 + x) / x;
}

long double second_math_func(long double x)
{
    return expl(-x * x / 2.0);
}

long double third_math_func(long double x)
{
    if (x >= 0.999999999999999)
    {
        x = 0.999999999999999;
    }

    return logl(1.0 / (1.0 - x));
}

long double fourth_math_func(long double x)
{
    return pow(x, x);
}

long double calc_integral(long double eps, long double (*math_func) (long double))
{
    long long steps = 2;
    long double first_calc = calc_trapezoid(math_func, steps);

    steps *= 2;
    long double second_calc = calc_trapezoid(math_func, steps);

    while (fabsl(first_calc - second_calc) / 3.0 >= eps && steps <= 524288)
    {
        first_calc = second_calc;
        steps *= 2;
        second_calc = calc_trapezoid(math_func, steps);
    }

    return second_calc;
}