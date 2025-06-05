#include <stdio.h>

long int fibonacci(int n);

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

    if(n < 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Result: %li", fibonacci(n));

    return 0;
}

long int fibonacci(int n)
{
    if(n < 0)
    {
        return -1;
    }
    else if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}


