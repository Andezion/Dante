#include <stdio.h>

int main()
{
    int data[5][5];
    printf("Enter data:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&data[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }
    printf("\n");

    /*for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%i  ",data[i][j]);
        }
        printf("\n");
    }*/

    for (int i = 0; i < 5; i++)
    {
        int temp = data[i][i];
        data[i][i] = data[i][4 - i];
        data[i][4 - i] = temp;
    }

    printf("\n");

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%i  ",data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
