#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "opt_handler.h"

void solve_quadratic(double a, double b, double c, double eps)
{
    if (fabs(a) < eps)
    {
        if (fabs(b) < eps)
        {
            if (fabs(c) < eps)
            {
                printf("%.6lf %.6lf %.6lf\n", a, b, c);
                printf("Infinitive amount of solutions\n");
            }
            else
            {
                printf("%.6lf %.6lf %.6lf\n", a, b, c);
                printf("No solutions\n");
            }
        }
        else
        {
            printf("%.6lf %.6lf %.6lf\n", a, b, c);
            printf("One solution equals to %.6lf\n", -c / b);
        }
    }
    else
    {
        double discriminant = b * b - 4 * a * c;
        if (fabs(discriminant) < eps)
        {
            printf("%.6lf %.6lf %.6lf\n", a, b, c);
            printf("One solution equals to %.6lf\n", (-b / (2.0 * a)));
        }
        else if (discriminant >= eps)
        {
            printf("%.6lf %.6lf %.6lf\n", a, b, c);
            printf("Two solutions equal to %.6lf and %.6lf\n", (-b - sqrt(discriminant)) / (2.0 * a), (-b + sqrt(discriminant)) / (2.0 * a));
        }
        else
        {
            printf("%.6lf %.6lf %.6lf\n", a, b, c);
            printf("No solutions in R\n");
        }
    }
}

void handle_q_opt(char* argv[])
{
    double eps = strtod(argv[2], NULL);
    double a = strtod(argv[3], NULL);
    double b = strtod(argv[4], NULL);
    double c = strtod(argv[5], NULL);

    double permutations[6][3] = 
    {
        {a, b, c}, 
        {a, c, b}, 
        {b, a, c}, 
        {b, c, a}, 
        {c, a, b}, 
        {c, b, a}
    };

    for (int i = 0; i < 6; ++i)
    {
        solve_quadratic(permutations[i][0], permutations[i][1], permutations[i][2], eps);
    }
}

void handle_m_opt(char* argv[])
{
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    if (num1 % num2 == 0)
    {
        printf("First number is divided by second number\n");
    }
    else
    {
        printf("First number isnt divided by second number\n");
    }
}

void handle_t_opt(char* argv[])
{
    double eps = strtod(argv[2], NULL);
    double a = strtod(argv[3], NULL);
    double b = strtod(argv[4], NULL);
    double c = strtod(argv[5], NULL);

    if ((a < eps) || (b < eps) || (c < eps))
    {
        printf("It cant be sides of right triangle\n");
    }

    double nums[3] = {a, b, c};
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (nums[j + 1] - nums[j] < eps)
            {
                double temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    if (fabs(nums[0] * nums[0] + nums[1] * nums[1] - nums[2] * nums[2]) < eps)
    {
        printf("It can be sides of right triangle\n");
    }
    else
    {
        printf("It cant be sides of right triangle\n");
    }
}

void handle_unknown_opt(char* argv[])
{
    fprintf(stderr, "Error: unknown flag %c\n", argv[1][1]);
}

option_t opt_handler(char* argv[])
{
    switch (argv[1][1])
    {
        case 'q':
            return OPT_Q;
        case 'm':
            return OPT_M;
        case 't':
            return OPT_T;
        default:
            return OPT_UNKNOWN;
    }
}