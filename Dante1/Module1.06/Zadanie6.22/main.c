#include <stdio.h>

int main()
{
    int matrix[5][5];
    printf("Enter:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&matrix[i][j]);
            if(check != 1)
            {
                printf("\nIncorrect input\n");
                return 1;
            }
        }
    }

    int vector[5];
    for(int j = 0; j < 5; j++)
    {
        int min = __INT_MAX__;
        int max = -1 * __INT_MAX__;

        int diff;

        for(int i = 0; i < 5; i++)
        {
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
            if(matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
        diff = max - min;
        vector[j] = diff;
    }

    int max = vector[0];
    for(int i = 1; i < 5; i++)
    {
        if(max < vector[i])
        {
            max = vector[i];
        }
    }

    for(int j = 0; j < 5; j++)
    {
        if(max == vector[j])
        {
            for(int i = 0; i < 5; i++)
            {
                printf("%i ",matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
