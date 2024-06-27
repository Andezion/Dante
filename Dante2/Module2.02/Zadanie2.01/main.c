#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

struct point_t
{
    int x;
    int y;
};

struct point_t* set(struct point_t* p, int x, int y);
void show(const struct point_t* p);
struct point_t* read(struct point_t* p);
float distance(const struct point_t* p1, const struct point_t* p2, int *err_code);

int main()
{
    srand(time(NULL));

    struct point_t p1;
    struct point_t p2;

    int x = 1 + rand() % 10;
    int y = 1 + rand() % 10;

    if(set(&p2, x, y) == NULL)
    {
        printf("Incorrect input");
        return 1;
    }

    if(read(&p1) == NULL)
    {
        printf("Incorrect input");
        return 1;
    }

    show(&p1);
    show(&p2);

    int err_code;
    float result = distance(&p1, &p2, &err_code);
    if(result == -1.0f)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("%.2f",result);

    return 0;
}

float distance(const struct point_t* p1, const struct point_t* p2, int *err_code)
{
    if (p1 == NULL || p2 == NULL)
    {
        if (err_code == NULL)
        {
            return -1.0f;
        }
        *err_code = 1;
        return -1.0f;
    }

    float distance = sqrtf((powf((float)p2->x - (float)p1->x, 2)) + (powf((float)p2->y - (float)p1->y, 2)));
    if (err_code == NULL)
    {
        return distance;
    }

    *err_code = 0;
    return distance;
}

void show(const struct point_t* p)
{
    if(p == NULL)
    {
        return;
    }

    printf("x: %i y: %i\n",p->x, p->y);
}

struct point_t* set(struct point_t* p, int x, int y)
{
    if(p == NULL)
    {
        return NULL;
    }

    p->x = x;
    p->y = y;

    return p;
}

struct point_t* read(struct point_t* p)
{
    if(p == NULL)
    {
        return NULL;
    }

    int check;
    int x, y;

    printf("Enter: ");
    check = scanf("%i", &x);
    if(!check)
    {
        return NULL;
    }

    printf("Enter: ");
    check = scanf("%i",&y);
    if(!check)
    {
        return NULL;
    }

    p->x = x;
    p->y = y;

    return p;
}
