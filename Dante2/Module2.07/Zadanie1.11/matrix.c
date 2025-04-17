#include "matrix.h"
#include <stdio.h>
#include <malloc.h>

void matrix_display(const struct matrix_t* m)
{
    if(m == NULL || m->height <= 0 || m->width <= 0 || m->data == NULL)
    {
        return;
    }

    for(int i = 0; i < m->height; i++)
    {
        for(int j = 0; j < m->width; j++)
        {
            printf("%.3f ",*(*(m->data + i) + j));
        }
        printf("\n");
    }
}

void matrix_free(struct matrix_t *m)
{
    if (m == NULL || m->width <= 0 || m->height <= 0 || m->data == NULL)
    {
        return;
    }

    for (int i = 0; i < m->height; i++)
    {
        free(*(m->data + i));
    }

    free(m->data);

    m->width = 0;
    m->height = 0;
    m->data = NULL;
}


struct matrix_t* matrix_create(int width, int height, int *err_code)
{
    if(width <= 0 || height <= 0)
    {
        if(err_code)
        {
            *err_code = 1;
        }
        return NULL;
    }

    struct matrix_t *m;

    m = malloc(sizeof(struct matrix_t));
    if (m == NULL)
    {
        if(err_code)
        {
            *err_code = 2;
        }
        return NULL;
    }

    m->data = malloc(sizeof(int *) * height);
    if(m->data == NULL)
    {
        if(err_code)
        {
            *err_code = 2;
        }

        free(m);
        return NULL;
    }

    for(int i = 0; i < height; i++)
    {
        *(m->data + i) = malloc(sizeof(int) * width);
        if(*(m->data + i) == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(*(m->data + j));
            }
            free(m->data);
            free(m);

            if(err_code)
            {
                *err_code = 2;
            }
            return NULL;
        }
    }

    m->width = width;
    m->height = height;

    if(err_code)
    {
        *err_code = 0;
    }
    return m;
}

struct matrix_t* matrix_add(struct matrix_t* m1, const struct matrix_t* m2)
{
    if(m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL ||
       m1->height <= 0 || m1->width <= 0 || m2->height <= 0 || m2->width <= 0 ||
       m1->width != m2->width || m1->height != m2->height)
    {
        return NULL;
    }

    for(int i = 0; i < m1->height; i++)
    {
        for(int j = 0; j < m1->width; j++)
        {
            *(*(m1->data + i) + j) = *(*(m1->data + i) + j) + *(*(m2->data + i) + j);
        }
    }

    return m1;
}

struct matrix_t* matrix_subtract(struct matrix_t* m1, const struct matrix_t* m2)
{
    if(m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL ||
       m1->height <= 0 || m1->width <= 0 || m2->height <= 0 || m2->width <= 0 ||
       m1->width != m2->width || m1->height != m2->height)
    {
        return NULL;
    }

    for(int i = 0; i < m1->height; i++)
    {
        for(int j = 0; j < m1->width; j++)
        {
            *(*(m1->data + i) + j) = *(*(m1->data + i) + j) - *(*(m2->data + i) + j);
        }
    }

    return m1;
}
