#include "comparators.h"
#include <stdlib.h>

int sort_rows(int **array, int height, int width, func types)
{
    if(array == NULL || height < 1 || width < 1 || types == NULL)
    {
        return 1;
    }

    for(int i = 0; i < width - 1; i++)
    {
        for(int j = 0; j < width - 1; j++)
        {
            int result = types(*(array + j), *(array + j + 1), height);
            if(result == 1)
            {
                int *temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }

    return 0;
}

int comp_min(const int *array1, const int *array2, int number)
{
    if(array1 == NULL || array2 == NULL || number < 1)
    {
        return 2;
    }

    int temp1 = 10000;
    int temp2 = 10000;

    for(int i = 0; i < number; i++)
    {
        if(*(array1 + i) < temp1)
        {
            temp1 = temp1 + *(array1 + i);
        }
        if(*(array2 + i) < temp2)
        {
            temp2 = temp2 + *(array2 + i);
        }
    }

    if(temp1 > temp2)
    {
        return 1;
    }
    if(temp1 == temp2)
    {
        return 0;
    }
    return -1;
}

int comp_max(const int *array1, const int *array2, int number)
{
    if(array1 == NULL || array2 == NULL || number < 1)
    {
        return 2;
    }

    int temp1 = -10000;
    int temp2 = -10000;

    for(int i = 0; i < number; i++)
    {
        if(*(array1 + i) > temp1)
        {
            temp1 = temp1 + *(array1 + i);
        }
        if(*(array2 + i) > temp2)
        {
            temp2 = temp2 + *(array2 + i);
        }
    }

    if(temp1 > temp2)
    {
        return 1;
    }
    if(temp1 == temp2)
    {
        return 0;
    }
    return -1;
}

int comp_sum(const int *array1, const int *array2, int number)
{
    if(array1 == NULL || array2 == NULL || number < 1)
    {
        return 2;
    }

    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < number; i++)
    {
        sum1 = sum1 + *(array1 + i);
        sum2 = sum2 + *(array2 + i);
    }

    if(sum1 > sum2)
    {
        return 1;
    }
    if(sum1 == sum2)
    {
        return 0;
    }
    return -1;
}

