#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

void print(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int k = 0; k < count; k++)
    {
        int (*data)[4] = va_arg(args, int (*)[4]);

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

    va_end(args);
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

    print(3, A, B, C);

    return 0;
}
