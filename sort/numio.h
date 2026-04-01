#include <stdio.h>
#include <stdlib.h>

typedef unsigned index_t;
typedef long number_t;
typedef unsigned input_size_t;

void parse_numbers(char *argv[], number_t A[], input_size_t *n)
{
    char *endptr;

    for (index_t i = 0; *argv != NULL; argv++)
    {
        char *argstr = *argv;

        number_t a = strtol(argstr, &endptr, 10);

        if (*endptr == '\0')
        {
            A[i++] = a;
        }
        else
        {
            (*n)--;
            fprintf(stderr, "\x1b[93mThe argument '%s' is ignored.\x1b[0m\n", argstr);
        }
    }
}

void print_numbers(number_t A[], input_size_t n)
{
    for (index_t i = 0; i < n; i++)
    {
        printf("%ld ", A[i]);
    }
}