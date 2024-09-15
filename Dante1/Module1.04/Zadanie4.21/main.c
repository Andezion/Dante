#include <stdio.h>

int isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int vector[100];
    int size = 0;

    printf("Enter smth: ");

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

    if (size == 0)
    {
        printf("Not enough data available");
        return 2;
    }

    int found = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (isPrime(i) == 1)
        {
            printf("%i ", vector[i]);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Nothing to show");
    }

    return 0;
}
