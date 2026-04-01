#include "numio.h"

index_t minimum_index(number_t A[], input_size_t n, index_t s)
{
    number_t min = A[s];
    index_t minindex = s;

    for (index_t i = s + 1; i <= n - 1; i++)
    {
        if (min > A[i])
        {
            min = A[i];
            minindex = i;
        }
    }

    return minindex;
}

void swap(number_t A[], index_t s, index_t i)
{
    number_t temp = A[s];
    A[s] = A[i];
    A[i] = temp;
}

void selection_sort(number_t A[], input_size_t n)
{
    for (index_t s = 0; 2 <= n - s; s++)
    {
        index_t minindex = minimum_index(A, n, s);
        swap(A, s, minindex);
    }
}