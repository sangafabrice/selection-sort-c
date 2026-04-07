#include "consoletime.h"
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

void selection_sort(number_t *firstptr, number_t *lastptr)
{
    console_time("selection sort");

    while (firstptr < lastptr)
    {
        number_t *minptr = minimum_ptr(firstptr, lastptr);
        swap(firstptr++, minptr);
    }

    console_timeEnd("selection sort");
}