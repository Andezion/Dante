#include <limits.h>
#include <stdio.h>

int main()
{
    int matrix[10][10];
    printf("Enter:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (scanf("%i", &matrix[i][j]) != 1)
            {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }

    int max = INT_MIN;
    int counter = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int sum_vert = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
            if (sum_vert > max)
            {
                max = sum_vert;
                counter = 1;
            }
            else if (sum_vert == max)
            {
                counter++;
            }

            int sum_gor = matrix[j][i] + matrix[j + 1][i] + matrix[j + 2][i];
            if (sum_gor > max)
            {
                max = sum_gor;
                counter = 1;
            }
            else if (sum_gor == max)
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

            sum = matrix[j][i] + matrix[j + 1][i] + matrix[j + 2][i];
            if (sum == max)
            {
                printf("1 %i %i\n", i, j);
            }
        }
    }
    return 0;
}
