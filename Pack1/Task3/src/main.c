#include <stdio.h>
#include "argument_validation.h"
#include "opt_handler.h"

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

    callback_t handlers[4] = 
    {
        handle_q_opt, 
        handle_m_opt, 
        handle_t_opt, 
        handle_unknown_opt
    };

    option_t option = opt_handler(argv);
    handlers[option](argv);
}