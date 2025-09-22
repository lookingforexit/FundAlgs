#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

typedef enum
{
    INVALID_ARGUMENT,
    OK
} status_code;

int get_input(int* number, status_code* code);

void print_help_msg(char* program_name);

#endif