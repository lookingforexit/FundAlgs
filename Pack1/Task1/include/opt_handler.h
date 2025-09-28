#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

typedef enum
{
    OPT_H,
    OPT_P,
    OPT_S,
    OPT_A,
    OPT_E,
    OPT_F,
    OPT_UNKNOWN
} option_t;

option_t get_option(char* argv[]);

void handle_h_opt(char* argv[]);

void handle_p_opt(char* argv[]);

void handle_s_opt(char* argv[]);

void handle_e_opt(char* argv[]);

void handle_a_opt(char* argv[]);

void handle_f_opt(char* argv[]);

typedef void (*callback_t)(char* argv[]);

#endif