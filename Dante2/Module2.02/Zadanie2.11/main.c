#include <stdio.h>
#include <math.h>
#include <ctype.h>

struct point_t
{
    int x;
    int y;
};
float distance(const struct point_t* p1, const struct point_t* p2, int *err_code);
int load_point_t(const char *filename, struct point_t* p1, struct point_t* p2, struct point_t* tmp1, struct point_t* tmp2);

int main()
{
    FILE *file;
    char filename[100];

    printf("Enter: ");
    scanf("%99[^\n]",filename);

    file = fopen(filename, "r");
    if(!file)
    {
        printf("Couldn't open file");
        return 4;
    }

    int popa = fgetc(file);
    while (popa != EOF)
    {
        if (isalpha(popa))
        {
            fclose(file);
            printf("File corrupted");
            return 6;
        }
        popa = fgetc(file);
    }

    struct point_t p1, p2, tmp1, tmp2;
    int latinas = load_point_t(filename, &p1, &p2, &tmp1, &tmp2);
    if(latinas != 0)
    {
        fclose(file);
        printf("File corrupted");
        return 6;
    }

    printf("%i %i %i %i\n", p1.x, p1.y, p2.x, p2.y);

    fclose(file);
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

int load_point_t(const char *filename, struct point_t *p1, struct point_t *p2, struct point_t *tmp1, struct point_t *tmp2)
{
    if (filename == NULL || p1 == NULL || p2 == NULL || tmp1 == NULL || tmp2 == NULL)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "r");
    if (!file)
    {
        return 2;
    }

    int temporary = fgetc(file);
    while (temporary != EOF)
    {
        if (!isdigit(temporary))
        {
            if (temporary != 10 && temporary != 32 && temporary != 45)
            {
                fclose(file);
                return 3;
            }
        }
        temporary = fgetc(file);
    }

    int check;
    fseek(file, 0, SEEK_SET);

    check = fscanf(file, "%d %d", &p1->x, &p1->y);
    if (check != 2)
    {
        fclose(file);
        return 3;
    }

    fgetc(file);

    check = fscanf(file, "%d %d", &p2->x, &p2->y);
    if (check != 2)
    {
        fclose(file);
        return 3;
    }

    fseek(file, 0, SEEK_SET);


    int error = 0;
    while (fscanf(file, "%d %d", &tmp1->x, &tmp1->y) == 2)
    {
        int work_please = ftell(file);
        while (fscanf(file, "%d %d", &tmp2->x, &tmp2->y) == 2)
        {
            if (distance(p1, p2, &error) > distance(tmp1, tmp2, &error))
            {
                p1->x = tmp1->x;
                p1->y = tmp1->y;
                p2->x = tmp2->x;
                p2->y = tmp2->y;
            }
            if (distance(p1, p2, &error) == distance(tmp1, tmp2, &error))
            {
                if(p1->x < tmp1->x || p2->x < tmp2->x)
                {
                    tmp1->x = p1->x;
                    tmp1->y = p1->y;
                    tmp2->x = p2->x;
                    tmp2->y = p2->y;
                }
                if(p1->x > tmp1->x || p2->x > tmp2->x)
                {
                    p1->x = tmp1->x;
                    p1->y = tmp1->y;
                    p2->x = tmp2->x;
                    p2->y = tmp2->y;
                }
            }
        }

        fseek(file, work_please, SEEK_SET);
    }

    fclose(file);
    return 0;
}
