#include <stdio.h>

#include "vector_utils.h"
#include "functions.h"

int main(void)
{
    printf("Enter values: ");

    int tab[100] = { 0 };

    int size = read_vector(tab, 100, -1);

    if (size < 1)
    {
        if (size == -2)
        {
            printf("Incorrect input\n");
            return 1;
        }

        printf("Not enough data available");
        return 3;
    }

    int result = get_next_number(tab, size, ALL_ODD);

    if (result == -1)
    {
        printf("Nothing to show\n");
    }
    else
    {
        printf("%d ", result);

        while ((result = get_next_number(NULL, 0, ALL_ODD)) != -1)
        {
            printf("%d ", result);
        }

        printf("\n");
    }

    result = get_next_number(tab, size, ALL_EVEN);

    if (result == -1)
    {
        printf("Nothing to show\n");
    }
    else
    {
        printf("%d ", result);

        while ((result = get_next_number(NULL, 0, ALL_EVEN)) != -1)
        {
            printf("%d ", result);
        }

        printf("\n");
    }

    result = get_next_number(tab, size, MIX);

    if (result == -1)
    {
        printf("Nothing to show\n");
    }
    else
    {
        printf("%d ", result);

        while ((result = get_next_number(NULL, 0, MIX)) != -1)
        {
            printf("%d ", result);
        }

        printf("\n");
    }


    return 0;
}
