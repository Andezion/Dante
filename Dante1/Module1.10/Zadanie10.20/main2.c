#include <stdio.h>

#include "vector_utils.h"

int main(void)
{
    printf("Enter values: ");

    int tab[100] = { 0 };

    int size = read_vector(tab, 100, 0);

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

    while (getchar() != '\n') {}

    int to_find;

    printf("Enter value to find: ");

    if (scanf("%d", &to_find) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }


    int index = find(tab, size, to_find);

    if (index == -2)
    {
        printf("Incorrect input\n");
        return 1;
    }

    if (index == -1)
    {
        printf("Nothing to show");
        return 0;
    }


    while (index != -1)
    {
        printf("%d ", index);

        index = find(NULL, 0, to_find);
    }

    return 0;
}
