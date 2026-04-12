#include "sort/selection.h"

int main(int argc, char *argv[])
{
    number_t first[argc], *last = nullptr;

    parse_numbers(&argv[1], first, &last);

    if (!last)
        return EXIT_FAILURE;

    selection_sort(first, last);

    print_numbers(first, last);

    return EXIT_SUCCESS;
}