#include <stdio.h>
#include <unistd.h>
#include "argument_validation.h"

void print_help_msg(char* program_name)
{
    printf("Usage: %s <existing input filename> <existing output filename>\n", program_name);
}

int filename_validation(char* filename)
{
    if (access(filename, F_OK) != 0)
    {
        return 0;
    }
    return 1;
}

status_code_t arguments_validation(int argc, char* argv[])
{
    if (argc != 3)
    {
        return INVALID_ARGUMENT_COUNT;
    }

    char* input_filename = argv[1];
    if (!filename_validation(input_filename))
    {
        return INVALID_ARGUMENT;
    }

    char* output_filename = argv[2];
    if (!filename_validation(output_filename))
    {
        return INVALID_ARGUMENT;
    }

    return OK;
}