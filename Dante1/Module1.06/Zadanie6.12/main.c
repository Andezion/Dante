#include <stdio.h>

int main()
{
    int matrix[10][10];
    printf("Enter:\n");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int check = scanf("%i", &matrix[i][j]);
            if(check != 1)
            {
                printf("\nIncorrect input");
                return 1;
            }
        }
    }

    int result = 0;
    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            int counter = 0;
            for(int i1 = -1; i1 < 2; i1++)
            {
                for(int j1 = -1; j1 < 2; j1++)
                {
                    if(i1 == 0 && j1 == 0)
                    {
                        continue;
                    }
                    if(matrix[i][j] < matrix[i + i1][j + j1])
                    {
                        counter++;
                    }
                }
            }
            if(counter == 8)
            {
                result++;
            }
        }
    }

    if(result == 0)
    {
        printf("\nNothing to show\n");
    }
    else
    {
        printf("%i\n", result);
    }

    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            int counter = 0;
            for(int i1 = -1; i1 < 2; i1++)
            {
                for(int j1 = -1; j1 < 2; j1++)
                {
                    if(i1 == 0 && j1 == 0)
                    {
                        continue;
                    }
                    if(matrix[i][j] < matrix[i + i1][j + j1])
                    {
                        counter++;
                    }
                }
            }
            if(counter == 8)
            {
                printf("%i %i\n", i, j);
            }
        }
    }

    return 0;
}
