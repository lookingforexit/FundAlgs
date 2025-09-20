#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_operations.h"

void print_multiplies(int x)
{
    int divider = abs(x);

    if (divider == 0 || divider > 100)
    {
        printf("No naturals numbers that can be divided by %d in 1-100 range.\n", divider);
        return;
    }

    for (int i = divider; i <= 100; i += divider)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void print_is_prime(int x)
{
    if (x < 2)
    {
        printf("%d isn't a prime number.\n", x);
    }

    for (int divider = 2; divider * divider <= x; ++divider)
    {
        if (!(x % divider))
        {
            printf("%d isn't a prime number.\n", x);
            return;
        }
    }

    printf("%d is a prime number.\n", x);
}

void print_hex_digits(int x)
{
    if (x == 0)
    {
        printf("0\n");
        return;
    }

    int hex_digits[10];
    int hex_digits_count = 0;
    int number = abs(x);
    while (number > 0)
    {
        hex_digits[hex_digits_count] = number % 16;
        number /= 16;
        ++hex_digits_count;
    }

    if (x < 0)
    {
        printf("- ");
    }
    for (int i = hex_digits_count - 1; i >= 0; --i)
    {
        if (hex_digits[i] < 10)
        {
            printf("%d ", hex_digits[i]);
        }
        else
        {
            printf("%c ", 'A' + hex_digits[i] - 10);
        }
    }
    printf("\n");
}

void print_pow_table(int x)
{
    if (x < 1 || x > 10)
    {
        printf("%d has to be in 1-10 range.\n", x);
        return;
    }

    for (int base = 1; base <= 10; ++base)
    {
        for (int exp = 1; exp <= x; ++exp)
        {
            long long result = 1;
            for (int i = 0; i < exp; ++i)
            {
                result *= base;
            }
            printf("%lld ", result);
        }
        printf("\n");
    }
}

void print_sum_btw_one_and_number(int x)
{
    if (x < 1)
    {
        printf("The sum equals to 0.\n");
        return;
    }

    long long result_sum = x * (x + 1) / 2;
    printf("The sum equals to %lld.\n", result_sum);
}

void print_factorial(int x)
{
    if (x < 0)
    {
        printf("%d isn't a non-negative number.\n", x);
        return;
    }

    long long factorial = 1;
    for (int i = 2; i <= x; ++i)
    {
        factorial *= i;
    }

    printf("Factorial %d equals to %lld.\n", x, factorial);
}