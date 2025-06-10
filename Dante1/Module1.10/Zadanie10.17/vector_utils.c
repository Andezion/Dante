#include "vector_utils.h"
#include <stdio.h>

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
