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
            printf("\nIncorrect input");
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
    if(size > 100)
    {
        size = 100;
    }

    getchar();

    int number;

    printf("\nEnter: ");
    int check = scanf("%i", &number);
    if (check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (number > vector[i])
        {
            sum1++;
        }
        if (number < vector[i])
        {
            sum2++;
        }
    }

    printf("%i\n%i", sum1, sum2);

    return 0;
}
