#include "image_utils.h"
#include <stdlib.h>
#include <stdio.h>

int image_draw_rectangle(struct image_t *img, const struct rectangle_t *rect, int value)
{
    if (img == NULL || rect == NULL || img->ptr == NULL || value < 0 || value > 255 ||
        img->width <= 0 || img->height <= 0 || rect->width <= 0 || rect->height <= 0)
    {
        return 1;
    }

    int dx1 = rect->p.x;
    int dx2 = dx1 - 1 + rect->width;

    int dy1 = rect->p.y;
    int dy2 = dy1 - 1 + rect->height;

    if (dx1 < 0 || dy1 < 0 || dx2 >= img->width || dy2 >= img->height)
    {
        return 1;
    }

    for (int i = dx1; i <= dx2; i++)
    {
        *(*(img->ptr + dy1) + i) = value;
        *(*(img->ptr + dy2) + i) = value;
    }
    for (int i = dy1 + 1; i < dy2; i++)
    {
        *(*(img->ptr + i) + dx1) = value;
        *(*(img->ptr + i) + dx2)  = value;
    }

    return 0;
}

const int *image_get_pixel(const struct image_t *img, int x, int y)
{
    if (img == NULL || img->ptr == NULL || x < 0 || x >= img->width || y < 0 || y >= img->height)
    {
        return NULL;
    }

    const int *result = &*(*(img->ptr + y) + x);

    return result;
}

int *image_set_pixel(struct image_t *img, int x, int y)
{
    if (img == NULL || img->ptr == NULL || x < 0 || x >= img->width || y < 0 || y >= img->height)
    {
        return NULL;
    }

    int *result = &*(*(img->ptr + y) + x);

    return result;
}

struct image_t *load_image_t(const char *filename, int *err_code)
{
    if (filename == NULL || *filename == 0)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return NULL;
    }

    int error;

    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        if (err_code)
        {
            *err_code = 2;
        }
        return NULL;
    }

    struct image_t *image = malloc(sizeof(struct image_t));
    if (image == NULL)
    {
        if (err_code)
        {
            *err_code = 4;
        }

        fclose(file);
        return NULL;
    }

    fgets(image->type, 3, file);
    if(*(image->type + 0) != 'P' || *(image->type + 1) != '2')
    {
        if(err_code != NULL)
        {
            *err_code = 3;
        }

        fclose(file);
        free(image);
        return NULL;
    }

    error = fscanf(file, "%i %i", &image->width, &image->height);
    if (error != 2 || image->width <= 0 || image->height <= 0)
    {
        if (err_code)
        {
            *err_code = 3;
        }

        fclose(file);
        free(image);
        return NULL;
    }

    int temp_shit_so_this_funk_can_work_correctly_uwu;
    error = fscanf(file, "%i", &temp_shit_so_this_funk_can_work_correctly_uwu);
    if (error != 1 || temp_shit_so_this_funk_can_work_correctly_uwu > 255 || temp_shit_so_this_funk_can_work_correctly_uwu < 0)
    {
        if (err_code)
        {
            *err_code = 3;
        }

        fclose(file);
        free(image);
        return NULL;
    }

    image->ptr = malloc(image->height * sizeof(int *));
    if (image->ptr == NULL)
    {
        if (err_code)
        {
            *err_code = 4;
        }

        fclose(file);
        free(image);
        return NULL;
    }

    for (int i = 0; i < image->height; i++)
    {
        *(image->ptr + i) = malloc(image->width * sizeof(int));
        if (*(image->ptr + i) == NULL)
        {
            if (err_code)
            {
                *err_code = 4;
            }

            for (int j = 0; j < i; j++)
            {
                free(*(image->ptr + j));
            }
            free(image->ptr);
            fclose(file);
            free(image);
            return NULL;
        }
    }

    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            temp_shit_so_this_funk_can_work_correctly_uwu = 0;
            error = fscanf(file, "%i", &temp_shit_so_this_funk_can_work_correctly_uwu);
            if (error != 1 || temp_shit_so_this_funk_can_work_correctly_uwu < 0 || temp_shit_so_this_funk_can_work_correctly_uwu > 255)
            {
                if (err_code)
                {
                    *err_code = 3;
                }

                for (int y = 0; y < image->height; y++)
                {
                    free(*(image->ptr + y));
                }
                free(image->ptr);
                fclose(file);
                free(image);
                return NULL;
            }
            *(*(image->ptr + i) + j) = temp_shit_so_this_funk_can_work_correctly_uwu;
        }
    }

    fclose(file);
    if (err_code)
    {
        *err_code = 0;
    }
    return image;
}

int save_image_t(const char *filename, const struct image_t *m1)
{
    if (filename == NULL || *filename == 0 || m1 == NULL ||
        m1->ptr == NULL || m1->width <= 0 || m1->height <= 0)
    {
        return 1;
    }

    int error;

    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL)
    {
        return 2;
    }

    error = fprintf(file, "%s\n", m1->type);
    if (error < 0)
    {
        fclose(file);
        return 3;
    }
    error = fprintf(file, "%i %i\n", m1->width, m1->height);
    if (error < 0)
    {
        fclose(file);
        return 3;
    }
    error = fprintf(file, "255\n");
    if (error < 0)
    {
        fclose(file);
        return 3;
    }

    for (int i = 0; i < m1->height; i++)
    {
        for (int j = 0; j < m1->width; j++)
        {
            if (j + 1 == m1->width)
            {
                error = fprintf(file, "%i%s", *(*(m1->ptr + i) + j), "");
                if (error < 0)
                {
                    fclose(file);
                    return 3;
                }
            }
            else
            {
                error = fprintf(file, "%i%s", *(*(m1->ptr + i) + j), " ");
                if (error < 0)
                {
                    fclose(file);
                    return 3;
                }
            }
        }

        error = fprintf(file, "\n");
        if (error < 0)
        {
            fclose(file);
            return 3;
        }
    }

    fclose(file);
    return 0;
}

void destroy_image(struct image_t **m)
{
    if (m == NULL || *m == NULL)
    {
        return;
    }

    for (int i = 0; i < (*m)->height; i++)
    {
        free(*((*m)->ptr + i));
    }

    free((*m)->ptr);
    free(*m);
    *m = NULL;
}

int draw_image(struct image_t *img, const struct image_t *src, int destx, int desty)
{
    if(img == NULL || img->ptr == NULL || img->width < 1 || img->height < 1 || src == NULL
       || src->ptr == NULL || src->width < 1 || src->height < 1 || desty < 0 || destx < 0 ||
       *(img->type + 0) != 'P' || *(img->type + 1) != '2' || *(src->type + 0) != 'P' || *(src->type + 1) != '2' ||
       src->width > img->width || src->height > img->height || destx + src->width > img->width || desty + src->height > img->height)
    {
        return 1;
    }

    for(int i = 0; i < src->height; i++)
    {
        for(int j = 0; j < src->width; j++)
        {
            if(*(*(src->ptr + i) + j) < 0)
            {
                return 1;
            }
        }
    }

    for(int i = desty, i1 = 0; i1 < src->height; i++, i1++)
    {
        for(int j = destx, j1 = 0; j1 < src->width; j++, j1++)
        {
            *(*(img->ptr + i) + j) = *(*(src->ptr + i1) + j1);
        }
    }

    return 0;
}
