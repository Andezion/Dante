#include <stdio.h>

int main()
{
    int data[5][5];

    int sum1 = 0, sum2 = 0;

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

            if(i == j)
            {
                sum1 = sum1 + data[i][j];
            }
            if(i + j == 4)
            {
                sum2 = sum2 + data[i][j];
            }
        }
    }
    printf("%i %i",sum1,sum2);

    return 0;
}
