#include <stdio.h>
#include "vector_utils.h"

int read_vector(int *tab, int size, int stop_value)
{
    if (size < 1 || tab == NULL || size > 250)
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
    if(tab == NULL || size <= 0)
    {
        return;
    }

    if(size > 150)
    {
        size = 150;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%i ",*(tab + i));
    }
    printf("\n");
}
