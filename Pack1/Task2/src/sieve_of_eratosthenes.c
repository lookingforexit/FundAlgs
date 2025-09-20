#include <stdio.h>
#include <stdlib.h>
#include "sieve_of_eratosthenes.h"

int* sieve_of_eratosthenes(const int max_num, int index)
{
    int* const sieve = calloc(max_num + 1, sizeof(int));
    if (!sieve)
    {
        printf("Unable to allocate memory for sieve.\n");
        return NULL;
    }

    int* const prime_numbers = malloc(index * sizeof(int));
    if (!prime_numbers)
    {
        printf("Unable to allocate memory for prime numbers.\n");
        return NULL;
    }

    int counter = 0;
    sieve[0] = -1, sieve[1] = -1;
    for (int i = 2; i * i <= max_num; ++i)
    {
        if (sieve[i] != -1)
        {
            for (long long j = i * i; j <= max_num; j += i)
            {
                sieve[j] = -1;
            }
        }
    }

    for (int i = 0; i < max_num + 1; ++i)
    {
        if (sieve[i] != -1 && counter <= index)
        {
            prime_numbers[counter++] = i;
        }
    }

    free(sieve);
    
    return prime_numbers;
}