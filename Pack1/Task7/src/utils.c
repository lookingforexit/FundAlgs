#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

char* delete_leading_zeros(char* str)
{
    while (*str == '0')
    {
        ++str;
    }
    if (*str == '\0')
    {
        return "0";
    }
    return str;
}

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

    char num_str[1024];
    int pos = 0;

    while ((ascii_value = fgetc(input_file)) != EOF)
    {
        char ch = (char)ascii_value;

        if (isdigit(ch) || isalpha(ch))
        {
            is_printed = 0;
            
            if (isdigit(ch))
            {
                int value = (ch - '0');
                basis = value >= basis ? (value + 1) : basis;
            }
            else
            {
                int value = isupper(ch) ? (ch - 'A') + 10 : (ch - 'a') + 10;
                basis = value >= basis ? (value + 1) : basis;
            }

            num_str[pos] = ch;
            ++pos;
        }
        else 
        {
            if (basis >= 2 && basis <= 36 && !is_printed)
            {
                num_str[pos] = '\0';
                fprintf(output_file, "%s %d %lld\n", delete_leading_zeros(num_str), basis, strtoll(num_str, NULL, basis));
                is_printed = 1;
            }
            basis = 2;
            pos = 0;
        }
    }
    if (basis >= 2 && !is_printed)
    {
        num_str[pos] = '\0';
        fprintf(output_file, "%s %d %lld\n", delete_leading_zeros(num_str), basis, strtoll(num_str, NULL, basis));
    }
    fprintf(output_file, "Done");

    fclose(input_file);
    fclose(output_file);
}