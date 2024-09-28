#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrixA[5][5];
    int matrixB[5][5];

    printf("Enter:\n");

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i", &matrixA[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    printf("Enter:\n");

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i", &matrixB[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    int helper[25] = { 0 }; // for storing some numbers


    for(int i = 0; i < 5; i++)
    {
        int counter = 0;

        for(int j = 0; j < 5; j++)
        {
            for(int i1 = 0; i1 < 5; i1++)
            {
                if(matrixA[j][i] == matrixB[i1][i])
                {
                    int temp = 1;
                    for (int j1 = 0; j1 < counter; j1++)
                    {
                        if (helper[j1] == matrixA[j][i])
                        {
                            temp = 0;
                            break;
                        }
                    }

                    if (temp == 1)
                    {
                        helper[counter] = matrixA[j][i];
                        counter++;
                    }
                }
            }
        }

        printf("%i ", counter);

        for(int i1 = 0; i1 < counter; i1++)
        {
            printf("%i ", helper[i1]);
        }
        printf("\n");
    }

    return 0;
}
