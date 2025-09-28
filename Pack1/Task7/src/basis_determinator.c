#include <stdio.h>
#include <ctype.h>
#include "basis_determinator.h"

void determine_the_basis(const char* input_filename, const char* output_filename)
{
    FILE* input_file = fopen(input_filename, "r");
    if (!input_file)
    {
        fprintf(stderr, "Error: unadle to open input file\n");
        return;
    }

    FILE* output_file = fopen(output_filename, "w");
    if (!output_file)
    {
        fprintf(stderr, "Error: unable to open output file\n");
        return;
    }

    int ascii_value;
    int basis = 2;
    int is_printed = 1;
    while ((ascii_value = fgetc(input_file)) != EOF)
    {
        char ch = (char)ascii_value;
        if (isdigit(ch) || isalpha(ch))
        {
            fputc(ch, output_file);

            is_printed = 0;
            
            if (isdigit(ch))
            {
                int value = (ch - '0');
                basis = value >= basis ? (value + 1) : basis;
            }
            else
            {
                ch = toupper(ch);
                int value = (ch - 'A') + 10;
                basis = value >= basis ? (value + 1) : basis;
            }
        }
        else 
        {
            if (basis >= 2 && basis <= 36 && !is_printed)
            {
                fprintf(output_file, " %d\n", basis);
                is_printed = 1;
            }
            basis = 2;
        }
    }
    if (basis >= 2 && !is_printed)
    {
        fprintf(output_file, " %d\n", basis);
    }
    fprintf(output_file, "Done");

    fclose(input_file);
    fclose(output_file);
}