#include "sort/selection.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        return EXIT_FAILURE;
    }

    input_size_t n = argc - 1;
    number_t A[n];

    parse_numbers(&argv[1], A, &n);

    if (n == 0)
    {
        return EXIT_FAILURE;
    }

    selection_sort(A, &A[n-1]);

    print_numbers(A, n);

    return EXIT_SUCCESS;
}