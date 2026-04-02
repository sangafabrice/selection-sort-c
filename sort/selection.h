#include "numio.h"

typedef unsigned unsorted_size_t;

number_t *minimum_ptr(number_t A[], unsorted_size_t n_s)
{
    number_t *minptr = A;

    for (number_t *ptr = A + 1; ptr != A + n_s; ptr++)
    {
        if (*minptr > *ptr)
        {
            minptr = ptr;
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
        number_t *firstptr = A + s;
        number_t *minptr = minimum_ptr(firstptr, n - s);

        if (firstptr != minptr)
        {
            swap(firstptr, minptr);
        }
    }
}