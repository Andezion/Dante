#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    int A[4][4], B[4][4], C[4][4];


    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            A[i][j] = rand() % 10;
            printf("%2i ",A[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            B[i][j] = rand() % 10;
            printf("%2i ",B[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(i == j)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = 0;
            }
            printf("%2i ",C[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        int suma = 0;
        for(int j = 0; j < 4; j++)
        {
            suma = suma + A[i][j];
        }
        printf("%2i ",suma);
    }

    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        int suma = 0;
        for(int j = 0; j < 4; j++)
        {
            suma = suma + A[j][i];
        }
        printf("%2i ",suma);
    }

    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        int suma = 0;
        for(int j = 0; j < 4; j++)
        {
            suma = suma + B[i][j];
        }
        printf("%2i ",suma);
    }

    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        int suma = 0;
        for(int j = 0; j < 4; j++)
        {
            suma = suma + B[j][i];
        }
        printf("%2i ",suma);
    }

    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        int suma = 0;
        for(int j = 0; j < 4; j++)
        {
            suma = suma + C[i][j];
        }
        printf("%2i ",suma);
    }

    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        int suma = 0;
        for(int j = 0; j < 4; j++)
        {
            suma = suma + C[j][i];
        }
        printf("%2i ",suma);
    }

    printf("\n");

    return 0;
}
