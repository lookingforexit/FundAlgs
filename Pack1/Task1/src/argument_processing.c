#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "math_operations.h"
#include "argument_processing.h"

void print_help_msg(char* program_name)
{
    printf("Usage: %s <number> <flag>.\n", program_name);
    printf("Available flags: -h, -p, -s, -e, -a, -f ('-' can be replaced by '/').\n");
    printf("For '-d' number has to be <= 10.\n");
}

status_code argument_validation(const int argc, char* argv[])
{
    if (argv == NULL)
    {
        return INVALID_ARGUMENT;
    }
    if (argc != 3)
    {
        return INVALID_ARGUMENT_COUNT;
    }

    char *number = argv[1];
    int start_num_pos = 0;
    if (number[start_num_pos] == '-')
    {
        ++start_num_pos;
    }
    if (!number[start_num_pos])
    {
        return INVALID_ARGUMENT;
    }
    while (number[start_num_pos])
    {
        if (!isdigit(number[start_num_pos]))
        {
            return INVALID_ARGUMENT;
        }
        ++start_num_pos;
    }

    const char *flag = argv[2];
    if (flag[0] != '-' && flag[0] != '/')
    {
        return INVALID_ARGUMENT;
    }

    if ((flag[1] != 'h' && flag[1] != 'p' &&
        flag[1] != 's' && flag[1] != 'a' &&
        flag[1] != 'f') || flag[2] != '\0')
    {
        return INVALID_ARGUMENT;
    }
    if (flag[1] == 'e' && atoi(number) > 10)
    {
        return INVALID_ARGUMENT;
    }

    return OK;
}

void argument_processing(char* argv[])
{
    int number = atoi(argv[1]);
    char *flag = argv[2];

    switch (flag[1])
    {
        case 'h':
            print_multiplies(number);
            break;
        case 'p':
            print_is_prime(number);
            break;
        case 's':
            print_hex_digits(number);
            break;
        case 'e':
            print_pow_table(number);
            break;
        case 'a':
            print_sum_btw_one_and_number(number);
            break;
        case 'f':
            print_factorial(number);
            break;
    }

    return;
}