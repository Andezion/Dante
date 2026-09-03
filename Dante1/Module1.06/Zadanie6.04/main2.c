#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int data[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%4d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    int A[4][4], B[4][4], C[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;

            if (i == j) C[i][j] = 1;
            else C[i][j] = 0;
        }
    }

    print(A);
    print(B);
    print(C);

    return 0;
}
