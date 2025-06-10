#include <stdio.h>
#include <stdlib.h>

int dd_test(const int *ptr, int width, int height);

int main()
{
    int matrix[5][5] = { 0 };

    printf("Enter number:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int check = scanf("%i", &*(*(matrix + i) + j));
            if (check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    int result = dd_test((const int *)matrix, 5, 5);
    if (result == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}

int dd_test(const int *ptr, int width, int height)
{
    if (width != height || ptr == NULL || width < 0 || height < 0)
    {
        return -1;
    }
    if(width == 0 && height == 0)
    {
        return -1;
    }

    for (int i = 0; i < height; ++i)
    {
        int temp = abs(*(ptr + i * width + i));

        int sum = 0;
        for (int j = 0; j < width; ++j)
        {
            if (j != i)
            {
                sum = sum +  abs(*(ptr + i * width + j));
            }
        }

        if (temp <= sum)
        {
            return 0;
        }
    }

    return 1;
}
