#include <stdio.h>

int main()
{
    int matrix[7][7];
    printf("Enter:\n");
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            int check = scanf("%i",&matrix[i][j]);
            if(check != 1)
            {
                printf("\nIncorrect input\n");
                return 1;
            }
        }
    }

    int vector[4];
    int size = 0;

    printf("\nEnter: ");
    for(int i = 0; i < 4; i++)
    {
        int check = scanf("%i",&vector[i]);
        if(check != 1)
        {
            printf("\nIncorrect input\n");
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
        printf("\nNot enough data available\n");
        return 2;
    }

    int counter = 0;
    for (int i = 0; i <= 7 - size; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int temp = 1;
            for (int k = 0; k < size; k++)
            {
                if (matrix[i + k][j] != vector[k])
                {
                    temp = 0;
                    break;
                }
            }
            if (temp)
            {
                counter++;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j <= 7 - size; j++)
        {
            int temp = 1;
            for (int k = 0; k < size; k++)
            {
                if (matrix[i][j + k] != vector[k])
                {
                    temp = 0;
                    break;
                }
            }
            if (temp)
            {
                counter++;
            }
        }
    }
    printf("\n%i\n", counter);

    for (int i = 0; i <= 7 - size; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int temp = 1;
            for (int k = 0; k < size; k++)
            {
                if (matrix[i + k][j] != vector[k])
                {
                    temp = 0;
                    break;
                }
            }
            if (temp)
            {
                printf("1 %i %i\n", j, i);
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j <= 7 - size; j++)
        {
            int temp = 1;
            for (int k = 0; k < size; k++)
            {
                if (matrix[i][j + k] != vector[k])
                {
                    temp = 0;
                    break;
                }
            }
            if (temp)
            {
                printf("2 %i %i\n", j, i);
            }
        }
    }

    return 0;
}




