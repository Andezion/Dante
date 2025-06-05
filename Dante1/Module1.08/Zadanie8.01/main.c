#include <stdio.h>

unsigned long factorial_rec(int n);

int main()
{
    int num;

    printf("Enter: ");

    int check = scanf("%i",&num);

    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(num < 0 || num > 20)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("%lu", factorial_rec(num));

    return 0;
}

unsigned long factorial_rec(int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(n <= 1)
    {
        return 1;
    }
    return n * factorial_rec(n - 1);
}
