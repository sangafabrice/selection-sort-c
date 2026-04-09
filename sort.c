#include "sort/selection.h"

int main(int argc, char *argv[])
{
    player_t first[argc], *last = NULL;

    parse_players(&argv[1], first, &last);

    if (!last)
    {
        return EXIT_FAILURE;
    }

    selection_sort(first, last);

    print_players(first, last);

    return EXIT_SUCCESS;
}