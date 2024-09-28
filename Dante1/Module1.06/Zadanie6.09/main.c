#include <stdio.h>

int main()
{
    int data[10][10];

    int suma1 = 0;
    int suma2 = 0;

    printf("Enter:\n");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int check = scanf("%i",&data[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
            if((i + j) % 2 == 0)
            {
                suma1 = suma1 + data[i][j];
            }
            else
            {
                suma2 = suma2 + data[i][j];
            }
        }
    }

    printf("\n%i",suma1 - suma2);

    return 0;
}
