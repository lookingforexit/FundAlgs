#ifndef ARGUMENT_VALIDATION_H
#define ARGUMENT_VALIDATION_H

typedef enum
{
    INVALID_ARGUMENT_COUNT,
    INVALID_ARGUMENT,
    OK
} status_code_t;

void print_help_msg(char* program_name);

int filename_validation(char* filename);

status_code_t arguments_validation(int argc, char* argv[]);

#endif