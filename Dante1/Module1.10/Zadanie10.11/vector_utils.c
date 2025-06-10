#include "vector_utils.h"
#include <stdio.h>

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
    if(counter > 150)
    {
        counter = 150;
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

int shift(int *array, int array_size, int positions_to_shift, enum direction dir)
{
    if(array == NULL || array_size <= 0 || (dir != 1 && dir != 2))
    {
        return 1;
    }

    if (positions_to_shift == 0)
    {
        return 0;
    }

    positions_to_shift = positions_to_shift % array_size;

    if (dir == ROTATE_RIGHT)
    {
        for (int i = 0; i < positions_to_shift; i++)
        {
            int temp = *(array + array_size - 1);
            for (int j = array_size - 1; j > 0; --j)
            {
                *(array + j) = *(array + j - 1);
            }
            *(array + 0) = temp;
        }
    }
    if(dir == ROTATE_LEFT)
    {
        for (int i = 0; i < positions_to_shift; i++)
        {
            int temp = *(array + 0);
            for (int j = 0; j < array_size - 1; j++)
            {
                *(array + j) = *(array + j + 1);
            }
            *(array + array_size - 1) = temp;
        }
    }

    return 0;
}
