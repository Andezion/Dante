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

    int AB[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            AB[i][j] = 0;
            for(int k = 0; k < 4; k++)
            {
                AB[i][j] = AB[i][j] + A[i][k] * B[k][j];
            }
            printf("%2i ",AB[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int BA[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            BA[i][j] = 0;
            for(int k = 0; k < 4; k++)
            {
                BA[i][j] = BA[i][j] + B[i][k] * A[k][j];
            }
            printf("%2i ",BA[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int AC[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            AC[i][j] = 0;
            for(int k = 0; k < 4; k++)
            {
                AC[i][j] = AC[i][j] + A[i][k] * C[k][j];
            }
            printf("%2i ",AC[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int CA[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            CA[i][j] = 0;
            for(int k = 0; k < 4; k++)
            {
                CA[i][j] = CA[i][j] + C[i][k] * A[k][j];
            }
            printf("%2i ",CA[i][j]);
        }
        printf("\n");
    }

    return 0;
}
