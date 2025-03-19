#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct point_t
{
    int x;
    int y;
};

struct point_t* read(struct point_t* p);
int save_points_b(const char *filename, const struct point_t* p, unsigned int N);

int main()
{
    int number;
    printf("Enter: ");

    int check;
    check = scanf("%i",&number);
    if(!check)
    {
        printf("Incorrect input");
        return 1;
    }
    if(number > 100)
    {
        number = 100;
    }
    if(number <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Enter:");
    struct point_t p[100];
    for(int i = 0; i < number; i++)
    {
        char *check2 = (char *)read(p + i);
        if(check2 == NULL)
        {
            printf("Incorrect input");
            return 1;
        }
    }

    while(getchar() != '\n');
    char filename[31];
    printf("Enter: ");
    scanf("%30[^\n]",filename);
    while(getchar() != '\n');

    check = save_points_b(filename, p, number);
    if(check == 2)
    {
        printf("Couldn't create file");
        return 5;
    }

    printf("File saved");
    return 0;
}

int save_points_b(const char *filename, const struct point_t* p, unsigned int N)
{
    if(filename == NULL || p == NULL || N == 0)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "wb");
    if(!file)
    {
        return 2;
    }

    size_t check = fwrite(p, sizeof(struct point_t), N, file);
    if(check != N)
    {
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}

struct point_t* read(struct point_t* p)
{
    if(p == NULL)
    {
        return NULL;
    }

    int check;
    int x, y;

    check = scanf("%i %i", &x, &y);
    if(!check)
    {
        return NULL;
    }

    p->x = x;
    p->y = y;

    return p;
}
