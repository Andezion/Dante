#include <stdlib.h>
#include <stdio.h>
#include "matrix_utils.h"

struct matrix_t* matrix_transpose(const struct matrix_t *m)
{
    if(m == NULL || m->ptr == NULL || m->height <= 0 || m->width <= 0)
    {
        return NULL;
    }

    struct matrix_t *tm;

    tm = malloc(sizeof(struct matrix_t));
    if(tm == NULL)
    {
        return NULL;
    }

    int error = matrix_create(tm, m->height, m->width);
    if(error == 2)
    {
        free(tm);
        return NULL;
    }

    for(int i = 0; i < m->height; i++)
    {
        for(int j = 0; j < m->width; j++)
        {
            *(*(tm->ptr + j) + i) = *(*(m->ptr + i) + j);
        }
    }

    return tm;
}

int matrix_save_b(const struct matrix_t *m, const char *filename)
{
    if(filename == NULL || m == NULL || m->ptr == NULL || m->height <= 0 || m->width <= 0)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "wb");
    if(!file)
    {
        return 2;
    }

    size_t error;

    error = fwrite(&m->width, sizeof(int), 1, file);
    if(error != 1)
    {
        fclose(file);
        return 3;
    }
    error = fwrite(&m->height, sizeof(int), 1, file);
    if(error != 1)
    {
        fclose(file);
        return 3;
    }

    for(int i = 0; i < m->height; i++)
    {
        error = fwrite(*(m->ptr + i), sizeof(int), m->width, file);
        if((int)error != m->width)
        {
            fclose(file);
            return 3;
        }
    }

    fclose(file);
    return 0;
}

int matrix_save_t(const struct matrix_t *m, const char *filename)
{
    if(filename == NULL || m == NULL || m->ptr == NULL || m->height <= 0 || m->width <= 0)
    {
        return 1;
    }

    int error;

    FILE *file;
    file = fopen(filename, "wt");
    if(!file)
    {
        return 2;
    }

    error = fprintf(file, "%i %i\n",m->width, m->height);
    if(error < 0)
    {
        fclose(file);
        return 3;
    }

    for(int i = 0; i < m->height; i++)
    {
        for(int j = 0; j < m->width; j++)
        {
            int temporary = *(*(m->ptr + i) + j);

            char type;
            if(j == m->width - 1)
            {
                type = '\n';
            }
            else
            {
                type = ' ';
            }

            error = fprintf(file,"%i%c",temporary, type);
            if(error < 0)
            {
                fclose(file);
                return 3;
            }
        }
    }

    fclose(file);
    return 0;
}

void matrix_destroy_struct(struct matrix_t **m)
{
    if(m == NULL)
    {
        return;
    }

    matrix_destroy(*m);
    free(*m);

    *m = NULL;
}

struct matrix_t *matrix_create_struct(int width, int height)
{
    if (width <= 0 || height <= 0)
    {
        return NULL;
    }

    struct matrix_t *m;

    m = malloc(sizeof(struct matrix_t));
    if (m == NULL)
    {
        return NULL;
    }

    int error = matrix_create(m, width, height);
    if(error != 0)
    {
        free(m);
        return NULL;
    }

    return m;
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
    if(m == NULL || m->height <= 0)
    {
        return;
    }

    for(int i = 0; i < m->height; i++)
    {
        free(*(m->ptr + i));
    }
    m->height = 0;
    m->width = 0;

    free(m->ptr);
    m->ptr = NULL;
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
