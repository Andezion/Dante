#include <stdio.h>

unsigned long sum_rec(int n);

int main()
{
    int n;
    printf("Enter n: ");

    int check = scanf("%i",&n);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(n <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Result: %lu", sum_rec(n));

    return 0;
}

unsigned long sum_rec(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    return n + sum_rec(n - 1);
}


