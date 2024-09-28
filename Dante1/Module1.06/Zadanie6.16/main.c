#include <stdio.h>

int main()
{
    int matrix[5][5];
    int vector[5];

    printf("Enter:\n");

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&matrix[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
            vector[j] += matrix[i][j];
        }
    }

    int max = vector[0];
    int need = 0;
    for(int i = 1; i < 5; i++)
    {
        if(max < vector[i])
        {
            max = vector[i];
            need = i;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        if(vector[i] == max)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%i ",matrix[j][need]);
            }
            printf("\n");
        }
    }

    return 0;
}
