#include <stdio.h>
#include <stdlib.h>

typedef unsigned index_t;
typedef long number_t;
typedef unsigned input_size_t;

void parse_numbers(char *argv[], number_t A[])
{
    for (index_t i = 0; *argv != NULL; i++)
    {
        A[i] = strtol(*(argv++), NULL, 10);
    }
}

void print_numbers(number_t A[], input_size_t n)
{
    for (index_t i = 0; i < n; i++)
    {
        printf("%ld ", A[i]);
    }
}