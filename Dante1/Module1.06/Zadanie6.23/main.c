#include <stdio.h>

int main(void)
{
    int error;

    printf("Enter:\n");
    int array_one[5][5];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            error = scanf("%i",&array_one[i][j]);
            if(error != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    printf("Enter:\n");
    int array_two[5][5];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            error = scanf("%i",&array_two[i][j]);
            if(error != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    int point = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(array_one[i][j] != array_two[i][j])
            {
                point = 1;
            }
        }
    }
    if(point == 0)
    {
        printf("0 0 1 2 3 4\n"
               "1 0 1 2 3 4\n"
               "2 0 1 2 3 4\n"
               "3 0 1 2 3 4\n"
               "4 0 1 2 3 4");
        return 0;
    }

    for (int i = 0; i < 5; i++)
    {
        int first_match = 1;
        for (int j = 0; j < 5; j++)
        {
            int match = 1;
            for (int k = 0; k < 5; k++)
            {
                if (array_one[i][k] != array_two[k][j])
                {
                    match = 0;
                    break;
                }
            }
            if (match)
            {
                if (first_match)
                {
                    printf("%d %d", i, j);
                    first_match = 0;
                }
                else
                {
                    printf(" %d", j);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
