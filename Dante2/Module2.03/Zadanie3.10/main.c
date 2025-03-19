#include <stdio.h>
#include <math.h>

struct point_t
{
    int x;
    int y;
};

struct rectangle_t
{
    struct point_t p;
    int width;
    int height;
};

struct circle_t
{
    struct point_t c;
    float r;
};

struct triangle_t
{
    struct point_t p1;
    struct point_t p2;
    struct point_t p3;
};

enum figure_types
{
    TRIANGLE = 1,
    RECTANGLE,
    CIRCLE
};

struct figure_t
{
    union
    {
        struct rectangle_t rect;
        struct triangle_t triangle;
        struct circle_t circ;
    };
    enum figure_types type;
};

int sort_by_area(struct figure_t **figures, int size);

float area_triangle(const struct triangle_t *t);
float area_rectangle(const struct rectangle_t *r);
float area_circle(const struct circle_t *c);
float area_figure(const struct figure_t *f);

void display_rectangle(const struct rectangle_t *rect);
void display_triangle(const struct triangle_t *t);
void display_circle(const struct circle_t *circ);
void display_figure(struct figure_t *f);


int main()
{
    int max = 50;
    int iterator = 0;

    int choice;
    int error;

    struct figure_t popa;
    struct figure_t storage[50];
    struct figure_t *pointer[50];

    while(iterator != max)
    {
        printf("Enter type: ");
        error = scanf("%i",&choice);
        if(!error)
        {
            printf("Incorrect input");
            return 1;
        }

        if(choice == TRIANGLE)
        {
            popa.type = 1;

            printf("Enter points of triangle: ");
            error = scanf("%i %i %i %i %i %i", &popa.triangle.p1.x, &popa.triangle.p1.y,
                          &popa.triangle.p2.x, &popa.triangle.p2.y,
                          &popa.triangle.p3.x, &popa.triangle.p3.y);
            if(error != 6)
            {
                printf("Incorrect input");
                return 1;
            }

            while(getchar() != '\n');
        }
        else if(choice == RECTANGLE)
        {
            popa.type = 2;

            printf("Enter points of rect: ");
            error = scanf("%i %i %i %i", &popa.rect.p.x, &popa.rect.p.y, &popa.rect.width, &popa.rect.height);
            if(error != 4)
            {
                printf("Incorrect input");
                return 1;
            }

            while(getchar() != '\n');
        }
        else if(choice == CIRCLE)
        {
            popa.type = 3;

            printf("Enter points of circ: ");
            error = scanf("%i %i %f", &popa.circ.c.x, &popa.circ.c.y, &popa.circ.r);
            if(error != 3)
            {
                printf("Incorrect input");
                return 1;
            }

            while(getchar() != '\n');
        }
        else if(choice == 0)
        {
            break;
        }
        else
        {
            printf("Incorrect input data");
            return 2;
        }

        *(storage + iterator) = popa;
        *(pointer + iterator) = (storage + iterator);

        iterator++;
    }

    error = sort_by_area(pointer, iterator);
    {
        if(error == 1)
        {
            printf("Incorrect input data");
            return 2;
        }
    }
    for(int i = 0; i < iterator; i++)
    {
        display_figure(*(pointer + i));
    }

    return 0;
}

int sort_by_area(struct figure_t **figures, int size)
{
    if(figures == NULL || size <= 0)
    {
        return 1;
    }
    for(int i = 0; i < size; i++)
    {
        if(*(figures + i) == NULL)
        {
            return 1;
        }
    }

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            float to_comp1 = area_figure(*(figures + j));
            if(to_comp1 == -1.0f)
            {
                return 1;
            }

            float to_comp2 = area_figure(*(figures + j + 1));
            if(to_comp2 == -1.0f)
            {
                return 1;
            }

            if(to_comp2 > to_comp1)
            {
                struct figure_t *temp = *(figures + j);
                *(figures + j) = *(figures + j + 1);
                *(figures + j + 1) = temp;
            }
        }
    }

    return 0;
}

void display_figure(struct figure_t *f)
{
    if(f == NULL)
    {
        return;
    }

    if(f->type == TRIANGLE)
    {
        display_triangle(&f->triangle);
    }
    if(f->type == CIRCLE)
    {
        display_circle(&f->circ);
    }
    if(f->type == RECTANGLE)
    {
        display_rectangle(&f->rect);
    }
    else
    {
        return;
    }
}

void display_rectangle(const struct rectangle_t *rect)
{
    if(rect == NULL)
    {
        return;
    }
    printf("Rectangle (%i, %i), width = %i, height = %i\n",rect->p.x, rect->p.y, rect->width, rect->height);
}

void display_triangle(const struct triangle_t *t)
{
    if(t == NULL)
    {
        return;
    }
    printf("Triangle  p1(%i, %i), p2(%i, %i), p3(%i, %i)\n",t->p1.x, t->p1.y, t->p2.x, t->p2.y, t->p3.x, t->p3.y);
}

void display_circle(const struct circle_t *circ)
{
    if(circ == NULL)
    {
        return;
    }

    printf("Circle (%i, %i), radius = %f\n",circ->c.x, circ->c.y, circ->r);
}

float area_triangle(const struct triangle_t *t)
{
    if(t == NULL)
    {
        return -1.0f;
    }

    float result = 0.5f * (float)((t->p1.x - t->p3.x) * (t->p2.y - t->p3.y) - (t->p2.x - t->p3.x) * (t->p1.y - t->p3.y));
    if(result == 0)
    {
        return -1.0f;
    }
    return fabsf(result);
}

float area_rectangle(const struct rectangle_t *r)
{
    if(r == NULL || r->height < 0 || r->width < 0)
    {
        return -1.0f;
    }

    float result = (float)(r->width * r->height);
    if(result == 0)
    {
        return -1.0f;
    }

    return fabsf(result);
}

float area_circle(const struct circle_t *c)
{
    if(c == NULL || c->r < 0)
    {
        return -1.0f;
    }

    float result = M_PI * c->r * c->r;
    if(result == 0)
    {
        return -1.0f;
    }

    return result;
}

float area_figure(const struct figure_t *f)
{
    if(f == NULL)
    {
        return -1.0f;
    }

    if(f->type == TRIANGLE)
    {
        float result = area_triangle(&f->triangle);
        if(result != -1.0f)
        {
            return result;
        }
    }
    else if(f->type == CIRCLE)
    {
        if(f->circ.r <= 0)
        {
            return -1.0f;
        }
        float result = area_circle(&f->circ);
        if(result != -1.0f)
        {
            return result;
        }
    }
    else if(f->type == RECTANGLE)
    {
        if(f->rect.height <= 0 || f->rect.width <= 0)
        {
            return -1.0f;
        }
        float result = area_rectangle(&f->rect);
        if(result != -1.0f)
        {
            return result;
        }
    }

    return -1.0f;
}
