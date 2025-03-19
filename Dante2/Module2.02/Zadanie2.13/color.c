#include "color.h"
#include <stdio.h>
#include <math.h>

int load_colors_t(const char *filename, struct color_t* p, int N)
{
    if (!filename || !p || N <= 0)
    {
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return -2;
    }

    int count = 0, data_read = 0, errors_encountered = 0;
    struct color_t *p_current = p;

    while (count < N && !feof(file))
    {
        int temp_c;
        int scan_result = fscanf(file, "%f %f %f %d", &p_current->r, &p_current->g, &p_current->b, &temp_c);
        if (scan_result != 4)
        {
            errors_encountered = 1;
            fscanf(file, "%*[^\n]");
        }
        else
        {
            p_current->c = temp_c;
            data_read = 1;
            count++;
            p_current++;
        }
    }
    fclose(file);

    if(errors_encountered == 1)
    {
        return -3;
    }


    if (!data_read)
    {
        return -3;
    }

    return count;
}

float distance(const struct color_t* p1, const struct color_t* p2, int *err_code)
{
    if (!p1 || !p2)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return -1;
    }

    float dist = sqrtf(powf(p1->r - p2->r, 2) + powf(p1->g - p2->g, 2) + powf(p1->b - p2->b, 2));
    if (err_code)
    {
        *err_code = 0;
    }
    return dist;
}

enum colors find_nearest_neighbour(const struct color_t* database, int size, const struct color_t* unknown, int *err_code)
{
    if (!database || size <= 0 || !unknown)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return UNKNOWN;
    }

    float min_dist = 100000;
    int min_index = -1;
    int duplicate_min = 0;

    const struct color_t *p_current = database;
    for (int i = 0; i < size; i++, p_current++)
    {
        float dist = distance(unknown, p_current, NULL);
        if (dist >= min_dist)
        {
            if (dist == min_dist && p_current->c != (database + min_index)->c)
            {
                duplicate_min = 1;
            }
        }
        else
        {
            min_dist = dist;
            min_index = i;
            duplicate_min = 0;
        }
    }

    if (min_index == -1 || duplicate_min)
    {
        if (err_code)
        {
            *err_code = 2;
        }
        return UNKNOWN;
    }

    if (err_code)
    {
        *err_code = 0;
    }
    return (database + min_index)->c;
}
