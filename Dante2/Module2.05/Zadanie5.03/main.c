#include <stdio.h>
#include <stdlib.h>

int create_array_2d_2(int ***ptr, int width, int height);
void destroy_array_2d(int ***ptr, int height);
void display_array_2d(int **ptr, int width, int height);
int sum_array_2d(int **ptr, int width, int height);
int sum_row(int *ptr, int width);

int main()
{
    int error;

    int width, height;
    printf("Enter: ");

    error = scanf("%i %i",&width, &height);
    if(error != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(height <= 0 || width <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    int **ptr;
    error = create_array_2d_2(&ptr, width, height);
    if(error == 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(error == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter:\n");
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            error = scanf("%i",(*(ptr + i) + j));
            if(!error)
            {
                destroy_array_2d(&ptr, height);
                printf("Incorrect input");
                return 1;
            }
        }
    }
    display_array_2d(ptr, width, height);

    for(int i = 0; i < height; i++)
    {
        printf("%i\n", sum_row(*(ptr + i), width));
    }
    printf("%i", sum_array_2d(ptr, width, height));

    destroy_array_2d(&ptr, height);
    return 0;
}

int sum_array_2d(int **ptr, int width, int height)
{
    if(ptr == NULL || width <= 0 || height <= 0)
    {
        return -1;
    }

    int suma = 0;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            suma = suma + *(*(ptr + i) + j);
        }
    }

    return suma;
}

int sum_row(int *ptr, int width)
{
    if(ptr == NULL || width <= 0)
    {
        return -1;
    }

    int suma = 0;

    for(int i = 0; i < width; i++)
    {
        suma = suma + *(ptr + i);
    }

    return suma;
}

int create_array_2d_2(int ***ptr, int width, int height)
{
    if(width <= 0 || height <= 0 || ptr == NULL)
    {
        return 1;
    }

    int **array = malloc(sizeof(int *) * height);
    if(array == NULL)
    {
        return 2;
    }

    for(int i = 0; i < height; i++)
    {
        *(array + i) = malloc(sizeof(int) * width);
        if(*(array + i) == NULL)
        {
            destroy_array_2d(&array, height);
            return 2;
        }
    }

    *ptr = array;

    return 0;
}

void display_array_2d(int **ptr, int width, int height)
{
    if (ptr == NULL || width <= 0 || height <= 0)
    {
        return;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%i ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
}

void destroy_array_2d(int ***ptr, int height)
{
    if (ptr == NULL || height <= 0)
    {
        return;
    }

    int **temp = *ptr;
    for (int i = 0; i < height; i++)
    {
        free(*(temp + i));
    }
    free(temp);

    *ptr = NULL;
}
