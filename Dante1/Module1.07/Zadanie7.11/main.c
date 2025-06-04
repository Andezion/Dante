#include <stdio.h>

int is_prime(int a);

int main()
{
    int num1, num2;

    printf("Enter num1: ");
    int check = scanf("%i",&num1);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter num2: ");
    int check2 = scanf("%i",&num2);
    if(check2 != 1 || num1 > num2)
    {
        printf("Incorrect input");
        return 1;
    }

    int count = 0;
    for(int i = num1; i <= num2; i++)
    {
        if(is_prime(i) == 1)
        {
            printf("%i ",i);
            count++;
        }
    }
    if(count == 0)
    {
        printf("Nothing to show");

    }

    return 0;
}

int is_prime(int a)
{
    int counter = 0;
    if(a == 0 || a == 1 || a < 0)
    {
        return 0;
    }
    for(int i = 1; i <= a; i++)
    {
        if(a % i == 0)
        {
            counter++;
        }
    }
    if(counter <= 2)
    {
        return 1;
    }
    return 0;
}
