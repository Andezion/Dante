#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"

int bubble_sort_asc(int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    if(size == 1)
    {
        printf("%i",tab[0]);
        return 0;
    }

    for(int i = 0; i < size; i++)
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

int bubble_sort_desc(int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    if(size == 1)
    {
        printf("%i",tab[0]);
        return 0;
    }

    for(int i = 0; i < size; i++)
    {
        int pointer = 0;
        for(int j = 0; j < size - 1; j++)
        {
            if(tab[j] < tab[j + 1])
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

int bubble_sort(int tab[], int size, enum direction1 dir)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    if(size > 50)
    {
        size = 50;
    }

    if(dir == ASCENDING)
    {
        bubble_sort_asc(tab,size);
        return 0;
    }
    if(dir == DESCENDING)
    {
        bubble_sort_desc(tab,size);
        return 0;
    }
    return 1;
}
