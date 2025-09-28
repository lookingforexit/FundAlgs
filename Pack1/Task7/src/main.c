#include <stdio.h>
#include "argument_validation.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    status_code_t code = arguments_validation(argc, argv);

    if (code == INVALID_ARGUMENT)
    {
        printf("Invalid argument provided\n");
        print_help_msg(argv[0]);
        return 1;
    }
    else if (code == INVALID_ARGUMENT_COUNT)
    {
        printf("Invalid amount of arguments provided\n");
        print_help_msg(argv[0]);
        return 1;
    }

    determine_the_basis(argv[1], argv[2]);
}