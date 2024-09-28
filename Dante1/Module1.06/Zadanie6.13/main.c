#include <stdio.h>
#include <limits.h>

int main()
{
    int error;

    int array[5][5];

    printf("Enter:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            error = scanf("%i", &array[i][j]);
            if(error != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    int max = INT_MIN;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if (i != k || j != l)
                    {
                        int sum = array[i][j] + array[k][l];
                        if (sum > max)
                        {
                            max = sum;
                        }
                    }
                }
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if ((i != k || j != l) && (i * 5 + j < k * 5 + l))
                    {
                        int sum = array[i][j] + array[k][l];
                        if (sum == max)
                        {
                            counter++;
                        }
                    }
                }
            }
        }
    }

    printf("%i %i\n", max, counter);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if ((i != k || j != l) && (i * 5 + j < k * 5 + l))
                    {
                        int sum = array[i][j] + array[k][l];
                        if (sum == max)
                        {
                            printf("%i %i %i %i\n", i, j, k, l);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
