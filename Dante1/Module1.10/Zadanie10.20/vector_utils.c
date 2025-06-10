#include "vector_utils.h"
#include <stdio.h>

int find(const int* tab, int size, int to_find)
{
    static int pointer = 0;
    static const int* temp_array = NULL;
    static int temp_size = 0;

    if (tab == NULL)
    {
        if (temp_array == NULL)
        {
            return -2;
        }
        tab = temp_array;
        size = temp_size;
    }
    else
    {
        if (size <= 0)
        {
            return -2;
        }
        temp_array = tab;
        temp_size = size;
        pointer = 0;
    }

    for (int i = pointer; i < size; ++i)
    {
        if (*(tab + i) == to_find)
        {
            pointer = i + 1;
            return i;
        }
    }

    pointer = 0;
    return -1;
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

int read_vector(int *vec, int size, int stop_value)
{
    if (size < 1 || vec == NULL || size > 100)
    {
        return -1;
    }

    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        int check = scanf("%i", &*(vec + i));
        if (check != 1)
        {
            return -2;
        }
        if (*(vec + i) == stop_value)
        {
            break;
        }
        counter++;
    }

    return counter;
}
