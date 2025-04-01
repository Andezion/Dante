#include <stdio.h>
#include <stdlib.h>

int save_array(const int* tab, int size, const char *filename);
int sort(int* tab, int size);
int load_array(int **tab, int *size, const char *filename);

int main()
{
    char *filename = malloc(sizeof(char) * 31);
    if(filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter: ");
    scanf("%30[^\n]",filename);

    int error;
    int *tab;
    int size;

    error = load_array(&tab, &size, filename);
    if (error != 0)
    {
        if (error == 2)
        {
            printf("Couldn't open file\n");
            free(filename);
            return 4;
        }
        else if (error == 3)
        {
            printf("File corrupted\n");
            free(filename);
            return 6;
        }
        else if (error == 4)
        {
            printf("Failed to allocate memory\n");
            free(filename);
            return 8;
        }
    }

    error = sort(tab, size);
    if (error != 0)
    {
        printf("Incorrect input\n");
        free(filename);
        free(tab);
        return 1;
    }

    error = save_array(tab, size, filename);
    if (error != 0)
    {
        if (error == 2)
        {
            printf("Couldn't create file\n");
            free(tab);
            free(filename);
            return 5;
        }
        else if (error == 3)
        {
            printf("File corrupted\n");
            free(tab);
            free(filename);
            return 6;
        }
    }

    printf("File saved\n");
    free(filename);
    free(tab);
    return 0;
}

int save_array(const int* tab, int size, const char *filename)
{
    if(tab == NULL || size <= 0 || filename == NULL)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "wb");
    if(!file)
    {
        return 2;
    }

    size_t error;

    error = fwrite(&size, sizeof(int), 1, file);
    if(error != 1)
    {
        fclose(file);
        return 3;
    }
    error = fwrite(tab, sizeof(int), size, file);
    if((int) error != size)
    {
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}

int load_array(int **tab, int *size, const char *filename)
{
    if (tab == NULL || size == NULL || filename == NULL)
    {
        return 1;
    }

    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        return 2;
    }

    size_t check = fread(size, sizeof(int), 1, file);
    if (check != 1 || *size <= 0)
    {
        fclose(file);
        return 3;
    }

    *tab = malloc(*size * sizeof(int));
    if (*tab == NULL)
    {
        fclose(file);
        return 4;
    }

    check = fread(*tab, sizeof(int), *size, file);
    if ((int) check != *size)
    {
        free(*tab);
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}

int sort(int* tab, int size)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(*(tab + j) > *(tab + j + 1))
            {
                int temp = *(tab + j);
                *(tab + j) = *(tab + j + 1);
                *(tab + j + 1) = temp;
            }
        }
    }

    return 0;
}
