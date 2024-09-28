#include <stdio.h>

int main()
{
    int data[5][5];

    int help1[5] = { -100, -100, -100, -100, -100 };
    int help2[5] = { -100, -100, -100, -100, -100 };

    printf("Enter:\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int check = scanf("%i", &data[i][j]);
            if (check != 1)
            {
                printf("Incorrect input");
                return 1;
            }

            if (data[i][j] > help1[i])
            {
                help1[i] = data[i][j];
            }
            if (data[i][j] > help2[j])
            {
                help2[j] = data[i][j];
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%i ", help1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%i ", help2[i]);
    }

    return 0;
}
