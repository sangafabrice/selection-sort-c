#include "numio.h"

number_t *minimum_ptr(number_t *firstptr, number_t *lastptr)
{
    auto minptr = firstptr;

    while (++firstptr <= lastptr)
        if (*minptr > *firstptr)
            minptr = firstptr;

    return minptr;
}

void swap(number_t *firstptr, number_t *minptr)
{
    auto temp = *firstptr;
    *firstptr = *minptr;
    *minptr = temp;
}

void selection_sort(number_t *firstptr, number_t *lastptr)
{
    while (firstptr < lastptr)
        swap(firstptr++, minimum_ptr(firstptr, lastptr));
}