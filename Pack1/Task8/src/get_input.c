#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "get_input.h"

void print_help_msg(char* program_name)
{
    printf("Usage: %s\n", program_name);
    printf("Enter the base for numbers [2..36]: <base>\n");
    printf("Enter the numbers in this base (uppercase), 'Stop' for stop input\n");
}

void print_dec_to_base(long long number, int base)
{
    if (number == 0) 
    {
        printf("0\n");
        return;
    }

    int is_negative = number < 0 ? 1 : 0;
    number = llabs(number);

    char buffer[1024];
    int pos = 0;
    while (number > 0)
    {
        if (number % base <= 9)
        {
            buffer[pos] = (number % base) + '0';
        }
        else
        {
            buffer[pos] = (number % base - 10) + 'A';
        }

        number /= base;
        ++pos;
    }

    if (is_negative) 
    {
        putc('-', stdout);
    }
    for (int i = 0; i < pos; ++i)
    {
        putc(buffer[pos - i - 1], stdout);
    }
    putc('\n', stdout);
}

int is_valid_number_str(char* str)
{
    if (str == NULL || *str == '\0')
    {
        return 0;
    }

    for (int i = (str[0] == '-') ? 1 : 0; i < (int)strlen(str); ++i)
    {
        if (!isdigit(str[i]) && !isupper(str[i]))
        {
            return 0;
        }
    }

    return 1;
}

status_code input_processing(int argc)
{
    if (argc != 1)
    {
        return INVALID_ARGUMENT_COUNT;
    }

    printf("Enter the base[2..36]: ");
    char line[1024];
    if (!fgets(line, sizeof(line), stdin))
    {
        return INVALID_ARGUMENT;
    }
    char* endptr;
    int base = (int)strtol(line, &endptr, 10);
    if ((*endptr != '\0' && *endptr != '\n') || base < 2 || base > 36)
    {
        return INVALID_ARGUMENT;
    }

    long long dec_number;
    long long max_number = (long long)(-1e32);
    printf("Enter the numbers in %d base (Stop for stop):\n", base);
    while (fgets(line, sizeof(line), stdin))
    {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "Stop") == 0)
        {
            break;
        }
        if (!is_valid_number_str(line))
        {
            return INVALID_ARGUMENT;
        }

        dec_number = strtoll(line, &endptr, base);
        if (*endptr != '\0')
        {
            return INVALID_ARGUMENT;
        }
        
        if (dec_number > max_number)
        {
            max_number = dec_number;
        }
    }

    printf("The max number is %lld\n", max_number);
    print_dec_to_base(max_number, 9);
    print_dec_to_base(max_number, 18);
    print_dec_to_base(max_number, 27);
    print_dec_to_base(max_number, 36);

    return OK;
}