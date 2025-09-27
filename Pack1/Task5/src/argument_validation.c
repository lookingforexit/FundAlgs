#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "argument_validation.h"

void print_help_msg(char* program_name)
{
    printf("Usage: %s <flag> <input_filename> [optional: <output_filename>]\n", program_name);
    printf("Available flags: -d, -i, -s, -a ('-' can be replaced by '/')\n");
    printf("Available flags: -nd, -ni, -ns, -na ('-' can be replaced by '/)\n");
    printf("If you use optional 'n' in flag you have to write output filename\n");
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
    if (argc < 3)
    {
        return INVALID_ARGUMENT_COUNT;
    }

    char* flag = argv[1];
    if ((strlen(flag) != 2 && strlen(flag) != 3) || (flag[0] != '-' && flag[0] != '/'))
    {
        return INVALID_ARGUMENT;
    }

    if (strlen(flag) == 3 && flag[1] != 'n')
    {
        return INVALID_ARGUMENT;
    }

    int is_n_flag = (strlen(flag) == 3);
    if (!is_n_flag)
    {
        if (argc != 3)
        {
            return INVALID_ARGUMENT_COUNT;
        }
    }
    else
    {
        if (argc != 4)
        {
            return INVALID_ARGUMENT_COUNT;
        }
    }
    
    if (!is_n_flag)
    {
        if (!filename_validation(argv[2]))
        {
            return INVALID_ARGUMENT;
        }
    }
    else
    {
        if (!filename_validation(argv[2]) || !filename_validation(argv[3]))
        {
            return INVALID_ARGUMENT;
        }
    }

    switch (flag[is_n_flag + 1])
    {
        case 'd':
            return OK;
        case 'i':
            return OK;
        case 's':
            return OK;
        case 'a':
            return OK;
        default:
            return INVALID_ARGUMENT;
    }
}