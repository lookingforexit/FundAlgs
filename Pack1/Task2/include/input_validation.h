#ifndef INPUT_VALIDAION_H
#define INPUT_VALIDATION_H

typedef enum
{
    OK,
    INVALID_ARGUMENT
} status_code;

void print_help_msg(char* program_name);

int get_input(int* number, status_code* code);

#endif