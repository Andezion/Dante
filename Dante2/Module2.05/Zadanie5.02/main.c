#include <stdio.h>
#include <stdlib.h>

int **create_array_2d(int width, int height);
void display_array_2d(int **ptr, int width, int height);
void destroy_array_2d(int **ptr, int height);

int main()
{
    int error;

    int width, height;
    printf("Enter: ");

    error = scanf("%i %i", &width, &height);
    if (error != 2)
    {
        printf("Incorrect input");
        return 1;
    }

    if (width <= 0 || height <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    int **array = create_array_2d(width, height);
    if (array == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter: ");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            error = scanf("%i", &*(*(array + i) + j));
            if (error != 1)
            {
                printf("Incorrect input");
                destroy_array_2d(array, height);
                return 1;
            }
        }
    }

    display_array_2d(array, width, height);
    destroy_array_2d(array, height);

    return 0;
}

int **create_array_2d(int width, int height)
{
    if(width <= 0 || height <= 0)
    {
        return NULL;
    }

    int **array = (int **) malloc(sizeof(int *) * height);
    if(array == NULL)
    {
        return NULL;
    }

    for(int i = 0; i < height; i++)
    {
        *(array + i) = malloc(sizeof(int) * width);
        if(*(array + i) == NULL)
        {
            destroy_array_2d(array, height);
            return NULL;
        }
    }

    return array;
}

void display_array_2d(int **ptr, int width, int height)
{
    if (ptr != NULL)
    {
        if (width > 0 && height > 0)
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    printf("%i ", *(*(ptr + i) + j));
                }
                printf("\n");
            }
        }
    }
}

void destroy_array_2d(int **ptr, int height)
{
    if (ptr == NULL)
    {
        return;
    }

    for (int i = 0; i < height; i++)
    {
        free(*(ptr + i));
    }
    free(ptr);
}
