#include <stdio.h>

int main()
{
    int matrixA[5][5];
    int vectorA[5] = {0};

    int matrixB[5][5];
    int vectorB[5] = {0};

    printf("Enter:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&matrixA[i][j]);
            if(check != 1)
            {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    printf("Enter:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&matrixB[i][j]);
            if(check != 1)
            {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        int sum1 = 0, sum2 = 0;
        for(int j = 0; j < 5; j++)
        {
            sum1 = sum1 + matrixA[j][i];
            sum2 = sum2 + matrixB[j][i];
        }
        vectorA[i] = sum1;
        vectorB[i] = sum2;
    }

    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (vectorA[j] >= vectorB[j])
            {
                printf("%i ", matrixA[i][j]);
            }
            else
            {
                printf("%i ", matrixB[i][j]);
            }
        }
        printf("\n");
    }


    return 0;
}
