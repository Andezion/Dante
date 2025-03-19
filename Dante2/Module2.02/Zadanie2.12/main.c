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
int load_segments_b(const char *filename, struct segment_t* p, unsigned int N);
int save_segments_b(const char *filename, const struct segment_t* s, unsigned int N);
int sort(struct segment_t *s, int N);

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

int sort(struct segment_t *s, int N)
{
    if(s == NULL || N == 0)
    {
        return 1;
    }
    return 0;
}

int save_segments_b(const char *filename, const struct segment_t* s, unsigned int N)
{
    if(filename == NULL || s == NULL || N == 0)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "wb");
    if(!file)
    {
        return 2;
    }

    size_t check = fwrite(s, sizeof(struct segment_t), N, file);
    if(!check)
    {
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}


int load_segments_b(const char *filename, struct segment_t* p, unsigned int N)
{
    if(filename == NULL || p == NULL || N == 0)
    {
        return -1;
    }

    FILE *file;
    file = fopen(filename, "rb");
    if(!file)
    {
        return -2;
    }

    unsigned int popa = 0;

    unsigned int n = fread(&popa, sizeof(int), 1, file);
    if (n != 1)
    {
        fclose(file);
        return -3;
    }
    unsigned int check = fread(&p, sizeof(struct segment_t), popa, file);

    if (check != popa)
    {
        fclose(file);
        return -3;
    }

    fclose(file);
    return (int)popa;
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
