#include "functions.h"

int all_even_helper(int number)
{
    if (number == 0) return 1;

    if (number % 10 % 2 == 0)
    {
        return all_even_helper(number / 10);
    }
    return 0;
}

int all_even(int number)
{
    if (number == 0) return 1;

    if (number < 0) number = -number;

    return all_even_helper(number);
}

int all_odd_helper(int number)
{
    if (number == 0) return 1;

    if (number % 10 % 2 == 1)
    {
        return all_odd_helper(number / 10);
    }
    return 0;
}

int all_odd(int number)
{
    if (number == 0) return 0;

    if (number < 0) number = -number;

    return all_odd_helper(number);
}

int helper(const int *tab, int size, enum type t, int *index)
{
    if (*index >= size)
    {
        return -1;
    }

    int current_val = *(tab + *index);

    int correct = 0;

    switch (t)
    {
        case ALL_ODD:
            correct = all_odd(current_val);
        break;

        case ALL_EVEN:
            correct = all_even(current_val);
        break;

        case MIX:
            correct = !all_odd(current_val) &&
                      !all_even(current_val);
        break;

        default:
            return -2;
    }

    if (correct)
    {
        (*index)++;
        return current_val;
    }

    (*index)++;

    return helper(tab, size, t, index);
}


int get_next_number(const int *tab, int size, enum type t)
{
    static const int *saved_tab = NULL;
    static int saved_size = 0;
    static int current_index = 0;

    if (tab != NULL)
    {
        if (size <= 0)
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

    return helper(saved_tab, saved_size, t, &current_index);
}
