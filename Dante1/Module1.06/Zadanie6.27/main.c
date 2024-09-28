#include <stdio.h>

int main()
{
    int data1[5][10];
    int data2[10][5];

    printf("Enter data:\n");

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int check = scanf("%i",&data1[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
            data2[j][i] = data1[i][j];
        }
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%i ",data2[i][j]);
        }
        printf("\n");
    }


    return 0;
}
