#include <stdio.h>
#include <math.h>

int goldbach(int num);
int czy_pierwsza(int num);

int main()
{
    int num1, num2;

    printf("Enter num1: ");
    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter num2: ");
    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(num2 < num1)
    {
        printf("Incorrect data input");
        return 2;
    }

    printf("\n");
    for(int i = num1; i <= num2; i++)
    {
        if(i % 2 == 0)
        {
            printf("%i: ",i);
            goldbach(i);
            printf("\n");
        }
    }

    return 0;
}

int goldbach(int num)
{
    int pointer = 0;
    if (num % 2 != 0 || num < 4)
    {
        return 0;
    }
    for (int i = 2; i < num; i++)
    {
        if (czy_pierwsza(i) == 1)
        {
            int j = num - i;
            if (czy_pierwsza(j) == 1)
            {
                printf("(%i, %i) ", i, j);
                pointer = 1;
            }
        }
    }

    return pointer;
}

int czy_pierwsza(int num)
{
    if (num < 2)
    {
        return 0;
    }

    int sqrt_num = sqrt(num);
    for (int i = 2; i <= sqrt_num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
