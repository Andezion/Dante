#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"

int selection_sort_asc(int tab[], int size)
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

    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (tab[j] < tab[index])
            {
                index = j;
            }
        }

        int temp = tab[index];
        tab[index] = tab[i];
        tab[i] = temp;

        display_vector(tab, size);
    }
    return 0;
}


int selection_sort_desc(int tab[], int size)
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

    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (tab[j] > tab[index])
            {
                index = j;
            }
        }

        int temp = tab[index];
        tab[index] = tab[i];
        tab[i] = temp;

        display_vector(tab, size);
    }
    return 0;
}


int selection_sort(int tab[], int size, enum direction1 dir)
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
        selection_sort_asc(tab,size);
        return 0;
    }
    if(dir == DESCENDING)
    {
        selection_sort_desc(tab,size);
        return 0;
    }
    return 1;
}

