#include <stdio.h>
#include <stdlib.h>

struct matrix_t
{
    int **ptr;
    int width;
    int height;
};

int matrix_create(struct matrix_t *m, int width, int height);
int matrix_read(struct matrix_t *m);
void matrix_display(const struct matrix_t *m);
void matrix_destroy(struct matrix_t *m);

int main()
{
    int error;
    int width, height;

    printf("Enter: ");
    error = scanf("%i %i",&width, &height);
    if(error != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(width <= 0 || height <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    struct matrix_t m;
    error = matrix_create(&m, width, height);
    if(error == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    if(error == 1)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Enter:\n");
    error = matrix_read(&m);
    if(error == 1)
    {
        printf("Incorrect input data");
        matrix_destroy(&m);
        return 2;
    }
    if(error == 2)
    {
        printf("Incorrect input");
        matrix_destroy(&m);
        return 1;
    }

    matrix_display(&m);
    matrix_destroy(&m);
    return 0;
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
