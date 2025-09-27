#ifndef OPT_HANDLER_H
#define OPT_HANDLER_H

typedef enum
{
    OPT_Q,
    OPT_M,
    OPT_T,
    OPT_UNKNOWN
} option_t;

void solve_quadratic(double a, double b, double c, double eps);

void handle_q_opt(char* argv[]);

void handle_m_opt(char* argv[]);

void handle_t_opt(char* argv[]);

void handle_unknown_opt(char* argv[]);

option_t opt_handler(char* argv[]);

typedef void (*callback_t)(char* argv[]);

#endif