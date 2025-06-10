#include <stdio.h>
#include "functions.h"

int all_even(int number)
{
    int temp = number % 10;
    if(temp % 2 == 0)
    {
        return all_even(number / 10);
    }
    return 0;
}

int all_odd(int number)
{
    int temp = number % 10;
    if(temp % 2 == 1)
    {
        return all_odd(number / 10);
    }
    return 0;
}

int omggg_workPLZZZ(const int *tab, int size, enum type t, int index)
{
    if (index >= size)
    {
        return -1;
    }

    switch (t)
    {
        case ALL_ODD:
            if (all_odd(*(tab + index)))
            {
                return *(tab + index);
            }
            break;
        case ALL_EVEN:
            if (all_even(*(tab + index)))
            {
                return *(tab + index);
            }
            break;
        case MIX:
            return *(tab + index);
    }

    return omggg_workPLZZZ(tab, size, t, index + 1);
}


int get_next_number(const int *tab, int size, enum type t)
{
    if (tab == NULL || size <= 0)
    {
        return -2;
    }

    return omggg_workPLZZZ(tab, size, t, 0);
}
