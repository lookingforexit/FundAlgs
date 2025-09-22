#include <stdio.h>
#include "input_validation.h"
#include "print_calculations.h"

int main(int argc, char* argv[])
{
    if (argc != 1)
    {
        printf("Program has to run without command line flags.\n");
        print_help_msg(argv[0]);
        return 1;
    }

    print_help_msg(argv[0]);

    int precision;
    status_code code;

    printf("Enter the precision:\n");
    get_input(&precision, &code);

    if (code == INVALID_ARGUMENT)
    {
        print_help_msg(argv[0]);
        return 1;
    }

    print_calculations(precision);
}