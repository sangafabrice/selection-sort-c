#include "numio.h"

number_t *minimum_ptr(number_t A[], number_t *sentinelptr)
{
    number_t *minptr = A;

    while (++A != sentinelptr)
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

void selection_sort(number_t A[], input_size_t n)
{
    for (index_t s = 0; 1 < n - s; s++)
    {
        number_t *firstptr = &A[s];
        number_t *minptr = minimum_ptr(firstptr, &A[n]);

        if (firstptr != minptr)
        {
            swap(firstptr, minptr);
        }
    }
}