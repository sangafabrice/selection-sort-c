#include "numio.h"

index_t minimum_index(number_t A[], input_size_t n, index_t s)
{
    index_t minindex = s;

    for (index_t i = s + 1; i <= n - 1; i++)
    {
        if (A[minindex] > A[i])
        {
            minindex = i;
        }
    }

    return minindex;
}

void swap(number_t *first, number_t *min)
{
    number_t temp = *first;
    *first = *min;
    *min = temp;
}

void selection_sort(number_t A[], input_size_t n)
{
    for (index_t s = 0; 2 <= n - s; s++)
    {
        index_t minindex = minimum_index(A, n, s);
        
        if (s != minindex)
        {
            swap(&A[s], &A[minindex]);
        }
    }
}