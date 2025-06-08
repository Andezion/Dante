#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"

int insertion_sort_asc(int tab[], int size)
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

    for (int i = 1; i < size; i++)
    {
        int temp = tab[i];
        int j;

        for (j = i - 1; j >= 0 && temp < tab[j]; j--)
        {
            tab[j + 1] = tab[j];
        }

        tab[j + 1] = temp;
        display_vector(tab, size);
    }
    display_vector(tab, size);

    return 0;
}

int insertion_sort_desc(int tab[], int size)
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

    for (int i = 1; i < size; i++)
    {
        int temp = tab[i];
        int j = i;

        while (j > 0 && temp > tab[j - 1])
        {
            tab[j] = tab[j - 1];
            j--;
        }

        tab[j] = temp;
        display_vector(tab, size);
    }
    display_vector(tab, size);

    return 0;
}


int insertion_sort(int tab[], int size, enum direction1 dir)
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
        insertion_sort_asc(tab,size);
        return 0;
    }
    if(dir == DESCENDING)
    {
        insertion_sort_desc(tab,size);
        return 0;
    }
    return 1;
}
