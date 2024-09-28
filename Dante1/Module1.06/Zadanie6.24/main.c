#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int matrix[5][5];
    printf("Enter:\n");


    float sum = 0;
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
            sum = sum + (float)matrix[i][j];
        }
    }

    float middle = sum / 25;
    float diff = 100;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(fabsf(middle - (float)matrix[i][j]) < diff)
            {
                diff = fabsf(middle - (float)matrix[i][j]);
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(fabsf(middle - (float)matrix[i][j]) == diff)
            {
                printf("%i %i\n",i,j);
            }
        }
    }

    return 0;
}
