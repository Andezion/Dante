#include <stdio.h>
#include "vector_utils.h"

int main(void)
{
    printf("Enter values: ");

    int tab[100];
    const int size = read_vector(tab, 100, 0);
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

    display_vector(tab, size);
    if (reverse_vector(tab, size) != 0)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("\n");
    display_vector(tab, size);

    return 0;
}
