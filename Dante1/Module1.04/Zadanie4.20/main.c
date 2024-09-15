#include <stdio.h>

int main()
{
    int vector[100];
    int size = 0;

    printf("Enter number:\n");
    for(int i = 0; i < 100; i++)
    {
        int check = scanf("%i",&vector[i]);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(vector[i] == 0)
        {
            break;
        }
        size++;
    }

    if(size < 1)
    {
        printf("Not enough data available");
        return 2;
    }

    for(int i = size - 1; i >= 0; i--)
    {
        if(i % 2 == 0)
        {
            printf("%i ",vector[i]);
        }
    }

    return 0;
}
