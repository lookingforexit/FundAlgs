#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "argument_validation.h"

void print_help_msg(char* program_name)
{
    printf("Usage: %s <flag> <arguments>\n", program_name);
    printf("Available flags -q, -m, -t ('-' can be replaced by '/')\n");
    printf("Usage for 'q' flag: <eps> <number1> <number2> <number3>\n");
    printf("Usage for 'm' flag: <number1> <number2>\n");
    printf("Usage for 't' flag: <eps> <number1> <number2> <number3>\n");
}

status_code_t arguments_validation(int argc, char* argv[])
{
    if (argc < 2)
    {
        return INVALID_ARGUMENT_COUNT;
    }

    char* flag = argv[1];
    if (strlen(flag) != 2 || (flag[0] != '-' && flag[0] != '/'))
    {
        return INVALID_ARGUMENT;
    }

    switch (flag[1])
    {
        case 'q':
            if (argc != 6)
            {
                return INVALID_ARGUMENT_COUNT;
            }
            
            for (int i = 2; i < 6; ++i)
            {
                char* endptr;
                strtod(argv[i], &endptr);
                if (*endptr != '\0')
                {
                    return INVALID_ARGUMENT;
                }
            }

            if (strtod(argv[2], NULL) <= 0)
            {
                return INVALID_ARGUMENT;
            }

            break;
        case 'm':
            if (argc != 4)
            {
                return INVALID_ARGUMENT_COUNT;
            }

            for (int i = 2; i < 4; ++i)
            {
                char* endptr;
                int number = (int)strtol(argv[i], &endptr, 10);
                if (*endptr != '\0' || number == 0)
                {
                    return INVALID_ARGUMENT;
                }
            }

            break;
        case 't':
            if (argc != 6)
            {
                return INVALID_ARGUMENT_COUNT;
            }

            for (int i = 2; i < 6; ++i)
            {
                char* endptr;
                double number = strtod(argv[i], &endptr);
                if (*endptr != '\0' || number <= 0)
                {
                    return INVALID_ARGUMENT;
                }
            }

            break;
        default:
            return INVALID_ARGUMENT;
    }

    return OK;
}