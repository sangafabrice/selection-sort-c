#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

typedef unsigned index_t;
typedef long number_t;
typedef unsigned input_size_t;

void parse_numbers(char *argv[], number_t *firstptr, number_t **lastptr)
{
    char *endptr = NULL;

    while (*argv != NULL)
    {
        char *argstr = *(argv++);

        errno = 0;
        number_t a = strtol(argstr, &endptr, 10);

        if (*endptr == '\0' && !(errno == ERANGE && (a == LONG_MAX || a == LONG_MIN)))
        {
            *firstptr = a;
            *lastptr = firstptr++;
        }
        else
        {
            fprintf(stderr, "\x1b[93mThe argument '%s' is ignored.\x1b[0m\n", argstr);
        }
    }

    errno = 0;
}

void print_numbers(number_t *firstptr, number_t *lastptr)
{
    while (firstptr <= lastptr)
    {
        printf("%ld ", *(firstptr++));
    }
}