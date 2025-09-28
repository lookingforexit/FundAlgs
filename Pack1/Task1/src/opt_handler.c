#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "opt_handler.h"

void handle_h_opt(char* argv[])
{
    int divider = abs(atoi(argv[2]));
    if (divider == 0 || divider > 100)
    {
        printf("No numbers in 1-100 range\n");
        return;
    }

    for (int i = divider; i <= 100; i += divider)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void handle_p_opt(char* argv[])
{
    int number = atoi(argv[2]);
    if (number < 2)
    {
        printf("%d isn't a prime number\n", number);
        return;
    }

    for (int divider = 2; divider * divider <= number; ++divider)
    {
        if (number % divider == 0)
        {
            printf("%d isn't a prime number\n", number);
            return;
        }
    }

    printf("%d is a prime number\n", number);
}

void handle_s_opt(char* argv[])
{
    int number = atoi(argv[2]);
    if (number == 0)
    {
        printf("0\n");
        return;
    }

    int digits[8];
    int digits_count = 0;
    int positive_number = abs(number);
    while (positive_number > 0)
    {
        digits[digits_count] = positive_number % 16;
        positive_number /= 16;
        ++digits_count;
    }

    if (number < 0)
    {
        printf("- ");
    }
    for (int i = 0; i < digits_count; ++i)
    {
        if (digits[digits_count - i - 1] < 10)
        {
            printf("%d ", digits[digits_count - i - 1]);
        }
        else
        {
            printf("%c ", 'A' + digits[digits_count - i - 1] - 10);
        }
    }
    printf("\n");
}

void handle_e_opt(char* argv[])
{
    int number = atoi(argv[2]);

    for (int base = 1; base <= 10; ++base)
    {
        for (int exp = 1; exp <= number; ++exp)
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

void handle_a_opt(char* argv[])
{
    int number = atoi(argv[2]);
    if (number < 1)
    {
        printf("The sum equals to 0\n");
        return;
    }

    long long result_sum = number * (number + 1) / 2;
    printf("The sum equals to %lld\n", result_sum);
}

void handle_f_opt(char* argv[])
{
    int number = atoi(argv[2]);
    if (number < 0)
    {
        printf("%d isn't a non-negative number\n", number);
        return;
    }

    long long factorial = 1;
    for (int i = 2; i <= number; ++i)
    {
        factorial *= i;
    }

    printf("Factorial %d equals to %lld\n", number, factorial);
}

void handle_unknown_opt(char* argv[])
{
    printf("Error: unknown flag %c\n", argv[1][1]);
}

option_t get_option(char* argv[])
{
    switch (argv[1][1])
    {
        case 'h':
            return OPT_H;
        case 'p':
            return OPT_P;
        case 's':
            return OPT_S;
        case 'e':
            return OPT_E;
        case 'a':
            return OPT_A;
        case 'f':
            return OPT_F;
        default:
            return OPT_UNKNOWN;
    }
}