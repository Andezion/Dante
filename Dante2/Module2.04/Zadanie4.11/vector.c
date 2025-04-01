#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int vector_create_struct(struct vector_t **a, int N)
{
    if(a == NULL || N <= 0)
    {
        return 1;
    }

    struct vector_t *b = malloc(sizeof(struct vector_t));
    if(b == NULL)
    {
        return 2;
    }

    /*b->ptr = malloc(sizeof(int) * N);
    if(b->ptr == NULL)
    {
        free(b);
        return 2;
    }*/

    int error = vector_create(b, N);
    if(error == 2)
    {
        free(b);
        return 2;
    }

    *a = b;

    return 0;
}

void vector_destroy_struct(struct vector_t **a)
{
    if(a == NULL || *a == NULL)
    {
        return;
    }

    vector_destroy(*a);
    free(*a);
}

int vector_create(struct vector_t *a, int N)
{
    if(a == NULL || N <= 0)
    {
        return 1;
    }

    a->ptr = malloc(sizeof(int) * N);
    if(a->ptr == NULL)
    {
        return 2;
    }

    a->size = 0;
    a->capacity = N;

    return 0;
}

void vector_destroy(struct vector_t *a)
{
    if(a == NULL)
    {
        return;
    }

    free(a->ptr);
}

void vector_display(const struct vector_t *a)
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

int vector_push_back(struct vector_t *a, int value)
{
    if (a == NULL || a->ptr == NULL || a->size < 0 || a->capacity < 1 || a->size > a->capacity)
    {
        return 1;
    }

    if (a->size == a->capacity)
    {
        int number = a->capacity * 2;

        int *temp = realloc(a->ptr, number * sizeof(int));
        if (temp == NULL)
        {
            return 2;
        }

        a->capacity = number;
        a->ptr = temp;
    }

    *(a->ptr + a->size) = value;
    a->size++;

    return 0;
}

int vector_erase(struct vector_t *a, int value)
{
    if (a == NULL || a->ptr == NULL || a->size < 0 || a->capacity < 1 || a->size > a->capacity)
    {
        return -1;
    }

    int counter = 0;
    int number = 0;
    for (int i = 0; i < a->size; i++)
    {
        if (*(a->ptr + i) == value)
        {
            counter++;
        }
        else
        {
            *(a->ptr + number) = *(a->ptr + i);
            number++;
        }
    }

    int temp = a->capacity / 4;
    if (number <= temp && temp * 2 >= 1)
    {
        int *data = realloc(a->ptr, (temp * 2) * sizeof(int));
        if (data == NULL)
        {
            return -1;
        }

        a->ptr = data;
        a->capacity = a->capacity / 2;
    }

    a->size = number;
    return counter;
}
