#include <stdio.h>
#include <math.h>
#include "math_calculations.h"

long double calc_eps(const int precision)
{
    long double eps = 1.0;
    
    for (int i = 0; i < precision; ++i)
    {
        eps /= 2.0;
    }
    
    return eps;
}

long long factorial(const int n)
{
    long long factorial = 1;
    
    for (int i = 2; i <= n; ++i)
    {
        factorial *= i;
    }

    return factorial;
}

long long combinations(const int k, const int m)
{
    long long combinations = factorial(m) / (factorial(m - k) * factorial(k));

    return combinations;
}

long double calc_e_lim_in_point(const int n)
{
    long double lim_value = powl(1.0 + 1.0 / n, n);

    return lim_value;
}

long double calc_e_lim(const long double eps)
{
    int n = 2;
    long double prev_lim_value = calc_e_lim_in_point(n - 1);
    long double lim_value = calc_e_lim_in_point(n);

    while (fabsl(lim_value - prev_lim_value) >= eps)
    {
        ++n;
        prev_lim_value = lim_value;
        lim_value = calc_e_lim_in_point(n);
    }

    return lim_value;
}

long double calc_e_series(const long double eps)
{
    int n = 0;
    long long factorial = 1;
    long double element_value = 1.0;
    long double series_value = 1.0;

    while (fabsl(element_value) >= eps)
    {
        ++n;
        factorial *= n;
        element_value = 1.0 / factorial;
        series_value += element_value;
    }

    return series_value;
}

long double calc_e_equation(const long double eps)
{
    // ln x - 1 = 0
    long double left_border = 1.0;
    long double right_border = 3.0;
    long double mid_value;

    while (fabsl(right_border - left_border) >= eps)
    {
        mid_value = (left_border + right_border) / 2.0;

        if ((log(right_border) - 1.0) * (log(mid_value) - 1.0) < 0)
        {
            left_border = mid_value;
        }
        else
        {
            right_border = mid_value;
        }
    }

    return (left_border + right_border) / 2.0;
}

long double calc_pi_lim_increment_coefficient(const int n)
{
    // smth like f(n+1)/f(n), based method for functions with factorials
    long double coefficient = 4.0 * n * (n - 1.0) / ((2.0 * n - 1.0) * (2.0 * n - 1.0));

    return coefficient;
}

long double calc_pi_lim(const long double eps)
{
    int n = 2;
    long double prev_lim_value = 4.0;
    long double lim_value = prev_lim_value * calc_pi_lim_increment_coefficient(n);

    while (fabsl(lim_value - prev_lim_value) >= eps)
    {
        ++n;
        prev_lim_value = lim_value;
        lim_value *= calc_pi_lim_increment_coefficient(n);
    }

    return lim_value;
}

long double calc_pi_series(const long double eps)
{
    int n = 1;
    long double element_value = 1.0;
    long double series_value = 1.0;

    while (4.0 * fabsl(element_value) >= eps)
    {
        ++n;
        element_value = ((n % 2 == 0) ? -1.0 : 1.0) / (2.0 * n - 1.0);
        series_value += element_value;
    }

    return 4.0 * series_value;
}

long double calc_pi_equation(const long double eps) 
{
    // cos x + 1 = 0;

    // chord method based on secant method
    // long double prev_value = 2.0; 
    // long double value = 4.0;
    // long double next_value = ((cosl(value) + 1.0) * prev_value - (cosl(prev_value) + 1.0) * value) / (cosl(value) - cosl(prev_value));

    // while (value - prev_value >= eps)
    // {
    //     prev_value = value;
    //     value = next_value;
    //     next_value = ((cosl(value) + 1.0) * prev_value - (cosl(prev_value) + 1.0) * value) / (cosl(value) - cosl(prev_value));
    // }

    // return next_value;


    // Newton method based of function derivative (better convergence speed and more accurate value)
    long double approximated_value = 3.0;

    while (cosl(approximated_value) + 1.0 >= eps)
    {
        approximated_value -= (cosl(approximated_value) + 1.0) / (-sinl(approximated_value));
    }

    return approximated_value;
}

long double calc_ln2_lim_in_point(const int n)
{
    long double lim_value = n * (powl(2.0, 1.0 / n) - 1.0);

    return lim_value;
}

long double calc_ln2_lim(const long double eps)
{
    int n = 2;
    long double prev_lim_value = calc_ln2_lim_in_point(n - 1);
    long double lim_value = calc_ln2_lim_in_point(n);

    while (fabsl(lim_value - prev_lim_value) >= eps)
    {
        ++n;
        prev_lim_value = lim_value;
        lim_value = calc_ln2_lim_in_point(n);
    }

    return lim_value;
}

long double calc_ln2_series(const long double eps)
{
    int n = 1;
    long double element_value = 1.0;
    long double series_value = 1.0;

    while (fabsl(element_value) >= eps)
    {
        ++n;
        element_value = ((n % 2 == 0) ? -1.0 : 1.0) / n;
        series_value += element_value;
    }

    return series_value;
}

long double calc_ln2_equation(const long double eps)
{
    // e^x - 2 = 0
    long double left_border = 0;
    long double right_border = 1.0;
    long double mid_value;

    while (fabsl(right_border - left_border) >= eps)
    {
        mid_value = (left_border + right_border) / 2.0;

        if ((exp(right_border) - 2.0) * (exp(mid_value) - 2.0) < 0)
        {
            left_border = mid_value;
        }
        else
        {
            right_border = mid_value;
        }
    }

    return (left_border + right_border) / 2.0;
}

long double calc_root_of_two_lim(const long double eps)
{
    int n = 1;
    long double prev_lim_value = -0.5;
    long double lim_value = 0.625;

    while (fabsl(lim_value - prev_lim_value) >= eps)
    {
        ++n;
        prev_lim_value = lim_value;
        lim_value = prev_lim_value - powl(prev_lim_value, 2.0) / 2.0 + 1.0;
    }

    return lim_value;
}

long double calc_root_of_two_series(const long double eps)
{
    int n = 2;
    long double element_value = powl(2.0, 0.25);
    long double series_value = powl(2.0, 0.25);

    while (fabsl(series_value - (series_value / element_value)) >= eps)
    {
        ++n;
        element_value = powl(2.0, powl(2.0, -n));
        series_value *= element_value;
    }

    return series_value;
}

long double calc_root_of_two_equation(const long double eps)
{
    // x^2 - 2 = 0
    long double left_border = 1.0;
    long double right_border = 2.0;
    long double mid_value;

    while (fabsl(right_border - left_border) >= eps)
    {
        mid_value = (left_border + right_border) / 2.0;

        if ((powl(right_border, 2.0) - 2.0) * (powl(mid_value, 2.0) - 2.0) < 0)
        {
            left_border = mid_value;
        }
        else
        {
            right_border = mid_value;
        }
    }

    return (left_border + right_border) / 2.0;
}

long double calc_gamma_lim_in_point(const int n)
{
    long double sum = 0;

    for (int k = 1; k <= n; ++k)
    {
        sum += (long double)(combinations(k, n) * ((k % 2 == 0) ? 1 : -1)) / k * log(factorial(k));
    }

    return sum;
}

long double calc_gamma_lim(const long double eps)
{
    int n = 1;
    long double prev_lim_value = calc_gamma_lim_in_point(n++);
    long double lim_value = calc_gamma_lim_in_point(n++);

    while (fabsl(lim_value - prev_lim_value) >= eps && n != 20) 
    {
        ++n;
        prev_lim_value = lim_value;
        lim_value = calc_gamma_lim_in_point(n);
    }

    return lim_value;
}

long double calc_gamma_series(const long double eps)
{
    int n = 2;
    long double prev_element_value;
    long double element_value = 0.5;
    long double series_value = -calc_pi_series(eps) * calc_pi_series(eps) / 6.0 + element_value;

    while (element_value >= eps || prev_element_value >= eps)
    {
        ++n;
        prev_element_value = element_value;
        element_value = 1.0 / (floorl(sqrtl(n)) * floorl(sqrtl(n))) - 1.0 / n;
        series_value += element_value;
    }

    return series_value;
}

long double calc_multiply_Paddic_numbers_and_logarithm(const int n)
{
    int sieve[(int)2e6];

    for (int i = 2; i <= n; ++i) 
    {
        sieve[i] = 1;
    }

    for (int i = 2; i * i <= n; ++i) 
    {
        if (sieve[i]) 
        {
            for (int j = i * i; j <= n; j += i) 
            {
                sieve[j] = 0;
            }
        }
    }

    long double multiply_Paddic_numbers = 1.0;
    for (int i = 2; i <= n; ++i) 
    {
        if (sieve[i]) 
        {
            multiply_Paddic_numbers *= (i - 1.0) / i;
        }
    }

    return logl(n) * multiply_Paddic_numbers;
}

long double calc_gamma_equation(const long double eps)
{
    // e^-x - lim (ln t П (p-1)/p), t -> inf, p <=t, p belongs to P (P-addic set)
    long double left_border  = 0;
    long double right_border = 1.0;
    long double mid_value;

    long double function_in_limit = calc_multiply_Paddic_numbers_and_logarithm((int)2e6);

    while (fabsl(right_border - left_border) >= eps)
    {
        mid_value = (left_border + right_border) / 2.0;

        if (expl(-mid_value) > function_in_limit)
        {
            left_border = mid_value;
        }
        else
        {
            right_border = mid_value;
        }
    }

    return (left_border + right_border) / 2.0;
}