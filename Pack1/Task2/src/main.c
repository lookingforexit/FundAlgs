#include <stdio.h>
#include <stdlib.h>
#include "../include/input_validation.h"
#include "../include/sieve_of_eratosthenes.h"

int main(int argc, char* argv[])
{
    printf("Amount of requests (>=1): ");

    int amount;
    status_code code;
    get_input(&amount, &code);
    if (code == INVALID_ARGUMENT)
    {
        print_help_msg(argv[0]);
        return 1;
    }

    int* const requests = malloc(amount * sizeof(int));
    if (requests == NULL)
    {
        printf("Unable to allocate memory for requests.\n");
        return 1;
    }

    int max = 0;
    for (int i = 0; i < amount; ++i)
    {
        printf("%d: ", i + 1);
        get_input(requests + i, &code);
        if (code == INVALID_ARGUMENT)
        {
            print_help_msg(argv[0]);
            free(requests);
            return 1;
        }

        if(*(requests + i) > max)
        {
            max = *(requests + i);
        }
    }

    int number = 100000;
    int* const primes = sieve_of_eratosthenes(number, max);

    if (primes == NULL)
    {
        printf("Unable to allocate memory for sieve.\n");
        free(requests);
        return 1;
    }

    printf("\n");

    for (int i = 0; i < amount; ++i)
    {
        printf("%d: %d\n", *(requests + i), primes[*(requests + i) - 1]);
    }

    free(requests);
    free(primes);

    return 0;
}