#ifndef MATH_CALCULATIONS_H
#define MATH_CALCULATIONS_H

long double calc_eps(const int precision);

long long factorial(const int n);

long long combinations(const int k, const int m);

long double calc_e_lim_in_point(const int n);

long double calc_e_lim(const long double eps);

long double calc_e_series(const long double eps);

long double calc_e_equation(const long double eps);

long double calc_pi_lim_increment_coefficient(const int n);

long double calc_pi_lim(const long double eps);

long double calc_pi_series(const long double eps);

long double calc_pi_equation(const long double eps);

long double calc_ln2_lim_in_point(const int n);

long double calc_ln2_lim(const long double eps);

long double calc_ln2_series(const long double eps);

long double calc_ln2_equation(const long double eps);

long double calc_root_of_two_lim(const long double eps);

long double calc_root_of_two_series(const long double eps);

long double calc_root_of_two_equation(const long double eps);

long double calc_gamma_lim_in_point(const int n);

long double calc_gamma_lim(const long double eps);

long double calc_gamma_series(const long double eps);

long double calc_multiply_Paddic_numbers_and_logarithm(const int n);

long double calc_gamma_equation(const long double eps);

#endif