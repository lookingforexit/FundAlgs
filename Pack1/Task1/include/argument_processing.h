#ifndef ARGUMENT_PROCESSING_H
#define ARGUMENT_PROCESSING_H

typedef enum
{
    OK,
    INVALID_ARGUMENT,
    INVALID_ARGUMENT_COUNT
} status_code;

status_code argument_validation(const int argc, char* argv[]);

void argument_processing(char* argv[]);

void print_help_msg(char* program_name);

#endif