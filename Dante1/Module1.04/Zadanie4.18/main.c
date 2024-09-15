#include <stdio.h>

int main()
{
    int vector[200];
    int size = 0;

    printf("Enter: ");

    for (int i = 0; i < 200; i++)
    {
        int check = scanf("%i", &vector[i]);
        if (check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if (vector[i] == 0)
        {
            break;
        }
        size++;
    }

    if (size < 1)
    {
        printf("Not enough data available");
        return 2;
    }

    if (size > 100)
    {
        size = 100;
    }

    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        for (int j = 0; j < i; j++)
        {
            if (vector[i] == vector[j])
            {
                temp = 1;
                break;
            }
        }
        if (temp == 0)
        {
            printf("%i ", vector[i]);
        }
    }

    return 0;
}
