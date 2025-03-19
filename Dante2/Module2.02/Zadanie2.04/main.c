#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

struct point_t
{
    int x;
    int y;
};

int save_point_b(const char *filename, const struct point_t* p);
int load_point_b(const char *filename, struct point_t* p);
int save_point_t(const char *filename, const struct point_t* p);
int load_point_t(const char *filename, struct point_t* p);

void show(const struct point_t* p);
struct point_t* set(struct point_t* p, int x, int y);

int main()
{
    srand(time(NULL));
    struct point_t p;
    char filename[31];

    int x = 1 + rand() % 10;
    int y = 1 + rand() % 10;

    set(&p, x, y);

    printf("x: %i, y: %i\n",p.x,p.y);
    printf("Enter: ");
    scanf("%30[^\n]",filename);

    while(getchar() != '\n'); // очистка этой залупы

    if(strrchr(filename, '.') == NULL)
    {
        printf("Unsupported file format");
        return 7;
    }

    int error = 0;

    if(strcmp(strrchr(filename, '.'), ".txt") == 0)
    {
        error = save_point_t(filename, &p);
    }
    else if(strcmp(strrchr(filename, '.'), ".bin") == 0)
    {
        error = save_point_b(filename, &p);
    }
    else
    {
        printf("Unsupported file format");
        return 7;
    }

    if(error == 2)
    {
        printf("Couldn't create file");
        return 5;
    }
    if(error == 3)
    {
        printf("Error writing to file");
        return 3;
    }

    printf("File saved\n");

    char answer;
    printf("Enter: ");
    scanf("%c",&answer);
    if(tolower(answer) == 'y')
    {
        if (strcmp(strrchr(filename, '.'), ".txt") == 0)
        {
            error = load_point_t(filename, &p);
        }

        if (strcmp(strrchr(filename, '.'), ".bin") == 0)
        {
            error = load_point_b(filename, &p);
        }

        if (error == 2)
        {
            printf("Couldn't open file");
            return 4;
        }

        if (error == 3)
        {
            printf("File corrupted");
            return 6;
        }
        show(&p);
    }
    else if(tolower(answer) == 'n')
    {
        return 0;
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

    return 0;
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

int load_point_b(const char *filename, struct point_t* p)
{
    if(filename == NULL || p == NULL)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "rb");
    if(!file)
    {
        return 2;
    }

    int size = sizeof(struct point_t);
    if (fread(p, size, 1, file) != 1)
    {
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}

int load_point_t(const char *filename, struct point_t* p)
{
    if(filename == NULL || p == NULL)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "r");
    if(!file)
    {
        return 2;
    }

    int size = fscanf(file, "%i %i",&p->x, &p->y);
    if(size != 2)
    {
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}

int save_point_b(const char *filename, const struct point_t* p)
{
    FILE *file;

    if (!filename || !p)
    {
        return 1;
    }

    file = fopen(filename, "wb");
    if (file == NULL)
    {
        return 2;
    }

    int size = sizeof(struct point_t);
    if (fwrite(p, size, 1, file) == 1)
    {
        fclose(file);
        return 0;
    }

    fclose(file);
    return 3;
}

int save_point_t(const char *filename, const struct point_t* p)
{
    FILE *file;

    if (filename == NULL || p == NULL)
    {
        return 1;
    }

    file = fopen(filename, "w");
    if (file == NULL)
    {
        return 2;
    }

    if (fprintf(file, "%i %i", p->x, p->y) < 0)
    {
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}
