#include <stdio.h>
#include <math.h>

struct point_t
{
    int x;
    int y;
};

struct segment_t
{
    struct point_t start;
    struct point_t end;
};

struct segment_t* read_segment(struct segment_t* p);
void show_segment(const struct segment_t* p);
float length(const struct segment_t* s, int *err_code);

int main()
{
    struct segment_t p;
    printf("Enter: ");

    if(read_segment(&p) == NULL)
    {
        printf("Incorrect input");
        return 1;
    }

    show_segment(&p);

    int err_code;
    float result = length(&p, &err_code);
    if(result == -1.0f)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("%.2f",result);

    return 0;
}

float length(const struct segment_t* s, int *err_code)
{
    if (s == NULL)
    {
        if (err_code == NULL)
        {
            return -1.0f;
        }
        *err_code = 1;
        return -1.0f;
    }

    float distance = sqrtf((powf((float)s->end.x - (float)s->start.x, 2)) + (powf((float)s->end.y - (float)s->start.y, 2)));
    if (err_code == NULL)
    {
        return distance;
    }

    *err_code = 0;
    return distance;
}

void show_segment(const struct segment_t* p)
{
    if(p == NULL)
    {
        return;
    }
    printf("%i; %i\n",p->start.x, p->start.y);
    printf("%i; %i\n",p->end.x, p->end.y);
}

struct segment_t* read_segment(struct segment_t* p)
{
    if(p == NULL)
    {
        return NULL;
    }

    int error;

    printf("Enter x1: ");
    error = scanf("%i",&p->start.x);
    if(!error)
    {
        return NULL;
    }
    printf("Enter y1: ");
    error = scanf("%i",&p->start.y);
    if(!error)
    {
        return NULL;
    }
    printf("Enter x2: ");
    error = scanf("%i",&p->end.x);
    if(!error)
    {
        return NULL;
    }
    printf("Enter y2: ");
    error = scanf("%i",&p->end.y);
    if(!error)
    {
        return NULL;
    }

    return p;
}
