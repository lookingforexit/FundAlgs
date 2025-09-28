#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "argument_processing.h"

void print_help_msg(char* program_name)
{
    printf("Usage: %s <flag> <decimal number>\n", program_name);
    printf("Available flags: -h, -p, -s, -e, -a, -f ('-' can be replaced by '/').\n");
    printf("For flag 'a' number has to be in 1-10 range\n");
    printf("For flag 'f' number has to be non-negative\n");
}

status_code_t argument_validation(const int argc, char* argv[])
{
    if (argc != 3)
    {
        return INVALID_ARGUMENT_COUNT;
    }

    char* flag = argv[1];
    if (strlen(flag) != 2 || (flag[0] != '-' && flag[0] != '/'))
    {
        return INVALID_ARGUMENT;
    }

    char* endptr;
    int number = (int)strtol(argv[2], &endptr, 10);
    if (*endptr != '\0')
    {
        return INVALID_ARGUMENT;
    }

    switch (flag[1])
    {
        case 'h':
            break;
        case 'p':
            break;
        case 's':
            break;
        case 'e':
            break;
        case 'a':
            if (number < 1 || number > 10)
            {
                return INVALID_ARGUMENT;
            }

            break;
        case 'f':
            if (number < 0)
            {
                return INVALID_ARGUMENT;
            }

            break;
        default:
            return INVALID_ARGUMENT;
    }

    return OK;
}