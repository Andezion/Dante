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

    for(int i = 0; i < size - 1; i++)
    {
        printf("%.2f ",(float)(vector[i] + vector[i + 1]) / 2);
    }

    return 0;
}
