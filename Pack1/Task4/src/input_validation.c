#include <stdio.h>
#include <string.h>
#include "input_validation.h"

void print_help_msg(char* program_name)
{
    printf("Usage: %s\n", program_name);
    printf("Enter the precision: <precision>\n");
    printf("Precision has to be a natural number less tor equals to 24.\n");
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
            if (*number < 1 || *number > 24)
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