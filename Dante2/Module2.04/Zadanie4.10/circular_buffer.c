#include "circular_buffer.h"
#include <stdio.h>
#include <stdlib.h>

int circular_buffer_create(struct circular_buffer_t *cb, int N)
{
    if (cb == NULL || N <= 0)
    {
        return 1;
    }

    cb->ptr = malloc(N * sizeof(int));
    if (cb->ptr == NULL)
    {
        return 2;
    }

    cb->begin = 0;
    cb->end = 0;
    cb->capacity = N;
    cb->full = 0;

    return 0;
}

int circular_buffer_create_struct(struct circular_buffer_t **cb, int N)
{
    if (cb == NULL || N <= 0)
    {
        return 1;
    }

    struct circular_buffer_t *check = malloc(sizeof(struct circular_buffer_t));
    if (check == NULL)
    {
        return 2;
    }

    int *check1 = malloc(N * sizeof(int));
    if (check1 == NULL)
    {
        free(check);
        return 2;
    }

    check->ptr = check1;
    check->begin = 0;
    check->end = 0;
    check->capacity = N;
    check->full = 0;
    *cb = check;

    return 0;
}

void circular_buffer_destroy(struct circular_buffer_t *cb)
{
    if (cb == NULL)
    {
        return;
    }

    free(cb->ptr);

    cb->ptr = NULL;
    cb->begin = 0;
    cb->end = 0;
    cb->capacity = 0;
    cb->full = 0;
}

void circular_buffer_destroy_struct(struct circular_buffer_t **cb)
{
    if (cb == NULL || *cb == NULL)
    {
        return;
    }

    circular_buffer_destroy(*cb);
    free(*cb);

    *cb = NULL;
}

int circular_buffer_push_back(struct circular_buffer_t *cb, int value)
{
    if(cb == NULL || cb->ptr == NULL)
    {
        return 1;
    }
    if(cb->begin < 0 || cb->end < 0)
    {
        return 1;
    }
    if (cb->capacity < 1 || cb->begin >= cb->capacity)
    {
        return 1;
    }
    if(cb->end >= cb->capacity || cb->full > 1)
    {
        return 1;
    }

    if (cb->full)
    {
        int number = (cb->begin + 1) % cb->capacity;
        cb->begin = number;
    }

    *(cb->ptr + cb->end) = value;

    cb->end = (cb->end + 1) % cb->capacity;
    if (cb->end == cb->begin)
    {
        cb->full = 1;
    }
    return 0;
}

int circular_buffer_pop_front(struct circular_buffer_t *cb, int *err_code)
{
    if(cb == NULL || cb->ptr == NULL || cb->begin < 0 || cb->end < 0)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 0;
    }
    if(cb->capacity < 1 || cb->begin >= cb->capacity)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 0;
    }
    if (cb->end >= cb->capacity || cb->full > 1)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 0;
    }

    if (cb->begin == cb->end && !cb->full)
    {
        if (err_code)
        {
            *err_code = 2;
        }
        return 0;
    }

    int value = *(cb->ptr + cb->begin);
    int number = (cb->begin + 1) % cb->capacity;

    cb->begin = number;
    cb->full = 0;

    if (err_code)
    {
        *err_code = 0;
    }

    return value;
}

int circular_buffer_pop_back(struct circular_buffer_t *cb, int *err_code)
{
    if(cb == NULL || cb->ptr == NULL || cb->begin < 0 || cb->end < 0)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 0;
    }
    if(cb->capacity < 1 || cb->begin >= cb->capacity)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 0;
    }
    if (cb->end >= cb->capacity || cb->full > 1)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 0;
    }

    if (cb->begin == cb->end && !cb->full)
    {
        if (err_code)
        {
            *err_code = 2;
        }
        return 0;
    }

    int number = (cb->end - 1 + cb->capacity) % cb->capacity;
    int index = number;

    int value = *(cb->ptr + index);
    cb->end = index;
    cb->full = 0;

    if (err_code)
    {
        *err_code = 0;
    }

    return value;
}

int circular_buffer_empty(const struct circular_buffer_t *cb)
{
    if(cb == NULL || cb->ptr == NULL || cb->begin < 0 || cb->end < 0)
    {
        return -1;
    }
    if(cb->end >= cb->capacity || cb->full > 1)
    {
        return -1;
    }
    if (cb->capacity < 1 || cb->begin >= cb->capacity)
    {
        return -1;
    }

    if (cb->begin == cb->end && cb->full == 0)
    {
        return 1;
    }

    return 0;
}

int circular_buffer_full(const struct circular_buffer_t *cb)
{
    if(cb == NULL || cb->ptr == NULL || cb->begin < 0 || cb->end < 0)
    {
        return -1;
    }
    if(cb->end >= cb->capacity || cb->full > 1)
    {
        return -1;
    }
    if (cb->capacity < 1 || cb->begin >= cb->capacity)
    {
        return -1;
    }

    if (cb->begin == cb->end && cb->full)
    {
        return 1;
    }

    return 0;
}

void circular_buffer_display(const struct circular_buffer_t *cb)
{
    if (cb == NULL || cb->ptr == NULL || cb->begin >= cb->capacity
        || cb->end >= cb->capacity || circular_buffer_empty(cb))
    {
        return;
    }
    if (cb->begin < cb->end)
    {
        for (int i = cb->begin; i < cb->end; ++i)
        {
            printf("%i ", *(cb->ptr + i));
        }
    }
    else
    {
        for (int i = cb->begin; i < cb->capacity; ++i)
        {
            printf("%i ", *(cb->ptr + i));
        }
        for (int i = 0; i < cb->end; ++i)
        {
            printf("%i ", *(cb->ptr + i));
        }

    }
}
