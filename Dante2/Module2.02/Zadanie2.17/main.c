#include <stdio.h>

struct array_t
{
    int size;
    int array[100];
};

int save_array_b(const char *filename, const struct array_t *arr);
int load_array_b(const char *filename, struct array_t *arr);

int sort(struct array_t *arr);

int main()
{
    struct array_t arr;

    char filename[31];
    printf("Write your: ");
    scanf("%30[^\n]", filename);

    int result = load_array_b(filename, &arr);
    if (result == 1)
    {
        printf("Incorrect input data");
        return 2;
    }
    if (result == 2)
    {
        printf("Couldn't open file");
        return 4;
    }
    if (result == 3)
    {
        printf("File corrupted");
        return 6;
    }

    result = sort(&arr);
    if (result == 1)
    {
        printf("Incorrect input data");
        return 2;
    }

    result = save_array_b(filename, &arr);
    if (result != 0)
    {
        printf("Couldn't create file");
        return 5;
    }

    printf("File saved");
    return 0;
}

int save_array_b(const char *filename, const struct array_t *arr)
{
    if(filename == NULL || arr == NULL || arr->size <= 0)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "wb");
    if(!file)
    {
        return 2;
    }

    unsigned int check;

    check = fwrite(&(arr->size), sizeof(int), 1, file);
    if(check != 1)
    {
        fclose(file);
        return 3;
    }
    check = fwrite(arr->array, sizeof(int), arr->size, file);
    if((int)check != arr->size)
    {
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}

int load_array_b(const char *filename, struct array_t *arr)
{
    if (filename == NULL || arr == NULL)
    {
        return 1;
    }

    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return 2;
    }

    unsigned long long check = fread(arr, sizeof(struct array_t), 1, fp);
    if (check != 1)
    {
        fclose(fp);
        return 3;
    }

    fclose(fp);
    return 0;
}

int sort(struct array_t *arr)
{
    if(arr == NULL || arr->size <= 0 || arr->size > 100)
    {
        return 1;
    }

    for(int i = 0; i < arr->size - 1; i++)
    {
        int point = 0;
        for(int j = 0; j < arr->size - 1; j++)
        {
            if(*(arr->array + j) > *(arr->array + j + 1))
            {
                int temp = *(arr->array + j);
                *(arr->array + j) = *(arr->array + j + 1);
                *(arr->array + j + 1) = temp;
                point = 1;
            }
        }
        if(point == 0)
        {
            break;
        }
    }

    return 0;
}
