#include "sort/selection.h"

int main(int argc, char *argv[])
{
    if (--argc < 1)
    {
        return EXIT_FAILURE;
    }

    number_t *first = malloc(sizeof(number_t) * argc), *last;

    parse_numbers(&argv[1], first, &last);

    if (last == NULL)
    {
        return EXIT_FAILURE;
    }

    selection_sort(first, last);

    print_numbers(first, last);

    free(first);

    return EXIT_SUCCESS;
}