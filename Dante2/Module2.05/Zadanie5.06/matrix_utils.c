#include <stdlib.h>
#include <stdio.h>
#include "matrix_utils.h"

struct matrix_t* matrix_create_struct(int width, int height)
{
    if(width <= 0 || height <= 0)
    {
        return NULL;
    }

    struct matrix_t *arr = malloc(sizeof(struct matrix_t));
    if(arr == NULL)
    {
        return NULL;
    }

    int error = matrix_create(arr, width, height);
    if(error != 0)
    {
        free(arr);
        return NULL;
    }

    return arr;
}

void matrix_destroy_struct(struct matrix_t **m)
{
    if(m == NULL || *m == NULL || (*m)->height <= 0 || (*m)->ptr == NULL)
    {
        return;
    }

    matrix_destroy(*m);
    free(*m);
    *m = NULL;
}

struct matrix_t* matrix_copy(const struct matrix_t *copy)
{
    if(copy == NULL || copy->ptr == NULL || copy->height <= 0 || copy->width <= 0)
    {
        return NULL;
    }

    struct matrix_t *orig = malloc(sizeof(struct matrix_t));
    if(orig == NULL)
    {
        return NULL;
    }

    orig->width = copy->width;
    orig->height = copy->height;

    orig->ptr = malloc(sizeof(int *) * orig->height);
    if(orig->ptr == NULL)
    {
        free(orig);
        return NULL;
    }

    for(int i = 0; i < orig->height; i++)
    {
        *(orig->ptr + i) = malloc(sizeof(int) * orig->width);
        if (*(orig->ptr + i) == NULL)
        {
            for (int x = 0; x < i; x++)
            {
                free(*(orig->ptr + x));
            }
            free(orig->ptr);
            free(orig);

            return NULL;
        }
        for (int j = 0; j < orig->width; j++)
        {
            *(*(orig->ptr + i) + j) = *(*(copy->ptr + i) + j);
        }
    }

    return orig;
}

struct matrix_t* matrix_load_b(const char *filename, int *err_code)
{
    if(!filename)
    {
        if(err_code)
        {
            *err_code = 1;
        }
        return NULL;
    }

    FILE *file;
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        if(err_code)
        {
            *err_code = 2;
        }
        return NULL;
    }

    int width, height;
    size_t error1 = fread(&width, sizeof(int), 1, file);
    size_t error2 = fread(&height, sizeof(int), 1, file);
    if (error1 != 1 || error2 != 1 || width <= 0 || height <= 0)
    {
        if(err_code)
        {
            *err_code = 3;
        }
        fclose(file);

        return NULL;
    }

    struct matrix_t *temp  = malloc(sizeof(struct matrix_t));
    if (temp == NULL)
    {
        if(err_code)
        {
            *err_code = 4;
        }
        fclose(file);

        return NULL;
    }

    temp->width = width;
    temp->height = height;

    temp->ptr = malloc(sizeof(int *) * temp->height);
    if (temp->ptr == NULL)
    {
        if(err_code)
        {
            *err_code = 4;
        }
        fclose(file);
        free(temp);

        return NULL;
    }


    for (int i = 0; i < temp->height; i++)
    {
        *(temp->ptr + i) = malloc(sizeof(int) * temp->width);
        if (*(temp->ptr + i) == NULL)
        {
            if(err_code)
            {
                *err_code = 4;
            }
            fclose(file);

            for (int j = 0; j < i; j++)
            {
                free(*(temp->ptr + j));
            }
            free(temp->ptr);
            free(temp);

            return NULL;
        }
        if ((int)fread(*(temp->ptr + i), sizeof(int), temp->width, file) != temp->width)
        {
            if(err_code)
            {
                *err_code = 3;
            }
            fclose(file);

            for (int j = 0; j <= i; j++)
            {
                free(*(temp->ptr + j));
            }
            free(temp->ptr);
            free(temp);

            return NULL;
        }
    }

    fclose(file);
    if(err_code)
    {
        *err_code = 0;
    }
    return temp;
}

struct matrix_t* matrix_load_t(const char *filename, int *err_code)
{
    if(filename == NULL)
    {
        if(err_code)
        {
            *err_code = 1;
        }
        return NULL;
    }

    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL)
    {
        if(err_code)
        {
            *err_code = 2;
        }
        return NULL;
    }

    int width, height;
    int error = fscanf(file, "%i %i",&width, &height);
    if(error != 2 || width <= 0 || height <= 0)
    {
        if(err_code)
        {
            *err_code = 3;
        }
        fclose(file);
        return NULL;
    }

    struct matrix_t *temp = malloc(sizeof(struct matrix_t));
    if (temp == NULL)
    {
        if(err_code)
        {
            *err_code = 4;
        }
        fclose(file);
        return NULL;
    }

    temp->width = width;
    temp->height = height;

    temp->ptr = malloc(sizeof(int *) * temp->height);
    if (temp->ptr == NULL)
    {
        if(err_code)
        {
            *err_code = 4;
        }
        fclose(file);
        free(temp);
        return NULL;
    }

    for (int i = 0; i < temp->height; i++)
    {
        *(temp->ptr + i) = malloc(sizeof(int) * temp->width);
        if (*(temp->ptr + i) == NULL)
        {
            if(err_code)
            {
                *err_code = 4;
            }
            fclose(file);

            for (int j = 0; j < i; j++)
            {
                free(*(temp->ptr + j));
            }
            free(temp->ptr);
            free(temp);

            return NULL;
        }
        for (int j = 0; j < temp->width; j++)
        {
            int check = fscanf(file, "%d", (*(temp->ptr + i) + j));
            if (check != 1)
            {
                if(err_code)
                {
                    *err_code = 3;
                }
                fclose(file);

                for (int x = 0; x <= i; x++)
                {
                    free(*(temp->ptr + x));
                }
                free(temp->ptr);
                free(temp);

                return NULL;
            }
        }
    }

    fclose(file);
    if(err_code)
    {
        *err_code = 0;
    }
    return temp;
}

struct matrix_t* matrix_add(const struct matrix_t *m1, const struct matrix_t *m2)
{
    if(m1 == NULL || m2 == NULL || m1->ptr == NULL || m2->ptr == NULL ||
    m1->height <= 0 || m1->width <= 0 || m2->height <= 0 || m2->width <= 0 ||
    m1->width != m2->width || m1->height != m2->height)
    {
        return NULL;
    }

    struct matrix_t *result = matrix_create_struct(m1->width, m1->height);
    if(result == NULL)
    {
        return NULL;
    }

    for(int i = 0; i < result->height; i++)
    {
        for(int j = 0; j < result->width; j++)
        {
            *(*(result->ptr + i) + j) = *(*(m1->ptr + i) + j) + *(*(m2->ptr + i) + j);
        }
    }

    return result;
}

struct matrix_t* matrix_subtract(const struct matrix_t *m1, const struct matrix_t *m2)
{
    if(m1 == NULL || m2 == NULL || m1->ptr == NULL || m2->ptr == NULL ||
       m1->height <= 0 || m1->width <= 0 || m2->height <= 0 || m2->width <= 0 ||
       m1->width != m2->width || m1->height != m2->height)
    {
        return NULL;
    }

    struct matrix_t *result = matrix_create_struct(m1->width, m1->height);
    if(result == NULL)
    {
        return NULL;
    }

    for(int i = 0; i < result->height; i++)
    {
        for(int j = 0; j < result->width; j++)
        {
            *(*(result->ptr + i) + j) = *(*(m1->ptr + i) + j) - *(*(m2->ptr + i) + j);
        }
    }

    return result;
}

struct matrix_t* matrix_multiply(const struct matrix_t *m1, const struct matrix_t *m2)
{
    if(!m1 || !m2 || !m1->ptr || !m2->ptr || m1->height <= 0 || m2->height <= 0
    || m1->width <= 0 || m2->width <= 0 || m1->width != m2->height)
    {
        return NULL;
    }

    struct matrix_t* result = malloc(sizeof(struct matrix_t));
    if (result == NULL)
    {
        return NULL;
    }

    result->width = m2->width;
    result->height = m1->height;

    result->ptr = malloc(sizeof(int *) * result->height);
    if (result->ptr == NULL)
    {
        free(result);
        return NULL;
    }

    for (int i = 0; i < result->height; i++)
    {
        *(result->ptr + i) = malloc(sizeof(int) * result->width);
        if (*(result->ptr + i) == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(*(result->ptr + j));
            }
            free(result->ptr);
            free(result);
            return NULL;
        }
    }

    for (int i = 0; i < result->height; i++)
    {
        for (int j = 0; j < result->width; j++)
        {
            *(*(result->ptr + i) + j) = 0;

            for (int x = 0; x < m1->width; x++)
            {
                *(*(result->ptr + i) + j) += *(*(m1->ptr + i) + x) * *(*(m2->ptr + x) + j);
            }
        }
    }

    return result;
}

int matrix_read(struct matrix_t *m)
{
    if(m == NULL || m->ptr == NULL || m->height <= 0 || m->width <= 0)
    {
        return 1;
    }

    int error;

    for(int i = 0; i < m->height; i++)
    {
        for(int j = 0; j < m->width; j++)
        {
            error = scanf("%i",(*(m->ptr + i) + j));
            if(!error)
            {
                matrix_destroy(m);
                return 2;
            }
        }
    }

    return 0;
}

void matrix_display(const struct matrix_t *m)
{
    if(m == NULL || m->height <= 0 || m->width <= 0 || m->ptr == NULL)
    {
        return;
    }

    for (int i = 0; i < m->height; i++)
    {
        for (int j = 0; j < m->width; j++)
        {
            printf("%i ", *(*(m->ptr + i) + j));
        }
        printf("\n");
    }
}

void matrix_destroy(struct matrix_t *m)
{
    if(m == NULL || m->height <= 0 || m->width <= 0 || m->ptr == NULL)
    {
        return;
    }

    for(int i = 0; i < m->height; i++)
    {
        free(*(m->ptr + i));
    }
    free(m->ptr);
    m->ptr = NULL;

    m->height = 0;
    m->width = 0;
}

int matrix_create(struct matrix_t *m, int width, int height)
{
    if(m == NULL || width <= 0 || height <= 0)
    {
        return 1;
    }

    m->ptr = malloc(sizeof(int *) * height);
    if(m->ptr == NULL)
    {
        return 2;
    }

    for(int i = 0; i < height; i++)
    {
        *(m->ptr + i) = malloc(sizeof(int) * width);
        if(*(m->ptr + i) == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(*(m->ptr + j));
            }
            free(m->ptr);
            return 2;
        }
    }

    m->width = width;
    m->height = height;

    return 0;
}
