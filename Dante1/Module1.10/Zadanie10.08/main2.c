#include <stdio.h>
#include "vector_utils.h"

int main(void)
{
    printf("Enter values: ");

    int tab[100];
    const int size = read_vector(tab, 100, -1);
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

    if (sort(tab, size) == 1)
    {
        printf("Incorrect input");
        return 1;
    }

    display_vector(tab, size);

    return 0;
}
