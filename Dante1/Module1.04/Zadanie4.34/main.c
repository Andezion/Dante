#include <stdio.h>

int main()
{
    int vector[100];
    int size = 0;

    printf("Enter: ");
    for(int i = 0; i < 100; i++)
    {
        int check = scanf("%i",&vector[i]);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(vector[i] == -1)
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

    int counter = 0;
    for(int i = 0; i < size / 2; i++)
    {
        if(vector[i] == vector[size - i - 1])
        {
            counter++;
        }
    }
    if(counter == size / 2)
    {
        printf("\nTAK");
    }
    else
    {
        printf("\nNIE");
    }

    return 0;
}
