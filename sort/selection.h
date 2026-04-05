#include "playerio.h"

player_t *minimum_ptr(player_t *firstptr, player_t *lastptr)
{
    player_t *minptr = firstptr;

    while (++firstptr <= lastptr)
    {
        if (minptr->caps > firstptr->caps)
        {
            minptr = firstptr;
        }
    }

    return minptr;
}

void swap(player_t *firstptr, player_t *minptr)
{
    player_t temp = *firstptr;
    *firstptr = *minptr;
    *minptr = temp;
}

void selection_sort(player_t *firstptr, player_t *lastptr)
{
    while (firstptr < lastptr)
    {
        player_t *minptr = minimum_ptr(firstptr, lastptr);
        swap(firstptr++, minptr);
    }
}