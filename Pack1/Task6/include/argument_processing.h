#ifndef ARGUMENT_PROCESSING_H
#define ARGUMENT_PROCESSING_H

typedef enum
{
    INVALID_ARGUMENT,
    INVALID_ARGUMENT_COUNT,
    OK
} status_code;

void print_help_msg(char* filename);

status_code argument_validation(int argc, char* argv[]);

#endif