#include <stdio.h>

int main()
{
    int vector[1000];
    int size = 0;

    printf("Enter: ");
    for(int i = 0; i < 1000; i++)
    {
        int check = scanf("%i",&vector[i]);
        if(check != 1)
        {
            printf("\nIncorrect input");
            return 1;
        }
        if(vector[i] == 0)
        {
            break;
        }
        size++;
    }

    if(size < 2)
    {
        printf("Not enough data available");
        return 2;
    }

    printf("\n");

    if(size % 2 == 0)
    {
        for (int i = 1; i <= size / 2; i++)
        {
            printf("%i ", vector[size - i] - vector[i - 1]);
        }
    }
    else
    {
        for (int i = 1; i <= size / 2; i++)
        {
            printf("%i ", vector[size - i] - vector[i - 1]);
        }
        printf("%i",vector[size / 2]);
    }

    return 0;
}
