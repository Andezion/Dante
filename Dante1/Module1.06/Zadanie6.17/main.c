#include <stdio.h>

int main()
{
    int data_in[5][5];

    printf("Enter:\n");

    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int check = scanf("%i",&data_in[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
            if(i == 4 || j == 4 || i == 0 || j == 0)
            {
                sum = sum + data_in[i][j];
            }
        }
    }

    printf("%i",sum);

    return 0;
}
