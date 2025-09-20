#include <stdio.h>
#include "../include/argument_processing.h"
#include "../include/math_operations.h"

int main(int argc, char *argv[])
{
    const status_code code = argument_validation(argc, argv);

    if (code == INVALID_ARGUMENT)
    {
        printf("Error: invalid argument provided.\n");
        print_help_msg(argv[0]);
        return 1;
    }
    else if (code == INVALID_ARGUMENT_COUNT)
    {
        printf("Error: invalid count of arguments.\n");
        print_help_msg(argv[0]);
        return 1;
    }

    argument_processing(argv);

    return 0;
}