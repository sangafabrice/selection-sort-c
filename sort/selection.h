#include "numio.h"

number_t *minimum_ptr(number_t *firstptr, number_t *lastptr)
{
    number_t *minptr = firstptr;

    while (++firstptr <= lastptr)
    {
        if (*minptr > *firstptr)
        {
            minptr = firstptr;
        }
    }

    return minptr;
}

void swap(number_t *firstptr, number_t *minptr)
{
    number_t temp = *firstptr;
    *firstptr = *minptr;
    *minptr = temp;
}

void selection_sort(number_t A[], number_t *lastptr)
{
    for (number_t *firstptr = A; firstptr < lastptr; firstptr++)
    {
        number_t *minptr = minimum_ptr(firstptr, lastptr);

        if (firstptr != minptr)
        {
            swap(firstptr, minptr);
        }
    }
}