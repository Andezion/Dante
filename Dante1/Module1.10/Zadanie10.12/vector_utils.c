#include "vector_utils.h"
#include <stdio.h>

int create_histogram(const float *vec, int size, int *out, int out_size)
{
    if(vec == NULL || size <= 0 || out == NULL || out_size <= 0)
    {
        return 1;
    }

    for(int i = 0; i < out_size; i++)
    {
        *(out + i) = 0;
    }

    for(int i = 0; i < out_size; i++)
    {
        int counter = 0;
        for(int j = 0; j < size; j++)
        {
            if((float)i <= *(vec + j) && *(vec + j) < (float)(i + 1))
            {
                counter++;
            }
        }
        *(out + i) = counter;
    }

    return 0;
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

int read_vector_float(float *vec, int size, float stop_value)
{
    if (size < 1 || vec == NULL || size > 100)
    {
        return -1;
    }

    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        int check = scanf("%f", &*(vec + i));
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
