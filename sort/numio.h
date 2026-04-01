#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

typedef unsigned index_t;
typedef long number_t;
typedef unsigned input_size_t;

void parse_numbers(char *argv[], number_t A[], input_size_t *n)
{
    char *endptr;

    for (index_t i = 0; *argv != NULL; argv++)
    {
        char *argstr = *argv;

        errno = 0;
        number_t a = strtol(argstr, &endptr, 10);

        if (*endptr == '\0' && !(errno == ERANGE && (a == LONG_MAX || a == LONG_MIN)))
        {
            A[i++] = a;
        }
        else
        {
            (*n)--;
            fprintf(stderr, "\x1b[93mThe argument '%s' is ignored.\x1b[0m\n", argstr);
        }
    }

    errno = 0;
}

void print_numbers(number_t A[], input_size_t n)
{
    for (index_t i = 0; i < n; i++)
    {
        printf("%ld ", A[i]);
    }
}