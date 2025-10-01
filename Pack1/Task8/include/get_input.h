#ifndef GET_INPUT_H
#define GET_INPUT_H

typedef enum
{
    INVALID_ARGUMENT,
    INVALID_ARGUMENT_COUNT,
    OK
} status_code;

void print_help_msg(char* program_name);

void print_dec_to_base(long long number, int base);

int is_valid_number_str(char* str);

status_code input_processing(int argc);

#endif