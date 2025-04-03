#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "format_type.h"

struct statistic_t
{
    int min;
    int max;
    float avg;
    float standard_deviation;
    int range;
};

int statistics(int **ptr, struct statistic_t **stats)
{
    if(ptr == NULL || stats == NULL)
    {
        return 1;
    }

    struct statistic_t *stat = malloc(sizeof(struct statistic_t));
    if(stat == NULL)
    {
        return 2;
    }

    if (*ptr == NULL)
    {
        free(stat);
        return 3;
    }

    stat->min = *(*(ptr + 0) + 0);
    stat->max = *(*(ptr + 0) + 0);

    int i = 0;
    int suma = 0;
    int counter = 0;
    while (*(ptr + i) != NULL)
    {
        int j = 0;
        while (*(*(ptr + i) + j) != -1)
        {
            suma = suma + *(*(ptr + i) + j);

            if (stat->max < *(*(ptr + i) + j))
            {
                stat->max = *(*(ptr + i) + j);
            }
            if (stat->min > *(*(ptr + i) + j))
            {
                stat->min = *(*(ptr + i) + j);
            }

            j++;
            counter++;
        }
        i++;
    }

    if (counter == 0)
    {
        free(stat);
        return 3;
    }

    stat->avg = (float) suma / (float) counter;

    i = 0;
    float temp = 0.0f;
    while (*(ptr + i) != NULL)
    {
        int j = 0;
        while (*(*(ptr + i) + j) != -1)
        {

            temp = temp + powf((float) *(*(ptr + i) + j) - stat->avg, 2);
            j++;
        }
        i++;
    }

    stat->standard_deviation = sqrtf(temp / (float) counter);
    stat->range = stat->max - stat->min;

    *stats = stat;

    return 0;
}
void display(int **ptr);
int save(const char *filename, int **ptr, enum save_format_t format);

int main()
{
    int error;

    int A[] = {10, 20, 30, 40, 50, 60, 70, -1};
    int B[] = {100, 200, 300, 400, 500, 600, 700, 800, -1};
    int C[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, -1};
    int* D[] = {A, B, C, NULL};

    display(D);

    char *filename = malloc(sizeof(char) * 40);
    if (!filename)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Enter filename (max 39 characters): ");
    scanf("%39[^\n]", filename);

    char *temp_bin = malloc(sizeof(char) * (strlen(filename) + 5));
    if (!temp_bin)
    {
        printf("Failed to allocate memory");
        free(filename);
        return 8;
    }
    strcpy(temp_bin, filename);
    strcat(temp_bin, ".bin");

    char *temp_txt = malloc(sizeof(char) * (strlen(filename) + 5));
    if (!temp_txt)
    {
        printf("Failed to allocate memory");
        free(temp_bin);
        free(filename);
        return 8;
    }
    strcpy(temp_txt, filename);
    strcat(temp_txt, ".txt");

    error = save(temp_txt, D, 0);
    if (error == 0)
    {
        printf("File saved\n");
    }
    else
    {
        printf("Couldn't create file\n");
    }

    error = save(temp_bin, D, 1);
    if (error == 0)
    {
        printf("File saved\n");
    }
    else
    {
        printf("Couldn't create file\n");
    }

    struct statistic_t *work_plz = NULL;
    error = statistics(D, &work_plz);
    if (error != 0)
    {
        if (error == 1)
        {
            printf("Incorrect input\n");
        }
        else if (error == 2)
        {
            printf("Failed to allocate memory\n");
        }
        else
        {
            printf("popo pipo po pipo\n");
        }
        free(filename);
        free(temp_bin);
        free(temp_txt);
        return error;
    }

    printf("%i\n%i\n%i\n%f\n%f",
           work_plz->min, work_plz->max, work_plz->range, work_plz->avg, work_plz->standard_deviation);

    free(filename);
    free(temp_bin);
    free(temp_txt);
    free(work_plz);
    return 0;
}

int save(const char *filename, int **ptr, enum save_format_t format)
{
    if (filename == NULL || ptr == NULL || (format != fmt_binary && format != fmt_text))
    {
        return 1;
    }

    if (format == fmt_binary)
    {
        FILE *file;
        file = fopen(filename, "wb");
        if (!file)
        {
            return 2;
        }

        int counter = 0;
        int one = -1;

        while (*(ptr + counter) != NULL)
        {
            int row = 0;
            while (*(*(ptr + counter) + row) != -1)
            {
                fwrite((*(ptr + counter) + row), sizeof(int), 1, file);
                row++;
            }
            fwrite(&one, sizeof(int), 1, file);
            counter++;
        }

        fclose(file);
    }
    else
    {
        FILE *file;
        file = fopen(filename, "w");
        if (!file)
        {
            return 2;
        }

        int counter = 0;
        while (*(ptr + counter) != NULL)
        {
            int row = 0;

            while (*(*(ptr + counter) + row) != -1)
            {
                fprintf(file, "%d ", *(*(ptr + counter) + row));
                row++;
            }

            fprintf(file, "%i\n", -1);
            counter++;
        }

        fclose(file);
    }

    return 0;
}

void display(int **ptr)
{
    if(ptr == NULL || *ptr == NULL)
    {
        return;
    }

    int counter = 0;
    while(*(ptr + counter) != NULL)
    {
        int temp = 0;

        while(*(*(ptr + counter) + temp) != -1)
        {
            printf("%i ",*(*(ptr + counter) + temp));
            temp++;
        }

        printf("\n");
        counter++;
    }
}
