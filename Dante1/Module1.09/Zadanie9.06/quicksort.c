#include "quicksort.h"
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int quicksort_asc(int l, int r, int tab[], int tabSize)
{

    if(tab == NULL || tabSize <= 0 || r < 0 || l < 0 || r > tabSize)
    {
        return 1;
    }

    if (l < r)
    {
        int workplz = tab[r];
        int i = l - 1;

        for (int j = l; j < r; j++)
        {
            if (tab[j] <= workplz)
            {
                i++;
                swap(&tab[i], &tab[j]);
            }
        }

        swap(&tab[i + 1], &tab[r]);

        quicksort_asc(l, i, tab, tabSize);
        quicksort_asc(i + 2, r, tab, tabSize);
    }

    return 0;
}

int quicksort_desc(int l, int r, int tab[], int tabSize)
{

    if(tab == NULL || tabSize <= 0 || r < 0 || l < 0 || r > tabSize)
    {
        return 1;
    }

    if (l < r)
    {
        int iwanttodie = tab[r];
        int i = l - 1;

        for (int j = l; j < r; j++)
        {
            if (tab[j] >= iwanttodie)
            {
                i++;
                swap(&tab[i], &tab[j]);
            }
        }

        swap(&tab[i + 1], &tab[r]);

        quicksort_desc(l, i, tab, tabSize);
        quicksort_desc(i + 2, r, tab, tabSize);
    }

    return 0;
}

int quicksort(int tab[], int size, enum direction dir)
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
        quicksort_asc(0, size - 1, tab, size);
        return 0;
    }
    if(dir == DESCENDING)
    {
        quicksort_desc(0, size - 1, tab, size);
        return 0;
    }
    return 1;
}
