#include <stdio.h>

int main()
{
    int matrix[10][10];
    printf("Enter:\n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int check = scanf("%i", &matrix[i][j]);
            if (check != 1)
            {
                printf("incorrect input\n");
                return 1;
            }
        }
    }

    int max = -10000;
    int counter = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
            if (sum > max)
            {
                max = sum;
                counter = 1;
            }
            else if (sum == max)
            {
                counter++;
            }
        }
    }

    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            int sum = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j];
            if (sum > max)
            {
                max = sum;
                counter = 1;
            }
            else if (sum == max)
            {
                counter++;
            }
        }
    }

    printf("%i\n", max);
    printf("%i\n", counter);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
            if (sum == max)
            {
                printf("2 %i %i\n", i, j);
            }
        }
    }

    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            int sum = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j];
            if (sum == max)
            {
                printf("1 %i %i\n", i, j);
            }
        }
    }

    return 0;
}
