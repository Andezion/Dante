#include <stdio.h>

long int fibonacci(int n)
{
    if(n < 0)
    {
        return -1;
    }
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 2;
    }
    return  n + fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int number;

    printf("Enter: ");
    int check = scanf("%i",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    long int result = fibonacci(number);
    if(result == -1)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("\nResult is: %li",result);

    return 0;
}
