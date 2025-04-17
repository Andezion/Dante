#include "comparators.h"
#include <stdlib.h>

int sort_int(int *array, int size, int (*func)(int, int))
{
    if(array == NULL || size < 1 || func == NULL)
    {
        return 1;
    }

    for(int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if ((func(*(array + j - 1), *(array + j))) == 123)
            {
                int shit = *(array + j);
                *(array + j) = *(array + j - 1);
                *(array + j - 1) = shit;
            }
        }
    }

    return 0;
}

int comp_int(int a, int b)
{
    if(a > b)
    {
        return 123;
    }
    else if(a < b)
    {
        return -123;
    }
    else
    {
        return 0;
    }
}

int comp_int_abs(int a, int b)
{
    if(abs(a) > abs(b))
    {
        return 123;
    }
    else if(abs(a) < abs(b))
    {
        return -123;
    }
    else
    {
        return 0;
    }
}

int comp_int_length(int a, int b)
{
    int size1 = 0;
    while(a != 0)
    {
        size1++;
        a = a / 10;
    }

    int size2 = 0;
    while(b != 0)
    {
        size2++;
        b = b / 10;
    }

    if(size1 > size2)
    {
        return 123;
    }
    else if(size1 < size2)
    {
        return -123;
    }
    else
    {
        return 0;
    }
}

int comp_int_digits_sum(int a, int b)
{
    int num1 = 0;
    int temp1 = abs(a);
    while (temp1 != 0)
    {
        num1 = num1 + temp1 % 10;
        temp1 = temp1 / 10;
    }

    int num2 = 0;
    int temp2 = abs(b);
    while (temp2 != 0)
    {
        num2 = num2 + temp2 % 10;
        temp2 = temp2 / 10;
    }

    if(num1 > num2)
    {
        return 123;
    }
    else if(num2 > num1)
    {
        return -123;
    }
    else
    {
        return 0;
    }
}
