#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "array.h"

float angle_between_vectors(const struct array_t *a, const struct array_t *b)
{
    if(a == NULL || a->ptr == NULL || a->size > a->capacity || a->capacity <= 0 || a->size <= 0
       || b == NULL || b->ptr == NULL || b->size > b->capacity || b->capacity <= 0 || b->size <= 0
       || a->size != b->size)
    {
        return -1.0f;
    }

    float result;
    result = length(a) * length(b);
    if(!result)
    {
        return -1;
    }

    result = dot_product(a, b) / result;
    result = acosf(result);
    result = result * 180 / (2 * asinf(1));

    return result;
}

int normalize_vector(const struct array_t *a, struct array_t **b)
{
    if( a == NULL || a->ptr == NULL || b == NULL || a->size <= 0 || a->size > a->capacity)
    {
        return 1;
    }

    float temp = length(a);
    if(temp == 0)
    {
        return 3;
    }

    int error = array_create_struct_float(b, a->size);
    if(error != 0)
    {
        return 2;
    }

    for(int i = 0; i < a->size; i++)
    {
        array_push_back_float(*b, *(a->ptr + i) / temp);
    }

    return 0;
}

float dot_product(const struct array_t *a, const struct array_t *b)
{
    if (!a || !b || a->size > a->capacity || b->size > b->capacity ||
        a->size != b->size || !a->ptr || !b->ptr || a->size < 1 || b->size < 1)
    {
        return -1;
    }

    double result = 0;
    for (int i = 0; i < a->size; i++)
    {
        result = result + (double)*(a->ptr + i) * *(b->ptr + i);
    }
    return (float)result;
}

float length(const struct array_t *a)
{
    if(a == NULL || a->ptr == NULL || a->size < 1 || a->size > a->capacity)
    {
        return -1.0f;
    }

    double result = 0;
    for (int i = 0; i < a->size; i++)
    {
        result = result + (double)*(a->ptr + i) * *(a->ptr + i);
    }
    return (float)sqrt(result);
}

int subtract_vectors(const struct array_t *a, const struct array_t *b, struct array_t **c)
{
    if(a == NULL || a->ptr == NULL || a->size > a->capacity || a->capacity <= 0 || a->size <= 0
       || b == NULL || b->ptr == NULL || b->size > b->capacity || b->capacity <= 0 || b->size <= 0
       || a->size != b->size || c == NULL)
    {
        return 1;
    }

    int error = array_create_struct_float(c, a->size);
    if(error != 0)
    {
        return 2;
    }

    for(int i = 0; i < a->size; i++)
    {
        array_push_back_float(*c, *(a->ptr + i) - *(b->ptr + i));
    }

    return 0;
}

int add_vectors(const struct array_t *a, const struct array_t *b, struct array_t **c)
{
    if(a == NULL || a->ptr == NULL || a->size > a->capacity || a->capacity <= 0 || a->size <= 0
       || b == NULL || b->ptr == NULL || b->size > b->capacity || b->capacity <= 0 || b->size <= 0
       || a->size != b->size || c == NULL)
    {
        return 1;
    }

    int error = array_create_struct_float(c, a->size);
    if(error != 0)
    {
        return 2;
    }

    for(int i = 0; i < a->size; i++)
    {
        array_push_back_float(*c, *(a->ptr + i) + *(b->ptr + i));
    }

    return 0;
}

int array_create_struct_float(struct array_t **a, int N)
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

    int error = array_create_float(array_p, N);
    if (error != 0)
    {
        free(array_p);
        return error;
    }

    *a = array_p;
    return 0;
}

void array_destroy_struct_float(struct array_t **a)
{
    if(a == NULL || *a == NULL)
    {
        return;
    }

    array_destroy_float(*a);
    free(*a);
}

void array_destroy_float(struct array_t *a)
{
    if(a == NULL)
    {
        return;
    }

    free(a->ptr);
    a->ptr = NULL;
    a->size = 0;
    a->capacity = 0;
}

void array_display_float(const struct array_t *a)
{
    if(a == NULL || a->ptr == NULL || a->size > a->capacity ||
       a->capacity <= 0 || a->size <= 0)
    {
        return;
    }

    for(int i = 0; i < a->size; i++)
    {
        printf("%.2f ",*(a->ptr + i));
    }
    printf("\n");
}

int array_create_float(struct array_t *a, int N)
{
    if(a == NULL || N <= 0)
    {
        return 1;
    }

    a->ptr = malloc(sizeof(float) * N);
    if(!a->ptr)
    {
        return 2;
    }
    a->capacity = N;
    a->size = 0;

    return 0;
}

int array_push_back_float(struct array_t *a, float value)
{
    if(a == NULL || a->ptr == NULL || a->size > a->capacity ||
       a->capacity <= 0 || a->size < 0)
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
