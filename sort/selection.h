#include "numio.h"

number_t *minimum_ptr(number_t A[], number_t *lastptr)
{
    number_t *minptr = A;

    while (++A <= lastptr)
    {
        if (*minptr > *A)
        {
            minptr = A;
        }
    }

    return minptr;
}

void swap(number_t *first, number_t *min)
{
    number_t temp = *first;
    *first = *min;
    *min = temp;
}

void selection_sort(number_t A[], number_t *lastptr)
{
    for (number_t *firstptr = A; firstptr <= lastptr - 1; firstptr++)
    {
        number_t *minptr = minimum_ptr(firstptr, lastptr);

        if (firstptr != minptr)
        {
            swap(firstptr, minptr);
        }
    }
}