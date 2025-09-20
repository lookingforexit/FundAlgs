#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/input_validation.h"

void print_help_msg(char* program_name)
{
    printf("Usage: <amount of requests>\n");
    printf("Next n lines has to consist of only 1 positive number.\n");
}

int get_input(int* number, status_code* code)
{
    char buffer[100];
    char term_symbol;
    if (fgets(buffer, sizeof(buffer), stdin)) 
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (sscanf(buffer, "%d%c", number, &term_symbol) == 1) 
        {
            if (*number < 1)
            {
                *code = INVALID_ARGUMENT;
                return -1;
            }
            
            *code = OK;
            return *number;
        } 

        *code = INVALID_ARGUMENT;
        return -1;
    } 

    *code = INVALID_ARGUMENT;
    return -1;
}