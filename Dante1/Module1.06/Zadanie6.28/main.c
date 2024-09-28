#include <stdio.h>

int main()
{
    int matrix[10][10];
    float new_matrix[8][8];

    printf("Enter:\n");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int check = scanf("%i",&matrix[i][j]);
            if(check != 1)
            {
                printf("\nIncorrect input");
                return 1;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            float temp = 0;
            for (int i1 = 0; i1 < 3; i1++)
            {
                for (int j1 = 0; j1 < 3; j1++)
                {
                    temp = temp + (float)matrix[i + i1][j + j1];
                }
            }
            new_matrix[i][j] = temp / 9;
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%.2f ",new_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
