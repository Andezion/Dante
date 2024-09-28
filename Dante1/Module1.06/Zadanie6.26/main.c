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
                printf("\nIncorrect input\n");
                return 1;
            }
        }
    }

    int small_matrix[2][2];
    printf("Enter:\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            int check = scanf("%i",&small_matrix[i][j]);
            if(check != 1)
            {
                printf("\nIncorrect input\n");
                return 1;
            }
        }
    }

    int counter = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if((matrix[i][j] == small_matrix[0][0]) && (matrix[i + 1][j] == small_matrix[1][0]) &&
                    (matrix[i][j + 1] == small_matrix[0][1]) && (matrix[i + 1][j + 1] == small_matrix[1][1]))
            {
                counter++;
            }
        }
    }
    printf("\n%i",counter);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if((matrix[i][j] == small_matrix[0][0]) && (matrix[i + 1][j] == small_matrix[1][0]) &&
               (matrix[i][j + 1] == small_matrix[0][1]) && (matrix[i + 1][j + 1] == small_matrix[1][1]))
            {
                printf("\n%i %i", j, i);
            }
        }
    }

    return 0;
}
