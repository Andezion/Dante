#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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


int load(const char *filename, int ***ptr, enum save_format_t format);
int statistics_row(int **ptr, struct statistic_t **stats);
void destroy(int ***ptr);
void display(int **ptr);

int main()
{
    int error;

    char *filename = malloc(40 * sizeof(char));
    if (filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter storage_of_our_smth: ");
    scanf("%39s", filename);

    int where_is_this_fking_point = 0;
    for(int i = 0; i < 39; i++)
    {
        if(strcmp(".", filename + i) == 0)
        {
            where_is_this_fking_point++;
        }
    }

    char *extension = strrchr(filename, '.');
    if (extension == NULL || (strcmp(extension, ".bin") != 0 && strcmp(extension, ".txt") != 0))
    {
        printf("Unsupported file format");
        free(filename);
        return 7;
    }

    char *temporary = strrchr(filename, '.');
    int check1 = strcmp(temporary, ".bin");
    int check2 = strcmp(temporary, ".txt");
    if (temporary == NULL || check1 != 0 && check2 != 0)
    {
        printf("Unsupported file format");
        free(filename);
        return 7;
    }

    int **storage_of_our_smth;
    if (strcmp(temporary, ".bin") == 0)
    {
        error = load(filename, &storage_of_our_smth, fmt_binary);
    }
    else
    {
        error = load(filename, &storage_of_our_smth, fmt_text);
    }
    free(filename);

    if (error == 4)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    else if (error == 2)
    {
        printf("Couldn't open file");
        return 4;
    }
    else if (error == 3 || error == 1)
    {
        printf("File corrupted");
        return 6;
    }


    struct statistic_t *returning_value;
    error = statistics_row(storage_of_our_smth, &returning_value);
    if (error < 0)
    {
        destroy(&storage_of_our_smth);
        printf("Failed to allocate memory");
        return 8;
    }

    for (int i = 0; i < error; i++)
    {
        printf("%.2i %.2i %.2i %.2f %.2f\n", (*(returning_value + i)).min, (*(returning_value + i)).max, (*(returning_value + i)).range, (*(returning_value + i)).avg, (*(returning_value + i)).standard_deviation);
    }

    destroy(&storage_of_our_smth);
    free(returning_value);
    return 0;
}

int load(const char *filename, int ***ptr, enum save_format_t format)
{
    if (filename == NULL || ptr == NULL || format > 2)
    {
        return 1;
    }

    FILE *file;
    if (format == fmt_text)
    {
        file = fopen(filename, "rt");
    }
    else
    {
        file = fopen(filename, "rb");
    }
    if (file == NULL)
    {
        return 2;
    }

    int little_count = 0;
    int i_hate_this_dante;

    for (int i = 0; !feof(file); i++)
    {
        int error;
        switch (format)
        {
            case fmt_text:
                error = fscanf(file, "%i", &i_hate_this_dante);
                break;
            case fmt_binary:
                error = fread(&i_hate_this_dante, sizeof(int), 1, file);
        }
        if (!feof(file))
        {
            if (error == 1)
            {
                if (i_hate_this_dante != -1)
                {
                    continue;
                }
                little_count++;
            }
            else
            {
                fclose(file);
                return 3;
            }
        }
        else
        {
            break;
        }
    }

    fseek(file, 0, SEEK_SET);

    if (little_count <= 0)
    {
        fclose(file);
        return 3;
    }

    *ptr = calloc(little_count + 1, sizeof(int *));
    if (*ptr == NULL)
    {
        fclose(file);
        return 4;
    }

    *(*ptr + little_count) = NULL;
    for (int i = 0; i < little_count; i++)
    {
        int what = 0;
        int die = 0;
        for (int j = 0; die != -1; j++)
        {
            switch (format)
            {
                case fmt_text:
                    fscanf(file, "%i", &die);
                    break;
                case fmt_binary:
                    fread(&die, sizeof(int), 1, file);
            }
            what++;
        }
        *(*ptr + i) = calloc(what, sizeof(int));
        if (*(*ptr + i) != NULL)
        {
            continue;
        }
        for (int j2 = 0; j2 < i; j2++)
        {
            free(*(*ptr + j2));
        }
        free(*ptr);
        fclose(file);
        return 4;
    }

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < little_count; i++)
    {
        for (int j = 0, read_int = 0; read_int != -1; j++)
        {
            switch (format)
            {
                case fmt_text:
                    fscanf(file, "%i", &read_int);
                    break;
                case fmt_binary:
                    fread(&read_int, sizeof(int), 1, file);
            }
            *(*(*ptr + i) + j) = read_int;
        }
    }
    fclose(file);
    return 0;
}

void destroy(int ***ptr)
{
    if(ptr == NULL || *ptr == NULL)
    {
        return;
    }

    int **temp = *ptr;
    int count = 0;

    while(*(temp + count) != NULL)
    {
        free(*(temp + count));
        count++;
    }

    free(*ptr);
    *ptr = NULL;
}

void display(int **ptr)
{
    if(ptr == NULL)
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

int statistics_row(int **ptr, struct statistic_t **stats)
{
    if (ptr == NULL || stats == NULL)
    {
        return -1;
    }

    int counter_because_we_have_really_much_structs = 0;
    while(*(ptr + counter_because_we_have_really_much_structs) != NULL)
    {
        counter_because_we_have_really_much_structs++;
    }

    struct statistic_t *stat = malloc(counter_because_we_have_really_much_structs * sizeof(struct statistic_t));
    if (stat == NULL)
    {
        return -2;
    }

    int i = 0;
    while(*(ptr + i) != NULL)
    {
        int min = 100000;
        int max = -100000;
        int little_counter = 0;

        float sum = 0, diff = 0;

        for (int j = 0; *(*(ptr + i) + j) != -1; j++)
        {
            if (*(*(ptr + i) + j) < min)
            {
                min = *(*(ptr + i) + j);
            }
            if (*(*(ptr + i) + j) > max)
            {
                max = *(*(ptr + i) + j);
            }

            sum = sum + (float) *(*(ptr + i) + j);
            diff = diff + (float) *(*(ptr + i) + j) * (float) *(*(ptr + i) + j);
            little_counter++;
        }
        if (little_counter < 1)
        {
            (*(stat + i)).min = -1;
            (*(stat + i)).max = -1;
            (*(stat + i)).avg = -1;
            (*(stat + i)).standard_deviation = -1;
            (*(stat + i)).range = -1;
        }
        else
        {
            (*(stat + i)).min = min;
            (*(stat + i)).max = max;
            (*(stat + i)).avg = sum / (float) little_counter;
            (*(stat + i)).standard_deviation = sqrtf((diff / (float) little_counter) - ((*(stat + i)).avg * (*(stat + i)).avg));
            (*(stat + i)).range = max - min;
        }
        i++;
    }

    *stats = stat;
    return i;
}
