#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

typedef unsigned index_t;
typedef long number_t;
typedef unsigned input_size_t;
typedef struct player_t player_t;

struct player_t
{
    char const *name;
    number_t caps;
};

void parse_players(char *argv[], player_t *firstptr, player_t **lastptr)
{
    char *endptr;

    while (*argv != NULL)
    {
        char *namestr = *(argv++);
        char *capsnum = *(argv++);

        errno = 0;
        number_t a = strtol(capsnum, &endptr, 10);

        if (*endptr == '\0' && !(errno == ERANGE && (a == LONG_MAX || a == LONG_MIN)))
        {
            (*firstptr).name = namestr;
            (*firstptr).caps = a;
            *lastptr = firstptr++;
        }
        else
        {
            break;
        }
    }

    errno = 0;
}

void print_players(player_t *firstptr, player_t *lastptr)
{
    while (firstptr <= lastptr)
    {
        printf("%s:\t%ld\n", (*firstptr++).name, (*firstptr).caps);
    }
}