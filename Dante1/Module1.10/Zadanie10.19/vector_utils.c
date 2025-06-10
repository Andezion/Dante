#include "vector_utils.h"
#include <stdio.h>
#include <malloc.h>

int read_vector(int *tab, int size, int stop_value)
{
    if (size < 1 || tab == NULL || size > 100)
    {
        return -1;
    }

    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        int check = scanf("%i", &*(tab + i));
        if (check != 1)
        {
            return -2;
        }
        if (*(tab + i) == stop_value)
        {
            break;
        }
        counter++;
    }

    return counter;
}

void display_vector(const int* tab, int size)
{
    if(tab == NULL || size < 0)
    {
        return;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%i ",*(tab + i));
    }
}

int reverse_vector(int* tab, int size)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    int *new = malloc(sizeof(int) * size + 1);
    for(int i = 0; i < size; i++)
    {
        *(new + i) = *(tab + size - i - 1);
    }

    for(int i = 0; i < size; i++)
    {
        *(tab + i) = *(new + i);
    }

    free(new);
    return 0;
}
