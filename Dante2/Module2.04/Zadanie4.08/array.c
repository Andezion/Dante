#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int array_create(struct array_t *a, int N)
{
    if(a == NULL || N <= 0)
    {
        return 1;
    }

    a->ptr = malloc(sizeof(int) * N);
    if(!a->ptr)
    {
        return 2;
    }
    a->capacity = N;
    a->size = 0;

    return 0;
}

int array_push_back(struct array_t *a, int value)
{
    if(a == NULL || a->ptr == NULL || a->size > a->capacity || a->capacity <= 0 || a->size < 0)
    {
        return 1;
    }

    if(a->size == a->capacity)
    {
        return 2;
    }

    *(a->ptr + a->size) = value;
    a->size++;

    return 0;
}

void array_display(const struct array_t *a)
{
    if(a == NULL || a->ptr == NULL || a->size > a->capacity || a->capacity <= 0 || a->size <= 0)
    {
        return;
    }

    for(int i = 0; i < a->size; i++)
    {
        printf("%i ",*(a->ptr + i));
    }
}

void array_destroy(struct array_t *a)
{
    if(a == NULL)
    {
        return;
    }

    free(a->ptr);
}

int array_create_struct(struct array_t **a, int N)
{
    if (a == NULL || N <= 0)
    {
        return 1;
    }

    struct array_t *array_p = malloc(sizeof(struct array_t));
    if (array_p == NULL)
    {
        return 2;
    }

    int error = array_create(array_p, N);
    if (error != 0)
    {
        free(array_p);
        return error;
    }

    *a = array_p;
    return 0;
}

void array_destroy_struct(struct array_t **a)
{
    if(a == NULL || *a == NULL)
    {
        return;
    }

    array_destroy(*a);
    free(*a);
}

int array_remove_item(struct array_t *a, int value)
{
    if(a == NULL || a->ptr == NULL || a->size > a->capacity || a->capacity <= 0 || a->size < 0)
    {
        return -1;
    }

    int counter = 0;

    for(int i = a->size - 1; i > -1; i--)
    {
        if(*(a->ptr + i) == value)
        {
            for(int j = i; j < a->size - 1; j++)
            {
                *(a->ptr + j) = *(a->ptr + j + 1);
            }
            counter++;
            a->size--;
        }
    }

    return counter;
}
