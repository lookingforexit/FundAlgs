#include <stdio.h>
#include <stdlib.h>
#include "argument_processing.h"

void print_help_msg(char* filename)
{
    printf("Usage: %s <epsilon>\n", filename);
    printf("Epsilon has to be float number in (1e-24)-(1e-1) range\n");
}

status_code argument_validation(int argc, char* argv[])
{
    if (argc != 2)
    {
        return INVALID_ARGUMENT_COUNT;
    }

    if (argv == NULL)
    {
        return INVALID_ARGUMENT;
    }

    char* endptr;
    long double number = strtold(argv[1], &endptr);
    if (*endptr != '\0') 
    {
        return INVALID_ARGUMENT;
    }

    if ((number > 1e-1) || (number < 1e-24))
    {
        return INVALID_ARGUMENT;
    }

    return OK;
}