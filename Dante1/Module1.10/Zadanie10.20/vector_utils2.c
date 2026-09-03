#include "vector_utils.h"

int read_vector(int *tab, int size, int stop_value)
{
    if (size < 1 || tab == NULL || size > 100)
    {
        return -1;
    }

    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        int check = scanf("%i", tab + i);
        if (check != 1)
        {
            return -2;
        }
        if (*(tab + i) == stop_value)
        {
            break;
        }
        counter++;
    }

    return counter;
}

int find(const int *tab, int size, int to_find)
{
    static const int *saved_tab = NULL;
    static int saved_size = 0;
    static int current_index = 0;

    if (tab != NULL)
    {
        if (size < 1)
        {
            return -2;
        }

        saved_tab = tab;
        saved_size = size;
        current_index = 0;
    }
    else
    {
        if (saved_tab == NULL)
        {
            return -2;
        }
    }

    const int *pointer = saved_tab + current_index;

    while (current_index < saved_size)
    {
        if (*pointer == to_find)
        {
            int found_index = current_index;

            current_index++;
            pointer++;

            return found_index;
        }

        current_index++;
        pointer++;
    }

    return -1;
}
