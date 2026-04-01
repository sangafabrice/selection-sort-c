#include "numio.h"

number_t *minimum_ptr(number_t A[], input_size_t n, index_t s)
{
    number_t *minptr = A + s;

    while (++s < n)
    {
        if (*minptr > A[s])
        {
            minptr = A + s;
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
        number_t *minptr = minimum_ptr(A, n, s);
        
        if (A + s != minptr)
        {
            swap(&A[s], minptr);
        }
    }
}