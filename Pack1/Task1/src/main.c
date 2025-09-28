#include <stdio.h>
#include "argument_processing.h"
#include "opt_handler.h"

int main(int argc, char *argv[])
{
    const status_code_t code = argument_validation(argc, argv);

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

    callback_t handlers[7] = 
    {
        handle_h_opt,
        handle_p_opt,
        handle_s_opt,
        handle_e_opt,
        handle_a_opt,
        handle_f_opt
    };

    option_t option = get_option(argv);
    handlers[option](argv);

    return 0;
}