#include "statistics.h"
#include <stdlib.h>

int mode(int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return 0;
    }

    for (int i = 0; i < size - 1; i++)
    {
        int pointer = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                pointer = 1;
            }
        }
        if(pointer == 0)
        {
            break;
        }
    }

    int to_check = tab[0];
    int mode = to_check;

    int pointer = 1;
    int counter = 1;

    for (int i = 1; i < size; ++i)
    {
        if (tab[i] != to_check)
        {
            pointer = 1;
            to_check = tab[i];
        }
        else
        {
            ++pointer;
        }

        if (pointer > counter)
        {
            counter = pointer;
            mode = to_check;
        }
    }

    return mode;
}

float median(int tab[], int size)
{
    if (tab == NULL || size <= 0)
    {
        return 0;
    }

    for (int i = 0; i < size - 1; i++)
    {
        int pointer = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                pointer = 1;
            }
        }
        if(pointer == 0)
        {
            break;
        }
    }

    float result;
    if (size % 2 == 0)
    {
        result = (tab[size / 2 - 1] + tab[size / 2]) / 2.0;
    }
    else
    {
        result = (float)tab[size / 2];
    }

    return result;
}

float average(const int tab[], int size)
{
    if (tab == NULL || size <= 0)
    {
        return 0;
    }

    float sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum = sum + (float)tab[i];
    }

    return sum / (float)size;
}
