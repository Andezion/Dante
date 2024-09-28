#include <stdio.h>

int main()
{
    int matrix[10][10];
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

    printf("\n");

    int vector[4];
    int size = 0;

    printf("\nEnter: ");
    for(int i = 0; i < 4; i++)
    {
        int check = scanf("%i",&vector[i]);
        if(check != 1)
        {
            printf("\nIncorrect input");
            return 1;
        }
        if(vector[i] == 0)
        {
            break;
        }
        size++;
    }
    if(size < 1)
    {
        printf("\nNot enough data available");
        return 2;
    }

    printf("\n");

    for(int k = 0; k < size; k++)
    {
        printf("%i ",k);
        int counter = 0;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(matrix[i][j] == vector[k] * vector[k])
                {
                    counter++;
                }
            }
        }
        printf("%i ",counter);
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(matrix[i][j] == vector[k] * vector[k])
                {
                    printf("%i %i ", j, i);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
