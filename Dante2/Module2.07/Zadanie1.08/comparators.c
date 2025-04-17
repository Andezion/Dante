#include "comparators.h"
#include <stdlib.h>

int comp_int(const void *ptr1, const void *ptr2)
{
    if(ptr1 == NULL || ptr2 == NULL)
    {
        return 0;
    }

    int one = *(int *) ptr1;
    int two = *(int *) ptr2;

    if(one > two)
    {
        return 1;
    }
    if(one == two)
    {
        return 0;
    }

    return -1;
}

int comp_double(const void *ptr1, const void *ptr2)
{
    if(ptr1 == NULL || ptr2 == NULL)
    {
        return 0;
    }

    double one = *(double *) ptr1;
    double two = *(double *) ptr2;

    if(one > two)
    {
        return 1;
    }
    if(one == two)
    {
        return 0;
    }

    return -1;
}

int comp_point(const void *ptr1, const void *ptr2)
{
    if(ptr1 == NULL || ptr2 == NULL)
    {
        return 0;
    }

    struct point_t one = *(struct point_t *) ptr1;
    struct point_t two = *(struct point_t *) ptr2;

    if (one.x > two.x)
    {
        return 1;
    }
    else if (one.x < two.x)
    {
        return -1;
    }
    else
    {
        if (one.y > two.y)
        {
            return 1;
        }
        else if (one.y < two.y)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int sort(void *tab, int size, int type_of_element, func helper)
{
    if(type_of_element <= 0 || helper == NULL ||  tab == NULL || size <= 0)
    {
        return 1;
    }

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            unsigned char *temporary_value_one = (unsigned char*)(tab);
            temporary_value_one = temporary_value_one + (j * type_of_element);

            unsigned char *temporary_value_two = (unsigned char*)(tab);
            temporary_value_two = temporary_value_two + ((j + 1) * type_of_element);

            int errorchik = helper(temporary_value_one, temporary_value_two);
            if(errorchik > 0)
            {
                for(int k = 0; k < type_of_element; k++)
                {
                    unsigned char temp = *(temporary_value_one + k);
                    *(temporary_value_one + k) = *(temporary_value_two + k);
                    *(temporary_value_two + k) = temp;
                }
            }
        }
    }

    return 0;
}
