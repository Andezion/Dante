#include <stdio.h>

int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg);
int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg);

int main()
{
    int matrix[5][5] = { 0 };
    printf("Enter:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&*(*(matrix + i) + j));
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    int max, min;
    float avg;

    for(int i = 0; i < 5; i++)
    {
        int check = column_statistics(&matrix[0][0], 5, 5, i, &max, &min, &avg);
        if(check != 0)
        {
            printf("Incorrect input");
            return 1;
        }
        printf("%i %i %.2f\n",min, max, avg);
    }

    for(int j = 0; j < 5; j++)
    {
        int check = row_statistics(&matrix[0][0], 5, 5, j, &max, &min, &avg);
        if(check != 0)
        {
            printf("Incorrect input");
            return 1;
        }
        printf("%i %i %.2f\n",min, max, avg);
    }

    return 0;
}

int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg)
{
    if (column_id < 0 || column_id >= width || ptr == NULL || avg == NULL || max == NULL || min == NULL || height <= 0 || width < 0)
    {
        return 1;
    }

    float sum = 0.0f;
    *max = *min = *(ptr + column_id);

    for (int i = 0; i < height; i++)
    {
        int temp = *(ptr + i * width + column_id);
        sum = sum + (float)temp;

        if (temp <= *max)
        {

        }
        else
        {
            *max = temp;
        }


        if (temp >= *min)
        {
            continue;
        }
        *min = temp;
    }

    *avg = sum / (float)height;

    return 0;
}

int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg)
{
    if (row_id < 0 || row_id >= height || ptr == NULL || avg == NULL || max == NULL || min == NULL || width <= 0 || height < 0)
    {
        return 1;
    }

    float sum = 0.0f;
    *max = *min = *(ptr + row_id * width);

    for (int i = 0; i < width; i++)
    {
        int temp = *(ptr + row_id * width + i);
        sum = sum + (float)temp;

        if (temp <= *max)
        {

        }
        else
        {
            *max = temp;
        }

        if (temp >= *min)
        {
            continue;
        }
        *min = temp;
    }

    *avg = sum / (float)width;

    return 0;
}
