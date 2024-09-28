#include <stdio.h>

int main()
{
    int matrix[5][5];

    printf("Enter matrix:\n");

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
        }
    }

    int suma = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j >= i)
            {
                suma = suma + matrix[i][j];
            }
        }
    }

    printf("%i",suma);

    return 0;
}
