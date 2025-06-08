#include <stdlib.h>
#include <stdio.h>
#include "vector_utils.h"

int read_vector(int *tab, int size, int stop_value)
{
    if (size < 1 || tab == NULL || size > 150)
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
    for(int i = 0; i < size; i++)
    {
        printf("%i ",*(tab + i));
    }
    printf("\n");
}

int bubble_sort(int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    for(int i = 0; i < size - 1; i++)
    {
        int pointer = 0;
        for(int j = 0; j < size - 1; j++)
        {
            if(tab[j] > tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                pointer = 1;
            }
        }
        display_vector(tab, size);
        if(pointer == 0)
        {
            break;
        }
    }

    return 0;
}
