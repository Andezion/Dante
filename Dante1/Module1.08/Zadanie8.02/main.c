#include <stdio.h>

long power_rec(int a, int n);

int main()
{
    int a, n;

    printf("Enter a: ");

    int check1 = scanf("%i",&a);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter n: ");

    int check2 = scanf("%i",&n);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(n < 0)
    {
        printf("Incorrect input data");
        return 2;
    }
    if(n == 1)
    {
        printf("%i",a);
        return 0;
    }
    printf("%ld", power_rec(a, n));

    return 0;
}

long power_rec(int a, int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(n < 1)
    {
        return 1;
    }
    return a * power_rec(a, n - 1);
}

