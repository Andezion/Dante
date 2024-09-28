#include <stdio.h>

int main()
{
    int matrixA[5][5];
    int matrixB[5][5];

    printf("Enter:\n");

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&matrixA[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    printf("Enter\n");

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&matrixB[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
            if(matrixA[i][j] > matrixB[i][j])
            {
                continue;
            }
            else
            {
                matrixA[i][j] = matrixB[i][j];
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%i ",matrixA[i][j]);
        }
        printf("\n");
    }

    return 0;
}
