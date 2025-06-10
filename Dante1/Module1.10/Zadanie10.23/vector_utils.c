#include "vector_utils.h"
#include <stdio.h>

int product_left(const long long *input, int input_size, long long *output, int output_size)
{
    if(input == NULL || input_size <= 1 || output_size <= 1 || output == NULL || input_size != output_size)
    {
        return 1;
    }

    *(output + 0) = 1;
    for (int i = 1; i < input_size; i++)
    {
        *(output + i) = *(output + i - 1) * *(input + i - 1);
    }

    return 0;
}

int product_right(const long long *input, int input_size, long long *output, int output_size)
{
    if(input == NULL || input_size <= 1 || output_size <= 1 || output == NULL || input_size != output_size)
    {
        return 1;
    }

    *(output + input_size - 1) = 1;
    for (int i = input_size - 2; i >= 0; i--)
    {
        *(output + i) = *(output + i + 1) * *(input + i + 1);
    }

    return 0;
}

void display_vector_ll(const long long* tab, int size)
{
    if(tab == NULL || size < 0)
    {
        return;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%lli ",*(tab + i));
    }
}

int read_vector_ll(long long *vec, int size, int stop_value)
{
    if (size < 1 || vec == NULL || size > 100)
    {
        return -1;
    }

    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        int check = scanf("%lli", &*(vec + i));
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
