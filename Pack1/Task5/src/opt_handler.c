#include <stdio.h>
#include <ctype.h>
#include "opt_handler.h"

int is_letter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void handle_d_opt(char* argv[])
{
    char* input_filename = argv[2];
    FILE* input_file = fopen(input_filename, "r");
    if (!input_file)
    {
        fprintf(stderr, "Error: unable to open input file\n");
        return;
    }

    char* output_filename = argv[3];
    FILE* output_file = fopen(output_filename, "w");
    if (!output_file)
    {
        fprintf(stderr, "%s\n", output_filename);
        fprintf(stderr, "Error: unable to open output file\n");
        return;
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF)
    {
        if (!isdigit(ch))
        {
            fputc(ch, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void handle_i_opt(char* argv[])
{
    char* input_filename = argv[2];
    FILE* input_file = fopen(input_filename, "r");
    if (!input_file)
    {
        fprintf(stderr, "Error: unable to open input file\n");
        return;
    }

    char* output_filename = argv[3];
    FILE* output_file = fopen(output_filename, "w");
    if (!output_file)
    {
        fprintf(stderr, "Error: unable to open output file\n");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file))
    {
        int i = 0;
        int count_of_letters = 0;

        while (buffer[i] != '\0')
        {
            if (is_letter(buffer[i]))
            {
                ++count_of_letters;
            }

            ++i;
        }

        fprintf(output_file, "%d\n", count_of_letters);
    }

    fclose(input_file);
    fclose(output_file);
}

void handle_s_opt(char* argv[])
{
    char* input_filename = argv[2];
    FILE* input_file = fopen(input_filename, "r");
    if (!input_file)
    {
        fprintf(stderr, "Error: unable to open input file\n");
        return;
    }

    char* output_filename = argv[3];
    FILE* output_file = fopen(output_filename, "w");
    if (!output_file)
    {
        fprintf(stderr, "Error: unable to open output file\n");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file))
    {
        int i = 0;
        int count_of_symbols = 0;

        while (buffer[i] != '\0')
        {
            if (!is_letter(buffer[i]) && !isdigit(buffer[i]) && buffer[i] != ' ' && buffer[i] != '\n')
            {
                ++count_of_symbols;
            }
            ++i;
        }

        fprintf(output_file, "%d\n", count_of_symbols);
    }

    fclose(input_file);
    fclose(output_file);
}

void handle_a_opt(char* argv[])
{
    char* input_filename = argv[2];
    FILE* input_file = fopen(input_filename, "r");
    if (!input_file)
    {
        fprintf(stderr, "Error: unable to open input file\n");
        return;
    }

    char* output_filename = argv[3];
    FILE* output_file = fopen(output_filename, "w");
    if (!output_file)
    {
        fprintf(stderr, "Error: unable to open output file\n");
        return;
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF)
    {
        if (ch == ' ' || ch == '\n' || isdigit(ch))
        {
            fprintf(output_file, "%c", ch);
        }
        else
        {
            fprintf(output_file, "%X", ch);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void handle_unknown_opt(char* argv[])
{
    fprintf(stderr, "Error: unknown flag %c\n", argv[1][1]);
}

option_t opt_handler(char* argv[])
{
    switch (argv[1][1] != 'n' ? argv[1][1] : argv[1][2])
    {
        case 'd':
            return OPT_D;
        case 'i':
            return OPT_I;
        case 's':
            return OPT_S;
        case 'a':
            return OPT_A;
        default:
            return OPT_UNKNOWN;
    }
}