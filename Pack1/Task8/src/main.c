#include <stdio.h>
#include "get_input.h"

int main(int argc, char* argv[])
{
    status_code code = input_processing(argc);
    if (code == INVALID_ARGUMENT)
    {
        fprintf(stderr, "Error: invalid argument provided\n");
        print_help_msg(argv[0]);
        return 1;
    }
    else if (code == INVALID_ARGUMENT_COUNT)
    {
        fprintf(stderr, "Error: invalid amount of arguments provided\n");
        print_help_msg(argv[0]);
        return 1;
    }

    return 0;
}