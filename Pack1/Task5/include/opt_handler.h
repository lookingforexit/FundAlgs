#ifndef OPT_HANDLER_H
#define OPT_HANDLER_H

typedef enum
{
    OPT_D,
    OPT_I,
    OPT_S,
    OPT_A,
    OPT_UNKNOWN
} option_t;

int is_letter(char ch);

void handle_d_opt(char* argv[]);

void handle_i_opt(char* argv[]);

void handle_s_opt(char* argv[]);

void handle_a_opt(char* argv[]);

void handle_unknown_opt(char* argv[]);

option_t opt_handler(char* argv[]);

typedef void (*callback_t)(char* argv[]);

#endif