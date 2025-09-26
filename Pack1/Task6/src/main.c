#include <stdio.h>
#include <stdlib.h>
#include "print_calculations.h"
#include "argument_processing.h"

int main(int argc, char* argv[])
{
    status_code code = argument_validation(argc, argv);

    if (code == INVALID_ARGUMENT_COUNT)
    {
        printf("Invalid amount of arguments provided\n");
        print_help_msg(argv[0]);
        return 1;
    }

    if (code == INVALID_ARGUMENT)
    {
        printf("Invalid argument provided\n");
        print_help_msg(argv[0]);
        return 1;
    }

    long double eps = strtold(argv[1], NULL);
    print_calculations(eps);
}