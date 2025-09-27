#include <stdio.h>
#include <string.h>
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

    callback_t handlers[5] = 
    {
        handle_d_opt, 
        handle_i_opt, 
        handle_s_opt,
        handle_a_opt, 
        handle_unknown_opt
    };

    if (argv[1][1] != 'n')
    {
        char* full_argv[argc + 1];
        for (int i = 0; i < argc; ++i)
        {
            full_argv[i] = argv[i];
        }

        char filename_buffer[1024];
        char* symbol = strrchr(full_argv[argc - 1], '/');
        if (symbol) 
        {
            int dir_length = symbol - full_argv[argc - 1] + 1;
            memcpy(filename_buffer, full_argv[argc - 1], dir_length);
            strcpy(filename_buffer + dir_length, "out_");
            strcat(filename_buffer + dir_length, symbol + 1);
        } 
        else 
        {
            strcpy(filename_buffer, "out_");
            strcat(filename_buffer, full_argv[argc - 1]);
        }
        full_argv[argc] = filename_buffer;
        
        option_t option = opt_handler(full_argv);
        handlers[option](full_argv);
    }
    else
    {
        option_t option = opt_handler(argv);
        handlers[option](argv);
    }    
}