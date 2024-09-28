#include <stdio.h>

int main()
{
    int matrix[5][5];
    float vector[5];

    printf("Enter:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&matrix[i][j]);
            if(check != 1)
            {
                printf("\nIncorrect input");
                return 1;
            }
        }
    }

    for(int j = 0; j < 5; j++)
    {
        float sum = 0;
        for(int i = 0; i < 5; i++)
        {
            sum = sum + (float)matrix[i][j];
        }
        vector[j] = sum / 5;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%.2f ",vector[i]);
    }

    return 0;
}
