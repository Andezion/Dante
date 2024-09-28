#include <stdio.h>

int main()
{
    int data[15][15];
    int result[30] = { 0 };

    printf("Enter numbers:\n");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            int check = scanf("%i", &data[i][j]);
            if (check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
            if (data[i][j] < 0 || data[i][j] >= 30)
            {
                printf("Value out of range");
                return 2;
            }
            result[data[i][j]]++;
        }
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            printf("%2i ", result[data[i][j]]);
        }
        printf("\n");
    }

    return 0;
}
