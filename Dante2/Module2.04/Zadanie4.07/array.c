#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int array_create(struct array_t *a, int N)
{
    if (a == NULL || N <= 0)
    {
        return 1;
    }

    a->ptr = malloc(sizeof(int) * N);
    if (a->ptr == NULL)
    {
        return 2;
    }
    a->capacity = N;
    a->size = 0;

    return 0;
}

int array_copy(const struct array_t *src, struct array_t *dest)
{
    if(src == NULL || dest == NULL || dest==src || src->ptr==NULL
       || src->size <= 0 || src->capacity <= 0)
    {
        return 1;
    }

    int popa = array_create(dest, src->size);
    if(popa == 1 || popa == 2)
    {
        return 2;
    }


    for (int i = 0; i < src->size; i++)
    {
        *(dest->ptr + i) = *(src->ptr + i);
    }

    dest->size = src->size;
    dest->capacity = src->capacity;

    return 0;
}

int array_separate(const struct array_t *a, struct array_t *odd, struct array_t *even)
{
    if (a == NULL || odd == NULL || even == NULL || a->ptr == NULL ||
        odd == even || odd == a || even == a ||
        a->size <= 0 || a->capacity <= 0 || a->size != a->capacity)
    {
        return -1;
    }

    int some_temporary = 0,
            storage = 0, control_point,
            some_shit_help_me, ex;

    for (int i = 0; i < a->size; i++)
    {
        if (*(a->ptr + i) % 2 == 0)
        {
            storage++;
        }
        else
        {
            some_temporary++;
        }
    }

    odd->size = some_temporary;
    even->size = storage;

    if (storage == 0 && some_temporary == 0)
    {
        return 1;
    }
    else if (some_temporary > 0 && storage == 0)
    {
        ex = array_copy(a, odd);
        if (ex == 0)
        {
            return 1;
        }
        return 0;
    }
    else if (some_temporary == 0 && storage > 0)
    {
        ex = array_copy(a, even);
        if (ex == 0)
        {
            return 2;
        }
        return 0;
    }
    else
    {
        odd->ptr = (int *) malloc(some_temporary * sizeof(int));
        if (odd->ptr == NULL)
        {
            return 0;
        }

        even->ptr = (int *) malloc(storage * sizeof(int));
        if (even->ptr == NULL)
        {
            free(odd->ptr);
            return 0;
        }

        control_point = 0;
        some_shit_help_me = 0;

        for (int i = 0; i < a->size; i++)
        {
            if (*(a->ptr + i) % 2 != 0)
            {
                *(odd->ptr + some_shit_help_me) = *(a->ptr + i);
                some_shit_help_me++;
            }
            else
            {
                *(even->ptr + control_point) = *(a->ptr + i);
                control_point++;
            }
        }

        odd->capacity = some_shit_help_me;
        even->capacity = control_point;

        if (control_point == 0 && some_shit_help_me > 0)
        {
            return 1;
        }
        if (control_point > 0 && some_shit_help_me == 0)
        {
            return 2;
        }
    }

    return 3;
}

int array_push_back(struct array_t *a, int value)
{
    if (a == NULL || a->ptr == NULL || a->size > a->capacity || a->capacity <= 0 || a->size < 0)
    {
        return 1;
    }

    if (a->size == a->capacity)
    {
        return 2;
    }

    *(a->ptr + a->size) = value;
    a->size++;

    return 0;
}

void array_display(const struct array_t *a)
{
    if (a == NULL || a->ptr == NULL || a->size > a->capacity || a->capacity <= 0 || a->size <= 0)
    {
        return;
    }

    for (int i = 0; i < a->size; i++)
    {
        printf("%i ", *(a->ptr + i));
    }
}

void array_destroy(struct array_t *a)
{
    if (a == NULL)
    {
        return;
    }

    free(a->ptr);
    a->ptr = NULL;
    a->size = 0;
    a->capacity = 0;
}
