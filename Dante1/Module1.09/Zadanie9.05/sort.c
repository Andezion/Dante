#include <stdio.h>
#include "types_utils.h"
#include "vector_utils.h"
#include "sort.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort(int tab[], int size, enum direction dir, enum algorithm alg)
{
    if(tab == NULL || size <= 0 || (dir != 1 && dir != 2))
    {
        return 1;
    }

    if(alg == BUBBLE_SORT)
    {
        bubble_sort(tab,size,dir);
        return 0;
    }
    else if(alg == SELECTION_SORT)
    {
        selection_sort(tab,size,dir);
        return 0;
    }
    else if(alg == INSERTION_SORT)
    {
        insertion_sort(tab,size,dir);
        return 0;
    }
    else
    {
        return 1;
    }
}

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


int selection_sort(int tab[], int size, enum direction dir)
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

int bubble_sort(int tab[], int size, enum direction dir)
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


int insertion_sort(int tab[], int size, enum direction dir)
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
